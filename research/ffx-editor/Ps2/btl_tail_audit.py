#!/usr/bin/env python3
"""
btl_tail_audit.py — Jarvis-BTL-TAIL (2026-09-18)

Structured inventory for the wave-13 BTL-TAIL residuals, all VA-verified on
the canonical IDB (C:\\IDA_DB\\ffxoficial.exe.i64, sync16) via ida-pro-mcp.

Scope:
  (a) unk_112A906 / unk_112A908 / unk_112A909  -> the [stat]/[rnd]/[crit]
      env-backed battle debug flags in the 0x112A8F5-0x112A927 debug-flag
      block, plus the full sibling inventory for context.
  (b) FFX_Damage_HitDamagePrecheck @0x78C330    -> per-hit outcome classifier
      (result enum stored to ActionResultChunk.byte0 / hitResultCtx[0]).
  (c) FFX_BtlCmd_ProcessHitDamage post-0x7B0295 -> target-bitmask writeback +
      counter/retaliation result pass.

Outputs:
  docs/reverse/data/wave13/btl_env_debug_flags.csv
  docs/reverse/data/wave13/hitdamage_precheck_codes.csv
  docs/reverse/data/wave13/prochit_tail_map.csv

Usage:
  python3 research_tools/Ps2/btl_tail_audit.py [--out-dir DIR] [--print]

Everything below is static, VA-anchored data — the script runs offline and
only *emits* the tables (the IDA extraction already happened live on sync16;
evidence addresses are recorded per row).
"""

from __future__ import annotations

import argparse
import csv
import os
import sys

# ---------------------------------------------------------------------------
# (a) Env/debug-flag block inventory — 0x112A8F5..0x112A927 + related.
#
# Column sources:
#   env_id/env_key : FFX_Menu2D_EnvKeyTable @0xC443E0 (48 entries {char*,id,x},
#                     key strings @0xB55A48+; id = index into the table)
#   flag_addr      : write site in FFX_Menu2D_ParseEnvConfig @0x7CE380
#                     (case env_id -> flag = n2 & 1), or ATEL write in
#                     FFX_Btl_FieldOpcode_DebugGameplayFlags @0x7A8210.
#   atel_flagid    : case number in DebugGameplayFlags (write) /
#                     GetBattleStateFlag @0x7A2800 (read). "-" = not script-accessible.
#   menu_elemid    : FFX_Dbg_CreateTextElement id in the battle-config debug
#                     window FFX_Menu2D_BlendPackedTransfer @0x7C6D90
#                     (debug window #6, ms_battle_config_flag). "-" = no row.
#   role           : VA-verified semantic (see doc §Tail-resolution).
#   evidence       : primary VA proof sites.
# ---------------------------------------------------------------------------

