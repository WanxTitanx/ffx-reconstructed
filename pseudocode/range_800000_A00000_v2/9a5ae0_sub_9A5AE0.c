// Function: sub_9A5AE0
// Address: 0x9a5ae0
// bad sp value at call has been detected, the output may be wrong!
void __userpurge sub_9A5AE0(float *a1@<ecx>, int a2@<ebp>, float *a3, float a4, float a5)
{
  double v5; // st6
  double v6; // st7
  double v7; // st4
  double v8; // st3
  double v9; // st5
  double v10; // st4
  double v11; // st7
  double v12; // st3
  bool v13; // zf
  float v14; // eax
  float v15; // eax
  float v16; // [esp+10h] [ebp-D8h]
  float v17; // [esp+14h] [ebp-D4h]
  float v18; // [esp+18h] [ebp-D0h]
  float v19; // [esp+1Ch] [ebp-CCh]
  float v20; // [esp+20h] [ebp-C8h]
  float v21; // [esp+24h] [ebp-C4h]
  float v22; // [esp+28h] [ebp-C0h]
  float v23; // [esp+2Ch] [ebp-BCh]
  float v24; // [esp+30h] [ebp-B8h]
  float v25; // [esp+34h] [ebp-B4h]
  float v26; // [esp+38h] [ebp-B0h]
  float v27; // [esp+3Ch] [ebp-ACh] BYREF
  float v28; // [esp+40h] [ebp-A8h]
  float v29; // [esp+44h] [ebp-A4h]
  int v30; // [esp+48h] [ebp-A0h]
  float v31; // [esp+4Ch] [ebp-9Ch]
  float v32; // [esp+50h] [ebp-98h]
  float v33; // [esp+54h] [ebp-94h]
  float v34; // [esp+5Ch] [ebp-8Ch]
  float v35; // [esp+60h] [ebp-88h]
  float v36; // [esp+64h] [ebp-84h]
  float v37; // [esp+74h] [ebp-74h]
  float v38; // [esp+78h] [ebp-70h]
  float v39; // [esp+7Ch] [ebp-6Ch]
  float v40; // [esp+80h] [ebp-68h]
  float v41; // [esp+84h] [ebp-64h]
  float v42; // [esp+88h] [ebp-60h]
  float v43; // [esp+8Ch] [ebp-5Ch]
  float v44; // [esp+90h] [ebp-58h]
  float v45; // [esp+94h] [ebp-54h]
  int v46; // [esp+98h] [ebp-50h]
  float v47; // [esp+A8h] [ebp-40h]
  float v48; // [esp+ACh] [ebp-3Ch]
  float v49; // [esp+B0h] [ebp-38h]
  float v50; // [esp+B4h] [ebp-34h]
  float v51; // [esp+BCh] [ebp-2Ch] BYREF
  float v52; // [esp+C0h] [ebp-28h]
  float v53; // [esp+C4h] [ebp-24h]
  float v54; // [esp+D4h] [ebp-14h]
  float v55; // [esp+D8h] [ebp-10h]
  int v56; // [esp+DCh] [ebp-Ch]
  void *v57; // [esp+E0h] [ebp-8h]
  void *retaddr; // [esp+E8h] [ebp+0h]

  v56 = a2;
  v57 = retaddr;
  v26 = a3[4];
  v46 = 0;
  v42 = *a3;
  v48 = v26 - v42;
  v20 = a3[5];
  v38 = a3[1];
  v49 = v20 - v38;
  v18 = a3[6];
  v40 = a3[2];
  v50 = v18 - v40;
  v16 = a3[8];
  v34 = v16 - v42;
  v17 = a3[9];
  v35 = v17 - v38;
  v23 = a3[10];
  v36 = v23 - v40;
  v43 = v36 * v49 - v35 * v50;
  v27 = v43;
  v44 = v50 * v34 - v36 * v48;
  v28 = v44;
  v45 = v48 * v35 - v34 * v49;
  v29 = v45;
  v5 = v43;
  v30 = 0;
  v6 = v44;
  v47 = v40 * v45 + v38 * v44 + v42 * v43;
  v21 = a1[5];
  v22 = a1[4];
  v24 = a1[6];
  v54 = v22 * v43 + v21 * v44 + v24 * v45;
  v7 = v47;
  v39 = v54 - v47;
  v19 = a1[9];
  v25 = a1[8];
  v47 = a1[10];
  v54 = v25 * v43 + v19 * v44 + v47 * v45;
  v54 = v54 - v7;
  v8 = v39;
  if ( v54 * v39 < 0.0 && (((_BYTE)a1[12] & 1) == 0 || v39 <= 0.0) )
  {
    v54 = v8 - v54;
    v41 = v8 / v54;
    if ( a1[13] > (double)v41 )
    {
      v54 = v5 * v5 + v6 * v6 + v45 * v45;
      v37 = v54 * -0.00009999999747378752;
      v55 = 1.0 - v41;
      v48 = v22 * v55 + v25 * v41;
      v49 = v19 * v41 + v21 * v55;
      v50 = v41 * v47 + v55 * v24;
      v34 = v42 - v48;
      v35 = v38 - v49;
      v36 = v40 - v50;
      v31 = v26 - v48;
      v32 = v20 - v49;
      v33 = v18 - v50;
      v51 = v33 * v35 - v32 * v36;
      v9 = v35;
      v52 = v36 * v31 - v33 * v34;
      v53 = v34 * v32 - v31 * v35;
      v55 = v6 * v52 + v51 * v5 + v53 * v45;
      if ( v55 >= (double)v37 )
      {
        v51 = v16 - v48;
        v52 = v17 - v49;
        v53 = v23 - v50;
        v10 = v53;
        v11 = v52;
        v48 = v32 * v53 - v52 * v33;
        v12 = v51;
        v49 = v51 * v33 - v53 * v31;
        v50 = v52 * v31 - v51 * v32;
        v55 = v49 * v44 + v48 * v5 + v50 * v45;
        if ( v55 >= (double)v37 )
        {
          v51 = v11 * v36 - v10 * v9;
          v52 = v10 * v34 - v12 * v36;
          v53 = v9 * v12 - v11 * v34;
          v55 = v5 * v51 + v52 * v44 + v53 * v45;
          if ( v55 >= (double)v37 )
          {
            v55 = sqrt(v54);
            v13 = ((_BYTE)a1[12] & 2) == 0;
            v55 = 1.0 / v55;
            v27 = v43 * v55;
            v28 = v28 * v55;
            v29 = v55 * v29;
            if ( v13 && v39 > 0.0 )
            {
              v55 = a5;
              v14 = *a1;
              v54 = a4;
              a1[13] = ((double (__thiscall *)(float *, float *, _DWORD))*(_DWORD *)(LODWORD(v14) + 8))(
                         a1,
                         &v27,
                         LODWORD(v41));
            }
            else
            {
              v55 = a5;
              v15 = *a1;
              v54 = a4;
              a1[13] = ((double (__thiscall *)(float *, float *, _DWORD))*(_DWORD *)(LODWORD(v15) + 8))(
                         a1,
                         &v51,
                         LODWORD(v41));
            }
          }
        }
      }
    }
  }
}
