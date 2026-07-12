// Function: sub_9B2800
// Address: 0x9b2800
int __thiscall sub_9B2800(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  int v5; // ecx
  _DWORD *v6; // ecx
  _DWORD *v7; // edx
  _DWORD *v8; // edx
  int result; // eax

  v5 = *this;
  *(this + 76) = *a2;
  *(this + 77) = a2[1];
  *(this + 78) = a2[2];
  *(this + 79) = a2[3];
  *((_BYTE *)this + 384) = 1;
  v6 = this + 4 * v5 + 4;
  *v6 = *a2;
  v6[1] = a2[1];
  v6[2] = a2[2];
  v6[3] = a2[3];
  v7 = this + 4 * *this + 24;
  *v7 = *a3;
  v7[1] = a3[1];
  v7[2] = a3[2];
  v7[3] = a3[3];
  v8 = this + 4 * *this + 44;
  *v8 = *a4;
  v8[1] = a4[1];
  v8[2] = a4[2];
  result = a4[3];
  v8[3] = result;
  ++*this;
  return result;
}
