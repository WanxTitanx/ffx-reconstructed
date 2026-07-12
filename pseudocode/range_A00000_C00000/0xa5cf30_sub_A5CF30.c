// Function: sub_A5CF30
// Address: 0xa5cf30
// Size: 0x188
// Prototype: 

int __cdecl sub_A5CF30(int a1, int a2, int a3)
{
  int result; // eax
  int i; // esi

  switch ( a1 )
  {
    case 1:
    case 2:
    case 3:
    case 4:
      sub_A45860(1, a2);
      FFX_BtlEffect_Enable_w_0();
      result = 1;
      break;
    case 5:
      sub_A45860(25, a2);
      FFX_BtlEffect_Enable_w();
      result = 1;
      break;
    case 6:
      sub_A45860(35, a2);
      FFX_BtlEffect_Enable_w();
      result = 1;
      break;
    case 7:
      sub_A45860(36, a2);
      FFX_BtlEffect_Enable_w();
      result = 1;
      break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 24:
      sub_A458A0(a3, a2);
      result = 1;
      break;
    case 12:
    case 13:
    case 14:
    case 15:
      sub_A458F0(a3, a2);
      result = 1;
      break;
    case 16:
      sub_A45860(5, a2);
      FFX_BtlEffect_Enable_w();
      result = 1;
      break;
    case 17:
      sub_A45860(9, a2);
      FFX_BtlEffect_Enable_w();
      result = 1;
      break;
    case 18:
      sub_A45860(13, a2);
      FFX_BtlEffect_Enable_w();
      result = 1;
      break;
    case 19:
      sub_A45860(17, a2);
      FFX_BtlEffect_Enable_w();
      result = 1;
      break;
    case 20:
      sub_A45860(21, a2);
      FFX_BtlEffect_Enable_w();
      result = 1;
      break;
    case 21:
      sub_A45860(29, a2);
      FFX_BtlEffect_Enable_w();
      result = 1;
      break;
    case 22:
      sub_A45860(33, a2);
      FFX_BtlEffect_Enable_w();
      result = 1;
      break;
    case 23:
      sub_A45860(1, a2);
      for ( i = 0; i < 7; ++i )
        sub_A458C0(i, a2);
      FFX_BtlEffect_Enable_w_0();
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

