// Function: sub_B0B990
// Address: 0xb0b990
// Size: 0x4b
// Prototype: void __cdecl()

void __cdecl sub_B0B990()
{
  _DWORD *v0; // eax
  _DWORD *v1; // ecx

  p____7PUtility_Phyre__6B_ = &Phyre::PUtility::`vftable';
  v0 = dword_C901A8;
  if ( dword_C901A8[0] )
  {
    do
    {
      v1 = (_DWORD *)*v0;
      if ( (_DWORD *)*v0 == &p____7PUtility_Phyre__6B_ )
        break;
      v0 = v1 + 1;
    }
    while ( v1[1] );
    if ( *v0 )
    {
      *v0 = unk_1A85914;
      unk_1A85914 = 0;
    }
  }
}

