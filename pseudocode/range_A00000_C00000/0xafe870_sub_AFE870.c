// Function: sub_AFE870
// Address: 0xafe870
// Size: 0x35
// Prototype: void __cdecl()

void __cdecl sub_AFE870()
{
  if ( dword_CA4EBC >= 0 && dword_CA4EC0 )
    Phyre_Memory_AlignedFree(dword_CA4EC0);
  dword_CA4EC0 = 0;
  dword_CA4EBC = 0;
}

