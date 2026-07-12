// Function: sub_A5A360
// Address: 0xa5a360
// Size: 0xed
// Prototype: int __cdecl(int, int, int, float)

int __cdecl sub_A5A360(int a1, __int16 *a2, __int16 *a3, float a4)
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
  *(float *)(a1 + 40) = a4;
  *(float *)(a1 + 20) = a4;
  *(float *)a1 = a4;
  *(float *)(a1 + 48) = (double)*a2 + (double)*a3;
  result = a3[1];
  *(float *)(a1 + 52) = (double)a2[1] + (double)result;
  *(float *)(a1 + 56) = 0.0;
  *(float *)(a1 + 60) = 1.0;
  return result;
}

