// Function: sub_81E5D0
// Address: 0x81e5d0
int __cdecl sub_81E5D0(int a1, int a2)
{
  FILE *v2; // eax

  v2 = __iob_func();
  return fprintf(
           v2 + 2,
           "SFX SqsSePitchTranslate: try to set pitch for seq(%d), function is not implemented yet!!!\n",
           a2);
}
