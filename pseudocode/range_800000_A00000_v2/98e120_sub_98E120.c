// Function: sub_98E120
// Address: 0x98e120
int __thiscall sub_98E120(int this, int a2, int a3)
{
  int v3; // edx
  int v4; // esi
  double v5; // st7
  double v6; // st7
  int v8; // edx
  int v9; // [esp+1Ch] [ebp+Ch]
  float v10; // [esp+1Ch] [ebp+Ch]
  int v11; // [esp+1Ch] [ebp+Ch]
  float v12; // [esp+1Ch] [ebp+Ch]
  int v13; // [esp+1Ch] [ebp+Ch]
  float v14; // [esp+1Ch] [ebp+Ch]

  if ( *(_BYTE *)(this + 72) )
  {
    v3 = *(_DWORD *)(this + 128);
    v4 = 2 * a3;
    v9 = *(unsigned __int16 *)(v3 + 16 * a3 + 6);
    *(_DWORD *)(a2 + 12) = 0;
    v10 = (double)v9 / *(float *)(this + 48);
    v5 = v10 + *(float *)(this + 16);
    v11 = *(unsigned __int16 *)(v3 + 8 * v4 + 8);
    *(float *)a2 = v5;
    v12 = (double)v11 / *(float *)(this + 52);
    v6 = v12 + *(float *)(this + 20);
    v13 = *(unsigned __int16 *)(v3 + 8 * v4 + 10);
    *(float *)(a2 + 4) = v6;
    v14 = (double)v13 / *(float *)(this + 56);
    *(float *)(a2 + 8) = v14 + *(float *)(this + 24);
    return a2;
  }
  else
  {
    v8 = *(_DWORD *)(this + 88);
    *(_DWORD *)a2 = *(_DWORD *)(v8 + (a3 << 6) + 16);
    *(_DWORD *)(a2 + 4) = *(_DWORD *)(v8 + (a3 << 6) + 20);
    *(_DWORD *)(a2 + 8) = *(_DWORD *)(v8 + (a3 << 6) + 24);
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(v8 + (a3 << 6) + 28);
    return a2;
  }
}
