// Function: sub_A92A60
// Address: 0xa92a60
// Size: 0x1a5
// Prototype: 

void *__fastcall sub_A92A60(int a1, int a2, int a3)
{
  int v3; // esi
  int v4; // eax
  int v5; // edi
  int v6; // ebx
  int v7; // eax
  int n32; // edx
  unsigned int v9; // esi
  int n32_1; // eax
  int v11; // ecx
  int i; // ecx
  unsigned int v13; // edx
  int v14; // edx
  int v15; // edx
  int v16; // edi
  int *v17; // esi
  int v18; // eax
  char v19; // dl
  int v20; // ecx
  int v21; // ebx
  unsigned int v22; // edx
  _DWORD v25[33]; // [esp+Ch] [ebp-94h] BYREF
  int v26; // [esp+90h] [ebp-10h]
  int v27; // [esp+94h] [ebp-Ch]
  void *Block; // [esp+98h] [ebp-8h]
  char v29; // [esp+9Fh] [ebp-1h]

  v3 = a3;
  v4 = a2;
  v26 = a2;
  v5 = 0;
  if ( a3 )
    v4 = a3;
  v27 = a1;
  Block = malloc_0(4 * v4);
  memset(v25, 0, sizeof(v25));
  v6 = 0;
  if ( v26 <= 0 )
    goto LABEL_22;
  v7 = v27;
  do
  {
    n32 = *(char *)(v6 + v7);
    if ( n32 <= 0 )
    {
      if ( !v3 )
        ++v5;
    }
    else
    {
      v9 = v25[n32];
      if ( n32 < 32 && v9 >> n32 )
        goto LABEL_38;
      *((_DWORD *)Block + v5++) = v9;
      n32_1 = n32;
      while ( 1 )
      {
        v11 = v25[n32_1];
        if ( (v11 & 1) != 0 )
          break;
        v25[n32_1--] = v11 + 1;
        if ( n32_1 <= 0 )
          goto LABEL_15;
      }
      if ( n32_1 == 1 )
        ++v25[1];
      else
        v25[n32_1] = 2 * v25[n32_1 - 1];
LABEL_15:
      for ( i = n32 + 1; i < 33; v9 = v13 )
      {
        v13 = v25[i];
        if ( v13 >> 1 != v9 )
          break;
        v25[i] = 2 * v25[i - 1];
        ++i;
      }
      v3 = a3;
      v7 = v27;
    }
    v14 = v26;
    ++v6;
  }
  while ( v6 < v26 );
  if ( v5 == 1 && v25[2] == 2 )
  {
LABEL_26:
    v16 = 0;
    if ( v14 > 0 )
    {
      v17 = (int *)Block;
      do
      {
        v18 = 0;
        v19 = *(_BYTE *)(v16 + v27);
        v20 = 0;
        v29 = v19;
        v21 = v19;
        if ( v19 > 0 )
        {
          do
          {
            v22 = (unsigned int)*v17 >> v20++;
            v18 = v22 & 1 | (2 * v18);
          }
          while ( v20 < v21 );
          v19 = v29;
        }
        if ( !a3 || v19 )
          *v17++ = v18;
        ++v16;
      }
      while ( v16 < v26 );
    }
    return Block;
  }
  else
  {
LABEL_22:
    v15 = 1;
    while ( ((0xFFFFFFFF >> (32 - v15)) & v25[v15]) == 0 )
    {
      if ( ++v15 >= 33 )
      {
        v14 = v26;
        goto LABEL_26;
      }
    }
LABEL_38:
    free_1(Block);
    return 0;
  }
}

