// Function: sub_9313F0
// Address: 0x9313f0
void __cdecl sub_9313F0(int a1, int a2, int n50)
{
  int v3; // ebx
  int v4; // edi
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  unsigned __int8 *v8; // esi
  int v10; // eax
  unsigned __int8 v11; // al
  unsigned __int8 n0x63; // al
  int v13; // edx
  _BYTE v14[4]; // [esp+4h] [ebp-20h] BYREF
  _BYTE v15[4]; // [esp+8h] [ebp-1Ch] BYREF
  int v16; // [esp+Ch] [ebp-18h]
  char Buffer[16]; // [esp+10h] [ebp-14h] BYREF

  v3 = unk_193C0F0;
  if ( unk_193C0F0 && unk_193BF80 && *(_DWORD *)unk_193BF80 )
  {
    v4 = 192 * *(_DWORD *)(unk_193C0F0 + 648) + *(_DWORD *)(*(_DWORD *)(*(_DWORD *)unk_193BF80 + 8) + 8) + 144;
    v5 = *(_DWORD *)(v4 + 8);
    if ( v5 <= 0 )
    {
      v8 = 0;
    }
    else
    {
      v6 = *(_DWORD *)(unk_193C0F0 + 776);
      if ( v6 >= 0 )
      {
        v7 = v5 - 1;
        if ( v6 <= v7 )
          v7 = *(_DWORD *)(unk_193C0F0 + 776);
      }
      else
      {
        v7 = 0;
      }
      *(_DWORD *)(unk_193C0F0 + 776) = v7;
      v3 = unk_193C0F0;
      v8 = (unsigned __int8 *)(*(_DWORD *)(v4 + 12) + 4 * *(_DWORD *)(unk_193C0F0 + 776));
    }
    v16 = *(_DWORD *)(v4 + 16);
    switch ( a2 )
    {
      case 32769:
        sub_937780(a1, &unk_C5EDD0);
        sub_93C110();
        break;
      case 32771:
        *(_DWORD *)(v3 + 16) = 0;
        break;
      case 32774:
        sub_93C050();
        switch ( n50 )
        {
          case '%':
            *(_DWORD *)v4 ^= 1u;
            if ( (*(_BYTE *)v4 & 1) != 0 )
              *(_DWORD *)(unk_193C0F0 + 776) = *(__int16 *)(v4 + 6);
            break;
          case '&':
            *(_DWORD *)(unk_193C0F0 + 916) = *(_DWORD *)(v4 + 8);
            sub_93C2E0(unk_193C0F0 + 872, unk_193C0F0 + 916, 5, "Anime Data", a1);
            break;
          case '\'':
            if ( --*(_DWORD *)(unk_193C0F0 + 776) < 0 )
              *(_DWORD *)(unk_193C0F0 + 776) = *(_DWORD *)(v4 + 8) - 1;
            break;
          case '(':
            v10 = unk_193C0F0;
            ++*(_DWORD *)(unk_193C0F0 + 776);
            if ( *(_DWORD *)(v10 + 776) >= *(_DWORD *)(v4 + 8) )
              *(_DWORD *)(unk_193C0F0 + 776) = 0;
            break;
          case ')':
            if ( v8 )
            {
              if ( --*v8 >= *(int *)(v16 + 48) )
                *v8 = *(_BYTE *)(v16 + 48) - 1;
            }
            break;
          case '*':
            if ( v8 )
            {
              if ( ++*v8 >= *(int *)(v16 + 48) )
                *v8 = 0;
            }
            break;
          case '+':
            if ( v8 )
            {
              v11 = v8[1];
              if ( v11 )
                v8[1] = v11 - 1;
            }
            break;
          case ',':
            if ( v8 )
            {
              n0x63 = v8[1];
              if ( n0x63 < 0x63u )
                v8[1] = n0x63 + 1;
            }
            break;
          case '-':
            if ( *(int *)(v4 + 8) > 0 )
            {
              v13 = 0;
              do
                *(_BYTE *)(*(_DWORD *)(v4 + 12) + 4 * v13++ + 1) = v8[1];
              while ( v13 < *(_DWORD *)(v4 + 8) );
            }
            break;
          case '.':
            if ( v8 )
              --v8[3];
            break;
          case '/':
            if ( v8 )
              ++v8[3];
            break;
          case '0':
            if ( v8 )
              --v8[2];
            break;
          case '1':
            if ( v8 )
              ++v8[2];
            break;
          default:
            return;
        }
        break;
      case 32775:
        if ( n50 == 50 )
          sub_93C150(a1, 50);
        break;
      case 32785:
        if ( sub_93C3D0(v3 + 872) )
          sub_9308D0(v4, *(_DWORD *)(unk_193C0F0 + 916));
        if ( v8 )
        {
          if ( sub_93C120(a1) )
          {
            sub_93C060(v15, v14);
            if ( sub_93C100() == 50 )
            {
              v8[2] += v15[0];
              v8[3] += v14[0];
            }
          }
        }
        if ( (*(_BYTE *)v4 & 1) != 0 )
        {
          *(_WORD *)(v4 + 6) = *(_WORD *)(unk_193C0F0 + 776);
          sub_84A710(a1, 37, "Stop");
        }
        else
        {
          sub_84A710(a1, 37, "Play");
        }
        sprintf(Buffer, "%d", *(_DWORD *)(v4 + 8));
        sub_84A710(a1, 38, Buffer);
        sub_848820(71);
        sub_848860(27);
        sub_848880("%02d", *(_DWORD *)(unk_193C0F0 + 776));
        if ( v8 )
        {
          sub_848820(71);
          sub_848860(40);
          sub_848880("%02d", *v8);
          sub_848820(71);
          sub_848860(53);
          sub_848880("%02d", v8[1]);
          sub_848820(2);
          sub_848860(90);
          sub_848880("X:%d", (char)v8[2]);
          sub_848820(2);
          sub_848860(100);
          sub_848880("Y:%d", (char)v8[3]);
        }
        break;
      default:
        return;
    }
  }
}
