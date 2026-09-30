// NOME ENGANOSO: Nao atualiza ossos. Carrega texturas PS3 de magia. Busca slot de animacao por chave n438, limpa slot e invoca FFX_Ps3Data_LoadTextureListAndRegisterEntries_structural com caminho /FFX_Data/GameData/PS3Data/magic/<nome>/tex/TexList.txt
// EVIDENCIA: Nome original Phyre_Animation_UpdateBones ENGANOSO. Funcao carrega TexList.txt de PS3Data/magic e chama FFX_Ps3Data_LoadTextureListAndRegisterEntries_structural. Nao atualiza ossos.
// FFX MagicTex: Load PS3 texture list
int __thiscall FFX_MagicTex_LoadPS3TexList(_DWORD *this, int n438)
{
  unsigned int v3; // esi
  int v4; // eax
  _DWORD *i; // ecx
  const char *v7; // ecx
  char Buffer[256]; // [esp+10h] [ebp-204h] BYREF
  char Buffer_1[256]; // [esp+110h] [ebp-104h] BYREF

  FFX_FileSystem_BuildDataPath("/FFX_Data/GameData/PS3Data/magic", Buffer_1, 256); /*0x6710c9*/
  v3 = *(this + 10); /*0x6710ce*/
  v4 = 0; /*0x6710d4*/
  if ( !v3 ) /*0x6710d8*/
    return 0; /*0x6710d8*/
  for ( i = (_DWORD *)*(this + 12); !*i || *i != n438; ++i ) /*0x6710da*/
  {
    if ( ++v4 >= v3 ) /*0x6710f0*/
      return 0; /*0x6710f0*/
  }
  if ( v4 == -1 ) /*0x67110a*/
    return 0; /*0x6710f2*/
  *(_DWORD *)(*(this + 12) + 4 * v4) = 0; /*0x67110f*/
  v7 = (const char *)(*(this + 16064) - (*(_BYTE *)(this + 16064) & 1)); /*0x671126*/
  if ( !v7 ) /*0x671128*/
    return 5; /*0x67112c*/
  sprintf(Buffer, "%s/%s/tex/TexList.txt", Buffer_1, v7); /*0x671154*/
  return FFX_Ps3Data_LoadTextureListAndRegisterEntries_structural((int)this, Buffer, n438); /*0x6710f2*/
}