FLAG_ROWS = [
    # flag_addr, env_id, env_key, atel_flagid, menu_elemid, role, status, evidence
    ("0x112A8F5", "5",  "[exe]",     "-",  "93",  "env flag [exe] — debug-menu toggle (role TBD)", "OPEN",   "ParseEnvConfig@0x7CE45C;Blend@0x7C6F42"),
    ("0x112A8F8", "4",  "[mtkmon]",  "12", "91",  "env flag [mtkmon] — g_DebugFlags[0] (role TBD)", "OPEN",   "ParseEnvConfig@0x7CE44C;ATEL case12@0x7A8265"),
    ("0x112A8F9", "12", "[mtkply]",  "1,2","139", "env flag [mtkply] — read by GetBattleStateFlag cases 1/2 (role TBD)", "OPEN", "ParseEnvConfig@0x7CE4C3;ATEL 1/2"),
    ("0x112A8FA", "13", "[teki]",    "3",  "140", "env flag [teki] (role TBD)", "OPEN",   "ParseEnvConfig@0x7CE4D3"),
    ("0x112A8FB", "14", "[sp0]",     "-",  "-",   "env flag [sp0] = CtbWaitForce1 (CTB wait force)", "PARTIAL","name g_BtlEnvFlag0E_CtbWaitForce1;ParseEnvConfig@0x7CE4E3"),
    ("0x112A8FC", "6",  "[camera]",  "-",  "96",  "env flag [camera] (role TBD)", "OPEN",   "ParseEnvConfig@0x7CE46C"),
    ("0x112A900", "10", "[mag0]",    "-",  "137", "env flag [mag0] (role TBD)", "OPEN",    "ParseEnvConfig@0x7CE4A3"),
    ("0x112A901", "11", "[mp0]",     "4",  "138", "env flag [mp0] (role TBD)", "OPEN",     "ParseEnvConfig@0x7CE4B3"),
    ("0x112A902", "20", "[btmag0]",  "-",  "152", "env flag [btmag0] (role TBD)", "OPEN",   "ParseEnvConfig@0x7CE553"),
    ("0x112A903", "15", "[evmag0]",  "-",  "-",   "env flag [evmag0] (role TBD)", "OPEN",   "ParseEnvConfig@0x7CE4F3"),
    ("0x112A904", "21", "[summon]",  "-",  "154", "env flag [summon] (role TBD)", "OPEN",   "ParseEnvConfig@0x7CE563"),
    ("0x112A905", "24", "[full]",    "-",  "156", "env flag [full] (role TBD)", "OPEN",    "ParseEnvConfig@0x7CE42C"),
    ("0x112A906", "22", "[stat]",    "-",  "155", "FFX_Battle_DbgFlag_StatusEffectsDisabled — set => ComputeHitDamage skips ResolveStatusInflictionMatrix + ResolveHitTargetEffectsAndMultipliers + hitResult+6|=cmd+0x5A (master status/on-hit-effects OFF)", "PROVEN", "gate@0x78EB88;ParseEnvConfig@0x7CE573;TextWriter@0x7CDDC4;Blend@0x7C70BF/0x7C76FE/0x7C7BF4"),
    ("0x112A907", "23", "[willdie]", "-",  "197", "env flag [willdie] (role TBD)", "OPEN",  "ParseEnvConfig@0x7CE583"),
    ("0x112A908", "16", "[rnd]",     "6",  "146", "FFX_Battle_DbgFlag_DamageVarianceOff — passed as useRandomVariance=(1-flag) to all 3 FormulaDispatch channel calls; set => n256=256 deterministic damage", "PROVEN", "disasm 0x78E954/0x78EA90/0x78EB0C (movsx+sub);ParseEnvConfig@0x7CE503;ATEL case6@0x7A82A5"),
    ("0x112A909", "17", "[crit]",    "7",  "147", "FFX_Battle_DbgFlag_CritDisabled — set => ComputeHitDamage skips ComputeCriticalHit (no x2 crits)", "PROVEN", "gate@0x78E9B4;ParseEnvConfig@0x7CE513;ATEL case7@0x7A82B4"),
    ("0x112A90A", "18", "[abs]",     "8",  "148", "FFX_Battle_DbgFlag_StatusAlwaysInflict — set => status infliction always succeeds (pre-existing name)", "PROVEN","named; readers ResolveHitAccuracyAndEffects@0x78AB38, ResolveStatusInflictionMatrix@0x78AFF9"),
    ("0x112A90B", "19", "[print]",   "9",  "149", "env flag [print] (role TBD)", "OPEN",    "ParseEnvConfig@0x7CE543"),
    ("0x112A90C", "25", "[limit]",   "5",  "194", "env flag [limit] (role TBD)", "OPEN",    "ParseEnvConfig@0x7CE593"),
    ("0x112A90D", "33", "[criton]",  "13", "210", "FFX_Battle_DbgFlag_CritAlwaysOn — set => every eligible hit crits (roll bypassed in ComputeCriticalHit)", "PROVEN", "read@0x7897CA;ParseEnvConfig@0x7CE523;ATEL case13@0x7A831E"),
    ("0x112A90E", "-",  "-",         "14", "-",   "FFX_Battle_DbgFlag_DamageForce1 — set => all channel damage forced to 1 (ATEL-only)", "PROVEN", "ComputeHitDamage epilogue@0x78ECBE;ATEL case14@0x7A832D"),
    ("0x112A90F", "-",  "-",         "15", "-",   "FFX_Battle_DbgFlag_DamageForce10000 — set => all channel damage forced to 10000 (ATEL-only)", "PROVEN", "ComputeHitDamage epilogue@0x78ECDF;ATEL case15@0x7A833C"),
    ("0x112A910", "-",  "-",         "16", "-",   "FFX_Battle_DbgFlag_DamageForce100000 — set => all channel damage forced to 100000 (ATEL-only)", "PROVEN", "ComputeHitDamage epilogue@0x78ED00;ATEL case16@0x7A834B"),
    ("0x112A911", "-",  "-",         "17", "-",   "ATEL debug flag 17 (role TBD)", "OPEN",   "ATEL case17@0x7A835A"),
    ("0x112A912", "-",  "-",         "18", "-",   "ATEL debug flag 18 (role TBD)", "OPEN",   "ATEL case18@0x7A8369"),
    ("0x112A913", "-",  "-",         "19", "-",   "ATEL debug flag 19 (role TBD)", "OPEN",   "ATEL case19@0x7A8378"),
    ("0x112A914", "32", "[overkill]","20", "209", "env flag [overkill] (role TBD)", "OPEN",  "ParseEnvConfig@0x7CE613;ATEL case20"),
    ("0x112A915", "27", "[look]",    "24", "196", "env flag [look] (role TBD)", "OPEN",     "ParseEnvConfig@0x7CE5B3"),
    ("0x112A916", "28", "[limitoff]","-",  "199", "env flag [limitoff] (role TBD)", "OPEN",  "ParseEnvConfig@0x7CE5C3"),
    ("0x112A917", "31", "[testeff]", "-",  "204", "env flag [testeff] (role TBD)", "OPEN",   "ParseEnvConfig@0x7CE603"),
    ("0x112A918", "29", "[slow]",    "-",  "200", "env flag [slow] (role TBD)", "OPEN",     "ParseEnvConfig@0x7CE5D3"),
    ("0x112A91A", "30", "[throw]",   "-",  "202", "env flag [throw] (role TBD)", "OPEN",    "ParseEnvConfig@0x7CE5F3"),
    ("0x112A91B", "34", "[map]",     "-",  "212", "env flag [map] (role TBD)", "OPEN",      "ParseEnvConfig@0x7CE623"),
    ("0x112A91C", "35", "[slowmag]", "-",  "201", "env flag [slowmag] (role TBD)", "OPEN",   "ParseEnvConfig@0x7CE5E3"),
    ("0x112A91D", "36", "[plyhp1]",  "-",  "216", "env flag [plyhp1] — toggle calls FFX_Battle_FlagPartyActorsForHpMpUpdate (party HP/MP set to 1)", "PARTIAL","Blend toggle@0x7C7911"),
    ("0x112A91E", "37", "[monhp1]",  "-",  "217", "env flag [monhp1] — toggle calls FFX_Battle_FlagMonsterActorsForHpMpUpdate (monster HP/MP set to 1)", "PARTIAL","Blend toggle@0x7C793C"),
    ("0x112A91F", "38", "[miss]",    "-",  "218", "FFX_Battle_DbgFlag_StatusApplyDisabled — per-status inner gate in ResolveStatusInflictionMatrix (@0x78B02F jnz->skip) + CheckSenseAbility/ResolveHitAccuracyAndEffects/ResolveHitTargetEffects", "PROVEN","named; gates@0x78B02F/0x78B626/0x78A9E8/0x78A868"),
    ("0x112A920", "39", "[wep]",     "-",  "219", "env flag [wep] (role TBD)", "OPEN",      "ParseEnvConfig@0x7CE663"),
    ("0x112A921", "40", "[item]",    "-",  "221", "env flag [item] (role TBD)", "OPEN",     "ParseEnvConfig@0x7CE673"),
    ("0x112A922", "26", "[skip]",    "23", "195", "env flag [skip] (role TBD)", "OPEN",     "ParseEnvConfig@0x7CE5A3"),
    ("0x112A923", "-",  "-",         "25", "-",   "g_EncounterForcedCtbStartMode — ATEL flagId 25 (CTB start mode, encounter-forced)", "PARTIAL","ATEL case25@0x7A83D0;name pre-existing"),
    ("0x112A924", "41", "[camp]",    "-",  "227", "env flag [camp] — toggle calls FFX_Camera_ZeroReturn (camera lock/zero)", "PARTIAL","Blend toggle@0x7C79C4"),
    ("0x112A925", "42", "[localcam]","-",  "229", "env flag [localcam] (role TBD)", "OPEN",  "ParseEnvConfig@0x7CE683"),
    ("0x112A926", "43", "[neckoff]", "-",  "230", "env flag [neckoff] (role TBD)", "OPEN",  "ParseEnvConfig@0x7CE6A3"),
    ("0x112A927", "44", "[focus]",   "-",  "232", "env flag [focus] (role TBD)", "OPEN",    "ParseEnvConfig@0x7CE6B3"),
]

