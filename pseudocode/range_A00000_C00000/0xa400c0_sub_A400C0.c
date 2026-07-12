// Function: sub_A400C0
// Address: 0xa400c0
// Size: 0x160
// Prototype: int __cdecl(int, int, int, int, int, int, float)

_DWORD *__cdecl sub_A400C0(int a1, int a2, _DWORD *a3, int a4, int a5, int a6, float a7)
{
  _DWORD *v7; // ebx
  _DWORD *v8; // eax
  _DWORD *result; // eax
  unsigned int *v10; // esi
  int v11; // eax
  unsigned int *v12; // edi
  _DWORD *v13; // eax
  float v14[3]; // [esp+4h] [ebp-3Ch] BYREF
  float v15; // [esp+10h] [ebp-30h]
  float v16[3]; // [esp+14h] [ebp-2Ch] BYREF
  float v17; // [esp+20h] [ebp-20h]
  double v18; // [esp+24h] [ebp-1Ch]
  _DWORD v19[4]; // [esp+2Ch] [ebp-14h] BYREF
  float v20; // [esp+3Ch] [ebp-4h]

  v7 = a3;
  v8 = sub_A3F280(a3, (unsigned int *)&a1);
  if ( !v8 || (result = v8 + 4) == 0 )
  {
    sub_A413D0(v14, a2 + 12 * a1, a5, a6);
    v10 = *(unsigned int **)a4;
    v11 = (*(_DWORD *)(a4 + 4) - *(_DWORD *)a4) >> 2;
    v19[0] = v11;
    if ( !v11 )
      goto LABEL_9;
    v12 = &v10[v11];
    if ( v10 == v12 )
      goto LABEL_9;
    v18 = 1.0 - a7;
    while ( 1 )
    {
      sub_A413D0(v16, a2 + 12 * *v10, a5, a6);
      v20 = v14[0] * v16[0];
      v20 = v20 + v14[1] * v16[1];
      v20 = v20 + v14[2] * v16[2];
      if ( v20 > v18 )
      {
        *(float *)&v19[3] = v17;
        *(float *)&v19[2] = v15;
        *(float *)&v19[1] = v15;
        v20 = v15 - v17;
        v20 = fabs(v20);
        if ( a7 > (double)v20 )
          break;
      }
      if ( ++v10 == v12 )
        goto LABEL_9;
    }
    if ( v10 == v12 )
    {
LABEL_9:
      sub_A42520(&a1, v19);
      return (_DWORD *)sub_A42690(&a1);
    }
    else
    {
      v13 = sub_A3F280(v7, v10);
      if ( v13 )
        return (_DWORD *)sub_A42520(&a1, v13 + 4);
      else
        return (_DWORD *)sub_A42520(&a1, 0);
    }
  }
  return result;
}

