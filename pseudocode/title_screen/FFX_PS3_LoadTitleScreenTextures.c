/*
 * Function: FFX_PS3_LoadTitleScreenTextures
 * Address:   0x67CA70
 * Prototype: int FFX_PS3_LoadTitleScreenTextures()
 *
 * Loads title screen textures asynchronously.
 * Texture path list at off_C59EBC to off_C59ED0.
 * Path format: /FFX_Data/GameData/PS3Data/.../*.dds.phyre
 *
 * Referenced texture paths:
 *   /FFX_Data/GameData/PS3Data/map/dream/fp/tex/D3D11/dirt01.dds.phyre
 *   /FFX_Data/GameData/PS3Data/menu/D3D11/copyright_nagi.dds.phyre
 *
 * Callees:
 *   FFX_Texture_LoadAsync
 */

int FFX_PS3_LoadTitleScreenTextures()
{
  const char **path_ptr; // esi
  int result; // eax

  path_ptr = (const char **)&off_C59EBC;
  do
    result = FFX_Texture_LoadAsync(*path_ptr++);
  while ( (int)path_ptr < (int)&off_C59ED0 );
  return result;
}
