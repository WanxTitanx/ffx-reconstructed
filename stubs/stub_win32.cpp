// ============================================================================
// FFX.EXE — Win32 System API Stubs
// Modules: ADVAPI32, USER32, KERNEL32, SHELL32, ole32, OLEAUT32, SHLWAPI,
//          WINMM, d3d11, DINPUT8, IMM32, XINPUT9_1_0, VERSION, dbghelp
// ============================================================================

#define _CRT_SECURE_NO_WARNINGS

// Ensure Vista+ types (threadpool, notification, etc.) are available
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0601
#endif
#ifndef WINVER
#define WINVER 0x0601
#endif

#pragma warning(push)
#pragma warning(disable : 4996) // Deprecated APIs (GetVersionExA, etc.)

#include <combaseapi.h>
#include <d3d11.h>
#include <dbghelp.h>
#include <dinput.h>
#include <dxgi.h> // IDXGIAdapter, IDXGISwapChain, DXGI_SWAP_CHAIN_DESC
#include <mmsystem.h>
#include <oleauto.h>
#include <shellapi.h> // CommandLineToArgvW
#include <shlobj.h>   // SHGetFolderPathW
#include <shlwapi.h>  // PathRemoveFileSpecW/A, PathCombineW/A
#include <wincrypt.h>
#include <windows.h>
#include <winver.h> // VerQueryValueW, GetFileVersionInfoA, GetFileVersionInfoSizeA
#include <xinput.h>

// ============================================================================
// ADVAPI32 Stubs
// ============================================================================

// Stub for ADVAPI32::GetUserNameA
BOOL WINAPI stub_GetUserNameA(LPSTR lpBuffer, LPDWORD lpnSize) {
  if (lpBuffer && lpnSize && *lpnSize > 0) {
    lpBuffer[0] = '\0';
    *lpnSize = 0;
  }
  return FALSE; // Stub: fail gracefully
}

// Stub for ADVAPI32::CryptAcquireContextA
BOOL WINAPI stub_CryptAcquireContextA(HCRYPTPROV *phProv, LPCSTR szContainer,
                                      LPCSTR szProvider, DWORD dwProvType,
                                      DWORD dwFlags) {
  if (phProv)
    *phProv = (HCRYPTPROV)1;
  return TRUE; // Stub: always succeeds
}

// Stub for ADVAPI32::CryptCreateHash
BOOL WINAPI stub_CryptCreateHash(HCRYPTPROV hProv, ALG_ID Algid, HCRYPTKEY hKey,
                                 DWORD dwFlags, HCRYPTHASH *phHash) {
  if (phHash)
    *phHash = (HCRYPTHASH)1;
  return TRUE; // Stub: always succeeds
}

// Stub for ADVAPI32::CryptHashData
BOOL WINAPI stub_CryptHashData(HCRYPTHASH hHash, const BYTE *pbData,
                               DWORD dwDataLen, DWORD dwFlags) {
  return TRUE; // Stub: always succeeds
}

// Stub for ADVAPI32::CryptGetHashParam
BOOL WINAPI stub_CryptGetHashParam(HCRYPTHASH hHash, DWORD dwParam,
                                   BYTE *pbData, DWORD *pdwDataLen,
                                   DWORD dwFlags) {
  return TRUE; // Stub: always succeeds
}

// Stub for ADVAPI32::CryptReleaseContext
BOOL WINAPI stub_CryptReleaseContext(HCRYPTPROV hProv, DWORD dwFlags) {
  return TRUE; // Stub: always succeeds
}

// Stub for ADVAPI32::CryptDestroyHash
BOOL WINAPI stub_CryptDestroyHash(HCRYPTHASH hHash) {
  return TRUE; // Stub: always succeeds
}

// ============================================================================
// USER32 Stubs
// ============================================================================

// Stub for USER32::PeekMessageW
BOOL WINAPI stub_PeekMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin,
                              UINT wMsgFilterMax, UINT wRemoveMsg) {
  if (lpMsg)
    ZeroMemory(lpMsg, sizeof(MSG));
  return FALSE; // Stub: no messages
}

// Stub for USER32::DispatchMessageW
LRESULT WINAPI stub_DispatchMessageW(const MSG *lpMsg) {
  return 0; // Stub: no-op
}

// Stub for USER32::GetWindowInfo
BOOL WINAPI stub_GetWindowInfo(HWND hWnd, PWINDOWINFO pwi) {
  return FALSE; // Stub: fail
}

// Stub for USER32::ChangeDisplaySettingsA
LONG WINAPI stub_ChangeDisplaySettingsA(DEVMODEA *lpDevMode, DWORD dwFlags) {
  return DISP_CHANGE_SUCCESSFUL; // Stub: always success
}

// Stub for USER32::LoadIconA
HICON WINAPI stub_LoadIconA(HINSTANCE hInstance, LPCSTR lpIconName) {
  return (HICON)1; // Stub: return dummy handle
}

// Stub for USER32::LoadCursorA
HCURSOR WINAPI stub_LoadCursorA(HINSTANCE hInstance, LPCSTR lpCursorName) {
  return (HCURSOR)1; // Stub: return dummy handle
}

// Stub for USER32::CallNextHookEx
LRESULT WINAPI stub_CallNextHookEx(HHOOK hhk, int nCode, WPARAM wParam,
                                   LPARAM lParam) {
  return 0; // Stub: no-op
}

// Stub for USER32::UnhookWindowsHookEx
BOOL WINAPI stub_UnhookWindowsHookEx(HHOOK hhk) {
  return TRUE; // Stub: always succeeds
}

// Stub for USER32::ClientToScreen
BOOL WINAPI stub_ClientToScreen(HWND hWnd, LPPOINT lpPoint) {
  return TRUE; // Stub: identity
}

// Stub for USER32::GetClipCursor
BOOL WINAPI stub_GetClipCursor(LPRECT lpRect) {
  if (lpRect)
    SetRect(lpRect, 0, 0, 1920, 1080);
  return TRUE; // Stub: return default rect
}

// Stub for USER32::wsprintfW
int WINAPI stub_wsprintfW(LPWSTR out, LPCWSTR fmt, ...) {
  if (out)
    out[0] = L'\0';
  return 0; // Stub: no-op
}

// Stub for USER32::SetCursorPos
BOOL WINAPI stub_SetCursorPos(int X, int Y) {
  return TRUE; // Stub: always succeeds
}

