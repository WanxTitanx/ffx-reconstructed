// Function: sub_A6D890
// Address: 0xa6d890
// Size: 0x350
// Prototype: 

int __cdecl sub_A6D890(int a1, int a2, _DWORD *a3, int a4, int a5, int a6, int a7)
{
  int v7; // ebx
  float *v8; // esi
  float *v9; // edi
  int v10; // ebx
  bool v11; // zf
  int result; // eax
  int v13; // edx
  double v14; // st7
  __int16 *v15; // ecx
  __int16 v16; // ax
  __int16 v17; // si
  int v18; // ecx
  int v19; // eax
  double v20; // st6
  int v21; // eax
  double v22; // st6
  int v23; // eax
  __int16 v24; // si
  int i; // ecx
  int n3_1; // ecx
  int v27; // edx
  double v28; // st6
  int v29; // [esp+14h] [ebp-104h]
  float v30; // [esp+1Ch] [ebp-FCh]
  float v31; // [esp+20h] [ebp-F8h]
  __int16 *v32; // [esp+28h] [ebp-F0h]
  __int16 *v33; // [esp+28h] [ebp-F0h]
  int n3; // [esp+2Ch] [ebp-ECh]
  int v35; // [esp+2Ch] [ebp-ECh]
  float v36; // [esp+30h] [ebp-E8h]
  float v37; // [esp+30h] [ebp-E8h]
  int v38; // [esp+30h] [ebp-E8h]
  _BYTE v39[60]; // [esp+38h] [ebp-E0h] BYREF
  _BYTE v40[64]; // [esp+74h] [ebp-A4h] BYREF
  _BYTE v41[64]; // [esp+B4h] [ebp-64h] BYREF
  float v42[3]; // [esp+F4h] [ebp-24h] BYREF
  float v43; // [esp+100h] [ebp-18h]
  float v44[4]; // [esp+104h] [ebp-14h] BYREF

  v31 = (double)*(unsigned __int8 *)(a2 + 76) * 0.0078125;
  if ( !dword_22FB3E0[a7] )
    dword_22FB3E0[a7] = sub_687190(16 * *(__int16 *)(a1 + 20), (void *)0x10);
  v29 = dword_22FB3E0[a7];
  sub_A690C0(v40, v41);
  sub_A6CD80((int)v41, (int)v41, *(_DWORD *)(a2 + 44));
  unk_C8F52C = unk_11A0004;
  unk_C8F530 = unk_11A0008;
  unk_C8F534 = unk_11A000C;
  a3[160] = unk_11A0000;
  a3[161] = unk_C8F52C;
  a3[162] = unk_C8F530;
  a3[163] = unk_C8F534;
  unk_C8F52C = unk_11A0034;
  unk_C8F530 = unk_11A0038;
  unk_C8F534 = unk_11A003C;
  MEMORY[0xC8F528] = unk_11A0030;
  a3[164] = unk_11A0030;
  a3[165] = unk_C8F52C;
  a3[166] = unk_C8F530;
  a3[167] = unk_C8F534;
  v7 = *(_DWORD *)(a2 + 44);
  v8 = (float *)v39;
  v32 = (__int16 *)(a1 + *(_DWORD *)(a1 + 28) + 16);
  v9 = (float *)(v7 + 8);
  v10 = v7 - (_DWORD)v39;
  n3 = 3;
  do
  {
    v36 = sqrt(*(float *)((char *)v8 + v10) * *(float *)((char *)v8 + v10) + *(v9 - 1) * *(v9 - 1) + *v9 * *v9);
    v8 += 4;
    v9 += 4;
    v11 = n3-- == 1;
    v37 = 1.0 / v36;
    *(v8 - 5) = *(float *)((char *)v8 + v10 - 16) * v37;
    *(v8 - 4) = *(v9 - 5) * v37;
    *(v8 - 3) = v37 * *(v9 - 4);
    *(v8 - 2) = *(v9 - 3);
  }
  while ( !v11 );
  result = a1;
  v13 = 0;
  v38 = 0;
  if ( *(__int16 *)(a1 + 18) > 0 )
  {
    v14 = 1.0;
    v15 = v32;
    do
    {
      v16 = *v15++;
      v35 = v16;
      if ( v16 > 0 )
      {
        do
        {
          v17 = 4 * *v15;
          v33 = v15 + 1;
          v18 = *(_DWORD *)(a2 + 60);
          v19 = v17++;
          v20 = *(float *)(v18 + 4 * v19);
          v21 = v17++;
          v42[0] = -v20;
          v22 = *(float *)(v18 + 4 * v21);
          v23 = v17;
          v24 = v17 - 2;
          v42[1] = -v22;
          v42[2] = -*(float *)(v18 + 4 * v23);
          v43 = v14;
          sub_6ED420(v44, v41, v42);
          for ( i = 0; i < 4; ++i )
          {
            if ( v44[i] < 0.0 )
              v44[i] = 0.0;
          }
          v44[3] = 1.0;
          sub_6ED420(v44, v40, v44);
          n3_1 = 0;
          v27 = v29 + 4 * v24;
          do
          {
            if ( v44[n3_1] < 0.0 )
              v44[n3_1] = 0.0;
            v28 = v44[n3_1++] * v31;
            v27 += 4;
            v30 = v28;
            v44[n3_1 - 1] = v30;
            *(float *)(v27 - 4) = (v30 * *(float *)(a6 + 4 * n3_1 - 4) * *(float *)(a5 + 4 * n3_1 - 4)
                                 + *(float *)(a4 + 4 * n3_1 - 4))
                                / 255.0;
          }
          while ( n3_1 < 3 );
          v11 = v35-- == 1;
          v14 = 1.0;
          v15 = v33;
        }
        while ( !v11 );
        v13 = v38;
        v14 = 1.0;
      }
      ++v13;
      result = *(__int16 *)(a1 + 18);
      v38 = v13;
    }
    while ( v13 < result );
  }
  return result;
}

