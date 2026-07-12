// Function: ___common_cos_reduction_LA
// Address: 0xaa5b00
// Size: 0x2f0
// Prototype: 

unsigned int __cdecl __common_cos_reduction_LA(double a1, double *a2)
{
  int v2; // edi
  int v3; // ecx
  int v4; // esi
  unsigned __int64 v5; // st7
  double v6; // st6
  double v7; // st5
  double v8; // st4
  __int64 v9; // rax
  double v10; // rax
  double v12; // [esp+0h] [ebp-60h]
  double v13; // [esp+10h] [ebp-50h]
  double v14; // [esp+10h] [ebp-50h]
  double v15; // [esp+20h] [ebp-40h]
  double v16; // [esp+40h] [ebp-20h]
  double v17; // [esp+48h] [ebp-18h]
  double v18; // [esp+48h] [ebp-18h]
  double v19; // [esp+48h] [ebp-18h]

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
      v3 = (HIDWORD(a1) >> 20) & 0x7FF;
      LODWORD(v13) = LODWORD(a1);
      HIDWORD(v13) = HIDWORD(a1) - 209715200;
      v4 = (v3 - 1052) / 25;
      *(_QWORD *)&v12 = *(_QWORD *)&v13 & 0xFFFFFFC000000000uLL;
      v5 = *(_QWORD *)&v13 & 0xFFFFFFC000000000uLL;
      v15 = v13 - COERCE_DOUBLE(*(_QWORD *)&v13 & 0xFFFFFFC000000000uLL);
      if ( -25 * v4 + v3 - 1052 < 17 )
      {
        v18 = 0.0;
      }
      else
      {
        v6 = dbl_25D8400[v4];
        v7 = dbl_25D8408[v4++];
        v18 = v6 * v15
            + v7 * *(double *)&v5
            - COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v6 * v15 + v7 * *(double *)&v5) & 0xFFFFFFC000000000uLL);
      }
      v8 = dbl_25D8408[v4];
      v14 = *(double *)&v5 * dbl_25D8410[v4] + v15 * v8;
      v19 = dbl_25D8400[v4] * v15 + *(double *)&v5 * v8 + v18;
      v16 = v14 + v19;
      LODWORD(v9) = __common_srl(COERCE__INT64(v14 + v19), 51 - (HIDWORD(v16) >> 20));
      v2 = v9 | 1;
      LODWORD(v10) = __common_sll(v9 | 1, 51 - (HIDWORD(v16) >> 20));
      v17 = (v19
           - v10
           + v14
           + dbl_25D8418[v4] * v12
           + dbl_25D8410[v4] * v15
           + dbl_25D8418[v4] * v15
           + dbl_25D8420[v4] * v12
           + dbl_25D8428[v4] * v12
           + dbl_25D8420[v4] * v15
           + dbl_25D8428[v4] * v15
           + dbl_25D8430[v4] * v12
           + dbl_25D8430[v4] * v15
           + v12 * dbl_25D8438[v4])
          * -8.87960937049345e43;
    }
    else
    {
      v2 = (int)(-3.347575643058099e-140 * a1) | 1;
      v17 = a1
          - 1.570796325802803 * (double)v2
          - 9.920935739593517e-10 * (double)v2
          - 5.721188709663575e-18 * (double)v2
          - (double)v2 * 1.644625693632426e-26;
    }
    *a2 = v17;
    return ~(v2 << 30) & 0x80000000;
  }
}

