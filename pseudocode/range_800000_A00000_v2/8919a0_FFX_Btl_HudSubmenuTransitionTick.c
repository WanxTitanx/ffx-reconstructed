// Function: FFX_Btl_HudSubmenuTransitionTick
// Address: 0x8919a0
int FFX_Btl_HudSubmenuTransitionTick()
{
  int n20; // eax

  n20 = unk_133F668 - 1;
  switch ( unk_133F668 )
  {
    case 1:
      n20 = 20;
      MEMORY[0x133F6C2] = 20;
      goto LABEL_3;
    case 3:
    case 6:
    case 7:
LABEL_3:
      ++unk_133F668;
      break;
    case 4:
      if ( unk_133D6A0 == 1 )
      {
        n20 = 32;
        n32 = 32;
      }
      if ( (n32 & 0x20) != 0 )
      {
        n20 = FFX_Btl_MenuDispatchSfx(1);
        ++unk_133F668;
      }
      break;
    case 8:
      unk_133F668 = 0;
      n20 = 0;
      break;
    default:
      return n20;
  }
  return n20;
}
