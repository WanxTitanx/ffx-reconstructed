// Function: sub_B02430
// Address: 0xb02430
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02430()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB0100;
  v1 = (_DWORD *)unk_CB0104;
  *(_DWORD *)(dword_CB0100 + 4) = unk_CB0104;
  *v1 = v0;
  dword_CB0100 = &dword_CB0100;
  unk_CB0104 = &dword_CB0100;
  if ( (unk_CB0110 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB010C);
}

