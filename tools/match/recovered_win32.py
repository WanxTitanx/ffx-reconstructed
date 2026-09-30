"""Observe compiler processes and loaded DLLs through the Windows debugger API.

Only processes started here are traced. No process memory or code is changed.
The trace proves executable/DLL consumption; source dependencies are separately
checked from the compiler's include records and immutable staged files.

API layouts: learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-debug_event
"""
import ctypes as C
import hashlib
import os
from pathlib import Path
import subprocess
import time

D = C.c_uint32
W = C.c_uint16
P = C.c_void_p


class ExceptionRecord(C.Structure):
    _fields_ = [('code', D), ('flags', D), ('record', P), ('address', P),
                ('parameters', D), ('information', C.c_size_t * 15)]


class ExceptionInfo(C.Structure):
    _fields_ = [('record', ExceptionRecord), ('first_chance', D)]


class ProcessInfo(C.Structure):
    _fields_ = [('file', P), ('process', P), ('thread', P), ('base', P),
                ('debug_offset', D), ('debug_size', D), ('local_base', P),
                ('start', P), ('image_name', P), ('unicode', W)]


class DllInfo(C.Structure):
    _fields_ = [('file', P), ('base', P), ('debug_offset', D), ('debug_size', D),
                ('image_name', P), ('unicode', W)]


class DebugUnion(C.Union):
    _fields_ = [('exception', ExceptionInfo), ('process', ProcessInfo),
                ('dll', DllInfo), ('exit_code', D)]


class DebugEvent(C.Structure):
    _fields_ = [('kind', D), ('pid', D), ('tid', D), ('data', DebugUnion)]


class StartupInfo(C.Structure):
    _fields_ = [('size', D), ('reserved', P), ('desktop', P), ('title', P),
                ('x', D), ('y', D), ('xsize', D), ('ysize', D), ('xchars', D),
                ('ychars', D), ('fill', D), ('flags', D), ('show', W),
                ('reserved_size', W), ('reserved_pointer', P),
                ('stdin', P), ('stdout', P), ('stderr', P)]


class CreatedProcess(C.Structure):
    _fields_ = [('process', P), ('thread', P), ('pid', D), ('tid', D)]


