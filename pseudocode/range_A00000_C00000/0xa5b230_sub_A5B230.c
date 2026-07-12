// Function: sub_A5B230
// Address: 0xa5b230
// Size: 0x1cc
// Prototype: 

int sub_A5B230()
{
  int result; // eax
  int n6240; // edi
  int v2; // esi
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

  result = 0;
  n6240 = 0;
  v19 = 0;
  n6240_1 = 0;
  do
  {
    v2 = dword_2305834[0];
    EntryByIdRange = FFX_Table_GetEntryByIdRange(result, (__int16 *)unk_1A860E0, &v15);
    v4 = dword_1A85F98[(unsigned __int8)EntryByIdRange[22]];
    *(_DWORD *)(n6240 + v2 + 63528) = v4 + *(__int16 *)(v4 + 16);
    v5 = dword_1A85FE8[(unsigned __int8)EntryByIdRange[22]];
    *(_DWORD *)(n6240 + v2 + 63532) = v5 + *(__int16 *)(v5 + 16);
    v6 = *(__int16 **)(n6240 + v2 + 63528);
    if ( v6 )
    {
      *(_WORD *)(n6240 + v2 + 63540) = (v6[22] - v6[16]) >> 4;
      *(_WORD *)(n6240 + v2 + 63542) = (v6[23] - v6[17]) >> 4;
    }
    else
    {
      *(_DWORD *)(n6240 + v2 + 63540) = 1048592;
    }
    n32 = *(_WORD *)(n6240 + v2 + 63540);
    if ( n32 >= 24 )
    {
      v8 = unk_2305790;
      if ( n32 >= 32 )
        v8 = unk_2305794;
    }
    else
    {
      v8 = unk_230578C;
    }
    *(_DWORD *)(n6240 + v2 + 63536) = v8 + *(__int16 *)(v8 + 16);
    n32_1 = (float)n32;
    *(float *)(n6240 + v2 + 63544) = n32_1 * 0.00007812499825377017;
    if ( !*((_WORD *)EntryByIdRange + 8) || (*((_WORD *)EntryByIdRange + 8) & 0x8000) != 0 )
    {
      *(_WORD *)(n6240 + v2 + 63548) = 4096;
    }
    else
    {
      v9 = (_WORD *)(n6240 + v2 + 63548);
      v16 = (double)(n32 >> 1);
      v10 = v16;
      HIDWORD(v16) = 7;
      n7 = 7;
      v17 = v10 + 3.0;
      n32_1 = 0.0;
      v12 = v17;
      do
      {
        n32_2 = n32_1;
        n32_3 = (int)n32_1;
        *v9 = (int)(flt_C44BE0[(n32_3 >> 4) & 0xFFF] * v12);
        v9[1] = -(__int16)(int)(flt_C44BE0[((n32_3 + 0x4000) >> 4) & 0xFFF] * v12);
        n32_1 = n32_2 + 9362.2861328125;
        v9 += 2;
        --n7;
      }
      while ( n7 );
      n6240 = n6240_1;
    }
    n6240 += 48;
    result = ++v19;
    n6240_1 = n6240;
  }
  while ( n6240 < 6240 );
  return result;
}

