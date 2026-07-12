// Function: sub_93CFF0
// Address: 0x93cff0
int __cdecl sub_93CFF0(_DWORD *a1, float *a2)
{
  int result; // eax

  *a1 = (int)*a2;
  a1[1] = (int)a2[1];
  a1[2] = (int)a2[2];
  result = (int)a2[3];
  a1[3] = result;
  return result;
}
