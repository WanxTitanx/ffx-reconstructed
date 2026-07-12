// Function: sub_B06330
// Address: 0xb06330
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B06330()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CCA034;
  v1 = (_DWORD *)unk_CCA038;
  *(_DWORD *)(dword_CCA034 + 4) = unk_CCA038;
  *v1 = v0;
  dword_CCA034 = &dword_CCA034;
  unk_CCA038 = &dword_CCA034;
  if ( (unk_CCA044 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)dword_CCA040);
}

