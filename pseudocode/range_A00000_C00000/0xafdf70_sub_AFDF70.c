// Function: sub_AFDF70
// Address: 0xafdf70
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFDF70()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA2CAC;
  v1 = (_DWORD *)unk_CA2CB0;
  *(_DWORD *)(dword_CA2CAC + 4) = unk_CA2CB0;
  *v1 = v0;
  dword_CA2CAC = &dword_CA2CAC;
  unk_CA2CB0 = &dword_CA2CAC;
  if ( (unk_CA2CBC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA2CB8);
}

