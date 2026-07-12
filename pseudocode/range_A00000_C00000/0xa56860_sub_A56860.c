// Function: sub_A56860
// Address: 0xa56860
// Size: 0x1da
// Prototype: 

__int16 *__cdecl sub_A56860(float *a1, int a2, int (__cdecl *a3)(__int16 *))
{
  int v3; // eax
  __int16 *v4; // esi
  unsigned int v5; // eax
  __int16 *v6; // ebx
  float v8; // [esp+8h] [ebp-28h]
  float v9; // [esp+10h] [ebp-20h]
  float v10; // [esp+10h] [ebp-20h]
  float v11; // [esp+10h] [ebp-20h]
  unsigned int v12; // [esp+14h] [ebp-1Ch]
  float v13; // [esp+18h] [ebp-18h]
  float v14; // [esp+1Ch] [ebp-14h] BYREF
  float v15; // [esp+20h] [ebp-10h]
  float v16; // [esp+24h] [ebp-Ch]
  float v17; // [esp+28h] [ebp-8h]

  v3 = *(__int16 *)(dword_2305834[0] + 2);
  v16 = 0.0;
  v17 = 1.0;
  v4 = (__int16 *)(dword_2305834[0] + 2056);
  v8 = 0.0;
  v12 = dword_2305834[0] + 8 * (5 * v3 + 257);
  v5 = v12;
  v6 = 0;
  if ( dword_2305834[0] + 2056 < v12 )
  {
    do
    {
      if ( v4[3] != -1 )
      {
        if ( a3 && !a3(v4)
          || (v14 = (double)*v4 - *a1, v15 = (double)v4[1] - a1[1], v13 = sub_62FE90(&v14, a2), v13 <= 0.5) )
        {
          v5 = v12;
        }
        else
        {
          unk_C8F830 = v14 * v14;
          unk_C8F83C = LODWORD(v17);
          unk_C8F834 = v15 * v15;
          unk_C8F838 = v16 * v16;
          unk_C8F834 = unk_C8F830 + unk_C8F834;
          unk_C8F838 = unk_C8F834 + unk_C8F838;
          v9 = fabs(unk_C8F838);
          v10 = sqrt(v9);
          unk_C8F788 = v10;
          unk_C8F830 = flt_C0A004 + v10;
          if ( unk_C8F830 <= 0.0 )
          {
            v5 = v12;
          }
          else
          {
            v11 = v13 / (unk_C8F830 * unk_C8F830);
            v5 = v12;
            if ( v8 < (double)v11 )
            {
              v8 = v13 / (unk_C8F830 * unk_C8F830);
              v6 = v4;
            }
          }
        }
      }
      v4 += 20;
    }
    while ( (unsigned int)v4 < v5 );
  }
  return v6;
}

