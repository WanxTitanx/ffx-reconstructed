// Function: sub_9325C0
// Address: 0x9325c0
void __cdecl sub_9325C0(int a1, int a2, int a3)
{
  int v3; // ecx
  _DWORD *v4; // eax
  int v5; // edx
  int v6; // ecx
  double v7; // st7
  int v8; // esi
  int v9; // ecx
  _DWORD *v10; // eax
  _DWORD *v11; // ecx
  float v12; // [esp+0h] [ebp-18h]
  float v13; // [esp+0h] [ebp-18h]
  char Buffer[16]; // [esp+4h] [ebp-14h] BYREF

  if ( unk_193C0F0 && unk_193BF80 )
  {
    switch ( a2 )
    {
      case 32769:
        sub_937780(a1, &unk_C608F0);
        sub_93C110();
        break;
      case 32771:
        *(_DWORD *)(unk_193C0F0 + 84) = 0;
        break;
      case 32774:
        switch ( a3 )
        {
          case 200:
            *(_DWORD *)(unk_193C0F0 + 96) = 1;
            sub_937EF0(unk_193C0F0 + 4, 8, 8, 340, 190, 14, &sub_934BC0, "Load", a1);
            sub_934FB0();
            break;
          case 201:
            if ( *(_DWORD *)unk_193BF80 )
            {
              v3 = *(_DWORD *)(*(_DWORD *)unk_193BF80 + 8);
              if ( v3 )
              {
                v4 = *(_DWORD **)(v3 + 8);
                if ( v4 )
                {
                  v5 = 0;
                  if ( (*(_BYTE *)v4 & 2) != 0 )
                  {
                    if ( *(int *)(v3 + 4) > 0 )
                    {
                      do
                      {
                        *v4 &= ~2u;
                        ++v5;
                        v4 += 48;
                      }
                      while ( v5 < *(_DWORD *)(v3 + 4) );
                    }
                  }
                  else if ( *(int *)(v3 + 4) > 0 )
                  {
                    do
                    {
                      *v4 |= 2u;
                      ++v5;
                      v4 += 48;
                    }
                    while ( v5 < *(_DWORD *)(v3 + 4) );
                  }
                }
              }
            }
            break;
          case 202:
            if ( *(_DWORD *)unk_193BF80 )
            {
              v6 = *(_DWORD *)(*(_DWORD *)unk_193BF80 + 8);
              v12 = (float)(int)++*(_DWORD *)(unk_193C0F0 + 3076);
              v7 = v12;
              goto LABEL_35;
            }
            break;
          case 203:
            if ( *(_DWORD *)unk_193BF80 )
            {
              ++*(_DWORD *)(unk_193C0F0 + 3080);
              v8 = unk_193C0F0;
              v9 = *(_DWORD *)(unk_193C0F0 + 3080);
              if ( v9 < 0 )
                goto LABEL_38;
              goto LABEL_22;
            }
            break;
          case 205:
            ++*(_DWORD *)(unk_193C0F0 + 3068);
            break;
          case 206:
            sub_934250();
            break;
          case 207:
            sub_937EF0(unk_193C0F0 + 76, 8, 8, 120, 171, 6, sub_936A00, "VRAM", a1);
            break;
          case 208:
            sub_9364A0();
            break;
          case 209:
            sub_72A840(1);
            nullsub_176();
            break;
          case 210:
            nullsub_177();
            break;
          case 211:
            nullsub_178();
            break;
          case 212:
            nullsub_179();
            break;
          default:
            return;
        }
        break;
      case 32778:
        switch ( a3 )
        {
          case 202:
            if ( *(_DWORD *)unk_193BF80 )
            {
              v6 = *(_DWORD *)(*(_DWORD *)unk_193BF80 + 8);
              v13 = (float)(int)--*(_DWORD *)(unk_193C0F0 + 3076);
              v7 = v13;
LABEL_35:
              *(float *)(v6 + 172) = v7 * 0.01745329238474369;
              sub_920C00(v6);
            }
            break;
          case 203:
            if ( *(_DWORD *)unk_193BF80 )
            {
              --*(_DWORD *)(unk_193C0F0 + 3080);
              v8 = unk_193C0F0;
              v9 = *(_DWORD *)(unk_193C0F0 + 3080);
              if ( v9 >= 0 )
              {
LABEL_22:
                if ( unk_193BF80 )
                  v10 = *(_DWORD **)unk_193BF80;
                else
                  v10 = 0;
                if ( v9 > *v10 - 1 )
                {
                  if ( unk_193BF80 )
                    v11 = *(_DWORD **)unk_193BF80;
                  else
                    v11 = 0;
                  v9 = *v11 - 1;
                }
              }
              else
              {
LABEL_38:
                v9 = 0;
              }
              *(_DWORD *)(v8 + 3080) = v9;
              sub_9217E0(*(_DWORD *)(unk_193C0F0 + 3080));
            }
            break;
          case 205:
            --*(_DWORD *)(unk_193C0F0 + 3068);
            break;
          case 209:
            sub_72A840(0);
            break;
          default:
            return;
        }
        break;
      case 32785:
        sprintf(Buffer, "Bank:%d", *(_DWORD *)(unk_193C0F0 + 3076));
        sub_84A710(a1, 202, Buffer);
        sprintf(Buffer, "Stg:%d", *(_DWORD *)(unk_193C0F0 + 3080));
        sub_84A710(a1, 203, Buffer);
        sprintf(Buffer, "No.%d", *(_DWORD *)(unk_193C0F0 + 3068));
        sub_84A710(a1, 205, Buffer);
        break;
      default:
        return;
    }
  }
}
