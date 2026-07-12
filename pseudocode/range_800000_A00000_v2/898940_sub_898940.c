// Function: sub_898940
// Address: 0x898940
__int16 sub_898940()
{
  __int16 n12290; // ax
  int v1; // edx
  char *v2; // ebx
  char *v3; // esi
  char v4; // cl
  int v5; // edi
  _WORD *v6; // edx
  _WORD *v7; // eax
  int v8; // [esp+0h] [ebp-4h]

  n12290 = n12290;
  if ( n12290 != 0xFFFF && n12290 != 0xFFFE && n12290 != 12290 )
  {
    if ( unk_23CC092[0] >= 0 )
    {
      v1 = unk_23CC092[0] + 1;
      v2 = (char *)&unk_133C91A;
      v3 = (char *)&unk_133D74A + 360 * unk_23CC088[0];
      v8 = v1;
      do
      {
        v4 = *v2;
        *((_WORD *)v3 - 1) = *(v2 - 8);
        *(_WORD *)v3 = v4;
        v5 = v4;
        if ( v4 > 0 )
        {
          v6 = v3 + 10;
          v7 = v2 + 12;
          do
          {
            *(v6 - 4) = *(v7 - 4);
            *v6++ = *v7++;
            --v5;
          }
          while ( v5 );
          v1 = v8;
        }
        *((_WORD *)v3 + 9) = *((_WORD *)v2 + 1);
        *(_DWORD *)(v3 + 26) = *(_DWORD *)(v2 + 206);
        *((_WORD *)v3 + 11) = *((_WORD *)v2 + 101);
        *((_WORD *)v3 + 12) = *((_WORD *)v2 + 102);
        *((_WORD *)v3 + 15) = *((_WORD *)v2 + 28);
        *((_WORD *)v3 + 10) = *((_WORD *)v2 + 27);
        v3 += 36;
        v2 += 240;
        v8 = --v1;
      }
      while ( v1 );
    }
    n12290 = unk_23CC088[0];
    unk_133D730[unk_23CC088[0]] = 1;
  }
  return n12290;
}
