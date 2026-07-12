// Function: sub_AFC860
// Address: 0xafc860
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFC860()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C999DC;
  v1 = (_DWORD *)unk_C999E0;
  *(_DWORD *)(dword_C999DC + 4) = unk_C999E0;
  *v1 = v0;
  dword_C999DC = &dword_C999DC;
  unk_C999E0 = &dword_C999DC;
  if ( (unk_C999EC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C999E8);
}

