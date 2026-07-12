// Function: sub_998EF0
// Address: 0x998ef0
int __userpurge sub_998EF0@<eax>(_DWORD *a1@<ecx>, int a2@<ebp>, int a3, int n1065353216_2, int a5)
{
  int v6; // ecx
  int v7; // edi
  float *v8; // eax
  int v9; // ecx
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st6
  double v14; // st5
  double v15; // st6
  double v16; // st7
  double v17; // st6
  int v18; // eax
  double v19; // st5
  double v20; // st4
  double v21; // st3
  double v22; // st5
  double v23; // st6
  double v24; // st5
  double v25; // st7
  double v26; // st6
  double v27; // st4
  int v28; // eax
  double v29; // st3
  double v30; // rt1
  double v31; // st6
  double v32; // st5
  double v33; // st7
  double v34; // st6
  double v35; // st5
  double v36; // st4
  double v37; // st3
  int v38; // eax
  int result; // eax
  int v40; // xmm0_4
  int (__thiscall *v41)(int, int, int, int); // eax
  int v42; // eax
  _DWORD *v43; // ecx
  int v44; // edx
  int v45; // edi
  int v46; // [esp-3Ch] [ebp-13Ch]
  int v47; // [esp-38h] [ebp-138h]
  int v48; // [esp-34h] [ebp-134h]
  int n1065353216; // [esp-1Ch] [ebp-11Ch] BYREF
  int n1065353216_1; // [esp-18h] [ebp-118h]
  int v51; // [esp-14h] [ebp-114h]
  int v52; // [esp-10h] [ebp-110h]
  int v53; // [esp+0h] [ebp-100h]
  float v54; // [esp+4h] [ebp-FCh] BYREF
  float v55; // [esp+8h] [ebp-F8h]
  float v56; // [esp+Ch] [ebp-F4h]
  int v57; // [esp+10h] [ebp-F0h]
  float v58; // [esp+14h] [ebp-ECh] BYREF
  float v59; // [esp+18h] [ebp-E8h]
  float v60; // [esp+1Ch] [ebp-E4h]
  int v61; // [esp+20h] [ebp-E0h]
  float *v62; // [esp+24h] [ebp-DCh]
  float v63; // [esp+28h] [ebp-D8h]
  float v64; // [esp+2Ch] [ebp-D4h]
  float v65; // [esp+30h] [ebp-D0h]
  float v66; // [esp+34h] [ebp-CCh]
  float v67; // [esp+38h] [ebp-C8h]
  float v68; // [esp+3Ch] [ebp-C4h]
  float v69; // [esp+40h] [ebp-C0h]
  float v70; // [esp+44h] [ebp-BCh]
  float v71; // [esp+48h] [ebp-B8h]
  float v72; // [esp+4Ch] [ebp-B4h]
  float v73; // [esp+50h] [ebp-B0h]
  float v74; // [esp+54h] [ebp-ACh]
  float v75; // [esp+58h] [ebp-A8h]
  float v76; // [esp+5Ch] [ebp-A4h]
  float v77; // [esp+60h] [ebp-A0h]
  _DWORD v78[35]; // [esp+64h] [ebp-9Ch] BYREF
  int v79; // [esp+F0h] [ebp-10h]
  int v80; // [esp+F4h] [ebp-Ch]
  void *v81; // [esp+F8h] [ebp-8h]
  int v82; // [esp+FCh] [ebp-4h] BYREF
  void *retaddr; // [esp+100h] [ebp+0h]

  v80 = a2;
  v81 = retaddr;
  v79 = -1;
  v78[34] = &loc_AD92EB;
  v78[33] = NtCurrentTeb()->NtTib.ExceptionList;
  v78[32] = &v82;
  v6 = a1[14];
  v7 = a1[13];
  v8 = (float *)a1[2];
  v53 = v7;
  v62 = v8;
  if ( v6 )
  {
    v9 = *(_DWORD *)(v6 + 20);
    if ( v9 )
    {
      if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v9 + 44))(v9) & 1) != 0 )
      {
        v10 = v62[13];
        n1065353216 = 1065353216;
        v68 = v10;
        n1065353216_1 = 1065353216;
        v11 = *(float *)(a3 + 20);
        v51 = 0;
        v72 = v11;
        v52 = 0;
        v67 = v62[12];
        v74 = *(float *)(a3 + 16);
        v65 = v62[14];
        v71 = *(float *)(a3 + 24);
        v70 = v62[18];
        v12 = v74;
        v13 = v72;
        v14 = v71;
        v74 = v68 * v72 + v74 * v67 + v71 * v65;
        v77 = v74 + v70;
        v64 = v62[9];
        v66 = v62[8];
        v63 = v62[10];
        v74 = v62[17];
        v72 = v66 * v12 + v64 * v72 + v63 * v71;
        v75 = v72 + v74;
        v71 = v62[5];
        v69 = v62[4];
        v72 = v62[6];
        v73 = v62[16];
        v15 = v14 * v72 + v13 * v71 + v12 * v69;
        v16 = v72;
        v72 = v15;
        v59 = v75;
        v17 = v73;
        v18 = a1[14];
        v58 = v72 + v73;
        v60 = v77;
        v19 = *(float *)(a3 + 4);
        v61 = 0;
        v77 = v19;
        v57 = 0;
        v75 = *(float *)a3;
        v73 = *(float *)(a3 + 8);
        v20 = v77;
        v21 = v75;
        v22 = v73;
        v77 = v68 * v77 + v75 * v67 + v73 * v65;
        v73 = v77 + v70;
        v56 = v73;
        v77 = v75 * v66 + v20 * v64 + v22 * v63;
        v75 = v77 + v74;
        v77 = v16 * v22 + v20 * v71 + v21 * v69;
        v54 = v17 + v77;
        v55 = v75;
        (*(void (__thiscall **)(_DWORD, float *, float *, int *))(**(_DWORD **)(v18 + 20) + 8))(
          *(_DWORD *)(v18 + 20),
          &v54,
          &v58,
          &n1065353216);
        v68 = v62[13];
        v77 = *(float *)(a3 + 36);
        v67 = v62[12];
        v75 = *(float *)(a3 + 32);
        v65 = v62[14];
        v57 = 0;
        v73 = *(float *)(a3 + 40);
        v74 = v62[18];
        v23 = v77;
        v24 = v75;
        v25 = v73;
        v77 = v68 * v77 + v75 * v67 + v73 * v65;
        v76 = v77 + v74;
        v64 = v62[9];
        v66 = v62[8];
        v63 = v62[10];
        v70 = v62[17];
        v77 = v75 * v66 + v23 * v64 + v73 * v63;
        v73 = v77 + v70;
        v71 = v62[5];
        v55 = v73;
        v69 = v62[4];
        v56 = v76;
        v72 = v62[6];
        v75 = v62[16];
        v77 = v25 * v72 + v23 * v71 + v24 * v69;
        v26 = v75;
        v54 = v77 + v75;
        v76 = *(float *)(a3 + 20);
        v77 = *(float *)(a3 + 16);
        v75 = *(float *)(a3 + 24);
        v27 = v76;
        v28 = a1[14];
        v29 = v77;
        v61 = 0;
        v30 = v75;
        v76 = v68 * v76 + v77 * v67 + v75 * v65;
        v75 = v76 + v74;
        v60 = v75;
        v76 = v77 * v66 + v27 * v64 + v30 * v63;
        v77 = v76 + v70;
        v76 = v72 * v30 + v27 * v71 + v29 * v69;
        v58 = v26 + v76;
        v59 = v77;
        (*(void (__thiscall **)(_DWORD, float *, float *, int *))(**(_DWORD **)(v28 + 20) + 8))(
          *(_DWORD *)(v28 + 20),
          &v58,
          &v54,
          &n1065353216);
        v68 = v62[13];
        v76 = *(float *)(a3 + 4);
        v67 = v62[12];
        v77 = *(float *)a3;
        v65 = v62[14];
        v75 = *(float *)(a3 + 8);
        v74 = v62[18];
        v31 = v76;
        v32 = v77;
        v33 = v75;
        v76 = v68 * v76 + v77 * v67 + v75 * v65;
        v57 = 0;
        v73 = v76 + v74;
        v64 = v62[9];
        v66 = v62[8];
        v63 = v62[10];
        v70 = v62[17];
        v76 = v77 * v66 + v31 * v64 + v75 * v63;
        v75 = v76 + v70;
        v71 = v62[5];
        v55 = v75;
        v69 = v62[4];
        v56 = v73;
        v72 = v62[6];
        v77 = v62[16];
        v76 = v33 * v72 + v31 * v71 + v32 * v69;
        v34 = v77;
        v54 = v76 + v77;
        v77 = *(float *)(a3 + 36);
        v76 = *(float *)(a3 + 32);
        v75 = *(float *)(a3 + 40);
        v35 = v76;
        v36 = v77;
        v37 = v75;
        v76 = v68 * v77 + v76 * v67 + v75 * v65;
        v75 = v76 + v74;
        v38 = a1[14];
        v60 = v75;
        v61 = 0;
        v76 = v35 * v66 + v77 * v64 + v37 * v63;
        v77 = v76 + v70;
        v76 = v72 * v37 + v36 * v71 + v35 * v69;
        v58 = v34 + v76;
        v59 = v77;
        (*(void (__thiscall **)(_DWORD, float *, float *, int *))(**(_DWORD **)(v38 + 20) + 8))(
          *(_DWORD *)(v38 + 20),
          &v58,
          &v54,
          &n1065353216);
      }
    }
  }
  result = *(_DWORD *)(a1[1] + 204);
  if ( *(int *)(result + 4) < 20 )
  {
    sub_9976E0(v78, (_DWORD *)a3, (_DWORD *)(a3 + 16), (_DWORD *)(a3 + 32));
    v40 = a1[15];
    v76 = v62[51];
    *((_DWORD *)v62 + 51) = v78;
    v48 = a1[17];
    v47 = a1[2];
    v41 = *(int (__thiscall **)(int, int, int, int))(*(_DWORD *)v7 + 4);
    v46 = a1[1];
    v79 = 0;
    v78[12] = v40;
    v42 = v41(v7, v46, v47, v48);
    v43 = (_DWORD *)a1[12];
    v51 = a5;
    v44 = v43[36];
    n1065353216_1 = n1065353216_2;
    v45 = v42;
    if ( v44 == a1[2] )
      (*(void (__thiscall **)(_DWORD *, int, int))(*v43 + 4))(v43, n1065353216_1, v51);
    else
      (*(void (__thiscall **)(_DWORD *, int, int))(*v43 + 8))(v43, n1065353216_1, v51);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v45 + 4))(
      v45,
      a1[1],
      a1[2],
      a1[14],
      a1[12]);
    (**(void (__thiscall ***)(int, _DWORD))v45)(v45, 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v53 + 48))(v53, v45);
    v62[51] = v76;
    v79 = -1;
    v78[0] = &btConvexInternalShape::`vftable';
    return sub_968890(v78);
  }
  return result;
}
