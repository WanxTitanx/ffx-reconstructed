// Function: sub_A93CA0
// Address: 0xa93ca0
// Size: 0x157
// Prototype: 

int __cdecl sub_A93CA0(int *a1, int a2, int a3, int a4)
{
  int v4; // esi
  int v5; // eax
  int v6; // ecx
  int i; // eax
  float v8; // xmm0_4
  int v10; // eax
  float *v11; // ecx
  int v12; // eax
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm0_4

  if ( a1[2] > 0 )
  {
    v4 = 0;
    if ( *a1 <= 8 )
    {
      if ( a4 > 0 )
      {
        while ( 1 )
        {
          v10 = sub_A94200(a1, a3);
          if ( v10 == -1 )
            return -1;
          v11 = (float *)(a1[4] + 4 * v10 * *a1);
          v12 = 0;
          switch ( *a1 )
          {
            case 1:
              goto LABEL_20;
            case 2:
              goto LABEL_19;
            case 3:
              goto LABEL_18;
            case 4:
              goto LABEL_17;
            case 5:
              goto LABEL_16;
            case 6:
              goto LABEL_15;
            case 7:
              goto LABEL_14;
            case 8:
              v13 = *v11 + *(float *)(a2 + 4 * v4);
              v12 = 1;
              ++v4;
              *(float *)(a2 + 4 * v4 - 4) = v13;
LABEL_14:
              v14 = v11[v12++] + *(float *)(a2 + 4 * v4++);
              *(float *)(a2 + 4 * v4 - 4) = v14;
LABEL_15:
              v15 = v11[v12++] + *(float *)(a2 + 4 * v4++);
              *(float *)(a2 + 4 * v4 - 4) = v15;
LABEL_16:
              v16 = v11[v12++] + *(float *)(a2 + 4 * v4++);
              *(float *)(a2 + 4 * v4 - 4) = v16;
LABEL_17:
              v17 = v11[v12++] + *(float *)(a2 + 4 * v4++);
              *(float *)(a2 + 4 * v4 - 4) = v17;
LABEL_18:
              v18 = v11[v12++] + *(float *)(a2 + 4 * v4++);
              *(float *)(a2 + 4 * v4 - 4) = v18;
LABEL_19:
              v19 = v11[v12++] + *(float *)(a2 + 4 * v4++);
              *(float *)(a2 + 4 * v4 - 4) = v19;
LABEL_20:
              v20 = v11[v12] + *(float *)(a2 + 4 * v4++);
              *(float *)(a2 + 4 * v4 - 4) = v20;
              break;
            default:
              break;
          }
          if ( v4 >= a4 )
            return 0;
        }
      }
    }
    else if ( a4 > 0 )
    {
      while ( 1 )
      {
        v5 = sub_A94200(a1, a3);
        if ( v5 == -1 )
          break;
        v6 = a1[4] + 4 * v5 * *a1;
        for ( i = 0; i < *a1; *(float *)(a2 + 4 * v4 - 4) = v8 )
          v8 = *(float *)(v6 + 4 * i++) + *(float *)(a2 + 4 * v4++);
        if ( v4 >= a4 )
          return 0;
      }
      return -1;
    }
  }
  return 0;
}