// Stub for USER32::SendMessageW
LRESULT WINAPI stub_SendMessageW(HWND hWnd, UINT Msg, WPARAM wParam,
                                 LPARAM lParam) {
  return 0; // Stub: no-op
}

// Stub for USER32::GetClientRect
BOOL WINAPI stub_GetClientRect(HWND hWnd, LPRECT lpRect) {
  if (lpRect)
    SetRect(lpRect, 0, 0, 640, 480);
  return TRUE; // Stub: return default rect
}

// Stub for USER32::MessageBoxW
int WINAPI stub_MessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption,
                            UINT uType) {
  // Print to debug output
  OutputDebugStringW(L"MessageBoxW stub: ");
  OutputDebugStringW(lpText ? lpText : L"");
  OutputDebugStringW(L"\n");
  return IDOK; // Stub: always OK
}

// Stub for USER32::ShowCursor
int WINAPI stub_ShowCursor(BOOL bShow) {
  return 0; // Stub: no-op
}

// Stub for USER32::RegisterWindowMessageA
UINT WINAPI stub_RegisterWindowMessageA(LPCSTR lpString) {
  return 0; // Stub: return 0 (WM_USER+ range would need tracking)
}

// Stub for USER32::TranslateMessage
BOOL WINAPI stub_TranslateMessage(const MSG *lpMsg) {
  return FALSE; // Stub: no-op
}

// Stub for USER32::DispatchMessageA
LRESULT WINAPI stub_DispatchMessageA(const MSG *lpMsg) {
  return 0; // Stub: no-op
}

// Stub for USER32::SetWindowsHookExA
HHOOK WINAPI stub_SetWindowsHookExA(int idHook, HOOKPROC lpfn, HINSTANCE hmod,
                                    DWORD dwThreadId) {
  return (HHOOK)1; // Stub: return dummy handle
}

// Stub for USER32::SetParent
HWND WINAPI stub_SetParent(HWND hWndChild, HWND hWndNewParent) {
  return NULL; // Stub: no-op
}

// Stub for USER32::PeekMessageA
BOOL WINAPI stub_PeekMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin,
                              UINT wMsgFilterMax, UINT wRemoveMsg) {
  if (lpMsg)
    ZeroMemory(lpMsg, sizeof(MSG));
  return FALSE; // Stub: no messages
}

// Stub for USER32::SendMessageA
LRESULT WINAPI stub_SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam,
                                 LPARAM lParam) {
  return 0; // Stub: no-op
}

// Stub for USER32::RegisterDeviceNotificationA
HDEVNOTIFY WINAPI stub_RegisterDeviceNotificationA(HANDLE hRecipient,
                                                   LPVOID NotificationFilter,
                                                   DWORD Flags) {
  return (HDEVNOTIFY)1; // Stub: return dummy handle
}

// Stub for USER32::PostMessageA
BOOL WINAPI stub_PostMessageA(HWND hWnd, UINT Msg, WPARAM wParam,
                              LPARAM lParam) {
  return TRUE; // Stub: always succeeds (message lost)
}

// Stub for USER32::DefWindowProcA
LRESULT WINAPI stub_DefWindowProcA(HWND hWnd, UINT Msg, WPARAM wParam,
                                   LPARAM lParam) {
  return 0; // Stub: no-op
}

// Stub for USER32::PostQuitMessage
void WINAPI stub_PostQuitMessage(int nExitCode) {
  // Stub: no-op
}

// Stub for USER32::RegisterClassA
ATOM WINAPI stub_RegisterClassA(const WNDCLASSA *lpWndClass) {
  return (ATOM)1; // Stub: return dummy atom
}

// Stub for USER32::SetWindowLongA
LONG WINAPI stub_SetWindowLongA(HWND hWnd, int nIndex, LONG dwNewLong) {
  return 0; // Stub: no-op
}

// Stub for USER32::GetWindowLongA
LONG WINAPI stub_GetWindowLongA(HWND hWnd, int nIndex) {
  return 0; // Stub: return 0
}

// Stub for USER32::ClipCursor
BOOL WINAPI stub_ClipCursor(const RECT *lpRect) {
  return TRUE; // Stub: always succeeds
}

// Stub for USER32::GetCursorPos
BOOL WINAPI stub_GetCursorPos(LPPOINT lpPoint) {
  if (lpPoint) {
    lpPoint->x = 0;
    lpPoint->y = 0;
  }
  return TRUE; // Stub: return origin
}

// Stub for USER32::AdjustWindowRect
BOOL WINAPI stub_AdjustWindowRect(LPRECT lpRect, DWORD dwStyle, BOOL bMenu) {
  return TRUE; // Stub: identity
}

// Stub for USER32::GetWindowRect
BOOL WINAPI stub_GetWindowRect(HWND hWnd, LPRECT lpRect) {
  if (lpRect)
    SetRect(lpRect, 0, 0, 640, 480);
  return TRUE; // Stub: return default rect
}

// Stub for USER32::SetWindowTextA
BOOL WINAPI stub_SetWindowTextA(HWND hWnd, LPCSTR lpString) {
  return TRUE; // Stub: always succeeds
}

// Stub for USER32::ReleaseDC
int WINAPI stub_ReleaseDC(HWND hWnd, HDC hDC) {
  return 1; // Stub: always success
}

// Stub for USER32::GetSystemMetrics
int WINAPI stub_GetSystemMetrics(int nIndex) {
  return 1024; // Stub: return default width
}

// Stub for USER32::SetWindowPos
BOOL WINAPI stub_SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int X, int Y,
                              int cx, int cy, UINT uFlags) {
  return TRUE; // Stub: always succeeds
}

// Stub for USER32::ShowWindow
BOOL WINAPI stub_ShowWindow(HWND hWnd, int nCmdShow) {
  return TRUE; // Stub: always succeeds
}

// Stub for USER32::DestroyWindow
BOOL WINAPI stub_DestroyWindow(HWND hWnd) {
  return TRUE; // Stub: always succeeds
}

// Stub for USER32::CreateWindowExA
HWND WINAPI stub_CreateWindowExA(DWORD dwExStyle, LPCSTR lpClassName,
                                 LPCSTR lpWindowName, DWORD dwStyle, int X,
                                 int Y, int nWidth, int nHeight,
                                 HWND hWndParent, HMENU hMenu,
                                 HINSTANCE hInstance, LPVOID lpParam) {
  return (HWND)1; // Stub: return dummy window handle
}

