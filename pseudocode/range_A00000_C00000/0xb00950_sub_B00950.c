// Function: sub_B00950
// Address: 0xb00950
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B00950()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAB004;
  v1 = (_DWORD *)unk_CAB008;
  *(_DWORD *)(dword_CAB004 + 4) = unk_CAB008;
  *v1 = v0;
  dword_CAB004 = &dword_CAB004;
  unk_CAB008 = &dword_CAB004;
  if ( (unk_CAB014 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAB010);
}

