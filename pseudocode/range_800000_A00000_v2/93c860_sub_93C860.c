// Function: sub_93C860
// Address: 0x93c860
int __cdecl sub_93C860(int a1, int a2, int n50)
{
  int n50_1; // eax
  int n50_2; // esi
  int n999; // eax
  int n99; // eax
  double v7; // st7
  int v8; // eax
  int n999_3; // eax
  int n99_2; // eax
  double v11; // st7
  int v12; // [esp+8h] [ebp-Ch] BYREF
  int n999_1; // [esp+Ch] [ebp-8h]
  int v14; // [esp+10h] [ebp-4h] BYREF
  float n99_1; // [esp+20h] [ebp+Ch]
  float n999_2; // [esp+20h] [ebp+Ch]
  float v17; // [esp+20h] [ebp+Ch]
  float n99_3; // [esp+20h] [ebp+Ch]
  float n999_4; // [esp+20h] [ebp+Ch]
  float v20; // [esp+20h] [ebp+Ch]

  n50_1 = sub_84AEC0(a1);
  n50_2 = n50_1;
  switch ( a2 )
  {
    case 32769:
      sub_937780(a1, dword_C61090);
      sub_84A4A0(a1, 8, 138, 6, 16, 101);
      sub_84A4A0(a1, 9, 158, 6, 16, 101);
      return sub_93C110();
    case 32771:
      *(_DWORD *)n50_1 = 0;
      return n50_1;
    case 32774:
      switch ( n50 )
      {
        case 0:
          *(_DWORD *)(n50_1 + 12) += 10;
          goto LABEL_9;
        case 1:
          *(_DWORD *)(n50_1 + 12) -= 10;
          goto LABEL_9;
        case 2:
          ++*(_DWORD *)(n50_1 + 12);
          goto LABEL_9;
        case 3:
          --*(_DWORD *)(n50_1 + 12);
          goto LABEL_9;
        case 4:
          *(_DWORD *)(n50_1 + 16) += 10;
          goto LABEL_9;
        case 5:
          *(_DWORD *)(n50_1 + 16) -= 10;
          goto LABEL_9;
        case 6:
          ++*(_DWORD *)(n50_1 + 16);
          goto LABEL_9;
        case 7:
          --*(_DWORD *)(n50_1 + 16);
LABEL_9:
          *(_DWORD *)(n50_1 + 28) = 1;
          goto LABEL_10;
        case 10:
          sub_84AB80(a1);
          *(_DWORD *)(n50_2 + 20) = 1;
          goto LABEL_10;
        case 11:
          **(float **)(n50_1 + 4) = *(float *)(n50_1 + 8);
          n50_1 = sub_84AB80(a1);
          *(_DWORD *)(n50_2 + 24) = 1;
          return n50_1;
        default:
LABEL_10:
          n999 = *(_DWORD *)(n50_2 + 12);
          if ( n999 >= 0 )
          {
            if ( n999 > 999 )
              n999 = 999;
          }
          else
          {
            n999 = 0;
          }
          n999_1 = n999;
          *(_DWORD *)(n50_2 + 12) = n999;
          n99 = *(_DWORD *)(n50_2 + 16);
          if ( n99 >= 0 )
          {
            if ( n99 > 99 )
              n99 = 99;
          }
          else
          {
            n99 = 0;
          }
          *(_DWORD *)(n50_2 + 16) = n99;
          n99_1 = (float)n99;
          v7 = n99_1 / 100.0;
          n999_2 = (float)n999_1;
          v17 = v7 + n999_2;
          **(float **)(n50_2 + 4) = v17;
          n50_1 = sub_93C050();
          break;
      }
      return n50_1;
    case 32775:
      n50_1 = n50;
      if ( n50 == 8 || n50 == 9 )
        return sub_93C150(a1, n50);
      return n50_1;
    case 32785:
      if ( !n50_1 || !*(_DWORD *)n50_1 )
        return n50_1;
      if ( !sub_93C120(a1) )
        goto LABEL_46;
      sub_93C060(&v12, &v14);
      v8 = sub_93C100() - 8;
      if ( v8 )
      {
        if ( v8 != 1 )
          goto LABEL_37;
        *(_DWORD *)(n50_2 + 16) -= v14;
      }
      else
      {
        *(_DWORD *)(n50_2 + 12) -= v14;
      }
      if ( v14 )
        *(_DWORD *)(n50_2 + 28) = 1;
LABEL_37:
      n999_3 = *(_DWORD *)(n50_2 + 12);
      if ( n999_3 >= 0 )
      {
        if ( n999_3 > 999 )
          n999_3 = 999;
      }
      else
      {
        n999_3 = 0;
      }
      n999_1 = n999_3;
      *(_DWORD *)(n50_2 + 12) = n999_3;
      n99_2 = *(_DWORD *)(n50_2 + 16);
      if ( n99_2 >= 0 )
      {
        if ( n99_2 > 99 )
          n99_2 = 99;
      }
      else
      {
        n99_2 = 0;
      }
      *(_DWORD *)(n50_2 + 16) = n99_2;
      n99_3 = (float)n99_2;
      v11 = n99_3 / 100.0;
      n999_4 = (float)n999_1;
      v20 = v11 + n999_4;
      **(float **)(n50_2 + 4) = v20;
LABEL_46:
      sub_93C730(a1, 138, 6, *(_DWORD *)(n50_2 + 12));
      sub_93C730(a1, 158, 6, *(_DWORD *)(n50_2 + 16));
      sub_848820(32);
      sub_848860(15);
      sub_848880("%3dm", *(_DWORD *)(n50_2 + 12));
      sub_848820(32);
      sub_848860(28);
      sub_848880("%3d", *(_DWORD *)(n50_2 + 16));
      sub_8487E0(144);
      sub_848880("cm");
      sub_8487E0(192);
      sub_848820(112);
      sub_848860(2);
      sub_848880("100");
      sub_848820(112);
      sub_848860(52);
      sub_848880(" 50");
      sub_848820(112);
      sub_848860(102);
      return sub_848880("  0");
    default:
      return n50_1;
  }
}