// ============================================================================
// KERNEL32 Stubs
// ============================================================================

// Stub for KERNEL32::GetLastError
DWORD WINAPI stub_GetLastError() {
  return ERROR_SUCCESS; // Stub: always success
}

// Stub for KERNEL32::EncodePointer
PVOID WINAPI stub_EncodePointer(PVOID Ptr) {
  return Ptr; // Stub: identity (no encoding)
}

// Stub for KERNEL32::DecodePointer
PVOID WINAPI stub_DecodePointer(PVOID Ptr) {
  return Ptr; // Stub: identity (no decoding)
}

// Stub for KERNEL32::IsProcessorFeaturePresent
BOOL WINAPI stub_IsProcessorFeaturePresent(DWORD ProcessorFeature) {
  return TRUE; // Stub: all features present
}

// Stub for KERNEL32::GetSystemTimeAsFileTime
void WINAPI stub_GetSystemTimeAsFileTime(LPFILETIME lpSystemTimeAsFileTime) {
  if (lpSystemTimeAsFileTime) {
    lpSystemTimeAsFileTime->dwLowDateTime = 0;
    lpSystemTimeAsFileTime->dwHighDateTime = 0;
  }
}

// Stub for KERNEL32::GetTickCount64
ULONGLONG WINAPI stub_GetTickCount64() {
  return 0; // Stub: return 0
}

// Stub for KERNEL32::InitializeCriticalSectionEx
BOOL WINAPI stub_InitializeCriticalSectionEx(
    LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount, DWORD Flags) {
  if (lpCriticalSection)
    InitializeCriticalSection(lpCriticalSection);
  return TRUE;
}

// Stub for KERNEL32::HeapDestroy
BOOL WINAPI stub_HeapDestroy(HANDLE hHeap) {
  return TRUE; // Stub: always succeeds
}

// Stub for KERNEL32::HeapAlloc
LPVOID WINAPI stub_HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes) {
  return HeapAlloc(GetProcessHeap(), dwFlags, dwBytes); // Delegate to real heap
}

// Stub for KERNEL32::HeapReAlloc
LPVOID WINAPI stub_HeapReAlloc(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem,
                               SIZE_T dwBytes) {
  return HeapReAlloc(GetProcessHeap(), dwFlags, lpMem, dwBytes);
}

// Stub for KERNEL32::HeapFree
BOOL WINAPI stub_HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem) {
  return HeapFree(GetProcessHeap(), dwFlags, lpMem);
}

// Stub for KERNEL32::HeapSize
SIZE_T WINAPI stub_HeapSize(HANDLE hHeap, DWORD dwFlags, LPCVOID lpMem) {
  return HeapSize(GetProcessHeap(), dwFlags, lpMem);
}

// Stub for KERNEL32::GetProcessHeap
HANDLE WINAPI stub_GetProcessHeap() {
  return GetProcessHeap(); // Real implementation
}

// Stub for KERNEL32::InterlockedIncrement
LONG WINAPI stub_InterlockedIncrement(LONG volatile *Addend) {
  return InterlockedIncrement(Addend); // Real implementation
}

// Stub for KERNEL32::InterlockedDecrement
LONG WINAPI stub_InterlockedDecrement(LONG volatile *Addend) {
  return InterlockedDecrement(Addend); // Real implementation
}

// Stub for KERNEL32::GetModuleHandleW
HMODULE WINAPI stub_GetModuleHandleW(LPCWSTR lpModuleName) {
  return GetModuleHandleW(lpModuleName); // Real implementation
}

// Stub for KERNEL32::FormatMessageA
DWORD WINAPI stub_FormatMessageA(DWORD dwFlags, LPCVOID lpSource,
                                 DWORD dwMessageId, DWORD dwLanguageId,
                                 LPSTR lpBuffer, DWORD nSize,
                                 va_list *Arguments) {
  if (lpBuffer && nSize > 0)
    lpBuffer[0] = '\0';
  return 0; // Stub: no message
}

// Stub for KERNEL32::GlobalMemoryStatusEx
BOOL WINAPI stub_GlobalMemoryStatusEx(LPMEMORYSTATUSEX lpBuffer) {
  if (lpBuffer) {
    lpBuffer->dwLength = sizeof(MEMORYSTATUSEX);
    lpBuffer->dwMemoryLoad = 0;
    lpBuffer->ullTotalPhys = 2ULL * 1024 * 1024 * 1024; // 2 GB
    lpBuffer->ullAvailPhys = 1ULL * 1024 * 1024 * 1024;
    lpBuffer->ullTotalPageFile = 4ULL * 1024 * 1024 * 1024;
    lpBuffer->ullAvailPageFile = 2ULL * 1024 * 1024 * 1024;
    lpBuffer->ullTotalVirtual = 2ULL * 1024 * 1024 * 1024;
    lpBuffer->ullAvailVirtual = 1ULL * 1024 * 1024 * 1024;
    lpBuffer->ullAvailExtendedVirtual = 0;
  }
  return TRUE;
}

// Stub for KERNEL32::CreateEventW
HANDLE WINAPI stub_CreateEventW(LPSECURITY_ATTRIBUTES lpEventAttributes,
                                BOOL bManualReset, BOOL bInitialState,
                                LPCWSTR lpName) {
  return CreateEventW(lpEventAttributes, bManualReset, bInitialState,
                      lpName); // Real implementation
}

// Stub for KERNEL32::LoadLibraryA
HMODULE WINAPI stub_LoadLibraryA(LPCSTR lpLibFileName) {
  return LoadLibraryA(lpLibFileName); // Real implementation
}

// Stub for KERNEL32::WaitForSingleObjectEx
DWORD WINAPI stub_WaitForSingleObjectEx(HANDLE hHandle, DWORD dwMilliseconds,
                                        BOOL bAlertable) {
  return WaitForSingleObjectEx(hHandle, dwMilliseconds,
                               bAlertable); // Real implementation
}

// Stub for KERNEL32::GetTimeZoneInformation
DWORD WINAPI
stub_GetTimeZoneInformation(LPTIME_ZONE_INFORMATION lpTimeZoneInformation) {
  if (lpTimeZoneInformation)
    ZeroMemory(lpTimeZoneInformation, sizeof(TIME_ZONE_INFORMATION));
  return TIME_ZONE_ID_UNKNOWN; // Stub
}

