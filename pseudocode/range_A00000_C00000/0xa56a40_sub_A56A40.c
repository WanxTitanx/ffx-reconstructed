// Function: sub_A56A40
// Address: 0xa56a40
// Size: 0x18c
// Prototype: 

__int16 *__cdecl sub_A56A40(float *a1, float *a2, int (__cdecl *a3)(__int16 *))
{
  __int16 *v3; // esi
  unsigned int v4; // eax
  __int16 *v5; // ebx
  float v7; // [esp+8h] [ebp-20h]
  float v8; // [esp+Ch] [ebp-1Ch]
  float v9; // [esp+18h] [ebp-10h]
  unsigned int v10; // [esp+1Ch] [ebp-Ch]
  float v11; // [esp+24h] [ebp-4h]
  float v12; // [esp+24h] [ebp-4h]

  v9 = 1000000000.0;
  v3 = (__int16 *)(dword_2305834[0] + 2056);
  v10 = dword_2305834[0] + 8 * (5 * *(__int16 *)(dword_2305834[0] + 2) + 257);
  v4 = v10;
  v5 = 0;
  if ( dword_2305834[0] + 2056 < v10 )
  {
    do
    {
      if ( v3[3] != -1 )
      {
        if ( a3 && !a3(v3) )
        {
          v4 = v10;
        }
        else
        {
          v7 = (double)*v3 - *a2;
          v8 = (double)v3[1] - a2[1];
          unk_C8F830 = v7 * v7;
          unk_C8F83C = 1.0;
          unk_C8F834 = v8 * v8;
          unk_C8F838 = (float)0.0 * 0.0;
          unk_C8F834 = unk_C8F830 + unk_C8F834;
          unk_C8F838 = unk_C8F834 + unk_C8F838;
          v11 = fabs(unk_C8F838);
          v12 = sqrt(v11);
          unk_C8F788 = v12;
          unk_C8F830 = flt_C0A004 + v12;
          v4 = v10;
          if ( v9 > (double)unk_C8F830 )
          {
            v9 = unk_C8F830;
            v5 = v3;
          }
        }
      }
      v3 += 20;
    }
    while ( (unsigned int)v3 < v4 );
  }
  *a1 = v9;
  return v5;
}

