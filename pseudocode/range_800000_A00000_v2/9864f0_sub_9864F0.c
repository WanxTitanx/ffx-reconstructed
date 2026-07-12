// Function: sub_9864F0
// Address: 0x9864f0
void (__thiscall ****__thiscall sub_9864F0(void (__thiscall ****this)(_DWORD, _DWORD), char a2))(_DWORD, _DWORD)
{
  *this = (void (__thiscall ***)(_DWORD, _DWORD))&btPairCachingGhostObject::`vftable';
  (***(this + 76))(*(this + 76), 0);
  sub_9D4D50(*(this + 76));
  sub_9863A0();
  if ( (a2 & 1) != 0 )
    sub_9D4D50(this);
  return this;
}