// Stub for KERNEL32::FileTimeToSystemTime
BOOL WINAPI stub_FileTimeToSystemTime(const FILETIME *lpFileTime,
                                      LPSYSTEMTIME lpSystemTime) {
  return FileTimeToSystemTime(lpFileTime, lpSystemTime); // Real implementation
}

// Stub for KERNEL32::SystemTimeToTzSpecificLocalTime
BOOL WINAPI stub_SystemTimeToTzSpecificLocalTime(
    LPTIME_ZONE_INFORMATION lpTimeZoneInformation, LPSYSTEMTIME lpUniversalTime,
    LPSYSTEMTIME lpLocalTime) {
  if (lpLocalTime && lpUniversalTime)
    CopyMemory(lpLocalTime, lpUniversalTime, sizeof(SYSTEMTIME));
  return TRUE;
}

// Stub for KERNEL32::GetFileTime
BOOL WINAPI stub_GetFileTime(HANDLE hFile, LPFILETIME lpCreationTime,
                             LPFILETIME lpLastAccessTime,
                             LPFILETIME lpLastWriteTime) {
  return GetFileTime(hFile, lpCreationTime, lpLastAccessTime,
                     lpLastWriteTime); // Real implementation
}

// Stub for KERNEL32::VirtualQuery
SIZE_T WINAPI stub_VirtualQuery(LPCVOID lpAddress,
                                PMEMORY_BASIC_INFORMATION lpBuffer,
                                SIZE_T dwLength) {
  return VirtualQuery(lpAddress, lpBuffer, dwLength); // Real implementation
}

// Stub for KERNEL32::VirtualFree
BOOL WINAPI stub_VirtualFree(LPVOID lpAddress, SIZE_T dwSize,
                             DWORD dwFreeType) {
  return VirtualFree(lpAddress, dwSize, dwFreeType); // Real implementation
}

// Stub for KERNEL32::VirtualAlloc
LPVOID WINAPI stub_VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize,
                                DWORD flAllocationType, DWORD flProtect) {
  return VirtualAlloc(lpAddress, dwSize, flAllocationType,
                      flProtect); // Real implementation
}

// Stub for KERNEL32::GetTickCount
DWORD WINAPI stub_GetTickCount() {
  return GetTickCount(); // Real implementation
}

// Stub for KERNEL32::GetSystemInfo
void WINAPI stub_GetSystemInfo(LPSYSTEM_INFO lpSystemInfo) {
  GetSystemInfo(lpSystemInfo); // Real implementation
}

// Stub for KERNEL32::SleepEx
DWORD WINAPI stub_SleepEx(DWORD dwMilliseconds, BOOL bAlertable) {
  return SleepEx(dwMilliseconds, bAlertable); // Real implementation
}

// Stub for KERNEL32::LoadLibraryW
HMODULE WINAPI stub_LoadLibraryW(LPCWSTR lpLibFileName) {
  return LoadLibraryW(lpLibFileName); // Real implementation
}

// Stub for KERNEL32::ReadProcessMemory
BOOL WINAPI stub_ReadProcessMemory(HANDLE hProcess, LPCVOID lpBaseAddress,
                                   LPVOID lpBuffer, SIZE_T nSize,
                                   SIZE_T *lpNumberOfBytesRead) {
  return FALSE; // Stub: fail (different process)
}

// Stub for KERNEL32::GetVersionExA
BOOL WINAPI stub_GetVersionExA(LPOSVERSIONINFOA lpVersionInformation) {
  if (lpVersionInformation) {
    lpVersionInformation->dwMajorVersion = 6;
    lpVersionInformation->dwMinorVersion = 1;
    lpVersionInformation->dwBuildNumber = 7601;
    lpVersionInformation->dwPlatformId = VER_PLATFORM_WIN32_NT;
    lpVersionInformation->szCSDVersion[0] = '\0';
  }
  return TRUE;
}

// Stub for KERNEL32::GetThreadContext
BOOL WINAPI stub_GetThreadContext(HANDLE hThread, LPCONTEXT lpContext) {
  return FALSE; // Stub: fail
}

// Stub for KERNEL32::GetStdHandle
HANDLE WINAPI stub_GetStdHandle(DWORD nStdHandle) {
  return GetStdHandle(nStdHandle); // Real implementation
}

// Stub for KERNEL32::GetModuleFileNameA
DWORD WINAPI stub_GetModuleFileNameA(HMODULE hModule, LPSTR lpFilename,
                                     DWORD nSize) {
  return GetModuleFileNameA(hModule, lpFilename, nSize); // Real implementation
}

// Stub for KERNEL32::GetConsoleScreenBufferInfo
BOOL WINAPI stub_GetConsoleScreenBufferInfo(
    HANDLE hConsoleOutput,
    PCONSOLE_SCREEN_BUFFER_INFO lpConsoleScreenBufferInfo) {
  return GetConsoleScreenBufferInfo(
      hConsoleOutput, lpConsoleScreenBufferInfo); // Real implementation
}

// Stub for KERNEL32::SetConsoleScreenBufferSize
BOOL WINAPI stub_SetConsoleScreenBufferSize(HANDLE hConsoleOutput,
                                            COORD dwSize) {
  return SetConsoleScreenBufferSize(hConsoleOutput,
                                    dwSize); // Real implementation
}

// Stub for KERNEL32::AllocConsole
BOOL WINAPI stub_AllocConsole() {
  return AllocConsole(); // Real implementation
}

// Stub for KERNEL32::GetEnvironmentVariableA
DWORD WINAPI stub_GetEnvironmentVariableA(LPCSTR lpName, LPSTR lpBuffer,
                                          DWORD nSize) {
  return GetEnvironmentVariableA(lpName, lpBuffer,
                                 nSize); // Real implementation
}

// Stub for KERNEL32::SetCurrentDirectoryA
BOOL WINAPI stub_SetCurrentDirectoryA(LPCSTR lpPathName) {
  return SetCurrentDirectoryA(lpPathName); // Real implementation
}

// Stub for KERNEL32::GetCurrentDirectoryA
DWORD WINAPI stub_GetCurrentDirectoryA(DWORD nBufferLength, LPSTR lpBuffer) {
  return GetCurrentDirectoryA(nBufferLength, lpBuffer); // Real implementation
}

