// Function: sub_AEC9C0
// Address: 0xaec9c0
// Size: 0x48
// Prototype: 

int sub_AEC9C0()
{
  _DWORD *v0; // eax
  int v1; // ecx

  v0 = dword_C901A8;
  if ( dword_C901A8[0] )
  {
    do
    {
      v1 = *v0;
      if ( *(_DWORD *)(*v0 + 12) >= 0xFFu )
        break;
      v0 = (_DWORD *)(v1 + 4);
    }
    while ( *(_DWORD *)(v1 + 4) );
  }
  dword_C2A058 = *v0;
  *v0 = &p____7PUtilityScripting_PScripting_Phyre__6B_;
  p____7PUtilityScripting_PScripting_Phyre__6B_ = &Phyre::PScripting::PUtilityScripting::`vftable';
  return atexit(sub_B04B80);
}

