// Function: sub_9A0E50
// Address: 0x9a0e50
_DWORD *__thiscall sub_9A0E50(_DWORD *this)
{
  _DWORD *k_2; // eax
  int k_1; // edi
  int k_5; // ebx
  _DWORD *k_10; // ecx
  int i_1; // eax
  int i_2; // edx
  int k_7; // ebx
  _DWORD *k_11; // ecx
  int j_1; // eax
  int j_2; // edx
  int k_8; // ecx
  int k; // ecx
  int k_9; // edi
  int v15; // ebx
  int v16; // edx
  int v17; // edx
  int i; // [esp+8h] [ebp-Ch]
  int j; // [esp+8h] [ebp-Ch]
  _DWORD *k_3; // [esp+Ch] [ebp-8h]
  _DWORD *k_4; // [esp+10h] [ebp-4h]
  _DWORD *k_6; // [esp+10h] [ebp-4h]

  k_2 = (_DWORD *)*(this + 9);
  k_1 = *(this + 3);
  k_3 = k_2;
  if ( (int)k_2 < k_1 )
  {
    k_5 = *(this + 9);
    if ( k_1 >= (int)k_2 )
    {
      if ( k_1 > (int)k_2 && *(this + 10) < k_1 )
      {
        if ( k_1 )
        {
          k_10 = (_DWORD *)sub_9D4CE0(4 * k_1, 16);
          k_4 = k_10;
        }
        else
        {
          k_10 = 0;
          k_4 = 0;
        }
        i_1 = *(this + 9);
        i_2 = 0;
        for ( i = i_1; i_2 < i_1; ++k_10 )
        {
          if ( k_10 )
          {
            *k_10 = *(_DWORD *)(*(this + 11) + 4 * i_2);
            i_1 = i;
          }
          ++i_2;
        }
        if ( *(this + 11) )
        {
          if ( *((_BYTE *)this + 48) )
            sub_9D4D50(*(this + 11));
          *(this + 11) = 0;
        }
        k_2 = k_4;
        *((_BYTE *)this + 48) = 1;
        *(this + 11) = k_4;
        *(this + 10) = k_1;
      }
      for ( ; k_5 < k_1; ++k_5 )
      {
        k_2 = (_DWORD *)(*(this + 11) + 4 * k_5);
        if ( k_2 )
          *k_2 = 0;
      }
    }
    *(this + 9) = k_1;
    k_7 = *(this + 14);
    if ( k_1 >= k_7 )
    {
      if ( k_1 > k_7 && *(this + 15) < k_1 )
      {
        if ( k_1 )
        {
          k_11 = (_DWORD *)sub_9D4CE0(4 * k_1, 16);
          k_6 = k_11;
        }
        else
        {
          k_11 = 0;
          k_6 = 0;
        }
        j_1 = *(this + 14);
        j_2 = 0;
        for ( j = j_1; j_2 < j_1; ++k_11 )
        {
          if ( k_11 )
          {
            *k_11 = *(_DWORD *)(*(this + 16) + 4 * j_2);
            j_1 = j;
          }
          ++j_2;
        }
        if ( *(this + 16) )
        {
          if ( *((_BYTE *)this + 68) )
            sub_9D4D50(*(this + 16));
          *(this + 16) = 0;
        }
        k_2 = k_6;
        *((_BYTE *)this + 68) = 1;
        *(this + 16) = k_6;
        *(this + 15) = k_1;
      }
      for ( ; k_7 < k_1; ++k_7 )
      {
        k_2 = (_DWORD *)(*(this + 16) + 4 * k_7);
        if ( k_2 )
          *k_2 = 0;
      }
    }
    k_8 = 0;
    for ( *(this + 14) = k_1; k_8 < k_1; k_2[k_8 - 1] = -1 )
    {
      k_2 = (_DWORD *)*(this + 11);
      ++k_8;
    }
    for ( k = 0; k < k_1; k_2[k - 1] = -1 )
    {
      k_2 = (_DWORD *)*(this + 16);
      ++k;
    }
    k_9 = 0;
    if ( (int)k_3 > 0 )
    {
      v15 = 0;
      do
      {
        v15 += 16;
        v16 = 9
            * ((~((*(_DWORD *)(*(_DWORD *)(*(this + 4) + v15 - 16) + 12)
                 | (*(_DWORD *)(*(_DWORD *)(*(this + 4) + v15 - 12) + 12) << 16)) << 15)
              + (*(_DWORD *)(*(_DWORD *)(*(this + 4) + v15 - 16) + 12)
               | (*(_DWORD *)(*(_DWORD *)(*(this + 4) + v15 - 12) + 12) << 16)))
             ^ ((~((*(_DWORD *)(*(_DWORD *)(*(this + 4) + v15 - 16) + 12)
                  | (*(_DWORD *)(*(_DWORD *)(*(this + 4) + v15 - 12) + 12) << 16)) << 15)
               + (*(_DWORD *)(*(_DWORD *)(*(this + 4) + v15 - 16) + 12)
                | (*(_DWORD *)(*(_DWORD *)(*(this + 4) + v15 - 12) + 12) << 16))) >> 10));
        v17 = (*(this + 3) - 1)
            & ((~(((v16 >> 6) ^ v16) << 11) + ((v16 >> 6) ^ v16))
             ^ ((~(((v16 >> 6) ^ v16) << 11) + ((v16 >> 6) ^ v16)) >> 16));
        *(_DWORD *)(*(this + 16) + 4 * k_9) = *(_DWORD *)(v17 * 4 + *(this + 11));
        k_2 = (_DWORD *)*(this + 11);
        k_2[v17] = k_9++;
      }
      while ( k_9 < (int)k_3 );
    }
  }
  return k_2;
}
