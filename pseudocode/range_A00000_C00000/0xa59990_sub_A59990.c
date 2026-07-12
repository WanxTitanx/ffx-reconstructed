// Function: sub_A59990
// Address: 0xa59990
// Size: 0x4e7
// Prototype: 

int sub_A59990()
{
  int v0; // ecx
  int v1; // eax
  int v2; // esi
  int v3; // edi
  int v4; // ecx
  double v5; // st7
  double v6; // st6
  int v7; // esi
  __int16 v8; // ax
  unsigned __int16 v9; // cx
  unsigned __int16 *v10; // edx
  int v11; // esi
  unsigned __int8 v12; // bl
  char v13; // cl
  _DWORD *v14; // ecx
  int v15; // ecx
  double v16; // st6
  int v17; // edx
  int v18; // ecx
  int v19; // eax
  int result; // eax
  double v21; // st5
  int v22[4]; // [esp+10h] [ebp-54h] BYREF
  int v23; // [esp+20h] [ebp-44h]
  int v24; // [esp+24h] [ebp-40h] BYREF
  double v25; // [esp+28h] [ebp-3Ch]
  float v26; // [esp+30h] [ebp-34h]
  float v27; // [esp+34h] [ebp-30h]
  float v28; // [esp+38h] [ebp-2Ch]
  int v29; // [esp+3Ch] [ebp-28h]
  int v30[4]; // [esp+40h] [ebp-24h] BYREF
  int v31; // [esp+50h] [ebp-14h] BYREF
  float v32; // [esp+54h] [ebp-10h]
  float v33; // [esp+58h] [ebp-Ch]
  float v34; // [esp+5Ch] [ebp-8h]

  v0 = dword_2305834[0];
  v1 = 5 * *(unsigned __int8 *)(dword_2305834[0] + 71224);
  *(float *)(dword_2305834[0] + 71200) = *(float *)(dword_2305834[0] + 71204) + *(float *)(dword_2305834[0] + 71200);
  v2 = dword_2305834[0];
  v3 = 16 * v1 + v0 + 69768;
  if ( !*(_DWORD *)(dword_2305834[0] + 71340) )
  {
    *(_DWORD *)(dword_2305834[0] + 71340) = 1;
    v2 = dword_2305834[0];
  }
  v4 = 5 * *(unsigned __int16 *)(v2 + 71218);
  v24 = *(__int16 *)(v2 + 40 * *(unsigned __int16 *)(v2 + 71218) + 2056);
  *(float *)&v31 = (float)v24;
  v24 = *(__int16 *)(v2 + 8 * v4 + 2058);
  v32 = (float)v24;
  v5 = 0.0;
  v33 = 0.0;
  v6 = 1.0;
  v34 = 1.0;
  if ( *(float *)(v2 + 71200) < 1.0 )
  {
LABEL_12:
    v19 = *(unsigned __int16 *)(v2 + 71222);
    if ( (_WORD)v19 == 0xFFFF )
    {
      sub_62FF20((int)v30, (int)&v31, v2 + 71228, *(float *)(v2 + 71200));
      *(float *)v3 = *(float *)v30;
      *(float *)(v3 + 4) = *(float *)&v30[1];
    }
    else
    {
      v23 = *(__int16 *)(v2 + 40 * v19 + 2056);
      v21 = (double)v23;
      v23 = *(__int16 *)(v2 + 40 * v19 + 2058);
      *(float *)v22 = v21;
      *(float *)&v22[1] = (float)v23;
      *(float *)&v22[2] = v5;
      *(float *)&v22[3] = v6;
      sub_A563B0((float *)v3, (float *)(v2 + 71228), (float *)&v31, (float *)v22, *(float *)(v2 + 71200));
    }
    *(float *)(v3 + 60) = (*(float *)(dword_2305834[0] + 71212) - *(float *)(dword_2305834[0] + 71208))
                        * *(float *)(dword_2305834[0] + 71200)
                        + *(float *)(dword_2305834[0] + 71208);
    *(_BYTE *)(dword_2305834[0] + 71111) = 1;
    return sub_A5B030();
  }
  else
  {
    while ( 1 )
    {
      *(_DWORD *)(v2 + 71160) = 0;
      v7 = dword_2305834[0];
      v8 = *(_WORD *)(dword_2305834[0] + 71218);
      v9 = *(_WORD *)(dword_2305834[0] + 71220);
      if ( v8 == v9 )
        break;
      *(_WORD *)(v7 + 71218) = sub_A56E00(v8, v9, (unsigned __int16 **)&v24);
      if ( *(_WORD *)(dword_2305834[0] + 71218) == 0xFFFF )
        break;
      v10 = (unsigned __int16 *)v24;
      *(_WORD *)(dword_2305834[0] + 71222) = *(_WORD *)(v24 + 4);
      v11 = dword_2305834[0];
      v12 = *((_BYTE *)v10 + 12);
      v13 = *(_BYTE *)(dword_2305834[0] + 71224);
      if ( ((unsigned __int8)(1 << v13) & v12) == 0 )
      {
        *((_BYTE *)v10 + 12) = v12 | (1 << v13);
        *((_BYTE *)v10 + 14) |= 8u;
        *(_DWORD *)(dword_2305834[0] + 71160) = v10;
        v11 = dword_2305834[0];
      }
      *(_WORD *)(v3 + 68) = *(_WORD *)(v11 + 71218);
      v14 = (_DWORD *)dword_2305834[0];
      *(_DWORD *)(dword_2305834[0] + 71228) = *(_DWORD *)v3;
      v14[17808] = *(_DWORD *)(v3 + 4);
      v14[17809] = *(_DWORD *)(v3 + 8);
      v14[17810] = *(_DWORD *)(v3 + 12);
      v15 = 5 * *(unsigned __int16 *)(dword_2305834[0] + 71218);
      HIDWORD(v25) = *(__int16 *)(dword_2305834[0] + 40 * *(unsigned __int16 *)(dword_2305834[0] + 71218) + 2056);
      *(float *)&v31 = (float)SHIDWORD(v25);
      HIDWORD(v25) = *(__int16 *)(dword_2305834[0] + 8 * v15 + 2058);
      v32 = (float)SHIDWORD(v25);
      unk_C8F820 = *(float *)(dword_2305834[0] + 71228);
      unk_C8F824 = *(float *)(dword_2305834[0] + 71232);
      flt_C8F828 = *(float *)(dword_2305834[0] + 71236);
      unk_C8F82C = *(_DWORD *)(dword_2305834[0] + 71240);
      unk_C8F830 = *(float *)&v31 - unk_C8F820;
      unk_C8F834 = v32 - unk_C8F824;
      unk_C8F83C = LODWORD(v34);
      unk_C8F838 = v33 - flt_C8F828;
      sub_42EF00();
      v26 = unk_C8F830;
      v27 = unk_C8F834;
      unk_C8F830 = unk_C8F830 * unk_C8F830;
      v28 = unk_C8F838;
      v29 = unk_C8F83C;
      unk_C8F834 = unk_C8F834 * unk_C8F834;
      unk_C8F838 = unk_C8F838 * unk_C8F838;
      unk_C8F830 = unk_C8F834 + unk_C8F830;
      unk_C8F830 = unk_C8F838 + unk_C8F830;
      *((float *)&v25 + 1) = fabs(unk_C8F830);
      *((float *)&v25 + 1) = sqrt(*((float *)&v25 + 1));
      unk_C8F788 = *((float *)&v25 + 1);
      unk_C8F830 = flt_C0A004 + *((float *)&v25 + 1);
      v23 = LODWORD(unk_C8F830);
      if ( unk_C8F830 <= 0.0 )
      {
        v5 = 0.0;
        v16 = 0.53333336;
      }
      else
      {
        v16 = 8.0 / unk_C8F830;
        v5 = 0.0;
      }
      *(float *)(dword_2305834[0] + 71204) = v16;
      v17 = dword_2305834[0];
      *(float *)(dword_2305834[0] + 71200) = *(float *)(dword_2305834[0] + 71200) - 1.0;
      *(float *)(dword_2305834[0] + 71208) = *(float *)(v3 + 60);
      HIDWORD(v25) = *(__int16 *)(dword_2305834[0]
                                + 48
                                * *(unsigned __int16 *)(dword_2305834[0] + 40 * *(unsigned __int16 *)(v3 + 68) + 2062)
                                + 63540) >> 1;
      v25 = (double)SHIDWORD(v25);
      *(float *)(dword_2305834[0] + 71212) = v25 + 3.0;
      v2 = dword_2305834[0];
      v18 = 5 * *(unsigned __int16 *)(dword_2305834[0] + 71218);
      HIDWORD(v25) = *(__int16 *)(dword_2305834[0] + 40 * *(unsigned __int16 *)(dword_2305834[0] + 71218) + 2056);
      *(float *)&v31 = (float)SHIDWORD(v25);
      HIDWORD(v25) = *(__int16 *)(dword_2305834[0] + 8 * v18 + 2058);
      v32 = (float)SHIDWORD(v25);
      v33 = v5;
      v6 = 1.0;
      v34 = 1.0;
      if ( *(float *)(v17 + 71200) < 1.0 )
        goto LABEL_12;
    }
    *(float *)v3 = *(float *)&v31;
    *(float *)(v3 + 4) = v32;
    *(float *)(v3 + 8) = v33;
    *(float *)(v3 + 12) = v34;
    *(_BYTE *)(dword_2305834[0] + 71111) = 1;
    *(_DWORD *)(dword_2305834[0] + 71080) = *(_DWORD *)(dword_2305834[0] + 71088);
    result = dword_2305834[0];
    *(_DWORD *)(dword_2305834[0] + 71088) = 0;
  }
  return result;
}

