// Function: sub_B08DC0
// Address: 0xb08dc0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B08DC0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_1944FC0;
  v1 = (_DWORD *)unk_1944FC4;
  *(_DWORD *)(dword_1944FC0 + 4) = unk_1944FC4;
  *v1 = v0;
  dword_1944FC0 = &dword_1944FC0;
  unk_1944FC4 = &dword_1944FC0;
  if ( (unk_1944FD0 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_1944FCC);
}

