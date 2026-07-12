// Function: sub_A5A990
// Address: 0xa5a990
// Size: 0x94
// Prototype: 

int __cdecl sub_A5A990(int a1)
{
  int v1; // edx
  int v2; // esi
  int v3; // ecx

  v1 = dword_2305834[0];
  v2 = 80 * a1 + dword_2305834[0] + 69768;
  v3 = 5 * *(unsigned __int16 *)(v2 + 68);
  *(float *)v2 = (float)*(__int16 *)(dword_2305834[0] + 40 * *(unsigned __int16 *)(v2 + 68) + 2056);
  *(float *)(v2 + 4) = (float)*(__int16 *)(v1 + 8 * v3 + 2058);
  *(float *)(v2 + 8) = 0.0;
  *(float *)(v2 + 12) = 1.0;
  *(float *)(v2 + 60) = (double)(*(__int16 *)(dword_2305834[0]
                                            + 48
                                            * *(unsigned __int16 *)(dword_2305834[0]
                                                                  + 40 * *(unsigned __int16 *)(v2 + 68)
                                                                  + 2062)
                                            + 63540) >> 1)
                      + 3.0;
  return v2;
}

