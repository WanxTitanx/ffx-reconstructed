// Function: sub_89A2A0
// Address: 0x89a2a0
int __cdecl sub_89A2A0(int a1, int n12565_2)
{
  char v2; // bl
  int n12565_1; // eax
  float *v5; // eax
  __int16 v6; // ax
  int n13_1; // eax
  int n13; // edi
  int v9; // eax
  char v10; // bl
  int v11; // edx
  int n12565_3; // ecx
  int v13; // eax
  char v14; // bl
  int v15; // esi
  int v16; // [esp+Ch] [ebp-Ch] BYREF
  int v17; // [esp+10h] [ebp-8h]
  int n12565; // [esp+14h] [ebp-4h]

  v2 = unk_23CC092[0];
  if ( unk_133C912[240 * unk_23CC092[0]] == 1 )
  {
    if ( *((_WORD *)&unk_133C9B6 + 120 * unk_23CC092[0]) >= *((_WORD *)&unk_133C9B4 + 120 * unk_23CC092[0]) )
    {
LABEL_3:
      sub_897510();
      return 1;
    }
    n12565_1 = 12565;
    n12565 = 12565;
    qmemcpy(&n0x1C_0, &n0x1C, 0x140u);
    if ( n256_0 == 0x10000 )
    {
      v5 = FFX_Btl_LookupCommandDataById(unk_133C91C[120 * unk_23CC092[0]], &v16);
      v6 = FFX_Btl_Ctb_ComputeTurnWeight(*((_WORD *)&unk_133C918 + 120 * unk_23CC092[0]), (int)v5);
      v2 = unk_23CC092[0];
      unk_133F0C6 = v6;
      n12565_1 = 12565;
    }
  }
  else
  {
    n12565_1 = n12565_2;
    n12565 = n12565_2;
  }
  if ( n12565_1 == 65534 )
  {
    n13 = 13;
  }
  else if ( n12565_1 == 0xFFFF )
  {
    n13 = 12;
  }
  else
  {
    n13_1 = sub_89AC10(a1, n12565_1);
    n13 = n13_1;
    if ( n13_1 < 0 )
      return 0;
    if ( n13_1 == 255 )
      goto LABEL_3;
    v2 = unk_23CC092[0];
  }
  if ( v2 >= 0 )
  {
    v9 = 240 * v2;
    *((_BYTE *)&unk_133C911 + v9) = 6;
    word_133C926[120 * v2 + *((char *)&unk_133C91B + v9)] = n12565;
  }
  v10 = v2 + 1;
  v17 = v10;
  unk_23CC092[0] = v10;
  memset((char *)&unk_133C910 + 240 * v10, 0, 0xF0u);
  v11 = a1;
  n12565_3 = n12565;
  *((_WORD *)&unk_133C918 + 120 * v10) = a1;
  unk_133C91C[120 * v10] = n12565_3;
  word_133C926[120 * v10] = 255;
  if ( v10 )
  {
    *((_WORD *)&unk_133C9B4 + 120 * v10) = *((_WORD *)&unk_133C8C4 + 120 * v10);
    *((_WORD *)&unk_133C9B6 + 120 * v10) = *((_WORD *)&unk_133C8C6 + 120 * v10);
  }
  else
  {
    unk_133C9B4 = 1;
  }
  *((_BYTE *)&unk_133C911 + 240 * v10) = 1;
  if ( n13 <= 128 )
  {
    sub_8997E0(v17, a1, n12565_3);
    v10 = unk_23CC092[0];
    n12565_3 = n12565;
    v11 = a1;
  }
  if ( n13 == 254 )
    sub_89A7D0(v10, v11, n12565_3);
  v13 = sub_785280(n12565_3);
  v14 = unk_23CC092[0];
  if ( v13 == 1
    && unk_133D730[unk_23CC088[0]] == 1
    && n12290 != 0xFFFF
    && n12290 != 0xFFFE
    && *((__int16 *)&unk_133C918 + 120 * unk_23CC092[0]) <= 17 )
  {
    sub_899A30();
  }
  if ( unk_133C912[240 * v14] == 1 && unk_133D128 == -1 && !n3_9 )
  {
    v15 = 0;
    if ( MEMORY[0x133F098] > 0 )
    {
      while ( !FFX_Battle_IsActorStatusStone(unk_133F09C[v15]) )
      {
        if ( ++v15 >= MEMORY[0x133F098] )
          return 1;
      }
      unk_133D1C0 = 0;
      unk_133D1BC = v15;
      unk_133D138 = dst_1[v15];
      i_5 = unk_133F09C[v15];
      src_0 = dst_1;
      unk_133D1B6 = word_133D13C[0];
    }
  }
  return 1;
}
