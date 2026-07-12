// Function: sub_A48D70
// Address: 0xa48d70
// Size: 0xc6
// Prototype: int __cdecl(int, float)

int __cdecl sub_A48D70(int a1, float a2)
{
  _DWORD *v2; // ecx
  int result; // eax

  v2 = (_DWORD *)dword_2305834[0];
  *(_DWORD *)(dword_2305834[0] + 71228) = *(_DWORD *)(dword_2305834[0] + 70328);
  v2[17808] = v2[17583];
  v2[17809] = v2[17584];
  v2[17810] = v2[17585];
  *(float *)(dword_2305834[0] + 71200) = 0.0;
  *(float *)(dword_2305834[0] + 71204) = a2;
  *(float *)(dword_2305834[0] + 71208) = *(float *)(dword_2305834[0] + 70388);
  *(float *)(dword_2305834[0] + 71212) = (double)(*(__int16 *)(dword_2305834[0]
                                                             + 48
                                                             * *(unsigned __int16 *)(dword_2305834[0] + 40 * a1 + 2062)
                                                             + 63540) >> 1)
                                       + 3.0;
  *(_WORD *)(dword_2305834[0] + 71220) = a1;
  result = dword_2305834[0];
  *(_WORD *)(dword_2305834[0] + 70396) = a1;
  return result;
}

