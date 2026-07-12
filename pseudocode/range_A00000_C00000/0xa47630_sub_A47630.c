// Function: sub_A47630
// Address: 0xa47630
// Size: 0x621
// Prototype: 

void *sub_A47630()
{
  double v0; // st7
  float *v1; // ecx
  int v2; // edi
  char *v3; // ebx
  double v4; // st5
  double v5; // st4
  double v6; // st6
  double i; // st3
  float v8; // eax
  float v9; // esi
  double v10; // st6
  double v11; // st5
  double v12; // rt1
  double v13; // st5
  double v14; // st6
  double v15; // st7
  double v16; // st6
  double v17; // st5
  double v18; // rtt
  double v19; // st5
  double v20; // st7
  int j; // esi
  float v23; // [esp+0h] [ebp-1C0h]
  float v24; // [esp+4h] [ebp-1BCh]
  float v25; // [esp+Ch] [ebp-1B4h]
  float v26; // [esp+10h] [ebp-1B0h]
  float v27; // [esp+14h] [ebp-1ACh]
  float v28; // [esp+18h] [ebp-1A8h]
  float v29; // [esp+1Ch] [ebp-1A4h]
  float i_1; // [esp+20h] [ebp-1A0h]
  float v31; // [esp+24h] [ebp-19Ch]
  _DWORD v32[4]; // [esp+30h] [ebp-190h]
  char v33; // [esp+40h] [ebp-180h] BYREF

  v0 = 0.0;
  v1 = (float *)unk_2305834;
  v2 = unk_2305834 + 71360;
  v31 = -2336.0;
  v3 = &v33;
  v4 = 0.0;
  v5 = (float)-2336.0;
  v6 = flt_C0A010;
  i_1 = -2560.0;
  for ( i = (float)-2560.0; ; i = (float)-2560.0 )
  {
    while ( 1 )
    {
      unk_C8F940 = LODWORD(i_1);
      unk_C8F944 = LODWORD(v31);
      unk_C8F948 = 0.0;
      unk_C8F94C = 1.0;
      flt_C8F950 = v1[17656];
      flt_C8F954 = v1[17657];
      flt_C8F958 = v1[17658];
      flt_C8F95C = v1[17659];
      flt_C8F960 = v1[17660];
      flt_C8F964 = v1[17661];
      flt_C8F968 = v1[17662];
      flt_C8F96C = v1[17663];
      flt_C8F970 = v1[17664];
      flt_C8F974 = v1[17665];
      flt_C8F978 = v1[17666];
      flt_C8F97C = v1[17667];
      unk_C8F980[0] = v1[17668];
      flt_C8F984 = v1[17669];
      flt_C8F988 = v1[17670];
      v8 = v1[17671];
      unk_C8F790 = flt_C8F950 * i;
      unk_C8F98C = LODWORD(v8);
      unk_C8F794 = flt_C8F954 * i;
      unk_C8F798 = flt_C8F958 * i;
      unk_C8F79C = flt_C8F95C * i;
      unk_C8F790 = flt_C8F960 * v5 + unk_C8F790;
      unk_C8F794 = flt_C8F964 * v5 + unk_C8F794;
      unk_C8F798 = flt_C8F968 * v5 + unk_C8F798;
      unk_C8F79C = flt_C8F96C * v5 + unk_C8F79C;
      unk_C8F790 = flt_C8F970 * v4 + unk_C8F790;
      unk_C8F794 = flt_C8F974 * v4 + unk_C8F794;
      unk_C8F798 = flt_C8F978 * v4 + unk_C8F798;
      unk_C8F79C = flt_C8F97C * v4 + unk_C8F79C;
      unk_C8F930 = unk_C8F980[0] * v6 + unk_C8F790;
      unk_C8F934 = flt_C8F984 * v6 + unk_C8F794;
      unk_C8F938 = flt_C8F988 * v6 + unk_C8F798;
      unk_C8F93C = v8 * v6 + unk_C8F79C;
      if ( unk_C8F93C <= v0 )
      {
        *v3++ = -1;
      }
      else
      {
        unk_C8F7E4 = 2304.0;
        unk_C8F7E0 = 2576.0;
        unk_C8F788 = v6 / unk_C8F93C;
        unk_C8F7D0 = unk_C8F930 * unk_C8F788;
        v9 = unk_C8F7D0;
        v26 = unk_C8F7D0;
        unk_C8F7D0 = 1528.0;
        unk_C8F800 = v26;
        unk_C8F7D4 = unk_C8F934 * unk_C8F788;
        unk_C8F7D8 = unk_C8F938 * unk_C8F788;
        v23 = unk_C8F7D8;
        v28 = unk_C8F7D8;
        unk_C8F808 = LODWORD(unk_C8F7D8);
        flt_C8F7DC = unk_C8F93C * unk_C8F788;
        v24 = flt_C8F7DC;
        v29 = flt_C8F7DC;
        unk_C8F80C = LODWORD(flt_C8F7DC);
        unk_C8F830 = unk_C8F788 + flt_C0A004;
        v25 = unk_C8F830;
        v27 = unk_C8F7D4;
        unk_C8F7D4 = 1600.0;
        unk_C8F7F0 = v26 - 1528.0;
        unk_C8F804 = v27;
        unk_C8FAC4 = unk_C8F508[0];
        unk_C8F7F4 = v27 - 1600.0;
        v10 = unk_C8F7F0;
        if ( unk_C8F7F0 == v0 || (v11 = unk_C8F7F4, unk_C8F7F4 == v0) )
        {
          sub_42EF30();
          v10 = unk_C8F7F0;
          v11 = unk_C8F7F4;
          v0 = 0.0;
        }
        v12 = v11;
        v13 = v10;
        v14 = v12;
        if ( v13 < v0 || v14 < v0 )
          sub_42EF20();
        sub_42EF00();
        unk_C8F7F0 = unk_C8F7E0 - unk_C8F800;
        unk_C8F7F4 = unk_C8F7E4 - unk_C8F804;
        v15 = unk_C8F7F0;
        v16 = 0.0;
        if ( 0.0 == unk_C8F7F0 || (v17 = unk_C8F7F4, unk_C8F7F4 == 0.0) )
        {
          sub_42EF30();
          v16 = 0.0;
          v17 = unk_C8F7F4;
          v15 = unk_C8F7F0;
        }
        v18 = v17;
        v19 = v15;
        v20 = v18;
        if ( v19 < v16 || v16 > v20 )
          sub_42EF20();
        sub_42EF00();
        ++v3;
        unk_C8F810 = v9;
        *(float *)v32 = v9;
        unk_C8F814 = v27;
        unk_C8F818 = v23;
        unk_C8F81C = LODWORD(v24);
        *(float *)&v32[1] = v27;
        *(float *)&v32[2] = v23;
        *(float *)&v32[3] = v24;
        for ( j = 0; j < 2; ++j )
          *(_DWORD *)((char *)&unk_C8F800 + j * 4) = (int)(*(float *)&v32[j] * 16.0);
        unk_C8F808 = (int)v28;
        unk_C8F80C = (int)v29;
        *(float *)v2 = unk_C8F800;
        *(float *)(v2 + 4) = unk_C8F804;
        *(_DWORD *)(v2 + 8) = unk_C8F808;
        *(float *)(v2 + 12) = v25;
        v1 = (float *)unk_2305834;
        v5 = v31;
        v0 = 0.0;
        v6 = flt_C0A010;
        i = i_1;
        v4 = 0.0;
      }
      v2 += 16;
      i_1 = i + 256.0;
      if ( i_1 > 2560.0 )
        break;
      i = i_1;
    }
    v31 = v5 + 256.0;
    v5 = v31;
    if ( v31 > 2080.0 )
      break;
    i_1 = -2560.0;
  }
  memset32(v1 + 19352, (int)&value_, 0x55u);
  return &value_;
}

