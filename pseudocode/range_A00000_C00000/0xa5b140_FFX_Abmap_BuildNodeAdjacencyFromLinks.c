// Function: FFX_Abmap_BuildNodeAdjacencyFromLinks
// Address: 0xa5b140
// Size: 0xea
// Prototype: int()

int FFX_Abmap_BuildNodeAdjacencyFromLinks()
{
  __int16 *v0; // esi
  int i_1; // eax
  int v2; // ebx
  int n5; // edx
  _WORD *v4; // edi
  _DWORD *j; // eax
  unsigned int v6; // ecx
  _WORD *v7; // esi
  _DWORD *j_1; // [esp+8h] [ebp-Ch]
  int n5_1; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v0 = (__int16 *)dword_2305834[0];
  i_1 = dword_2305834[0] + 2056;
  v2 = 0;
  for ( i = dword_2305834[0] + 2056; v2 < v0[1]; i_1 += 40 )
  {
    if ( *(_WORD *)(i_1 + 6) != 0xFFFF )
    {
      n5 = 0;
      v4 = 0;
      for ( j = (_DWORD *)(i_1 + 12); ; j = j_1 + 1 )
      {
        j_1 = j;
        n5_1 = n5;
        v6 = (unsigned int)&v0[8 * v0[2] + 21508 + 2 * v0[2]];
        v7 = v0 + 21508;
        if ( v4 )
          v7 = v4 + 10;
        if ( (unsigned int)v7 >= v6 )
          break;
        while ( *v7 != (_WORD)v2 && v7[1] != (_WORD)v2 )
        {
          v7 += 10;
          if ( (unsigned int)v7 >= v6 )
            goto LABEL_10;
        }
        v4 = v7;
        if ( n5 >= 5 )
        {
          nullsub_34();
          n5 = n5_1;
        }
        ++n5;
        *j_1 = v7;
        v0 = (__int16 *)dword_2305834[0];
      }
LABEL_10:
      if ( n5 < 5 )
        memset((void *)(i + 12 + 4 * n5), 0, 4 * (5 - n5));
      i_1 = i;
      v0 = (__int16 *)dword_2305834[0];
    }
    i = i_1 + 40;
    ++v2;
  }
  return i_1;
}

