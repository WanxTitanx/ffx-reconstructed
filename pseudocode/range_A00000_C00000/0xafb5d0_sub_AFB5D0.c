// Function: sub_AFB5D0
// Address: 0xafb5d0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB5D0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C94AAC;
  v1 = (_DWORD *)unk_C94AB0;
  *(_DWORD *)(dword_C94AAC + 4) = unk_C94AB0;
  *v1 = v0;
  dword_C94AAC = &dword_C94AAC;
  unk_C94AB0 = &dword_C94AAC;
  if ( (unk_C94ABC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C94AB8);
}

