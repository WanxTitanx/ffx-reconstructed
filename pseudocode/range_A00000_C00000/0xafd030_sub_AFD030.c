// Function: sub_AFD030
// Address: 0xafd030
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFD030()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C9B2A8;
  v1 = (_DWORD *)unk_C9B2AC;
  *(_DWORD *)(dword_C9B2A8 + 4) = unk_C9B2AC;
  *v1 = v0;
  dword_C9B2A8 = &dword_C9B2A8;
  unk_C9B2AC = &dword_C9B2A8;
  if ( (unk_C9B2B8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C9B2B4);
}

