// Function: FFX_MagicCoreOp_32_LoadedByOPURecordSpawn
// Address: 0x80af90
// [Jarvis naming goal 2026-06-17] Magic core opcode 0x32 handler: record spawn/load path anchored by literal LoadedByOPU_UNIT; allocates and initializes an OPU-loaded record.
int __cdecl FFX_MagicCoreOp_32_LoadedByOPURecordSpawn(int a1, int a2)
{
  bool v2; // zf
  __int16 v4; // ax
  int v5; // edi
  int v6; // eax
  _BYTE dst[76]; // [esp-4Ch] [ebp-BCh] BYREF
  int v8; // [esp+Ch] [ebp-64h]
  int v9; // [esp+10h] [ebp-60h]
  int v10; // [esp+14h] [ebp-5Ch]
  int v11; // [esp+18h] [ebp-58h]
  int v12; // [esp+1Ch] [ebp-54h]
  _DWORD src[19]; // [esp+20h] [ebp-50h] BYREF

  v2 = *(_WORD *)(a1 + 530) == 0;
  v12 = a2;
  if ( v2 )
  {
    v10 = *(_DWORD *)(a1 + 544);
    v9 = (*(__int16 *)(a1 + 538) >> 12) & 3;
    v4 = sub_801620(a1 + 768, v9);
    v5 = *(_DWORD *)(a1 + 800) + (v4 << 8);
    v11 = v4;
    v8 = v5;
    sub_801120((_DWORD *)v5);
    sub_800DD0(a1 + 768, v5, v10);
    *(_WORD *)(v5 + 26) = (*(_WORD *)(a1 + 770))++;
    if ( *(_WORD *)(a1 + 770) >= 0xFFF0u )
      *(_WORD *)(a1 + 770) = 0x8000;
    *(_DWORD *)v5 = unknown_libname_742(v12 + *(__int16 *)(v12 + 2));
    src[0] = v10;
    src[3] = v11;
    src[1] = v5;
    src[2] = 0;
    src[5] = 0;
    sprintf((char *const)&src[6], "LoadedByOPU_UNIT");
    if ( v9 == 1 )
    {
      qmemcpy(dst, src, sizeof(dst));
      nullsub_106(v11);
      v5 = v8;
    }
    v6 = v12;
    *(_DWORD *)a1 = v5;
    return v6 + 4;
  }
  else
  {
    *(_DWORD *)a1 = a1;
    return a2 + 4;
  }
}
