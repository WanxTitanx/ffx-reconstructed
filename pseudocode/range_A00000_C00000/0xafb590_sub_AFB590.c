// Function: sub_AFB590
// Address: 0xafb590
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB590()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C947E4;
  v1 = (_DWORD *)unk_C947E8;
  *(_DWORD *)(dword_C947E4 + 4) = unk_C947E8;
  *v1 = v0;
  dword_C947E4 = &dword_C947E4;
  unk_C947E8 = &dword_C947E4;
  if ( (unk_C947F4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C947F0);
}

