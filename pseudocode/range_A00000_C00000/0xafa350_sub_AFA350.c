// Function: sub_AFA350
// Address: 0xafa350
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA350()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C91124;
  v1 = (_DWORD *)unk_C91128;
  *(_DWORD *)(dword_C91124 + 4) = unk_C91128;
  *v1 = v0;
  dword_C91124 = &dword_C91124;
  unk_C91128 = &dword_C91124;
  if ( (unk_C91134 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C91130);
}

