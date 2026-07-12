// Function: sub_81B340
// Address: 0x81b340
double __cdecl sub_81B340(float a1)
{
  float v2; // [esp+8h] [ebp+8h]

  v2 = (float)((1024 - (unsigned __int16)(int)a1) & 0xFFF);
  return (float)(v2 * 3.141592025756836 * 0.00048828125);
}
