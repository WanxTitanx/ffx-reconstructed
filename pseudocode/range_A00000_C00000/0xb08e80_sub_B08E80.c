// Function: sub_B08E80
// Address: 0xb08e80
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B08E80()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_1944F98;
  v1 = (_DWORD *)unk_1944F9C;
  *(_DWORD *)(dword_1944F98 + 4) = unk_1944F9C;
  *v1 = v0;
  dword_1944F98 = &dword_1944F98;
  unk_1944F9C = &dword_1944F98;
  if ( (unk_1944FA8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_1944FA4);
}

