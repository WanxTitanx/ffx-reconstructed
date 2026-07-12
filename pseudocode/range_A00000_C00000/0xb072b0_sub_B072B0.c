// Function: sub_B072B0
// Address: 0xb072b0
// Size: 0x35
// Prototype: void __cdecl()

void __cdecl sub_B072B0()
{
  if ( dword_CDEC78 >= 0 && dword_CDEC7C )
    Phyre_Memory_AlignedFree(dword_CDEC7C);
  dword_CDEC7C = 0;
  dword_CDEC78 = 0;
}

