// Function: sub_B023F0
// Address: 0xb023f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B023F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB00B0;
  v1 = (_DWORD *)unk_CB00B4;
  *(_DWORD *)(dword_CB00B0 + 4) = unk_CB00B4;
  *v1 = v0;
  dword_CB00B0 = &dword_CB00B0;
  unk_CB00B4 = &dword_CB00B0;
  if ( (unk_CB00C0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB00BC);
}

