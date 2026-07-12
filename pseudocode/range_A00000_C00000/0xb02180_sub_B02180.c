// Function: sub_B02180
// Address: 0xb02180
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02180()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAFA68;
  v1 = (_DWORD *)unk_CAFA6C;
  *(_DWORD *)(dword_CAFA68 + 4) = unk_CAFA6C;
  *v1 = v0;
  dword_CAFA68 = &dword_CAFA68;
  unk_CAFA6C = &dword_CAFA68;
  if ( (unk_CAFA78 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAFA74);
}

