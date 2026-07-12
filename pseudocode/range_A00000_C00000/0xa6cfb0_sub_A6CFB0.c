// Function: sub_A6CFB0
// Address: 0xa6cfb0
// Size: 0x3b3
// Prototype: 

int __cdecl sub_A6CFB0(int a1, _DWORD *a2, int a3, int a4, int a5, int a6, int a7)
{
  _DWORD *v7; // ebx
  int v8; // ecx
  __int16 *v9; // edi
  int result; // eax
  int v11; // esi
  int v12; // ecx
  __int16 v13; // ax
  int v14; // ebx
  int v15; // esi
  int v16; // ecx
  int v17; // ecx
  double v18; // [esp+10h] [ebp-F0h]
  float v19; // [esp+14h] [ebp-ECh]
  int v20; // [esp+18h] [ebp-E8h]
  int v21; // [esp+1Ch] [ebp-E4h]
  int v22; // [esp+20h] [ebp-E0h]
  double v23; // [esp+24h] [ebp-DCh]
  float v24; // [esp+28h] [ebp-D8h]
  int v25; // [esp+28h] [ebp-D8h]
  int v26; // [esp+2Ch] [ebp-D4h]
  float v27; // [esp+30h] [ebp-D0h]
  float v28; // [esp+30h] [ebp-D0h]
  int v29; // [esp+30h] [ebp-D0h]
  int v30; // [esp+34h] [ebp-CCh]
  int v31; // [esp+38h] [ebp-C8h]
  float v32; // [esp+38h] [ebp-C8h]
  float v33; // [esp+38h] [ebp-C8h]
  _BYTE v34[64]; // [esp+3Ch] [ebp-C4h] BYREF
  _BYTE v35[16]; // [esp+7Ch] [ebp-84h] BYREF
  _BYTE v36[16]; // [esp+8Ch] [ebp-74h] BYREF
  _BYTE v37[32]; // [esp+9Ch] [ebp-64h] BYREF
  float v38[4]; // [esp+BCh] [ebp-44h] BYREF
  float v39[4]; // [esp+CCh] [ebp-34h] BYREF
  float v40; // [esp+DCh] [ebp-24h] BYREF
  float v41; // [esp+E0h] [ebp-20h]
  float v42; // [esp+E8h] [ebp-18h]
  float v43; // [esp+ECh] [ebp-14h] BYREF
  float v44; // [esp+F0h] [ebp-10h]
  int v45; // [esp+F4h] [ebp-Ch]
  float v46; // [esp+F8h] [ebp-8h]

  v7 = a2;
  sub_6EDAE0(v35);
  sub_6ED830(v35, a2[11]);
  sub_6ED830(v36, a2[11] + 16);
  sub_6ED830(v37, a2[11] + 32);
  v27 = (float)a5;
  v28 = v27 * 0.000244140625;
  sub_7EA610(v34, v28);
  sub_7E82C0(v34, v35, v34);
  v8 = *(_DWORD *)(a1 + 28);
  v9 = (__int16 *)(v8 + a1 + 16);
  v22 = 4096 / a6;
  v29 = 4096 / a7;
  if ( v8 )
  {
    result = a1;
    v11 = 0;
    v12 = 0;
    v20 = 0;
    if ( *(__int16 *)(a1 + 18) > 0 )
    {
      v21 = 0;
      do
      {
        sub_6ED420(v39, v34, v12 + v7[14]);
        v13 = *v9;
        v14 = *v9++;
        if ( v13 > 0 )
        {
          v19 = (float)(v22 * ((int)v39[0] % a6));
          v18 = v19 * 0.000244140625;
          v24 = (float)(v29 * ((int)v39[1] % a7));
          v23 = 0.000244140625 * v24;
          do
          {
            v15 = 16 * *v9;
            sub_6ED4B0(&v40, v15 + a2[15]);
            v42 = 1.0;
            sub_6ED420(&v40, v35, &v40);
            ++v9;
            v40 = (v40 + 3.0) * 0.5;
            v41 = 0.5 * (v41 + 3.0);
            *(float *)(v15 + a4) = v40 + v18;
            *(float *)(v15 + a4 + 4) = v41 + v23;
            --v14;
          }
          while ( v14 );
          v11 = v20;
        }
        result = *(__int16 *)(a1 + 18);
        v7 = a2;
        ++v11;
        v12 = v21 + 16;
        v20 = v11;
        v21 += 16;
      }
      while ( v11 < result );
    }
  }
  else
  {
    result = 0;
    v26 = 0;
    if ( *(__int16 *)(a1 + 18) > 0 )
    {
      v16 = 0;
      v30 = 0;
      do
      {
        sub_6ED420(v38, v34, v16 + a2[14]);
        v31 = v22 * ((int)v38[0] % a6);
        v17 = v30 + a2[15];
        v43 = *(float *)v17;
        v44 = *(float *)(v17 + 4);
        v45 = *(_DWORD *)(v17 + 8);
        v46 = 1.0;
        v25 = v29 * ((int)v38[1] % a7);
        sub_6ED420(&v43, v35, &v43);
        v16 = v30 + 16;
        ++v26;
        v30 = v16;
        v43 = (v43 + 3.0) * 0.5;
        v44 = 0.5 * (v44 + 3.0);
        v32 = (float)v31;
        *(float *)(v16 + a4 - 16) = v32 * 0.000244140625 + v43;
        v33 = (float)v25;
        *(float *)(v16 + a4 - 12) = 0.000244140625 * v33 + v44;
        result = *(__int16 *)(a1 + 18);
      }
      while ( v26 < result );
    }
  }
  return result;
}

