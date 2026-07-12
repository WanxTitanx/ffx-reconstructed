// Function: sub_8E4930
// Address: 0x8e4930
int __cdecl sub_8E4930(int a1, int a2, int a3, int n2, int a5, float a6, float a7, float a8, float a9)
{
  MEMORY[0x23CC128] = sub_8E4790(a1, a2, a3, n2, (int)a8, a5);
  *(_WORD *)(MEMORY[0x23CC128] + 74) = (int)a6;
  *(_WORD *)(MEMORY[0x23CC128] + 76) = (int)a7;
  *(_WORD *)(MEMORY[0x23CC128] + 78) = (int)a8;
  *(_WORD *)(MEMORY[0x23CC128] + 80) = (int)a9;
  return MEMORY[0x23CC128];
}
