// Function: sub_A278F0
// Address: 0xa278f0
// Size: 0xb2
// Prototype: 

int __thiscall sub_A278F0(_DWORD *this)
{
  int v3; // [esp+Ch] [ebp-4h] BYREF

  sub_A3DEA0(this + 32);
  FMOD::Channel::stop(*(this + 168));
  while ( 1 )
  {
    while ( FMOD::Sound::getOpenState(*(this + 167), &v3, 0, 0, 0) )
      ;
    if ( !v3 )
      break;
    Sleep(1u);
  }
  FMOD::Sound::release(*(this + 167));
  *(this + 167) = 0;
  *(this + 168) = 0;
  sub_A92040(this + 136);
  sub_A917A0(this + 108);
  sub_A90030(this + 104);
  sub_A8FD80(this + 96);
  sub_A3DF20(this + 32);
  return sub_42E200();
}

