// Function: sub_AFB4D0
// Address: 0xafb4d0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB4D0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C94544;
  v1 = (_DWORD *)unk_C94548;
  *(_DWORD *)(dword_C94544 + 4) = unk_C94548;
  *v1 = v0;
  dword_C94544 = &dword_C94544;
  unk_C94548 = &dword_C94544;
  if ( (unk_C94554 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C94550);
}

