// FFX Abmap: Build node placement matrix
int __cdecl FFX_Abmap_BuildNodePlacementMatrix(int a1, __int16 *a2, float a3)
{
  int result; // eax

  *(_QWORD *)a1 = n1006632960_1; /*0xa5ad3e*/
  *(_DWORD *)(a1 + 8) = FFX_Render_SharedTransformContext; /*0xa5ad4d*/
  *(float *)(a1 + 12) = MEMORY[0xC8F514][0]; /*0xa5ad55*/
  *(_QWORD *)(a1 + 16) = n1006632960_1; /*0xa5ad5d*/
  *(_DWORD *)(a1 + 24) = FFX_Render_SharedTransformContext; /*0xa5ad6d*/
  *(float *)(a1 + 28) = MEMORY[0xC8F514][0]; /*0xa5ad75*/
  *(_QWORD *)(a1 + 32) = n1006632960_1; /*0xa5ad7d*/
  *(_DWORD *)(a1 + 40) = FFX_Render_SharedTransformContext; /*0xa5ad90*/
  *(float *)(a1 + 44) = MEMORY[0xC8F514][0]; /*0xa5ad98*/
  *(_QWORD *)(a1 + 48) = n1006632960_1; /*0xa5ada0*/
  *(_DWORD *)(a1 + 56) = FFX_Render_SharedTransformContext; /*0xa5adb0*/
  *(float *)(a1 + 60) = MEMORY[0xC8F514][0]; /*0xa5adb8*/
  *(float *)(a1 + 40) = a3; /*0xa5adbb*/
  *(float *)(a1 + 20) = a3; /*0xa5adbe*/
  *(float *)a1 = a3; /*0xa5adc1*/
  *(float *)(a1 + 48) = (float)*a2; /*0xa5adcc*/
  *(float *)(a1 + 52) = (float)a2[1]; /*0xa5add9*/
  result = a2[2]; /*0xa5addc*/
  *(float *)(a1 + 56) = (float)result; /*0xa5ade6*/
  *(float *)(a1 + 60) = 1.0; /*0xa5adeb*/
  return result; /*0xa5adee*/
}
