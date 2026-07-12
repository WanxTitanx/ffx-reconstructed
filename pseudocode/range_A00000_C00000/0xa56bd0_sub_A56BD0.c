// Function: sub_A56BD0
// Address: 0xa56bd0
// Size: 0x1dd
// Prototype: 

int __cdecl sub_A56BD0(float *a1)
{
  int v2; // edi
  int n64; // ebx
  char v4; // al
  char n64_1; // dl
  int v6; // edx
  double v7; // st6
  double v8; // st7
  int v9; // ecx
  int result; // eax
  int v11; // eax
  float *v12; // ecx
  double v13; // st7
  char v14; // bl
  char v15; // dl
  float v16; // [esp+14h] [ebp+8h]
  float v17; // [esp+14h] [ebp+8h]
  float v18; // [esp+14h] [ebp+8h]
  float v19; // [esp+14h] [ebp+8h]

  a1[1] = 0.0;
  v2 = 0;
  *a1 = 0.0;
  n64 = sub_8BE420(0, 0, 2) - 128;
  v4 = sub_8BE420(0, 0, 3);
  n64_1 = v4 + 0x80;
  if ( (unsigned __int8)(n64 + 63) > 0x7Eu || (unsigned __int8)(v4 - 65) > 0x7Eu )
  {
    v12 = (float *)(dword_2305834[0] + 71140);
    v13 = *(float *)(dword_2305834[0] + 71140);
    if ( n64_1 * n64_1 + (char)n64 * (char)n64 <= 14400 )
    {
      v17 = v13 - 0.1;
      *v12 = v17;
      if ( v17 < 1.0 )
        *v12 = 1.0;
    }
    else
    {
      v16 = v13 + 0.1;
      *v12 = v16;
      if ( v16 > 2.0 )
        *v12 = 2.0;
    }
    if ( (char)n64 <= 64 )
    {
      if ( (char)n64 >= -64 )
        v14 = 0;
      else
        v14 = n64 + 64;
    }
    else
    {
      v14 = n64 - 64;
    }
    if ( n64_1 <= 64 )
    {
      if ( n64_1 >= -64 )
        v15 = 0;
      else
        v15 = v4 - 64;
    }
    else
    {
      v15 = v4 + 64;
    }
    v18 = (float)v14;
    *a1 = v18 * 0.125 * *v12;
    v19 = (float)v15;
    a1[1] = 0.125 * v19 * *v12;
    return 1;
  }
  v6 = dword_2305834[0];
  if ( (*(_WORD *)(dword_2305834[0] + 71276) & 0x8000) != 0 )
  {
    v7 = -1.0;
    v8 = 1.0;
    v9 = 1;
    *a1 = -1.0;
  }
  else
  {
    if ( (*(_WORD *)(dword_2305834[0] + 71276) & 0x2000) != 0 )
    {
      *a1 = 1.0;
      v9 = 1;
    }
    else
    {
      v9 = 0;
    }
    v7 = -1.0;
    v8 = 1.0;
  }
  if ( (*(_WORD *)(v6 + 71276) & 0x1000) != 0 )
  {
    a1[1] = v7;
LABEL_13:
    v2 = 1;
    goto LABEL_14;
  }
  if ( (*(_WORD *)(v6 + 71276) & 0x4000) != 0 )
  {
    a1[1] = v8;
    goto LABEL_13;
  }
LABEL_14:
  if ( !(v9 | v2) )
  {
    *(_BYTE *)(dword_2305834[0] + 71114) = 0;
LABEL_16:
    a1[2] = 0.0;
    a1[3] = v8;
    return 0;
  }
  if ( v9 == v2 )
    goto LABEL_16;
  v11 = dword_2305834[0];
  ++*(_BYTE *)(dword_2305834[0] + 71114);
  if ( *(_BYTE *)(v11 + 71114) >= 2u )
  {
    *(_BYTE *)(dword_2305834[0] + 71114) = 2;
    a1[2] = 0.0;
    result = 0;
  }
  else
  {
    a1[1] = 0.0;
    *a1 = 0.0;
    result = 0;
    a1[2] = 0.0;
  }
  a1[3] = v8;
  return result;
}

