// Function: sub_9930A0
// Address: 0x9930a0
__int16 __thiscall sub_9930A0(int this, int a2, float *a3, float *a4)
{
  int this_1; // edx
  double v5; // st7
  double v6; // st6
  double v7; // st5
  int v8; // edi
  int v9; // eax
  int v10; // esi
  _WORD *v11; // ecx
  float v13; // [esp-40h] [ebp-4Ch]
  float v14; // [esp-40h] [ebp-4Ch]
  float v15; // [esp-3Ch] [ebp-48h]
  float v16; // [esp-3Ch] [ebp-48h]
  float v17; // [esp-38h] [ebp-44h]
  float v18; // [esp-38h] [ebp-44h]
  float v19; // [esp-30h] [ebp-3Ch]
  float v20; // [esp-30h] [ebp-3Ch]
  float v21; // [esp-2Ch] [ebp-38h]
  float v22; // [esp-2Ch] [ebp-38h]
  float v23; // [esp-28h] [ebp-34h]
  float v24; // [esp-28h] [ebp-34h]
  unsigned __int16 v26; // [esp-18h] [ebp-24h]
  unsigned __int16 v27; // [esp-14h] [ebp-20h]
  unsigned __int16 v28; // [esp-10h] [ebp-1Ch]
  float v29; // [esp-Ch] [ebp-18h]
  int v30; // [esp-Ch] [ebp-18h]
  unsigned __int16 v31; // [esp-6h] [ebp-12h]
  unsigned __int16 v32; // [esp-4h] [ebp-10h]
  unsigned __int16 v33; // [esp-2h] [ebp-Eh]

  this_1 = this;
  v5 = *(float *)(this + 16);
  v19 = *a3 - v5;
  v6 = *(float *)(this + 20);
  v21 = a3[1] - v6;
  v7 = *(float *)(this + 24);
  v23 = a3[2] - v7;
  v13 = *(float *)(this + 48) * v19;
  v15 = *(float *)(this + 52) * v21;
  v29 = *(float *)(this + 56);
  v26 = (int)v13 & 0xFFFE;
  v17 = v29 * v23;
  v28 = (int)v15 & 0xFFFE;
  v27 = (int)v17 & 0xFFFE;
  v14 = *a4 - v5;
  v16 = a4[1] - v6;
  v18 = a4[2] - v7;
  v20 = *(float *)(this + 48) * v14;
  v22 = *(float *)(this + 52) * v16;
  v24 = v29 * v18;
  v8 = 0;
  LOWORD(v9) = (int)(v24 + 1.0) | 1;
  if ( *(int *)(this + 164) > 0 )
  {
    v9 = 0;
    v30 = 0;
    do
    {
      v10 = v9 + *(_DWORD *)(this_1 + 172);
      v31 = (int)(v22 + 1.0) | 1;
      v32 = (int)(v20 + 1.0) | 1;
      v33 = (int)(v24 + 1.0) | 1;
      if ( (v31 >= *(_WORD *)(v10 + 2)
         && v32 >= *(_WORD *)v10
         && v33 >= *(_WORD *)(v10 + 4)
         && *(_WORD *)(v10 + 6) >= v26
         && *(_WORD *)(v10 + 10) >= v27
         && *(_WORD *)(v10 + 8) >= v28
          ? -1
          : v31 >= *(_WORD *)(v10 + 2)
         && v32 >= *(_WORD *)v10
         && v33 >= *(_WORD *)(v10 + 4)
         && *(_WORD *)(v10 + 6) >= v26
         && *(_WORD *)(v10 + 10) >= v27
         && *(_WORD *)(v10 + 8) >= v28) < 0 )
      {
        sub_993300(a2, *(_DWORD *)(v10 + 12), *(_DWORD *)(v10 + 12) + *(_DWORD *)(v10 + 16), v8);
        this_1 = this;
        v11 = (_WORD *)(*(_DWORD *)(this + 148) + 16 * *(_DWORD *)(v10 + 12));
        *(_WORD *)v10 = *v11;
        *(_WORD *)(v10 + 2) = v11[1];
        *(_WORD *)(v10 + 4) = v11[2];
        *(_WORD *)(v10 + 6) = v11[3];
        *(_WORD *)(v10 + 8) = v11[4];
        *(_WORD *)(v10 + 10) = v11[5];
      }
      ++v8;
      v9 = v30 + 32;
      v30 += 32;
    }
    while ( v8 < *(_DWORD *)(this_1 + 164) );
  }
  return v9;
}
