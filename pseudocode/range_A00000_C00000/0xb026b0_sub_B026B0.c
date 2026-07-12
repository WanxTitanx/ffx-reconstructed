// Function: sub_B026B0
// Address: 0xb026b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B026B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB0DCC;
  v1 = (_DWORD *)unk_CB0DD0;
  *(_DWORD *)(dword_CB0DCC + 4) = unk_CB0DD0;
  *v1 = v0;
  dword_CB0DCC = &dword_CB0DCC;
  unk_CB0DD0 = &dword_CB0DCC;
  if ( (unk_CB0DDC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB0DD8);
}

