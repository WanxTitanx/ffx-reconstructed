// Function: sub_B008B0
// Address: 0xb008b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B008B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAAFDC;
  v1 = (_DWORD *)unk_CAAFE0;
  *(_DWORD *)(dword_CAAFDC + 4) = unk_CAAFE0;
  *v1 = v0;
  dword_CAAFDC = &dword_CAAFDC;
  unk_CAAFE0 = &dword_CAAFDC;
  if ( (unk_CAAFEC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAAFE8);
}

