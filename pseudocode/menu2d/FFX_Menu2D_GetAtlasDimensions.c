/*
 * Function: FFX_Menu2D_GetAtlasDimensions_structural
 * Address:   0x8AC3B0
 * Prototype: float *__cdecl FFX_Menu2D_GetAtlasDimensions_structural(int n15360, float *a2, float *a3)
 *
 * Returns texture atlas dimensions (width, height) for a given atlas ID.
 * Dimensions are hardcoded per atlas ID.
 *
 * Atlas dimensions:
 *   11948:   512 x 416 (worldmap)
 *   11980:   512 x 128 (strtex)
 *   15360:   locale-dependent (unk_1841D6C table)
 *   15616:   1-2 rows (battle-dependent)
 *   15617:   3 rows
 *   15680:   4 rows
 *   15712:   5 rows
 *   15744:   128 x 256
 *   15808:   256 x 128 (icon)
 *   15872:   256 x 256 (meswin)
 *   16000:   2048 x 1024 (battle_kuang / title)
 *   16001:   512 x 256 (texture)
 *   16003:   2048 x 1024 (menu_new)
 *   16004:   1024 x 1024 (stonetexture)
 *   16006:   1024 x 1024 (summonbg)
 *   16128:   256 x 256 (battle)
 *   1257216: 512 x 512 (help systems)
 *   1257220: 512 x 512
 *   1257224: 256 x 256
 *   1257228: 256 x 256
 *
 * Callees:
 *   FFX_Battle_QueueGateCheck
 *   FFX_Locale_GetLanguageId_Thunk
 *   nullsub_34 (assertion print)
 */

float *__cdecl FFX_Menu2D_GetAtlasDimensions_structural(int n15360, float *a2, float *a3)
{
  FFXBattleState *v3; // ecx
  float *result; // eax
  int n5; // ecx
  int v6; // ecx
  const char *savedregs; // [esp+0h] [ebp+0h]

  if ( n15360 <= 15712 )
  {
    if ( n15360 == 15712 )
    {
      n5 = 5;
    }
    else if ( n15360 > 15360 )
    {
      switch ( n15360 )
      {
        case 15616:
          n5 = (FFX_Battle_QueueGateCheck(v3) != 0) + 1;
          break;
        case 15617:
          n5 = 3;
          break;
        case 15680:
          n5 = 4;
          break;
        default:
          goto LABEL_31;
      }
    }
    else
    {
      if ( n15360 != 15360 )
      {
        switch ( n15360 )
        {
          case 11948:
            *a2 = 512.0; *a3 = 416.0; return a3;
          case 11980:
            *a2 = 512.0; *a3 = 128.0; return a3;
          default:
            goto LABEL_31;
        }
      }
      n5 = FFX_Locale_GetLanguageId_Thunk() != 0 ? 4 : 0;
    }
LABEL_33:
    v6 = 16 * n5;
    *a2 = (float)*(__int16 *)((char *)&unk_1841D6C + v6);
    *a3 = (float)*(__int16 *)((char *)&unk_1841D6E + v6);
    return a3;
  }
  if ( n15360 <= 16000 )
  {
    switch ( n15360 )
    {
      case 16000: *a2 = 2048.0; *a3 = 1024.0; return a3;
      case 15744: *a2 = 128.0;  *a3 = 256.0;  return a3;
      case 15808: *a2 = 256.0;  *a3 = 128.0;  return a3;
      case 15872: *a2 = 256.0;  *a3 = 256.0;  return a3;
    }
LABEL_31:
    nullsub_34("VIRTUOS ASSERTION:Image not found %s\n", savedregs);
LABEL_32:
    n5 = 0;
    goto LABEL_33;
  }
  if ( n15360 > 1257216 )
  {
    if ( n15360 != 1257220 )
    {
      if ( n15360 == 1257224 || n15360 == 1257228 )
        goto LABEL_19; /* 256x256 */
      goto LABEL_31;
    }
LABEL_34:
    *a2 = 512.0; *a3 = 512.0; return a3;
  }
  if ( n15360 == 1257216 ) goto LABEL_34;
  switch ( n15360 )
  {
    case 16001: *a2 = 512.0;  *a3 = 256.0;  return a3;
    case 16003: *a2 = 2048.0; *a3 = 1024.0; return a3;
    case 16006: *a2 = 1024.0; *a3 = 1024.0; return a3;
    case 16128: goto LABEL_19; /* 256x256 */
    default:    goto LABEL_31;
  }
  return result;
}
