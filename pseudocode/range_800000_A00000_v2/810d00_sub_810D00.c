// Function: sub_810D00
// Address: 0x810d00
int __cdecl sub_810D00(int a1, int a2, int a3, int a4)
{
  _WORD *v4; // edi

  v4 = (_WORD *)(a4 + word_C4930C[(*(__int16 *)(a1 + 538) >> 12) & 7]);
  *v4 += sub_7E32F0(*(__int16 *)(a3 + 2));
  return a3 + 4;
}
