// Function: sub_970350
// Address: 0x970350
float *__thiscall sub_970350(float *this, int a2, float a3)
{
  sub_96A2F0();
  *(_DWORD *)this = &btCapsuleShape::`vftable';
  *((_DWORD *)this + 1) = 10;
  *((_DWORD *)this + 16) = 1;
  *(this + 9) = a3 * 0.5;
  *((_DWORD *)this + 8) = a2;
  *((_QWORD *)this + 5) = (unsigned int)a2;
  return this;
}
