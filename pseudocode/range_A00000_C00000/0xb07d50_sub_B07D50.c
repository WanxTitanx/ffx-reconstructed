// Function: sub_B07D50
// Address: 0xb07d50
// Size: 0x4b
// Prototype: void __cdecl()

void __cdecl sub_B07D50()
{
  void ****v0; // eax
  void ***v1; // ecx

  p____7PUtilityDeveloperExtensions_PDeveloperExtensions_Phyre__6 = &Phyre::PUtility::`vftable';
  v0 = (void ****)dword_C901A8;
  if ( dword_C901A8[0] )
  {
    do
    {
      v1 = *v0;
      if ( *v0 == &p____7PUtilityDeveloperExtensions_PDeveloperExtensions_Phyre__6 )
        break;
      v0 = (void ****)(v1 + 1);
    }
    while ( v1[1] );
    if ( *v0 )
    {
      *v0 = (void ***)dword_C613F4;
      dword_C613F4 = 0;
    }
  }
}

