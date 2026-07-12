// Function: sub_AFA600
// Address: 0xafa600
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA600()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C91CAC;
  v1 = (_DWORD *)unk_C91CB0;
  *(_DWORD *)(dword_C91CAC + 4) = unk_C91CB0;
  *v1 = v0;
  dword_C91CAC = &dword_C91CAC;
  unk_C91CB0 = &dword_C91CAC;
  if ( (unk_C91CBC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C91CB8);
}

