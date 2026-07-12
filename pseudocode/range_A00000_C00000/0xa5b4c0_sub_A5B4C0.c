// Function: sub_A5B4C0
// Address: 0xa5b4c0
// Size: 0x8e
// Prototype: 

double __cdecl sub_A5B4C0(unsigned __int16 a1, float *a2)
{
  int v3; // edx

  if ( a1 == 0xFFFF )
  {
    a2[2] = 0.0;
    a2[1] = 0.0;
    *a2 = 0.0;
    a2[3] = 1.0;
    return 0.0;
  }
  else
  {
    v3 = dword_2305834[0];
    *a2 = (float)*(__int16 *)(dword_2305834[0] + 40 * a1 + 2056);
    a2[1] = (float)*(__int16 *)(v3 + 40 * a1 + 2058);
    a2[2] = 0.0;
    a2[3] = 1.0;
    return (float)(*(__int16 *)(dword_2305834[0] + 48 * *(unsigned __int16 *)(v3 + 40 * a1 + 2062) + 63540) / 2);
  }
}

