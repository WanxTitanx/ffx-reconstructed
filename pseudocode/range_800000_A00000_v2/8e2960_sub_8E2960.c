// Function: sub_8E2960
// Address: 0x8e2960
int __cdecl sub_8E2960(int a1)
{
  int v1; // ecx
  int n128; // eax
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  sub_8BE3E0();
  sub_8BE440();
  v1 = (unsigned __int16)sub_8BE480();
  n128 = *(_DWORD *)(a1 + 28);
  switch ( n128 )
  {
    case 0:
      *(_DWORD *)(a1 + 28) = 1;
      break;
    case 1:
      *(_DWORD *)(a1 + 28) = 2;
      break;
    case 2:
      n128 = sub_8ABA60(18, 23, &unk_23CC480);
      *(_DWORD *)(a1 + 28) = 3;
      break;
    case 3:
      n128 = sub_8ABAB0(v1);
      if ( !n128 )
      {
        n128 = sub_8B0AC0((int)&savedregs, (int)&unk_23CC480, 14336, 19, 0, 0, 512, 416);
        *(_DWORD *)(a1 + 28) = 4;
      }
      break;
    case 4:
      n128 = sub_8E2D60(v1);
      *(_DWORD *)(a1 + 28) = 5;
      break;
    case 5:
      n128 = sub_8E2D50(v1);
      if ( n128 == 128 )
        *(_DWORD *)(a1 + 28) = 6;
      break;
    case 6:
      *(_DWORD *)(a1 + 28) = 7;
      break;
    case 7:
      if ( (v1 & 0x40) != 0 )
      {
        n128 = FFX_BtlEffect_Enable(-2147483644);
        *(_DWORD *)(a1 + 28) = 8;
      }
      break;
    case 8:
      FFX_BtlHud_NamedAnimStop(1, "scene30");
      n128 = sub_8E2DD0(-6);
      *(_DWORD *)(a1 + 28) = 9;
      break;
    case 9:
      n128 = sub_8E2D50(v1);
      if ( !n128 )
        *(_DWORD *)(a1 + 28) = 10;
      break;
    case 10:
      sub_8E2B10(v1);
      n128 = sub_8AAD20(23);
      break;
    default:
      return n128;
  }
  return n128;
}
