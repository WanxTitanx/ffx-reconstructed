// Function: sub_B056D0
// Address: 0xb056d0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B056D0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC04DC;
  v1 = (_DWORD *)unk_CC04E0;
  *(_DWORD *)(dword_CC04DC + 4) = unk_CC04E0;
  *v1 = v0;
  dword_CC04DC = &dword_CC04DC;
  unk_CC04E0 = &dword_CC04DC;
  if ( (unk_CC04EC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CC04E8);
}

