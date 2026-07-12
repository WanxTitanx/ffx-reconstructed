// Function: sub_93D3D0
// Address: 0x93d3d0
void __cdecl sub_93D3D0(float *a1, float *a2)
{
  float v3; // [esp+10h] [ebp+Ch]
  float v4; // [esp+10h] [ebp+Ch]

  v3 = sqrt(*a2 * *a2 + a2[1] * a2[1] + a2[2] * a2[2]);
  if ( v3 > 0.0 )
  {
    v4 = 1.0 / v3;
    *a1 = *a2 * v4;
    a1[1] = v4 * a2[1];
    a1[2] = v4 * a2[2];
    a1[3] = a2[3];
  }
}
