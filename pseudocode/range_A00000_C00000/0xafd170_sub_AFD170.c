// Function: sub_AFD170
// Address: 0xafd170
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFD170()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C9B280;
  v1 = (_DWORD *)unk_C9B284;
  *(_DWORD *)(dword_C9B280 + 4) = unk_C9B284;
  *v1 = v0;
  dword_C9B280 = &dword_C9B280;
  unk_C9B284 = &dword_C9B280;
  if ( (unk_C9B290 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C9B28C);
}

