// Function: sub_A29770
// Address: 0xa29770
// Size: 0x6c9
// Prototype: 

int __thiscall sub_A29770(int this, unsigned int a2)
{
  int result; // eax
  char *v4; // ecx
  int v5; // eax
  char n10; // al
  int i; // edx
  int v8; // ebx
  int v9; // esi
  int v10; // esi
  float *v11; // ebx
  int v12; // esi
  bool v13; // zf
  int v14; // eax
  unsigned int v15; // ecx
  float v16; // eax
  int v17; // eax
  _DWORD *v18; // ecx
  int v19; // eax
  int v20; // ecx
  double v21; // st7
  double v22; // st7
  double v23; // st6
  double v24; // st4
  double v25; // st5
  double v26; // st7
  double v27; // st5
  double v28; // st4
  double v29; // st3
  double v30; // st4
  double v31; // st5
  double v32; // st4
  double v33; // st3
  double v34; // st5
  double v35; // st4
  double v36; // rt1
  double v37; // st4
  double v38; // st5
  double v39; // st4
  double v40; // st3
  double v41; // rt2
  double v42; // st3
  double v43; // st4
  double v44; // st5
  double v45; // st4
  double v46; // st3
  double v47; // st4
  double v48; // rt1
  int v49; // eax
  double v50; // st7
  double v51; // st7
  double v52; // st7
  int v53; // edx
  int v54; // edx
  float v55; // eax
  double v56; // st7
  double v57; // st7
  int v58; // eax
  int v59; // ebx
  double v60; // st7
  int v61; // esi
  int v62; // ebx
  int v63; // esi
  _DWORD *v64; // ebx
  int v65; // esi
  _DWORD v66[2]; // [esp+14h] [ebp-C4h] BYREF
  int v67; // [esp+1Ch] [ebp-BCh]
  unsigned int v68; // [esp+20h] [ebp-B8h]
  unsigned int v69; // [esp+24h] [ebp-B4h]
  int v70; // [esp+28h] [ebp-B0h]
  _DWORD v71[2]; // [esp+2Ch] [ebp-ACh] BYREF
  _DWORD v72[2]; // [esp+34h] [ebp-A4h] BYREF
  int v73; // [esp+3Ch] [ebp-9Ch]
  float v74; // [esp+40h] [ebp-98h]
  int v75; // [esp+44h] [ebp-94h]
  int v76; // [esp+48h] [ebp-90h] BYREF
  _DWORD *v77; // [esp+4Ch] [ebp-8Ch]
  int v78; // [esp+50h] [ebp-88h]
  float v79; // [esp+54h] [ebp-84h]
  unsigned int v80; // [esp+58h] [ebp-80h]
  int v81; // [esp+5Ch] [ebp-7Ch]
  int v82; // [esp+60h] [ebp-78h]
  float v83; // [esp+64h] [ebp-74h]
  char ArgList[4]; // [esp+68h] [ebp-70h]
  float v85; // [esp+6Ch] [ebp-6Ch]
  float v86; // [esp+70h] [ebp-68h]
  float v87[12]; // [esp+74h] [ebp-64h] BYREF
  _DWORD v88[12]; // [esp+A4h] [ebp-34h] BYREF

  if ( !a2 )
    return 0;
  v4 = *(char **)(this + 352);
  v5 = *(_DWORD *)(*(_DWORD *)(this + 344) + 48);
  *(float *)(this + 360) = 0.0;
  *(float *)(this + 364) = 0.0;
  v82 = v5;
  n10 = *v4;
  for ( i = 0; *v4; n10 = *v4 )
  {
    ++v4;
    if ( n10 == 10 )
      ++i;
  }
  v8 = *(_DWORD *)(this + 100);
  v70 = v8 + 64;
  v9 = 4 * (a2 - i);
  v67 = v8;
  result = sub_434D50(v72);
  if ( !result )
  {
    v81 = sub_434D50(v66);
    if ( v81 )
    {
      v10 = (*(_DWORD *)(v8 + 24) & 0x7FFFFFFF) != *(_DWORD *)(v8 + 16) + 1 ? *(_DWORD *)(v8 + 16) + 1 : 0;
      if ( !sub_564E10(v10, v72) )
      {
        *(_DWORD *)(v8 + 16) = v10;
        *(_BYTE *)(v8 + 20) = 0;
      }
      return v81;
    }
    v77 = 0;
    if ( *(_BYTE *)(this + 372) )
    {
      v77 = (_DWORD *)(*(_DWORD *)(this + 100) + 128);
      v81 = sub_434D50(v71);
      if ( v81 )
      {
        sub_4351B0(v71);
        return v81;
      }
      v77[1] = v9;
    }
    *(_DWORD *)(v8 + 4) = v9;
    *(_DWORD *)(v8 + 68) = v9;
    v11 = (float *)v66[0];
    v12 = 0;
    v13 = *(_BYTE *)(this + 372) == 0;
    v73 = v72[0];
    if ( !v13 )
      v12 = v71[0];
    v14 = *(_DWORD *)(v82 + 32);
    v15 = *(_DWORD *)(v14 + 28);
    v69 = *(_DWORD *)(v14 + 32);
    v76 = *(_DWORD *)(this + 352);
    v68 = v15;
    v16 = COERCE_FLOAT(sub_45D700(&v76));
    v79 = 0.0;
    v74 = 0.0;
    v85 = 0.0;
    *(float *)ArgList = v16;
    v83 = 0.0;
    v78 = 0;
    v81 = 0;
    while ( 1 )
    {
      if ( v16 == 0.0 )
      {
        v54 = v78;
LABEL_42:
        *(_DWORD *)(this + 112) = 6 * v54;
        if ( v54 )
          v58 = 4 * v54 - 1;
        else
          v58 = 0;
        v59 = v67;
        v60 = v74 + v79;
        *(_DWORD *)(this + 108) = v58;
        *(_DWORD *)(this + 104) = 0;
        *(float *)(this + 364) = v60 + *(float *)(this + 364);
        v61 = (*(_DWORD *)(v59 + 24) & 0x7FFFFFFF) != *(_DWORD *)(v59 + 16) + 1 ? *(_DWORD *)(v59 + 16) + 1 : 0;
        result = sub_564E10(v61, v72);
        if ( !result )
        {
          *(_DWORD *)(v59 + 16) = v61;
          *(_BYTE *)(v59 + 20) = 0;
          v62 = v70;
          v63 = (*(_DWORD *)(v70 + 24) & 0x7FFFFFFF) != *(_DWORD *)(v70 + 16) + 1 ? *(_DWORD *)(v70 + 16) + 1 : 0;
          result = sub_564E10(v63, v66);
          if ( !result )
          {
            *(_DWORD *)(v62 + 16) = v63;
            *(_BYTE *)(v62 + 20) = 0;
            if ( !*(_BYTE *)(this + 372) )
              return 0;
            v64 = v77;
            v65 = (v77[6] & 0x7FFFFFFF) != v77[4] + 1 ? v77[4] + 1 : 0;
            result = sub_564E10(v65, v71);
            if ( !result )
            {
              v64[4] = v65;
              *((_BYTE *)v64 + 20) = 0;
              return 0;
            }
          }
        }
        return result;
      }
      sub_A2BAB0(v87);
      v13 = (*(_DWORD *)(v82 + 16) & 0x7FFFFFFF) == 0;
      v80 = *(_DWORD *)(v82 + 16) & 0x7FFFFFFF;
      v87[0] = *(float *)ArgList;
      v17 = 0;
      if ( v13 )
      {
LABEL_24:
        v17 = -1;
      }
      else
      {
        v18 = *(_DWORD **)(v82 + 20);
        while ( *v18 != *(_DWORD *)ArgList )
        {
          ++v17;
          v18 += 12;
          if ( v17 >= v80 )
            goto LABEL_24;
        }
      }
      if ( *(_DWORD *)ArgList == 10 )
      {
        *(float *)&v80 = *(float *)(this + 368) * *(float *)(v82 + 8);
        v85 = 0.0;
        v83 = v83 - *(float *)&v80;
        v74 = *(float *)&v80 + v74;
        *(float *)(this + 364) = *(float *)(this + 364) + v79;
        v79 = 0.0;
        v16 = COERCE_FLOAT(sub_45D700(&v76));
        *(float *)ArgList = v16;
      }
      else
      {
        if ( v17 >= 0 )
        {
          v19 = *(_DWORD *)(v82 + 20) + 48 * v17;
          v20 = v73 + 32;
          v21 = *(float *)(v19 + 24);
          v75 = v19;
          *(float *)&v80 = v21;
          v73 = v20;
          v86 = *(float *)(v19 + 28);
          *(float *)ArgList = *(float *)(v19 + 32);
          v22 = *(float *)ArgList;
          v23 = v83;
          v83 = *(float *)ArgList + v83;
          v24 = v86 + v85;
          v86 = v24;
          *(float *)ArgList = v24 + *(float *)(v19 + 20);
          v25 = v22 - *(float *)&v80 + v23;
          v26 = v85;
          v85 = v25;
          v27 = v86;
          *(float *)(v20 - 32) = v86;
          v28 = v83;
          *(float *)(v20 - 28) = v83;
          v29 = *(float *)ArgList;
          *(float *)(v20 - 24) = *(float *)ArgList;
          *(float *)(v20 - 20) = v28;
          *(float *)(v20 - 16) = v29;
          v30 = v85;
          *(float *)(v20 - 12) = v85;
          *(float *)(v20 - 8) = v27;
          *(float *)(v20 - 4) = v30;
          if ( *(_BYTE *)(this + 372) )
          {
            v12 += 64;
            *(float *)(v12 - 64) = *(float *)(this + 376);
            *(float *)(v12 - 60) = *(float *)(this + 380);
            *(float *)(v12 - 56) = *(float *)(this + 384);
            *(float *)(v12 - 52) = *(float *)(this + 388);
            *(float *)(v12 - 48) = *(float *)(this + 376);
            *(float *)(v12 - 44) = *(float *)(this + 380);
            *(float *)(v12 - 40) = *(float *)(this + 384);
            *(float *)(v12 - 36) = *(float *)(this + 388);
            *(float *)(v12 - 32) = *(float *)(this + 392);
            *(float *)(v12 - 28) = *(float *)(this + 396);
            *(float *)(v12 - 24) = *(float *)(this + 400);
            *(float *)(v12 - 20) = *(float *)(this + 404);
            *(float *)(v12 - 16) = *(float *)(this + 392);
            *(float *)(v12 - 12) = *(float *)(this + 396);
            *(float *)(v12 - 8) = *(float *)(this + 400);
            *(float *)(v12 - 4) = *(float *)(this + 404);
          }
          v86 = (float)v68;
          v31 = v86;
          v83 = *(float *)(v19 + 12) / v86;
          v86 = (float)v69;
          v13 = *(_BYTE *)(v19 + 44) == 0;
          v32 = v86;
          *(float *)ArgList = *(float *)(v19 + 16) / v86;
          v33 = *(float *)(v19 + 12);
          if ( v13 )
          {
            v86 = (v33 + *(float *)(v19 + 20)) / v31;
            v85 = (*(float *)(v19 + 16) + *(float *)(v19 + 24)) / v32;
            v44 = v83;
            *v11 = v83;
            v45 = *(float *)ArgList;
            v11[1] = *(float *)ArgList;
            v46 = v86;
            v11[2] = v86;
            v11[3] = v45;
            v11[4] = v46;
            v47 = v85;
            v11[5] = v85;
            v48 = v47;
            v43 = v44;
            v38 = v48;
          }
          else
          {
            v85 = (v33 + *(float *)(v19 + 24)) / v31;
            v86 = (*(float *)(v19 + 16) + *(float *)(v19 + 20)) / v32;
            v34 = v83;
            *v11 = v83;
            v35 = *(float *)ArgList;
            v11[1] = *(float *)ArgList;
            v36 = v35;
            v37 = v34;
            v38 = v36;
            v11[2] = v37;
            v39 = v86;
            v11[3] = v86;
            v40 = v85;
            v11[4] = v85;
            v41 = v40;
            v42 = v39;
            v43 = v41;
            v11[5] = v42;
          }
          v11[6] = v43;
          v11 += 8;
          *(v11 - 1) = v38;
          v85 = v26 + *(float *)(v19 + 36);
          v83 = v23 + *(float *)(v19 + 40);
          *(float *)ArgList = COERCE_FLOAT(sub_45D700(&v76));
          if ( *(float *)ArgList != 0.0 )
          {
            sub_A2BAB0(v88);
            v88[0] = *(_DWORD *)ArgList;
            v49 = sub_A29320((_DWORD *)(v82 + 16), v88, 0);
            if ( v49 >= 0 )
            {
              v50 = sub_A29700((_DWORD *)this, v75, (_DWORD *)(*(_DWORD *)(v82 + 20) + 48 * v49));
              v85 = v50 + v85;
            }
          }
          v51 = v79;
          sub_512820(v79, *(float *)&v80);
          v79 = v51;
          v52 = *(float *)(this + 360);
          sub_512820(*(float *)(this + 360), v85);
          v53 = v78;
          *(float *)(this + 360) = v52;
          v16 = *(float *)ArgList;
          v54 = v53 + 1;
          v78 = v54;
          goto LABEL_39;
        }
        Phyre_DebugPrintf(
          2,
          "PBitmapFontText::createMeshGeometry: Warning - skipping unrenderable character with code '%d'. Check if this c"
          "haracter is included in the bitmap font data\n",
          *(_DWORD *)ArgList);
        v55 = COERCE_FLOAT(sub_45D700(&v76));
        v56 = *(float *)(this + 368);
        *(float *)ArgList = v55;
        *(float *)&v75 = v56 * *(float *)(v82 + 8);
        v85 = *(float *)&v75 * 0.5 + v85;
        v57 = *(float *)(this + 360);
        sub_512820(*(float *)(this + 360), v85);
        v16 = *(float *)ArgList;
        *(float *)(this + 360) = v57;
      }
      v54 = v78;
LABEL_39:
      if ( ++v81 >= a2 )
        goto LABEL_42;
    }
  }
  return result;
}

