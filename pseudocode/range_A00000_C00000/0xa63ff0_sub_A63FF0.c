// Function: sub_A63FF0
// Address: 0xa63ff0
// Size: 0x9bc
// Prototype: 

int __cdecl sub_A63FF0(int a1, int a2, int n34307)
{
  int n3; // edi
  float *v4; // edx
  double v5; // st7
  double v6; // st6
  double v7; // st4
  double v8; // st5
  double v9; // st6
  double v10; // st4
  double v11; // st7
  double v12; // rt1
  double v13; // st6
  double v14; // st7
  double v15; // st5
  int v16; // ecx
  double v17; // rt2
  double v18; // st6
  double v19; // st7
  double v20; // st6
  double v21; // st7
  double v22; // st7
  double v23; // st7
  int n48; // ebx
  char *v25; // esi
  bool v26; // cc
  int v27; // ebx
  int v28; // edx
  int v29; // ecx
  int v30; // eax
  int n128; // edx
  int n128_1; // ecx
  int n128_2; // eax
  int n32; // edi
  int n32_1; // eax
  double v36; // st7
  double v37; // st7
  int v38; // ecx
  int v39; // ecx
  int result; // eax
  int v41; // esi
  float v42; // [esp+8h] [ebp-38h]
  float v43; // [esp+1Ch] [ebp-24h]
  int n48_1; // [esp+38h] [ebp-8h]
  float v45; // [esp+3Ch] [ebp-4h]
  float v46; // [esp+3Ch] [ebp-4h]
  float v47; // [esp+3Ch] [ebp-4h]
  float v48; // [esp+3Ch] [ebp-4h]
  float v49; // [esp+3Ch] [ebp-4h]
  int n48_2; // [esp+3Ch] [ebp-4h]

  n3 = n34307 & 3;
  v4 = (float *)((char *)&unk_22C9760 + 64 * n3);
  if ( (n34307 & 3) == 0 || n3 == 1 )
  {
    flt_22C96E0 = 0.0;
    unk_22C96E4 = -2.0;
    unk_22C96E8 = 0.0;
    unk_22C96EC = 1.0;
    flt_22C96F0 = 8.0;
    unk_22C96F4 = -2.0;
    unk_22C96F8 = 0.0;
    flt_22C9700 = 0.0;
    unk_22C96FC = 1.0;
    unk_22C9704 = 2.0;
    unk_22C9714 = 2.0;
    unk_22C9708 = 0.0;
    unk_22C9718 = 0.0;
    unk_22C970C = 1.0;
    unk_22C971C = 1.0;
    flt_22C9710 = 8.0;
    v5 = -2.0;
    v6 = 2.0;
    v7 = 1.0;
    v8 = 0.0;
  }
  else
  {
    flt_22C96E0 = -8.0;
    unk_22C96E4 = -2.0;
    unk_22C96E8 = 0.0;
    unk_22C96EC = 1.0;
    unk_22C96FC = 1.0;
    flt_22C96F0 = 0.0;
    unk_22C96F8 = 0.0;
    unk_22C96F4 = -2.0;
    v5 = -2.0;
    flt_22C9700 = -8.0;
    unk_22C9704 = 2.0;
    unk_22C9714 = 2.0;
    v6 = 2.0;
    unk_22C9708 = 0.0;
    flt_22C9710 = 0.0;
    unk_22C9718 = 0.0;
    v7 = 1.0;
    v8 = 0.0;
    unk_22C970C = 1.0;
    unk_22C971C = 1.0;
  }
  if ( (n34307 & 3) != 0 )
  {
    if ( n3 == 1 )
    {
      flt_22C96D0 = 38.0;
      unk_22C96D4 = v6;
      unk_22C96D8 = v8;
      v9 = v7;
      v11 = v8;
      unk_22C96DC = v7;
      goto LABEL_15;
    }
    if ( n3 != 2 )
    {
      if ( n3 == 3 )
      {
        flt_22C96D0 = -38.0;
        unk_22C96D4 = v6;
        unk_22C96D8 = v8;
        v9 = v7;
        v11 = v8;
        unk_22C96DC = v7;
      }
      else
      {
        v9 = v7;
        v11 = v8;
      }
      goto LABEL_15;
    }
    v9 = v7;
    v10 = -38.0;
  }
  else
  {
    v9 = v7;
    v10 = 38.0;
  }
  flt_22C96D0 = v10;
  unk_22C96D4 = v5;
  unk_22C96D8 = v8;
  v11 = v8;
  unk_22C96DC = v9;
LABEL_15:
  v12 = v9;
  v13 = v11;
  v14 = v12;
  flt_22C9750 = v13;
  if ( (n34307 & 3) == 0 || n3 == 1 )
    v15 = 640.0;
  else
    v15 = -640.0;
  unk_22C9754 = v15;
  v16 = 4 * n3;
  unk_22C9758 = v13;
  v17 = v13;
  v18 = v14;
  v19 = v17;
  unk_22C975C = v18;
  if ( (n34307 & 0x800) == 0 )
    v16 += 16;
  unk_22C9720 = dword_C87C90[v16];
  unk_22C9724 = dword_C87C94[v16];
  unk_22C9728 = dword_C87C98[v16];
  unk_22C972C = dword_C87C9C[v16];
  unk_22C9730 = dword_C87D10[v16];
  unk_22C9734 = dword_C87D14[v16];
  unk_22C9738 = dword_C87D18[v16];
  unk_22C973C = dword_C87D1C[v16];
  n128 = 128;
  n32 = 32;
  if ( (n34307 & 0x800) != 0 )
  {
    n128_0 = 128;
    n128_1 = 0;
  }
  else
  {
    n128_0 = 0;
    n128_1 = 128;
  }
  v45 = (float)a2;
  v20 = v45;
  if ( v45 == v19 )
  {
    v46 = v19;
    v21 = v46;
  }
  else
  {
    v47 = (float)a1;
    v48 = v47 / v20;
    v21 = v48;
    if ( v4[5] < (double)v48 )
      v4[5] = v48;
    if ( v4[4] >= v21 )
    {
      v49 = v4[4] - 0.01999999955296516;
      v21 = v49;
    }
    v4[4] = v21;
  }
  n48_1 = (int)(v21 * 48.0);
  nullsub_49(&unk_22C93D0, &unk_C87C60, &unk_C87C70, &unk_C87C80);
  if ( unk_11A0044 )
    v22 = 0.87285;
  else
    v22 = 0.47;
  v42 = v22;
  sub_93D960((int)&unk_22C9410, 512.0, 0.80000001, v42, 2048.0, 2048.0, 1.0, 16777215.0, 1.0, 65536.0);
  v23 = 0.5;
  unk_2311550 = 1;
  n48 = 0;
  unk_2311558 = -286331154;
  n68 = 68;
  n66 = 66;
  n196621 = 196621;
  n71 = 71;
  unk_2311580 = 1;
  n20_2 = 20;
  v25 = (char *)&unk_23115A0;
  n48_2 = 0;
  do
  {
    v43 = v23;
    sub_7EA610(&unk_22C9350, v43);
    sub_7E9440(&unk_22C9350, &unk_22C9350, &flt_22C9750);
    sub_7E78B0(&unk_22C9380, &unk_22C93D0, &flt_22C96D0);
    sub_7E82C0(&unk_22C9390, &unk_22C9410, &unk_22C9350);
    sub_6ED980(v25 + 32, &unk_22C9390, &flt_22C96E0, 0);
    *((_DWORD *)v25 + 11) = 0x8000;
    sub_6ED980(v25 + 64, &unk_22C9390, &flt_22C96F0, 0);
    *((_DWORD *)v25 + 19) = 0x8000;
    sub_6ED980(v25 + 96, &unk_22C9390, &flt_22C9700, 0);
    *((_DWORD *)v25 + 27) = 0;
    sub_6ED980(v25 + 128, &unk_22C9390, &flt_22C9710, 0);
    v26 = n48 < n48_1;
    v27 = unk_22C972C;
    *((_DWORD *)v25 + 35) = 0;
    *((_DWORD *)v25 + 2) = 66;
    if ( v26 )
    {
      v28 = unk_22C9720;
      v29 = unk_22C9724;
      v30 = unk_22C9728;
      *((_DWORD *)v25 + 4) = unk_22C9720;
      *((_DWORD *)v25 + 12) = v28;
      *((_DWORD *)v25 + 20) = v28;
      *((_DWORD *)v25 + 28) = v28;
      *((_DWORD *)v25 + 5) = v29;
      *((_DWORD *)v25 + 13) = v29;
      *((_DWORD *)v25 + 21) = v29;
      *((_DWORD *)v25 + 29) = v29;
      *((_DWORD *)v25 + 6) = v30;
      *((_DWORD *)v25 + 14) = v30;
      *((_DWORD *)v25 + 22) = v30;
      *((_DWORD *)v25 + 30) = v30;
      *(_DWORD *)v25 = 72;
      *((_DWORD *)v25 + 7) = v27;
      *((_DWORD *)v25 + 15) = v27;
      *((_DWORD *)v25 + 23) = v27;
      *((_DWORD *)v25 + 31) = v27;
    }
    else
    {
      n128 = n128;
      n128_1 = n128_0;
      n128_2 = n128_1;
      n32 = n32;
      *((_DWORD *)v25 + 4) = n128;
      *((_DWORD *)v25 + 12) = n128;
      *((_DWORD *)v25 + 20) = n128;
      *((_DWORD *)v25 + 28) = n128;
      v28 = unk_22C9720;
      *((_DWORD *)v25 + 5) = n128_1;
      *((_DWORD *)v25 + 13) = n128_1;
      *((_DWORD *)v25 + 21) = n128_1;
      *((_DWORD *)v25 + 29) = n128_1;
      v29 = unk_22C9724;
      *((_DWORD *)v25 + 6) = n128_2;
      *((_DWORD *)v25 + 14) = n128_2;
      *((_DWORD *)v25 + 22) = n128_2;
      *((_DWORD *)v25 + 30) = n128_2;
      n32_1 = n32;
      *((_DWORD *)v25 + 7) = n32;
      *((_DWORD *)v25 + 15) = n32;
      *((_DWORD *)v25 + 23) = n32;
      n3 = n34307 & 3;
      *((_DWORD *)v25 + 31) = n32_1;
      v30 = unk_22C9728;
      *(_DWORD *)v25 = 66;
    }
    ++n32;
    unk_22C9720 = unk_22C9730 + v28;
    unk_22C9724 = unk_22C9734 + v29;
    unk_22C9728 = unk_22C9738 + v30;
    unk_22C972C = unk_22C973C + v27;
    if ( n3 )
    {
      if ( n3 == 1 )
      {
        unk_22C96D4 = unk_22C96D4 + 0.5;
        flt_22C96F0 = flt_22C96F0 + 0.800000011920929;
        flt_22C9710 = flt_22C9710 + 0.800000011920929;
        v36 = unk_22C9754 - 2.0;
      }
      else
      {
        if ( n3 == 2 )
        {
          v37 = unk_22C96D4 - 0.5;
        }
        else
        {
          if ( n3 != 3 )
            goto LABEL_48;
          v37 = unk_22C96D4 + 0.5;
        }
        unk_22C96D4 = v37;
        flt_22C96E0 = flt_22C96E0 - 0.800000011920929;
        flt_22C9700 = flt_22C9700 - 0.800000011920929;
        v36 = unk_22C9754 + 2.0;
      }
    }
    else
    {
      unk_22C96D4 = unk_22C96D4 - 0.5;
      flt_22C96F0 = flt_22C96F0 + 0.800000011920929;
      flt_22C9710 = flt_22C9710 + 0.800000011920929;
      v36 = unk_22C9754 - 2.0;
    }
    unk_22C9754 = v36;
LABEL_48:
    v23 = 0.5;
    n48 = n48_2 + 1;
    v25 += 144;
    n48_2 = n48;
  }
  while ( n48 < 48 );
  n336860190 = 336860190;
  v38 = unk_11A0764;
  unk_2311590 = (v25 - (char *)&unk_23115A0) / 16 / 9;
  *((_DWORD *)v25 + 4) = unk_11A0750;
  *((_DWORD *)v25 + 5) = unk_11A0754;
  *((_DWORD *)v25 + 6) = unk_11A0758;
  *((_DWORD *)v25 + 7) = unk_11A075C;
  *((_DWORD *)v25 + 8) = unk_11A0760;
  *((_DWORD *)v25 + 9) = v38;
  *((_DWORD *)v25 + 10) = unk_11A0768;
  v39 = unk_11A076C;
  *(_DWORD *)v25 = 32769;
  *((_DWORD *)v25 + 2) = -286331154;
  *((_DWORD *)v25 + 11) = v39;
  dword_2311540[0] = ((v25 - (char *)dword_2311540 + 48) / 16 - 1) | 0x70000000;
  unk_2311548 = 0;
  sub_62FA30(0, 0);
  nullsub_33(0);
  result = nullsub_39(268476416, dword_2311540);
  if ( !unk_2321542 )
    return result;
  v41 = (int)(*((float *)&unk_22C9760 + 16 * (n34307 & 3) + 5) * 100.0);
  if ( n34307 > 2049 )
  {
    if ( n34307 == 2050 )
    {
      sub_7E64F0(56, 1);
      return nullsub_93("prim%3d", v41);
    }
    else
    {
      if ( n34307 != 34307 )
        goto LABEL_59;
      sub_7E64F0(58, 34);
      nullsub_93("fpar");
      sub_7E64F0(59, 35);
      nullsub_93("%3d", v41);
      sub_7E64F0(56, 36);
      return nullsub_93("%6x", a2 + 16);
    }
  }
  else
  {
    switch ( n34307 )
    {
      case 2049:
        sub_7E64F0(2, 37);
        return nullsub_93("par%3d", v41);
      case 1537:
        sub_7E64F0(2, 34);
        nullsub_93("fprim");
        sub_7E64F0(2, 35);
        nullsub_93("%3d", v41);
        sub_7E64F0(2, 36);
        return nullsub_93("%6x", a2);
      case 2048:
        sub_7E64F0(2, 1);
        return nullsub_93("et%3d", v41);
      default:
LABEL_59:
        result = n34307 & 3;
        switch ( n34307 & 3 )
        {
          case 0:
            sub_7E64F0(2, 1);
            nullsub_93("%6x", a2);
            sub_7E64F0(2, 2);
            goto LABEL_61;
          case 1:
            sub_7E64F0(2, 35);
            nullsub_93("%3d", v41);
            sub_7E64F0(2, 36);
            result = nullsub_93("%6x", a2);
            break;
          case 2:
            sub_7E64F0(56, 1);
            nullsub_93("%6x", a2);
            sub_7E64F0(59, 2);
LABEL_61:
            result = nullsub_93("%3d", v41);
            break;
          case 3:
            sub_7E64F0(59, 35);
            nullsub_93("%3d", v41);
            sub_7E64F0(56, 36);
            result = nullsub_93("%6x", a2 + 16);
            break;
          default:
            return result;
        }
        break;
    }
  }
  return result;
}

