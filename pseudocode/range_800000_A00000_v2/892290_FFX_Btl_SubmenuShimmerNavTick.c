// Function: FFX_Btl_SubmenuShimmerNavTick
// Address: 0x892290
int FFX_Btl_SubmenuShimmerNavTick()
{
  int result; // eax
  char v1; // bl
  char v2; // cl
  unsigned __int16 v3; // ax
  __int16 v4; // dx
  __int16 v5; // si
  __int16 v6; // si

  result = n9_0 - 1;
  switch ( n9_0 )
  {
    case 1:
      byte_133D6B2[1] = 0;
      result = FFX_BtlHud_NamedAnimStartSimple(2, "btidu");
      ++n9_0;
      return result;
    case 2:
      result = FFX_BtlHud_NamedAnimIsPlaying(2, "btidu");
      if ( result == 1 )
        ++n9_0;
      return result;
    case 3:
      result = FFX_BtlHud_ShimmerStopOnEntry();
      ++n9_0;
      return result;
    case 4:
      FFX_BtlHud_ShimmerStart();
      v1 = FFX_BtlHud_InputStateRead(0, 0, -1);
      v2 = FFX_BtlHud_InputStateRead(0, 0, 0);
      if ( MEMORY[0x133F750] <= 0.0 )
      {
        n9_0 = 7;
        return 7;
      }
      if ( (v1 & 0x20) != 0 || (v2 & 0x20) != 0 )
      {
        if ( MEMORY[0x133D702] >= MEMORY[0x133D6FC] && MEMORY[0x133D702] <= MEMORY[0x133D6FE] )
        {
          n9_0 = 5;
          return 5;
        }
        FFX_Btl_MenuDispatchSfx(3);
        v3 = abs16(word_133D704);
        v4 = MEMORY[0x133D6F6];
        word_133D704 = v3;
        v5 = MEMORY[0x133D6F6];
      }
      else
      {
        v3 = word_133D704;
        v5 = MEMORY[0x133D702];
        v4 = MEMORY[0x133D6F6];
      }
      v6 = v3 + v5;
      result = v6;
      MEMORY[0x133D702] = v6;
      if ( v6 > v4 + unk_133D6FA )
      {
        v6 = 2 * (v4 + unk_133D6FA) - v6;
        result = -*(_DWORD *)&word_133D704;
        MEMORY[0x133D702] = v6;
        word_133D704 = -word_133D704;
      }
      if ( v6 < v4 )
      {
        result = -*(_DWORD *)&word_133D704;
        MEMORY[0x133D702] = 2 * v4 - v6;
        word_133D704 = -word_133D704;
      }
      return result;
    case 5:
      FFX_BtlHud_ShimmerStopOnExit();
      byte_133D6B2[1] = 1;
      FFX_BtlHud_NamedAnimStart(2, "bgood");
      FFX_Btl_MenuDispatchSfx(104);
      n9_0 = 6;
      return 6;
    case 6:
      result = FFX_BtlHud_NamedAnimIsPlaying(2, "bgood");
      if ( result == 1 )
        goto LABEL_21;
      return result;
    case 7:
      FFX_BtlHud_ShimmerStopOnExit();
      byte_133D6B2[1] = 0;
      n9_0 = 8;
      return 8;
    case 8:
LABEL_21:
      FFX_BtlHud_NamedAnimStop(2, "btidu");
      n9_0 = 9;
      return 9;
    case 9:
      ++n9_0;
      return result;
    case 10:
      FFX_BtlHud_SubmenuWriteFrameData(0, byte_133D6B2[1], MEMORY[0x133F750], MEMORY[0x133F74C]);
      FFX_BtlHud_ShimmerResetAll();
      n9_0 = 0;
      return 0;
    default:
      return result;
  }
}
