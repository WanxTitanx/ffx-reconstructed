// Function: sub_A690C0
// Address: 0xa690c0
// Size: 0xff

int __cdecl sub_A690C0(int a1, int a2)
{
  int v2; // eax
  int n2; // ecx
  double v4; // st7
  _BYTE v6[16]; // [esp+8h] [ebp-14h] BYREF

  sub_836240(0, a2); /*0xa690db*/
  sub_836240(1, a2 + 16); /*0xa690e6*/
  sub_836240(2, a2 + 32); /*0xa690f1*/
  *(_DWORD *)(a2 + 48) = unk_C8F508[0]; /*0xa690fb*/
  *(float *)(a2 + 52) = flt_C8F50C; /*0xa69103*/
  *(float *)(a2 + 56) = flt_C8F510; /*0xa6910b*/
  *(float *)(a2 + 60) = flt_C8F514[0]; /*0xa69113*/
  v2 = a2 + 8; /*0xa69119*/
  n2 = 2; /*0xa6911c*/
  do /*0xa69155*/
  {
    v4 = *(float *)(v2 - 8); /*0xa69121*/
    v2 += 24; /*0xa69124*/
    *(float *)(v2 - 32) = -v4; /*0xa69129*/
    *(float *)(v2 - 28) = -*(float *)(v2 - 28); /*0xa69131*/
    *(float *)(v2 - 24) = -*(float *)(v2 - 24); /*0xa69139*/
    *(float *)(v2 - 20) = -*(float *)(v2 - 20); /*0xa69141*/
    *(float *)(v2 - 16) = -*(float *)(v2 - 16); /*0xa69149*/
    *(float *)(v2 - 12) = -*(float *)(v2 - 12); /*0xa69151*/
    --n2; /*0xa69154*/
  }
  while ( n2 ); /*0xa69155*... [1503 chars total]