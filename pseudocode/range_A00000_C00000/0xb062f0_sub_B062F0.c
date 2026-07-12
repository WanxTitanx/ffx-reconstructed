// Function: sub_B062F0
// Address: 0xb062f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B062F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CCA00C;
  v1 = (_DWORD *)unk_CCA010;
  *(_DWORD *)(dword_CCA00C + 4) = unk_CCA010;
  *v1 = v0;
  dword_CCA00C = &dword_CCA00C;
  unk_CCA010 = &dword_CCA00C;
  if ( (unk_CCA01C & 1) != 0 )
    Phyre_Memory_AlignedFree((int)dword_CCA018);
}

