// Function: sub_9B1390
// Address: 0x9b1390
char __thiscall sub_9B1390(_DWORD *this, int a2, float *a3, int a4, int a5, int *a6)
{
  double v9; // st7
  int v10; // eax
  double v11; // st6
  int v12; // eax
  int v13; // edx
  int v15; // eax
  int v16; // [esp+1Ch] [ebp+10h]
  float v17; // [esp+20h] [ebp+14h]
  int v18; // [esp+20h] [ebp+14h]

  if ( *(unsigned __int8 *)(a4 + 59) == a2 )
    return 0;
  v9 = a3[5] * *(float *)(a4 + 4);
  v10 = dword_B6FEB4[a5];
  v11 = *(float *)a4;
  v16 = v10;
  v17 = v9 + v11 * a3[4] + a3[6] * *(float *)(a4 + 8);
  if ( v17 - *(float *)(a4 + 16) >= -0.000009999999747378752 )
  {
    v15 = dword_B6FEC0[a5];
    *(_BYTE *)(a4 + 59) = a2;
    v18 = v15;
    if ( (unsigned __int8)sub_9B1390(a2, a3, *(_DWORD *)(a4 + 4 * v16 + 36), *(unsigned __int8 *)(v16 + a4 + 56), a6)
      && (unsigned __int8)sub_9B1390(a2, a3, *(_DWORD *)(a4 + 4 * v18 + 36), *(unsigned __int8 *)(v18 + a4 + 56), a6) )
    {
      sub_9B2730(this + 2581, a4);
      sub_9B11A0(this + 2583, a4);
      return 1;
    }
    return 0;
  }
  v12 = sub_9B1680(*(_DWORD *)(a4 + 4 * v10 + 24), *(_DWORD *)(a4 + 4 * a5 + 24), a3, 0);
  if ( !v12 )
    return 0;
  *(_BYTE *)(v12 + 56) = a5;
  *(_DWORD *)(v12 + 36) = a4;
  *(_BYTE *)(a4 + a5 + 56) = 0;
  *(_DWORD *)(a4 + 4 * a5 + 36) = v12;
  v13 = *a6;
  if ( *a6 )
  {
    *(_DWORD *)(v13 + 40) = v12;
    *(_BYTE *)(v13 + 57) = 2;
    *(_BYTE *)(v12 + 58) = 1;
    *(_DWORD *)(v12 + 44) = v13;
    ++a6[2];
  }
  else
  {
    ++a6[2];
    a6[1] = v12;
  }
  *a6 = v12;
  return 1;
}