// Stub for KERNEL32::CloseHandle
BOOL WINAPI stub_CloseHandle(HANDLE hObject) {
  return CloseHandle(hObject); // Real implementation
}

// Stub for KERNEL32::RaiseException
void WINAPI stub_RaiseException(DWORD dwExceptionCode, DWORD dwExceptionFlags,
                                DWORD nNumberOfArguments,
                                const ULONG_PTR *lpArguments) {
  RaiseException(dwExceptionCode, dwExceptionFlags, nNumberOfArguments,
                 lpArguments); // Real implementation
}

// Stub for KERNEL32::QueryPerformanceCounter
BOOL WINAPI stub_QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount) {
  return QueryPerformanceCounter(lpPerformanceCount); // Real implementation
}

// Stub for KERNEL32::QueryPerformanceFrequency
BOOL WINAPI stub_QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency) {
  return QueryPerformanceFrequency(lpFrequency); // Real implementation
}

// Stub for KERNEL32::SetEvent
BOOL WINAPI stub_SetEvent(HANDLE hEvent) {
  return SetEvent(hEvent); // Real implementation
}

// Stub for KERNEL32::ResetEvent
BOOL WINAPI stub_ResetEvent(HANDLE hEvent) {
  return ResetEvent(hEvent); // Real implementation
}

// Stub for KERNEL32::ReleaseSemaphore
BOOL WINAPI stub_ReleaseSemaphore(HANDLE hSemaphore, LONG lReleaseCount,
                                  LPLONG lpPreviousCount) {
  return ReleaseSemaphore(hSemaphore, lReleaseCount,
                          lpPreviousCount); // Real implementation
}

// Stub for KERNEL32::WaitForSingleObject
DWORD WINAPI stub_WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds) {
  return WaitForSingleObject(hHandle, dwMilliseconds); // Real implementation
}

// Stub for KERNEL32::CreateEventA
HANDLE WINAPI stub_CreateEventA(LPSECURITY_ATTRIBUTES lpEventAttributes,
                                BOOL bManualReset, BOOL bInitialState,
                                LPCSTR lpName) {
  return CreateEventA(lpEventAttributes, bManualReset, bInitialState,
                      lpName); // Real implementation
}

// Stub for KERNEL32::Sleep
void WINAPI stub_Sleep(DWORD dwMilliseconds) {
  Sleep(dwMilliseconds); // Real implementation
}

// Stub for KERNEL32::CreateThread
HANDLE WINAPI stub_CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes,
                                SIZE_T dwStackSize,
                                LPTHREAD_START_ROUTINE lpStartAddress,
                                LPVOID lpParameter, DWORD dwCreationFlags,
                                LPDWORD lpThreadId) {
  return CreateThread(lpThreadAttributes, dwStackSize, lpStartAddress,
                      lpParameter, dwCreationFlags,
                      lpThreadId); // Real implementation
}

// Stub for KERNEL32::GetCurrentThreadId
DWORD WINAPI stub_GetCurrentThreadId() {
  return GetCurrentThreadId(); // Real implementation
}

// Stub for KERNEL32::SetThreadPriority
BOOL WINAPI stub_SetThreadPriority(HANDLE hThread, int nPriority) {
  return SetThreadPriority(hThread, nPriority); // Real implementation
}

// Stub for KERNEL32::GetExitCodeThread
BOOL WINAPI stub_GetExitCodeThread(HANDLE hThread, LPDWORD lpExitCode) {
  return GetExitCodeThread(hThread, lpExitCode); // Real implementation
}

// Stub for KERNEL32::GetModuleHandleA
HMODULE WINAPI stub_GetModuleHandleA(LPCSTR lpModuleName) {
  return GetModuleHandleA(lpModuleName); // Real implementation
}

// Stub for KERNEL32::GetProcAddress
FARPROC WINAPI stub_GetProcAddress(HMODULE hModule, LPCSTR lpProcName) {
  return GetProcAddress(hModule, lpProcName); // Real implementation
}

// Stub for KERNEL32::CreateSemaphoreA
HANDLE WINAPI stub_CreateSemaphoreA(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
                                    LONG lInitialCount, LONG lMaximumCount,
                                    LPCSTR lpName) {
  return CreateSemaphoreA(lpSemaphoreAttributes, lInitialCount, lMaximumCount,
                          lpName); // Real implementation
}

// Stub for KERNEL32::FreeLibrary
BOOL WINAPI stub_FreeLibrary(HMODULE hLibModule) {
  return FreeLibrary(hLibModule); // Real implementation
}

// Stub for KERNEL32::LoadLibraryExA
HMODULE WINAPI stub_LoadLibraryExA(LPCSTR lpLibFileName, HANDLE hFile,
                                   DWORD dwFlags) {
  return LoadLibraryExA(lpLibFileName, hFile, dwFlags); // Real implementation
}

// Stub for KERNEL32::InterlockedExchangeAdd
LONG WINAPI stub_InterlockedExchangeAdd(LONG volatile *Addend, LONG Value) {
  return InterlockedExchangeAdd(Addend, Value); // Real implementation
}

// Stub for KERNEL32::InterlockedCompareExchange
LONG WINAPI stub_InterlockedCompareExchange(LONG volatile *Destination,
                                            LONG Exchange, LONG Comperand) {
  return InterlockedCompareExchange(Destination, Exchange,
                                    Comperand); // Real implementation
}

// Stub for KERNEL32::IsDebuggerPresent
BOOL WINAPI stub_IsDebuggerPresent() {
  return IsDebuggerPresent(); // Real implementation
}

// Stub for KERNEL32::DebugBreak
void WINAPI stub_DebugBreak() {
  DebugBreak(); // Real implementation
}

// Stub for KERNEL32::CreateFileW
HANDLE WINAPI stub_CreateFileW(LPCWSTR lpFileName, DWORD dwDesiredAccess,
                               DWORD dwShareMode,
                               LPSECURITY_ATTRIBUTES lpSecurityAttributes,
                               DWORD dwCreationDisposition,
                               DWORD dwFlagsAndAttributes,
                               HANDLE hTemplateFile) {
  return CreateFileW(lpFileName, dwDesiredAccess, dwShareMode,
                     lpSecurityAttributes, dwCreationDisposition,
                     dwFlagsAndAttributes,
                     hTemplateFile); // Real implementation
}

