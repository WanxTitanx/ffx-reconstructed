/*
 * Function: FFX_Menu2D_TexHandleByAtlasId
 * Address:   0x8AC870
 * Prototype: char *__cdecl FFX_Menu2D_TexHandleByAtlasId(int n16000)
 *
 * Resolves a texture handle (file path) by atlas ID. Routes to locale-specific
 * texture paths based on FFX_JobSchedule_GetThreadDataPlus4() locale ID.
 *
 * Atlas ID routing:
 *   11948: worldmap.dds.phyre
 *   11980: strtex.dds.phyre
 *   11984: face_ply.dds.phyre
 *   11988: face_smn.dds.phyre
 *   12032: help system (locale-specific path)
 *   12036: help system (locale-specific path)
 *   15808: icon.dds.phyre
 *   15872: meswin.dds.phyre
 *   16000: battle_kuang.dds.phyre (title background)
 *   16001: texture.dds.phyre
 *   16002: ffx_bg.dds.phyre
 *   16003: menu_new.dds.phyre
 *   16004: stonetexture.dds.phyre
 *   16006: summonbg.dds.phyre
 *   16128: battle.dds.phyre
 *   1257216-1257228: mon_boku help system (locale-specific)
 *
 * Locale paths (meswin/battle/icon/strtex):
 *   Default (US): menu_us/
 *   0 (JP):      menu/
 *   2 (FR):      menu_fr/
 *   3 (ES):      menu_es/
 *   4 (DE):      menu_de/
 *   5 (IT):      menu_it/
 *   9 (KR):      menu_kr/
 *   10 (CH):     menu_ch/
 *
 * Callees:
 *   FFX_JobSchedule_GetThreadDataPlus4
 *   FFX_Locale_GetCurrentId
 */

char *__cdecl FFX_Menu2D_TexHandleByAtlasId(int n16000)
{
  int ThreadDataPlus4; // edx
  char *meswin_path; // ebx
  char *battle_path; // esi
  char *icon_path; // edi
  char *strtex_path; // ecx
  char *result_path; // eax

  ThreadDataPlus4 = FFX_JobSchedule_GetThreadDataPlus4();
  switch ( ThreadDataPlus4 )
  {
    case 0:
      meswin_path = off_C5997C[0];   // "/FFX_Data/GameData/PS3Data/menu/D3D11/meswin.dds.phyre"
      battle_path = off_C59D58[0];   // "/FFX_Data/GameData/PS3Data/menu/D3D11/battle.dds.phyre"
      icon_path = " ... /icon.dds.phyre";
      strtex_path = off_C59D60[0];   // "/FFX_Data/GameData/PS3Data/menu/D3D11/strtex.dds.phyre"
      break;
    case 2:
      /* French: menu_fr/ */
      meswin_path = off_C59E5C[0];
      battle_path = off_C59E60[0];
      icon_path = off_C59E64[0];
      strtex_path = off_C59E68[0];
      break;
    case 3:
      /* Spanish: menu_es/ */
      meswin_path = off_C59E6C[0];
      battle_path = off_C59E70[0];
      icon_path = off_C59E74[0];
      strtex_path = off_C59E78[0];
      break;
    case 4:
      /* German: menu_de/ */
      meswin_path = off_C59E7C[0];
      battle_path = off_C59E80[0];
      icon_path = off_C59E84[0];
      strtex_path = off_C59E88[0];
      break;
    case 5:
      /* Italian: menu_it/ */
      meswin_path = off_C59E8C[0];
      battle_path = off_C59E90[0];
      icon_path = off_C59E94[0];
      strtex_path = off_C59E98[0];
      break;
    case 9:
      /* Korean: menu_kr/ */
      meswin_path = off_C59E9C[0];
      battle_path = off_C59EA0[0];
      icon_path = off_C59EA4[0];
      strtex_path = off_C59EA8[0];
      break;
    case 10:
      /* Chinese: menu_ch/ */
      meswin_path = off_C59EAC[0];
      battle_path = off_C59EB0[0];
      icon_path = off_C59EB4[0];
      strtex_path = off_C59EB8[0];
      break;
    default:
      /* US English: menu_us/ */
      strtex_path = off_C59E58[0];
      icon_path = off_C59E54[0];
      battle_path = off_C59E50[0];
      meswin_path = off_C59E4C[0];
      break;
  }
  /* ... atlas ID routing ... */
  return result_path;
}
