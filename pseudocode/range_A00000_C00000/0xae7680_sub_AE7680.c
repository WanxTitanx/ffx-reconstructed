// Function: sub_AE7680
// Address: 0xae7680
// Size: 0x48
// Prototype: 

int sub_AE7680()
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
  dword_C1A354 = *v0;
  *v0 = &p____7PUtilityLOD_PLOD_Phyre__6B_;
  p____7PUtilityLOD_PLOD_Phyre__6B_ = &Phyre::PLOD::PUtilityLOD::`vftable';
  return atexit(sub_AFFB30);
}

