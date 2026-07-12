// Function: sub_AF2BF0
// Address: 0xaf2bf0
// Size: 0x48
// Prototype: 

int sub_AF2BF0()
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
  dword_C68460 = *v0;
  *v0 = &p____7PUtilityGame_PGame_Phyre__6B_;
  p____7PUtilityGame_PGame_Phyre__6B_ = &Phyre::PGame::PUtilityGame::`vftable';
  return atexit(sub_B08650);
}

