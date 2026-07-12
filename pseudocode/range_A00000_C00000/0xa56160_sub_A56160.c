// Function: sub_A56160
// Address: 0xa56160
// Size: 0x1cb
// Prototype: 

int __cdecl sub_A56160(int a1, int a2, int a3)
{
  int v3; // esi
  int v4; // edi
  _BYTE *v5; // esi
  int v6; // edi
  int v7; // esi
  int v8; // edx
  int v9; // ecx
  _BYTE *v10; // eax
  _WORD *v11; // ecx
  int result; // eax

  sub_A5B930();
  if ( !a3 )
  {
    FFX_BtlEffect_Enable(-2147483566);
    sub_786FB0(*(unsigned __int8 *)(dword_2305834[0] + 71100), *(_DWORD *)(dword_2305834[0] + 71196));
LABEL_11:
    v8 = dword_2305834[0];
    goto LABEL_12;
  }
  if ( a3 != 1 )
    goto LABEL_11;
  v3 = dword_2305834[0];
  v4 = *(__int16 *)(dword_2305834[0] + 4);
  FFX_BtlEffect_Enable(-2147483644);
  if ( v4 )
  {
    v5 = (_BYTE *)(v3 + 43028);
    do
    {
      --v4;
      if ( (v5[2] & 8) != 0 )
      {
        *v5 &= ~(1 << *(_BYTE *)(dword_2305834[0] + 71100));
        *(_DWORD *)(dword_2305834[0] + 71340) = 1;
      }
      v5 += 20;
    }
    while ( v4 );
  }
  v6 = dword_2305834[0];
  v7 = 10 * *(unsigned __int8 *)(dword_2305834[0] + 71224);
  *(_WORD *)(dword_2305834[0] + 80 * *(unsigned __int8 *)(dword_2305834[0] + 71224) + 69836) = *(_WORD *)(dword_2305834[0] + 71216);
  sub_A5A990(*(unsigned __int8 *)(dword_2305834[0] + 71224));
  sub_A58080(*(unsigned __int8 *)(dword_2305834[0] + 71224));
  *(_BYTE *)(dword_2305834[0] + 71111) = 1;
  sub_A5B030();
  sub_A48D70(*(unsigned __int16 *)(v6 + 8 * v7 + 69836), 0.5);
  v8 = dword_2305834[0];
  if ( !*(_DWORD *)(dword_2305834[0] + 71088) )
  {
    *(_DWORD *)(dword_2305834[0] + 71088) = *(_DWORD *)(dword_2305834[0] + 71080);
    *(_DWORD *)(dword_2305834[0] + 71080) = sub_A59E80;
    goto LABEL_11;
  }
LABEL_12:
  v9 = *(__int16 *)(v8 + 4);
  if ( *(_WORD *)(v8 + 4) )
  {
    v10 = (_BYTE *)(v8 + 43030);
    do
    {
      *v10 &= 0xF0u;
      v10 += 20;
      --v9;
    }
    while ( v9 );
  }
  v11 = (_WORD *)unk_1A86108;
  *(_BYTE *)(unk_1A86108 + 7523) = 0;
  v11[2916] = v11[2912];
  v11[2917] = v11[2913];
  v11[2918] = v11[2914];
  v11[2919] = v11[2915];
  v11[2922] = v11[2920];
  v11[2923] = v11[2921];
  result = dword_2305834[0];
  *(_DWORD *)(dword_2305834[0] + 71196) = 0;
  return result;
}

