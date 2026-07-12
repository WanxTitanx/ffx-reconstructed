// Function: sub_AF9BD0
// Address: 0xaf9bd0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AF9BD0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C9024C;
  v1 = (_DWORD *)unk_C90250;
  *(_DWORD *)(dword_C9024C + 4) = unk_C90250;
  *v1 = v0;
  dword_C9024C = &dword_C9024C;
  unk_C90250 = &dword_C9024C;
  if ( (unk_C9025C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C90258);
}