# env keys that do NOT land in the flag block (parse-only actions)
ENV_NONFLAG = [
    ("1",  "[env]",     "table header key (not a case)"),
    ("2",  "[scene]",   "n2_1 local (scene id echo)"),
    ("7",  "[p1]",      "g_BattleU8_112C895 (different region)"),
    ("8",  "[p2]",      "MEMORY[0x112C896] (different region)"),
    ("9",  "[p3]",      "local n2_49 (no global write)"),
    ("45", "[country]", "FFX_Locale_SetLanguageId_thunk(n2)"),
    ("46", "[pal]",     "FFX_System_LocaleStringLookup(n2) + BtlEventName[256]=n2"),
    ("47", "[draw]",    "no ParseEnvConfig case (unhandled in this table)"),
    ("48", "[asia]",    "FFX_Locale_SetLanguageId(n2)"),
]

# ---------------------------------------------------------------------------
# (b) FFX_Damage_HitDamagePrecheck @0x78C330 — outcome-classifier result enum.
# Result stored to hitResultCtx[0] (ComputeHitDamage) / ActionResultChunk[0]
# (ProcessHitActionResultChunks). VA-verified branches from disasm.
# ---------------------------------------------------------------------------

PRECHECK_CODES = [
    # code, condition (disasm), semantic, evidence
    ("0", "no positive dmg; (arg_30&3)!=0 for n2!=2, OR n2==2 && (arg_30&3)==0 && p[2]!=0", "channel-masked / CTB-channel-only hit", "0x78C4E0,0x78C4F4"),
    ("2", "n10000_1<0 && n8!=n8a && !arg_2C  OR  effectCounters[3]", "heal/absorb (negative damage) or ec[3] outcome", "0x78C4B2,0x78C4C1"),
    ("3", "positive dmg && n2==2 && (hitCounters_3&2) && arg_28>=0", "hit variant — actor+0x42A bit1 path (channel mode 2)", "0x78C402"),
    ("4", "positive dmg && n2==1 && (hitCounters_3&1) && !(arg_28&0x40)", "hit variant — actor+0x42A bit0 path (channel mode 1)", "0x78C41D"),
    ("5", "positive dmg, default; also 4|((hc_1&1)==0) on mask path, or 6-(v19!=0)==5 non-crit", "normal hit", "0x78C3D6,0x78C463,0x78C442"),
    ("6", "positive dmg && (arg_30&0x100) && v19==0", "critical hit (crit bit set by ComputeCriticalHit)", "0x78C42B"),
    ("7", "n10000_1>=0 && !p[2] && effectCounters[1] && n8!=n8a && !arg_2C", "counter/cross-target effect outcome", "0x78C511"),
    ("8", "n10000<=0 && hitCounters[1]", "status-cfg bucket hc[1] outcome (flags&0x40 class)", "0x78C476"),
    ("9", "n10000_1>=0 && !p[2] && !ec[1] && hitCounters[0]", "status-cfg bucket hc[0] outcome", "0x78C523"),
    ("10", "n10000_1>=0 && !p[2] && !ec[1] && !hc[0] && effectCounters[0]", "status-cfg bucket ec[0] outcome", "0x78C528"),
    ("11", "n10000<=0 && hitCounters[2]", "status-cfg bucket hc[2] outcome (flags&0x20 class)", "0x78C489"),
    ("12", "n10000<=0 && effectCounters[2]", "status-cfg bucket ec[2] outcome", "0x78C49F"),
]

