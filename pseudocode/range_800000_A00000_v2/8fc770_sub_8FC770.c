// Function: sub_8FC770
// Address: 0x8fc770
int __cdecl sub_8FC770(float *p_n128, float *a2)
{
  int result; // eax

  sub_9060F0(p_n128, a2);
  sub_905EF0(p_n128, a2);
  result = *((unsigned __int16 *)a2 + 19);
  if ( (result & 3) != 0 )
    result = sub_906050(p_n128, a2);
  p_n128[1] = a2[7] + 1.0 + p_n128[1];
  return result;
}
