// Function: sub_AFAC10
// Address: 0xafac10
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFAC10()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C92890;
  v1 = (_DWORD *)unk_C92894;
  *(_DWORD *)(dword_C92890 + 4) = unk_C92894;
  *v1 = v0;
  dword_C92890 = &dword_C92890;
  unk_C92894 = &dword_C92890;
  if ( (unk_C928A0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C9289C);
}

