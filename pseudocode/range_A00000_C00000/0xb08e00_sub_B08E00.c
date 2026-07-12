// Function: sub_B08E00
// Address: 0xb08e00
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B08E00()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_1944FE8;
  v1 = (_DWORD *)unk_1944FEC;
  *(_DWORD *)(dword_1944FE8 + 4) = unk_1944FEC;
  *v1 = v0;
  dword_1944FE8 = &dword_1944FE8;
  unk_1944FEC = &dword_1944FE8;
  if ( (unk_1944FF8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_1944FF4);
}

