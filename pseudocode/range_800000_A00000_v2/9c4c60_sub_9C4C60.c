// Function: sub_9C4C60
// Address: 0x9c4c60
// bad sp value at call has been detected, the output may be wrong!
_DWORD *__userpurge sub_9C4C60@<eax>(float *a1@<ecx>, int a2@<ebp>, int a3)
{
  _DWORD *v4; // eax
  int v5; // ecx
  double v6; // st7
  double v7; // st7
  double v8; // st7
  _DWORD *v9; // eax
  int v10; // ecx
  double v11; // st7
  _DWORD *v12; // eax
  struct _EXCEPTION_REGISTRATION_RECORD *v13; // ecx
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  bool v17; // zf
  float v18; // ecx
  int v19; // eax
  int v20; // esi
  _DWORD *v21; // eax
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // eax
  _DWORD *result; // eax
  double v27; // st7
  double v28; // st6
  double v29; // st7
  void **p_??_7ConvexResultCallback@btCollisionWorld@@6B@; // [esp+18h] [ebp-16Ch] BYREF
  float v31; // [esp+1Ch] [ebp-168h]
  __int16 v32; // [esp+20h] [ebp-164h]
  __int16 v33; // [esp+22h] [ebp-162h]
  float v34[4]; // [esp+48h] [ebp-13Ch] BYREF
  int v35; // [esp+58h] [ebp-12Ch] BYREF
  int v36; // [esp+68h] [ebp-11Ch]
  float v37[4]; // [esp+A8h] [ebp-DCh] BYREF
  float v38; // [esp+B8h] [ebp-CCh] BYREF
  float v39; // [esp+BCh] [ebp-C8h]
  float v40; // [esp+C0h] [ebp-C4h]
  int v41; // [esp+C4h] [ebp-C0h]
  float v42; // [esp+CCh] [ebp-B8h]
  float v43; // [esp+D0h] [ebp-B4h]
  float v44; // [esp+D4h] [ebp-B0h]
  float v45[16]; // [esp+D8h] [ebp-ACh] BYREF
  float v46[19]; // [esp+118h] [ebp-6Ch] BYREF
  int v47; // [esp+164h] [ebp-20h]
  float *v48; // [esp+168h] [ebp-1Ch]
  float v49; // [esp+16Ch] [ebp-18h]
  void *v50; // [esp+170h] [ebp-14h]
  int v51; // [esp+174h] [ebp-10h]
  _DWORD v52[2]; // [esp+178h] [ebp-Ch] BYREF
  int v53; // [esp+180h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+184h] [ebp+0h]

  v52[0] = a2;
  v52[1] = retaddr;
  v51 = -1;
  v50 = &loc_AD9F8B;
  v49 = *(float *)&NtCurrentTeb()->NtTib.ExceptionList;
  v48 = (float *)&v53;
  if ( a1[5] <= 0.0 )
    v44 = 0.0;
  else
    v44 = a1[5];
  v44 = v44 + a1[13];
  v4 = sub_9C34C0();
  v5 = 2 * *((_DWORD *)a1 + 50);
  v41 = 0;
  v6 = v44;
  v44 = *(float *)&v4[2 * v5 + 2] * v44;
  v43 = *(float *)&v4[2 * v5 + 1] * v6;
  v38 = v6 * *(float *)&v4[2 * v5];
  v44 = a1[26] + v44;
  v43 = a1[25] + v43;
  v38 = a1[24] + v38;
  v7 = v43;
  a1[32] = v38;
  v39 = v7;
  v8 = v44;
  a1[33] = v39;
  v40 = v8;
  a1[34] = v40;
  *((_DWORD *)a1 + 35) = v41;
  sub_6035C0(v45);
  sub_6035C0(v46);
  v43 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(**((_DWORD **)a1 + 3) + 40))(*((_DWORD *)a1 + 3)) + a1[14];
  v9 = sub_9C34C0();
  v10 = 2 * *((_DWORD *)a1 + 50);
  v41 = 0;
  v11 = v43;
  v43 = *(float *)&v9[2 * v10 + 2] * v43;
  v44 = *(float *)&v9[2 * v10 + 1] * v11;
  v37[0] = v11 * *(float *)&v9[2 * v10];
  v42 = a1[26] + v43;
  v43 = a1[25] + v44;
  v38 = a1[24] + v37[0];
  v45[12] = v38;
  v39 = v43;
  v45[13] = v43;
  v40 = v42;
  v45[14] = v42;
  v45[15] = 0.0;
  v46[12] = a1[32];
  v46[13] = a1[33];
  v46[14] = a1[34];
  v46[15] = a1[35];
  v12 = sub_9C34C0();
  v13 = (struct _EXCEPTION_REGISTRATION_RECORD *)(16 * *((_DWORD *)a1 + 50));
  v49 = *(float *)&v13;
  v14 = *(float *)((char *)&v13[1].Next + (_DWORD)v12);
  v15 = *(float *)((char *)&v13->Handler + (_DWORD)v12);
  v49 = 0.70709997;
  v16 = *(float *)((char *)&v13->Next + (_DWORD)v12);
  v48 = &v38;
  v47 = *((_DWORD *)a1 + 2);
  v38 = -v16;
  v39 = -v15;
  v40 = -v14;
  v41 = 0;
  sub_9C2F60(&p_??_7ConvexResultCallback@btCollisionWorld@@6B@, v47, &v38, COERCE_INT(0.70709997));
  v17 = *((_BYTE *)a1 + 194) == 0;
  v18 = a1[2];
  v51 = 0;
  v19 = *(_DWORD *)(LODWORD(v18) + 200);
  v49 = v18;
  v32 = *(_WORD *)(v19 + 4);
  v33 = *(_WORD *)(*(_DWORD *)(LODWORD(v18) + 200) + 6);
  if ( v17 )
    sub_97DD40(*((_DWORD **)a1 + 3), (int)v45, v46, &p_??_7ConvexResultCallback@btCollisionWorld@@6B@, 0.0);
  else
    sub_986CD0(
      SLODWORD(v18),
      (int)v52,
      *((int **)a1 + 3),
      v45,
      v46,
      (float *)&p_??_7ConvexResultCallback@btCollisionWorld@@6B@,
      COERCE_INT(*(float *)(a3 + 56)));
  if ( v31 >= 1.0 )
  {
    v29 = a1[13];
    a1[24] = a1[32];
    a1[28] = v29;
    a1[25] = a1[33];
    a1[26] = a1[34];
    result = (_DWORD *)*((_DWORD *)a1 + 35);
    *((_DWORD *)a1 + 27) = result;
  }
  else
  {
    v20 = 0;
    if ( (*(_BYTE *)(v36 + 244) & 2) != 0 )
      v20 = v36;
    v21 = sub_9C34C0();
    v22 = *(float *)&v21[4 * *((_DWORD *)a1 + 50) + 2];
    v23 = *(float *)&v21[4 * *((_DWORD *)a1 + 50) + 1];
    v24 = *(float *)&v21[4 * *((_DWORD *)a1 + 50)];
    v25 = *a1;
    v37[0] = -v24;
    v37[1] = -v23;
    v37[2] = -v22;
    v37[3] = 0.0;
    (*(void (__thiscall **)(float *, int, int *, float *, float *))(LODWORD(v25) + 48))(a1, v20, &v35, v34, v37);
    result = sub_9C34C0();
    v42 = *(float *)&result[4 * *((_DWORD *)a1 + 50) + 1] * v34[1]
        + *(float *)&result[4 * *((_DWORD *)a1 + 50)] * v34[0]
        + *(float *)&result[4 * *((_DWORD *)a1 + 50) + 2] * v34[2];
    if ( v42 > 0.0 )
    {
      v27 = v31;
      a1[28] = v31 * a1[13];
      v42 = 1.0 - v27;
      v28 = v42;
      a1[24] = a1[24] * v42 + a1[32] * v27;
      a1[25] = a1[33] * v27 + a1[25] * v28;
      a1[26] = v27 * a1[34] + v28 * a1[26];
    }
    a1[4] = 0.0;
    a1[5] = 0.0;
  }
  return result;
}
