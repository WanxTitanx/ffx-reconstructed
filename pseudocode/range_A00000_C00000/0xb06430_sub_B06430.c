// Function: sub_B06430
// Address: 0xb06430
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B06430()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CCA084;
  v1 = (_DWORD *)unk_CCA088;
  *(_DWORD *)(dword_CCA084 + 4) = unk_CCA088;
  *v1 = v0;
  dword_CCA084 = &dword_CCA084;
  unk_CCA088 = &dword_CCA084;
  if ( (unk_CCA094 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)dword_CCA090);
}

