// Function: sub_B01390
// Address: 0xb01390
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01390()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADED0;
  v1 = (_DWORD *)unk_CADED4;
  *(_DWORD *)(dword_CADED0 + 4) = unk_CADED4;
  *v1 = v0;
  dword_CADED0 = &dword_CADED0;
  unk_CADED4 = &dword_CADED0;
  if ( (unk_CADEE0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADEDC);
}

