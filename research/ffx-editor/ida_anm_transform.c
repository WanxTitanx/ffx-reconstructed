// FFX Abmap: Build node transform matrix
int __cdecl FFX_Abmap_BuildNodeTransformMatrix(int a1, __int16 *a2, __int16 *a3, float a4)
{
  int result; // eax

  *(_QWORD *)a1 = n1006632960_1; /*0xa5a375*/
  *(_DWORD *)(a1 + 8) = FFX_Render_SharedTransformContext; /*0xa5a384*/
  *(float *)(a1 + 12) = MEMORY[0xC8F514][0]; /*0xa5a38c*/
  *(_QWORD *)(a1 + 16) = n1006632960_1; /*0xa5a394*/
  *(_DWORD *)(a1 + 24) = FFX_Render_SharedTransformContext; /*0xa5a3a4*/
  *(float *)(a1 + 28) = MEMORY[0xC8F514][0]; /*0xa5a3ac*/
  *(_QWORD *)(a1 + 32) = n1006632960_1; /*0xa5a3b4*/
  *(_DWORD *)(a1 + 40) = FFX_Render_SharedTransformContext; /*0xa5a3c4*/
  *(float *)(a1 + 44) = MEMORY[0xC8F514][0]; /*0xa5a3cc*/
  *(_QWORD *)(a1 + 48) = n1006632960_1; /*0xa5a3d4*/
  *(_DWORD *)(a1 + 56) = FFX_Render_SharedTransformContext; /*0xa5a3e4*/
  *(float *)(a1 + 60) = MEMORY[0xC8F514][0]; /*0xa5a3ef*/
  *(float *)(a1 + 40) = a4; /*0xa5a3f2*/
  *(float *)(a1 + 20) = a4; /*0xa5a3f5*/
  *(float *)a1 = a4; /*0xa5a3f8*/
  *(float *)(a1 + 48) = (double)*a2 + (double)*a3; /*0xa5a418*/
  result = a3[1]; /*0xa5a42b*/
  *(float *)(a1 + 52) = (double)a2[1] + (double)result; /*0xa5a43b*/
  *(float *)(a1 + 56) = 0.0; /*0xa5a440*/
  *(float *)(a1 + 60) = 1.0; /*0xa5a445*/
  return result; /*0xa5a449*/
}
