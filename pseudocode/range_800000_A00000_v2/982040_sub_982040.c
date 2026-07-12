// Function: sub_982040
// Address: 0x982040
double __thiscall sub_982040(float *this)
{
  float v1; // xmm1_4
  float v3; // [esp+0h] [ebp-4h]
  float v4; // [esp+0h] [ebp-4h]

  v1 = *(this + 3);
  v3 = v1;
  if ( v1 >= -1.0 )
  {
    if ( v1 > 1.0 )
      v3 = 1.0;
  }
  else
  {
    v3 = -1.0;
  }
  v4 = acos(v3);
  return (float)(v4 + v4);
}
