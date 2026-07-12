// Function: sub_A95710
// Address: 0xa95710
// Size: 0x116
// Prototype: 

int __fastcall sub_A95710(int a1, int a2, float *a3, int a4, int a5, int a6, int a7)
{
  int result; // eax
  float v9; // xmm3_4
  float v10; // xmm5_4
  int v12; // edx
  float *v13; // ecx
  float v14; // xmm0_4
  int v15; // eax
  float v16; // xmm1_4
  float v17; // xmm0_4
  bool v18; // cc
  double v19; // xmm1_8
  double v20; // xmm0_8
  float v21; // xmm1_4
  int v22; // [esp+Ch] [ebp-4h]
  int v23; // [esp+20h] [ebp+10h]
  int v24; // [esp+28h] [ebp+18h]

  result = *(_DWORD *)(a1 + 4);
  v9 = *(float *)(a1 + 48);
  v10 = *(float *)(result + 4 * a4 + 12);
  v12 = 0;
  v22 = *(_DWORD *)a1;
  if ( *(int *)a1 > 0 )
  {
    v13 = a3;
    v23 = a5 - (_DWORD)a3;
    v24 = a7 - (_DWORD)a3;
    do
    {
      v14 = *(float *)(*(_DWORD *)(*(_DWORD *)(a1 + 12) + 4 * a4) + 4 * v12) + *(float *)((char *)v13 + a2 - (_DWORD)a3);
      v15 = *(_DWORD *)(a1 + 4);
      if ( v14 > *(float *)(v15 + 108) )
        v14 = *(float *)(v15 + 108);
      v16 = *v13 + v10;
      if ( v14 > v16 )
        v16 = v14;
      result = v23;
      *(float *)((char *)v13 + v23) = v16;
      if ( a4 == 1 )
      {
        result = v24;
        v17 = v14 - *(float *)((char *)v13 + v24);
        v18 = v17 <= -17.200001;
        v19 = (float)(v17 - -17.200001);
        v20 = v9;
        if ( v18 )
        {
          v21 = 1.0 - v19 * 0.0003 * v20;
        }
        else
        {
          v21 = 1.0 - v19 * 0.005 * v20;
          if ( v21 < 0.0 )
            v21 = 0.000099999997;
        }
        *(float *)((char *)v13 + a6 - (_DWORD)a3) = *(float *)((char *)v13 + a6 - (_DWORD)a3) * v21;
      }
      ++v12;
      ++v13;
    }
    while ( v12 < v22 );
  }
  return result;
}

