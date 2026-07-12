// Function: sub_B02330
// Address: 0xb02330
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02330()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAFC58;
  v1 = (_DWORD *)unk_CAFC5C;
  *(_DWORD *)(dword_CAFC58 + 4) = unk_CAFC5C;
  *v1 = v0;
  dword_CAFC58 = &dword_CAFC58;
  unk_CAFC5C = &dword_CAFC58;
  if ( (unk_CAFC68 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAFC64);
}

