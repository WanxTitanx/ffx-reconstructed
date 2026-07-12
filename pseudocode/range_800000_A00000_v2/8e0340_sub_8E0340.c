// Function: sub_8E0340
// Address: 0x8e0340
int __cdecl sub_8E0340(int a1)
{
  __int16 v1; // bx
  char v2; // cl
  int n4096; // eax
  int v4; // ecx
  int n9; // eax
  int MenuSlotIndex; // eax
  int v7; // esi
  int v8; // ecx
  int n4096_1; // esi
  int v10; // ecx
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // eax
  unsigned __int8 v20; // al
  unsigned __int8 v21; // al
  char v22; // [esp+8h] [ebp-4h]

  sub_8BE3E0();
  v1 = sub_8BE440();
  v2 = sub_8BE480();
  v22 = v2;
  word_1871504[0] += 170;
  if ( word_1871504[0] >= 4096 )
    word_1871504[0] = 4096;
  n4096 = *(_DWORD *)(a1 + 28);
  while ( 2 )
  {
    switch ( n4096 )
    {
      case 0:
        n4096 = sub_8AB210(-16);
        *(_DWORD *)(a1 + 28) = 1;
        return n4096;
      case 1:
        n4096 = 4096;
        if ( word_1871504[0] >= 4096 && !n4096_1 )
          *(_DWORD *)(a1 + 28) = 2;
        return n4096;
      case 2:
      case 3:
        n4096 = sub_8AAD10(0);
        *(_DWORD *)(a1 + 28) = 4;
        return n4096;
      case 4:
        *(_DWORD *)(a1 + 28) = 5;
        goto LABEL_6;
      case 5:
LABEL_6:
        if ( (v2 & 0x20) == 0 )
        {
          if ( (v2 & 0x40) != 0 )
          {
            n4096 = FFX_BtlEffect_Enable(-2147483644);
            *(_DWORD *)(a1 + 28) = 35;
          }
          else if ( (v1 & 0x1000) != 0 )
          {
            FFX_BtlEffect_Enable(-2147483647);
            v13 = --unk_1871508;
            if ( unk_1871508 < 0 )
            {
              v13 = sub_8E2280() - 1;
              unk_1871508 = v13;
            }
            v14 = sub_8E2270(v13);
            v15 = sub_8DDF40(v14);
            return sub_8AAE60(v15);
          }
          else if ( (v1 & 0x4000) != 0 )
          {
            FFX_BtlEffect_Enable(-2147483647);
            v16 = sub_8E2280();
            unk_1871508 = v17 >= v16 ? 0 : v17;
            v18 = sub_8E2270(unk_1871508);
            v19 = sub_8DDF40(v18);
            return sub_8AAE60(v19);
          }
          return n4096;
        }
        if ( !sub_8E2290(unk_1871508) )
          return FFX_BtlEffect_Enable(-2147483645);
        FFX_BtlEffect_Enable(-2147483647);
        if ( sub_8E2270(unk_1871508) == 6 )
        {
          n4096 = 10;
          goto LABEL_21;
        }
        if ( sub_8E2260(unk_1871508) )
        {
          if ( sub_8E2260(unk_1871508) == 2 )
          {
            n4096 = sub_8AAD10(1);
            *(_DWORD *)(a1 + 28) = 6;
          }
          else
          {
            sub_8AAD10(0);
            n4096_1 = sub_8A9820();
            n4096 = sub_8A9AE0(v10);
            if ( n4096_1 >= n4096 )
            {
              v12 = sub_8A9AE0(v11);
              n4096 = sub_8AAE30(v12 - 1);
            }
            *(_DWORD *)(a1 + 28) = 6;
          }
          return n4096;
        }
        n9 = sub_8E24C0(v4);
        goto LABEL_16;
      case 6:
        MenuSlotIndex = FFX_Party_GetMenuSlotIndex();
        v2 = v22;
        ::MenuSlotIndex = MenuSlotIndex;
        *(_DWORD *)(a1 + 28) = 7;
        goto LABEL_13;
      case 7:
LABEL_13:
        if ( (v2 & 0x20) != 0 )
        {
          v7 = sub_8A9820();
          if ( v7 >= sub_8A9AE0(v8) )
            return FFX_BtlEffect_Enable(-2147483645);
          FFX_BtlEffect_Enable(-2147483647);
          n9 = sub_8E24C0(unk_1871508);
LABEL_16:
          if ( n9 == 3 )
          {
            n4096 = 27;
            *(_DWORD *)(a1 + 28) = 27;
          }
          else if ( n9 == 9 )
          {
            n4096 = 31;
            *(_DWORD *)(a1 + 28) = 31;
          }
          else
          {
            n4096 = 25;
            *(_DWORD *)(a1 + 28) = 25;
          }
LABEL_21:
          v2 = v22;
          continue;
        }
        if ( (v2 & 0x40) != 0 )
        {
          n4096 = FFX_BtlEffect_Enable(-2147483644);
          *(_DWORD *)(a1 + 28) = 8;
        }
        else
        {
          n4096 = sub_8A9B00();
          if ( n4096 > 1 )
          {
            if ( (v1 & 0x1000) != 0 )
            {
              FFX_BtlEffect_Enable(-2147483647);
              sub_8AAF70();
              n4096 = FFX_Party_GetMenuSlotIndex();
              ::MenuSlotIndex = n4096;
            }
            else if ( (v1 & 0x4000) != 0 )
            {
              FFX_BtlEffect_Enable(-2147483647);
              sub_8AAEF0();
              n4096 = FFX_Party_GetMenuSlotIndex();
              ::MenuSlotIndex = n4096;
            }
          }
        }
        return n4096;
      case 8:
        ::MenuSlotIndex = -1;
        *(_DWORD *)(a1 + 28) = 9;
        goto LABEL_49;
      case 9:
LABEL_49:
        *(_DWORD *)(a1 + 28) = 2;
        return n4096;
      case 10:
        n4096 = sub_8A9820();
        n4096_2 = n4096;
        goto LABEL_51;
      case 11:
LABEL_51:
        n4096_3 = -1;
        *(_DWORD *)(a1 + 28) = 12;
        return n4096;
      case 12:
        *(_DWORD *)(a1 + 28) = 13;
        return n4096;
      case 13:
        *(_DWORD *)(a1 + 28) = 14;
        return n4096;
      case 14:
        if ( (v2 & 0x20) != 0 )
        {
          v20 = sub_8A9AB0(n4096_2);
          if ( !LOBYTE_w_0(v20) )
            return FFX_BtlEffect_Enable(-2147483645);
          n4096 = FFX_BtlEffect_Enable(-2147483647);
          *(_DWORD *)(a1 + 28) = 17;
        }
        else if ( (v2 & 0x40) != 0 )
        {
          n4096 = FFX_BtlEffect_Enable(-2147483644);
          *(_DWORD *)(a1 + 28) = 15;
        }
        else if ( (v1 & 0x4000) != 0 )
        {
          FFX_BtlEffect_Enable(-2147483647);
          ++n4096_2;
          n4096 = sub_8A9B00();
          if ( n4096_2 >= n4096 )
            n4096_2 = 0;
        }
        else if ( (v1 & 0x1000) != 0 )
        {
          n4096 = FFX_BtlEffect_Enable(-2147483647);
          if ( --n4096_2 < 0 )
          {
            n4096 = sub_8A9B00() - 1;
            n4096_2 = n4096;
          }
        }
        return n4096;
      case 15:
        n4096_2 = -1;
        n4096_3 = -1;
        *(_DWORD *)(a1 + 28) = 16;
        goto LABEL_66;
      case 16:
LABEL_66:
        n4096 = sub_8C30B0();
        *(_DWORD *)(a1 + 28) = 3;
        return n4096;
      case 17:
        n4096 = n4096_2;
        n4096_3 = n4096_2;
        *(_DWORD *)(a1 + 28) = 18;
        goto LABEL_68;
      case 18:
LABEL_68:
        *(_DWORD *)(a1 + 28) = 19;
        return n4096;
      case 19:
        *(_DWORD *)(a1 + 28) = 20;
        goto LABEL_70;
      case 20:
LABEL_70:
        if ( (v2 & 0x20) == 0 )
        {
          if ( (v2 & 0x40) != 0 )
          {
            n4096 = FFX_BtlEffect_Enable(-2147483644);
            *(_DWORD *)(a1 + 28) = 23;
          }
          else if ( (v1 & 0x1000) != 0 )
          {
            n4096 = FFX_BtlEffect_Enable(-2147483647);
            if ( --n4096_3 < 0 )
            {
              n4096 = sub_8A9B00() - 1;
              n4096_3 = n4096;
            }
          }
          else if ( (v1 & 0x4000) != 0 )
          {
            FFX_BtlEffect_Enable(-2147483647);
            ++n4096_3;
            n4096 = sub_8A9B00();
            if ( n4096_3 >= n4096 )
              n4096_3 = 0;
          }
          return n4096;
        }
        if ( n4096_2 != n4096_3 )
        {
          v21 = sub_8A9AB0(n4096_3);
          if ( LOBYTE_w_0(v21) )
          {
            n4096 = FFX_BtlEffect_Enable(-2147483647);
            *(_DWORD *)(a1 + 28) = 21;
            return n4096;
          }
        }
        return FFX_BtlEffect_Enable(-2147483645);
      case 21:
        sub_8A96D0(n4096_2, n4096_3);
        n4096 = n4096_3;
        n4096_2 = n4096_3;
        n4096_3 = -1;
        *(_DWORD *)(a1 + 28) = 22;
        goto LABEL_83;
      case 22:
LABEL_83:
        *(_DWORD *)(a1 + 28) = 11;
        return n4096;
      case 23:
        *(_DWORD *)(a1 + 28) = 24;
        goto LABEL_85;
      case 24:
LABEL_85:
        *(_DWORD *)(a1 + 28) = 11;
        return n4096;
      case 25:
        n4096 = sub_8C30B0();
        *(_DWORD *)(a1 + 28) = 26;
        return n4096;
      case 26:
        if ( unk_1871514 )
        {
          sub_8AA3C0(0);
          n4096 = sub_8AA3C0(3);
          *(_DWORD *)(a1 + 28) = 2;
        }
        return n4096;
      case 27:
        n4096 = sub_8A9630(10);
        *(_DWORD *)(a1 + 28) = 28;
        return n4096;
      case 28:
        n4096 = sub_8A9850();
        if ( n4096 >= 128 )
        {
          sub_8AA0B0(19, 0);
          n4096 = sub_8AAD20(1);
          *(_DWORD *)(a1 + 28) = 29;
        }
        return n4096;
      case 29:
        if ( unk_1871514 )
        {
          sub_8AA3C0(0);
          sub_8AA3C0(3);
          n4096 = sub_8A9630(-10);
          *(_DWORD *)(a1 + 28) = 30;
        }
        return n4096;
      case 30:
      case 34:
        n4096 = sub_8A9850();
        if ( n4096 <= 0 )
          *(_DWORD *)(a1 + 28) = 2;
        return n4096;
      case 31:
        n4096 = sub_8A9630(10);
        *(_DWORD *)(a1 + 28) = 32;
        return n4096;
      case 32:
        n4096 = sub_8A9850();
        if ( n4096 >= 128 )
        {
          sub_8AA0B0(11, 0);
          n4096 = sub_8AAD20(1);
          *(_DWORD *)(a1 + 28) = 33;
        }
        return n4096;
      case 33:
        if ( unk_1871514 )
        {
          sub_8AA3C0(0);
          sub_8AA3C0(3);
          n4096 = sub_8A9630(-10);
          *(_DWORD *)(a1 + 28) = 34;
        }
        return n4096;
      case 35:
        *(_DWORD *)(a1 + 28) = 36;
        goto LABEL_102;
      case 36:
LABEL_102:
        n4096 = sub_8A8E00();
        if ( n4096 )
        {
          n4096 = sub_8AB210(16);
          *(_DWORD *)(a1 + 28) = 37;
        }
        return n4096;
      case 37:
        n4096 = sub_8AB1E0();
        if ( n4096 >= 128 )
          *(_DWORD *)(a1 + 28) = 38;
        return n4096;
      case 38:
        return sub_8AAAD0(1);
      default:
        return n4096;
    }
  }
}
