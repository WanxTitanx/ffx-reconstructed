// Function: sub_B00640
// Address: 0xb00640
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B00640()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAA948;
  v1 = (_DWORD *)unk_CAA94C;
  *(_DWORD *)(dword_CAA948 + 4) = unk_CAA94C;
  *v1 = v0;
  dword_CAA948 = &dword_CAA948;
  unk_CAA94C = &dword_CAA948;
  if ( (unk_CAA958 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAA954);
}

