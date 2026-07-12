// Function: sub_A47440
// Address: 0xa47440
// Size: 0x89

int sub_A47440()
{
  int result; // eax
  float v1; // [esp+4h] [ebp-4h]
  float v2; // [esp+4h] [ebp-4h]

  v1 = flt_C44BE0[128 * (*(_DWORD *)(unk_2305834 + 71320) & 0x1F)]; /*0xa4745e*/
  *(float *)(unk_2305834 + 71076) = v1; /*0xa47464*/
  v2 = v1 + 1.0; /*0xa47470*/
  *(_BYTE *)(unk_2305834 + 71109) = (int)(v2 * 8.0) + 112; /*0xa4749c*/
  result = *(unsigned __int8 *)(unk_2305834 + 71109); /*0xa474b2*/
  *(_BYTE *)(unk_2305834 + 71109) = (result * *(unsigned __int8 *)(unk_2305834 + 71110)) >> 7; /*0xa474bf*/
  return result; /*0xa474c5*/
}