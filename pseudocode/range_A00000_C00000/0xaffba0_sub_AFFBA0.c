// Function: sub_AFFBA0
// Address: 0xaffba0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFFBA0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA93F8;
  v1 = (_DWORD *)unk_CA93FC;
  *(_DWORD *)(dword_CA93F8 + 4) = unk_CA93FC;
  *v1 = v0;
  dword_CA93F8 = &dword_CA93F8;
  unk_CA93FC = &dword_CA93F8;
  if ( (unk_CA9408 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA9404);
}

