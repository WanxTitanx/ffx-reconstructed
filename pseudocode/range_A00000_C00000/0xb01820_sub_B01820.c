// Function: sub_B01820
// Address: 0xb01820
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01820()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CADCC8;
  v1 = (_DWORD *)unk_CADCCC;
  *(_DWORD *)(dword_CADCC8 + 4) = unk_CADCCC;
  *v1 = v0;
  dword_CADCC8 = &dword_CADCC8;
  unk_CADCCC = &dword_CADCC8;
  if ( (unk_CADCD8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CADCD4);
}

