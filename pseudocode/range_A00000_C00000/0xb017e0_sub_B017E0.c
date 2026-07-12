// Function: sub_B017E0
// Address: 0xb017e0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B017E0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADEA8;
  v1 = (_DWORD *)unk_CADEAC;
  *(_DWORD *)(dword_CADEA8 + 4) = unk_CADEAC;
  *v1 = v0;
  dword_CADEA8 = &dword_CADEA8;
  unk_CADEAC = &dword_CADEA8;
  if ( (unk_CADEB8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADEB4);
}

