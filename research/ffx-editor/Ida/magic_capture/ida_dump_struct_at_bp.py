# IDAPython (debugger): at a breakpoint on MagicFile::setMagicId (x86 thiscall), log the magic id
# arg + the 'this' object bytes. READ-ONLY observation. IDA 7.4+ API.
#
# Usage:
#   1) From ida_anchor_xrefs.csv, find MagicFile::setMagicId start address; put it in BPT_ADDR below.
#   2) IDA > File > Script file... (this file). It arms a debug hook + a breakpoint.
#   3) Debugger > Run; enter a battle; cast Fire. Each hit appends to LOG.
#
# x86 thiscall: this -> ECX ; first stack arg -> [ESP+4] at function entry (before prologue).

import os
import idaapi
import idc
import ida_dbg
import ida_bytes

BPT_ADDR = 0x00000000  # <-- set to MagicFile::setMagicId start (e.g. 0x004ABCDE)
THIS_DUMP_BYTES = 0x80
LOG = r"C:\Users\wande\Documents\ffx-editor-main\work\magic_capture_lab\out\ida_setMagicId.log"


def _log(line):
    try:
        os.makedirs(os.path.dirname(LOG), exist_ok=True)
    except Exception:
        pass
    with open(LOG, "a", encoding="utf-8") as f:
        f.write(line + "\n")
    print(line)


class SetMagicIdHook(ida_dbg.DBG_Hooks):
    def dbg_bpt(self, tid, ea):
        if BPT_ADDR and ea != BPT_ADDR:
            return 0
        try:
            ecx = idc.get_reg_value("ECX")
            esp = idc.get_reg_value("ESP")
            arg0 = ida_bytes.get_dword(esp + 4)
            _log("hit setMagicId @0x%08X : id=%d (0x%X)  this=0x%08X" % (ea, arg0, arg0, ecx))
            data = idc.get_bytes(ecx, THIS_DUMP_BYTES) or b""
            _log("  this[0x%X]: %s" % (THIS_DUMP_BYTES, data.hex()))
        except Exception as e:
            _log("  dump error: %s" % e)
        return 0  # continue execution (read-only)


try:
    _hook
except NameError:
    _hook = SetMagicIdHook()
_hook.hook()

if BPT_ADDR:
    ida_dbg.add_bpt(BPT_ADDR, 0, idaapi.BPT_DEFAULT)
    print("armed bpt @0x%08X. Start the debugger and cast a spell. log -> %s" % (BPT_ADDR, LOG))
else:
    print("set BPT_ADDR to MagicFile::setMagicId, then re-run. log -> %s" % LOG)
