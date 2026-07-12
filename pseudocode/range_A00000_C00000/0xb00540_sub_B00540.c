// Function: sub_B00540
// Address: 0xb00540
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B00540()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAA970;
  v1 = (_DWORD *)unk_CAA974;
  *(_DWORD *)(dword_CAA970 + 4) = unk_CAA974;
  *v1 = v0;
  dword_CAA970 = &dword_CAA970;
  unk_CAA974 = &dword_CAA970;
  if ( (unk_CAA980 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAA97C);
}

