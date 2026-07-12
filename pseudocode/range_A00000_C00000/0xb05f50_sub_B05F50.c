// Function: sub_B05F50
// Address: 0xb05f50
// Size: 0x35
// Prototype: void __cdecl()

void __cdecl sub_B05F50()
{
  if ( dword_CC96E0 >= 0 && dword_CC96E4[0] )
    Phyre_Memory_AlignedFree(dword_CC96E4[0]);
  dword_CC96E4[0] = 0;
  dword_CC96E0 = 0;
}

