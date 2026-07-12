// Function: sub_B08E40
// Address: 0xb08e40
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B08E40()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_1944F70;
  v1 = (_DWORD *)unk_1944F74;
  *(_DWORD *)(dword_1944F70 + 4) = unk_1944F74;
  *v1 = v0;
  dword_1944F70 = &dword_1944F70;
  unk_1944F74 = &dword_1944F70;
  if ( (unk_1944F80 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_1944F7C);
}

