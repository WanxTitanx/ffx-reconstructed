// FFX Abmap: Init placement grid
int FFX_Abmap_InitPlacementGrid()
{
  int result; // eax
  int n6240; // edi
  unsigned int lpamng; // esi
  char *EntryByIdRange; // ebx
  int v4; // ecx
  int v5; // ecx
  __int16 *v6; // edx
  __int16 n32; // cx
  int v8; // edx
  _WORD *v9; // ebx
  double v10; // st7
  int n7; // edi
  double v12; // st7
  double n32_2; // st6
  int n32_3; // esi
  int v15; // [esp+Ch] [ebp-1Ch] BYREF
  double v16; // [esp+10h] [ebp-18h]
  float v17; // [esp+18h] [ebp-10h]
  int n6240_1; // [esp+1Ch] [ebp-Ch]
  int v19; // [esp+20h] [ebp-8h]
  float n32_1; // [esp+24h] [ebp-4h]

  result = 0; /*0xa5b238*/
  n6240 = 0; /*0xa5b23b*/
  v19 = 0; /*0xa5b23d*/
  n6240_1 = 0; /*0xa5b240*/
  do /*0xa5b3ef*/
  {
    lpamng = lpamng; /*0xa5b243*/
    EntryByIdRange = FFX_Table_GetEntryByIdRange(result, (__int16 *)panel_bin_ptr, &v15); /*0xa5b259*/
    v4 = unk_1A85F98[(unsigned __int8)EntryByIdRange[22]]; /*0xa5b262*/
    *(_DWORD *)(n6240 + lpamng + 63528) = v4 + *(__int16 *)(v4 + 16); /*0xa5b26f*/
    v5 = unk_1A85FE8[(unsigned __int8)EntryByIdRange[22]]; /*0xa5b27a*/
    *(_DWORD *)(n6240 + lpamng + 63532) = v5 + *(__int16 *)(v5 + 16); /*0xa5b287*/
    v6 = *(__int16 **)(n6240 + lpamng + 63528); /*0xa5b28e*/
    if ( v6 ) /*0xa5b297*/
    {
      *(_WORD *)(n6240 + lpamng + 63540) = (v6[22] - v6[16]) >> 4; /*0xa5b2a6*/
      *(_WORD *)(n6240 + lpamng + 63542) = (v6[23] - v6[17]) >> 4; /*0xa5b2bb*/
    }
    else
    {
      *(_DWORD *)(n6240 + lpamng + 63540) = 1048592; /*0xa5b2c5*/
    }
    n32 = *(_WORD *)(n6240 + lpamng + 63540); /*0xa5b2d0*/
    if ( n32 >= 24 ) /*0xa5b2dc*/
    {
      v8 = unk_2305790; /*0xa5b2e6*/
      if ( n32 >= 32 ) /*0xa5b2f0*/
        v8 = unk_2305794; /*0xa5b2f2*/
    }
    else
    {
      v8 = unk_230578C; /*0xa5b2de*/
    }
    *(_DWORD *)(n6240 + lpamng + 63536) = v8 + *(__int16 *)(v8 + 16); /*0xa5b2fe*/
    n32_1 = (float)n32; /*0xa5b30e*/
    *(float *)(n6240 + lpamng + 63544) = n32_1 * 0.00007812499825377017; /*0xa5b31a*/
    if ( !*((_WORD *)EntryByIdRange + 8) || (*((_WORD *)EntryByIdRange + 8) & 0x8000) != 0 ) /*0xa5b333*/
    {
      *(_WORD *)(n6240 + lpamng + 63548) = 4096; /*0xa5b3d4*/
    }
    else
    {
      v9 = (_WORD *)(n6240 + lpamng + 63548); /*0xa5b348*/
      v16 = (double)(n32 >> 1); /*0xa5b34d*/
      v10 = v16; /*0xa5b350*/
      HIDWORD(v16) = 7; /*0xa5b353*/
      n7 = 7; /*0xa5b360*/
      v17 = v10 + 3.0; /*0xa5b363*/
      n32_1 = 0.0; /*0xa5b368*/
      v12 = v17; /*0xa5b36b*/
      do /*0xa5b3c6*/
      {
        n32_2 = n32_1; /*0xa5b36e*/
        n32_3 = (int)n32_1; /*0xa5b378*/
        *v9 = (int)(eff_sin_t[(n32_3 >> 4) & 0xFFF] * v12); /*0xa5b393*/
        v9[1] = -(__int16)(int)(eff_sin_t[((n32_3 + 0x4000) >> 4) & 0xFFF] * v12); /*0xa5b3bb*/
        n32_1 = n32_2 + 9362.2861328125; /*0xa5b3bf*/
        v9 += 2; /*0xa5b3c2*/
        --n7; /*0xa5b3c5*/
      }
      while ( n7 ); /*0xa5b3c6*/
      n6240 = n6240_1; /*0xa5b3c8*/
    }
    n6240 += 48; /*0xa5b3df*/
    result = ++v19; /*0xa5b3e2*/
    n6240_1 = n6240; /*0xa5b3e6*/
  }
  while ( n6240 < 6240 ); /*0xa5b3ef*/
  return result; /*0xa5b3f5*/
}
