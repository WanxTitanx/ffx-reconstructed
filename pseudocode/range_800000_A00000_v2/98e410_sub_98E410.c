// Function: sub_98E410
// Address: 0x98e410
void __thiscall sub_98E410(int this, int a2, float *a3, float *a4)
{
  double v5; // st7
  double v6; // st6
  double v7; // st5
  double v8; // st0
  int v9; // edi
  unsigned __int16 v10; // cx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  unsigned __int16 v14; // di
  int v15; // eax
  int v16; // eax
  int v17; // edx
  float *v18; // ecx
  int v19; // ecx
  unsigned __int16 v20; // [esp-44h] [ebp-50h]
  float v21; // [esp-40h] [ebp-4Ch]
  float v22; // [esp-40h] [ebp-4Ch]
  float v23; // [esp-3Ch] [ebp-48h]
  float v24; // [esp-3Ch] [ebp-48h]
  float v25; // [esp-38h] [ebp-44h]
  float v26; // [esp-38h] [ebp-44h]
  float v27; // [esp-30h] [ebp-3Ch]
  float v28; // [esp-30h] [ebp-3Ch]
  float v29; // [esp-2Ch] [ebp-38h]
  float v30; // [esp-2Ch] [ebp-38h]
  float v31; // [esp-28h] [ebp-34h]
  float v32; // [esp-28h] [ebp-34h]
  unsigned __int16 v33; // [esp-12h] [ebp-1Eh]
  unsigned __int16 v34; // [esp-10h] [ebp-1Ch]
  unsigned __int16 v35; // [esp-Ah] [ebp-16h]
  unsigned __int16 v36; // [esp-4h] [ebp-10h]
  float v37; // [esp-4h] [ebp-10h]
  float v38; // [esp-4h] [ebp-10h]
  float v39; // [esp-4h] [ebp-10h]
  float v40; // [esp-4h] [ebp-10h]
  float v41; // [esp-4h] [ebp-10h]
  float v42; // [esp-4h] [ebp-10h]

  if ( *(_BYTE *)(this + 72) )
  {
    v5 = *(float *)(this + 16);
    v27 = *a3 - v5;
    v6 = *(float *)(this + 20);
    v29 = a3[1] - v6;
    v7 = *(float *)(this + 24);
    v31 = a3[2] - v7;
    v21 = v27 * *(float *)(this + 48);
    v23 = v29 * *(float *)(this + 52);
    v8 = *(float *)(this + 56);
    v20 = (int)v21 & 0xFFFE;
    v25 = v31 * v8;
    v36 = (int)v23 & 0xFFFE;
    v34 = (int)v25 & 0xFFFE;
    v22 = *a4 - v5;
    v24 = a4[1] - v6;
    v26 = a4[2] - v7;
    v28 = *(float *)(this + 48) * v22;
    v30 = *(float *)(this + 52) * v24;
    v32 = v8 * v26;
    v9 = *(_DWORD *)(this + 148);
    v35 = (int)(v30 + 1.0) | 1;
    v10 = (int)(v32 + 1.0) | 1;
    if ( *(_WORD *)(v9 + 16 * a2) > v20 )
      *(_WORD *)(v9 + 16 * a2) = v20;
    v11 = *(_DWORD *)(this + 148);
    v33 = (int)(v28 + 1.0) | 1;
    if ( *(_WORD *)(v11 + 16 * a2 + 6) < v33 )
      *(_WORD *)(v11 + 16 * a2 + 6) = v33;
    v12 = *(_DWORD *)(this + 148);
    if ( *(_WORD *)(v12 + 16 * a2 + 2) > v36 )
      *(_WORD *)(v12 + 16 * a2 + 2) = v36;
    v13 = *(_DWORD *)(this + 148);
    v14 = v34;
    if ( *(_WORD *)(v13 + 16 * a2 + 8) < v35 )
    {
      *(_WORD *)(v13 + 16 * a2 + 8) = v35;
      v14 = v34;
    }
    v15 = *(_DWORD *)(this + 148);
    if ( *(_WORD *)(v15 + 16 * a2 + 4) > v14 )
      *(_WORD *)(v15 + 16 * a2 + 4) = v14;
    v16 = *(_DWORD *)(this + 148);
    if ( *(_WORD *)(v16 + 16 * a2 + 10) < v10 )
      *(_WORD *)(v16 + 16 * a2 + 10) = v10;
  }
  else
  {
    v17 = a2 << 6;
    v18 = (float *)((a2 << 6) + *(_DWORD *)(this + 108));
    if ( *v18 > (double)*a3 )
      *v18 = *a3;
    v37 = a3[1];
    if ( v18[1] > (double)v37 )
      v18[1] = v37;
    v38 = a3[2];
    if ( v18[2] > (double)v38 )
      v18[2] = v38;
    v39 = a3[3];
    if ( v18[3] > (double)v39 )
      v18[3] = v39;
    v19 = *(_DWORD *)(this + 108);
    if ( *a4 > (double)*(float *)(v17 + v19 + 16) )
      *(float *)(v17 + v19 + 16) = *a4;
    v40 = a4[1];
    if ( v40 > (double)*(float *)(v17 + v19 + 20) )
      *(float *)(v17 + v19 + 20) = v40;
    v41 = a4[2];
    if ( v41 > (double)*(float *)(v17 + v19 + 24) )
      *(float *)(v17 + v19 + 24) = v41;
    v42 = a4[3];
    if ( v42 > (double)*(float *)(v17 + v19 + 28) )
      *(float *)(v17 + v19 + 28) = v42;
  }
}
