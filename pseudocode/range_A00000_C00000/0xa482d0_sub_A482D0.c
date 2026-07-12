// Function: sub_A482D0
// Address: 0xa482d0
// Size: 0x455
// Prototype: 

void __cdecl sub_A482D0(int a1, float *a2)
{
  float v2; // eax
  double v3; // st7
  float v4; // [esp+Ch] [ebp-1Ch]
  float v5; // [esp+10h] [ebp-18h]
  float v6; // [esp+20h] [ebp-8h]
  float v7; // [esp+20h] [ebp-8h]
  float v8; // [esp+20h] [ebp-8h]
  float v9; // [esp+20h] [ebp-8h]
  float v10; // [esp+20h] [ebp-8h]
  float v11; // [esp+20h] [ebp-8h]
  float v12; // [esp+20h] [ebp-8h]
  float v13; // [esp+20h] [ebp-8h]
  float v14; // [esp+20h] [ebp-8h]
  float v15; // [esp+20h] [ebp-8h]

  sub_A47C60((__int16 *)a1);
  flt_C8F940 = *(float *)(a1 + 16);
  flt_C8F944 = *(float *)(a1 + 20);
  flt_C8F948 = *(float *)(a1 + 24);
  unk_C8F94C = *(_DWORD *)(a1 + 28);
  flt_C8F950 = *(float *)(dword_2305834[0] + 70624);
  flt_C8F954 = *(float *)(dword_2305834[0] + 70628);
  flt_C8F958 = *(float *)(dword_2305834[0] + 70632);
  flt_C8F95C = *(float *)(dword_2305834[0] + 70636);
  flt_C8F960 = *(float *)(dword_2305834[0] + 70640);
  flt_C8F964 = *(float *)(dword_2305834[0] + 70644);
  flt_C8F968 = *(float *)(dword_2305834[0] + 70648);
  flt_C8F96C = *(float *)(dword_2305834[0] + 70652);
  flt_C8F970 = *(float *)(dword_2305834[0] + 70656);
  flt_C8F974 = *(float *)(dword_2305834[0] + 70660);
  flt_C8F978 = *(float *)(dword_2305834[0] + 70664);
  flt_C8F97C = *(float *)(dword_2305834[0] + 70668);
  unk_C8F980[0] = *(float *)(dword_2305834[0] + 70672);
  flt_C8F984 = *(float *)(dword_2305834[0] + 70676);
  flt_C8F988 = *(float *)(dword_2305834[0] + 70680);
  v2 = *(float *)(dword_2305834[0] + 70684);
  unk_C8F790 = flt_C8F940 * flt_C8F950;
  unk_C8F98C = LODWORD(v2);
  unk_C8F794 = flt_C8F954 * flt_C8F940;
  unk_C8F798 = flt_C8F958 * flt_C8F940;
  unk_C8F79C = flt_C8F940 * flt_C8F95C;
  unk_C8F790 = flt_C8F944 * flt_C8F960 + unk_C8F790;
  unk_C8F794 = flt_C8F964 * flt_C8F944 + unk_C8F794;
  unk_C8F798 = flt_C8F968 * flt_C8F944 + unk_C8F798;
  unk_C8F79C = flt_C8F944 * flt_C8F96C + unk_C8F79C;
  unk_C8F790 = flt_C8F948 * flt_C8F970 + unk_C8F790;
  unk_C8F794 = flt_C8F974 * flt_C8F948 + unk_C8F794;
  unk_C8F798 = flt_C8F978 * flt_C8F948 + unk_C8F798;
  unk_C8F79C = flt_C8F948 * flt_C8F97C + unk_C8F79C;
  unk_C8F930 = unk_C8F980[0] * flt_C0A010 + unk_C8F790;
  unk_C8F934 = flt_C8F984 * flt_C0A010 + unk_C8F794;
  unk_C8F938 = flt_C8F988 * flt_C0A010 + unk_C8F798;
  flt_C8F93C = v2 * flt_C0A010 + unk_C8F79C;
  if ( flt_C8F93C > 0.0 )
  {
    unk_C8F7E0 = flt_C8F93C;
    flt_C8F7DC = flt_C8F93C;
    unk_C8F788 = flt_C0A010 / flt_C8F93C;
    unk_C8F7D0 = unk_C8F930 * unk_C8F788;
    unk_C8F7D4 = unk_C8F934 * unk_C8F788;
    unk_C8F7D8 = unk_C8F788 * unk_C8F938;
    v6 = (float)(*(__int16 *)(a1 + 70) >> 4);
    v4 = v6 / *(float *)(dword_2305834[0] + 70480) + unk_C8F7D0;
    v7 = (float)(*(__int16 *)(a1 + 72) >> 4);
    v5 = v7 / *(float *)(dword_2305834[0] + 70480) + unk_C8F7D4;
    dword_2305828 = (int)(10.0 / *(float *)(dword_2305834[0] + 70480) + (double)dword_2305828);
    switch ( *(_BYTE *)(a1 + 78) & 3 )
    {
      case 0:
        *a2 = v4;
        v8 = (float)(int)dword_2305824;
        a2[1] = v5 - v8;
        v9 = (float)dword_2305828;
        a2[2] = v9 + v4;
        a2[3] = v5;
        break;
      case 1:
        v10 = (float)dword_2305828;
        *a2 = v4 - v10;
        v11 = (float)(int)dword_2305824;
        a2[1] = v5 - v11;
        a2[2] = v4;
        a2[3] = v5;
        break;
      case 2:
        v12 = (float)dword_2305828;
        *a2 = v4 - v12;
        a2[1] = v5;
        a2[2] = v4;
        v13 = (float)(int)dword_2305824;
        v3 = v13;
        goto LABEL_8;
      case 3:
        *a2 = v4;
        a2[1] = v5;
        v14 = (float)dword_2305828;
        a2[2] = v14 + v4;
        v15 = (float)(int)dword_2305824;
        v3 = v15;
LABEL_8:
        a2[3] = v3 + v5;
        break;
      default:
        return;
    }
  }
  else
  {
    *a2 = 9.9999998e10;
  }
}

