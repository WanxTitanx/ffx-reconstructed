// Function: sub_81D000
// Address: 0x81d000
int __cdecl sub_81D000(int a1, int a2)
{
  FILE *v2; // eax
  int result; // eax

  if ( n670 == -1 )
  {
    v2 = __iob_func();
    return fprintf(
             v2 + 2,
             "FMOD SFX ERROR! There are battle streaming sound has data to be sent when there is no magic file!\n");
  }
  else
  {
    result = a1;
    if ( a1 || (result = a2) != 0 )
    {
      result = *(_DWORD *)(result + 8);
      dword_C49498 = result;
    }
    else
    {
      dword_C49498 = -1;
    }
  }
  return result;
}
