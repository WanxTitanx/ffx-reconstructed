// Function: sub_817F60
// Address: 0x817f60
double __cdecl sub_817F60(float a1)
{
  float v2; // [esp+8h] [ebp+8h]

  v2 = a1 * 2048.0 / 3.141592025756836;
  return (float)((1024 - (unsigned __int16)(int)v2) & 0xFFF);
}
