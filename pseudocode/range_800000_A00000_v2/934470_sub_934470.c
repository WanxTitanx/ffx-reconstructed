// Function: sub_934470
// Address: 0x934470
void __cdecl sub_934470(int a1, int a2, int n24)
{
  int *v3; // ebx
  int v4; // esi
  int v6; // eax
  int v7; // eax
  int n26; // eax
  int v9; // eax
  int v10; // eax
  int v11; // [esp+0h] [ebp-1Ch] BYREF
  int v12; // [esp+4h] [ebp-18h] BYREF
  char Buffer[16]; // [esp+8h] [ebp-14h] BYREF

  if ( unk_193C0F0 && unk_193BF80 && *(_DWORD *)unk_193BF80 )
  {
    v3 = *(int **)(*(_DWORD *)unk_193BF80 + 8);
    if ( v3[1] <= 0 )
      v4 = 0;
    else
      v4 = v3[2] + 192 * *(_DWORD *)(unk_193C0F0 + 648);
    switch ( a2 )
    {
      case 32769:
        sub_937780(a1, &unk_C5EAC0);
        sub_93C110();
        break;
      case 32771:
        *(_DWORD *)(unk_193C0F0 + 12) = 0;
        break;
      case 32774:
        sub_93C050();
        if ( v4 && n24 )
        {
          switch ( n24 )
          {
            case 17:
              sub_934AF0();
              if ( --*(_DWORD *)(unk_193C0F0 + 648) < 0 )
                *(_DWORD *)(unk_193C0F0 + 648) = v3[1] - 1;
              goto LABEL_26;
            case 18:
              sub_934AF0();
              v6 = unk_193C0F0;
              ++*(_DWORD *)(unk_193C0F0 + 648);
              if ( *(_DWORD *)(v6 + 648) >= v3[1] )
                *(_DWORD *)(unk_193C0F0 + 648) = 0;
              goto LABEL_26;
            case 19:
              sub_934AF0();
              v7 = unk_193C0F0;
              ++*(_DWORD *)(unk_193C0F0 + 652);
              if ( *(int *)(v7 + 652) > 2 )
                *(_DWORD *)(unk_193C0F0 + 652) = 0;
LABEL_26:
              sub_934B50();
              break;
            case 20:
              --*(_DWORD *)(v4 + 16);
              break;
            case 21:
              ++*(_DWORD *)(v4 + 16);
              break;
            case 22:
              --*(_DWORD *)(v4 + 12);
              break;
            case 23:
              ++*(_DWORD *)(v4 + 12);
              break;
            case 25:
              sub_93C670(unk_193C0F0 + 744, v4 + 20, "Layer Z", a1);
              *(_DWORD *)v4 &= ~4u;
              break;
            case 26:
              sub_93C2E0(unk_193C0F0 + 656, v4 + 44, 5, "X Speed", a1);
              break;
            case 27:
              sub_93C2E0(unk_193C0F0 + 700, v4 + 48, 5, "Y Speed", a1);
              break;
            case 28:
              *(_DWORD *)v4 ^= 1u;
              break;
            case 29:
              *(_DWORD *)v4 ^= 0x10u;
              sub_92B460(v3);
              break;
            case 30:
              *(_DWORD *)v4 ^= 0x20u;
              break;
            case 31:
              *(_DWORD *)v4 ^= 0x40u;
              break;
            case 32:
              v3[65] ^= 1u;
              break;
            case 33:
              sub_937EF0(unk_193C0F0 + 16, 8, 8, 120, 129, 6, sub_9313F0, "Anime", a1);
              break;
            case 34:
              sub_937EF0(unk_193C0F0 + 20, 8, 8, 120, 40, 6, sub_935820, "Palette", a1);
              break;
            case 35:
              sub_937EF0(unk_193C0F0 + 24, 8, 8, 198, 78, 6, sub_932A60, "DepthZ", a1);
              *(_DWORD *)v4 |= 4u;
              break;
            case 36:
              sub_937EF0(unk_193C0F0 + 28, 8, 8, 120, 129, 6, sub_931050, "Alpha", a1);
              break;
            default:
              return;
          }
        }
        break;
      case 32775:
        if ( n24 == 24 )
          sub_93C150(a1, 24);
        break;
      case 32785:
        if ( v4 )
        {
          if ( sub_93C120(a1) )
          {
            sub_93C060(&v11, &v12);
            *(_DWORD *)(v4 + 12) += v11;
            *(_DWORD *)(v4 + 16) += v12;
          }
          sub_848820(71);
          sub_848860(1);
          n26 = *(_DWORD *)(unk_193C0F0 + 648);
          if ( n26 >= 26 )
            sub_848880("_%c", n26 + 71);
          else
            sub_848880("%c", n26 + 97);
          v9 = *(_DWORD *)(unk_193C0F0 + 652);
          if ( v9 )
          {
            v10 = v9 - 1;
            if ( v10 )
            {
              if ( v10 == 1 )
                sub_84A710(a1, 19, "Only");
            }
            else
            {
              sub_84A710(a1, 19, "White");
            }
          }
          else
          {
            sub_84A710(a1, 19, "Norm.");
          }
          sub_848820(2);
          sub_848860(38);
          sub_848880("X:%d", *(_DWORD *)(v4 + 12));
          sub_848820(2);
          sub_848860(48);
          sub_848880("Y:%d", *(_DWORD *)(v4 + 16));
          sprintf(Buffer, "%d", *(_DWORD *)(v4 + 44));
          sub_84A710(a1, 26, Buffer);
          sprintf(Buffer, "%d", *(_DWORD *)(v4 + 48));
          sub_84A710(a1, 27, Buffer);
          if ( (*(_BYTE *)v4 & 1) != 0 )
            sub_84A710(a1, 28, "OFF");
          else
            sub_84A710(a1, 28, "ON");
          if ( (*(_BYTE *)v4 & 0x10) != 0 )
            sub_84A710(a1, 29, "ON");
          else
            sub_84A710(a1, 29, "OFF");
          if ( (*(_BYTE *)v4 & 0x20) != 0 )
            sub_84A710(a1, 30, "OFF");
          else
            sub_84A710(a1, 30, "ON");
          if ( (*(_BYTE *)v4 & 0x40) != 0 )
            sub_84A710(a1, 31, "ON");
          else
            sub_84A710(a1, 31, "OFF");
          if ( v3[65] )
            sub_84A710(a1, 32, "ON");
          else
            sub_84A710(a1, 32, "OFF");
          if ( (*(_BYTE *)v4 & 4) != 0 )
          {
            sub_84A710(a1, 25, "-");
          }
          else
          {
            sprintf(Buffer, "%d", (int)*(float *)(v4 + 20));
            sub_84A710(a1, 25, Buffer);
          }
        }
        break;
      default:
        return;
    }
  }
}
