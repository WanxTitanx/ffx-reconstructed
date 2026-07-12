// Function: sub_98E1E0
// Address: 0x98e1e0
int __thiscall sub_98E1E0(int this, int a2, int a3)
{
  unsigned __int16 *v3; // edx
  double v4; // st7
  double v5; // st7
  _DWORD *v7; // edx
  int v8; // [esp+14h] [ebp+Ch]
  float v9; // [esp+14h] [ebp+Ch]
  int v10; // [esp+14h] [ebp+Ch]
  float v11; // [esp+14h] [ebp+Ch]
  int v12; // [esp+14h] [ebp+Ch]
  float v13; // [esp+14h] [ebp+Ch]

  if ( *(_BYTE *)(this + 72) )
  {
    v3 = (unsigned __int16 *)(*(_DWORD *)(this + 128) + 16 * a3);
    v8 = *v3;
    *(_DWORD *)(a2 + 12) = 0;
    v9 = (double)v8 / *(float *)(this + 48);
    v4 = v9 + *(float *)(this + 16);
    v10 = v3[1];
    *(float *)a2 = v4;
    v11 = (double)v10 / *(float *)(this + 52);
    v5 = v11 + *(float *)(this + 20);
    v12 = v3[2];
    *(float *)(a2 + 4) = v5;
    v13 = (double)v12 / *(float *)(this + 56);
    *(float *)(a2 + 8) = v13 + *(float *)(this + 24);
    return a2;
  }
  else
  {
    v7 = (_DWORD *)((a3 << 6) + *(_DWORD *)(this + 88));
    *(_DWORD *)a2 = *v7;
    *(_DWORD *)(a2 + 4) = v7[1];
    *(_DWORD *)(a2 + 8) = v7[2];
    *(_DWORD *)(a2 + 12) = v7[3];
    return a2;
  }
}
