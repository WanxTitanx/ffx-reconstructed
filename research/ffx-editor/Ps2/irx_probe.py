#!/usr/bin/env python3
"""irx_probe.py — offline probe for PS2 IOP relocatable modules (.IRX).

Mission (Jarvis-IOPSOUND, wave-17 lane 2026-09-18): crack open
`IOPSOUND.IRX` — Square's custom IOP sound driver ("IopSoundDriver",
build 2001/10/29) — to find the voice-set -> voice-bank mapping that the
EE side (`SLPS_250.88`, wave-15 report) proved lives inside this module.

An IRX is an ELF32 file (e_type 0xFF80, MIPS R3000-series — decode with
capstone MIPS32, NOT R5900) whose load image is *module-relative*: every
vaddr is the offset inside the loaded module image (.text base = 0).
The IOP loader adds the runtime base when it applies the REL relocs, so
lui/addiu pairs, j/jal targets and u32 pointers in the file already carry
their final module-relative values — xref scans work directly on file
bytes.

WHAT IT DOES
  - ELF32 header/phdr/shdr census (--sections)
  - .iopmod module info: name, version, gp, entry, sizes (--info)
  - IRX export-table scan (magic 0x41C00000) + import-stub scan
    (magic 0x41E00000): name, BCD version, per-entry fno + stub vaddr,
    best-effort SDK ordinal names (--imports, --exports)
  - REL relocation census per section (--relocs)
  - NUL-terminated ASCII strings (default: .rodata/.data; --all-strings
    opts in to .text where instruction bytes fake printable runs)
  - xref resolution: lui+addiu materialization, lui+load/store data
    access, u32 data pointers, j/jal call sites, gp-relative access
  - targeted capstone MIPS32 disassembly windows + whole-function dump

USAGE
  python3 irx_probe.py --info
  python3 irx_probe.py --imports [--csv out.csv]
  python3 irx_probe.py --exports
  python3 irx_probe.py --relocs
  python3 irx_probe.py --strings <substr|/regex/> [-i] [--all-strings]
  python3 irx_probe.py --xrefs <substr|/regex/> [-i]
  python3 irx_probe.py --xrefs-addr 0x163f0
  python3 irx_probe.py --gp-xrefs 0x193c0
  python3 irx_probe.py --disasm 0x15c94 [--before N] [--after N]
  python3 irx_probe.py --func 0x15c94          # whole function
  python3 irx_probe.py --callers 0x15d24       # jal sites to stub/fn

Default module: canonical IOPSOUND.IRX in the PS2 corpus (override --elf).
Capstone only needed for --disasm/--func; everything else is stdlib.
Exit codes: 0 ok, 2 usage error, 3 capstone missing.
"""

import argparse
import csv
import os
import re
import struct
import sys

DEFAULT_ELF = ('/mnt/ssd-kingston/ffx-reconstructed/ExtrasExtras/'
               'FFXINTERNATIONAL/unipyx/IOPSOUND.IRX')

STR_MIN_LEN = 4
XREF_LOOKAHEAD = 24

SHT_NOBITS = 8
SHT_REL = 9
SHF_ALLOC = 0x2

PT_SCE_IOPMOD = 0x70000080
SHT_SCE_IOPMOD = 0x70000080

IRX_EXPORT_MAGIC = 0x41C00000
IRX_IMPORT_MAGIC = 0x41E00000

R_MIPS = {0: 'NONE', 1: '16', 2: '32', 3: 'REL32', 4: '26', 5: 'HI16',
          6: 'LO16', 7: 'GPREL16', 8: 'LITERAL', 9: 'GOT16', 10: 'PC16',
          11: 'CALL16', 12: 'GPREL32'}

ELF_TYPES = {0: 'NULL', 1: 'REL', 2: 'EXEC', 3: 'DYN', 4: 'CORE',
             0xFF80: 'SCE-IOP-REL-EXEC', 0xFF91: 'SCE-EE-REL'}

# MIPS opcodes (primary opcode field = word>>26)
OP_SPECIAL, OP_REGIMM = 0x00, 0x01
OP_J, OP_JAL, OP_BEQ, OP_BNE, OP_BLEZ, OP_BGTZ = 0x02, 0x03, 0x04, 0x05, 0x06, 0x07
OP_ADDI, OP_ADDIU, OP_SLTI, OP_SLTIU = 0x08, 0x09, 0x0A, 0x0B
OP_ANDI, OP_ORI, OP_XORI, OP_LUI = 0x0C, 0x0D, 0x0E, 0x0F
OP_LB, OP_LH, OP_LWL, OP_LW = 0x20, 0x21, 0x22, 0x23
OP_LBU, OP_LHU, OP_LWR = 0x24, 0x25, 0x26
OP_SB, OP_SH, OP_SWL, OP_SW = 0x28, 0x29, 0x2A, 0x2B
OP_SWR = 0x2E
OP_LWC1, OP_LWC2 = 0x31, 0x33
OP_SWC1, OP_SWC2 = 0x39, 0x3B

REG_GP = 28
REG_RA = 31

I_DEST_OPS = {OP_ADDI, OP_ADDIU, OP_SLTI, OP_SLTIU, OP_ANDI, OP_ORI,
              OP_XORI, OP_LUI, OP_LB, OP_LH, OP_LWL, OP_LW, OP_LBU,
              OP_LHU, OP_LWR, OP_LWC1, OP_LWC2}
