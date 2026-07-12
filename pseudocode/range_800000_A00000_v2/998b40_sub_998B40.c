// Function: sub_998B40
// Address: 0x998b40
_DWORD *__thiscall sub_998B40(float *this, _DWORD *a2, float *a3)
{
  int n2; // edx
  float *v5; // edx
  float v6; // [esp-20h] [ebp-2Ch]
  float v7; // [esp-1Ch] [ebp-28h]
  float v8; // [esp-18h] [ebp-24h]
  float v9; // [esp-Ch] [ebp-18h]
  float v10; // [esp-4h] [ebp-10h]

  v10 = a3[1];
  v9 = a3[2];
  v6 = *(this + 18) * v9 + *(this + 16) * *a3 + *(this + 17) * v10;
  v7 = *(this + 21) * v10 + *a3 * *(this + 20) + *(this + 22) * v9;
  v8 = *a3 * *(this + 24) + v10 * *(this + 25) + v9 * *(this + 26);
  if ( v7 <= (double)v6 )
  {
    if ( v8 <= (double)v6 )
    {
      n2 = 0;
      goto LABEL_7;
    }
    goto LABEL_5;
  }
  if ( v8 > (double)v7 )
  {
LABEL_5:
    n2 = 2;
    goto LABEL_7;
  }
  n2 = 1;
LABEL_7:
  v5 = this + 4 * n2 + 16;
  *a2 = *(_DWORD *)v5;
  a2[1] = *((_DWORD *)v5 + 1);
  a2[2] = *((_DWORD *)v5 + 2);
  a2[3] = *((_DWORD *)v5 + 3);
  return a2;
}
