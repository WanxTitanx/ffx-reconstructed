// Function: FFX_Btl_SubmenuStateMachine
// Address: 0x890ee0
void FFX_Btl_SubmenuStateMachine()
{
  __int16 v0; // dx

  switch ( *(_WORD *)&byte_133D6B2[2] )
  {
    case 1:
      byte_133D6B2[0] = 0;
      FFX_BtlHud_NamedAnimStartSimple(2, "bauro");
      ++*(_WORD *)&byte_133D6B2[2];
      break;
    case 2:
      if ( FFX_BtlHud_NamedAnimIsPlaying(2, "bauro") )
      {
        FFX_BtlHud_NamedAnimStart(2, "bauro2");
        ++*(_WORD *)&byte_133D6B2[2];
      }
      break;
    case 3:
      FFX_BtlHud_ShimmerStopOnEntry();
      ++*(_WORD *)&byte_133D6B2[2];
      break;
    case 4:
      FFX_BtlHud_ShimmerStart();
      if ( MEMORY[0x133F750] > 0.0 )
      {
        if ( unk_25D09D4 )
        {
          if ( unk_25D09D4 == *(_WORD *)(unk_133D6C4 + 2 * unk_133D6BC[0]) )
          {
            v0 = unk_133D6BC[0] + 1;
          }
          else
          {
            FFX_Btl_MenuDispatchSfx(105);
            v0 = 0;
          }
          unk_133D6BC[0] = v0;
          if ( v0 >= unk_133D6C0 )
            *(_WORD *)&byte_133D6B2[2] = 5;
        }
      }
      else
      {
        *(_WORD *)&byte_133D6B2[2] = 7;
      }
      break;
    case 5:
      FFX_BtlHud_ShimmerStopOnExit();
      byte_133D6B2[0] = 1;
      FFX_BtlHud_NamedAnimStart(2, "bgood");
      FFX_Btl_MenuDispatchSfx(104);
      *(_WORD *)&byte_133D6B2[2] = 6;
      break;
    case 6:
      if ( FFX_BtlHud_NamedAnimIsPlaying(2, "bgood") )
        goto LABEL_16;
      break;
    case 7:
      FFX_BtlHud_ShimmerStopOnExit();
      byte_133D6B2[0] = 0;
      *(_WORD *)&byte_133D6B2[2] = 8;
      break;
    case 8:
LABEL_16:
      FFX_BtlHud_NamedAnimStop(2, "bauro");
      FFX_BtlHud_NamedAnimStop(2, "bauro2");
      *(_WORD *)&byte_133D6B2[2] = 9;
      break;
    case 9:
      ++*(_WORD *)&byte_133D6B2[2];
      break;
    case 0xA:
      FFX_BtlHud_SubmenuWriteFrameData(2u, byte_133D6B2[0], MEMORY[0x133F750], MEMORY[0x133F74C]);
      FFX_BtlHud_ShimmerResetAll();
      *(_WORD *)&byte_133D6B2[2] = 0;
      break;
    default:
      return;
  }
}
