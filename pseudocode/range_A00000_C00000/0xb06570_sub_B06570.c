// Function: sub_B06570
// Address: 0xb06570
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B06570()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CCA234;
  v1 = (_DWORD *)unk_CCA238;
  *(_DWORD *)(dword_CCA234 + 4) = unk_CCA238;
  *v1 = v0;
  dword_CCA234 = &dword_CCA234;
  unk_CCA238 = &dword_CCA234;
  if ( (unk_CCA244 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)dword_CCA240);
}

