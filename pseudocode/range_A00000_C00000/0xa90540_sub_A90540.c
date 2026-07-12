// Function: sub_A90540
// Address: 0xa90540
// Size: 0x14a
// Prototype: _DWORD __cdecl(int n6)

unsigned __int8 *__fastcall sub_A90540(int *a1, unsigned __int8 *a2, int n6)
{
  int n6_1; // ecx
  unsigned __int8 *result; // eax
  unsigned __int8 v6; // bl
  int n2147483391; // ecx
  char *v8; // eax
  int v9; // ecx
  int v10; // ecx
  int n32; // edi
  int v12; // eax
  unsigned __int8 *v13; // [esp+4h] [ebp-4h]
  int n6a; // [esp+10h] [ebp+8h]

  n6_1 = n6;
  result = a2;
  v13 = a2;
  if ( n6 )
  {
    while ( 1 )
    {
      v6 = *result;
      n6a = n6_1 - 1;
      n2147483391 = a1[4];
      if ( *a1 < n2147483391 - 4 )
        goto LABEL_7;
      if ( a1[3] )
        break;
LABEL_18:
      n6_1 = n6a;
      result = ++v13;
      if ( !n6a )
        return result;
    }
    if ( n2147483391 > 2147483391 || (v8 = (char *)realloc_0((void *)a1[2], n2147483391 + 256)) == 0 )
    {
      if ( a1[2] )
        free_1((void *)a1[2]);
      *(_QWORD *)a1 = 0;
      *((_QWORD *)a1 + 1) = 0;
      a1[4] = 0;
      goto LABEL_18;
    }
    v9 = *a1;
    a1[4] += 256;
    a1[2] = (int)v8;
    a1[3] = (int)&v8[v9];
LABEL_7:
    v10 = a1[1];
    n32 = v10 + 8;
    *(_BYTE *)a1[3] |= v6 << v10;
    if ( v10 + 8 >= 8 )
    {
      *(_BYTE *)(a1[3] + 1) = v6 >> (8 - *((_BYTE *)a1 + 4));
      if ( n32 >= 16 )
      {
        *(_BYTE *)(a1[3] + 2) = v6 >> (16 - *((_BYTE *)a1 + 4));
        if ( n32 >= 24 )
        {
          *(_BYTE *)(a1[3] + 3) = v6 >> (24 - *((_BYTE *)a1 + 4));
          if ( n32 >= 32 )
          {
            v12 = a1[1];
            if ( v12 )
              *(_BYTE *)(a1[3] + 4) = v6 >> (32 - v12);
            else
              *(_BYTE *)(a1[3] + 4) = 0;
          }
        }
      }
    }
    *a1 += n32 / 8;
    a1[3] += n32 / 8;
    a1[1] = n32 & 7;
    goto LABEL_18;
  }
  return result;
}

