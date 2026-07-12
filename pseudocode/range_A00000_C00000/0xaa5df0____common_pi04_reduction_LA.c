// Function: ___common_pi04_reduction_LA
// Address: 0xaa5df0
// Size: 0x30a
// Prototype: 

int __cdecl __common_pi04_reduction_LA(double a1, double *a2)
{
  signed int v2; // edi
  double v3; // st7
  int v4; // ecx
  int v5; // esi
  unsigned __int64 v6; // st7
  double v7; // st6
  double v8; // st5
  double v9; // st6
  __int64 v10; // rax
  double v11; // rax
  int v12; // edi
  double v14; // [esp+0h] [ebp-60h]
  double v15; // [esp+10h] [ebp-50h]
  double v16; // [esp+10h] [ebp-50h]
  double v17; // [esp+20h] [ebp-40h]
  __int64 v18; // [esp+30h] [ebp-30h]
  double v19; // [esp+38h] [ebp-28h]
  double v20; // [esp+38h] [ebp-28h]
  double v21; // [esp+38h] [ebp-28h]

  if ( SHIDWORD(a1) >= 2146435072 )
  {
    *(_DWORD *)a2 = -1;
    *((_DWORD *)a2 + 1) = 0x7FFFFFFF;
    return 0;
  }
  else
  {
    if ( HIDWORD(a1) >= 0x40FF4000 )
    {
      v4 = (HIDWORD(a1) >> 20) & 0x7FF;
      LODWORD(v15) = LODWORD(a1);
      HIDWORD(v15) = HIDWORD(a1) - 209715200;
      v5 = (v4 - 1052) / 25;
      *(_QWORD *)&v14 = *(_QWORD *)&v15 & 0xFFFFFFC000000000uLL;
      v6 = *(_QWORD *)&v15 & 0xFFFFFFC000000000uLL;
      v17 = v15 - COERCE_DOUBLE(*(_QWORD *)&v15 & 0xFFFFFFC000000000uLL);
      if ( -25 * v5 + v4 - 1052 < 17 )
      {
        v20 = 0.0;
      }
      else
      {
        v7 = dbl_25D85A0[v5];
        v8 = dbl_25D85A8[v5++];
        v20 = v7 * v17
            + v8 * *(double *)&v6
            - COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v7 * v17 + v8 * *(double *)&v6) & 0xFFFFFFC000000000uLL);
      }
      v9 = dbl_25D85A8[v5];
      v16 = v9 * v17 + *(double *)&v6 * dbl_25D85B0[v5];
      v21 = dbl_25D85A0[v5] * v17 + *(double *)&v6 * v9 + v20;
      *(double *)&v18 = v16 + v21;
      LODWORD(v10) = __common_srl(v18, 51 - (HIDWORD(v18) >> 20));
      v2 = (v10 + 1) & 0xFFFFFFFE;
      LODWORD(v11) = __common_sll(__SPAIR64__((unsigned __int64)(v10 + 1) >> 32, v2), 51 - (HIDWORD(v18) >> 20));
      v3 = -8.87960937049345e43;
      v19 = (v14 * dbl_25D85D8[v5]
           + v17 * dbl_25D85D0[v5]
           + v16
           + v21
           - v11
           + dbl_25D85B8[v5] * v14
           + dbl_25D85B0[v5] * v17
           + dbl_25D85B8[v5] * v17
           + v14 * dbl_25D85C0[v5]
           + dbl_25D85C0[v5] * v17
           + v14 * dbl_25D85C8[v5]
           + dbl_25D85C8[v5] * v17
           + v14 * dbl_25D85D0[v5])
          * -8.87960937049345e43;
    }
    else
    {
      v2 = ((int)(-3.347575643058099e-140 * a1) + 1) & 0xFFFFFFFE;
      v3 = -8.87960937049345e43;
      v19 = a1
          - 0.7853981629014015 * (double)v2
          - 4.960467869796759e-10 * (double)v2
          - 2.860594354831787e-18 * (double)v2
          - (double)v2 * 8.223128468162129e-27;
    }
    v12 = v2 >> 1;
    if ( v19 > v3 )
    {
      v12 -= 3;
      v19 = v19 - -8.87960937049345e43;
    }
    *a2 = v19;
    return v12;
  }
}

