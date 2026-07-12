// Function: sub_89AB40
// Address: 0x89ab40
int __cdecl sub_89AB40(__int16 n0x1C, __int16 n12565)
{
  int v2; // eax
  void *v3; // ecx

  memset(&n0x1C, 0, 0x140u);
  n0x1C = n0x1C;
  n255_3 = n12565;
  v2 = 240 * unk_23CC092[0];
  *(_WORD *)((char *)&unk_133C952 + v2) = 0;
  *(_DWORD *)((char *)&unk_133C9E8 + v2) = 0;
  sub_898520();
  sub_898400();
  sub_8982A0();
  sub_898360(v3);
  sub_8985B0();
  if ( n256_0 == 256 )
  {
    unk_133D1BE = 0;
    unk_133D1BC = 0;
    n3_9 = 2;
    src_0 = dst_1;
    *(_DWORD *)&i_5 = 65791;
    word_133D13C[0] = 1;
    dst_1[0] = unk_133D09C & dword_133D114 & unk_133D11C;
    unk_133D138 = unk_133D09C & dword_133D114 & unk_133D11C;
  }
  return 1;
}
