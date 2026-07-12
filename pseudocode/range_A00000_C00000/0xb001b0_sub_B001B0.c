// Function: sub_B001B0
// Address: 0xb001b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B001B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CA9CE8;
  v1 = (_DWORD *)unk_CA9CEC;
  *(_DWORD *)(dword_CA9CE8 + 4) = unk_CA9CEC;
  *v1 = v0;
  dword_CA9CE8 = &dword_CA9CE8;
  unk_CA9CEC = &dword_CA9CE8;
  if ( (unk_CA9CF8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CA9CF4);
}

