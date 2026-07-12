// Function: sub_89A7D0
// Address: 0x89a7d0
int __cdecl sub_89A7D0(int a1, __int16 a2, __int16 n12565)
{
  int v3; // esi
  __int16 v4; // ax

  v3 = 240 * a1;
  unk_133C912[240 * a1] = 1;
  sub_89AB40(a2, n12565);
  v4 = unk_133D1BC;
  ++*(_WORD *)((char *)&unk_133C9B6 + v3);
  *(_WORD *)((char *)&unk_133C952 + v3) = v4;
  *(_DWORD *)((char *)&unk_133C9E8 + v3) = unk_133D138;
  return sub_8A1020((char *)&unk_133C910 + 240 * a1);
}
