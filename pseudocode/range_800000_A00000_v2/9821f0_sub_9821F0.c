// Function: sub_9821F0
// Address: 0x9821f0
void __thiscall sub_9821F0(int this, int a2)
{
  int i_1; // edx
  int i_2; // edi
  int v5; // eax
  int v6; // ebx
  int v7; // edx
  _DWORD *v8; // ecx
  int i; // ecx
  _DWORD *v10; // eax
  int i_4; // ebx
  _DWORD *v12; // ecx
  int j_1; // eax
  int j_2; // edx
  _DWORD *v15; // eax
  int i_5; // ecx
  int k; // ecx
  int i_6; // edi
  int v19; // edx
  int v20; // edx
  int j; // [esp+8h] [ebp-Ch]
  int v22; // [esp+Ch] [ebp-8h]
  _DWORD *v23; // [esp+Ch] [ebp-8h]
  int i_3; // [esp+10h] [ebp-4h]

  i_1 = *(_DWORD *)(this + 4);
  i_2 = *(_DWORD *)(this + 48);
  i_3 = i_1;
  if ( i_1 < i_2 )
  {
    if ( i_2 >= i_1 )
    {
      if ( i_2 > i_1 && *(_DWORD *)(this + 8) < i_2 )
      {
        if ( i_2 )
          v5 = sub_9D4CE0(4 * i_2, 16);
        else
          v5 = 0;
        v6 = *(_DWORD *)(this + 4);
        v7 = 0;
        v22 = v5;
        if ( v6 > 0 )
        {
          v8 = (_DWORD *)v5;
          do
          {
            if ( v8 )
              *v8 = *(_DWORD *)(*(_DWORD *)(this + 12) + 4 * v7);
            ++v7;
            ++v8;
          }
          while ( v7 < v6 );
        }
        if ( *(_DWORD *)(this + 12) )
        {
          if ( *(_BYTE *)(this + 16) )
            sub_9D4D50(*(_DWORD *)(this + 12));
          *(_DWORD *)(this + 12) = 0;
        }
        i_1 = i_3;
        *(_BYTE *)(this + 16) = 1;
        *(_DWORD *)(this + 12) = v22;
        *(_DWORD *)(this + 8) = i_2;
      }
      for ( i = i_1; i < i_2; ++i )
      {
        v10 = (_DWORD *)(*(_DWORD *)(this + 12) + 4 * i);
        if ( v10 )
          *v10 = 0;
      }
    }
    *(_DWORD *)(this + 4) = i_2;
    i_4 = *(_DWORD *)(this + 24);
    if ( i_2 >= i_4 )
    {
      if ( i_2 > i_4 && *(_DWORD *)(this + 28) < i_2 )
      {
        if ( i_2 )
        {
          v12 = (_DWORD *)sub_9D4CE0(4 * i_2, 16);
          v23 = v12;
        }
        else
        {
          v12 = 0;
          v23 = 0;
        }
        j_1 = *(_DWORD *)(this + 24);
        j_2 = 0;
        for ( j = j_1; j_2 < j_1; ++v12 )
        {
          if ( v12 )
          {
            *v12 = *(_DWORD *)(*(_DWORD *)(this + 32) + 4 * j_2);
            j_1 = j;
          }
          ++j_2;
        }
        if ( *(_DWORD *)(this + 32) )
        {
          if ( *(_BYTE *)(this + 36) )
            sub_9D4D50(*(_DWORD *)(this + 32));
          *(_DWORD *)(this + 32) = 0;
        }
        i_1 = i_3;
        *(_BYTE *)(this + 36) = 1;
        *(_DWORD *)(this + 32) = v23;
        *(_DWORD *)(this + 28) = i_2;
      }
      for ( ; i_4 < i_2; ++i_4 )
      {
        v15 = (_DWORD *)(*(_DWORD *)(this + 32) + 4 * i_4);
        if ( v15 )
          *v15 = 0;
      }
    }
    i_5 = 0;
    for ( *(_DWORD *)(this + 24) = i_2; i_5 < i_2; *(_DWORD *)(*(_DWORD *)(this + 12) + 4 * i_5 - 4) = -1 )
      ++i_5;
    for ( k = 0; k < i_2; *(_DWORD *)(*(_DWORD *)(this + 32) + 4 * k - 4) = -1 )
      ++k;
    i_6 = 0;
    if ( i_1 > 0 )
    {
      do
      {
        v19 = ~((((9
                 * ((~(*(_DWORD *)(*(_DWORD *)(this + 72) + 8 * i_6) << 15)
                   + *(_DWORD *)(*(_DWORD *)(this + 72) + 8 * i_6))
                  ^ ((~(*(_DWORD *)(*(_DWORD *)(this + 72) + 8 * i_6) << 15)
                    + *(_DWORD *)(*(_DWORD *)(this + 72) + 8 * i_6)) >> 10))) >> 6)
               ^ (9
                * ((~(*(_DWORD *)(*(_DWORD *)(this + 72) + 8 * i_6) << 15)
                  + *(_DWORD *)(*(_DWORD *)(this + 72) + 8 * i_6))
                 ^ ((~(*(_DWORD *)(*(_DWORD *)(this + 72) + 8 * i_6) << 15)
                   + *(_DWORD *)(*(_DWORD *)(this + 72) + 8 * i_6)) >> 10)))) << 11)
            + (((9
               * ((~(*(_DWORD *)(*(_DWORD *)(this + 72) + 8 * i_6) << 15) + *(_DWORD *)(*(_DWORD *)(this + 72) + 8 * i_6))
                ^ ((~(*(_DWORD *)(*(_DWORD *)(this + 72) + 8 * i_6) << 15)
                  + *(_DWORD *)(*(_DWORD *)(this + 72) + 8 * i_6)) >> 10))) >> 6)
             ^ (9
              * ((~(*(_DWORD *)(*(_DWORD *)(this + 72) + 8 * i_6) << 15) + *(_DWORD *)(*(_DWORD *)(this + 72) + 8 * i_6))
               ^ ((~(*(_DWORD *)(*(_DWORD *)(this + 72) + 8 * i_6) << 15) + *(_DWORD *)(*(_DWORD *)(this + 72) + 8 * i_6)) >> 10))));
        v20 = 4 * ((*(_DWORD *)(this + 48) - 1) & (v19 ^ (v19 >> 16)));
        *(_DWORD *)(*(_DWORD *)(this + 32) + 4 * i_6) = *(_DWORD *)(v20 + *(_DWORD *)(this + 12));
        *(_DWORD *)(v20 + *(_DWORD *)(this + 12)) = i_6++;
      }
      while ( i_6 < i_3 );
    }
  }
}
