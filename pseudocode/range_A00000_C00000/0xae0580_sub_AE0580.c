// Function: sub_AE0580
// Address: 0xae0580
// Size: 0x48
// Prototype: 

int sub_AE0580()
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
  dword_C0A340 = *v0;
  *v0 = &p____7PUtilityGeometry_PGeometry_Phyre__6B_;
  p____7PUtilityGeometry_PGeometry_Phyre__6B_ = &Phyre::PGeometry::PUtilityGeometry::`vftable';
  return atexit(sub_AF9C80);
}

