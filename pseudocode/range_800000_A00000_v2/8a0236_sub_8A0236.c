// Function: sub_8A0236
// Address: 0x8a0236
// positive sp value has been detected, the output may be wrong!
int __usercall sub_8A0236@<eax>(char a1@<al>, int a2@<ebx>, int a3@<ebp>, int a4@<esi>)
{
  int v4; // eax
  int v5; // esi
  int v6; // ecx
  float v8; // [esp-4h] [ebp-28h]

  *(float *)(a3 - 44) = (float)*(int *)(a3 - 44);
  *(double *)(a3 - 60) = *(float *)(a3 - 44);
  *(float *)(a3 - 44) = (float)*(int *)(a3 + 8);
  v8 = *(float *)(a3 - 44);
  *(float *)(a3 - 44) = *(double *)(a3 - 60) - FFX_Menu2D_ScaleX_1920to512(28.0);
  sub_9055C0(*(_DWORD *)(a3 - 32), *(float *)(a3 - 44), v8, a1, 0.77999997, 1.0);
  v4 = *(__int16 *)(a2 + 40);
  *(_DWORD *)(a3 - 24) += 2;
  v5 = a4 + 1;
  *(_DWORD *)(a3 - 20) = v5;
  if ( v5 < v4 )
    JUMPOUT(0x89FFC0);
  v6 = *(_DWORD *)(a3 - 12) + 1;
  *(_DWORD *)(a3 - 12) = v6;
  if ( v6 < *(_DWORD *)(a3 - 28) )
    JUMPOUT(0x89FEF1);
  return 0;
}
