// Function: sub_9B69A0
// Address: 0x9b69a0
_DWORD *__thiscall sub_9B69A0(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax

  sub_97BAC0(a2, a3, a5);
  *(this + 23) = 0;
  *(this + 24) = 0;
  *(this + 25) = 0;
  sub_9B6920(this + 26);
  *this = &btDiscreteDynamicsWorld::`vftable';
  *(this + 44) = a4;
  *((_BYTE *)this + 200) = 1;
  *(this + 49) = 0;
  *(this + 47) = 0;
  *(this + 48) = 0;
  *((_BYTE *)this + 220) = 1;
  *(this + 54) = 0;
  *(this + 52) = 0;
  *(this + 53) = 0;
  *(this + 56) = 0;
  *(this + 57) = -1054867456;
  *(this + 58) = 0;
  *(this + 59) = 0;
  *(this + 60) = 0;
  *((_BYTE *)this + 246) = 0;
  *((_BYTE *)this + 264) = 1;
  *(this + 65) = 0;
  *(this + 63) = 0;
  *(this + 64) = 0;
  *(this + 67) = 0;
  if ( a4 )
  {
    *((_BYTE *)this + 245) = 0;
  }
  else
  {
    v6 = sub_9D4CE0(128, 16);
    if ( v6 )
      v7 = sub_9BCB40(v6);
    else
      v7 = 0;
    *(this + 44) = v7;
    *((_BYTE *)this + 245) = 1;
  }
  v8 = sub_9D4CE0(68, 16);
  if ( v8 )
    v9 = sub_A8DA40(v8);
  else
    v9 = 0;
  *(this + 45) = v9;
  *((_BYTE *)this + 244) = 1;
  return this;
}
