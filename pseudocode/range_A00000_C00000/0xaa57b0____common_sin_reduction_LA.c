// Function: ___common_sin_reduction_LA
// Address: 0xaa57b0
// Size: 0x2ef
// Prototype: 

signed int __cdecl __common_sin_reduction_LA(double a1, double *a2)
{
  signed int v2; // edi
  int v3; // ecx
  int v4; // esi
  unsigned __int64 v5; // st7
  double v6; // st6
  double v7; // st5
  double v8; // st4
  __int64 v9; // kr00_8
  double v11; // [esp+0h] [ebp-60h]
  double v12; // [esp+10h] [ebp-50h]
  double v13; // [esp+10h] [ebp-50h]
  double v14; // [esp+20h] [ebp-40h]
  double v15; // [esp+40h] [ebp-20h]
  double v16; // [esp+48h] [ebp-18h]
  double v17; // [esp+48h] [ebp-18h]
  double v18; // [esp+48h] [ebp-18h]

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
      LODWORD(v12) = LODWORD(a1);
      HIDWORD(v12) = HIDWORD(a1) - 209715200;
      v4 = (v3 - 1052) / 25;
      *(_QWORD *)&v11 = *(_QWORD *)&v12 & 0xFFFFFFC000000000uLL;
      v5 = *(_QWORD *)&v12 & 0xFFFFFFC000000000uLL;
      v14 = v12 - COERCE_DOUBLE(*(_QWORD *)&v12 & 0xFFFFFFC000000000uLL);
      if ( -25 * v4 + v3 - 1052 < 17 )
      {
        v17 = 0.0;
      }
      else
      {
        v6 = dbl_25D8400[v4];
        v7 = dbl_25D8408[v4++];
        v17 = v6 * v14
            + v7 * *(double *)&v5
            - COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v6 * v14 + v7 * *(double *)&v5) & 0xFFFFFFC000000000uLL);
      }
      v8 = dbl_25D8408[v4];
      v13 = *(double *)&v5 * dbl_25D8410[v4] + v14 * v8;
      v18 = dbl_25D8400[v4] * v14 + *(double *)&v5 * v8 + v17;
      v15 = v13 + v18;
      v9 = __common_srl(
             COERCE_UNSIGNED_INT64(v13 + v18),
             HIDWORD(COERCE_UNSIGNED_INT64(v13 + v18)),
             1075 - ((HIDWORD(v15) >> 20) & 0x7FF))
         + 1;
      v2 = v9 & 0xFFFFFFFE;
      v16 = (v18
           - COERCE_DOUBLE(__common_sll((unsigned int)v9 & 0xFFFFFFFE, HIDWORD(v9), 1075 - ((HIDWORD(v15) >> 20) & 0x7FF)))
           + v13
           + dbl_25D8418[v4] * v11
           + dbl_25D8410[v4] * v14
           + dbl_25D8418[v4] * v14
           + dbl_25D8420[v4] * v11
           + dbl_25D8428[v4] * v11
           + dbl_25D8420[v4] * v14
           + dbl_25D8428[v4] * v14
           + dbl_25D8430[v4] * v11
           + dbl_25D8430[v4] * v14
           + v11 * dbl_25D8438[v4])
          * -8.87960937049345e43;
    }
    else
    {
      v2 = ((int)(-3.347575643058099e-140 * a1) + 1) & 0xFFFFFFFE;
      v16 = a1
          - 1.570796325802803 * (double)v2
          - 9.920935739593517e-10 * (double)v2
          - 5.721188709663575e-18 * (double)v2
          - (double)v2 * 1.644625693632426e-26;
    }
    *a2 = v16;
    return v2 << 30;
  }
}

