// Function: sub_990100
// Address: 0x990100
__int16 __thiscall sub_990100(int this, int a2, int a3)
{
  int v3; // edx
  int v4; // esi
  int v5; // eax
  int v6; // edx
  int v7; // esi
  float v9; // [esp-30h] [ebp-3Ch]
  float v10; // [esp-2Ch] [ebp-38h]
  float v11; // [esp-28h] [ebp-34h]
  float v12; // [esp-20h] [ebp-2Ch]
  float v13; // [esp-1Ch] [ebp-28h]
  float v14; // [esp-18h] [ebp-24h]

  if ( *(_BYTE *)(this + 72) )
  {
    v3 = *(_DWORD *)(this + 148);
    v4 = 2 * a2;
    v12 = *(float *)a3 - *(float *)(this + 16);
    v13 = *(float *)(a3 + 4) - *(float *)(this + 20);
    v14 = *(float *)(a3 + 8) - *(float *)(this + 24);
    v9 = *(float *)(this + 48) * v12;
    v10 = *(float *)(this + 52) * v13;
    v11 = *(float *)(this + 56) * v14;
    *(_WORD *)(v3 + 8 * v4 + 6) = (int)(v9 + 1.0) | 1;
    *(_WORD *)(v3 + 8 * v4 + 8) = (int)(v10 + 1.0) | 1;
    LOWORD(v5) = (int)(v11 + 1.0) | 1;
    *(_WORD *)(v3 + 8 * v4 + 10) = v5;
  }
  else
  {
    v6 = *(_DWORD *)(this + 108);
    v7 = a2 << 6;
    *(_DWORD *)(v6 + v7 + 16) = *(_DWORD *)a3;
    *(_DWORD *)(v6 + v7 + 20) = *(_DWORD *)(a3 + 4);
    *(_DWORD *)(v6 + v7 + 24) = *(_DWORD *)(a3 + 8);
    v5 = *(_DWORD *)(a3 + 12);
    *(_DWORD *)(v6 + v7 + 28) = v5;
  }
  return v5;
}
