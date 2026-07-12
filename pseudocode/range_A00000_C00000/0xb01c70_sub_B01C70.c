// Function: sub_B01C70
// Address: 0xb01c70
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01C70()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAEA04;
  v1 = (_DWORD *)unk_CAEA08;
  *(_DWORD *)(dword_CAEA04 + 4) = unk_CAEA08;
  *v1 = v0;
  dword_CAEA04 = &dword_CAEA04;
  unk_CAEA08 = &dword_CAEA04;
  if ( (unk_CAEA14 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAEA10);
}