// Stub for KERNEL32::GetFileSizeEx
BOOL WINAPI stub_GetFileSizeEx(HANDLE hFile, PLARGE_INTEGER lpFileSize) {
  return GetFileSizeEx(hFile, lpFileSize); // Real implementation
}

// Stub for KERNEL32::ReadFile
BOOL WINAPI stub_ReadFile(HANDLE hFile, LPVOID lpBuffer,
                          DWORD nNumberOfBytesToRead,
                          LPDWORD lpNumberOfBytesRead,
                          LPOVERLAPPED lpOverlapped) {
  return ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead,
                  lpOverlapped); // Real implementation
}

// Stub for KERNEL32::SetEndOfFile
BOOL WINAPI stub_SetEndOfFile(HANDLE hFile) {
  return SetEndOfFile(hFile); // Real implementation
}

// Stub for KERNEL32::SetFilePointer
DWORD WINAPI stub_SetFilePointer(HANDLE hFile, LONG lDistanceToMove,
                                 PLONG lpDistanceToMoveHigh,
                                 DWORD dwMoveMethod) {
  return SetFilePointer(hFile, lDistanceToMove, lpDistanceToMoveHigh,
                        dwMoveMethod); // Real implementation
}

// Stub for KERNEL32::WriteFile
BOOL WINAPI stub_WriteFile(HANDLE hFile, LPCVOID lpBuffer,
                           DWORD nNumberOfBytesToWrite,
                           LPDWORD lpNumberOfBytesWritten,
                           LPOVERLAPPED lpOverlapped) {
  return WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite,
                   lpNumberOfBytesWritten, lpOverlapped); // Real implementation
}

// Stub for KERNEL32::InitializeCriticalSection
void WINAPI
stub_InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
  InitializeCriticalSection(lpCriticalSection); // Real implementation
}

// Stub for KERNEL32::EnterCriticalSection
void WINAPI stub_EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
  EnterCriticalSection(lpCriticalSection); // Real implementation
}

// Stub for KERNEL32::LeaveCriticalSection
void WINAPI stub_LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
  LeaveCriticalSection(lpCriticalSection); // Real implementation
}

// Stub for KERNEL32::DeleteCriticalSection
void WINAPI stub_DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
  DeleteCriticalSection(lpCriticalSection); // Real implementation
}

// Stub for KERNEL32::CreateThreadpoolWork
PTP_WORK WINAPI stub_CreateThreadpoolWork(PTP_WORK_CALLBACK pfnwk, PVOID pv,
                                          PTP_CALLBACK_ENVIRON pcbe) {
  return NULL; // Stub: threadpool not available
}

// Stub for KERNEL32::SubmitThreadpoolWork
void WINAPI stub_SubmitThreadpoolWork(PTP_WORK pwk) {
  // Stub: no-op
}

// Stub for KERNEL32::CreateThreadpoolWait
PTP_WAIT WINAPI stub_CreateThreadpoolWait(PTP_WAIT_CALLBACK pfnwa, PVOID pv,
                                          PTP_CALLBACK_ENVIRON pcbe) {
  return NULL; // Stub: threadpool not available
}

// Stub for KERNEL32::SetThreadpoolWait
void WINAPI stub_SetThreadpoolWait(PTP_WAIT pwa, HANDLE h,
                                   LARGE_INTEGER *pftTimeout) {
  // Stub: no-op
}

// Stub for KERNEL32::LoadResource
HGLOBAL WINAPI stub_LoadResource(HMODULE hModule, HRSRC hResInfo) {
  return (HGLOBAL)1; // Stub: return dummy handle
}

// Stub for KERNEL32::LockResource
LPVOID WINAPI stub_LockResource(HGLOBAL hResData) {
  return (LPVOID)1; // Stub: return dummy pointer
}

// Stub for KERNEL32::SizeofResource
DWORD WINAPI stub_SizeofResource(HMODULE hModule, HRSRC hResInfo) {
  return 0; // Stub: return 0
}

// Stub for KERNEL32::FindResourceW
HRSRC WINAPI stub_FindResourceW(HMODULE hModule, LPCWSTR lpName,
                                LPCWSTR lpType) {
  return NULL; // Stub: resource not found
}

// Stub for KERNEL32::GetCommandLineW
LPWSTR WINAPI stub_GetCommandLineW() {
  return L""; // Stub: empty command line
}

// Stub for KERNEL32::SuspendThread
DWORD WINAPI stub_SuspendThread(HANDLE hThread) {
  return SuspendThread(hThread); // Real implementation
}

// Stub for KERNEL32::CreateFileA
HANDLE WINAPI stub_CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess,
                               DWORD dwShareMode,
                               LPSECURITY_ATTRIBUTES lpSecurityAttributes,
                               DWORD dwCreationDisposition,
                               DWORD dwFlagsAndAttributes,
                               HANDLE hTemplateFile) {
  return CreateFileA(lpFileName, dwDesiredAccess, dwShareMode,
                     lpSecurityAttributes, dwCreationDisposition,
                     dwFlagsAndAttributes,
                     hTemplateFile); // Real implementation
}

// Stub for KERNEL32::GetFileAttributesW
DWORD WINAPI stub_GetFileAttributesW(LPCWSTR lpFileName) {
  return GetFileAttributesW(lpFileName); // Real implementation
}

// Stub for KERNEL32::SetUnhandledExceptionFilter
LPTOP_LEVEL_EXCEPTION_FILTER WINAPI stub_SetUnhandledExceptionFilter(
    LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter) {
  return SetUnhandledExceptionFilter(
      lpTopLevelExceptionFilter); // Real implementation
}

// Stub for KERNEL32::CreateDirectoryW
BOOL WINAPI stub_CreateDirectoryW(LPCWSTR lpPathName,
                                  LPSECURITY_ATTRIBUTES lpSecurityAttributes) {
  return CreateDirectoryW(lpPathName,
                          lpSecurityAttributes); // Real implementation
}

// Stub for KERNEL32::CreateMutexW
HANDLE WINAPI stub_CreateMutexW(LPSECURITY_ATTRIBUTES lpMutexAttributes,
                                BOOL bInitialOwner, LPCWSTR lpName) {
  return CreateMutexW(lpMutexAttributes, bInitialOwner,
                      lpName); // Real implementation
}

