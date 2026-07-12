// Function: sub_8985B0
// Address: 0x8985b0
__int16 sub_8985B0()
{
  float *v0; // eax
  int n3; // ebx
  __int16 v2; // dx
  int v3; // ecx
  __int16 v4; // si
  int v5; // edi
  int v6; // ebx
  int v7; // esi
  int v8; // edi
  int v9; // ebx
  int v10; // edx
  int v11; // eax
  _DWORD *v12; // esi
  _DWORD *v13; // edx
  __int16 v14; // di
  _DWORD *v15; // ecx
  __int16 v16; // si
  int v17; // eax
  int v18; // edx
  int i; // ecx
  __int16 n3_1; // ax
  int v21; // ecx
  _DWORD v22[2]; // [esp+Ch] [ebp-Ch] BYREF
  float *v23; // [esp+14h] [ebp-4h]

  memset(unk_133D140, 0, sizeof(unk_133D140));
  dword_133D194[0] = 0;
  unk_133D198 = 0;
  unk_133D19C = 0;
  unk_133D1A0 = 0;
  unk_133D1A4 = 0;
  unk_133D1A8 = 0;
  unk_133D1AC = 0;
  unk_133D1B0 = 0;
  v0 = FFX_Btl_LookupCommandDataById(n255_3, v22);
  n3 = n3_9;
  v2 = 0;
  v3 = dword_133D114 & *(_DWORD *)&word_133D130 & unk_133D128 & unk_133D12C;
  v4 = 0;
  v23 = v0;
  unk_133D134 = v3;
  unk_133D13C = 0;
  unk_133D190 = 0;
  switch ( n3_9 )
  {
    case 0:
      v5 = 0;
      if ( MEMORY[0x133F098] > 0 )
      {
        v6 = MEMORY[0x133F098];
        do
        {
          v7 = v3 & dword_133D0A4[(unsigned __int16)unk_133F09C[v5]];
          if ( v7 )
          {
            unk_133D140[v2] = v7;
            v3 = unk_133D134;
            v2 = ++unk_133D13C;
          }
          ++v5;
        }
        while ( v5 < v6 );
        v4 = unk_133D190;
        n3 = n3_9;
      }
      v8 = 0;
      if ( MEMORY[0x133F0AC] > 0 )
      {
        v9 = MEMORY[0x133F0AC];
        do
        {
          v10 = v3 & dword_133D0A4[(unsigned __int16)unk_133F0B0[v8]];
          if ( v10 )
          {
            dword_133D194[v4] = v10;
            v3 = unk_133D134;
            v4 = ++unk_133D190;
          }
          ++v8;
        }
        while ( v8 < v9 );
        v2 = unk_133D13C;
        n3 = n3_9;
      }
      break;
    case 1:
      v12 = dword_133D0A4;
      do
      {
        if ( (v3 & *v12) != 0 )
        {
          unk_133D140[v2] = v3 & *v12;
          v3 = unk_133D134;
          v2 = ++unk_133D13C;
        }
        ++v12;
      }
      while ( (int)v12 < (int)dword_133D0C4 );
      v4 = unk_133D190;
      v13 = dword_133D0F4;
      do
      {
        if ( (v3 & *v13) != 0 )
        {
          dword_133D194[v4] = v3 & *v13;
          v3 = unk_133D134;
          v4 = ++unk_133D190;
        }
        ++v13;
      }
      while ( (int)v13 < (int)&dword_133D114 );
      v2 = unk_133D13C;
      n3 = n3_9;
      break;
    case 2:
      if ( (v3 & dword_133D0A4[0]) != 0 )
      {
        v2 = 1;
        unk_133D140[0] = v3 & dword_133D0A4[0];
        unk_133D13C = 1;
      }
      v11 = v3 & dword_133D0F4[0];
      if ( (v3 & dword_133D0F4[0]) != 0 )
        goto LABEL_31;
      break;
    case 3:
      if ( n0x1C >= 0x14u )
      {
        if ( n0x1C < 0x1Cu )
        {
          v11 = 1 << n0x1C;
LABEL_31:
          v4 = 1;
          unk_133D190 = 1;
          dword_133D194[0] = v11;
        }
      }
      else
      {
        v2 = 1;
        unk_133D13C = 1;
        unk_133D140[0] = 1 << n0x1C;
      }
      break;
    default:
      break;
  }
  v14 = 0;
  unk_133D1BC = 0;
  if ( (*((_BYTE *)v23 + 26) & 2) != 0 )
  {
    v15 = dword_133D194;
    unk_133D1B6 = v4;
    v22[1] = 1;
    unk_133D1C0 = 1;
    unk_133D1B8 = dword_133D194;
    v16 = 1;
  }
  else
  {
    v16 = 0;
    v15 = unk_133D140;
    unk_133D1C0 = 0;
    unk_133D1B8 = unk_133D140;
    unk_133D1B6 = v2;
    if ( !n3 )
    {
      v17 = 0;
      if ( v2 <= 0 )
      {
        v16 = 0;
      }
      else
      {
        while ( unk_133D140[v17] != 1 << n0x1C )
        {
          if ( ++v17 >= v2 )
            goto LABEL_38;
        }
        v14 = v17;
        unk_133D1BC = v17;
LABEL_38:
        v15 = unk_133D140;
        v16 = 0;
      }
    }
  }
  unk_133D1BE = (*((_BYTE *)v23 + 26) & 0x20) != 0;
  v18 = v15[v14];
  unk_133D138 = v18;
  if ( !n3 || n3 == 3 )
  {
    for ( i = 0; i < 28; ++i )
    {
      if ( ((1 << i) & v18) != 0 )
        i_5 = i;
    }
  }
  else
  {
    i_5 = 255;
  }
  n3_1 = n3_9;
  v21 = 240 * unk_23CC092[0];
  *(_DWORD *)((char *)&unk_133C9E8 + v21) = v18;
  *(_WORD *)((char *)&unk_133C9E4 + v21) = v16;
  *(_WORD *)((char *)&unk_133C9E6 + v21) = n3_1;
  *(_WORD *)((char *)&unk_133C952 + v21) = v14;
  return n3_1;
}
