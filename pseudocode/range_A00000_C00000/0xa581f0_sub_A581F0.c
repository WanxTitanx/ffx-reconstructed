// Function: sub_A581F0
// Address: 0xa581f0
// Size: 0x1e6
// Prototype: int __cdecl(int, int, int, float, float, int)

float *__cdecl sub_A581F0(float *a1, float *a2, float *a3, float a4, float a5, _BYTE *a6)
{
  double v6; // st7
  double v8; // st5
  float v9; // [esp+Ch] [ebp-14h]
  float v10; // [esp+10h] [ebp-10h]
  float v11; // [esp+10h] [ebp-10h]
  float v12; // [esp+1Ch] [ebp-4h]
  float v13; // [esp+1Ch] [ebp-4h]
  float v14; // [esp+1Ch] [ebp-4h]
  float v15; // [esp+1Ch] [ebp-4h]

  *a6 = 2; /*0xa581fa*/
  v9 = *a3 - *a2; /*0xa5820c*/
  v10 = a3[1] - a2[1]; /*0xa5821d*/
  unk_C8F83C = 1.0; /*0xa58248*/
  unk_C8F810 = v9 + flt_C0A004; /*0xa5824d*/
  unk_C8F814 = v10 + *(float *)&dword_C0A008; /*0xa5825e*/
  unk_C8F818 = *(float *)&dword_C0A00C + 0.0; /*0xa58270*/
  unk_C8F830 = v9 * v9; /*0xa5827c*/
  unk_C8F834 = v10 * v10; /*0xa58288*/
  unk_C8F838 = 0.0 * (float)0.0; /*0xa58294*/
  unk_C8F824 = unk_C8F834 + unk_C8F830; /*0xa582a6*/
  flt_C8F828 = unk_C8F838 + unk_C8F824; /*0xa582b8*/
  v12 = fabs(flt_C8F828); /*0xa582c6*/
  v13 = sqrt(v12); /*0xa582d1*/
  unk_C8F830 = v13 + flt_C0A004; /*... [1897 chars total]