// Function: sub_AFACC0
// Address: 0xafacc0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFACC0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C931AC;
  v1 = (_DWORD *)unk_C931B0;
  *(_DWORD *)(dword_C931AC + 4) = unk_C931B0;
  *v1 = v0;
  dword_C931AC = &dword_C931AC;
  unk_C931B0 = &dword_C931AC;
  if ( (unk_C931BC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C931B8);
}

