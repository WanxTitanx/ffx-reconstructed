// Function: sub_990220
// Address: 0x990220
__int16 __thiscall sub_990220(int this, int a2, int a3)
{
  _WORD *v3; // edx
  double v4; // st7
  int v5; // eax
  _DWORD *v6; // edx
  float v8; // [esp-20h] [ebp-2Ch]
  float v9; // [esp-1Ch] [ebp-28h]
  float v10; // [esp-18h] [ebp-24h]
  float v11; // [esp-10h] [ebp-1Ch]
  float v12; // [esp-Ch] [ebp-18h]
  float v13; // [esp-8h] [ebp-14h]

  if ( *(_BYTE *)(this + 72) )
  {
    v3 = (_WORD *)(*(_DWORD *)(this + 148) + 16 * a2);
    v11 = *(float *)a3 - *(float *)(this + 16);
    v12 = *(float *)(a3 + 4) - *(float *)(this + 20);
    v13 = *(float *)(a3 + 8) - *(float *)(this + 24);
    v8 = *(float *)(this + 48) * v11;
    v9 = *(float *)(this + 52) * v12;
    v4 = *(float *)(this + 56) * v13;
    *v3 = (int)v8 & 0xFFFE;
    v10 = v4;
    v3[1] = (int)v9 & 0xFFFE;
    LOWORD(v5) = (int)v10 & 0xFFFE;
    v3[2] = v5;
  }
  else
  {
    v6 = (_DWORD *)((a2 << 6) + *(_DWORD *)(this + 108));
    *v6 = *(_DWORD *)a3;
    v6[1] = *(_DWORD *)(a3 + 4);
    v6[2] = *(_DWORD *)(a3 + 8);
    v5 = *(_DWORD *)(a3 + 12);
    v6[3] = v5;
  }
  return v5;
}
