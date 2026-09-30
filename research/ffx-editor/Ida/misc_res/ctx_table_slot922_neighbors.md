# ctx-table neighborhood of slot 922 (band-B) — g_FFX_MagicHostContextTable

Base `0xC64CE8`, 4-byte slots. Slot numbers below are **0-based**; the mission's
"slot 922" (0xC65B4C) = 0-based index **921** (byte offset 0xE64).

| idx | addr | target | identity |
|----:|------|--------|----------|
| 889–903 | 0xC65ACC–0xC65B04 | 0x63Fxxx | `Phyre_Class_*` offset getters/setters bank (host Phyre object accessors) |
| 904 | 0xC65B08 | 0x644D90 | `FFX_Magic_CallDrawParamSet00` |
| 905 | 0xC65B0C | 0x642FB0 | `FFX_DynamicLight_RegisterType4_Wrapper` |
| 906 | 0xC65B10 | 0x63DA90 | `FFX_Magic_ApplyShaderStateAll` |
| 907 | 0xC65B14 | 0x7114B0 | `FFX_KR_DivideTimingBy3` |
| 908 | 0xC65B18 | 0x71A5C0 | `FFX_BattleModel_DrawPrimitive` |
| 909 | 0xC65B1C | 0x713370 | `FFX_KR_ResetParticleSlotCounters` |
| 910 | 0xC65B20 | 0x712CB0 | `FFX_KR_AdjustPppBufferOffsets` |
| 911 | 0xC65B24 | 0x7FA5F0 | `FFX_MagicCoreOp_90_TextureDispatch` |
| 912 | 0xC65B28 | 0x642FF0 | `FFX_DynamicLight_RegisterType5_Wrapper` |
| 913 | 0xC65B2C | 0x639320 | `FFX_Magic_ReleaseSideOpResources` |
| 914 | 0xC65B30 | 0x642010 | `FFX_Shader_SetBallShaderParams` |
| 915 | 0xC65B34 | 0x6393F0 | `ResourcePool_FreeOrphanedEntry_Tag1001` |
| 916 | 0xC65B38 | 0x7BD7E0 | `FFX_Camera_Internal_OpAM` |
| 917 | 0xC65B3C | 0x9DB150 | `FFX_Magic_GetFrameDelta64` |
| 918 | 0xC65B40 | 0x643990 | `FFX_Global_SetCEC190` |
| 919 | 0xC65B44 | 0x1133398 | `g_MsSetDeath_NoDeathMotion` (**data global**, not fn — death-motion suppress flag, read by `FFX_Field_ResolveMotionClassToClip` 0x7A8DE7+) |
| 920 | 0xC65B48 | 0x63A470 | `FFX_Magic_Overlay_UpdateVertices` |
| **921** | **0xC65B4C** | **0xC3BBA8** | **band-B = `pppSysProgTbl+145` alias-bank base** (PPP opcode descriptor table, stride 0x28) |
| 922 | 0xC65B50 | 0x63C550 | `SetVisibilityStateOnObjects` |
| 923 | 0xC65B54 | 0x9DAFB0 | `FFX_Magic_SetTextureDescriptorFlag` |
| 924 | 0xC65B58 | 0x63A5D0 | `Phyre_RBTree_LowerBound` |
| 925 | 0xC65B5C | 0x794030 | `FFX_Battle_AccessCurrentActorData` |
| 926 | 0xC65B60 | 0x793660 | `FFX_Btl_IsValidBattleSlot` |
| 927 | 0xC65B64 | 0x639470 | `ResourcePool_FreeOrphanedEntry_Tag8001` |
| 928 | 0xC65B68 | 0x644F80 | `FFX_Field_ResetFieldServiceState` |
| 929 | 0xC65B6C | 0x63DC70 | `FFX_Field_ReleaseRefCountedPtr` |
| 930 | 0xC65B70 | 0x63D8C0 | `FFX_Shader_SetupClipPlaneParam` |
| 931 | 0xC65B74 | 0x644E50 | `FFX_Async_PostCommandType5` |
| 932 | 0xC65B78 | 0x6459F0 | `FFX_Magic_StackCallbackGroupRollback` |
| 933 | 0xC65B7C | 0x643820 | `FFX_MagicHost_UpdateShadowClrScaleThunk` |

Reading: the band-B pointer sits in a run of generic host-service exports
(render/shader/camera/battle accessors) — it is just one more pointer the DLL
side caches at `InitMagicPRX` time, not a special object.
