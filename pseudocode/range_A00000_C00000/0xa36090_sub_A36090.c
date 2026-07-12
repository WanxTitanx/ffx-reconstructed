// Function: sub_A36090
// Address: 0xa36090
// Size: 0x1f4
// Prototype: int __cdecl(int, int, float, float, float, float)

float *__cdecl sub_A36090(float *a1, int a2, float a3, float a4, float a5, float a6)
{
  int n5; // ebx
  float *result; // eax
  _DWORD *v8; // esi
  float *v9; // edi
  _DWORD *v10; // edx
  float *dst; // edi
  float *v12; // [esp+4h] [ebp-14h] BYREF
  int n16; // [esp+10h] [ebp-8h] BYREF
  int v14; // [esp+14h] [ebp-4h] BYREF

  n5 = dword_1A858B4[1]; /*0xa360a1*/
  result = (float *)sub_A3CF40(dword_1A858B4 + 614, 64); /*0xa360aa*/
  if ( result )
  {
    *result = a3; /*0xa360c2*/
    v8 = dword_1A858B4; /*0xa360c8*/
    result[1] = a4; /*0xa360ce*/
    result[2] = *a1; /*0xa360d5*/
    result[3] = a1[1]; /*0xa360db*/
    result[4] = a5; /*0xa360e1*/
    result[5] = a4; /*0xa360e6*/
    result[6] = a1[2]; /*0xa360ec*/
    result[7] = a1[1]; /*0xa360f2*/
    result[8] = a3; /*0xa360f7*/
    result[9] = a6; /*0xa360fd*/
    result[10] = *a1; /*0xa36102*/
    result[11] = a1[3]; /*0xa36108*/
    result[12] = a5; /*0xa3610d*/
    result[13] = a6; /*0xa36110*/
    result[14] = a1[2]; ... [3737 chars total]