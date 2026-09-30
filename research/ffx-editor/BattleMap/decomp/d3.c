// FFX FieldMap: Register guide map blob
int __cdecl FFX_FieldMap_RegisterGuideMapBlob(unsigned int FfxmapIdFile)
{
  int v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // esi
  int v11; // [esp-10h] [ebp-18h]
  int v12; // [esp-8h] [ebp-10h]
  int v13; // [esp+4h] [ebp-4h]
  signed int FfxmapIdFilea; // [esp+10h] [ebp+8h]

  // [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass. /*0x844bca*/
  if ( !FfxmapIdFile ) /*0x844bca*/
    return FFX_Field_MenuItemTextDisplay_init_structural(0); /*0x844bcd*/
  if ( *(_WORD *)(FfxmapIdFile + 4) > 4610 != MEMORY[0x1303478] ) /*0x844bf2*/
    FFX_Graphics_SetAudioInterpolationPtrs((char)MEMORY[0x1303478], *(_WORD *)(FfxmapIdFile + 4) > 4610); /*0x844bf6*/
  MEMORY[0x1303478] = *(_WORD *)(FfxmapIdFile + 4) > 4610; /*0x844c04*/
  v3 = FfxmapIdFile - *(_DWORD *)FfxmapIdFile; /*0x844c0b*/
  v13 = v3; /*0x844c0d*/
  if ( v3 ) /*0x844c10*/
  {
    v12 = *(_DWORD *)(FfxmapIdFile + 28); /*0x844c12*/
    *(_DWORD *)FfxmapIdFile = v3; /*0x844c15*/
    v4 = Std_IdentityFunc(v12); /*0x844c17*/
    v5 = Std_IdentityFunc_B(v3 + v4); /*0x844c1f*/
    v11 = *(_DWORD *)(FfxmapIdFile + 24); /*0x844c24*/
    *(_DWORD *)(FfxmapIdFile + 28) = v5; /*0x844c27*/
    v6 = Std_IdentityFunc(v11); /*0x844c2a*/
    *(_DWORD *)(FfxmapIdFile + 24) = Std_IdentityFunc_B(v3 + v6); /*0x844c37*/
    FfxmapIdFilea = 0; /*0x844c3f*/
    if ( *(__int16 *)(FfxmapIdFile + 6) > 0 ) /*0x844c4a*/
    {
      v7 = 0; /*0x844c4d*/
      do /*0x844c8e*/
      {
        v8 = Std_IdentityFunc(*(_DWORD *)(FfxmapIdFile + 28)); /*0x844c53*/
        v9 = Std_IdentityFunc(*(_DWORD *)(v8 + v7 + 12)); /*0x844c5d*/
        v10 = Std_IdentityFunc_B(v3 + v9); /*0x844c6d*/
        *(_DWORD *)(Std_IdentityFunc(*(_DWORD *)(FfxmapIdFile + 28)) + v7 + 12) = v10; /*0x844c77*/
        v3 = v13; /*0x844c7f*/
        ++FfxmapIdFilea; /*0x844c86*/
        v7 += 16; /*0x844c89*/
      }
      while ( FfxmapIdFilea < *(__int16 *)(FfxmapIdFile + 6) ); /*0x844c8e*/
    }
  }
  return FFX_Field_MenuItemTextDisplay_init_structural(FfxmapIdFile); /*0x844bd5*/
}