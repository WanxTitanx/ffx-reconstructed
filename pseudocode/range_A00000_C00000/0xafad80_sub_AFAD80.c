// Function: sub_AFAD80
// Address: 0xafad80
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFAD80()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C93BA8;
  v1 = (_DWORD *)unk_C93BAC;
  *(_DWORD *)(dword_C93BA8 + 4) = unk_C93BAC;
  *v1 = v0;
  dword_C93BA8 = &dword_C93BA8;
  unk_C93BAC = &dword_C93BA8;
  if ( (unk_C93BB8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C93BB4);
}

