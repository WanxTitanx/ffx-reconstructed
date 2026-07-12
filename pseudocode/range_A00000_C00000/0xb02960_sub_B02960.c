// Function: sub_B02960
// Address: 0xb02960
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02960()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CB0D54;
  v1 = (_DWORD *)unk_CB0D58;
  *(_DWORD *)(dword_CB0D54 + 4) = unk_CB0D58;
  *v1 = v0;
  dword_CB0D54 = &dword_CB0D54;
  unk_CB0D58 = &dword_CB0D54;
  if ( (unk_CB0D64 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CB0D60);
}

