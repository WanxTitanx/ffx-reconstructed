// Function: sub_AF12C0
// Address: 0xaf12c0
// Size: 0x48
// Prototype: 

int sub_AF12C0()
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
  dword_C613F4 = *v0;
  *v0 = &p____7PUtilityDeveloperExtensions_PDeveloperExtensions_Phyre__6;
  p____7PUtilityDeveloperExtensions_PDeveloperExtensions_Phyre__6 = &Phyre::PDeveloperExtensions::PUtilityDeveloperExtensions::`vftable';
  return atexit(sub_B07D50);
}

