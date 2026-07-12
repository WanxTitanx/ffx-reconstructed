// Function: sub_80CBD0
// Address: 0x80cbd0
int __cdecl sub_80CBD0(int a1, int a2)
{
  int v2; // edx
  unsigned int n0x4000; // eax
  char *v4; // ecx
  float *v5; // edi
  int result; // eax
  double v7; // st7
  double v8; // st7
  int v9; // ebx
  __int16 v10; // ax
  int v11; // ebx
  __int16 v12; // cx
  float v13; // [esp+Ch] [ebp-4h]
  float v14; // [esp+18h] [ebp+8h]
  float v15; // [esp+18h] [ebp+8h]
  float v16; // [esp+18h] [ebp+8h]
  __int16 v17; // [esp+18h] [ebp+8h]

  v2 = *(_DWORD *)(a1 + 544);
  n0x4000 = *(_WORD *)(a1 + 538) & 0xF000;
  v4 = (char *)&unk_12A40C0 + 32 * *(unsigned __int16 *)(v2 + 20);
  v5 = (float *)(v2 + *(unsigned __int8 *)(a2 + 2));
  if ( n0x4000 > 0x2000 )
  {
    if ( n0x4000 == 12288 )
    {
      v9 = *(__int16 *)(a2 + 4);
      v10 = *(_WORD *)(v9 + a2);
      v11 = a2 + v9;
      v17 = v10;
      v12 = sub_7E5C60(v10);
      if ( v12 >= v17 )
        v12 = v17 - 1;
      *v5 = (float)*(__int16 *)(v11 + 2 * v12 + 2);
      return a2 + 6;
    }
    else
    {
      if ( n0x4000 != 0x4000 )
        return a2;
      v13 = (float)*(__int16 *)(a2 + 4);
      v16 = (float)*(__int16 *)(a2 + 6);
      v8 = *v5;
      if ( v13 > v8 )
        v8 = v13;
      result = a2 + 8;
      if ( v16 >= v8 )
        *v5 = v8;
      else
        *v5 = v16;
    }
  }
  else if ( n0x4000 == 0x2000 )
  {
    v7 = (double)(int)sub_79A690(*(_DWORD *)v4, *(unsigned __int8 *)(v2 + 24), 0, 0, 0);
    *v5 = v7;
    return a2 + 4;
  }
  else
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
    {
      if ( n0x4000 == 4096 )
      {
        v14 = (float)*(__int16 *)(a2 + 4);
        v15 = v14 * 0.00390625;
        sub_7E6610(v15);
        *v5 = *v5 + v15;
        return a2 + 6;
      }
      return a2;
    }
    *v5 = (float)(unsigned __int8)v4[8];
    return a2 + 4;
  }
  return result;
}
