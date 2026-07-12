// Function: sub_AEE660
// Address: 0xaee660
// Size: 0x48
// Prototype: 

int sub_AEE660()
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
  dword_C2A0F8 = *v0;
  *v0 = &p____7PUtilityPhysics_PPhysics_Phyre__6B_;
  p____7PUtilityPhysics_PPhysics_Phyre__6B_ = &Phyre::PPhysics::PUtilityPhysics::`vftable';
  return atexit(sub_B05EF0);
}