// Stub for KERNEL32::GetCurrentProcess
HANDLE WINAPI stub_GetCurrentProcess() {
  return GetCurrentProcess(); // Real implementation
}

// Stub for KERNEL32::GetProcessId
DWORD WINAPI stub_GetProcessId(HANDLE Process) {
  return GetProcessId(Process); // Real implementation
}

// Stub for KERNEL32::GetModuleFileNameW
DWORD WINAPI stub_GetModuleFileNameW(HMODULE hModule, LPWSTR lpFilename,
                                     DWORD nSize) {
  return GetModuleFileNameW(hModule, lpFilename, nSize); // Real implementation
}

// Stub for KERNEL32::LocalFree
HLOCAL WINAPI stub_LocalFree(HLOCAL hMem) {
  return LocalFree(hMem); // Real implementation
}

// Stub for KERNEL32::SetThreadExecutionState
EXECUTION_STATE WINAPI stub_SetThreadExecutionState(EXECUTION_STATE esFlags) {
  return SetThreadExecutionState(esFlags); // Real implementation
}

// Stub for KERNEL32::WideCharToMultiByte
int WINAPI stub_WideCharToMultiByte(UINT CodePage, DWORD dwFlags,
                                    LPCWCH lpWideCharStr, int cchWideChar,
                                    LPSTR lpMultiByteStr, int cbMultiByte,
                                    LPCCH lpDefaultChar,
                                    LPBOOL lpUsedDefaultChar) {
  return WideCharToMultiByte(CodePage, dwFlags, lpWideCharStr, cchWideChar,
                             lpMultiByteStr, cbMultiByte, lpDefaultChar,
                             lpUsedDefaultChar); // Real implementation
}

// Stub for KERNEL32::GetThreadLocale
LCID WINAPI stub_GetThreadLocale() {
  return GetThreadLocale(); // Real implementation
}

// Stub for KERNEL32::SetThreadUILanguage
LANGID WINAPI stub_SetThreadUILanguage(LANGID LangId) {
  return SetThreadUILanguage(LangId); // Real implementation
}

// Stub for KERNEL32::GetSystemTime
void WINAPI stub_GetSystemTime(LPSYSTEMTIME lpSystemTime) {
  GetSystemTime(lpSystemTime); // Real implementation
}

// Stub for KERNEL32::ReleaseMutex
BOOL WINAPI stub_ReleaseMutex(HANDLE hMutex) {
  return ReleaseMutex(hMutex); // Real implementation
}

// Stub for KERNEL32::GetCurrentProcessId
DWORD WINAPI stub_GetCurrentProcessId() {
  return GetCurrentProcessId(); // Real implementation
}

// Stub for KERNEL32::ExitProcess
void WINAPI stub_ExitProcess(UINT uExitCode) {
  ExitProcess(uExitCode); // Real implementation
}

// Stub for KERNEL32::FindResourceExW
HRSRC WINAPI stub_FindResourceExW(HMODULE hModule, LPCWSTR lpType,
                                  LPCWSTR lpName, WORD wLanguage) {
  return NULL; // Stub: not found
}

// Stub for KERNEL32::MultiByteToWideChar
int WINAPI stub_MultiByteToWideChar(UINT CodePage, DWORD dwFlags,
                                    LPCSTR lpMultiByteStr, int cbMultiByte,
                                    LPWSTR lpWideCharStr, int cchWideChar) {
  return MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cbMultiByte,
                             lpWideCharStr, cchWideChar); // Real implementation
}

// Stub for KERNEL32::ExitThread
void WINAPI stub_ExitThread(DWORD dwExitCode) {
  ExitThread(dwExitCode); // Real implementation
}

// Stub for KERNEL32::TerminateThread
BOOL WINAPI stub_TerminateThread(HANDLE hThread, DWORD dwExitCode) {
  return TerminateThread(hThread, dwExitCode); // Real implementation
}

// Stub for KERNEL32::ResumeThread
DWORD WINAPI stub_ResumeThread(HANDLE hThread) {
  return ResumeThread(hThread); // Real implementation
}

// Stub for KERNEL32::CreateSemaphoreW
HANDLE WINAPI stub_CreateSemaphoreW(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
                                    LONG lInitialCount, LONG lMaximumCount,
                                    LPCWSTR lpName) {
  return CreateSemaphoreW(lpSemaphoreAttributes, lInitialCount, lMaximumCount,
                          lpName); // Real implementation
}

// Stub for KERNEL32::GetEnvironmentVariableW
DWORD WINAPI stub_GetEnvironmentVariableW(LPCWSTR lpName, LPWSTR lpBuffer,
                                          DWORD nSize) {
  return GetEnvironmentVariableW(lpName, lpBuffer,
                                 nSize); // Real implementation
}

// Stub for KERNEL32::SetLastError
void WINAPI stub_SetLastError(DWORD dwErrCode) {
  SetLastError(dwErrCode); // Real implementation
}

// Stub for KERNEL32::GetCurrentThread
HANDLE WINAPI stub_GetCurrentThread() {
  return GetCurrentThread(); // Real implementation
}

// ============================================================================
// SHELL32 Stubs
// ============================================================================

// Stub for SHELL32::SHGetFolderPathW
HRESULT WINAPI stub_SHGetFolderPathW(HWND hwnd, int csidl, HANDLE hToken,
                                     DWORD dwFlags, LPWSTR pszPath) {
  if (pszPath)
    pszPath[0] = L'\0';
  return E_FAIL; // Stub: fail
}

// Stub for SHELL32::CommandLineToArgvW
LPWSTR *WINAPI stub_CommandLineToArgvW(LPCWSTR lpCmdLine, int *pNumArgs) {
  return NULL; // Stub: fail
}

// Stub for SHELL32::ShellExecuteW
HINSTANCE WINAPI stub_ShellExecuteW(HWND hwnd, LPCWSTR lpOperation,
                                    LPCWSTR lpFile, LPCWSTR lpParameters,
                                    LPCWSTR lpDirectory, int nShowCmd) {
  return (HINSTANCE)32; // Stub: return >32 = success (shell not available)
}

// ============================================================================
// ole32 Stubs
// ============================================================================

// Stub for ole32::CoInitialize
HRESULT WINAPI stub_CoInitialize(LPVOID pvReserved) {
  return S_OK; // Stub: always success
}

