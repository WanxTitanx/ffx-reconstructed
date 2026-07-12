// Function: sub_AFB310
// Address: 0xafb310
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB310()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C94794;
  v1 = (_DWORD *)unk_C94798;
  *(_DWORD *)(dword_C94794 + 4) = unk_C94798;
  *v1 = v0;
  dword_C94794 = &dword_C94794;
  unk_C94798 = &dword_C94794;
  if ( (unk_C947A4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C947A0);
}

