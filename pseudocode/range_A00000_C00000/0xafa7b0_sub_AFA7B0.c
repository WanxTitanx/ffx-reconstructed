// Function: sub_AFA7B0
// Address: 0xafa7b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA7B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C91E6C;
  v1 = (_DWORD *)unk_C91E70;
  *(_DWORD *)(dword_C91E6C + 4) = unk_C91E70;
  *v1 = v0;
  dword_C91E6C = &dword_C91E6C;
  unk_C91E70 = &dword_C91E6C;
  if ( (unk_C91E7C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C91E78);
}

