// Function: sub_A5B7B0
// Address: 0xa5b7b0
// Size: 0x148
// Prototype: int(void)

int sub_A5B7B0()
{
  int v0; // esi
  unsigned __int16 v1; // ax
  int v2; // eax
  int v3; // ecx
  _BYTE *v4; // eax
  __int16 v5; // dx
  int v6; // eax
  int v7; // ecx
  unsigned __int16 v8; // dx
  int v9; // eax
  int result; // eax
  char v11; // [esp+0h] [ebp-Ch]

  v0 = *(unsigned __int16 *)(dword_2305834[0] + 80 * *(unsigned __int8 *)(dword_2305834[0] + 71100) + 69836);
  *(_DWORD *)(dword_2305834[0] + 71080) = sub_A44EF0;
  *(_DWORD *)(dword_2305834[0] + 71084) = sub_A45440;
  v11 = *(_BYTE *)(dword_2305834[0] + 71100);
  v1 = sub_7854A0(v11);
  sub_A474D0(v0, v1, v11);
  v2 = dword_2305834[0];
  v3 = *(__int16 *)(dword_2305834[0] + 2);
  if ( *(_WORD *)(dword_2305834[0] + 2) )
  {
    v4 = (_BYTE *)(dword_2305834[0] + 2090);
    do
    {
      --v3;
      if ( *((_WORD *)v4 - 14) != 0xFFFF )
        *v4 &= 0xFCu;
      v4 += 40;
    }
    while ( v3 );
    v2 = dword_2305834[0];
  }
  v5 = sub_7854A0(*(_BYTE *)(v2 + 71100));
  v6 = dword_2305834[0];
  v7 = *(__int16 *)(dword_2305834[0] + 2);
  v8 = 4 * v5;
  if ( *(_WORD *)(dword_2305834[0] + 2) )
  {
    v9 = dword_2305834[0] + 2090;
    do
    {
      --v7;
      if ( *(_WORD *)(v9 - 28) != 0xFFFF && *(_WORD *)(v9 + 2) <= v8 )
        *(_BYTE *)v9 |= 3u;
      v9 += 40;
    }
    while ( v7 );
    v6 = dword_2305834[0];
  }
  *(_DWORD *)(v6 + 71328) = 0;
  *(_DWORD *)(dword_2305834[0] + 71324) = 0;
  *(_DWORD *)(dword_2305834[0] + 71196) = 0;
  result = sub_A48D70(v0, 0.25);
  if ( !*(_DWORD *)(dword_2305834[0] + 71088) )
  {
    *(_DWORD *)(dword_2305834[0] + 71088) = *(_DWORD *)(dword_2305834[0] + 71080);
    *(_DWORD *)(dword_2305834[0] + 71080) = sub_A59E80;
    result = dword_2305834[0];
  }
  *(_BYTE *)(dword_2305834[0] + 71107) = 1;
  return result;
}

