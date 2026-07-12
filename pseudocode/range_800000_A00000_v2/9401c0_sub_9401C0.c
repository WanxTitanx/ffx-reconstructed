// Function: sub_9401C0
// Address: 0x9401c0
int sub_9401C0()
{
  int v0; // ebx
  int v1; // edi
  _BYTE *v2; // edx
  int n2; // eax
  int v4; // ecx
  int v5; // ecx
  _DWORD *v6; // esi
  _DWORD *v7; // ebx
  int v8; // edi
  int v9; // ecx
  int v10; // eax
  int v11; // [esp+8h] [ebp-10h]
  int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  _BYTE *v14; // [esp+14h] [ebp-4h]

  v0 = dword_25D5F54[unk_25D5F90];
  v1 = dword_25D5F4C[unk_25D5F90];
  v14 = (_BYTE *)dword_25D5F44[unk_25D5F90];
  v2 = v14;
  n2 = 0;
  v4 = 0;
  v13 = v0;
  if ( v1 > 0 )
  {
    while ( 1 )
    {
      if ( (*v2 & 2) != 0 )
      {
        *(&v11 + n2++) = v4;
        if ( n2 == 2 )
          break;
      }
      ++v4;
      v2 += 12;
      if ( v4 >= v1 )
        return n2;
    }
    v5 = v12;
    if ( v1 > v12 )
    {
      v6 = (_DWORD *)(v0 + 16 * v1);
      v7 = &v14[12 * v1];
      v8 = v1 - v12;
      do
      {
        *v7 = *(v7 - 3);
        v7[1] = *(v7 - 2);
        v7[2] = *(v7 - 1);
        *v6 = *(v6 - 4);
        v6[1] = *(v6 - 3);
        v6[2] = *(v6 - 2);
        v6[3] = *(v6 - 1);
        v7 -= 3;
        v6 -= 4;
        --v8;
      }
      while ( v8 );
      v5 = v12;
      v0 = v13;
    }
    v9 = 2 * v5;
    v10 = 2 * v11;
    *(float *)(v0 + 8 * v9) = (*(float *)(v0 + 8 * v9) + *(float *)(v0 + 16 * v11)) * 0.5;
    *(float *)(v0 + 8 * v9 + 4) = (*(float *)(v0 + 8 * v10 + 4) + *(float *)(v0 + 8 * v9 + 4)) * 0.5;
    *(float *)(v0 + 8 * v9 + 8) = 0.5 * (*(float *)(v0 + 8 * v10 + 8) + *(float *)(v0 + 8 * v9 + 8));
    ++dword_25D5F4C[unk_25D5F90];
    return sub_942320();
  }
  return n2;
}
