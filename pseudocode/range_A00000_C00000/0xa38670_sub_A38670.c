// Function: sub_A38670
// Address: 0xa38670
// Size: 0x16b
// Prototype: 

int __cdecl sub_A38670(unsigned int *a1, unsigned __int8 *a2, _DWORD *a3, int n4_2, int n4)
{
  int n4_1; // eax
  _DWORD *v6; // ecx
  _DWORD *v7; // edx
  bool v8; // zf
  unsigned __int8 *v9; // esi
  unsigned __int8 *v10; // edi
  unsigned int *v11; // ebx
  int n4_3; // [esp+10h] [ebp-Ch]
  unsigned __int8 *v13; // [esp+14h] [ebp-8h]
  unsigned int *v14; // [esp+18h] [ebp-4h]
  _DWORD *v15; // [esp+34h] [ebp+18h]
  int n4_4; // [esp+34h] [ebp+18h]

  n4_1 = n4;
  if ( n4 == 4 )
  {
    v14 = a1;
    n4_1 = n4_2;
    n4_3 = n4_2;
    if ( n4_2 )
    {
      v6 = a3;
      v7 = a2 + 4;
      n4_1 = a2 - (unsigned __int8 *)a3;
      v13 = a2 + 4;
      v15 = a3;
      do
      {
        *v14 = (((*v6 >> 2) & 0x3FC03FC0)
              + ((*v7 >> 2) & 0x3FC03FC0)
              + ((*(_DWORD *)((char *)v6 + n4_1) >> 2) & 0x3FC03FC0)
              + ((v15[1] >> 2) & 0x3FC03FC0)
              + 8388736)
             ^ (unsigned int)&unk_FF00FF
             & (((((unsigned int)&unk_FF00FF & *v6)
                + ((unsigned int)&unk_FF00FF & *v7)
                + ((unsigned int)&unk_FF00FF & *(_DWORD *)((char *)v6 + n4_1))
                + ((unsigned int)&unk_FF00FF & v15[1])
                + 131074) >> 2)
              ^ (((*v6 >> 2) & 0xFFC03FC0)
               + ((*v7 >> 2) & 0xFFC03FC0)
               + ((*(_DWORD *)((char *)v6 + n4_1) >> 2) & 0xFFC03FC0)
               + ((v15[1] >> 2) & 0xFFC03FC0)
               - 8388480));
        v6 = v15 + 2;
        v7 = v13 + 8;
        v8 = n4_3-- == 1;
        ++v14;
        n4_1 = a2 - (unsigned __int8 *)a3;
        v15 += 2;
        v13 += 8;
      }
      while ( !v8 );
    }
  }
  else if ( n4 == 1 )
  {
    n4_1 = n4_2;
    n4_4 = n4_2;
    if ( n4_2 )
    {
      v9 = (unsigned __int8 *)a3;
      v10 = a2;
      v11 = a1;
      do
      {
        n4_1 = (*v10 + v9[1] + v10[1] + *v9 + 2) / 4;
        v8 = n4_4-- == 1;
        *(_BYTE *)v11 = n4_1;
        v11 = (unsigned int *)((char *)v11 + 1);
        v10 += 2;
        v9 += 2;
      }
      while ( !v8 );
    }
  }
  return n4_1;
}

