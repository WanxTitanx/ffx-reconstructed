// Function: sub_8FD9F0
// Address: 0x8fd9f0
_DWORD *__cdecl sub_8FD9F0(int src, float *a2)
{
  _DWORD *v2; // edi
  __int64 v3; // rax
  unsigned __int64 v4; // rt0
  __int64 v5; // rax
  _DWORD *v6; // eax
  int i; // edi
  double v9; // [esp+Ch] [ebp-28h]
  double v10; // [esp+14h] [ebp-20h]
  _DWORD v11[5]; // [esp+1Ch] [ebp-18h]

  v2 = dword_187168C;
  *dword_187168C = 32769;
  v2[1] = 1342193664;
  v2[2] = 126702;
  v2[3] = 0;
  v3 = *(__int16 *)a2;
  v2[4] = v3 | 0x9D308000;
  v2[6] = 6;
  v2[7] = 0;
  v2[5] = HIDWORD(v3) | 0x2005D786;
  HIDWORD(v4) = ((unsigned __int64)*((__int16 *)a2 + 1) >> 32)
              | (16 * (*((__int16 *)a2 + 2) + 2 * (*(unsigned __int8 *)(src + 27) >> 4)));
  LODWORD(v4) = *((__int16 *)a2 + 1);
  v5 = *(__int16 *)a2;
  v2[8] = v5 | ((_DWORD)v4 << 20) | 0x9C008000;
  v2[9] = HIDWORD(v5) | (v4 >> 12) | 0x5D706;
  v2[10] = 6;
  v2[11] = 0;
  v11[0] = -16711681;
  v11[1] = &unk_FEFF01;
  v11[2] = &unk_FF0002;
  v11[3] = &unk_1FF0001;
  v11[4] = &unk_1010100;
  dword_187168C = v2 + 12;
  sub_8FAA20(0, 1, 0, 1, 128);
  sub_8FABE0(1, 7, 0, 0, 0, 0, 0, 0);
  sub_8FAB80(128, 128, 128, 40);
  v6 = dword_187168C;
  *dword_187168C = 32778;
  v6[1] = 1085227008;
  v6[2] = 17219;
  v6[3] = 0;
  dword_187168C = v6 + 4;
  for ( i = 0; i < 10; ++i )
  {
    sub_8FACA0((int)a2[2], (int)a2[3]);
    v9 = (double)*((char *)v11 + 2 * i + 1);
    v10 = (double)*((char *)v11 + 2 * i);
    sub_8FACF0((int)(v10 + *(float *)(src + 4)), (int)(v9 + *(float *)(src + 8) + a2[6]));
    sub_8FACA0((int)a2[4], (int)a2[5]);
    sub_8FACF0((int)(a2[7] + *(float *)(src + 4) + v10), (int)(*(float *)(src + 8) + a2[6] + a2[8] + v9));
  }
  return sub_8F3A30();
}