# ---------------------------------------------------------------------------
# (c) ProcessHitDamage @0x7AFE10 — post-0x7B0295 tail map.
# ---------------------------------------------------------------------------

TAIL_MAP = [
    ("0x7B0295", "LABEL_95", "n2_5 = n2 — per-defender loop continue (defender had no pending hits)", "decompile"),
    ("0x7B02A2", "epilogue", "post-loop: reload actor/ActionPoolEntry/v49", "decompile"),
    ("0x7B02AB", "writeback", "*(float*)&actor->unk_D40[128] = v25 — 31-bit hit-target bitmask stored as float at actor+0xDC0", "mov [edx+0DC0h],ebx"),
    ("0x7B02B7", "writeback", "if v49 < ActionPoolEntry[3]: ActionPoolEntry[4*v49+4] = v25 — per-instance target-mask slot", "decompile"),
    ("0x7B02C5", "writeback", "actor->unk_D24[2] = 0 — clears the action-in-flight flag set at entry (0x7AFEF9)", "decompile"),
    ("0x7B02D6", "counter-pass", "if (HitResultSlot && outcome): zero 31B hit-count array; Random = SelectAiTargetRandom(n2_5,&p_p_i,1)", "decompile"),
    ("0x7B0312", "counter-pass", "MEMORY[0x112CA0E] = p_p_i — FFX_Battle_CounterTargetCount; loop p_p_i_1 < p_p_i", "write site"),
    ("0x7B0320", "counter-pass", "per target v39=Random[i]: v40=a8[v39] (its hit-result slot); v41 = its chunk count", "decompile"),
    ("0x7B0341", "counter-pass", "p_n10000[ch] = -v40[44*v41+56+4*ch] — NEGATE the target's last 44B result-chunk damage triplet (chunk+32/36/40)", "decompile"),
    ("0x7B0366", "counter-pass", "FFX_Battle_ProcessHitActionResultChunks(n2, actor, outcome, HitResultSlot, p_n10000, 0) — append counter chunk to the action record", "call"),
    ("0x7B038F", "trap", "__report_rangecheckfailure — stack/range-check trap for i>=0x1F (dead unless bug)", "decompile"),
]

