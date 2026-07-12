// Function: sub_8E1C60
// Address: 0x8e1c60
int __cdecl sub_8E1C60(int a1, int a2)
{
  int n210; // eax
  int *k_1; // ecx
  int n208; // edi
  int n17; // esi
  int v6; // esi
  int v7; // esi
  int i; // ecx
  int v9; // edx
  int v10; // ebx
  _DWORD *p_n13; // edx
  _DWORD *v12; // ecx
  int n32; // esi
  int v14; // eax
  int v15; // eax
  int j; // ecx
  int v17; // edi
  int k; // esi
  int v19; // eax
  int v20; // eax
  int v21; // eax
  _DWORD v23[64]; // [esp+Ch] [ebp-104h] BYREF

  unk_1871508 = 0;
  dword_1871510 = 0;
  unk_187150C = -1;
  switch ( a2 )
  {
    case 12:
      n13 = 13;
      unk_187152C = 1;
      unk_1871648 = 1;
      unk_1871514 = 0;
      break;
    case 13:
      n13 = 12;
      unk_187152C = 1;
      unk_1871648 = 1;
      unk_1871514 = 0;
      break;
    case 14:
      n13 = 14;
      unk_187152C = 1;
      unk_1871648 = 1;
      unk_1871514 = 0;
      break;
    case 15:
      n13 = 10;
      unk_187152C = 1;
      unk_1871648 = 1;
      unk_1871514 = 0;
      break;
    case 16:
      n13 = 11;
      unk_187152C = 1;
      unk_1871648 = 1;
      unk_1871514 = 0;
      break;
    case 24:
      n13 = 55;
      unk_187152C = 1;
      unk_1871648 = 1;
      unk_1871514 = 0;
      break;
    default:
      n210 = sub_86C400();
      n208 = n210;
      n17 = 17;
      if ( !n210 || n210 >= 210 )
        n17 = 21;
      v6 = n17 | 0x8000;
      if ( !n210 || n210 >= 67 )
        v6 |= 8u;
      if ( !n210 || n210 >= 1096 )
        v6 |= 0x80u;
      v7 = v6 | 0x302;
      if ( (!n210 || n210 >= 217) && (sub_86BDE0() & 0x40) == 0 && sub_8A9B00() > 1 )
        v7 |= 0x40u;
      if ( sub_8AB190(k_1) && (n208 >= 208 || !n208) )
        v7 |= 0x20u;
      memset(v23, 0, sizeof(v23));
      for ( i = 0; i < 32; ++i )
      {
        if ( ((1 << i) & v7) != 0 )
        {
          v9 = (unsigned __int8)byte_C5B2D4[i];
          v23[2 * v9] = i;
          LOWORD(v23[2 * v9 + 1]) = 1;
          switch ( i )
          {
            case 1:
              HIWORD(v23[2 * v9 + 1]) = 1;
              break;
            case 2:
            case 3:
            case 4:
            case 15:
              HIWORD(v23[2 * v9 + 1]) = 2;
              break;
            default:
              HIWORD(v23[2 * v9 + 1]) = 0;
              break;
          }
        }
      }
      v10 = 0;
      p_n13 = &n13;
      v12 = v23;
      n32 = 32;
      do
      {
        if ( *((_WORD *)v12 + 2) == 1 )
        {
          *p_n13 = *v12;
          p_n13[1] = v12[1];
          ++v10;
          p_n13 += 2;
        }
        v12 += 2;
        --n32;
      }
      while ( n32 );
      unk_1871648 = v10;
      break;
  }
  sub_8AAE60(0);
  v14 = sub_8E2270(unk_1871508);
  v15 = sub_8DDF40(v14);
  sub_8AAE60(v15);
  unk_1871518 = a1 != 0 ? 0x3000 : 0;
  for ( j = 0; j < 8; ++j )
  {
    word_1871628[j] = 4 * j;
    if ( (unsigned int)j >= 8 )
      __report_rangecheckfailure();
    word_1871638[j] = 0;
  }
  v17 = sub_8AA150();
  unk_1871500 = v17;
  *(_DWORD *)(v17 + 8) = 0;
  *(_DWORD *)(v17 + 12) = sub_8E2040;
  *(_DWORD *)(v17 + 16) = sub_8E20F0;
  *(_DWORD *)(v17 + 20) = 0;
  *(_DWORD *)(v17 + 24) = 0;
  *(_DWORD *)(v17 + 28) = 0;
  *(_BYTE *)(v17 + 54) = 2;
  *(_BYTE *)(v17 + 62) = 7;
  for ( k = 0; k < sub_8E2280(); ++k )
  {
    v19 = sub_8E2270(k);
    v20 = sub_8DDF60(v19);
    v21 = sub_8DC9C0(v20);
    if ( v21 > dword_1871510 )
      dword_1871510 = v21;
  }
  return sub_8AAAB0(v17);
}
