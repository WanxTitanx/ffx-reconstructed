// Function: sub_B02590
// Address: 0xb02590
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02590()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB01C8;
  v1 = (_DWORD *)unk_CB01CC;
  *(_DWORD *)(dword_CB01C8 + 4) = unk_CB01CC;
  *v1 = v0;
  dword_CB01C8 = &dword_CB01C8;
  unk_CB01CC = &dword_CB01C8;
  if ( (unk_CB01D8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB01D4);
}

