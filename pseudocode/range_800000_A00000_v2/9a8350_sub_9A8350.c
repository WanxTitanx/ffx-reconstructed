// Function: sub_9A8350
// Address: 0x9a8350
float *__thiscall sub_9A8350(
        float *this,
        float *a2,
        float *a3,
        int a4,
        struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList)
{
  *(_DWORD *)this = &btGjkPairDetector::`vftable';
  *(this + 4) = 0.0;
  *(this + 5) = 1.0;
  *(this + 6) = 0.0;
  *(this + 7) = 0.0;
  *((_DWORD *)this + 8) = ExceptionList;
  *((_DWORD *)this + 9) = a4;
  *((_DWORD *)this + 10) = a2;
  *((_DWORD *)this + 11) = a3;
  *(this + 12) = a2[1];
  *(this + 13) = a3[1];
  *(this + 14) = ((double (__thiscall *)(float *))*(_DWORD *)(*(_DWORD *)a2 + 40))(a2);
  *(this + 15) = ((double (__thiscall *)(float *))*(_DWORD *)(*(_DWORD *)a3 + 40))(a3);
  *((_BYTE *)this + 64) = 0;
  *(this + 18) = NAN;
  *((_DWORD *)this + 21) = 1;
  return this;
}
