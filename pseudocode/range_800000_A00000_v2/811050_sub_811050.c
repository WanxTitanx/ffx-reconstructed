// Function: sub_811050
// Address: 0x811050
int __cdecl sub_811050(int a1, int a2, int a3, int a4)
{
  int v4; // esi
  int v5; // ebx
  int v6; // eax
  _WORD *v7; // ebx
  int n2048; // edx
  int v9; // eax
  float v11; // [esp+20h] [ebp+14h]

  v4 = *(_DWORD *)(a2 + 32) + (*(unsigned __int16 *)(a4 + 76) << 8);
  v5 = word_C4930C[(*(__int16 *)(a1 + 538) >> 12) & 7];
  v6 = *(__int16 *)(v5 + a4);
  v7 = (_WORD *)(a4 + v5);
  v11 = (float)v6;
  n2048 = *(_WORD *)(a1 + 538) & 0xE00;
  if ( (*(_WORD *)(a1 + 538) & 0xE00) != 0 )
  {
    if ( n2048 == 1024 )
    {
      v11 = sub_800BF0(*(unsigned __int8 *)(v4 + 24), *(char *)(a1 + 542)) * v11;
    }
    else if ( n2048 == 2048 )
    {
      sub_795730(*(unsigned __int8 *)(v4 + 24), (float *)(a1 + 192));
      v11 = *(float *)(a1 + 196) * v11;
      if ( v11 < 0.0 )
        v11 = -v11;
    }
  }
  else
  {
    v11 = sub_800B30(*(unsigned __int8 *)(v4 + 24), *(char *)(a1 + 542)) * v11;
  }
  v9 = (int)v11;
  if ( (__int16)v9 < *(__int16 *)(a3 + 2) )
    LOWORD(v9) = *(_WORD *)(a3 + 2);
  if ( (__int16)v9 > *(__int16 *)(a3 + 4) )
    LOWORD(v9) = *(_WORD *)(a3 + 4);
  *v7 = v9;
  return a3 + 6;
}
