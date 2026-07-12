// Function: sub_A9E4F0
// Address: 0xa9e4f0
// Size: 0x18e
// Prototype: _DWORD __cdecl(int n16, _DWORD *, _DWORD)

_DWORD *__fastcall sub_A9E4F0(int a1, _DWORD *a2, int n16, _DWORD *size_3, int size_4)
{
  char *v6; // edi
  _DWORD *size; // eax
  void *v8; // esp
  int *v9; // edx
  int v10; // eax
  unsigned int v11; // edi
  int *v12; // ecx
  int v13; // edi
  int *v14; // ecx
  int v15; // edx
  int size_2; // edi
  int n16a_1; // ecx
  float v18; // xmm1_4
  unsigned int size_5; // eax
  int n16_1; // edx
  float *v21; // ecx
  unsigned int v22; // edi
  float *v23; // edx
  float v24; // xmm0_4
  int v25; // ecx
  int v26; // edx
  float v27; // xmm0_4
  int buf_; // [esp+0h] [ebp-20h] BYREF
  int v29; // [esp+4h] [ebp-1Ch] BYREF
  int v30; // [esp+8h] [ebp-18h] BYREF
  int v31; // [esp+Ch] [ebp-14h]
  char *v32; // [esp+14h] [ebp-Ch]
  int size_1; // [esp+18h] [ebp-8h]
  int n16_2; // [esp+1Ch] [ebp-4h]
  int n16a; // [esp+28h] [ebp+8h]

  v6 = (char *)a2;
  size = (_DWORD *)(4 * (n16 + size_4));
  v32 = (char *)a2;
  v31 = a1;
  v8 = alloca((int)size);
  if ( a2 )
  {
    size = 0;
    if ( n16 >= 4 )
    {
      v9 = a2 + 3;
      v10 = v6 - (char *)&buf_;
      v11 = ((unsigned int)(n16 - 4) >> 2) + 1;
      v12 = &v29;
      size_1 = 4 * v11;
      do
      {
        *(v12 - 1) = *(v9 - 3);
        *v12 = *(int *)((char *)v12 + v10);
        v12[1] = *(v9 - 1);
        v12[2] = *v9;
        v12 += 4;
        v9 += 4;
        --v11;
      }
      while ( v11 );
      v6 = v32;
      size = (_DWORD *)size_1;
    }
    if ( (int)size < n16 )
    {
      v13 = v6 - (char *)&buf_;
      v14 = &buf_ + (_DWORD)size;
      v15 = n16 - (_DWORD)size;
      do
      {
        size = *(_DWORD **)((char *)v14 + v13);
        *v14++ = (int)size;
        --v15;
      }
      while ( v15 );
    }
  }
  else if ( n16 > 0 )
  {
    size = 0;
    memset(&buf_, 0, 4 * n16);
  }
  size_2 = 0;
  size_1 = 0;
  if ( size_4 > 0 )
  {
    v32 = (char *)&v30;
    do
    {
      n16a_1 = 0;
      v18 = 0.0;
      size_5 = size_2;
      n16_1 = n16;
      n16a = 0;
      if ( n16 >= 4 )
      {
        v21 = (float *)v32;
        v22 = ((unsigned int)(n16 - 4) >> 2) + 1;
        n16a = 4 * v22;
        size_5 = 4 * v22 + size_1;
        n16_2 = n16 - 4 * v22;
        v23 = (float *)(v31 - 8 + 4 * n16);
        do
        {
          v24 = v23[1] * *(v21 - 2);
          v21 += 4;
          v23 -= 4;
          v18 = (float)((float)((float)(v18 - v24) - (float)(*(v21 - 5) * v23[4])) - (float)(v23[3] * *(v21 - 4)))
              - (float)(v23[2] * *(v21 - 3));
          --v22;
        }
        while ( v22 );
        size_2 = size_1;
        n16a_1 = n16a;
        n16_1 = n16_2;
      }
      if ( n16a_1 < n16 )
      {
        v25 = v31 + 4 * n16_1;
        v26 = n16 - n16a;
        do
        {
          v27 = *((float *)&buf_ + size_5) * *(float *)(v25 - 4);
          v25 -= 4;
          ++size_5;
          v18 = v18 - v27;
          --v26;
        }
        while ( v26 );
      }
      v32 += 4;
      *((float *)&buf_ + size_5) = v18;
      size = size_3;
      *(float *)&size_3[size_2++] = v18;
      size_1 = size_2;
    }
    while ( size_2 < size_4 );
  }
  return size;
}

