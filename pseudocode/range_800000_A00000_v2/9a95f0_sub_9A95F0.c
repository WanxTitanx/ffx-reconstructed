// Function: sub_9A95F0
// Address: 0x9a95f0
char __userpurge sub_9A95F0@<al>(
        int a1@<ecx>,
        int a2@<ebp>,
        int a3,
        float *a4,
        float *a5,
        float *a6,
        void ***p_p_??_7CastResult@btConvexCast@@6B@)
{
  double v8; // st7
  double v9; // st7
  double v10; // st7
  float v11; // eax
  double v12; // st7
  double v13; // st6
  double v14; // st5
  double v15; // st4
  double v16; // st3
  void (__thiscall **p_??_7CastResult@btConvexCast@@6B@)(void ***, float); // eax
  void **v18; // xmm0_4
  float *v20; // [esp-8h] [ebp-1FCh]
  int v21; // [esp-4h] [ebp-1F8h]
  float v22; // [esp+18h] [ebp-1DCh] BYREF
  float v23; // [esp+78h] [ebp-17Ch]
  float v24; // [esp+88h] [ebp-16Ch]
  _DWORD v25[4]; // [esp+98h] [ebp-15Ch] BYREF
  float v26; // [esp+A8h] [ebp-14Ch]
  float v27; // [esp+ACh] [ebp-148h]
  float v28; // [esp+B0h] [ebp-144h]
  void **v29; // [esp+B4h] [ebp-140h]
  void **v30; // [esp+B8h] [ebp-13Ch]
  void **v31; // [esp+BCh] [ebp-138h]
  void **v32; // [esp+C0h] [ebp-134h]
  void **v33; // [esp+C4h] [ebp-130h]
  float k_v_][2]; // [esp+C8h] [ebp-12Ch] BYREF
  float v35; // [esp+E0h] [ebp-114h]
  int v36; // [esp+E4h] [ebp-110h]
  float v37; // [esp+E8h] [ebp-10Ch]
  float v38; // [esp+ECh] [ebp-108h]
  float v39; // [esp+F0h] [ebp-104h]
  float v40; // [esp+F4h] [ebp-100h]
  int v41; // [esp+F8h] [ebp-FCh] BYREF
  _DWORD v42[12]; // [esp+138h] [ebp-BCh] BYREF
  float v43; // [esp+168h] [ebp-8Ch]
  float v44; // [esp+16Ch] [ebp-88h]
  float v45; // [esp+170h] [ebp-84h]
  int v46; // [esp+174h] [ebp-80h]
  float v47; // [esp+178h] [ebp-7Ch]
  int v48; // [esp+17Ch] [ebp-78h]
  int v49; // [esp+180h] [ebp-74h]
  int v50; // [esp+184h] [ebp-70h]
  int v51; // [esp+188h] [ebp-6Ch]
  int v52; // [esp+18Ch] [ebp-68h]
  int v53; // [esp+190h] [ebp-64h]
  int v54; // [esp+194h] [ebp-60h]
  int v55; // [esp+198h] [ebp-5Ch]
  int v56; // [esp+19Ch] [ebp-58h]
  int v57; // [esp+1A0h] [ebp-54h]
  int v58; // [esp+1A4h] [ebp-50h]
  float v59; // [esp+1A8h] [ebp-4Ch]
  float v60; // [esp+1ACh] [ebp-48h]
  float v61; // [esp+1B0h] [ebp-44h]
  int v62; // [esp+1B4h] [ebp-40h]
  int n1566444395; // [esp+1B8h] [ebp-3Ch]
  int v64; // [esp+1BCh] [ebp-38h]
  int *v65; // [esp+1D8h] [ebp-1Ch]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+1DCh] [ebp-18h]
  void *v67; // [esp+1E0h] [ebp-14h]
  int v68; // [esp+1E4h] [ebp-10h]
  int v69; // [esp+1E8h] [ebp-Ch]
  void *v70; // [esp+1ECh] [ebp-8h]
  int v71; // [esp+1F0h] [ebp-4h] BYREF
  void *retaddr; // [esp+1F4h] [ebp+0h]

  v69 = a2;
  v70 = retaddr;
  v68 = -1;
  v67 = &loc_AD9B66;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v65 = &v71;
  sub_9B39F0(*(_DWORD *)(a1 + 4));
  v8 = a4[14] - *(float *)(a3 + 56);
  v39 = 0.0;
  v37 = v8;
  v38 = a4[13] - *(float *)(a3 + 52);
  v24 = a4[12] - *(float *)(a3 + 48);
  *(float *)&v36 = a6[14] - a5[14];
  v40 = a6[13] - a5[13];
  v23 = a6[12] - a5[12];
  v9 = v37;
  v37 = 0.0;
  v10 = v9 - *(float *)&v36;
  *(float *)&v36 = 0.0;
  v35 = v10;
  v38 = v38 - v40;
  v24 = v24 - v23;
  sub_6035C0(&v41);
  v25[0] = &btPointCollector::`vftable';
  strcpy((char *)k_v_], "k\v^]");
  v21 = *(_DWORD *)(a1 + 4);
  v20 = *(float **)(a1 + 12);
  v68 = 0;
  sub_9A8350(&v22, *(float **)(a1 + 8), v20, v21, 0);
  LOBYTE(v68) = 1;
  v42[0] = *(_DWORD *)a3;
  v42[1] = *(_DWORD *)(a3 + 4);
  v42[2] = *(_DWORD *)(a3 + 8);
  v42[3] = *(_DWORD *)(a3 + 12);
  v42[4] = *(_DWORD *)(a3 + 16);
  v42[5] = *(_DWORD *)(a3 + 20);
  v42[6] = *(_DWORD *)(a3 + 24);
  v42[7] = *(_DWORD *)(a3 + 28);
  v42[8] = *(_DWORD *)(a3 + 32);
  v42[9] = *(_DWORD *)(a3 + 36);
  v42[10] = *(_DWORD *)(a3 + 40);
  v42[11] = *(_DWORD *)(a3 + 44);
  v11 = *(float *)(a3 + 48);
  n1566444395 = 1566444395;
  v64 = 0;
  v43 = v11;
  v44 = *(float *)(a3 + 52);
  v45 = *(float *)(a3 + 56);
  v46 = *(_DWORD *)(a3 + 60);
  v47 = *a5;
  v48 = *((_DWORD *)a5 + 1);
  v49 = *((_DWORD *)a5 + 2);
  v50 = *((_DWORD *)a5 + 3);
  v51 = *((_DWORD *)a5 + 4);
  v52 = *((_DWORD *)a5 + 5);
  v53 = *((_DWORD *)a5 + 6);
  v54 = *((_DWORD *)a5 + 7);
  v55 = *((_DWORD *)a5 + 8);
  v56 = *((_DWORD *)a5 + 9);
  v57 = *((_DWORD *)a5 + 10);
  v58 = *((_DWORD *)a5 + 11);
  v59 = a5[12];
  v60 = a5[13];
  v61 = a5[14];
  v62 = *((_DWORD *)a5 + 15);
  sub_9A8450((int)v42, (int)v25, 0, 0);
  if ( LOBYTE(k_v_][1]) )
  {
    v12 = v24;
    v13 = v35;
    v14 = v38;
    if ( k_v_][0] <= 0.001 )
    {
LABEL_13:
      v40 = v12 * v26 + v14 * v27 + v13 * v28;
      if ( v40 < -*((float *)p_p_??_7CastResult@btConvexCast@@6B@ + 46) )
      {
LABEL_14:
        v18 = (void **)LODWORD(v39);
        *((float *)p_p_??_7CastResult@btConvexCast@@6B@ + 36) = v26;
        *((float *)p_p_??_7CastResult@btConvexCast@@6B@ + 37) = v27;
        *((float *)p_p_??_7CastResult@btConvexCast@@6B@ + 38) = v28;
        p_p_??_7CastResult@btConvexCast@@6B@[39] = v29;
        p_p_??_7CastResult@btConvexCast@@6B@[40] = v30;
        p_p_??_7CastResult@btConvexCast@@6B@[41] = v31;
        p_p_??_7CastResult@btConvexCast@@6B@[42] = v32;
        p_p_??_7CastResult@btConvexCast@@6B@[43] = v33;
        p_p_??_7CastResult@btConvexCast@@6B@[44] = v18;
        return 1;
      }
    }
    else
    {
      v15 = 1.0;
      v16 = v39;
      while ( ++v36 <= 32 )
      {
        v40 = v13 * v28 + v12 * v26 + v14 * v27;
        v40 = k_v_][0] / v40;
        v39 = v16 - v40;
        if ( v39 > v15 )
          break;
        if ( v39 < 0.0 )
          break;
        if ( v37 >= (double)v39 )
          break;
        p_??_7CastResult@btConvexCast@@6B@ = (void (__thiscall **)(void ***, float))*p_p_??_7CastResult@btConvexCast@@6B@;
        v37 = v39;
        (*p_??_7CastResult@btConvexCast@@6B@)(p_p_??_7CastResult@btConvexCast@@6B@, COERCE_FLOAT(LODWORD(v39)));
        v40 = 1.0 - v39;
        v43 = *(float *)(a3 + 48) * v40 + v39 * a4[12];
        v44 = *(float *)(a3 + 52) * v40 + a4[13] * v39;
        v45 = v40 * *(float *)(a3 + 56) + v39 * a4[14];
        v59 = a5[12] * v40 + a6[12] * v39;
        v60 = a5[13] * v40 + v39 * a6[13];
        v61 = v39 * a6[14] + v40 * a5[14];
        sub_9A8450((int)v42, (int)v25, 0, 0);
        if ( !LOBYTE(k_v_][1]) )
          break;
        if ( k_v_][0] < 0.0 )
          goto LABEL_14;
        if ( k_v_][0] <= 0.001 )
        {
          v12 = v24;
          v13 = v35;
          v14 = v38;
          goto LABEL_13;
        }
        v12 = v24;
        v13 = v35;
        v15 = 1.0;
        v16 = v39;
        v14 = v38;
      }
    }
  }
  return 0;
}
