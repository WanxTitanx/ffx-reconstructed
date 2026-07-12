// Function: sub_A5AD30
// Address: 0xa5ad30
// Size: 0xc0
// Prototype: int __cdecl(int, int, float)

int __cdecl sub_A5AD30(int a1, __int16 *a2, float a3)
{
  int result; // eax

  *(_DWORD *)a1 = unk_C8F508[0];
  *(float *)(a1 + 4) = flt_C8F50C;
  *(float *)(a1 + 8) = flt_C8F510;
  *(float *)(a1 + 12) = flt_C8F514[0];
  *(_DWORD *)(a1 + 16) = unk_C8F508[0];
  *(float *)(a1 + 20) = flt_C8F50C;
  *(float *)(a1 + 24) = flt_C8F510;
  *(float *)(a1 + 28) = flt_C8F514[0];
  *(_DWORD *)(a1 + 32) = unk_C8F508[0];
  *(float *)(a1 + 36) = flt_C8F50C;
  *(float *)(a1 + 40) = flt_C8F510;
  *(float *)(a1 + 44) = flt_C8F514[0];
  *(_DWORD *)(a1 + 48) = unk_C8F508[0];
  *(float *)(a1 + 52) = flt_C8F50C;
  *(float *)(a1 + 56) = flt_C8F510;
  *(float *)(a1 + 60) = flt_C8F514[0];
  *(float *)(a1 + 40) = a3;
  *(float *)(a1 + 20) = a3;
  *(float *)a1 = a3;
  *(float *)(a1 + 48) = (float)*a2;
  *(float *)(a1 + 52) = (float)a2[1];
  result = a2[2];
  *(float *)(a1 + 56) = (float)result;
  *(float *)(a1 + 60) = 1.0;
  return result;
}

