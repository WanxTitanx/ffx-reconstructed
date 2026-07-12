// Function: sub_A3DBF0
// Address: 0xa3dbf0
// Size: 0xc2
// Prototype: 

int __thiscall sub_A3DBF0(int *this, int a2, int *a3)
{
  int v4; // edi
  int v5; // eax
  int result; // eax
  int **v7; // ecx
  int v8; // edx
  _DWORD *v9; // ebx
  _DWORD *v10; // ecx
  int v11; // eax
  int **v12; // [esp+8h] [ebp-4h] BYREF

  v4 = *(this + 1) & 0x7FFFFFFF;
  if ( v4 )
  {
    v12 = 0;
    v5 = sub_A3D6F0(v4);
    result = sub_5B5AE0(sub_A3D6D0, v5, &v12);
    if ( result )
      return result;
    v7 = v12;
    *v12 = this;
    v7[1] = a3;
    v7[2] = (int *)v4;
    v8 = 0;
    v9 = v7 + 3;
    do
    {
      v10 = (_DWORD *)(v8 * 4 + *(this + 2));
      v8 += 6;
      v9[v8 - 6] = *v10;
      v9[v8 - 5] = v10[1];
      v9[v8 - 4] = v10[2];
      v9[v8 - 3] = v10[3];
      v9[v8 - 2] = v10[4];
      v9[v8 - 1] = v10[5];
      --v4;
    }
    while ( v4 );
    v11 = *(this + 1);
    if ( v11 )
    {
      if ( *(this + 2) )
      {
        if ( v11 >= 0 )
          Phyre_Memory_AlignedFree(*(this + 2));
      }
      *(this + 2) = 0;
      *(this + 1) = 0;
    }
  }
  return 0;
}