CSV_DIR_DEFAULT = os.path.join(
    os.path.dirname(os.path.abspath(__file__)), "..", "..",
    "docs", "reverse", "data", "wave13")


def emit(path, header, rows):
    with open(path, "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(header)
        w.writerows(rows)
    return path


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--out-dir", default=CSV_DIR_DEFAULT,
                    help="output directory for CSVs (default: docs/reverse/data/wave13)")
    ap.add_argument("--print", action="store_true", help="print tables to stdout")
    args = ap.parse_args()

    out = os.path.abspath(args.out_dir)
    os.makedirs(out, exist_ok=True)

    f1 = emit(os.path.join(out, "btl_env_debug_flags.csv"),
              ["flag_addr", "env_id", "env_key", "atel_flagid", "menu_elemid",
               "role", "status", "evidence"], FLAG_ROWS)
    f2 = emit(os.path.join(out, "hitdamage_precheck_codes.csv"),
              ["code", "condition", "semantic", "evidence"], PRECHECK_CODES)
    f3 = emit(os.path.join(out, "prochit_tail_map.csv"),
              ["va", "region", "action", "evidence"], TAIL_MAP)

    if args.print:
        for name, rows, hdr in (
            ("btl_env_debug_flags", FLAG_ROWS, None),
            ("hitdamage_precheck_codes", PRECHECK_CODES, None),
            ("prochit_tail_map", TAIL_MAP, None),
        ):
            print(f"\n== {name} ({len(rows)} rows) ==")
            for r in rows:
                print("  " + " | ".join(str(c) for c in r[:5]))

    print(f"\nWrote:\n  {f1}\n  {f2}\n  {f3}")
    print(f"\nRows: flags={len(FLAG_ROWS)} codes={len(PRECHECK_CODES)} tail={len(TAIL_MAP)}")
    print(f"ENV_NONFLAG rows (context, not emitted): {len(ENV_NONFLAG)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
