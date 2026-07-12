// Function: sub_AFAE00
// Address: 0xafae00
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFAE00()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C93BF8;
  v1 = (_DWORD *)unk_C93BFC;
  *(_DWORD *)(dword_C93BF8 + 4) = unk_C93BFC;
  *v1 = v0;
  dword_C93BF8 = &dword_C93BF8;
  unk_C93BFC = &dword_C93BF8;
  if ( (unk_C93C08 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C93C04);
}

