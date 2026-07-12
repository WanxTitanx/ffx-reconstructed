// Function: sub_B04B40
// Address: 0xb04b40
// Size: 0x35
// Prototype: void __cdecl()

void __cdecl sub_B04B40()
{
  if ( dword_CBE6D8 >= 0 && dword_CBE6DC )
    Phyre_Memory_AlignedFree(dword_CBE6DC);
  dword_CBE6DC = 0;
  dword_CBE6D8 = 0;
}

