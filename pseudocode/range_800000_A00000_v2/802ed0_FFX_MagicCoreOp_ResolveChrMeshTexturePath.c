// Function: FFX_MagicCoreOp_ResolveChrMeshTexturePath
// Address: 0x802ed0
int __cdecl FFX_MagicCoreOp_ResolveChrMeshTexturePath(__int64 a1, int a2, int a3, int a4)
{
  const char *NameFromModelSlot; // esi
  char v5; // al
  int v7; // [esp+8h] [ebp-338h] BYREF
  int v8; // [esp+Ch] [ebp-334h] BYREF
  int v9; // [esp+10h] [ebp-330h] BYREF
  char Source[256]; // [esp+14h] [ebp-32Ch] BYREF
  char Buffer[256]; // [esp+114h] [ebp-22Ch] BYREF
  char Str[256]; // [esp+214h] [ebp-12Ch] BYREF
  char /FFX_Data/GameData/PS3Data/chr[32]; // [esp+314h] [ebp-2Ch] BYREF
  char D3D11[8]; // [esp+334h] [ebp-Ch] BYREF

  strcpy(/FFX_Data/GameData/PS3Data/chr, "/FFX_Data/GameData/PS3Data/chr");
  strcpy(D3D11, "D3D11");
  v9 = 0;
  v8 = 0;
  v7 = 1;
  NameFromModelSlot = (const char *)FFX_MagicPath_GetNameFromModelSlot(a3);
  sprintf(Buffer, "%s.dds.phyre", NameFromModelSlot);
  v5 = *NameFromModelSlot;
  if ( *NameFromModelSlot == 109 )
  {
    sprintf(Str, "%s/mon/%s/tex/%s/%s", /FFX_Data/GameData/PS3Data/chr, NameFromModelSlot, D3D11, Buffer);
  }
  else
  {
    switch ( v5 )
    {
      case 'n':
        sprintf(Str, "%s/npc/%s/tex/%s/%s", /FFX_Data/GameData/PS3Data/chr, NameFromModelSlot, D3D11, Buffer);
        break;
      case 'f':
        sprintf(Str, "%s/obj/%s/tex/%s/%s", /FFX_Data/GameData/PS3Data/chr, NameFromModelSlot, D3D11, Buffer);
        break;
      case 'c':
        sprintf(Str, "%s/pc/%s/tex/%s/%s", /FFX_Data/GameData/PS3Data/chr, NameFromModelSlot, D3D11, Buffer);
        break;
      case 's':
        sprintf(Str, "%s/sum/%s/tex/%s/%s", /FFX_Data/GameData/PS3Data/chr, NameFromModelSlot, D3D11, Buffer);
        break;
      case 'w':
        sprintf(Str, "%s/wep/%s/tex/%s/%s", /FFX_Data/GameData/PS3Data/chr, NameFromModelSlot, D3D11, Buffer);
        break;
    }
  }
  nullsub_34();
  FFX_FileIO_UnifyFilename(Str, Source, 256);
  v9 = 3 * *(_DWORD *)(a2 + 4);
  v8 = v9;
  FFX_MagicCoreOp_CreateModelTexturedVtxFormat(a1, a4);
  FFX_Ps3Data_BuildTextureSlotRecord_LoadTime(a1, 1, (int)&v9, &v8, Source, (int)&v7);
  return 1;
}
