// Function: sub_9C4410
// Address: 0x9c4410
int __userpurge sub_9C4410@<eax>(float a1@<ecx>, int a2@<ebp>, int a3, float a4)
{
  float v5; // xmm1_4
  double v6; // st7
  _DWORD *v7; // eax
  int v8; // ecx
  double v9; // st7
  double v10; // st7
  _DWORD *v11; // eax
  bool v12; // zf
  int v13; // ecx
  int v14; // eax
  int v15; // esi
  int v16; // edi
  _DWORD *v17; // eax
  float v18; // edi
  int result; // eax
  double v20; // st7
  double v21; // st6
  int *v22; // [esp-10h] [ebp-184h]
  int v23; // [esp-Ch] [ebp-180h]
  int v24; // [esp+0h] [ebp-174h]
  int v25; // [esp+0h] [ebp-174h]
  void **p_??_7ConvexResultCallback@btCollisionWorld@@6B@; // [esp+18h] [ebp-15Ch] BYREF
  float v27; // [esp+1Ch] [ebp-158h]
  __int16 v28; // [esp+20h] [ebp-154h]
  __int16 v29; // [esp+22h] [ebp-152h]
  int v30; // [esp+48h] [ebp-12Ch] BYREF
  int v31; // [esp+58h] [ebp-11Ch] BYREF
  int v32; // [esp+68h] [ebp-10Ch]
  float v33; // [esp+A8h] [ebp-CCh]
  float v34; // [esp+BCh] [ebp-B8h]
  float v35; // [esp+C0h] [ebp-B4h]
  float v36; // [esp+C4h] [ebp-B0h]
  float v37[16]; // [esp+C8h] [ebp-ACh] BYREF
  float v38[23]; // [esp+108h] [ebp-6Ch] BYREF
  int v39; // [esp+164h] [ebp-10h]
  _DWORD v40[2]; // [esp+168h] [ebp-Ch] BYREF
  int v41; // [esp+170h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+174h] [ebp+0h]

  v40[0] = a2;
  v40[1] = retaddr;
  v39 = -1;
  LODWORD(v38[22]) = &loc_AD9F0B;
  v38[21] = *(float *)&NtCurrentTeb()->NtTib.ExceptionList;
  LODWORD(v38[20]) = &v41;
  v34 = a1;
  v5 = *(float *)(LODWORD(a1) + 16);
  if ( v5 >= 0.0 )
    v36 = 0.0;
  else
    v36 = -v5;
  v36 = v36 * a4;
  v6 = v36;
  if ( v36 > 0.0 )
  {
    v35 = *(float *)(LODWORD(a1) + 52);
    if ( v35 > v6 && (*(_BYTE *)(LODWORD(a1) + 192) || !*(_BYTE *)(LODWORD(a1) + 193)) )
    {
      v36 = v35;
      v6 = v35;
    }
  }
  v35 = v6 + *(float *)(LODWORD(a1) + 112);
  v7 = sub_9C34C0();
  v8 = 2 * *(_DWORD *)(LODWORD(a1) + 200);
  v9 = v35;
  v36 = *(float *)&v7[4 * *(_DWORD *)(LODWORD(a1) + 200) + 2] * v35;
  v35 = *(float *)&v7[2 * v8 + 1] * v35;
  v33 = v9 * *(float *)&v7[2 * v8];
  *(float *)(LODWORD(a1) + 128) = *(float *)(LODWORD(a1) + 128) - v33;
  *(float *)(LODWORD(a1) + 132) = *(float *)(LODWORD(a1) + 132) - v35;
  *(float *)(LODWORD(a1) + 136) = *(float *)(LODWORD(a1) + 136) - v36;
  sub_6035C0(v37);
  sub_6035C0(v38);
  v10 = *(float *)(LODWORD(a1) + 40);
  v37[12] = *(float *)(LODWORD(a1) + 96);
  v37[13] = *(float *)(LODWORD(a1) + 100);
  v37[14] = *(float *)(LODWORD(a1) + 104);
  v37[15] = *(float *)(LODWORD(a1) + 108);
  v38[12] = *(float *)(LODWORD(a1) + 128);
  v38[13] = *(float *)(LODWORD(a1) + 132);
  v38[14] = *(float *)(LODWORD(a1) + 136);
  v38[15] = *(float *)(LODWORD(a1) + 140);
  *(float *)&v24 = v10;
  v11 = sub_9C34C0();
  sub_9C2F60(
    &p_??_7ConvexResultCallback@btCollisionWorld@@6B@,
    *(_DWORD *)(LODWORD(a1) + 8),
    &v11[4 * *(_DWORD *)(LODWORD(a1) + 200)],
    v24);
  v12 = *(_BYTE *)(LODWORD(a1) + 194) == 0;
  v13 = *(_DWORD *)(LODWORD(a1) + 8);
  v14 = *(_DWORD *)(v13 + 200);
  v25 = *(int *)(a3 + 56);
  v39 = 0;
  v28 = *(_WORD *)(v14 + 4);
  v29 = *(_WORD *)(*(_DWORD *)(v13 + 200) + 6);
  v22 = *(int **)(LODWORD(a1) + 12);
  if ( v12 )
    sub_97DD40(v22, (int)v37, v38, &p_??_7ConvexResultCallback@btCollisionWorld@@6B@, v25);
  else
    sub_986CD0(v13, (int)v40, v22, v37, v38, (float *)&p_??_7ConvexResultCallback@btCollisionWorld@@6B@, v25);
  if ( v27 >= 1.0 )
  {
    *(_DWORD *)(LODWORD(a1) + 96) = *(_DWORD *)(LODWORD(a1) + 128);
    *(_DWORD *)(LODWORD(a1) + 100) = *(_DWORD *)(LODWORD(a1) + 132);
    *(_DWORD *)(LODWORD(a1) + 104) = *(_DWORD *)(LODWORD(a1) + 136);
    result = *(_DWORD *)(LODWORD(a1) + 140);
    *(_DWORD *)(LODWORD(a1) + 108) = result;
  }
  else
  {
    v15 = *(_DWORD *)LODWORD(a1);
    v16 = 0;
    if ( (*(_BYTE *)(v32 + 244) & 2) != 0 )
      v16 = v32;
    v17 = sub_9C34C0();
    v23 = v16;
    v18 = v34;
    result = (*(int (__thiscall **)(float, int, int *, int *, _DWORD *))(v15 + 48))(
               COERCE_FLOAT(LODWORD(v34)),
               v23,
               &v31,
               &v30,
               &v17[4 * *(_DWORD *)(LODWORD(v34) + 200)]);
    v20 = v27;
    v34 = 1.0 - v27;
    v21 = v34;
    *(float *)(LODWORD(v18) + 96) = *(float *)(LODWORD(v18) + 96) * v34 + *(float *)(LODWORD(v18) + 128) * v27;
    *(float *)(LODWORD(v18) + 100) = *(float *)(LODWORD(v18) + 132) * v20 + v21 * *(float *)(LODWORD(v18) + 100);
    *(float *)(LODWORD(v18) + 104) = v20 * *(float *)(LODWORD(v18) + 136) + v21 * *(float *)(LODWORD(v18) + 104);
    *(_DWORD *)(LODWORD(v18) + 16) = 0;
    *(_DWORD *)(LODWORD(v18) + 20) = 0;
    *(_BYTE *)(LODWORD(v18) + 193) = 0;
  }
  return result;
}