// Stub for ole32::CoCreateInstance
HRESULT WINAPI stub_CoCreateInstance(REFCLSID rclsid, LPUNKNOWN pUnkOuter,
                                     DWORD dwClsContext, REFIID riid,
                                     LPVOID *ppv) {
  if (ppv)
    *ppv = NULL;
  return CLASS_E_CLASSNOTAVAILABLE; // Stub: class not available
}

// Stub for ole32::CoSetProxyBlanket
HRESULT WINAPI stub_CoSetProxyBlanket(LPUNKNOWN pProxy, DWORD dwAuthnSvc,
                                      DWORD dwAuthzSvc,
                                      OLECHAR *pServerPrincName,
                                      DWORD dwAuthnLevel, DWORD dwImpLevel,
                                      RPC_AUTH_IDENTITY_HANDLE pAuthInfo,
                                      DWORD dwCapabilities) {
  return S_OK; // Stub: always success
}

// Stub for ole32::CoUninitialize
void WINAPI stub_CoUninitialize() {
  // Stub: no-op
}

// ============================================================================
// OLEAUT32 Stubs
// ============================================================================

// Stub for OLEAUT32::SysAllocString
BSTR WINAPI stub_SysAllocString(const OLECHAR *psz) {
  return NULL; // Stub: fail (allocation not available)
}

// Stub for OLEAUT32::SysAllocStringLen
BSTR WINAPI stub_SysAllocStringLen(const OLECHAR *strIn, UINT ui) {
  return NULL; // Stub: fail
}

// Stub for OLEAUT32::SysFreeString
void WINAPI stub_SysFreeString(BSTR bstrString) {
  // Stub: no-op
}

// ============================================================================
// SHLWAPI Stubs
// ============================================================================

// Stub for SHLWAPI::PathRemoveFileSpecW
BOOL WINAPI stub_PathRemoveFileSpecW(LPWSTR pszPath) {
  return FALSE; // Stub: no-op
}

// Stub for SHLWAPI::PathCombineW
LPWSTR WINAPI stub_PathCombineW(LPWSTR pszDest, LPCWSTR pszDir,
                                LPCWSTR pszFile) {
  if (pszDest)
    pszDest[0] = L'\0';
  return NULL; // Stub: fail
}

// Stub for SHLWAPI::PathRemoveFileSpecA
BOOL WINAPI stub_PathRemoveFileSpecA(LPSTR pszPath) {
  return FALSE; // Stub: no-op
}

// Stub for SHLWAPI::PathCombineA
LPSTR WINAPI stub_PathCombineA(LPSTR pszDest, LPCSTR pszDir, LPCSTR pszFile) {
  if (pszDest)
    pszDest[0] = '\0';
  return NULL; // Stub: fail
}

// ============================================================================
// WINMM Stubs
// ============================================================================

// Stub for WINMM::timeBeginPeriod
MMRESULT WINAPI stub_timeBeginPeriod(UINT uPeriod) {
  return TIMERR_NOERROR; // Stub: always success
}

// Stub for WINMM::timeEndPeriod
MMRESULT WINAPI stub_timeEndPeriod(UINT uPeriod) {
  return TIMERR_NOERROR; // Stub: always success
}

// Stub for WINMM::timeGetTime
DWORD WINAPI stub_timeGetTime() {
  return timeGetTime(); // Real implementation
}

// ============================================================================
// DINPUT8 Stubs
// ============================================================================

// Stub for DINPUT8::DirectInput8Create
HRESULT WINAPI stub_DirectInput8Create(HINSTANCE hinst, DWORD dwVersion,
                                       REFIID riidltf, LPVOID *ppvOut,
                                       LPUNKNOWN punkOuter) {
  if (ppvOut)
    *ppvOut = NULL;
  return DIERR_DEVICENOTREG; // Stub: DirectInput not available
}

// ============================================================================
// IMM32 Stubs
// ============================================================================

// Stub for IMM32::ImmAssociateContext
HIMC WINAPI stub_ImmAssociateContext(HWND hWnd, HIMC hIMC) {
  return NULL; // Stub: no-op
}

// ============================================================================
// XINPUT9_1_0 Stubs
// ============================================================================

// Stub for XINPUT9_1_0::XInputSetState
DWORD WINAPI stub_XInputSetState(DWORD dwUserIndex,
                                 XINPUT_VIBRATION *pVibration) {
  return ERROR_DEVICE_NOT_CONNECTED; // Stub: no controller
}

// Stub for XINPUT9_1_0::XInputGetState
DWORD WINAPI stub_XInputGetState(DWORD dwUserIndex, XINPUT_STATE *pState) {
  return ERROR_DEVICE_NOT_CONNECTED; // Stub: no controller
}

// ============================================================================
// VERSION Stubs
// ============================================================================

// Stub for VERSION::VerQueryValueW
BOOL WINAPI stub_VerQueryValueW(LPCVOID pBlock, LPCWSTR lpSubBlock,
                                LPVOID *lplpBuffer, PUINT puLen) {
  if (lplpBuffer)
    *lplpBuffer = NULL;
  if (puLen)
    *puLen = 0;
  return FALSE; // Stub: no version info
}

// Stub for VERSION::GetFileVersionInfoA
BOOL WINAPI stub_GetFileVersionInfoA(LPCSTR lptstrFilename, DWORD dwHandle,
                                     DWORD dwLen, LPVOID lpData) {
  return FALSE; // Stub: fail
}

// Stub for VERSION::GetFileVersionInfoSizeA
DWORD WINAPI stub_GetFileVersionInfoSizeA(LPCSTR lptstrFilename,
                                          LPDWORD lpdwHandle) {
  if (lpdwHandle)
    *lpdwHandle = 0;
  return 0; // Stub: no version info
}

// ============================================================================
// dbghelp Stubs
// ============================================================================

// Stub for dbghelp::MiniDumpWriteDump
BOOL WINAPI stub_MiniDumpWriteDump(
    HANDLE hProcess, DWORD ProcessId, HANDLE hFile, MINIDUMP_TYPE DumpType,
    PMINIDUMP_EXCEPTION_INFORMATION ExceptionParam,
    PMINIDUMP_USER_STREAM_INFORMATION UserStreamParam,
    PMINIDUMP_CALLBACK_INFORMATION CallbackParam) {
  return FALSE; // Stub: minidump not available
}

#pragma warning(pop)
