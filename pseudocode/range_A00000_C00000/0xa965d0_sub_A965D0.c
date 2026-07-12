// Function: sub_A965D0
// Address: 0xa965d0
// Size: 0x1a1
// Prototype: 

int __fastcall sub_A965D0(int *a1, int a2, int a3, int a4, int a5, float a6)
{
  int *v6; // ebx
  int result; // eax
  int v8; // ecx
  float v9; // xmm6_4
  int v10; // esi
  int v11; // edx
  int v12; // ebx
  float v13; // xmm4_4
  int v14; // edi
  int v15; // eax
  int n16; // edi
  int n7_1; // edx
  int n7; // ecx
  double n7_2; // xmm0_8
  int v20; // edx
  int v21; // edi
  int v22; // eax
  int v23; // ecx
  float v24; // xmm0_4
  float *v25; // [esp+8h] [ebp-18h]
  int v26; // [esp+Ch] [ebp-14h]
  int v28; // [esp+14h] [ebp-Ch]
  int v29; // [esp+18h] [ebp-8h]
  int *v30; // [esp+1Ch] [ebp-4h]
  int v31; // [esp+34h] [ebp+14h]

  v6 = a1;
  result = a1[1];
  v8 = *a1;
  v9 = *(float *)(result + 496) - a6;
  v10 = 0;
  v30 = v6;
  v28 = v8;
  v31 = 0;
  if ( v8 > 0 )
  {
    v11 = a3;
    do
    {
      v12 = v6[5];
      v13 = *(float *)(v11 + 4 * v10);
      v14 = *(_DWORD *)(v12 + 4 * v10);
      v15 = v10 + 1;
      if ( v10 + 1 < v8 )
      {
        do
        {
          if ( *(_DWORD *)(v12 + 4 * v10 + 4) != v14 )
            break;
          v10 = v15;
          if ( *(float *)(v11 + 4 * v15) > v13 )
            v13 = *(float *)(v11 + 4 * v15);
          ++v15;
        }
        while ( v10 + 1 < v8 );
        v31 = v10;
      }
      result = a4;
      if ( (float)(v13 + 6.0) > *(float *)(a4 + 4 * v10) )
      {
        n16 = v14 >> v30[8];
        if ( n16 < 17 )
        {
          if ( n16 < 0 )
            n16 = 0;
        }
        else
        {
          n16 = 16;
        }
        v29 = v30[9];
        n7_1 = 0;
        n7 = 7;
        n7_2 = ((float)(v13 + v9) - 30.0) * 0.1000000014901161;
        if ( (int)n7_2 > 0 )
          n7_1 = (int)n7_2;
        if ( n7_1 < 7 )
          n7 = n7_1;
        v20 = v30[9];
        v25 = *(float **)(*(_DWORD *)(a2 + 4 * n16) + 4 * n7);
        v21 = (int)v25[1];
        v22 = *(_DWORD *)(v12 + 4 * v10);
        v6 = v30;
        v23 = (int)*v25;
        result = (int)(float)((float)((float)(v22 - v30[7]) + (float)((float)(*v25 - 16.0) * (float)v29))
                            - (float)(v29 >> 1));
        if ( v23 >= v21 )
        {
          v8 = v28;
          v11 = a3;
          goto LABEL_27;
        }
        v26 = v30[10];
        do
        {
          if ( result > 0 )
          {
            v20 = v29;
            v24 = v25[v23 + 2] + v13;
            if ( v24 > *(float *)(a5 + 4 * result) )
              *(float *)(a5 + 4 * result) = v24;
          }
          result += v20;
          if ( result >= v26 )
            break;
          ++v23;
        }
        while ( v23 < v21 );
        v10 = v31;
        v8 = v28;
        v11 = a3;
      }
      v6 = v30;
LABEL_27:
      v31 = ++v10;
    }
    while ( v10 < v8 );
  }
  return result;
}

