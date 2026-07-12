// Function: sub_9C4740
// Address: 0x9c4740
void __userpurge sub_9C4740(int a1@<ecx>, int a2@<ebp>, int a3, float *a4)
{
  int v5; // esi
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  bool v10; // zf
  double v11; // st7
  int n10; // ecx
  double v13; // st6
  float v14; // eax
  double v15; // st6
  double v16; // st6
  float v17; // eax
  double v18; // st6
  float v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // ecx
  int *v23; // ecx
  int v24; // eax
  int v25; // esi
  int v26; // eax
  int *v27; // [esp+0h] [ebp-1C0h]
  int v28; // [esp+Ch] [ebp-1B4h]
  float v29; // [esp+10h] [ebp-1B0h]
  int v30; // [esp+10h] [ebp-1B0h]
  void **p_??_7ConvexResultCallback@btCollisionWorld@@6B@; // [esp+24h] [ebp-19Ch] BYREF
  float v32; // [esp+28h] [ebp-198h]
  __int16 v33; // [esp+2Ch] [ebp-194h]
  __int16 v34; // [esp+2Eh] [ebp-192h]
  _BYTE v35[16]; // [esp+54h] [ebp-16Ch] BYREF
  int v36; // [esp+64h] [ebp-15Ch] BYREF
  int v37; // [esp+74h] [ebp-14Ch]
  float v38[5]; // [esp+B4h] [ebp-10Ch] BYREF
  float *v39; // [esp+C8h] [ebp-F8h]
  int v40; // [esp+CCh] [ebp-F4h]
  int n10_1; // [esp+D0h] [ebp-F0h]
  float v42; // [esp+D4h] [ebp-ECh] BYREF
  float v43; // [esp+D8h] [ebp-E8h]
  float v44; // [esp+DCh] [ebp-E4h]
  int v45; // [esp+E0h] [ebp-E0h]
  float v46; // [esp+F0h] [ebp-D0h]
  float v47; // [esp+F4h] [ebp-CCh]
  float v48; // [esp+F8h] [ebp-C8h]
  float v49; // [esp+FCh] [ebp-C4h]
  int v50; // [esp+100h] [ebp-C0h]
  float v51; // [esp+108h] [ebp-B8h]
  float v52; // [esp+10Ch] [ebp-B4h]
  float v53; // [esp+110h] [ebp-B0h]
  float v54[16]; // [esp+114h] [ebp-ACh] BYREF
  float v55[23]; // [esp+154h] [ebp-6Ch] BYREF
  int v56; // [esp+1B0h] [ebp-10h]
  _DWORD v57[2]; // [esp+1B4h] [ebp-Ch] BYREF
  int v58; // [esp+1BCh] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+1C0h] [ebp+0h]

  v57[0] = a2;
  v57[1] = retaddr;
  v56 = -1;
  LODWORD(v55[22]) = &loc_AD9F4B;
  v55[21] = *(float *)&NtCurrentTeb()->NtTib.ExceptionList;
  LODWORD(v55[20]) = &v58;
  v5 = a3;
  v6 = a4[2];
  v39 = a4;
  v7 = v6 + *(float *)(a1 + 104);
  v50 = 0;
  v40 = a3;
  v51 = v7;
  v53 = a4[1] + *(float *)(a1 + 100);
  v47 = *a4 + *(float *)(a1 + 96);
  v8 = v53;
  *(float *)(a1 + 128) = v47;
  v48 = v8;
  v9 = v51;
  *(float *)(a1 + 132) = v48;
  v49 = v9;
  *(float *)(a1 + 136) = v49;
  *(_DWORD *)(a1 + 140) = v50;
  sub_6035C0(v54);
  sub_6035C0(v55);
  v10 = *(_BYTE *)(a1 + 164) == 0;
  v46 = 1.0;
  if ( v10
    || (v53 = *(float *)(a1 + 84) * *(float *)(a1 + 180)
            + *(float *)(a1 + 80) * *(float *)(a1 + 176)
            + *(float *)(a1 + 88) * *(float *)(a1 + 184),
        v53 <= 0.0) )
  {
    v11 = 0.0;
  }
  else
  {
    sub_9C5100(a1, (int)v57, a1 + 176, COERCE_INT(0.0), 1.0);
    v11 = 0.0;
  }
  n10 = 10;
  do
  {
    n10_1 = n10 - 1;
    if ( n10 <= 0 )
      break;
    v13 = *(float *)(a1 + 104) - *(float *)(a1 + 136);
    v54[12] = *(float *)(a1 + 96);
    v54[13] = *(float *)(a1 + 100);
    v14 = *(float *)(a1 + 104);
    v51 = v13;
    v15 = *(float *)(a1 + 100);
    v54[14] = v14;
    v16 = v15 - *(float *)(a1 + 132);
    v54[15] = *(float *)(a1 + 108);
    v17 = *(float *)(a1 + 128);
    v53 = v16;
    v55[12] = v17;
    v18 = *(float *)(a1 + 96) - *(float *)(a1 + 128);
    v55[13] = *(float *)(a1 + 132);
    v55[14] = *(float *)(a1 + 136);
    v19 = *(float *)(a1 + 140);
    v38[0] = v18;
    v38[1] = v53;
    v55[15] = v19;
    v38[2] = v51;
    v38[3] = 0.0;
    *(float *)&v28 = v11;
    sub_9C2F60(&p_??_7ConvexResultCallback@btCollisionWorld@@6B@, *(_DWORD *)(a1 + 8), v38, v28);
    v20 = *(_DWORD *)(a1 + 8);
    v56 = 0;
    v33 = *(_WORD *)(*(_DWORD *)(v20 + 200) + 4);
    v21 = *(_DWORD *)(v20 + 200);
    v22 = *(_DWORD *)(a1 + 12);
    v34 = *(_WORD *)(v21 + 6);
    v52 = ((double (__thiscall *)(int, _DWORD))*(_DWORD *)(*(_DWORD *)v22 + 40))(v22, LODWORD(v29));
    v23 = *(int **)(a1 + 12);
    v24 = *v23;
    v53 = *(float *)(a1 + 56) + v52;
    (*(void (__thiscall **)(int *, float))(v24 + 36))(v23, COERCE_FLOAT(LODWORD(v53)));
    v30 = *(int *)(v5 + 56);
    v27 = *(int **)(a1 + 12);
    if ( *(_BYTE *)(a1 + 194) )
      sub_986CD0(
        *(_DWORD *)(a1 + 8),
        (int)v57,
        v27,
        v54,
        v55,
        (float *)&p_??_7ConvexResultCallback@btCollisionWorld@@6B@,
        v30);
    else
      sub_97DD40(v27, (int)v54, v55, &p_??_7ConvexResultCallback@btCollisionWorld@@6B@, v30);
    v29 = v52;
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a1 + 12) + 36))(*(_DWORD *)(a1 + 12));
    v46 = v46 - v32;
    if ( v32 >= 1.0 )
    {
      v11 = 0.0;
      *(_DWORD *)(a1 + 96) = *(_DWORD *)(a1 + 128);
      *(_DWORD *)(a1 + 100) = *(_DWORD *)(a1 + 132);
      *(_DWORD *)(a1 + 104) = *(_DWORD *)(a1 + 136);
      *(_DWORD *)(a1 + 108) = *(_DWORD *)(a1 + 140);
    }
    else
    {
      sub_9C5100(a1, (int)v57, (int)v35, COERCE_INT(0.0), 1.0);
      v53 = *(float *)(a1 + 136) - *(float *)(a1 + 104);
      v51 = *(float *)(a1 + 132) - *(float *)(a1 + 100);
      v47 = *(float *)(a1 + 128) - *(float *)(a1 + 96);
      v52 = v47 * v47 + v51 * v51 + v53 * v53;
      if ( v52 <= 0.00000011920929 )
        return;
      v52 = sqrt(v52);
      v25 = 0;
      if ( (*(_BYTE *)(v37 + 244) & 2) != 0 )
        v25 = v37;
      v42 = *v39;
      v43 = v39[1];
      v44 = v39[2];
      v45 = *((_DWORD *)v39 + 3);
      v52 = 1.0 / v52;
      v47 = v47 * v52;
      v48 = v52 * v51;
      v49 = v52 * v53;
      v53 = v42 * v42 + v43 * v43 + v44 * v44;
      v53 = sqrt(v53);
      v26 = *(_DWORD *)a1;
      v53 = 1.0 / v53;
      v42 = v53 * v42;
      v43 = v43 * v53;
      v44 = v53 * v44;
      (*(void (__thiscall **)(int, int, int *, _BYTE *, float *))(v26 + 48))(a1, v25, &v36, v35, &v42);
      v53 = *(float *)(a1 + 84) * v48 + v47 * *(float *)(a1 + 80) + *(float *)(a1 + 88) * v49;
      v11 = 0.0;
      if ( v53 <= 0.0 )
        return;
      v5 = v40;
    }
    n10 = n10_1;
    v56 = -1;
  }
  while ( v46 > 0.0099999998 );
}
