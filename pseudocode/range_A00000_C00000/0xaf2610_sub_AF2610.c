// Function: sub_AF2610
// Address: 0xaf2610
// Size: 0xa
// Prototype: 

_DWORD *sub_AF2610()
{
  int n255; // edx
  float *v1; // eax
  float *v2; // eax
  int n256; // ecx

  n255 = 255;
  v1 = (float *)&unk_19429A4;
  do
  {
    *(v1 - 2) = 0.0;
    *(v1 - 1) = 1.0;
    v1 += 3;
    --n255;
    *(v1 - 3) = 0.0;
  }
  while ( n255 >= 0 );
  v2 = (float *)&unk_19429A0;
  n256 = 256;
  do
  {
    *(v2 - 1) = 0.0;
    *v2 = 1.0;
    v2 += 3;
    *(v2 - 2) = 0.0;
    --n256;
  }
  while ( n256 );
  dword_1942998 = 0;
  return &dword_1942998;
}

