// Function: sub_B02920
// Address: 0xb02920
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02920()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB0CDC;
  v1 = (_DWORD *)unk_CB0CE0;
  *(_DWORD *)(dword_CB0CDC + 4) = unk_CB0CE0;
  *v1 = v0;
  dword_CB0CDC = &dword_CB0CDC;
  unk_CB0CE0 = &dword_CB0CDC;
  if ( (unk_CB0CEC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB0CE8);
}