MEM_OPS = {OP_LB, OP_LH, OP_LWL, OP_LW, OP_LBU, OP_LHU, OP_LWR,
           OP_SB, OP_SH, OP_SWL, OP_SW, OP_SWR, OP_LWC1, OP_LWC2,
           OP_SWC1, OP_SWC2}
LO_MATERIALIZE_OPS = {OP_ADDIU: 'addiu', OP_ORI: 'ori', OP_XORI: 'xori',
                      OP_ANDI: 'andi', OP_ADDI: 'addi'}
MNEMONIC = {OP_LUI: 'lui', OP_LW: 'lw', OP_SW: 'sw', OP_LB: 'lb',
            OP_LBU: 'lbu', OP_LH: 'lh', OP_LHU: 'lhu', OP_SB: 'sb',
            OP_SH: 'sh', OP_LWL: 'lwl', OP_LWR: 'lwr', OP_SWL: 'swl',
            OP_SWR: 'swr', OP_LWC1: 'lwc1', OP_LWC2: 'lwc2',
            OP_SWC1: 'swc1', OP_SWC2: 'swc2', **LO_MATERIALIZE_OPS}

# ── best-effort IOP SDK ordinal -> name tables ────────────────────────────
# These are the well-known export ordinals of the stock IOP modules that
# IOPSOUND links against (ps2sdk exports.tab order). Names marked with '?'
# in the report mean "SDK ordinal, name probable but unverified against
# this SDK rev" — IOPSOUND was built Oct 2001 (SDK ~2.4.x).
KNOWN_IMPORTS = {
    'libsd': {
        1: 'sceSdInit', 2: 'sceSdSetParam', 3: 'sceSdGetParam',
        4: 'sceSdSetSwitch', 5: 'sceSdGetSwitch', 6: 'sceSdSetAddr',
        7: 'sceSdGetAddr', 8: 'sceSdSetCoreAttr', 9: 'sceSdGetCoreAttr',
        10: 'sceSdNote2Pitch', 11: 'sceSdPitch2Note', 12: 'sceSdProcBatch',
        13: 'sceSdProcBatchEx', 14: 'sceSdProcBatch_C',
        15: 'sceSdVoiceTrans', 16: 'sceSdBlockTrans',
        17: 'sceSdVoiceTransStatus', 18: 'sceSdBlockTransStatus',
        19: 'sceSdSetTransCallback', 20: 'sceSdSetIRQCallback',
        21: 'sceSdSetEffectAttr', 22: 'sceSdGetEffectAttr',
        23: 'sceSdClearEffectWorkArea', 24: 'sceSdSetEffectModeParams',
        25: 'sceSdSetEffectMode', 26: 'sceSdSetEffectType',
        27: 'sceSdGetEffectType', 28: 'sceSdCleanEffectWorkArea',
    },
    'cdvdman': {
        4: 'sceCdInit', 5: 'sceCdStandby', 6: 'sceCdRead', 7: 'sceCdSeek',
        8: 'sceCdGetError', 9: 'sceCdGetToc', 10: 'sceCdSeekF',
        11: 'sceCdReadDVD', 12: 'sceCdStatus', 13: 'sceCdTrayReq',
        14: 'sceCdReadKey?', 15: 'sceCdCallback?', 16: 'sceCdReadClock?',
    },
    'sysmem': {
        4: 'sceAllocMemory', 5: 'sceFreeMemory', 6: 'sceQueryMemSize',
        7: 'sceQueryMaxFreeMemSize', 8: 'sceQueryTotalFreeMemSize',
        9: 'sceQueryBlockAddress', 10: 'sceQueryBlockSize',
        11: 'sceQueryMemoryContext?',
    },
    'intrman': {
        4: 'sceRegisterIntrHandler', 5: 'sceReleaseIntrHandler',
        6: 'sceEnableIntr', 7: 'sceDisableIntr', 8: 'sceCpuSuspendIntr',
        9: 'sceCpuResumeIntr', 10: 'sceQueryIntrContext',
        11: 'sceQueryIntrStack?', 12: 'sceiSetIntc?', 13: 'sceiResetIntc?',
        15: 'sceEnableSubIntr?', 16: 'sceDisableSubIntr?',
        17: 'sceBindSubIntr?', 18: 'sceReleaseSubIntr?',
    },
    'ioman': {
        4: 'open', 5: 'close', 6: 'read', 7: 'write', 8: 'lseek',
        9: 'ioctl', 10: 'remove', 11: 'mkdir', 12: 'rmdir', 13: 'dopen',
        14: 'dclose', 15: 'dread', 16: 'getstat', 17: 'chstat',
        20: 'format?', 21: 'AddDrv?', 22: 'DelDrv?',
    },
    'loadcore': {
        4: 'sceRegisterLibraryEntries', 5: 'sceRegisterNonBootableEntries?',
        6: 'sceReleaseLibraryEntries?', 7: 'sceFindModuleByName?',
        8: 'sceFindModuleByAddress?', 9: 'sceFindModuleByUid?',
        10: 'sceQueryModuleInfo?', 11: 'sceRegisterBootedEntries?',
        12: 'sceRegisterLibraryEntryTable?', 13: 'sceFlushICache?',
        14: 'sceGetResidentEnd?', 15: 'sceGetMemoryLimit?',
    },
    'sifcmd': {
        4: 'sceSifInitCmd', 5: 'sceSifExitCmd', 6: 'sceSifGetSreg',
        7: 'sceSifSetSreg', 8: 'sceSifSetCmdBuffer',
        9: 'sceSifSetSysCmdBuffer', 10: 'sceSifAddCmdHandler',
        11: 'sceSifRemoveCmdHandler', 12: 'sceSifSendCmd',
        13: 'sceSifWriteBackDCache', 14: 'sceSifBindRpc',
        15: 'sceSifCallRpc', 16: 'sceSifCheckStatRpc',
        17: 'sceSifGetOtherData', 18: 'sceSifRegisterRpc',
        19: 'sceSifRemoveRpc', 20: 'sceSifSetRpcQueue',
        21: 'sceSifRemoveRpcQueue', 22: 'sceSifGetNextRequest',
        23: 'sceSifExecRequest', 24: 'sceSifRpcLoop',
    },
    'sifman': {
        4: 'sceSifInit?', 5: 'sceSifSetDma', 6: 'sceSifDmaStat',
        7: 'sceSifSetDChain', 8: 'sceSifSetOneDma?', 9: 'sceSifDmaCount?',
        10: 'sceSifInitIopHeap?', 11: 'sceSifFreeIopHeap?',
        12: 'sceSifAllocIopHeap?', 13: 'sceSifResetIopHeap?',
        14: 'sceSifInitSema?', 15: 'sceSifWaitSema?', 16: 'sceSifSignalSema?',
        17: 'sceSifCheckInit?', 18: 'sceSifInitRebootNotify?',
        19: 'sceSifInit2?', 20: 'sceSifCheckRebootNotify?',
        21: 'sceSifSetSMFLAG?', 22: 'sceSifSetRebootMessage?',
        23: 'sceSifGetSMFLAG?', 24: 'sceSifSync?', 25: 'sceSifRebootIop?',
        26: 'sceSifGetRebootPayload?',
    },
    'sysclib': {
        4: 'look_ctype_table?', 5: 'toupper?', 6: 'tolower?',
        7: 'setjmp?', 8: 'longjmp?', 9: 'wmemset?', 10: 'wmemcpy?',
        11: 'memcmp?', 12: 'memmove?', 13: 'memcpy?', 14: 'memset?',
        15: 'memchr?', 16: 'printf?', 17: 'sprintf?', 18: 'strcat?',
        19: 'strchr?', 20: 'strcmp?', 21: 'strcpy?', 22: 'strlen?',
        23: 'strncmp?', 24: 'strncpy?', 25: 'strrchr?', 26: 'strstr?',
        27: 'strtol?', 28: 'wprintf?', 29: 'gets?', 30: 'atoi?',
    },
    'thbase': {
        4: 'CreateThread', 5: 'DeleteThread', 6: 'StartThread',
        7: 'ExitThread?', 8: 'ExitDeleteThread', 9: 'TerminateThread',
        10: 'TerminateDeleteThread', 11: 'SuspendThread',
        12: 'ResumeThread', 13: 'ChangeThreadPriority',
        14: 'iChangeThreadPriority?', 15: 'RotateThreadReadyQueue',
        16: 'iRotateThreadReadyQueue?', 17: 'ReleaseWaitThread',
        18: 'iReleaseWaitThread', 19: 'GetThreadId',
        20: 'ReferThreadStatus', 21: 'iReferThreadStatus',
        22: 'SleepThread', 23: 'WakeupThread', 24: 'iWakeupThread',
        25: 'CancelWakeupThread', 26: 'iCancelWakeupThread',
        27: 'DelayThread', 28: 'GetSystemTime?', 29: 'SetAlarm?',
        30: 'iSetAlarm?', 31: 'GetSystemLowTime?',
        33: 'SetThreadContext?', 34: 'GetThreadContext?',
        35: 'GetThreadManPriority?', 36: 'ChangeThreadStack?',
    },
    'thsemap': {
        4: 'CreateSema', 5: 'DeleteSema', 6: 'SignalSema',
        7: 'iSignalSema', 8: 'WaitSema', 9: 'PollSema',
        10: 'iPollSema', 11: 'ReferSemaStatus', 12: 'iReferSemaStatus',
    },
    'timrman': {
        4: 'sceAllocHardTimer?', 5: 'sceReferHardTimer?',
        6: 'sceFreeHardTimer?', 7: 'sceSetTimerMode?',
        8: 'sceGetTimerStatus?', 9: 'sceGetTimerCounter?',
        10: 'sceSetTimerCounter?', 11: 'sceSetTimerCompare?',
        12: 'sceGetTimerCompare?', 13: 'sceHoldTimer?',
        14: 'sceStartTimer?', 15: 'sceStopTimer?',
        16: 'sceGetTimerPrecount?', 17: 'sceGetTimerBase?',
        18: 'sceUSec2SysClock?', 19: 'sceSysClock2USec?',
    },
}


