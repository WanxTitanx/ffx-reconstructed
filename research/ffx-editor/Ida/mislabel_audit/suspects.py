import sys, json
sys.path.insert(0, "work/_mislabel_audit")
from apply_renames import call, init
init()
SUSPECTS = [
 ("0x887a00","FFX_File_Exists","trampolines to FFX_SoundSpuDma_CopyStringAndReadResult (copies str to sound global + submits DMA + returns result) — file-existence role unproven; callers Encounter_Loader/AnimatedBg_LoadInit suggest a probe op, but target is DMA-path"),
 ("0x8ac2a0","FFX_Locale_GetCurrentId","jmp FFX_JobSchedule_GetThreadDataPlus4 (returns job/thread data+4) — locale-id role unproven; called by BtlUI_GetActorDataFloatPtr, likely an ABI/shared alias rather than a real locale getter"),
 ("0x872410","FFX_Encounter_SetFlagAndLoadMagic","sets local flag=1 then jmps FFX_MagicFile_LoadWrapper_B — load+set plausible but Encounter-vs-MagicFile subsystem claim unverified"),
 ("0x8854c0","FFX_Sound_SpuDma_TestAndFreeChannel","body = call FFX_SoundStub_Return0; ret — returns 0 stub; 'TestAndFreeChannel' overclaims (no test/free logic)"),
 ("0x903300","FFX_Save_SpawnSaveLoadMenu","calls (now) FFX_Save_ReturnArg0_stub + Menu_PoolAllocatorB — allocates a menu obj but inner init is stubbed; 'Spawn' overclaims the init side"),
 ("0x8b35b0","FFX_Save_FileClose","call Save_SetFileHandle(0) — plausibly 'close handle'; verified-OK but paired with mislabeled FileOpen/FileRead family; low-priority suspect"),
 ("0x7a29a0","FFX_Btl_FieldOpcode_AttachWeapon","name fine (PopOperand+AttachWeaponToActor) but confirm arg-order; low-priority"),
]
items=[{"addr":a,"comment":f"// mislabel-candidate: {ev} [Jarvis-DEVIN mislabel-audit 2026-09-16]"} for a,_,ev in SUSPECTS]
for i in range(0,len(items),25):
    for t in call("append_comments",{"items":items[i:i+25]}):
        print(t[:200])
json.dump([{"addr":a,"old":o,"verdict":"SUSPECTED","evidence":e} for a,o,e in SUSPECTS],
          open("work/_mislabel_audit/suspects.json","w"),indent=1)
print("suspect comments added:",len(SUSPECTS))
