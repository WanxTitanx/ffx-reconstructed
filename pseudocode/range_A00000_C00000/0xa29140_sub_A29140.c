// Function: sub_A29140
// Address: 0xa29140
// Size: 0x1aa
// Prototype: int __cdecl(int, char *Str, int)

int __cdecl sub_A29140(_BYTE *i, char *Str, unsigned int *a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // ecx
  unsigned int v6; // edx
  unsigned int *v7; // ecx
  _DWORD *v8; // edx
  const char *p_Val_1; // edi
  char *p_Val; // esi
  _BYTE *v12; // eax
  int *v13; // ecx
  _BYTE *v14; // [esp+10h] [ebp-14h]
  int *v15; // [esp+18h] [ebp-Ch]
  int v16; // [esp+1Ch] [ebp-8h]
  unsigned int v17; // [esp+20h] [ebp-4h]

  v3 = sub_A290D0(i, Str);
  v17 = v3;
  if ( v3 != *a3 )
  {
    v4 = 0;
    if ( v3 )
    {
      v4 = (_DWORD *)sub_42FC60(4 * v3, 4);
      if ( v4 )
      {
        if ( v17 )
        {
          v5 = v4;
          v6 = v17;
          do
          {
            if ( v5 )
              *v5 = 0;
            ++v5;
            --v6;
          }
          while ( v6 );
        }
      }
      else if ( v17 )
      {
        return 13;
      }
    }
    v7 = a3;
    v8 = (_DWORD *)a3[1];
    if ( v8 != v4 )
    {
      if ( (*a3 & 0x80000000) == 0 )
        sub_434460(v8, *a3 & 0x7FFFFFFF);
      v7 = a3;
    }
    v7[1] = (unsigned int)v4;
    *v7 = v17;
  }
  p_Val_1 = sub_A29030(i, Str);
  v16 = 0;
  if ( !v17 )
    return 0;
  while ( 1 )
  {
    p_Val = (char *)p_Val_1;
    if ( !Str || !p_Val_1 )
      goto LABEL_25;
    if ( *p_Val_1 )
    {
      while ( !strchr(Str, *p_Val) )
      {
        if ( !*++p_Val )
          goto LABEL_25;
      }
    }
    if ( !*p_Val )
LABEL_25:
      p_Val = (char *)&p_Val_1[strlen(p_Val_1)];
    v15 = (int *)(a3[1] + 4 * v16);
    if ( !p_Val_1 || !p_Val )
      return 1;
    if ( p_Val < p_Val_1 )
      return 5;
    v12 = (_BYTE *)sub_42FC60(p_Val - p_Val_1 + 1, 2);
    v14 = v12;
    if ( !v12 )
      return 13;
    memcpy(v12, p_Val_1, p_Val - p_Val_1 + 1);
    v13 = v15;
    v14[p_Val - p_Val_1] = 0;
    if ( (*(_BYTE *)v15 & 1) == 0 )
    {
      Phyre_Memory_AlignedFree(*v15);
      v13 = v15;
    }
    *v13 = (int)v14;
    p_Val_1 = sub_A29030(p_Val, Str);
    if ( ++v16 >= v17 )
      return 0;
  }
}

