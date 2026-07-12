// Function: sub_A9DEF0
// Address: 0xa9def0
// Size: 0x156
// Prototype: 

void *__fastcall sub_A9DEF0(int a1, _DWORD *a2)
{
  int *v3; // esi
  double *v4; // ebx
  void *result; // eax
  int v6; // eax
  int v7; // edi
  int v8; // esi

  v3 = *(int **)(a1 + 28);
  v4 = (double *)(v3 + 840);
  result = memset(a2, 0, 0x30u);
  if ( v3 != (int *)-3360 && v3[843] > 0 )
  {
    v6 = v3[1] / *v3;
    v7 = *(_DWORD *)(a1 + 8);
    v8 = *v3 >> 1;
    *a2 = 1;
    a2[6] = v6;
    a2[3] = (int)floor((double)*(int *)v4 * (double)v8 / (double)v7 + 0.5);
    a2[4] = (int)floor((double)*((int *)v4 + 1) * (double)v8 / (double)v7 + 0.5);
    a2[5] = (int)floor((double)*((int *)v4 + 2) * (double)v8 / (double)v7 + 0.5);
    *((_QWORD *)a2 + 4) = 0x401C000000000000LL;
    result = (void *)(int)((double)*((int *)v4 + 3) * v4[2]);
    a2[2] = result;
    a2[1] = result;
  }
  return result;
}

