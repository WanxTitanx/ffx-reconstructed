// Function: sub_AF9890
// Address: 0xaf9890
// Size: 0x48
// Prototype: 

int sub_AF9890()
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
  dword_C85B38 = *v0;
  *v0 = &p____7PUtilityIggy_PIggy_Phyre__6B_;
  p____7PUtilityIggy_PIggy_Phyre__6B_ = &Phyre::PIggy::PUtilityIggy::`vftable';
  return atexit(sub_B0B8D0);
}

