// Function: sub_9862D0
// Address: 0x9862d0
_BYTE *__thiscall sub_9862D0(_BYTE *this)
{
  sub_979F40();
  *(this + 288) = 1;
  *((_DWORD *)this + 71) = 0;
  *((_DWORD *)this + 69) = 0;
  *((_DWORD *)this + 70) = 0;
  *((_DWORD *)this + 61) = 4;
  *(_DWORD *)this = &btPairCachingGhostObject::`vftable';
  if ( sub_9D4CE0(76, 16) )
    *((_DWORD *)this + 76) = sub_9A01E0();
  else
    *((_DWORD *)this + 76) = 0;
  return this;
}
