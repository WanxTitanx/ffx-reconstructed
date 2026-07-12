// Function: sub_B06530
// Address: 0xb06530
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B06530()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC9FE4;
  v1 = (_DWORD *)unk_CC9FE8;
  *(_DWORD *)(dword_CC9FE4 + 4) = unk_CC9FE8;
  *v1 = v0;
  dword_CC9FE4 = &dword_CC9FE4;
  unk_CC9FE8 = &dword_CC9FE4;
  if ( (unk_CC9FF4 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)dword_CC9FF0);
}

