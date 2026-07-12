// Function: sub_A5D3C0
// Address: 0xa5d3c0
// Size: 0x225
// Prototype: 

int __cdecl sub_A5D3C0(_BYTE *a1)
{
  int result; // eax
  _BYTE *v2; // edx
  int v3; // ecx
  int v4; // ebx
  char n37; // al
  _BYTE *v6; // esi
  _DWORD *v7; // edi
  unsigned __int8 n102; // dl
  _BYTE *v9; // esi
  int n4; // ecx
  int n4_1; // ebx
  double v12; // st7
  double *v13; // [esp+24h] [ebp-4h]
  _UNKNOWN *retaddr; // [esp+2Ch] [ebp+4h] BYREF

  result = sub_62FA30(0, 0);
  if ( unk_2286154 )
  {
    v2 = a1;
    v3 = dword_2286140;
    unk_2322776 = 0;
    unk_2322770 = unk_228614C;
    v4 = dword_2286140 + 80;
    dword_2322764 = a1;
    dword_2322760 = a1;
    unk_232276C = dword_2286140 + 80;
    unk_2322768 = dword_2286140 + 80;
    unk_2322772 = unk_2286150 + unk_228614E;
    n37 = *a1;
    v6 = a1;
    if ( *a1 )
    {
      v13 = (double *)&retaddr;
      v7 = &a1;
      do
      {
        if ( n37 == 37 || n37 == 36 )
        {
          n102 = v6[1];
          v9 = v6 + 1;
          n4 = 0;
          n4_1 = 0;
          if ( n102 == 120 )
          {
LABEL_15:
            dword_2322764 = v9 + 1;
            dword_2322760 = v9 + 1;
            unk_2322768 = unk_232276C;
            if ( !n4 )
              n4 = 4;
            v13 = (double *)((char *)v13 + 4);
            sub_A5EEA0(*++v7, n4, &dword_2322760, &dword_2286140);
          }
          else
          {
            while ( n102 != 100 )
            {
              if ( n102 == 102 )
              {
                dword_2322764 = v9 + 1;
                dword_2322760 = v9 + 1;
                unk_2322768 = unk_232276C;
                if ( !n4 )
                  n4 = 4;
                if ( !n4_1 )
                  n4_1 = 4;
                v12 = v13[1];
                v7 += 2;
                ++v13;
                sub_A5EA30(v12, n4_1, n4, (int)&dword_2322760, (int)&dword_2286140);
                goto LABEL_18;
              }
              if ( n102 == 46 )
              {
                n4_1 = n4;
                n4 = 0;
              }
              else if ( (unsigned __int8)(n102 - 48) <= 9u )
              {
                n4 = n102 + 16 * (n4 - 3);
              }
              n102 = *++v9;
              if ( n102 == 120 )
                goto LABEL_15;
            }
            dword_2322764 = v9 + 1;
            dword_2322760 = v9 + 1;
            unk_2322768 = unk_232276C;
            if ( !n4 )
              n4 = 4;
            v13 = (double *)((char *)v13 + 4);
            sub_A5E880(*++v7, n4, &dword_2322760, &dword_2286140);
          }
        }
        else
        {
          dword_2322760 = v2;
          unk_2322768 = v4;
          sub_A5F040(&dword_2322760);
        }
LABEL_18:
        v2 = dword_2322764;
        v4 = unk_232276C;
        v6 = dword_2322764;
        n37 = *dword_2322764;
      }
      while ( *dword_2322764 );
      v3 = dword_2286140;
    }
    sub_A5F2D0(v3, v4);
    sub_62FA30(0, 0);
    nullsub_33(0);
    nullsub_39(unk_22881D0, dword_2286140);
    result = sub_7EB490();
    ++unk_2286150;
  }
  return result;
}

