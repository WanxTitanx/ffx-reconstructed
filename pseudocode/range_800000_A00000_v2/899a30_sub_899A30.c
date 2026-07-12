// Function: sub_899A30
// Address: 0x899a30
__int16 sub_899A30()
{
  int v0; // eax
  unsigned int v1; // edi
  int v2; // edx
  int v3; // esi
  int v4; // ebx
  __int16 *v5; // ecx
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  __int16 v9; // ax
  int v10; // eax
  int i_1; // ecx
  int v12; // esi
  int v13; // esi
  int i; // ecx
  int v16; // [esp+4h] [ebp-14h]
  unsigned __int16 v17; // [esp+8h] [ebp-10h]
  int v18; // [esp+10h] [ebp-8h]

  v0 = unk_23CC092[0] + 10 * unk_23CC088[0];
  v1 = 240 * unk_23CC092[0];
  v2 = 36 * v0;
  v18 = unk_23CC092[0];
  v16 = 36 * v0;
  v17 = *((_WORD *)&unk_133D75C + 18 * v0);
  if ( unk_133C91C[v1 / 2] != v17 )
    return v0;
  if ( !unk_133C912[240 * unk_23CC092[0]] )
  {
    v3 = *((_DWORD *)&unk_133C934 + 60 * unk_23CC092[0]);
    v4 = 0;
    if ( v3 > 0 )
    {
      v5 = (__int16 *)*((_DWORD *)&unk_133C930 + 60 * unk_23CC092[0]);
      while ( *((unsigned __int16 *)&unk_133D754 + 18 * v0 + *((char *)&unk_133C91B + 240 * unk_23CC092[0])) != *v5 )
      {
        ++v4;
        ++v5;
        if ( v4 >= v3 )
          goto LABEL_7;
      }
      unk_133C912[240 * unk_23CC092[0]] = *((_BYTE *)&unk_133D748 + 36 * v0);
      v7 = 120 * v18;
      word_133C91E[v7 + *((char *)&unk_133C91B + v1)] = v4;
      word_133C926[v7 + *((char *)&unk_133C91B + v1)] = *((_WORD *)&unk_133D754
                                                        + 18 * v0
                                                        + *((char *)&unk_133C91B + 240 * v4));
      unk_133C91C[v1 / 2] = v17;
      *(_WORD *)((char *)&unk_133C950 + v1) = *(_WORD *)((char *)&unk_133C948 + v1)
                                            * (v4 / *(__int16 *)((char *)&unk_133C948 + v1) - 1);
      v8 = *(__int16 *)((char *)&unk_133C948 + v1);
      if ( *(_DWORD *)((char *)&unk_133C934 + v1) >= v8 * *(__int16 *)((char *)&unk_133C94A + v1) )
      {
        if ( v4 < v8 )
          *(_WORD *)((char *)&unk_133C950 + v1) = 0;
        v10 = (*(__int16 *)((char *)&unk_133C948 + v1) + *(_DWORD *)((char *)&unk_133C934 + v1) - 1)
            / *(__int16 *)((char *)&unk_133C948 + v1);
        if ( v4 <= *(__int16 *)((char *)&unk_133C948 + v1) * (v10 - 1) - 1 )
          goto LABEL_23;
        v9 = *(_WORD *)((char *)&unk_133C948 + v1) * (v10 - *(_WORD *)((char *)&unk_133C94A + v1));
      }
      else
      {
        v9 = 0;
      }
      *(_WORD *)((char *)&unk_133C950 + v1) = v9;
LABEL_23:
      v2 = v16;
      *(_WORD *)((char *)&unk_133C952 + v1) = v4;
      v0 = *(_DWORD *)((char *)&unk_133D764 + v16);
      *(_DWORD *)((char *)&unk_133C9E8 + v1) = v0;
      goto LABEL_8;
    }
LABEL_7:
    LOWORD(v0) = 0;
    *((_DWORD *)&unk_133C950 + 60 * unk_23CC092[0]) = 0;
  }
LABEL_8:
  if ( unk_133C912[v1] == 1 )
  {
    v6 = *(_DWORD *)((char *)&unk_133D764 + v2);
    if ( v6 )
    {
      if ( !*(_WORD *)((char *)&unk_133D762 + v2) )
      {
        v0 = 0;
        if ( !*(_WORD *)((char *)&unk_133D760 + v2) )
        {
          while ( dst_1[v0] != v6 )
          {
            if ( ++v0 >= 20 )
              return v0;
          }
          i_1 = 0;
          unk_133D1C0 = 0;
          unk_133D1BC = v0;
          v12 = dst_1[v0];
          unk_133D138 = v12;
          do
          {
            if ( ((1 << i_1) & v12) != 0 )
              i_5 = i_1;
            ++i_1;
          }
          while ( i_1 < 20 );
          goto LABEL_15;
        }
        while ( src[v0] != v6 )
        {
          if ( ++v0 >= 8 )
            return v0;
        }
        unk_133D1C0 = 1;
        unk_133D1BC = v0;
        v13 = src[v0];
        unk_133D138 = v13;
        for ( i = 20; i < 28; ++i )
        {
          if ( ((1 << i) & v13) != 0 )
            i_5 = i;
        }
LABEL_52:
        src_0 = src;
        unk_133D1B6 = word_133D190[0];
        LOWORD(v0) = word_133D190[0];
        return v0;
      }
      if ( *(_WORD *)((char *)&unk_133D762 + v2) == 1 )
      {
        v0 = 0;
        if ( *(_WORD *)((char *)&unk_133D760 + v2) )
        {
          if ( word_133D190[0] > 0 )
          {
            while ( (v6 & src[v0]) == 0 )
            {
              if ( ++v0 >= word_133D190[0] )
                return v0;
            }
            unk_133D1BC = v0;
            unk_133D1C0 = 1;
            unk_133D138 = src[v0];
            unk_133D1B6 = word_133D190[0];
            i_5 = 255;
            src_0 = src;
            LOWORD(v0) = 255;
          }
        }
        else if ( word_133D13C[0] > 0 )
        {
          while ( (v6 & dst_1[v0]) == 0 )
          {
            if ( ++v0 >= word_133D13C[0] )
              return v0;
          }
          unk_133D1BC = v0;
          unk_133D1C0 = 0;
          unk_133D138 = dst_1[v0];
          unk_133D1B6 = word_133D13C[0];
          i_5 = 255;
          src_0 = dst_1;
          LOWORD(v0) = 255;
        }
      }
      else
      {
        LOWORD(v0) = *(_WORD *)((char *)&unk_133D762 + v2) - 2;
        if ( *(_WORD *)((char *)&unk_133D762 + v2) == 2 )
        {
          if ( !*(_WORD *)((char *)&unk_133D760 + v2) )
          {
            unk_133D1C0 = 0;
            unk_133D1BC = 0;
            unk_133D138 = dst_1[0];
            i_5 = 255;
LABEL_15:
            src_0 = dst_1;
            unk_133D1B6 = word_133D13C[0];
            LOWORD(v0) = word_133D13C[0];
            return v0;
          }
          unk_133D1C0 = 1;
          unk_133D1BC = 0;
          unk_133D138 = src[0];
          i_5 = 255;
          goto LABEL_52;
        }
      }
    }
  }
  return v0;
}
