// Function: sub_AFA110
// Address: 0xafa110
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA110()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = unk_C90AD8;
  v1 = (_DWORD *)unk_C90ADC;
  *(_DWORD *)(unk_C90AD8 + 4) = unk_C90ADC;
  *v1 = v0;
  unk_C90AD8 = &unk_C90AD8;
  unk_C90ADC = &unk_C90AD8;
  if ( (unk_C90AE8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C90AE4);
}

