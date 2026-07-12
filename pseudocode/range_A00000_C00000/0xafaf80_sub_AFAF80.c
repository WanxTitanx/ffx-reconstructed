// Function: sub_AFAF80
// Address: 0xafaf80
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFAF80()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C941A0;
  v1 = (_DWORD *)unk_C941A4;
  *(_DWORD *)(dword_C941A0 + 4) = unk_C941A4;
  *v1 = v0;
  dword_C941A0 = &dword_C941A0;
  unk_C941A4 = &dword_C941A0;
  if ( (unk_C941B0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C941AC);
}

