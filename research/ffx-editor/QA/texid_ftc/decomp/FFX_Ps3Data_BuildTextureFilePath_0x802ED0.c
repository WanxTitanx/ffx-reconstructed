// FFX Ps3Data: Build texture file path
int __cdecl FFX_Ps3Data_BuildTextureFilePath(__int64 a1, int a2, int a3, int n0x4000)
{
  const char *DwordFromResourceOffset4; // esi
  char v6; // al
  int v8; // [esp+8h] [ebp-338h] BYREF
  int v9; // [esp+Ch] [ebp-334h] BYREF
  int v10; // [esp+10h] [ebp-330h] BYREF
  char Source[256]; // [esp+14h] [ebp-32Ch] BYREF
  char Buffer[256]; // [esp+114h] [ebp-22Ch] BYREF
  char Str[256]; // [esp+214h] [ebp-12Ch] BYREF
  char /FFX_Data/GameData/PS3Data/chr[32]; // [esp+314h] [ebp-2Ch] BYREF
  char D3D11[8]; // [esp+334h] [ebp-Ch] BYREF

  strcpy(/FFX_Data/GameData/PS3Data/chr, "/FFX_Data/GameData/PS3Data/chr"); /*0x802efa*/
  strcpy(D3D11, "D3D11"); /*0x802efe*/
  v10 = 0; /*0x802f08*/
  v9 = 0; /*0x802f12*/
  v8 = 1; /*0x802f1c*/
  DwordFromResourceOffset4 = (const char *)FFX_Magic_ReadDwordFromResourceOffset4(a3); /*0x802f36*/
  sprintf(Buffer, "%s.dds.phyre", DwordFromResourceOffset4); /*0x802f45*/
  v6 = *DwordFromResourceOffset4; /*0x802f47*/
  if ( *DwordFromResourceOffset4 == 109 ) /*0x802f4e*/
  {
    sprintf(Str, "%s/mon/%s/tex/%s/%s", /FFX_Data/GameData/PS3Data/chr, DwordFromResourceOffset4, D3D11, Buffer); /*0x802f65*/
  }
  else
  {
    switch ( v6 ) /*0x802f6c*/
    {
      case 'n': /*0x802f6c*/
        sprintf(Str, "%s/npc/%s/tex/%s/%s", /FFX_Data/GameData/PS3Data/chr, DwordFromResourceOffset4, D3D11, Buffer); /*0x802f83*/
        break;
      case 'f': /*0x802f6c*/
        sprintf(Str, "%s/obj/%s/tex/%s/%s", /FFX_Data/GameData/PS3Data/chr, DwordFromResourceOffset4, D3D11, Buffer); /*0x802f9e*/
        break;
      case 'c': /*0x802f6c*/
        sprintf(Str, "%s/pc/%s/tex/%s/%s", /FFX_Data/GameData/PS3Data/chr, DwordFromResourceOffset4, D3D11, Buffer); /*0x802fb9*/
        break;
      case 's': /*0x802f6c*/
        sprintf(Str, "%s/sum/%s/tex/%s/%s", /FFX_Data/GameData/PS3Data/chr, DwordFromResourceOffset4, D3D11, Buffer); /*0x802fd4*/
        break;
      case 'w': /*0x802f6c*/
        sprintf(Str, "%s/wep/%s/tex/%s/%s", /FFX_Data/GameData/PS3Data/chr, DwordFromResourceOffset4, D3D11, Buffer); /*0x802ff6*/
        break;
    }
  }
  dbgPrintf(); /*0x803007*/
  FFX_FileSystem_BuildDataPath(Str, Source, 256); /*0x80301f*/
  v10 = 3 * *(_DWORD *)(a2 + 4); /*0x803038*/
  v9 = v10; /*0x80303e*/
  FFX_TextureSlot_MatrixInit(a1, n0x4000); /*0x803044*/
  FFX_Ps3Data_BuildTextureSlotRecord_LoadTime(a1, 1, (int)&v10, &v9, Source, (int)&v8); /*0x803069*/
  return 1; /*0x803074*/
}