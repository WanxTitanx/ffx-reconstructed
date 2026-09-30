// FFX Menu2D: Get atlas dimensions
float *__cdecl FFX_Menu2D_GetAtlasDimensions_structural(int n15360, float *a2, float *a3)
{
  FFXBattleState *v3; // ecx
  float *result; // eax
  int n5; // ecx
  int v6; // ecx

  // [Jarvis naming goal 2026-06-17] structural name from aggressive-honest FFX.exe pass.
  if ( n15360 <= 15712 )
  {
    if ( n15360 == 15712 )
    {
      n5 = 5; /*0x8ac472*/
    }
    else if ( n15360 > 15360 )
    {
      switch ( n15360 ) /*0x8ac444*/
      {
        case 15616: /*0x8ac444*/
          n5 = (FFX_Battle_QueueGateCheck(v3) != 0) + 1; /*0x8ac458*/
          break; /*0x8ac459*/
        case 15617: /*0x8ac444*/
          n5 = 3; /*0x8ac45e*/
          break; /*0x8ac463*/
        case 15632: /*0x8ac444*/
        case 15648: /*0x8ac444*/
        case 15664: /*0x8ac444*/
          goto LABEL_32;
        case 15680: /*0x8ac444*/
          n5 = 4; /*0x8ac468*/
          break; /*0x8ac46d*/
        default:
          goto LABEL_31;
      }
    }
    else
    {
      if ( n15360 != 15360 ) /*0x8ac3ce*/
      {
        switch ( n15360 ) /*0x8ac3e5*/
        {
          case 11948: /*0x8ac3e5*/
            *a2 = 512.0; /*0x8ac40d*/
            *a3 = 416.0; /*0x8ac418*/
            result = a3; /*0x8ac40f*/
            break; /*0x8ac41b*/
          case 11980: /*0x8ac3e5*/
            *a2 = 512.0; /*0x8ac3f5*/
            *a3 = 128.0; /*0x8ac400*/
            result = a3; /*0x8ac3f7*/
            break; /*0x8ac403*/
          case 11984: /*0x8ac3e5*/
          case 11988: /*0x8ac3e5*/
            goto LABEL_26;
          case 12032: /*0x8ac3e5*/
          case 12036: /*0x8ac3e5*/
            goto LABEL_34;
          default:
            goto LABEL_31;
        }
        return result; /*0x8ac403*/
      }
      n5 = FFX_Locale_GetLanguageId_Thunk() != 0 ? 4 : 0;
    }
LABEL_33:
    v6 = 16 * n5; /*0x8ac56b*/
    *a2 = (float)*(__int16 *)((char *)&unk_1841D6C + v6); /*0x8ac57e*/
    *a3 = (float)*(__int16 *)((char *)&unk_1841D6E + v6); /*0x8ac590*/
    return a3; /*0x8ac593*/
  }
  if ( n15360 <= 16000 ) /*0x8ac481*/
  {
    switch ( n15360 ) /*0x8ac483*/
    {
      case 16000: /*0x8ac483*/
LABEL_22:
        *a2 = 2048.0; /*0x8ac4dc*/
        *a3 = 1024.0; /*0x8ac4f0*/
        return a3; /*0x8ac4f3*/
      case 15744: /*0x8ac483*/
        *a2 = 128.0; /*0x8ac4cd*/
        *a3 = 256.0; /*0x8ac4d8*/
        return a3; /*0x8ac4db*/
      case 15808: /*0x8ac483*/
        *a2 = 256.0; /*0x8ac4b5*/
        *a3 = 128.0; /*0x8ac4c0*/
        return a3; /*0x8ac4c3*/
      case 15872: /*0x8ac483*/
LABEL_19:
        *a2 = 256.0; /*0x8ac49a*/
        *a3 = 256.0; /*0x8ac4a8*/
        return a3; /*0x8ac4ab*/
    }
LABEL_31:
    dbgPrintf(); /*0x8ac55c*/
LABEL_32:
    n5 = 0; /*0x8ac569*/
    goto LABEL_33; /*0x8ac569*/
  }
  if ( n15360 > 1257216 ) /*0x8ac4f9*/
  {
    if ( n15360 != 1257220 ) /*0x8ac548*/
    {
      if ( n15360 == 1257224 || n15360 == 1257228 ) /*0x8ac556*/
        goto LABEL_19; /*0x8ac556*/
      goto LABEL_31; /*0x8ac556*/
    }
LABEL_34:
    *a2 = 512.0; /*0x8ac594*/
    *a3 = 512.0; /*0x8ac5a2*/
    return a3; /*0x8ac59f*/
  }
  if ( n15360 == 1257216 ) /*0x8ac4fb*/
    goto LABEL_34; /*0x8ac4fb*/
  switch ( n15360 ) /*0x8ac512*/
  {
    case 16001: /*0x8ac512*/
LABEL_26:
      *a2 = 512.0; /*0x8ac519*/
      *a3 = 256.0; /*0x8ac52d*/
      result = a3; /*0x8ac524*/
      break; /*0x8ac530*/
    case 16003: /*0x8ac512*/
      goto LABEL_22;
    case 16006: /*0x8ac512*/
      *a2 = 1024.0; /*0x8ac53a*/
      *a3 = 1024.0; /*0x8ac53f*/
      result = a3; /*0x8ac53c*/
      break; /*0x8ac542*/
    case 16128: /*0x8ac512*/
      goto LABEL_19;
    default:
      goto LABEL_31;
  }
  return result; /*0x8ac402*/
}