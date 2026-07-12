// Function: sub_99AD00
// Address: 0x99ad00
double __thiscall sub_99AD00(int this, int a2, int a3, int a4, int a5)
{
  int v6; // ecx
  int v7; // eax
  int v8; // esi
  int v9; // ecx
  int v10; // edi
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  double v14; // st7
  double v15; // st5
  double v16; // st6
  double v17; // st6
  double v18; // st7
  double v19; // st5
  double v20; // st3
  int v21; // ecx
  double result; // st7
  float v23; // [esp-180h] [ebp-18Ch]
  int v24; // [esp-17Ch] [ebp-188h]
  float v25; // [esp-178h] [ebp-184h]
  int v26; // [esp-174h] [ebp-180h]
  float v27; // [esp-170h] [ebp-17Ch]
  float v28; // [esp-16Ch] [ebp-178h]
  float v29; // [esp-168h] [ebp-174h]
  int v30; // [esp-154h] [ebp-160h]
  int v31; // [esp-150h] [ebp-15Ch]
  float v32; // [esp-14Ch] [ebp-158h]
  int v33; // [esp-148h] [ebp-154h]
  float v34; // [esp-144h] [ebp-150h]
  int v35; // [esp-140h] [ebp-14Ch]
  float v36; // [esp-138h] [ebp-144h]
  float v37; // [esp-130h] [ebp-13Ch]
  float v38; // [esp-124h] [ebp-130h]
  float v39; // [esp-120h] [ebp-12Ch]
  float v40; // [esp-110h] [ebp-11Ch]
  float v41; // [esp-F8h] [ebp-104h]
  int v42; // [esp-F0h] [ebp-FCh]
  float v43; // [esp-ECh] [ebp-F8h]
  float v44; // [esp-E8h] [ebp-F4h]
  float v45; // [esp-D8h] [ebp-E4h]
  float v47; // [esp-D0h] [ebp-DCh]
  float v48; // [esp-C0h] [ebp-CCh]
  int v49; // [esp-B0h] [ebp-BCh]
  float v50; // [esp-ACh] [ebp-B8h]
  float v51; // [esp-A8h] [ebp-B4h]
  float v52; // [esp-A4h] [ebp-B0h]
  float v53; // [esp-A0h] [ebp-ACh]
  int v54; // [esp-A0h] [ebp-ACh]
  float v55; // [esp-9Ch] [ebp-A8h]
  float v56; // [esp-98h] [ebp-A4h]
  float v57; // [esp-94h] [ebp-A0h]
  float v58; // [esp-90h] [ebp-9Ch]
  float v59; // [esp-8Ch] [ebp-98h]
  float v60; // [esp-88h] [ebp-94h]
  float v61; // [esp-84h] [ebp-90h]
  float v62; // [esp-84h] [ebp-90h]
  float v63; // [esp-84h] [ebp-90h]
  float v64; // [esp-84h] [ebp-90h]
  float v65; // [esp-84h] [ebp-90h]
  float v66; // [esp-84h] [ebp-90h]
  float v67; // [esp-80h] [ebp-8Ch]

  v6 = a3;
  v7 = *(_DWORD *)(this + 12);
  v8 = a2;
  if ( *(_BYTE *)(this + 28) )
  {
    v8 = a3;
    v6 = a2;
  }
  v30 = v6;
  v9 = *(_DWORD *)(v8 + 204);
  v10 = 0;
  v31 = v9;
  v59 = 1.0;
  v33 = v7;
  if ( v7 <= 0 )
    return 1.0;
  v11 = 0;
  v49 = 0;
  do
  {
    v12 = *(_DWORD *)(v9 + 24);
    v13 = *(_DWORD *)(v11 + v12 + 64);
    v48 = *(float *)(v8 + 16);
    v34 = *(float *)(v8 + 20);
    v41 = *(float *)(v8 + 24);
    v24 = *(_DWORD *)(v8 + 28);
    v39 = *(float *)(v8 + 32);
    v32 = *(float *)(v8 + 36);
    v37 = *(float *)(v8 + 40);
    v26 = *(_DWORD *)(v8 + 44);
    v47 = *(float *)(v8 + 48);
    v45 = *(float *)(v8 + 52);
    v44 = *(float *)(v8 + 56);
    v42 = *(_DWORD *)(v8 + 60);
    v40 = *(float *)(v8 + 64);
    v38 = *(float *)(v8 + 68);
    v36 = *(float *)(v8 + 72);
    v35 = *(_DWORD *)(v8 + 76);
    v14 = *(float *)(v49 + v12 + 48);
    v15 = *(float *)(v49 + v12 + 52);
    v16 = *(float *)(v49 + v12 + 56);
    v61 = v41 * v16 + v14 * v48 + v15 * v34;
    v27 = v61 + v40;
    v62 = v39 * v14 + v32 * v15 + v37 * v16;
    v28 = v62 + v38;
    v63 = v16 * v44 + v15 * v45 + v14 * v47;
    v29 = v63 + v36;
    v52 = *(float *)(v49 + v12 + 24);
    v51 = *(float *)(v49 + v12 + 8);
    v55 = *(float *)(v49 + v12 + 40);
    v53 = v47 * v51 + v45 * v52 + v44 * v55;
    v58 = *(float *)(v49 + v12 + 20);
    v60 = *(float *)(v49 + v12 + 4);
    v64 = *(float *)(v49 + v12 + 36);
    v25 = v47 * v60 + v45 * v58 + v44 * v64;
    v17 = *(float *)(v49 + v12 + 16);
    v18 = *(float *)(v49 + v12 + 32);
    v19 = *(float *)(v49 + v12);
    v43 = v44 * v18 + v45 * v17 + v47 * v19;
    v23 = v39 * v51 + v32 * v52 + v37 * v55;
    v20 = v64;
    v65 = v37 * v64 + v32 * v58 + v39 * v60;
    v50 = v19 * v39 + v17 * v32 + v18 * v37;
    v57 = v51 * v48 + v52 * v34 + v41 * v55;
    v56 = v20 * v41 + v58 * v34 + v60 * v48;
    v67 = v18 * v41 + v17 * v34 + v19 * v48;
    *(float *)(v8 + 16) = v67;
    *(float *)(v8 + 20) = v56;
    *(float *)(v8 + 24) = v57;
    *(_DWORD *)(v8 + 28) = 0;
    *(float *)(v8 + 32) = v50;
    *(float *)(v8 + 36) = v65;
    *(float *)(v8 + 40) = v23;
    *(_DWORD *)(v8 + 44) = 0;
    *(float *)(v8 + 48) = v43;
    *(float *)(v8 + 52) = v25;
    *(float *)(v8 + 56) = v53;
    *(_DWORD *)(v8 + 60) = 0;
    *(float *)(v8 + 64) = v27;
    *(float *)(v8 + 68) = v28;
    *(float *)(v8 + 72) = v29;
    *(_DWORD *)(v8 + 76) = 0;
    v54 = *(_DWORD *)(v8 + 204);
    *(_DWORD *)(v8 + 204) = v13;
    v21 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v10);
    v66 = ((double (__thiscall *)(int, int, int, int, int))*(_DWORD *)(*(_DWORD *)v21 + 8))(v21, v8, v30, a4, a5);
    if ( v59 > (double)v66 )
      v59 = v66;
    result = v59;
    *(_DWORD *)(v8 + 204) = v54;
    *(float *)(v8 + 16) = v48;
    *(float *)(v8 + 20) = v34;
    *(float *)(v8 + 24) = v41;
    *(_DWORD *)(v8 + 28) = v24;
    *(float *)(v8 + 32) = v39;
    *(float *)(v8 + 36) = v32;
    *(float *)(v8 + 40) = v37;
    *(_DWORD *)(v8 + 44) = v26;
    *(float *)(v8 + 48) = v47;
    v9 = v31;
    *(float *)(v8 + 52) = v45;
    *(float *)(v8 + 56) = v44;
    *(_DWORD *)(v8 + 60) = v42;
    *(float *)(v8 + 64) = v40;
    *(float *)(v8 + 68) = v38;
    *(float *)(v8 + 72) = v36;
    ++v10;
    v11 = v49 + 80;
    *(_DWORD *)(v8 + 76) = v35;
    v49 += 80;
  }
  while ( v10 < v33 );
  return result;
}
