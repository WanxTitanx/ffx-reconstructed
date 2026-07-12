// Function: sub_AF9D20
// Address: 0xaf9d20
// Size: 0x4b
// Prototype: void __cdecl()

void __cdecl sub_AF9D20()
{
  void ****v0; // eax
  void ***v1; // ecx

  p____7PUtilityScene_PScene_Phyre__6B_ = &Phyre::PUtility::`vftable';
  v0 = (void ****)dword_C901A8;
  if ( dword_C901A8[0] )
  {
    do
    {
      v1 = *v0;
      if ( *v0 == &p____7PUtilityScene_PScene_Phyre__6B_ )
        break;
      v0 = (void ****)(v1 + 1);
    }
    while ( v1[1] );
    if ( *v0 )
    {
      *v0 = (void ***)dword_C0A3C4;
      dword_C0A3C4 = 0;
    }
  }
}

