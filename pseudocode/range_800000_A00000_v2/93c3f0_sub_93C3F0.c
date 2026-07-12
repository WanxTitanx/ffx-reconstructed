// Function: sub_93C3F0
// Address: 0x93c3f0
void __cdecl sub_93C3F0(int a1, int a2, int n15)
{
  int v3; // eax
  int v4; // esi
  int n10; // eax
  int v6; // eax
  int v7; // ecx
  _BYTE *v8; // edx
  int v9; // eax
  const char *v10; // [esp-4h] [ebp-Ch]
  float v11; // [esp+14h] [ebp+Ch]

  v3 = sub_84AEC0(a1);
  v4 = v3;
  switch ( a2 )
  {
    case 32769:
      sub_937780(a1, dword_C60EB0);
      return;
    case 32771:
      *(_DWORD *)v3 = 0;
      return;
    case 32774:
      if ( n15 == 14 )
      {
        v10 = (const char *)(v3 + 12);
        if ( *(_DWORD *)(v3 + 8) == 11 )
        {
          v11 = atof(v10);
          **(float **)(v4 + 4) = v11;
        }
        else
        {
          v9 = atoi(v10);
          sub_93C270(*(_BYTE **)(v4 + 4), *(_DWORD *)(v4 + 8), v9);
        }
        *(_DWORD *)(v4 + 40) = 1;
      }
      else if ( n15 != 15 )
      {
        return;
      }
      sub_84AB80(a1);
      return;
    case 32775:
      switch ( n15 )
      {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
          if ( *(_DWORD *)(v3 + 32) )
          {
            *(_WORD *)(v3 + 12) = 48;
            *(_DWORD *)(v3 + 28) = 0;
            *(_DWORD *)(v3 + 36) = 0;
            *(_DWORD *)(v3 + 32) = 0;
          }
          n10 = *(_DWORD *)(v3 + 28);
          if ( n10 < 10 )
          {
            if ( *(_DWORD *)(v4 + 36) )
            {
              if ( !n10 )
                *(_DWORD *)(v4 + 28) = 1;
              *(_BYTE *)(v4 + (*(_DWORD *)(v4 + 28))++ + 12) = 46;
              *(_DWORD *)(v4 + 36) = 0;
            }
            *(_BYTE *)(v4 + *(_DWORD *)(v4 + 28) + 12) = n15 + 48;
            *(_BYTE *)(v4 + *(_DWORD *)(v4 + 28) + 13) = 0;
            v6 = *(_DWORD *)(v4 + 28);
            if ( v6 > 0 || n15 )
              *(_DWORD *)(v4 + 28) = v6 + 1;
          }
          break;
        case 10:
          if ( *(_DWORD *)(v3 + 8) == 11 )
            *(_DWORD *)(v3 + 36) = 1;
          break;
        case 11:
          v7 = *(_DWORD *)(v3 + 28);
          if ( v7 > 0 )
          {
            v8 = (_BYTE *)(v3 + 12);
            if ( *(_BYTE *)(v3 + 12) == 45 )
            {
              do
              {
                *v8 = v8[1];
                ++v8;
              }
              while ( (int)&v8[-12 - v3] < *(_DWORD *)(v3 + 28) );
              --*(_DWORD *)(v3 + 28);
            }
            else
            {
              do
              {
                --v7;
                *(_BYTE *)(v3 + v7 + 14) = *(_BYTE *)(v3 + v7 + 13);
              }
              while ( v7 >= 0 );
              ++*(_DWORD *)(v3 + 28);
              *v8 = 45;
            }
          }
          break;
        case 12:
          *(_WORD *)(v3 + 12) = 48;
          *(_DWORD *)(v3 + 28) = 0;
          *(_DWORD *)(v3 + 36) = 0;
          break;
        default:
          return;
      }
      return;
    case 32785:
      if ( v3 && *(_DWORD *)v3 )
      {
        sub_848530(a1);
        sub_848480(2);
        sub_8484C0(80, 80, 80, 0);
        sub_848680(2, 0);
        sub_848680(96, 0);
        sub_848680(96, 10);
        sub_848680(2, 10);
        sub_848680(2, 0);
        sub_848460();
        sub_848820(6);
        sub_848860(2);
        sub_848880("%10s", (const char *)(v4 + 12));
      }
      return;
    default:
      return;
  }
}
