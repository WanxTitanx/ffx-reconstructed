// Function: sub_9B3930
// Address: 0x9b3930
int __thiscall sub_9B3930(_DWORD *this, int n3)
{
  _DWORD *v3; // esi
  _DWORD *v4; // edx
  _DWORD *v5; // edx
  int v6; // ecx
  _DWORD *v7; // ecx
  _DWORD *v8; // edx
  _DWORD *v9; // ecx
  int result; // eax

  v3 = this + 4 * (*this)--;
  v4 = this + 4 * n3 + 4;
  *v4 = *v3;
  v4[1] = v3[1];
  v4[2] = v3[2];
  v4[3] = v3[3];
  v5 = this + 4 * *this + 24;
  v6 = 16 * (n3 + 6);
  *(_DWORD *)((char *)this + v6) = *v5;
  v7 = (_DWORD *)((char *)this + v6);
  v7[1] = v5[1];
  v7[2] = v5[2];
  v7[3] = v5[3];
  v8 = this + 4 * *this + 44;
  v9 = this + 4 * n3 + 44;
  *v9 = *v8;
  v9[1] = v8[1];
  v9[2] = v8[2];
  result = v8[3];
  v9[3] = result;
  return result;
}
