// Function: sub_93CE10
// Address: 0x93ce10
int __cdecl sub_93CE10(int a1, int a2)
{
  int v2; // ecx
  int v3; // edx
  int n4; // eax

  v2 = a1 + 4;
  v3 = a2 + 12;
  n4 = 4;
  do
  {
    v2 += 16;
    *(float *)(v2 - 20) = *(float *)(v3 - 12);
    v3 += 16;
    *(float *)(v2 - 16) = *(float *)(a2 - a1 + v2 - 16);
    *(float *)(v2 - 12) = *(float *)(v3 - 20);
    *(float *)(v2 - 8) = *(float *)(v3 - 16);
    --n4;
  }
  while ( n4 );
  return n4;
}
