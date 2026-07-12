// Function: sub_A76270
// Address: 0xa76270
// Size: 0x4a8
// Prototype: 

int __cdecl sub_A76270(int a1, _DWORD *a2, int a3)
{
  int v3; // eax
  unsigned int *v4; // edx
  int v5; // esi
  int result; // eax
  float *v7; // ecx
  unsigned int v8; // ecx
  float v9; // [esp+8h] [ebp-18h]
  float v10; // [esp+8h] [ebp-18h]
  float v11; // [esp+Ch] [ebp-14h]

  unk_C8F5B8 = *(_DWORD *)(a3 + dword_C8B500 + 1024);
  dword_C8B500 = 0;
  v3 = *(_DWORD *)(a3 + 1028);
  flt_C8F950 = flt_C0A004;
  unk_C8F5C8 = v3;
  flt_C8F954 = *(float *)&dword_C0A008;
  dword_C8B500 = 0;
  qword_C8F598 = 0xFFFFFFFFLL;
  flt_C8F958 = *(float *)&dword_C0A00C;
  flt_C8F95C = flt_C0A010;
  n1132462080 = a2[11];
  dword_C8B500 = 0;
  flt_C8F910 = *(float *)n1132462080;
  flt_C8F914 = *(float *)(n1132462080 + 4);
  flt_C8F918 = *(float *)(n1132462080 + 8);
  flt_C8F91C = *(float *)(n1132462080 + 12);
  unk_C8F920 = *(float *)(n1132462080 + 16);
  unk_C8F924 = *(float *)(n1132462080 + 20);
  unk_C8F928 = *(float *)(n1132462080 + 24);
  unk_C8F92C = *(float *)(n1132462080 + 28);
  flt_C8F930 = *(float *)(n1132462080 + 32);
  flt_C8F934 = *(float *)(n1132462080 + 36);
  flt_C8F938 = *(float *)(n1132462080 + 40);
  flt_C8F93C = *(float *)(n1132462080 + 44);
  flt_C8F940 = *(float *)(n1132462080 + 48);
  flt_C8F944 = *(float *)(n1132462080 + 52);
  flt_C8F948 = *(float *)(n1132462080 + 56);
  flt_C8F94C = *(float *)(n1132462080 + 60);
  qword_C8F5A8 = *(unsigned __int16 *)(a1 + 18);
  LODWORD(qword_C8F588) = a2[14];
  unk_C8F578 = *(_DWORD *)(a3 + 916);
  unk_C8F75C[0] = *(float *)(a3 + 1044);
  flt_C8F760 = *(float *)(a3 + 1056);
  unk_C8F764 = *(_DWORD *)(a3 + 1064);
  n1132462080 = 1132462080;
  flt_C8F72C = *(float *)unk_C8F508;
  flt_C8F730 = 1.0;
  unk_C8F52C = 0;
  flt_C8F734[0] = 256.0;
  n1132462080 = a2[8];
  a2[17] = n1132462080;
  dword_C8B500 = 0;
  v4 = (unsigned int *)unk_C8F5B8;
  v5 = HIDWORD(qword_C8F5A8);
  result = qword_C8F5A8;
  v7 = (float *)qword_C8F588;
  do
  {
    if ( v5 < 0 || v5 <= 0 && !result )
      break;
    do
    {
      flt_C8F950 = *v7;
      flt_C8F954 = v7[1];
      flt_C8F958 = v7[2];
      flt_C8F95C = v7[3];
      v11 = *v7;
      unk_C8F790 = flt_C8F910 * *v7;
      unk_C8F794 = flt_C8F914 * v11;
      unk_C8F798 = flt_C8F918 * v11;
      unk_C8F79C = v11 * flt_C8F91C;
      unk_C8F790 = unk_C8F920 * flt_C8F954 + unk_C8F790;
      unk_C8F794 = unk_C8F924 * flt_C8F954 + unk_C8F794;
      unk_C8F798 = unk_C8F928 * flt_C8F954 + unk_C8F798;
      unk_C8F79C = flt_C8F954 * unk_C8F92C + unk_C8F79C;
      unk_C8F790 = flt_C8F930 * flt_C8F958 + unk_C8F790;
      unk_C8F794 = flt_C8F934 * flt_C8F958 + unk_C8F794;
      unk_C8F798 = flt_C8F938 * flt_C8F958 + unk_C8F798;
      unk_C8F79C = flt_C8F958 * flt_C8F93C + unk_C8F79C;
      unk_C8F980[0] = flt_C8F940 * flt_C0A010 + unk_C8F790;
      flt_C8F984 = flt_C8F944 * flt_C0A010 + unk_C8F794;
      v8 = LODWORD(flt_C8F984);
      flt_C8F768 = flt_C8F984;
      n1132462080 = LODWORD(flt_C8F984);
      flt_C8F988 = flt_C8F948 * flt_C0A010 + unk_C8F798;
      unk_C8F530 = LODWORD(flt_C8F988);
      flt_C8F98C[0] = flt_C0A010 * flt_C8F94C + unk_C8F79C;
      unk_C8F534 = LODWORD(flt_C8F98C[0]);
      unk_C8F52C = SLODWORD(flt_C8F984) >> 31;
      if ( unk_C8F75C[0] >= (double)flt_C8F984 )
      {
        v9 = flt_C8F984 - unk_C8F75C[0];
        v10 = v9 * flt_C8F760;
        flt_C8F768 = v10 + flt_C8F730;
        dword_C8B504 = flt_C8F72C >= (double)flt_C8F768;
        v8 = unk_C8F508[0];
        flt_C8F768 = *(float *)unk_C8F508;
        flt_C8F76C = *(float *)unk_C8F508 * flt_C8F734[0];
      }
      else
      {
        dword_C8B504 = 0;
      }
      *v4 = v8;
      *(float *)(unk_C8F5B8 + 4) = flt_C8F76C;
      result = qword_C8F5A8 - 1;
      v7 = (float *)(qword_C8F588 + 16);
      v4 = (unsigned int *)(unk_C8F5B8 + 16);
      qword_C8F5A8 = (int)qword_C8F5A8 - 1;
      v5 = HIDWORD(qword_C8F5A8);
      LODWORD(qword_C8F588) = qword_C8F588 + 16;
      qword_C8F588 = (unsigned int)qword_C8F588;
      unk_C8F5B8 += 16;
      unk_C8F5BC = 0;
    }
    while ( SHIDWORD(qword_C8F5A8) > 0 );
  }
  while ( qword_C8F5A8 >= 0 && result );
  return result;
}

