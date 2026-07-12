// Function: sub_B04B80
// Address: 0xb04b80
// Size: 0x4b
// Prototype: void __cdecl()

void __cdecl sub_B04B80()
{
  void ****v0; // eax
  void ***v1; // ecx

  p____7PUtilityScripting_PScripting_Phyre__6B_ = &Phyre::PUtility::`vftable';
  v0 = (void ****)dword_C901A8;
  if ( dword_C901A8[0] )
  {
    do
    {
      v1 = *v0;
      if ( *v0 == &p____7PUtilityScripting_PScripting_Phyre__6B_ )
        break;
      v0 = (void ****)(v1 + 1);
    }
    while ( v1[1] );
    if ( *v0 )
    {
      *v0 = (void ***)dword_C2A058;
      dword_C2A058 = 0;
    }
  }
}

