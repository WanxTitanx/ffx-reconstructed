// Function: sub_B00820
// Address: 0xb00820
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B00820()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAA87C;
  v1 = (_DWORD *)unk_CAA880;
  *(_DWORD *)(dword_CAA87C + 4) = unk_CAA880;
  *v1 = v0;
  dword_CAA87C = &dword_CAA87C;
  unk_CAA880 = &dword_CAA87C;
  if ( (unk_CAA88C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAA888);
}

