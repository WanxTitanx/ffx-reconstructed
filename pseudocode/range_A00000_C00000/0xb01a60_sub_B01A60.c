// Function: sub_B01A60
// Address: 0xb01a60
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01A60()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAE6CC;
  v1 = (_DWORD *)unk_CAE6D0;
  *(_DWORD *)(dword_CAE6CC + 4) = unk_CAE6D0;
  *v1 = v0;
  dword_CAE6CC = &dword_CAE6CC;
  unk_CAE6D0 = &dword_CAE6CC;
  if ( (unk_CAE6DC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAE6D8);
}

