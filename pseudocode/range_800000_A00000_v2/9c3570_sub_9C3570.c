// Function: sub_9C3570
// Address: 0x9c3570
int __thiscall sub_9C3570(float *this)
{
  int result; // eax
  double v3; // st7

  result = (*(int (__thiscall **)(float *))(*(_DWORD *)this + 36))(this);
  if ( (_BYTE)result )
  {
    v3 = *(this + 7);
    *((_BYTE *)this + 193) = 1;
    *(this + 4) = v3;
  }
  return result;
}
