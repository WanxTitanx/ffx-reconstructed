// Function: sub_89E460
// Address: 0x89e460
int __cdecl sub_89E460(__int16 a1, __int16 a2, int a3)
{
  int v3; // ecx
  int v4; // edx

  v3 = 3 * unk_13403F8;
  v4 = unk_13403F8 + 1;
  word_1340278[2 * v3] = 1;
  *((_WORD *)&unk_134027C + 2 * v3) = a1;
  *((_WORD *)&unk_134027E + 2 * v3) = a2;
  dword_1340280[v3] = a3;
  unk_13403F8 = v4;
  return a3;
}
