// Function: sub_93D8A0
// Address: 0x93d8a0
int __cdecl sub_93D8A0(int a1, int a2)
{
  int v2; // eax
  float *v3; // ecx
  int n4; // edx
  double v5; // st7
  _BYTE v7[4]; // [esp+4h] [ebp-44h] BYREF
  char v8; // [esp+8h] [ebp-40h] BYREF

  v2 = a2 + 32;
  v3 = (float *)&v8;
  n4 = 4;
  do
  {
    v5 = *(float *)(v2 - 32);
    v2 += 4;
    *(v3 - 1) = v5;
    v3 += 4;
    *(v3 - 4) = *(float *)(v2 - 20);
    *(v3 - 3) = *(float *)(v2 - 4);
    *(v3 - 2) = *(float *)(v2 + 12);
    --n4;
  }
  while ( n4 );
  return sub_93CE10(a1, (int)v7);
}
