// Function: sub_9C2E80
// Address: 0x9c2e80
_BYTE *__thiscall sub_9C2E80(_BYTE *this, int a2, int a3, int a4, int a5)
{
  float v6; // [esp+14h] [ebp+14h]

  *(_DWORD *)this = &btKinematicCharacterController::`vftable';
  *(this + 160) = 1;
  *((_DWORD *)this + 39) = 0;
  *((_DWORD *)this + 37) = 0;
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 50) = a5;
  *((_DWORD *)this + 14) = 1017370378;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 2) = a2;
  *((_DWORD *)this + 48) = &unk_1010000;
  *((_DWORD *)this + 13) = a4;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 3) = a3;
  *((_DWORD *)this + 49) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 11) = 1105933107;
  *((_DWORD *)this + 6) = 1113325568;
  *((_DWORD *)this + 7) = 1092616192;
  *((_DWORD *)this + 9) = 1061752795;
  v6 = cos(0.7853981852531433);
  *((float *)this + 10) = v6;
  return this;
}
