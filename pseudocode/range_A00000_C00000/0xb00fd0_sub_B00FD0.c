// Function: sub_B00FD0
// Address: 0xb00fd0
// Size: 0x35
// Prototype: void __cdecl()

void __cdecl sub_B00FD0()
{
  if ( dword_CACEDC >= 0 && dword_CACEE0 )
    Phyre_Memory_AlignedFree(dword_CACEE0);
  dword_CACEE0 = 0;
  dword_CACEDC = 0;
}

