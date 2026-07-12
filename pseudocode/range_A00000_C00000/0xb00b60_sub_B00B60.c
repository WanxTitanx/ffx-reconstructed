// Function: sub_B00B60
// Address: 0xb00b60
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B00B60()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAB9B4;
  v1 = (_DWORD *)unk_CAB9B8;
  *(_DWORD *)(dword_CAB9B4 + 4) = unk_CAB9B8;
  *v1 = v0;
  dword_CAB9B4 = &dword_CAB9B4;
  unk_CAB9B8 = &dword_CAB9B4;
  if ( (unk_CAB9C4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAB9C0);
}

