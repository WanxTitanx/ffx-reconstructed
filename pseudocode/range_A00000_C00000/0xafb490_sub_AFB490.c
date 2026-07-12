// Function: sub_AFB490
// Address: 0xafb490
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB490()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C94A84;
  v1 = (_DWORD *)unk_C94A88;
  *(_DWORD *)(dword_C94A84 + 4) = unk_C94A88;
  *v1 = v0;
  dword_C94A84 = &dword_C94A84;
  unk_C94A88 = &dword_C94A84;
  if ( (unk_C94A94 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C94A90);
}

