// Function: sub_AF9C80
// Address: 0xaf9c80
// Size: 0x4b
// Prototype: void __cdecl()

void __cdecl sub_AF9C80()
{
  void ****v0; // eax
  void ***v1; // ecx

  p____7PUtilityGeometry_PGeometry_Phyre__6B_ = &Phyre::PUtility::`vftable';
  v0 = (void ****)dword_C901A8;
  if ( dword_C901A8[0] )
  {
    do
    {
      v1 = *v0;
      if ( *v0 == &p____7PUtilityGeometry_PGeometry_Phyre__6B_ )
        break;
      v0 = (void ****)(v1 + 1);
    }
    while ( v1[1] );
    if ( *v0 )
    {
      *v0 = (void ***)dword_C0A340;
      dword_C0A340 = 0;
    }
  }
}