def u32(b, o):
    return struct.unpack_from('<I', b, o)[0]


def s16(b, o):
    return struct.unpack_from('<h', b, o)[0]


def _ver_str(v):
    """IRX module/lib version u16 -> 'major.minor' as hex digits.
    0x0214 -> '2.14', 0x0104 -> '1.04' (SDK BCD-nibble convention;
    NOT a fraction — never divide by 256)."""
    return f'{v >> 8:x}.{v & 0xFF:02x}'


# ── ELF parsing ────────────────────────────────────────────────────────────

class Section:
    __slots__ = ('idx', 'name', 'shtype', 'flags', 'addr', 'off', 'size',
                 'link', 'info', 'entsz')

    def __init__(self, idx, name, shtype, flags, addr, off, size, link,
                 info, entsz):
        self.idx, self.name, self.shtype, self.flags = idx, name, shtype, flags
        self.addr, self.off, self.size = addr, off, size
        self.link, self.info, self.entsz = link, info, entsz

    @property
    def loadable(self):
        return bool(self.flags & SHF_ALLOC) and self.shtype != SHT_NOBITS \
            and self.size > 0

    def contains(self, vaddr):
        return self.addr <= vaddr < self.addr + self.size


class IrxImage:
    def __init__(self, path):
        self.path = path
        self.blob = open(path, 'rb').read()
        b = self.blob
        if b[:4] != b'\x7fELF' or b[4] != 1 or b[5] != 1:
            raise ValueError(f'{path}: not a little-endian ELF32')
        self.e_type = struct.unpack_from('<H', b, 16)[0]
        self.e_machine = struct.unpack_from('<H', b, 18)[0]
        self.e_entry = u32(b, 24)
        self.e_phoff = u32(b, 28)
        self.e_shoff = u32(b, 32)
        self.e_flags = u32(b, 36)
        self.e_phentsize, self.e_phnum = struct.unpack_from('<HH', b, 42)
        self.e_shentsize, self.e_shnum, self.e_shstrndx = \
            struct.unpack_from('<HHH', b, 46)
        self.phdrs = []
        for i in range(self.e_phnum):
            o = self.e_phoff + i * self.e_phentsize
            self.phdrs.append(struct.unpack_from('<8I', b, o))
        shstr_off = u32(b, self.e_shoff + self.e_shstrndx * self.e_shentsize
                        + 16)
        self.sections = []
        for i in range(self.e_shnum):
            o = self.e_shoff + i * self.e_shentsize
            (no, st, fl, addr, off, size, lk, inf, _a, esz) = \
                struct.unpack_from('<10I', b, o)
            end = b.index(b'\0', shstr_off + no)
            name = b[shstr_off + no:end].decode('ascii', 'replace')
            self.sections.append(Section(i, name, st, fl, addr, off, size,
                                         lk, inf, esz))
        self.iopmod = self._parse_iopmod()

    def _parse_iopmod(self):
        sec = self.section_named('.iopmod')
        if sec is None:
            # fall back to the PT_SCE_IOPMOD program header
            for (t, off, va, pa, fsz, msz, fl, al) in self.phdrs:
                if t == PT_SCE_IOPMOD and fsz >= 0x18:
                    sec = Section(-1, '.iopmod(phdr)', 0, 0, 0, off, fsz,
                                  0, 0, 0)
                    break
        if sec is None:
            return None
        o = sec.off
        b = self.blob
        (self_link, entry, gp, text_sz, data_sz, bss_sz, ver) = \
            struct.unpack_from('<6IH', b, o)
        name_b = b[o + 0x1a:o + sec.size]
        name = name_b.split(b'\0')[0].decode('ascii', 'replace')
        return {'self_link': self_link, 'entry': entry, 'gp': gp,
                'text_size': text_sz, 'data_size': data_sz,
                'bss_size': bss_sz, 'version': ver, 'name': name,
                'file_off': o}

    def section_at_vaddr(self, vaddr):
        for s in self.sections:
            if s.loadable and s.contains(vaddr):
                return s
        return None

    def vaddr_to_off(self, vaddr):
        s = self.section_at_vaddr(vaddr)
        if s is None:
            return None
        return s.off + (vaddr - s.addr)

    def read_vaddr(self, vaddr, n):
        off = self.vaddr_to_off(vaddr)
        if off is None:
            return None
        return self.blob[off:off + n]

    def section_named(self, name):
        for s in self.sections:
            if s.name == name:
                return s
        return None

    def relocs_for(self, target_name):
        """REL entries of section .rel.<target_name> -> list of dicts."""
        rel = self.section_named('.rel' + target_name)
        tgt = self.section_named(target_name)
        if rel is None or tgt is None:
            return []
        out = []
        for i in range(rel.size // 8):
            r_off, r_info = struct.unpack_from('<2I', self.blob,
                                               rel.off + i * 8)
            out.append({'vaddr': tgt.addr + r_off,
                        'type': r_info & 0xFF,
                        'sym': r_info >> 8})
        return out


# ── IRX export / import tables ─────────────────────────────────────────────

def scan_magics(img, magic):
    """Byte-scan every loadable section for a u32 magic. Returns vaddrs."""
    needle = struct.pack('<I', magic)
    out = []
    for s in img.sections:
        if not s.loadable:
            continue
        data = img.blob[s.off:s.off + s.size]
        start = 0
        while True:
            i = data.find(needle, start)
            if i < 0:
                break
            out.append(s.addr + i)
            start = i + 1
    return out


def decode_exports(img):
    """IRX export table: {magic 0x41C00000, zero, version, name[8],
    funcs[] (u32, NULL-terminated)}. Returns list of dicts."""
    out = []
    for v in scan_magics(img, IRX_EXPORT_MAGIC):
        off = img.vaddr_to_off(v)
        if off is None:
            continue
        zero, ver = struct.unpack_from('<2I', img.blob, off + 4)
        name = img.blob[off + 12:off + 20].split(b'\0')[0]\
            .decode('ascii', 'replace')
        funcs = []
        p = off + 20
        while p + 4 <= len(img.blob):
            w = u32(img.blob, p)
            if w == 0:
                break
            funcs.append(w)
            p += 4
        out.append({'vaddr': v, 'version': ver, 'name': name,
                    'funcs': funcs, 'flags2': zero})
    return out


def decode_imports(img):
    """IRX import stub: {magic 0x41E00000, zero, version, name[8],
    entries[{jump=0x03e00008, fno=0x240000NN}], terminated {0,0}}.
    fno = second word & 0xFFFF (the `li $zero,fno` immediate)."""
    out = []
    for v in scan_magics(img, IRX_IMPORT_MAGIC):
        off = img.vaddr_to_off(v)
        if off is None:
            continue
        zero, ver = struct.unpack_from('<2I', img.blob, off + 4)
        name = img.blob[off + 12:off + 20].split(b'\0')[0]\
            .decode('ascii', 'replace')
        entries = []
        p = off + 20
        while p + 8 <= len(img.blob):
            jump, fno = struct.unpack_from('<2I', img.blob, p)
            if jump == 0 and fno == 0:
                break
            entries.append({'vaddr': v + (p - off),
                            'jump': jump,
                            'fno': fno & 0xFFFF})
            p += 8
        known = KNOWN_IMPORTS.get(name, {})
        for e in entries:
            e['probable'] = known.get(e['fno'], '')
        out.append({'vaddr': v, 'version': ver, 'name': name,
                    'entries': entries, 'flags2': zero})
    return out


# ── string extraction ──────────────────────────────────────────────────────

def extract_strings(img, min_len=STR_MIN_LEN, include_text=False):
    _WS = frozenset((0x09, 0x0A, 0x0D))
    out = []
    for s in img.sections:
        if not s.loadable:
            continue
        if not include_text and s.name == '.text':
            continue
        data = img.blob[s.off:s.off + s.size]
        i = 0
        n = len(data)
        while i < n:
            if 0x20 <= data[i] < 0x7F:
                j = i
                ok = True
                while j < n:
                    c = data[j]
                    if c == 0:
                        break
                    if not (0x20 <= c < 0x7F or c in _WS):
                        ok = False
                        break
                    j += 1
                if ok and j < n and data[j] == 0 and j - i >= min_len:
                    out.append((s.off + i, s.addr + i, s.name,
                                data[i:j].decode('ascii')))
                i = j + 1
            else:
                i += 1
    return out


def _matcher(arg, ci):
    if len(arg) > 2 and arg.startswith('/') and arg.endswith('/'):
        rx = re.compile(arg[1:-1], re.IGNORECASE if ci else 0)
        return rx.search
    needle = arg.lower() if ci else arg
    return lambda s: needle in (s.lower() if ci else s)


# ── xref resolvers ─────────────────────────────────────────────────────────

def _hi_lo(vaddr):
    hi = (vaddr + 0x8000) >> 16
    lo = vaddr - (hi << 16)
    return hi & 0xFFFF, lo & 0xFFFF


def jump_xrefs(img, vaddr):
    """`jal`/`j` sites targeting `vaddr` (direct call encoding)."""
    text = img.section_named('.text')
    if text is None:
        return []
    if (vaddr & 0xF0000000) != (text.addr & 0xF0000000) or vaddr & 3:
        return []
    idx = vaddr >> 2
    data = img.blob[text.off:text.off + text.size]
    hits = []
    for i in range(text.size // 4):
        w = u32(data, i * 4)
        op = w >> 26
        if op in (OP_J, OP_JAL) and (w & 0x3FFFFFF) == idx:
            hits.append({'addr': text.addr + i * 4,
                         'kind': 'jal' if op == OP_JAL else 'j'})
    return hits


def code_xrefs(img, vaddr):
    """lui+op address formation sites in .text for `vaddr`."""
    text = img.section_named('.text')
    if text is None:
        return []
    hiA, loA = _hi_lo(vaddr)
    hiB, loB = (vaddr >> 16) & 0xFFFF, vaddr & 0xFFFF
    data = img.blob[text.off:text.off + text.size]
    n_instr = text.size // 4
    hits = []
    for i in range(n_instr):
        w = u32(data, i * 4)
        if w >> 26 != OP_LUI:
            continue
        imm = w & 0xFFFF
        if imm not in (hiA, hiB):
            continue
        rt = (w >> 16) & 0x1F
        lui_addr = text.addr + i * 4
        conv_A = (imm == hiA)
        for k in range(1, XREF_LOOKAHEAD + 1):
            j = i + k
            if j >= n_instr:
                break
            w2 = u32(data, j * 4)
            op2 = w2 >> 26
            rs2 = (w2 >> 21) & 0x1F
            rt2 = (w2 >> 16) & 0x1F
            rd2 = (w2 >> 11) & 0x1F
            imm2 = w2 & 0xFFFF
            addr2 = text.addr + j * 4
            if rs2 == rt and op2 in LO_MATERIALIZE_OPS:
                if imm2 == loA or imm2 == loB:
                    hits.append({
                        'lui_addr': lui_addr, 'pair_addr': addr2,
                        'kind': 'addr-materialize',
                        'pair_desc': f'{MNEMONIC[op2]} $r{rt},$r{rt},0x{imm2:04x}'})
                    break
            if rs2 == rt and op2 in MEM_OPS:
                if imm2 == loA:
                    hits.append({
                        'lui_addr': lui_addr, 'pair_addr': addr2,
                        'kind': 'data-access',
                        'pair_desc': f'{MNEMONIC.get(op2, op2)} 0x{imm2:04x}($r{rt})'})
                    break
            if op2 in I_DEST_OPS and rt2 == rt:
                break
            if op2 == OP_SPECIAL and rd2 == rt:
                break
    return hits


def data_xrefs(img, vaddr):
    """u32 little-endian words == vaddr in loadable data sections
    (pointer tables — module-relative pointers read straight out)."""
    needle = struct.pack('<I', vaddr)
    hits = []
    for s in img.sections:
        if not s.loadable or s.name == '.text':
            continue
        data = img.blob[s.off:s.off + s.size]
        start = 0
        while True:
            idx = data.find(needle, start)
            if idx < 0:
                break
            hits.append({'off': s.off + idx, 'vaddr': s.addr + idx,
                         'section': s.name})
            start = idx + 1
    return hits


def gp_xrefs(img, gp, target):
    """Find .text `op rt, imm($gp)` sites whose effective address ==
    `target` (imm = target - gp). Catches small-data globals that never
    show up via lui chains."""
    text = img.section_named('.text')
    if text is None:
        return []
    imm = (target - gp) & 0xFFFF
    data = img.blob[text.off:text.off + text.size]
    hits = []
    for i in range(text.size // 4):
        w = u32(data, i * 4)
        op = w >> 26
        if op not in MEM_OPS and op not in LO_MATERIALIZE_OPS:
            continue
        if (w >> 21) & 0x1F == REG_GP and (w & 0xFFFF) == imm:
            hits.append({'addr': text.addr + i * 4,
                         'pair_desc': f'{MNEMONIC.get(op, hex(op))} '
                                      f'$r{(w >> 16) & 0x1F},{imm:#x}($gp)'})
    return hits


# ── disassembly ────────────────────────────────────────────────────────────

def _md():
    try:
        from capstone import Cs, CS_ARCH_MIPS, CS_MODE_MIPS32, \
            CS_MODE_LITTLE_ENDIAN
    except ImportError:
        return None
    return Cs(CS_ARCH_MIPS, CS_MODE_MIPS32 | CS_MODE_LITTLE_ENDIAN)


def disasm(img, vaddr, before, after):
    md = _md()
    if md is None:
        sys.stderr.write('capstone required for --disasm '
                         '(pip install capstone)\n')
        return 3
    sec = img.section_at_vaddr(vaddr)
    if sec is None:
        sys.stderr.write(f'vaddr {vaddr:#x} is not inside a loaded '
                         'section\n')
        return 2
    start = max(vaddr - before * 4, sec.addr)
    end = min(vaddr + after * 4, sec.addr + sec.size)
    code = img.read_vaddr(start, end - start)
    pos = 0
    while pos < len(code):
        addr = start + pos
        ins = next(md.disasm(code[pos:pos + 4], addr), None)
        mark = '>>' if addr == vaddr else '  '
        if ins is None:
            print(f'{mark} {addr:#010x}: {code[pos:pos + 4].hex():8}  '
                  f'.word      0x{u32(code, pos):08x}')
        else:
            print(f'{mark} {ins.address:#010x}: {ins.bytes.hex():8}  '
                  f'{ins.mnemonic:10} {ins.op_str}')
        pos += 4
    return 0


def func_bounds(img, vaddr):
    """Heuristic function extents: back up to the nearest `addiu
    $sp,$sp,-N` prologue (or jr $ra boundary), forward to the first
    `jr $ra` + delay slot. Used by --func."""
    text = img.section_named('.text')
    if text is None or not text.contains(vaddr):
        return None
    data = img.blob[text.off:text.off + text.size]
    n = text.size // 4

    def word(i):
        return u32(data, i * 4)

    i = (vaddr - text.addr) // 4
    start = i
    # walk back at most 0x400 instrs for a prologue or a previous ret
    for k in range(i, max(i - 0x400, 0), -1):
        w = word(k)
        op = w >> 26
        rs = (w >> 21) & 0x1F
        rt = (w >> 16) & 0x1F
        imm = w & 0xFFFF
        # addiu $sp,$sp,-N  (classic prologue)
        if op == OP_ADDIU and rs == 29 and rt == 29 and imm & 0x8000:
            start = k
            break
        # jr $ra (0x03e00008) — previous function end; start just after
        # its delay slot
        if w == 0x03E00008:
            start = min(k + 2, i)
            break
    else:
        start = max(i - 0x400, 0)
    end = i
    for k in range(i, min(i + 0x800, n - 1)):
        if word(k) == 0x03E00008:      # jr $ra; include delay slot
            end = k + 2
            break
    else:
        end = min(i + 0x800, n)
    return text.addr + start * 4, text.addr + end * 4


def disasm_func(img, vaddr):
    md = _md()
    if md is None:
        sys.stderr.write('capstone required for --func '
                         '(pip install capstone)\n')
        return 3
    b = func_bounds(img, vaddr)
    if b is None:
        sys.stderr.write(f'vaddr {vaddr:#x} not in .text\n')
        return 2
    start, end = b
    print(f'# func window {start:#x}..{end:#x} '
          f'({(end - start) // 4} instrs)')
    code = img.read_vaddr(start, end - start)
    pos = 0
    while pos < len(code):
        addr = start + pos
        ins = next(md.disasm(code[pos:pos + 4], addr), None)
        mark = '>>' if addr == vaddr else '  '
        if ins is None:
            print(f'{mark} {addr:#010x}: {code[pos:pos + 4].hex():8}  '
                  f'.word      0x{u32(code, pos):08x}')
        else:
            print(f'{mark} {ins.address:#010x}: {ins.bytes.hex():8}  '
                  f'{ins.mnemonic:10} {ins.op_str}')
        pos += 4
    return 0


# ── CLI helpers ────────────────────────────────────────────────────────────

def _write_csv(path, fields, rows):
    os.makedirs(os.path.dirname(os.path.abspath(path)) or '.',
                exist_ok=True)
    with open(path, 'w', newline='') as f:
        w = csv.writer(f)
        w.writerow(fields)
        w.writerows(rows)
    print(f'wrote {len(rows)} rows -> {path}')


def _resolve_and_print(img, strs):
    rows = []
    for off, v, s, t in strs:
        rows.append(('STRING', f'{v:#x}', s, t, '', ''))
        for h in code_xrefs(img, v):
            rows.append(('code-xref', f"{h['lui_addr']:#x}",
                         f"{h['pair_addr']:#x}", h['kind'],
                         h['pair_desc'], t))
        for h in jump_xrefs(img, v):
            rows.append(('jmp-xref', f"{h['addr']:#x}", '', h['kind'],
                         '', t))
        for h in data_xrefs(img, v):
            rows.append(('data-xref', f"{h['vaddr']:#x}",
                         h['section'], 'u32 ptr', f"off {h['off']:#x}", t))
    for r in rows:
        print('  '.join(str(c) for c in r))
    print(f'# {len(rows)} rows')
    return rows


def main(argv=None):
    ap = argparse.ArgumentParser(
        description='IOPSOUND.IRX probe (iopmod/imports/relocs/strings/'
                    'xrefs/disasm)')
    ap.add_argument('--elf', default=DEFAULT_ELF)
    ap.add_argument('-i', '--ignore-case', action='store_true')
    ap.add_argument('--info', action='store_true',
                    help='ELF + .iopmod module info')
    ap.add_argument('--sections', action='store_true')
    ap.add_argument('--imports', action='store_true')
    ap.add_argument('--exports', action='store_true')
    ap.add_argument('--relocs', action='store_true')
    ap.add_argument('--strings', metavar='PAT', nargs='?', const='',
                    help='strings matching PAT (empty = all)')
    ap.add_argument('--all-strings', action='store_true',
                    help='include .text in string scan (noisy)')
    ap.add_argument('--xrefs', metavar='PAT')
    ap.add_argument('--xrefs-addr', metavar='VADDR')
    ap.add_argument('--gp-xrefs', metavar='VADDR',
                    help='find gp-relative accesses to module vaddr')
    ap.add_argument('--callers', metavar='VADDR',
                    help='jal/j sites to vaddr (alias of jump xrefs)')
    ap.add_argument('--disasm', metavar='VADDR')
    ap.add_argument('--disasm-off', metavar='FOFF')
    ap.add_argument('--func', metavar='VADDR',
                    help='disasm the whole function containing vaddr')
    ap.add_argument('--before', type=int, default=16)
    ap.add_argument('--after', type=int, default=48)
    ap.add_argument('--csv', metavar='OUT.csv')
    ap.add_argument('--min-len', type=int, default=STR_MIN_LEN)
    args = ap.parse_args(argv)

    img = IrxImage(args.elf)
    mod = img.iopmod or {}
    print(f'# {args.elf}')
    print(f'# ELF32 machine={img.e_machine} '
          f'type={ELF_TYPES.get(img.e_type, img.e_type)} '
          f'entry={img.e_entry:#x} '
          f'module="{mod.get("name", "?")}" '
          f'ver={_ver_str(mod.get("version", 0))} gp={mod.get("gp", 0):#x}')

    did = False

    if args.info:
        did = True
        print(f'e_entry   = {img.e_entry:#x}')
        print(f'e_phnum   = {img.e_phnum}  e_shnum = {img.e_shnum}')
        for i, (t, off, va, pa, fsz, msz, fl, al) in enumerate(img.phdrs):
            tn = 'PT_SCE_IOPMOD' if t == PT_SCE_IOPMOD else \
                ('PT_LOAD' if t == 1 else hex(t))
            print(f'phdr[{i}] {tn:13} off={off:#x} vaddr={va:#x} '
                  f'filesz={fsz:#x} memsz={msz:#x} flags={fl:#x}')
        if img.iopmod:
            m = img.iopmod
            print(f'.iopmod @ file off {m["file_off"]:#x}:')
            print(f'  self_link = {m["self_link"]:#x}')
            print(f'  entry     = {m["entry"]:#x}')
            print(f'  gp        = {m["gp"]:#x}')
            print(f'  text_size = {m["text_size"]:#x}')
            print(f'  data_size = {m["data_size"]:#x}')
            print(f'  bss_size  = {m["bss_size"]:#x}')
            print(f'  version   = {m["version"]:#x} '
                  f'({_ver_str(m["version"])})')
            print(f'  name      = {m["name"]}')

    if args.sections:
        did = True
        rows = []
        for i, s in enumerate(img.sections):
            rows.append((i, s.name, f'{s.shtype:#x}', f'{s.flags:#x}',
                         f'{s.addr:#x}', f'{s.off:#x}', f'{s.size:#x}',
                         s.link, s.info))
            print(f'shdr[{i:2}] {s.name:16} type={s.shtype:#010x} '
                  f'flags={s.flags:#x} addr={s.addr:#x} off={s.off:#x} '
                  f'size={s.size:#x} link={s.link} info={s.info}')
        if args.csv:
            _write_csv(args.csv,
                       ['idx', 'name', 'type', 'flags', 'vaddr', 'off',
                        'size', 'link', 'info'], rows)

    if args.exports:
        did = True
        exps = decode_exports(img)
        if not exps:
            print('# NO export tables (0x41C00000 absent) — module has no '
                  'library exports; interface is runtime (SIF RPC/cmd '
                  'service)')
        rows = []
        for e in exps:
            print(f'export "{e["name"]}" v{_ver_str(e["version"])} '
                  f'@ {e["vaddr"]:#x} — {len(e["funcs"])} funcs')
            for n, f in enumerate(e['funcs']):
                rows.append((e['name'], n, f'{f:#x}'))
                print(f'  [{n:2}] {f:#x}')
        if args.csv:
            _write_csv(args.csv, ['lib', 'fno', 'func_vaddr'], rows)

    if args.imports:
        did = True
        rows = []
        for st in decode_imports(img):
            print(f'import "{st["name"]}" v{_ver_str(st["version"])} '
                  f'@ {st["vaddr"]:#x} — {len(st["entries"])} entries')
            for e in st['entries']:
                tag = f'  ~{e["probable"]}' if e['probable'] else ''
                rows.append((st['name'], f'{st["version"]:#x}',
                             f"{e['vaddr']:#x}", e['fno'],
                             f"{e['jump']:#x}", e['probable']))
                print(f'  fno {e["fno"]:3} @ {e["vaddr"]:#x}  '
                      f'jump={e["jump"]:#x}{tag}')
        if args.csv:
            _write_csv(args.csv,
                       ['lib', 'version', 'stub_vaddr', 'fno',
                        'jump_word', 'probable_name'], rows)

    if args.relocs:
        did = True
        rows = []
        for s in img.sections:
            rs = img.relocs_for(s.name)
            if not rs:
                continue
            by_type = {}
            for r in rs:
                by_type[r['type']] = by_type.get(r['type'], 0) + 1
                rows.append((s.name, f"{r['vaddr']:#x}",
                             R_MIPS.get(r['type'], r['type']), r['sym']))
            desc = ' '.join(f'R_MIPS_{R_MIPS.get(t, t)}x{n}'
                            for t, n in sorted(by_type.items()))
            print(f'.rel{s.name}: {len(rs)} relocs  {desc}')
        if args.csv:
            _write_csv(args.csv, ['section', 'vaddr', 'type', 'sym'],
                       rows)

    if args.strings is not None:
        did = True
        match = _matcher(args.strings, args.ignore_case) \
            if args.strings else (lambda s: True)
        strs = [(o, v, s, t) for o, v, s, t in
                extract_strings(img, args.min_len, args.all_strings)
                if match(t)]
        for o, v, s, t in strs:
            print(f'{o:#>10x} {v:#>10x} {s:>10} {t!r}')
        print(f'# {len(strs)} strings')
        if args.csv:
            _write_csv(args.csv, ['file_off', 'vaddr', 'section', 'text'],
                       [(f'{o:#x}', f'{v:#x}', s, t) for o, v, s, t in
                        strs])

    if args.xrefs is not None:
        did = True
        match = _matcher(args.xrefs, args.ignore_case)
        strs = [(o, v, s, t) for o, v, s, t in
                extract_strings(img, args.min_len, args.all_strings)
                if match(t)]
        rows = _resolve_and_print(img, strs)
        if args.csv:
            _write_csv(args.csv,
                       ['kind', 'site', 'detail1', 'detail2', 'detail3',
                        'string'], rows)

    if args.xrefs_addr is not None:
        did = True
        v = int(args.xrefs_addr, 0)
        print(f'# xrefs to {v:#x}')
        for h in code_xrefs(img, v):
            print(f"  code {h['lui_addr']:#x} -> {h['pair_addr']:#x} "
                  f"{h['kind']} {h['pair_desc']}")
        for h in jump_xrefs(img, v):
            print(f"  jump {h['addr']:#x}  {h['kind']}")
        for h in data_xrefs(img, v):
            print(f"  data {h['vaddr']:#x} ({h['section']} off "
                  f"{h['off']:#x})")

    if args.gp_xrefs is not None:
        did = True
        gp = (img.iopmod or {}).get('gp')
        v = int(args.gp_xrefs, 0)
        if gp is None:
            print('# no gp in .iopmod — cannot resolve')
        else:
            print(f'# gp-relative xrefs to {v:#x} (gp={gp:#x}, '
                  f'imm={v - gp:#x})')
            for h in gp_xrefs(img, gp, v):
                print(f"  {h['addr']:#x}  {h['pair_desc']}")

    if args.callers is not None:
        did = True
        v = int(args.callers, 0)
        print(f'# jal/j callers of {v:#x}')
        for h in jump_xrefs(img, v):
            print(f"  {h['addr']:#x}  {h['kind']}")

    if args.disasm is not None:
        did = True
        rc = disasm(img, int(args.disasm, 0), args.before, args.after)
        if rc:
            return rc

    if args.disasm_off is not None:
        did = True
        foff = int(args.disasm_off, 0)
        # translate file off -> vaddr via containing section
        tgt = None
        for s in img.sections:
            if s.loadable and s.off <= foff < s.off + s.size:
                tgt = s.addr + (foff - s.off)
                break
        if tgt is None:
            print(f'# file off {foff:#x} not in a loadable section')
            return 2
        rc = disasm(img, tgt, args.before, args.after)
        if rc:
            return rc

    if args.func is not None:
        did = True
        rc = disasm_func(img, int(args.func, 0))
        if rc:
            return rc

    if not did:
        ap.print_help()
    return 0


if __name__ == '__main__':
    sys.exit(main())
