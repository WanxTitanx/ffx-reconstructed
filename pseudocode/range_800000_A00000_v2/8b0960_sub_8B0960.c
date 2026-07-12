// Function: sub_8B0960
// Address: 0x8b0960
int sub_8B0960()
{
  int i; // ebx
  int result; // eax
  __int16 n3; // cx
  int StubZero; // eax
  _DWORD *v4; // ecx
  int v5; // ecx
  _DWORD *v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // edi
  int v10; // [esp-Ch] [ebp-1Ch]
  float v11; // [esp+Ch] [ebp-4h]
  float v12; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 8; ++i )
  {
    result = *(_DWORD *)(dword_1865AFC[i] + 20);
    n3 = *(_WORD *)(result + 44);
    if ( n3 <= 3 && n3 >= 1 && *(_DWORD *)(result + 148) )
    {
      StubZero = FFX_Kernel_GetStubZero();
      v4 = *(_DWORD **)(dword_1865AFC[i] + 20);
      if ( StubZero )
      {
        v4[36] = v4[29];
        v8 = *(_DWORD *)(dword_1865AFC[i] + 20);
        *(_DWORD *)(v8 + 148) = *(_DWORD *)(v8 + 120);
        v6 = *(_DWORD **)(dword_1865AFC[i] + 20);
        v7 = v6[31];
      }
      else
      {
        v4[36] = v4[23];
        v5 = *(_DWORD *)(dword_1865AFC[i] + 20);
        *(_DWORD *)(v5 + 148) = *(_DWORD *)(v5 + 96);
        v6 = *(_DWORD **)(dword_1865AFC[i] + 20);
        v7 = v6[25];
      }
      v6[38] = v7;
      sub_8B8D90(*(_DWORD *)(dword_1865AFC[i] + 20));
      sub_8AF800(
        i,
        *(__int16 *)(dword_1865AFC[i] + 12),
        *(__int16 *)(dword_1865AFC[i] + 8),
        *(__int16 *)(dword_1865AFC[i] + 10));
      sub_906E90(*(_DWORD *)(dword_1865AFC[i] + 16));
      v9 = *(_DWORD *)(dword_1865AFC[i] + 20);
      v11 = (float)((*(__int16 *)(v9 + 66) - *(__int16 *)(v9 + 70)) / 2);
      v10 = (__int16)(int)(v11 + *(float *)(v9 + 52));
      v12 = (float)((*(__int16 *)(v9 + 64) - *(__int16 *)(v9 + 68)) / 2);
      result = sub_8B8CC0(
                 i,
                 v9 + 72,
                 (__int16)(int)(v12 + *(float *)(v9 + 48)),
                 v10,
                 *(__int16 *)(v9 + 68),
                 *(__int16 *)(v9 + 70));
    }
  }
  return result;
}
