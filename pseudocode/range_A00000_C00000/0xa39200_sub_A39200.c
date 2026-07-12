// Function: sub_A39200
// Address: 0xa39200
// Size: 0x68d
// Prototype: 

int __stdcall sub_A39200(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // esi
  int v10; // ecx
  int v11; // eax
  int result; // eax
  double v13; // st7
  int v14; // ecx
  float *v15; // esi
  int v16; // ecx
  int v17; // edx
  int v18; // eax
  int v19; // eax
  char n4; // al
  _DWORD *v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // ecx
  int v25; // ecx
  float v26; // esi
  int v27; // eax
  _DWORD *v28; // eax
  double v29; // st7
  double v30; // st6
  int v31; // ecx
  float v32; // esi
  int v33; // ecx
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  int v37; // edx
  int v38; // ebx
  int v39; // [esp-Ch] [ebp-FCh]
  int v40[6]; // [esp+Ch] [ebp-E4h] BYREF
  _DWORD v41[5]; // [esp+24h] [ebp-CCh] BYREF
  _DWORD v42[4]; // [esp+38h] [ebp-B8h] BYREF
  float v43[4]; // [esp+48h] [ebp-A8h] BYREF
  int v44; // [esp+58h] [ebp-98h]
  float v45; // [esp+5Ch] [ebp-94h] BYREF
  float v46; // [esp+60h] [ebp-90h]
  float v47; // [esp+64h] [ebp-8Ch]
  float v48; // [esp+68h] [ebp-88h]
  int v49; // [esp+6Ch] [ebp-84h] BYREF
  int v50; // [esp+70h] [ebp-80h] BYREF
  int v51; // [esp+74h] [ebp-7Ch]
  int v52; // [esp+78h] [ebp-78h]
  float v53; // [esp+7Ch] [ebp-74h]
  float v54; // [esp+80h] [ebp-70h]
  float v55; // [esp+84h] [ebp-6Ch]
  unsigned int v56; // [esp+88h] [ebp-68h] BYREF
  unsigned int v57; // [esp+8Ch] [ebp-64h]
  _DWORD v58[4]; // [esp+B4h] [ebp-3Ch] BYREF
  int v59; // [esp+C4h] [ebp-2Ch] BYREF
  int v60; // [esp+C8h] [ebp-28h]
  int v61; // [esp+CCh] [ebp-24h]
  int v62; // [esp+D0h] [ebp-20h]
  int v63; // [esp+D4h] [ebp-1Ch]
  int v64; // [esp+D8h] [ebp-18h]
  int v65; // [esp+DCh] [ebp-14h] BYREF
  int v66; // [esp+E0h] [ebp-10h]
  int v67; // [esp+E4h] [ebp-Ch]
  int v68; // [esp+E8h] [ebp-8h]

  v6 = a2;
  v55 = *((float *)dword_1A858B4 + 1);
  v44 = dword_1A858B4[479];
  v7 = dword_1A858B4[444];
  v51 = v7;
  if ( a2 <= v7 )
    v6 = v7;
  v8 = dword_1A858B4[445];
  v9 = a3;
  v65 = v6;
  v52 = v8;
  if ( a3 <= v8 )
    v9 = v8;
  v10 = dword_1A858B4[440] + v51;
  v11 = a4;
  v66 = v9;
  if ( a4 >= v10 )
  {
    v11 = v10;
    a4 = v10;
  }
  v67 = v11;
  result = a5;
  if ( a5 >= dword_1A858B4[441] + v52 )
    result = dword_1A858B4[441] + v52;
  v68 = result;
  if ( a4 >= v6 && result >= v9 )
  {
    v53 = (float)(int)dword_1A858B4[432];
    v54 = v53;
    v53 = (float)(v65 - v51);
    v13 = v54;
    v43[0] = v53 / v54;
    v54 = (float)(int)dword_1A858B4[433];
    v53 = v54;
    v54 = (float)(v66 - v52);
    v43[1] = v54 / v53;
    v54 = (float)(v67 - v51);
    v43[2] = v54 / v13;
    v54 = (float)(v68 - v52);
    v14 = *(_DWORD *)LODWORD(v55);
    v39 = dword_1A858B4[501];
    v43[3] = v54 / v53;
    (*(void (__stdcall **)(float, int, void *, int))(v14 + 140))(COERCE_FLOAT(LODWORD(v55)), v39, &unk_B7A3F8, -1);
    (*(void (__stdcall **)(float, _DWORD, _DWORD))(*(_DWORD *)LODWORD(v55) + 144))(
      COERCE_FLOAT(LODWORD(v55)),
      dword_1A858B4[508],
      0);
    v15 = (float *)dword_1A858B4;
    if ( dword_1A858B4[625] )
    {
      v16 = dword_1A858B4[447];
      v17 = dword_1A858B4[448];
      v58[2] = v16 + dword_1A858B4[449];
      v18 = dword_1A858B4[450];
      v58[1] = v17;
      v58[3] = v17 + v18;
      v19 = dword_1A858B4[1];
      v58[0] = v16;
      (*(void (__stdcall **)(int, int, _DWORD *))(*(_DWORD *)v19 + 180))(v19, 1, v58);
      v15 = (float *)dword_1A858B4;
      dword_1A858B4[625] = 0;
    }
    v15[626] = 0.0;
    v15[479] = 0.0;
    n4 = *(_BYTE *)(a1 + 12);
    if ( n4 == 4 )
    {
      switch ( *(_BYTE *)(a1 + 14) )
      {
        case 0:
          v21 = (_DWORD *)sub_A3BA10(*(_DWORD *)(a1 + 28));
          v42[0] = *v21;
          v42[1] = v21[1];
          v22 = v21[2];
          v42[3] = v21[3];
          v23 = -*((_DWORD *)v15 + 444);
          v42[2] = v22;
          v24 = *((_DWORD *)v15 + 445);
          v65 += v23;
          v67 += v23;
          v25 = -v24;
          v66 += v25;
          v68 += v25;
          *(float *)v41 = v15[440];
          *(float *)&v41[1] = v15[441];
          *(float *)&v41[2] = v15[432];
          *(float *)&v41[3] = v15[433];
          v41[4] = sub_A38AA0;
          *((_DWORD *)v15 + 446) = 1;
          sub_A36490(&psub_A39900, v41, a1, &v65, v42, a6);
          dword_1A858B4[446] = 0;
          sub_A3CD30();
          sub_A3C350();
          goto LABEL_38;
        case 1:
          sub_A374E0(a1, a6, a1, &v65, (int)v43, a6);
          goto LABEL_38;
        case 2:
          sub_A38C40(a1, a6, a1, &v65, (int)v43, 1, a6);
          goto LABEL_38;
        case 3:
          sub_A38C40(a1, a6, a1, &v65, (int)v43, 0, a6);
          goto LABEL_38;
        default:
          goto LABEL_39;
      }
      goto LABEL_39;
    }
    v53 = 0.0;
    v45 = 1.0;
    v46 = 1.0;
    v47 = 0.0;
    v48 = 0.0;
    if ( n4 == 5 )
    {
      v26 = v15[1];
      v55 = v26;
      v27 = sub_A3B590();
      (*(void (__stdcall **)(int, int *))(*(_DWORD *)v27 + 28))(v27, &v49);
      if ( (_DWORD *)dword_1A858B4[683] == dword_1A858B4 + 627 && dword_1A858B4[484] )
      {
        (*(void (__stdcall **)(_DWORD, int *))(*(_DWORD *)dword_1A858B4[483] + 32))(dword_1A858B4[483], v40);
        (*(void (__stdcall **)(_DWORD, int *))(*(_DWORD *)dword_1A858B4[483] + 28))(dword_1A858B4[483], &v50);
        (*(void (__stdcall **)(int, unsigned int *))(*(_DWORD *)v50 + 40))(v50, &v56);
        (*(void (__stdcall **)(float, int, _DWORD, int, _DWORD, int))(*(_DWORD *)LODWORD(v26) + 228))(
          COERCE_FLOAT(LODWORD(v26)),
          v50,
          0,
          v49,
          0,
          v40[0]);
        (*(void (__stdcall **)(int))(*(_DWORD *)v50 + 8))(v50);
        *(_DWORD *)(a6 + 24) += v56 * v57;
        v28 = dword_1A858B4;
        *(_WORD *)a6 |= 2u;
        ++*(_WORD *)(a6 + 4);
        (*(void (__stdcall **)(float, int, int, _DWORD *))(*(_DWORD *)LODWORD(v26) + 32))(
          COERCE_FLOAT(LODWORD(v26)),
          1,
          1,
          v28 + 483);
        (*(void (__stdcall **)(float, int, int, _DWORD *))(*(_DWORD *)LODWORD(v26) + 40))(
          COERCE_FLOAT(LODWORD(v26)),
          1,
          1,
          dword_1A858B4 + 493);
        v55 = (float)v56;
        v54 = v55;
        v55 = (float)(int)dword_1A858B4[432];
        v29 = v54;
        v45 = v55 / v54;
        v55 = (float)v57;
        v54 = v55;
        v55 = (float)(int)dword_1A858B4[433];
        v30 = v55 / v54;
        LODWORD(v55) = dword_1A858B4[434] + dword_1A858B4[444] - dword_1A858B4[442];
        v46 = v30;
        v55 = (float)SLODWORD(v55);
        v31 = dword_1A858B4[435] + dword_1A858B4[445] - dword_1A858B4[443];
        v47 = v55 / v29;
        v55 = (float)v31;
        v48 = v55 / v54;
      }
      else
      {
        v59 = 0;
        v60 = 0;
        v61 = 0;
        v62 = 0;
        v63 = 0;
        v64 = 1;
        v51 = 0;
        v52 = 0;
        v32 = COERCE_FLOAT(sub_A3B610(a6));
        v53 = v32;
        if ( (_DWORD *)dword_1A858B4[683] == dword_1A858B4 + 627 )
        {
          v59 = dword_1A858B4[434];
          v60 = dword_1A858B4[435];
          v62 = dword_1A858B4[434] + dword_1A858B4[438];
          v63 = dword_1A858B4[435] + dword_1A858B4[439];
          v51 = dword_1A858B4[442] - dword_1A858B4[444];
          v52 = dword_1A858B4[443] - dword_1A858B4[445];
        }
        else
        {
          v62 = dword_1A858B4[440];
          v63 = dword_1A858B4[441];
        }
        (*(void (__stdcall **)(float, _DWORD, _DWORD, int, int, _DWORD, int, _DWORD, int *))(*(_DWORD *)LODWORD(v55)
                                                                                           + 184))(
          COERCE_FLOAT(LODWORD(v55)),
          *(_DWORD *)LODWORD(v32),
          0,
          v51,
          v52,
          0,
          v49,
          0,
          &v59);
        v33 = v63 - v60;
        v34 = v62 - v59;
        *(_WORD *)a6 |= 2u;
        ++*(_WORD *)(a6 + 4);
        *(_DWORD *)(a6 + 24) += v34 * v33;
        sub_A3CCB0(1, LODWORD(v32), 0, 0);
      }
      (*(void (__stdcall **)(int))(*(_DWORD *)v49 + 8))(v49);
    }
    if ( sub_A3C6C0(2, a1, a6, &v45) )
    {
      sub_A36040(&v65, v43, a6);
      v35 = *(_DWORD *)(a1 + 28);
      v15 = (float *)dword_1A858B4;
      v36 = *(_DWORD *)(a1 + 32);
      v37 = dword_1A858B4[688];
      v38 = dword_1A858B4[689];
      if ( v35 )
      {
        *(_DWORD *)(v35 + 40) = v37;
        *(_DWORD *)(v35 + 44) = v38;
      }
      if ( v36 )
      {
        *(_DWORD *)(v36 + 40) = v37;
        *(_DWORD *)(v36 + 44) = v38;
      }
      if ( v53 == 0.0 )
        goto LABEL_39;
      if ( *(float **)(LODWORD(v53) + 24) == v15 + 164 )
      {
        sub_A39F00(LODWORD(v53));
LABEL_39:
        result = v44;
        *((_DWORD *)v15 + 479) = v44;
        return result;
      }
      sub_A3B480(LODWORD(v53), a6);
    }
LABEL_38:
    v15 = (float *)dword_1A858B4;
    goto LABEL_39;
  }
  return result;
}

