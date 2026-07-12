// Function: sub_AFFF00
// Address: 0xafff00
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFFF00()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA93A8;
  v1 = (_DWORD *)unk_CA93AC;
  *(_DWORD *)(dword_CA93A8 + 4) = unk_CA93AC;
  *v1 = v0;
  dword_CA93A8 = &dword_CA93A8;
  unk_CA93AC = &dword_CA93A8;
  if ( (unk_CA93B8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA93B4);
}

