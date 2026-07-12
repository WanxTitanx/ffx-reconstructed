// Function: sub_A649C0
// Address: 0xa649c0
// Size: 0x40
// Prototype: 

float *__cdecl sub_A649C0(char a1)
{
  float *result; // eax

  result = (float *)((char *)&unk_22C9760 + 64 * (a1 & 3));
  result[4] = 0.0;
  *(_DWORD *)result = 0xFFFF;
  result[5] = 0.0;
  result[1] = 0.0;
  result[6] = 0.0;
  result[2] = 0.0;
  result[3] = 0.0;
  result[7] = 0.0;
  return result;
}