def digest_file(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def run(argv, cwd, environment, log_path, timeout=300):
    """Return observed executable/DLL identities and real process exit codes."""
    if os.name != 'nt':
        raise RuntimeError('the pinned MSVC compiler must run on Windows')
    import msvcrt
    kernel = C.WinDLL('kernel32', use_last_error=True)
    signatures = {
        'CreateProcessW': ([C.c_wchar_p, C.c_wchar_p, P, P, C.c_int, D, P,
                            C.c_wchar_p, C.POINTER(StartupInfo), C.POINTER(CreatedProcess)], C.c_int),
        'WaitForDebugEvent': ([C.POINTER(DebugEvent), D], C.c_int),
        'ContinueDebugEvent': ([D, D, D], C.c_int),
        'GetFinalPathNameByHandleW': ([P, C.c_wchar_p, D, D], D),
        'K32GetModuleFileNameExW': ([P, P, C.c_wchar_p, D], D),
        'CloseHandle': ([P], C.c_int),
        'TerminateProcess': ([P, D], C.c_int),
    }
    for name, (arguments, result) in signatures.items():
        api = getattr(kernel, name)
        api.argtypes, api.restype = arguments, result
    expected_size = 176 if C.sizeof(P) == 8 else 96
    if C.sizeof(DebugEvent) != expected_size:
        raise RuntimeError('Windows debug structure layout is incorrect')

    def checked(value):
        if not value:
            raise C.WinError(C.get_last_error())
        return value

    def module_path(handle, process, base):
        buffer = C.create_unicode_buffer(32768)
        size = kernel.GetFinalPathNameByHandleW(handle, buffer, len(buffer), 0) if handle else 0
        if not size or size >= len(buffer):
            size = kernel.K32GetModuleFileNameExW(process, base, buffer, len(buffer))
        checked(size)
        if size >= len(buffer)-1:
            raise RuntimeError('truncated compiler module path')
        name = buffer.value
        if name.startswith(chr(92)*2+'?'+chr(92)):
            name = name[4:]
        return str(Path(name).resolve())

    cwd = Path(cwd).resolve()
    deadline = time.monotonic() + timeout
    events, libraries, processes, exited = [], {}, {}, {}
    created = CreatedProcess()
    command = C.create_unicode_buffer(subprocess.list2cmdline([str(arg) for arg in argv]))
    env = C.create_unicode_buffer('\0'.join(k+'='+v for k, v in sorted(environment.items()))+'\0\0')
    with Path(log_path).open('xb') as log, open(os.devnull, 'rb') as null:
        output_handle = msvcrt.get_osfhandle(log.fileno())
        input_handle = msvcrt.get_osfhandle(null.fileno())
        os.set_handle_inheritable(output_handle, True)
        os.set_handle_inheritable(input_handle, True)
        startup = StartupInfo()
        startup.size, startup.flags = C.sizeof(startup), 0x100
        startup.stdout = startup.stderr = output_handle
        startup.stdin = input_handle
        try:
            checked(kernel.CreateProcessW(str(argv[0]), command, None, None, True,
                0x1 | 0x400 | 0x08000000, env, str(cwd), C.byref(startup), C.byref(created)))
            # DEBUG_PROCESS follows compiler child processes as well.
            while not exited or set(exited) != set(processes):
                if time.monotonic() >= deadline:
                    raise TimeoutError('compiler process trace timed out')
                event = DebugEvent()
                if not kernel.WaitForDebugEvent(C.byref(event), 1000):
                    error = C.get_last_error()
                    if error in (121, 258):
                        continue
                    raise C.WinError(error)
                disposition = 0x10002  # DBG_CONTINUE
                if event.kind == 3:
                    data = event.data.process
                    processes[event.pid] = data.process
                    name = module_path(data.file, data.process, data.base)
                    if data.file:
                        checked(kernel.CloseHandle(data.file))
                    value = digest_file(name)
                    libraries[name] = value
                    events.append({'kind': 'process', 'pid': event.pid, 'path': name, 'sha256': value})
                elif event.kind == 6:
                    data = event.data.dll
                    name = module_path(data.file, processes[event.pid], data.base)
                    if data.file:
                        checked(kernel.CloseHandle(data.file))
                    value = digest_file(name)
                    if name in libraries and libraries[name] != value:
                        raise RuntimeError('loaded compiler library changed')
                    libraries[name] = value
                    events.append({'kind': 'dll', 'pid': event.pid, 'path': name, 'sha256': value})
                elif event.kind == 5:
                    exited[event.pid] = event.data.exit_code
                    events.append({'kind': 'exit', 'pid': event.pid, 'exit_code': event.data.exit_code})
                elif event.kind == 1:
                    code = event.data.exception.record.code
                    if code not in (0x80000003, 0x4000001f):  # native/WOW64 initial breakpoints
                        disposition = 0x80010001  # compiler handles its own exceptions
                        events.append({'kind': 'exception', 'pid': event.pid, 'code': code,
                                       'first_chance': event.data.exception.first_chance})
                checked(kernel.ContinueDebugEvent(event.pid, event.tid, disposition))
        except BaseException:
            for pid, handle in processes.items():
                if pid not in exited:
                    kernel.TerminateProcess(handle, 1)
            if created.process and created.pid not in exited:
                kernel.TerminateProcess(created.process, 1)
            raise
        finally:
            os.set_handle_inheritable(output_handle, False)
            os.set_handle_inheritable(input_handle, False)
            for handle in (created.thread, created.process):
                if handle:
                    kernel.CloseHandle(handle)
    if created.pid not in exited or not libraries:
        raise RuntimeError('compiler process trace is incomplete')
    for path, value in libraries.items():
        if digest_file(path) != value:
            raise RuntimeError('compiler executable/library changed during the invocation')
    return {'schema_version': 1, 'method': 'Windows DEBUG_PROCESS module/exit events',
            'argv': [str(arg) for arg in argv], 'cwd': str(cwd), 'root_pid': created.pid,
            'exit_code': exited[created.pid], 'events': events,
            'loaded_files': dict(sorted(libraries.items())),
            'all_processes_exited': set(exited) == set(processes),
            'all_processes_succeeded': all(code == 0 for code in exited.values()),
            'scope': 'actual executable/DLL loads and process exits; include files checked separately'}
