// FFX DatEt: Load VFX texture lists global
int __thiscall FFX_DatEt_LoadVfxTexLists_Global_structural(_DWORD *this)
{
  int result; // eax
  char Buffer[256]; // [esp+4h] [ebp-204h] BYREF
  char Src[256]; // [esp+104h] [ebp-104h] BYREF

  FFX_FileSystem_BuildDataPath( /*0x665817*/
    "/FFX_Data/GameData/PS3Data/yonishi_data/dat_et/bat_eff/et_tex/tex/TexList.txt",
    Src,
    256);
  FFX_FileSystem_BuildDataPath("/FFX_Data/GameData/PS3Data/yonishi_data/dat_et/et_ffx/tex/TexList.txt", Buffer, 256); /*0x66582d*/
  result = LoadVfxResourceFileList(this, 0, Src, 0); /*0x665842*/
  if ( !result ) /*0x665849*/
    return LoadVfxResourceFileList(this, 0, Buffer, 0); /*0x665857*/
  return result; /*0x66585c*/
}