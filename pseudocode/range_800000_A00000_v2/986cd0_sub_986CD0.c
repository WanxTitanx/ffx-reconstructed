// Function: sub_986CD0
// Address: 0x986cd0
int __userpurge sub_986CD0@<eax>(int a1@<ecx>, int a2@<ebp>, int *a3, float *a4, float *a5, float *a6, int a7)
{
  int v7; // esi
  float *v8; // edi
  int result; // eax
  int v10; // ecx
  float v11; // esi
  int (__thiscall *v12)(float *, int); // eax
  int *v13; // ecx
  int v14; // eax
  double v15; // st6
  double v16; // st5
  int n2; // esi
  int n16; // edx
  double v19; // st4
  double v20; // st3
  int n4; // ecx
  int n32; // edi
  int v23; // edi
  double v24; // st2
  double v25; // st1
  int n16_1; // edx
  int n4_1; // ecx
  int n32_1; // esi
  int v29; // esi
  int v30; // edx
  double v31; // st7
  double v32; // st6
  double v33; // st5
  int i; // ecx
  bool v35; // zf
  int v36; // [esp+10h] [ebp-210h]
  float v37[4]; // [esp+34h] [ebp-1ECh] BYREF
  float v38[4]; // [esp+44h] [ebp-1DCh] BYREF
  float v39; // [esp+54h] [ebp-1CCh]
  float v40; // [esp+58h] [ebp-1C8h]
  float v41; // [esp+5Ch] [ebp-1C4h]
  float v42; // [esp+64h] [ebp-1BCh]
  float v43; // [esp+68h] [ebp-1B8h]
  float v44; // [esp+6Ch] [ebp-1B4h]
  float v45; // [esp+78h] [ebp-1A8h]
  int v46; // [esp+7Ch] [ebp-1A4h]
  float *v47; // [esp+80h] [ebp-1A0h]
  float v48; // [esp+84h] [ebp-19Ch] BYREF
  float v49; // [esp+88h] [ebp-198h]
  float v50; // [esp+8Ch] [ebp-194h]
  int v51; // [esp+90h] [ebp-190h]
  float v52; // [esp+94h] [ebp-18Ch] BYREF
  float v53; // [esp+98h] [ebp-188h]
  float v54; // [esp+9Ch] [ebp-184h]
  int v55; // [esp+A0h] [ebp-180h]
  float v56; // [esp+A4h] [ebp-17Ch] BYREF
  float v57; // [esp+A8h] [ebp-178h]
  float v58; // [esp+ACh] [ebp-174h]
  float v59[4]; // [esp+B4h] [ebp-16Ch] BYREF
  float v60; // [esp+C4h] [ebp-15Ch] BYREF
  float v61; // [esp+C8h] [ebp-158h]
  float v62; // [esp+CCh] [ebp-154h]
  float v63; // [esp+D4h] [ebp-14Ch]
  float v64; // [esp+D8h] [ebp-148h]
  float v65; // [esp+DCh] [ebp-144h]
  int v66; // [esp+E0h] [ebp-140h]
  float v67; // [esp+E4h] [ebp-13Ch]
  float v68; // [esp+E8h] [ebp-138h]
  float v69; // [esp+ECh] [ebp-134h]
  int v70; // [esp+F0h] [ebp-130h]
  float v71; // [esp+F4h] [ebp-12Ch]
  float v72; // [esp+F8h] [ebp-128h]
  float v73; // [esp+FCh] [ebp-124h]
  int v74; // [esp+100h] [ebp-120h]
  float v75; // [esp+104h] [ebp-11Ch]
  float v76; // [esp+108h] [ebp-118h]
  float v77; // [esp+10Ch] [ebp-114h]
  int v78; // [esp+110h] [ebp-110h]
  int n8; // [esp+118h] [ebp-108h]
  int *v80; // [esp+11Ch] [ebp-104h]
  int v81; // [esp+120h] [ebp-100h]
  float v82; // [esp+124h] [ebp-FCh]
  float v83; // [esp+128h] [ebp-F8h]
  float *v84; // [esp+12Ch] [ebp-F4h]
  float v85; // [esp+130h] [ebp-F0h]
  BOOL v86; // [esp+134h] [ebp-ECh]
  int n8_1; // [esp+138h] [ebp-E8h]
  float v88; // [esp+13Ch] [ebp-E4h]
  int n2_1; // [esp+140h] [ebp-E0h]
  _BYTE v90[64]; // [esp+144h] [ebp-DCh] BYREF
  float v91[16]; // [esp+184h] [ebp-9Ch] BYREF
  float v92[20]; // [esp+1C4h] [ebp-5Ch] BYREF
  _DWORD v93[3]; // [esp+214h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+220h] [ebp+0h]

  v93[0] = a2;
  v93[1] = retaddr;
  v7 = a1;
  v46 = a1;
  v80 = a3;
  v92[0] = *a4;
  v92[1] = a4[1];
  v92[2] = a4[2];
  v92[3] = a4[3];
  v92[4] = a4[4];
  v92[5] = a4[5];
  v92[6] = a4[6];
  v92[7] = a4[7];
  v92[8] = a4[8];
  v92[9] = a4[9];
  v92[10] = a4[10];
  v92[11] = a4[11];
  v92[12] = a4[12];
  v92[13] = a4[13];
  v92[14] = a4[14];
  v92[15] = a4[15];
  v91[0] = *a5;
  v91[1] = a5[1];
  v91[2] = a5[2];
  v91[3] = a5[3];
  v91[4] = a5[4];
  v91[5] = a5[5];
  v91[6] = a5[6];
  v91[7] = a5[7];
  v91[8] = a5[8];
  v91[9] = a5[9];
  v8 = a6;
  v91[10] = a5[10];
  v91[11] = a5[11];
  v91[12] = a5[12];
  v91[13] = a5[13];
  v91[14] = a5[14];
  v91[15] = a5[15];
  v84 = a6;
  sub_97D980(v92, v91, 1.0, &v60, &v56);
  sub_6035C0(v90);
  sub_5FE290(v59);
  sub_603C50(v59);
  result = sub_9683D0(v90, &v60, &v56, 1.0, v38, v37);
  v10 = 0;
  v81 = 0;
  if ( *(int *)(v7 + 276) > 0 )
  {
    do
    {
      v11 = *(float *)(*(_DWORD *)(v7 + 284) + 4 * v10);
      v36 = *(_DWORD *)(LODWORD(v11) + 200);
      v12 = *(int (__thiscall **)(float *, int))(*(_DWORD *)v8 + 4);
      v45 = v11;
      result = v12(v8, v36);
      if ( (_BYTE)result )
      {
        v13 = *(int **)(LODWORD(v11) + 204);
        v14 = *v13;
        v47 = (float *)(LODWORD(v11) + 16);
        (*(void (__thiscall **)(int *, int, float *, float *))(v14 + 4))(v13, LODWORD(v11) + 16, &v48, &v52);
        v78 = 0;
        v74 = 0;
        v66 = 0;
        v75 = v38[0] + v48;
        v48 = v75;
        v76 = v38[1] + v49;
        v49 = v76;
        v77 = v38[2] + v50;
        v50 = v77;
        v51 = 0;
        v71 = v37[0] + v52;
        v52 = v71;
        v72 = v37[1] + v53;
        v53 = v72;
        v73 = v37[2] + v54;
        v54 = v73;
        v55 = 0;
        v39 = v71 - v75;
        v40 = v72 - v76;
        v41 = v73 - v77;
        v63 = v39 * 0.5;
        v64 = v40 * 0.5;
        v65 = 0.5 * v41;
        v42 = v75 + v71;
        v70 = 0;
        v43 = v72 + v76;
        v44 = v77 + v73;
        v60 = v42 * 0.5;
        v61 = v43 * 0.5;
        v62 = 0.5 * v44;
        v67 = a4[12] - v60;
        v68 = a4[13] - v61;
        result = (int)a5;
        v69 = a4[14] - v62;
        v56 = a5[12] - v60;
        v57 = a5[13] - v61;
        v58 = a5[14] - v62;
        *(float *)&n8_1 = -v63;
        v86 = *(float *)&n8_1 > (double)v67;
        n8 = 8;
        if ( v67 <= (double)v63 )
          n8 = 0;
        v15 = v64;
        *(float *)&n2_1 = -v64;
        v16 = v68;
        if ( *(float *)&n2_1 <= (double)v68 )
          n2 = 0;
        else
          n2 = 2;
        if ( v16 <= v15 )
          n16 = 0;
        else
          n16 = 16;
        v19 = v65;
        v88 = -v65;
        v20 = v69;
        if ( v88 <= (double)v69 )
          n4 = 0;
        else
          n4 = 4;
        if ( v20 <= v19 )
          n32 = 0;
        else
          n32 = 32;
        v23 = v86 | n8 | n2 | n16 | n4 | n32;
        v86 = *(float *)&n8_1 > (double)v56;
        n8_1 = 8;
        if ( v56 <= (double)v63 )
          *(float *)&n8_1 = 0.0;
        v24 = v57;
        v25 = *(float *)&n2_1;
        n2_1 = 2;
        if ( v25 <= v57 )
          *(float *)&n2_1 = 0.0;
        if ( v24 <= v15 )
          n16_1 = 0;
        else
          n16_1 = 16;
        if ( v88 <= (double)v58 )
          n4_1 = 0;
        else
          n4_1 = 4;
        if ( v58 <= v19 )
          n32_1 = 0;
        else
          n32_1 = 32;
        v29 = v86 | n8_1 | n2_1 | n16_1 | n4_1 | n32_1;
        if ( (v29 & v23) != 0 )
        {
          v8 = v84;
        }
        else
        {
          v83 = 0.0;
          v85 = 1.0;
          v59[3] = 0.0;
          v59[0] = v56 - v67;
          v82 = 1.0;
          v30 = 1;
          n2_1 = 2;
          v59[1] = v24 - v16;
          v59[2] = v58 - v20;
          v31 = 0.0;
          v32 = 1.0;
          do
          {
            v33 = v82;
            for ( i = 0; i != 3; ++i )
            {
              if ( (v30 & v23) != 0 )
              {
                v88 = (-*(float *)((char *)&v67 + i * 4) - *(float *)((char *)&v63 + i * 4) * v33) / v59[i];
                if ( v88 >= v31 )
                {
                  v83 = v88;
                  v31 = v88;
                }
              }
              else if ( (v30 & v29) != 0 )
              {
                v88 = (-*(float *)((char *)&v67 + i * 4) - *(float *)((char *)&v63 + i * 4) * v33) / v59[i];
                if ( v32 > v88 )
                {
                  v85 = v88;
                  v32 = v88;
                }
              }
              v30 *= 2;
            }
            v35 = n2_1-- == 1;
            v82 = -1.0;
          }
          while ( !v35 );
          v8 = v84;
          if ( v32 >= v31 )
            result = sub_982C40((int)v93, v80, v92, v91, v45, *(int **)(LODWORD(v45) + 204), v47, v84, a7);
        }
      }
      v7 = v46;
      v10 = v81 + 1;
      v81 = v10;
    }
    while ( v10 < *(_DWORD *)(v46 + 276) );
  }
  return result;
}
