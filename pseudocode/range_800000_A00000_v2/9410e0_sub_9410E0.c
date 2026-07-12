// Function: sub_9410E0
// Address: 0x9410e0
_DWORD *sub_9410E0()
{
  int n5; // edx
  _DWORD *v1; // ebx
  _DWORD *result; // eax
  _BYTE *v3; // ecx
  int v4; // esi
  int v5; // edi
  int v6; // edi
  int v7; // esi
  int v8; // ebx
  int v9; // [esp+8h] [ebp-24h]
  int v10; // [esp+Ch] [ebp-20h]
  int v11; // [esp+10h] [ebp-1Ch]
  int v12; // [esp+18h] [ebp-14h]
  int n5_1; // [esp+1Ch] [ebp-10h]
  _DWORD *v14; // [esp+20h] [ebp-Ch]
  _DWORD *v15; // [esp+24h] [ebp-8h]
  _DWORD *v16; // [esp+28h] [ebp-4h]

  n5 = dword_25D5F4C[unk_25D5F90];
  v1 = (_DWORD *)dword_25D5F54[unk_25D5F90];
  result = (_DWORD *)dword_25D5F44[unk_25D5F90];
  v3 = result;
  n5_1 = n5;
  v15 = v1;
  v14 = v1;
  if ( n5 > 5 )
  {
    v4 = 0;
    v5 = dword_25D5F4C[unk_25D5F90];
    do
    {
      if ( (*v3 & 2) != 0 )
        ++v4;
      v3 += 12;
      --v5;
    }
    while ( v5 );
    v12 = v4;
    if ( n5 - v4 >= 5 )
    {
      v16 = (_DWORD *)dword_25D5F44[unk_25D5F90];
      do
      {
        if ( (*(_BYTE *)result & 2) == 0 )
        {
          v6 = *v1;
          v7 = result[2];
          v8 = v1[1];
          v11 = result[1];
          v10 = v15[2];
          v9 = v15[3];
          *v16 = *result;
          v16[1] = v11;
          v16[2] = v7;
          *v14 = v6;
          v14[1] = v8;
          v1 = v15;
          v14[2] = v10;
          v14[3] = v9;
          v16 += 3;
          n5 = n5_1;
          v14 += 4;
        }
        v1 += 4;
        result += 3;
        --n5;
        v15 = v1;
        n5_1 = n5;
      }
      while ( n5 );
      dword_25D5F4C[unk_25D5F90] -= v12;
      return (_DWORD *)sub_942320();
    }
  }
  return result;
}
