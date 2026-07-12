// Function: sub_A28330
// Address: 0xa28330
// Size: 0x1e
// Prototype: int __stdcall(float)

BOOL __thiscall sub_A28330(_DWORD *this, float a2)
{
  return FMOD::Channel::setVolume(*(this + 168), LODWORD(a2)) == 0;
}

