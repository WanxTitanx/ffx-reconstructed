// Function: sub_93D830
// Address: 0x93d830
float *__cdecl sub_93D830(float *a1, float *a2, float *a3)
{
  float *v3; // ecx
  float *v4; // eax
  int n4; // edx

  v3 = a2 + 3;
  v4 = a1 + 1;
  n4 = 4;
  do
  {
    v4 += 4;
    *(v4 - 5) = *(v3 - 3);
    v3 += 4;
    *(v4 - 4) = *(float *)((char *)v4 + (char *)a2 - (char *)a1 - 16);
    *(v4 - 3) = *(v3 - 5);
    *(v4 - 2) = *(v3 - 4);
    --n4;
  }
  while ( n4 );
  a1[12] = a2[12] + *a3;
  a1[13] = a2[13] + a3[1];
  a1[14] = a2[14] + a3[2];
  return a3;
}
