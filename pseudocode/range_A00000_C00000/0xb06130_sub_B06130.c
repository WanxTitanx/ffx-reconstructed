// Function: sub_B06130
// Address: 0xb06130
// Size: 0x35
// Prototype: void __cdecl()

void __cdecl sub_B06130()
{
  if ( dword_CC9D14 >= 0 && dword_CC9D18 )
    Phyre_Memory_AlignedFree(dword_CC9D18);
  dword_CC9D18 = 0;
  dword_CC9D14 = 0;
}

