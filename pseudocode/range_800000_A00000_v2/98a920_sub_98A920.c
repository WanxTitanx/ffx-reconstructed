// Function: sub_98A920
// Address: 0x98a920
char __thiscall sub_98A920(int *this, float *dst, float *src, float *a4, float a5)
{
  double v7; // st7
  float v8; // [esp+10h] [ebp+Ch]
  int v9; // [esp+10h] [ebp+Ch]
  int v10; // [esp+10h] [ebp+Ch]
  int v11; // [esp+10h] [ebp+Ch]

  if ( *src >= (double)*dst
    && src[1] >= (double)dst[1]
    && src[2] >= (double)dst[2]
    && dst[4] >= (double)src[4]
    && dst[5] >= (double)src[5]
    && dst[6] >= (double)src[6] )
  {
    return 0;
  }
  *src = *src - a5;
  src[1] = src[1] - a5;
  src[2] = src[2] - a5;
  v8 = src[4] + a5;
  src[4] = v8;
  src[5] = src[5] + a5;
  v7 = v8;
  src[6] = a5 + src[6];
  v9 = *(int *)a4;
  if ( *a4 <= 0.0 )
    *src = *(float *)&v9 + *src;
  else
    src[4] = v7 + *(float *)&v9;
  v10 = *((int *)a4 + 1);
  if ( *(float *)&v10 <= 0.0 )
    src[1] = src[1] + *(float *)&v10;
  else
    src[5] = *(float *)&v10 + src[5];
  v11 = *((int *)a4 + 2);
  if ( *(float *)&v11 <= 0.0 )
    src[2] = *(float *)&v11 + src[2];
  else
    src[6] = src[6] + *(float *)&v11;
  sub_98A770(this, dst, src);
  return 1;
}
