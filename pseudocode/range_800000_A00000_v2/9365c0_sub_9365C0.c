// Function: sub_9365C0
// Address: 0x9365c0
int __cdecl sub_9365C0(int a1, int a2, int n89)
{
  int result; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int v6; // ecx
  int v7; // edi
  int *v8; // eax
  int v9; // edi
  int v10; // ecx
  int v11; // edx
  int v12; // ebx
  int v13; // ecx
  int n16; // edi
  int v15; // ecx
  int v16; // edx
  int v17; // eax
  int v18; // [esp+0h] [ebp-14h] BYREF
  int v19; // [esp+4h] [ebp-10h] BYREF
  int v20; // [esp+8h] [ebp-Ch]
  int v21; // [esp+Ch] [ebp-8h]
  int v22; // [esp+10h] [ebp-4h]

  result = unk_193C0F0;
  v22 = unk_193C0F0;
  if ( unk_193C0F0 )
  {
    result = unk_193BF80;
    if ( unk_193BF80 )
    {
      if ( *(_DWORD *)unk_193BF80 )
      {
        v4 = *(_DWORD **)(*(_DWORD *)unk_193BF80 + 8);
        v5 = v4[1];
        v6 = 0;
        v7 = 0;
        if ( v5 > 0 )
        {
          v8 = (int *)(v4[2] + 8);
          do
          {
            if ( v7 < *(v8 - 1) )
              v7 = *(v8 - 1);
            if ( v6 < *v8 )
              v6 = *v8;
            v8 += 48;
            --v5;
          }
          while ( v5 );
        }
        v9 = v7 - 512;
        if ( v4[62] )
          v10 = v6 - 448;
        else
          v10 = v6 - 224;
        v11 = v9 < 0 ? 0 : v9;
        result = a2 - 32769;
        v21 = v11;
        v12 = v10 < 0 ? 0 : v10;
        switch ( a2 )
        {
          case 32769:
            sub_937780(a1, dword_C5F5D8);
            result = sub_93C110();
            break;
          case 32771:
            result = v22;
            *(_DWORD *)(v22 + 36) = 0;
            break;
          case 32774:
            v13 = v4[24];
            n16 = v4[25];
            v22 = v4[23];
            v20 = v13;
            switch ( n89 )
            {
              case 'S':
                --n16;
                goto LABEL_21;
              case 'T':
                ++n16;
                goto LABEL_21;
              case 'U':
                --v13;
                goto LABEL_21;
              case 'V':
                ++v13;
                goto LABEL_21;
              case 'W':
                result = v22 - 1;
                goto LABEL_22;
              case 'X':
                result = v22 + 1;
                goto LABEL_22;
              case 'Y':
                sub_93C050();
                v11 = v21;
                v13 = v20;
                goto LABEL_21;
              default:
LABEL_21:
                result = v22;
LABEL_22:
                if ( result >= 0 )
                {
                  if ( result <= v11 )
                    v11 = result;
                }
                else
                {
                  v11 = 0;
                }
                v4[23] = v11;
                if ( v13 >= 0 )
                {
                  if ( v13 <= v12 )
                    v12 = v13;
                }
                else
                {
                  v12 = 0;
                }
                v4[24] = v12;
                if ( n16 >= -16 )
                {
                  if ( n16 > 16 )
                    n16 = 16;
                  v4[25] = n16;
                }
                else
                {
                  v4[25] = -16;
                }
                break;
            }
            break;
          case 32775:
            if ( n89 == 89 )
              result = sub_93C150(a1, 89);
            break;
          case 32785:
            if ( sub_93C120(a1) )
            {
              sub_93C060(&v19, &v18);
              v15 = v4[24] - v18;
              v16 = v4[23] - v19;
              if ( v16 >= 0 )
              {
                v17 = v21;
                if ( v16 <= v21 )
                  v17 = v4[23] - v19;
              }
              else
              {
                v17 = 0;
              }
              v4[23] = v17;
              if ( v15 >= 0 )
              {
                if ( v15 <= v12 )
                  v12 = v15;
              }
              else
              {
                v12 = 0;
              }
              v4[24] = v12;
            }
            sub_848820(2);
            sub_848860(12);
            sub_848880("Y:%d", v4[25]);
            sub_848820(2);
            sub_848860(38);
            sub_848880("X:%d", v4[23]);
            sub_848820(2);
            sub_848860(48);
            result = sub_848880("Y:%d", v4[24]);
            break;
          default:
            return result;
        }
      }
    }
  }
  return result;
}
