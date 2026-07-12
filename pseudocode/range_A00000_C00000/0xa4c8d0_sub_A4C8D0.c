// Function: sub_A4C8D0
// Address: 0xa4c8d0
// Size: 0x550
// Prototype: 

void __usercall sub_A4C8D0(int a1@<ebp>)
{
  int v1; // edi
  float v2; // eax
  double v3; // st6
  double v4; // st7
  double v5; // st5
  double v6; // st4
  double v7; // st3
  int n7; // esi
  double v9; // st2
  int v10; // edi
  double v11; // rt1
  double v12; // rt0
  double v13; // st2
  double v14; // st7
  int v15; // ecx
  unsigned __int8 v16; // dl
  int v17; // [esp-154h] [ebp-160h]
  float v18; // [esp-150h] [ebp-15Ch]
  __int16 v19; // [esp-150h] [ebp-15Ch]
  int v20; // [esp-14Ch] [ebp-158h]
  float v21; // [esp-144h] [ebp-150h]
  int n4; // [esp-140h] [ebp-14Ch] BYREF
  _BYTE *v23; // [esp-13Ch] [ebp-148h]
  __int16 n72; // [esp-138h] [ebp-144h]
  char v25; // [esp-136h] [ebp-142h]
  int v26; // [esp-134h] [ebp-140h]
  int v27; // [esp-130h] [ebp-13Ch]
  int v28; // [esp-12Ch] [ebp-138h]
  int v29; // [esp-128h] [ebp-134h]
  int v30; // [esp-124h] [ebp-130h]
  _BYTE *v31; // [esp-120h] [ebp-12Ch]
  int v32; // [esp-11Ch] [ebp-128h]
  int v33; // [esp-118h] [ebp-124h]
  int v34; // [esp-114h] [ebp-120h]
  int v35; // [esp-108h] [ebp-114h]
  int v36; // [esp-104h] [ebp-110h]
  int v37; // [esp-100h] [ebp-10Ch]
  unsigned int *v38; // [esp-FCh] [ebp-108h]
  _BYTE v39[64]; // [esp-C8h] [ebp-D4h] BYREF
  unsigned int v40; // [esp-88h] [ebp-94h] BYREF
  float v41; // [esp-84h] [ebp-90h]
  float v42; // [esp-80h] [ebp-8Ch]
  float v43; // [esp-7Ch] [ebp-88h]
  unsigned int v44; // [esp-78h] [ebp-84h]
  float v45; // [esp-74h] [ebp-80h]
  float v46; // [esp-70h] [ebp-7Ch]
  float v47; // [esp-6Ch] [ebp-78h]
  unsigned int v48; // [esp-68h] [ebp-74h]
  float v49; // [esp-64h] [ebp-70h]
  float v50; // [esp-60h] [ebp-6Ch]
  float v51; // [esp-5Ch] [ebp-68h]
  unsigned int v52; // [esp-58h] [ebp-64h]
  float v53; // [esp-54h] [ebp-60h]
  float v54; // [esp-50h] [ebp-5Ch]
  float v55; // [esp-4Ch] [ebp-58h]
  float v56; // [esp-48h] [ebp-54h] BYREF
  float v57; // [esp-44h] [ebp-50h]
  float v58; // [esp-40h] [ebp-4Ch]
  float v59; // [esp-3Ch] [ebp-48h]
  unsigned int v60; // [esp-38h] [ebp-44h]
  float v61; // [esp-34h] [ebp-40h]
  float v62; // [esp-30h] [ebp-3Ch]
  float v63; // [esp-2Ch] [ebp-38h]
  unsigned int v64; // [esp-28h] [ebp-34h]
  float v65; // [esp-24h] [ebp-30h]
  float v66; // [esp-20h] [ebp-2Ch]
  float v67; // [esp-1Ch] [ebp-28h]
  unsigned int v68; // [esp-18h] [ebp-24h]
  float v69; // [esp-14h] [ebp-20h]
  float v70; // [esp-10h] [ebp-1Ch]
  float v71; // [esp-Ch] [ebp-18h]
  int v72; // [esp+0h] [ebp-Ch]
  void *v73; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v72 = a1;
  v73 = retaddr;
  n4 = 4;
  v20 = dword_2305834[0];
  v29 = dword_C86580[*(unsigned __int8 *)(dword_2305834[0] + 71100)];
  HIBYTE(v29) = *(char *)(dword_2305834[0] + 71109) / 3;
  n72 = 72;
  v31 = v39;
  v38 = &v40;
  v54 = 4.0;
  v42 = flt_C8F510;
  v46 = flt_C8F510;
  v50 = flt_C8F510;
  v58 = flt_C8F510;
  v62 = flt_C8F510;
  v66 = flt_C8F510;
  v70 = flt_C8F510;
  v30 = 0;
  v55 = 1.0;
  v25 = 0;
  v36 = 0;
  v35 = 0;
  v23 = byte_1740830;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v37 = 0;
  v34 = 0;
  v33 = 0;
  v32 = 0;
  v40 = unk_C8F508[0];
  v41 = flt_C8F50C;
  v43 = flt_C8F514[0];
  v44 = unk_C8F508[0];
  v45 = flt_C8F50C;
  v47 = flt_C8F514[0];
  v48 = unk_C8F508[0];
  v49 = flt_C8F50C;
  v51 = flt_C8F514[0];
  v52 = unk_C8F508[0];
  v53 = flt_C8F50C;
  v56 = *(float *)unk_C8F508;
  v57 = flt_C8F50C;
  v59 = flt_C8F514[0];
  v60 = unk_C8F508[0];
  v61 = flt_C8F50C;
  v63 = flt_C8F514[0];
  v64 = unk_C8F508[0];
  v65 = flt_C8F50C;
  v67 = flt_C8F514[0];
  v68 = unk_C8F508[0];
  v69 = flt_C8F50C;
  v71 = flt_C8F514[0];
  v1 = unk_23057FC;
  v18 = (*(float *)(dword_2305834[0] + 71076) * 3.0 + 125.0) * 0.0007812500116415322;
  v66 = v18;
  v61 = v18;
  v56 = v18;
  v68 = *(_DWORD *)(dword_2305834[0] + 70944);
  v2 = *(float *)(dword_2305834[0] + 70948);
  v70 = 0.0;
  v69 = v2;
  v71 = 1.0;
  sub_6ED700(v39, dword_2305834[0] + 70624, &v56);
  sub_A657C0(v1, &n4, 4);
  v17 = (unsigned __int16)(*(_WORD *)(dword_2305834[0] + 71320) << 11);
  v19 = *(_WORD *)(dword_2305834[0] + 80 * *(unsigned __int8 *)(dword_2305834[0] + 71100) + 69836);
  n72 = 72;
  v31 = v39;
  v38 = &v40;
  v54 = 3.0;
  v55 = 1.0;
  v30 = 0;
  v25 = 0;
  v36 = 0;
  v35 = 0;
  v23 = byte_1740830;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v37 = 0;
  v34 = 0;
  v33 = 0;
  v32 = 0;
  v40 = unk_C8F508[0];
  v41 = flt_C8F50C;
  v42 = flt_C8F510;
  v43 = flt_C8F514[0];
  v44 = unk_C8F508[0];
  v45 = flt_C8F50C;
  v46 = flt_C8F510;
  v47 = flt_C8F514[0];
  v48 = unk_C8F508[0];
  v49 = flt_C8F50C;
  v50 = flt_C8F510;
  v51 = flt_C8F514[0];
  v52 = unk_C8F508[0];
  v53 = flt_C8F50C;
  v56 = *(float *)unk_C8F508;
  v57 = flt_C8F50C;
  v70 = 0.0;
  v3 = 1.0;
  v4 = 0.0;
  v71 = 1.0;
  v60 = unk_C8F508[0];
  v5 = 2.0;
  v64 = unk_C8F508[0];
  v6 = 1.0;
  v68 = unk_C8F508[0];
  v7 = 16.0;
  n7 = 0;
  v9 = 0.001249999972060323;
  v58 = flt_C8F510;
  v59 = flt_C8F514[0];
  v61 = flt_C8F50C;
  v62 = flt_C8F510;
  v63 = flt_C8F514[0];
  v65 = flt_C8F50C;
  v66 = flt_C8F510;
  v67 = flt_C8F514[0];
  v69 = flt_C8F50C;
  n4 = 36;
  v10 = v20 + 69828;
  while ( 1 )
  {
    if ( n7 == 7 )
      v54 = v5;
    v12 = v9;
    v13 = v4;
    v14 = v12;
    if ( v13 < *(float *)v10 )
    {
      v15 = dword_2305834[0];
      if ( v19 != *(_WORD *)(v10 + 8) || n7 == *(unsigned __int8 *)(dword_2305834[0] + 71100) || n7 == 7 )
      {
        v29 = dword_C86660[n7];
        v16 = (int)(v7 * (v6 + flt_C44BE0[((v17 + (n7 << 13)) >> 4) & 0xFFF])) + 96;
        HIBYTE(v29) = v16;
        if ( v3 > *(float *)(dword_2305834[0] + 71156) )
        {
          v15 = dword_2305834[0];
          HIBYTE(v29) = (int)(*(float *)(dword_2305834[0] + 71156) * (double)v16);
        }
        v21 = v14 * *(float *)v10;
        v66 = v21;
        v61 = v21;
        v56 = v21;
        v68 = *(_DWORD *)(v10 - 60);
        v69 = *(float *)(v10 - 56);
        sub_6ED700(v39, v15 + 70624, &v56);
        sub_A657C0(unk_23057F8, &n4, 4);
        v6 = 1.0;
        v7 = 16.0;
        v14 = 0.001249999972060323;
        v3 = 1.0;
        v13 = 0.0;
        v5 = 2.0;
      }
    }
    ++n7;
    v10 += 80;
    if ( n7 >= 8 )
      break;
    v11 = v13;
    v9 = v14;
    v4 = v11;
  }
}

