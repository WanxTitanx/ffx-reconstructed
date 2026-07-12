// Function: sub_A90440
// Address: 0xa90440
// Size: 0xf2
// Prototype: _DWORD __cdecl(int n6)

int __fastcall sub_A90440(_DWORD *a1, _BYTE *a2, int n6)
{
  int n6_1; // eax
  int v4; // edx
  int n32; // edi
  int v6; // ebx
  unsigned __int8 *v7; // eax
  int n6a; // [esp+10h] [ebp+8h]

  n6_1 = n6;
  if ( n6 )
  {
    while ( 1 )
    {
      v4 = a1[4];
      n6a = n6_1 - 1;
      n32 = a1[1] + 8;
      if ( *a1 < v4 - 4 )
        break;
      if ( *a1 > v4 - ((a1[1] + 15) >> 3) )
      {
        a1[3] = 0;
        *a1 = v4;
        a1[1] = 1;
        LOBYTE(v6) = -1;
      }
      else
      {
        if ( a1[1] != -8 )
          break;
        LOBYTE(v6) = 0;
      }
LABEL_14:
      *a2++ = v6;
      n6_1 = n6a;
      if ( !n6a )
        return n6_1;
    }
    v7 = (unsigned __int8 *)a1[3];
    v6 = *v7 >> *((_BYTE *)a1 + 4);
    if ( n32 > 8 )
    {
      v6 |= v7[1] << (8 - *((_BYTE *)a1 + 4));
      if ( n32 > 16 )
      {
        v6 |= *(unsigned __int8 *)(a1[3] + 2) << (16 - *((_BYTE *)a1 + 4));
        if ( n32 > 24 )
        {
          v6 |= *(unsigned __int8 *)(a1[3] + 3) << (24 - *((_BYTE *)a1 + 4));
          if ( n32 > 32 )
          {
            if ( a1[1] )
              v6 |= *(unsigned __int8 *)(a1[3] + 4) << (32 - *((_BYTE *)a1 + 4));
          }
        }
      }
    }
    a1[3] += n32 / 8;
    *a1 += n32 / 8;
    a1[1] = n32 & 7;
    goto LABEL_14;
  }
  return n6_1;
}

