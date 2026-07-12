// Function: sub_936A00
// Address: 0x936a00
void __cdecl sub_936A00(int a1, int a2, int a3)
{
  int v3; // ecx
  bool v4; // sf
  int v5; // eax
  int v6; // eax
  _DWORD v7[13]; // [esp+0h] [ebp-48h]
  char Buffer[16]; // [esp+34h] [ebp-14h] BYREF

  v3 = unk_193C0F0;
  if ( unk_193C0F0 && unk_193BF80 )
  {
    switch ( a2 )
    {
      case 32769:
        sub_937780(a1, dword_C60618);
        break;
      case 32771:
        *(_DWORD *)(unk_193C0F0 + 76) = 0;
        break;
      case 32774:
        switch ( a3 )
        {
          case 184:
            *(_DWORD *)(unk_193C0F0 + 2788) += 4096;
            *(_DWORD *)(unk_193C0F0 + 2788) &= 0x3FFFu;
            break;
          case 185:
            *(_DWORD *)(unk_193C0F0 + 2788) += 256;
            *(_DWORD *)(unk_193C0F0 + 2788) &= 0x3FFFu;
            break;
          case 186:
            *(_DWORD *)(unk_193C0F0 + 2788) += 16;
            *(_DWORD *)(unk_193C0F0 + 2788) &= 0x3FFFu;
            break;
          case 187:
            ++*(_DWORD *)(unk_193C0F0 + 2788);
            *(_DWORD *)(unk_193C0F0 + 2788) &= 0x3FFFu;
            break;
          case 188:
            sub_93C2E0(unk_193C0F0 + 2828, unk_193C0F0 + 2792, 5, "TBW", a1);
            break;
          case 189:
            ++*(_DWORD *)(unk_193C0F0 + 2796);
            if ( *(int *)(v3 + 2796) > 12 )
              *(_DWORD *)(unk_193C0F0 + 2796) = 0;
            break;
          case 190:
            sub_93C2E0(unk_193C0F0 + 2872, unk_193C0F0 + 2800, 5, "TW", a1);
            break;
          case 191:
            sub_93C2E0(unk_193C0F0 + 2916, unk_193C0F0 + 2804, 5, "TH", a1);
            break;
          case 192:
            *(_DWORD *)(unk_193C0F0 + 2808) += 4096;
            *(_DWORD *)(unk_193C0F0 + 2808) &= 0x3FFFu;
            break;
          case 193:
            *(_DWORD *)(unk_193C0F0 + 2808) += 256;
            *(_DWORD *)(unk_193C0F0 + 2808) &= 0x3FFFu;
            break;
          case 194:
            *(_DWORD *)(unk_193C0F0 + 2808) += 16;
            *(_DWORD *)(unk_193C0F0 + 2808) &= 0x3FFFu;
            break;
          case 195:
            ++*(_DWORD *)(unk_193C0F0 + 2808);
            *(_DWORD *)(unk_193C0F0 + 2808) &= 0x3FFFu;
            break;
          case 196:
            sub_93C2E0(unk_193C0F0 + 2960, unk_193C0F0 + 2812, 5, "W", a1);
            break;
          case 197:
            sub_93C2E0(unk_193C0F0 + 3004, unk_193C0F0 + 2816, 5, "H", a1);
            break;
          case 198:
            ++*(_DWORD *)(unk_193C0F0 + 2820);
            if ( *(int *)(v3 + 2820) > 2 )
              *(_DWORD *)(unk_193C0F0 + 2820) = 0;
            break;
          case 199:
            sub_937190();
            *(_DWORD *)(unk_193C0F0 + 2824) = 0;
            break;
          default:
            return;
        }
        break;
      case 32778:
        switch ( a3 )
        {
          case 184:
            *(_DWORD *)(unk_193C0F0 + 2788) -= 4096;
            *(_DWORD *)(unk_193C0F0 + 2788) &= 0x3FFFu;
            break;
          case 185:
            *(_DWORD *)(unk_193C0F0 + 2788) -= 256;
            *(_DWORD *)(unk_193C0F0 + 2788) &= 0x3FFFu;
            break;
          case 186:
            *(_DWORD *)(unk_193C0F0 + 2788) -= 16;
            *(_DWORD *)(unk_193C0F0 + 2788) &= 0x3FFFu;
            break;
          case 187:
            --*(_DWORD *)(unk_193C0F0 + 2788);
            *(_DWORD *)(unk_193C0F0 + 2788) &= 0x3FFFu;
            break;
          case 189:
            v4 = --*(_DWORD *)(unk_193C0F0 + 2796) < 0;
            if ( v4 )
              *(_DWORD *)(unk_193C0F0 + 2796) = 12;
            break;
          case 192:
            *(_DWORD *)(unk_193C0F0 + 2808) -= 4096;
            *(_DWORD *)(unk_193C0F0 + 2808) &= 0x3FFFu;
            break;
          case 193:
            *(_DWORD *)(unk_193C0F0 + 2808) -= 256;
            *(_DWORD *)(unk_193C0F0 + 2808) &= 0x3FFFu;
            break;
          case 194:
            *(_DWORD *)(unk_193C0F0 + 2808) -= 16;
            *(_DWORD *)(unk_193C0F0 + 2808) &= 0x3FFFu;
            break;
          case 195:
            --*(_DWORD *)(unk_193C0F0 + 2808);
            *(_DWORD *)(unk_193C0F0 + 2808) &= 0x3FFFu;
            break;
          case 196:
            *(_DWORD *)(unk_193C0F0 + 2812) = *(_DWORD *)(unk_193C0F0 + 2816);
            break;
          case 197:
            *(_DWORD *)(unk_193C0F0 + 2816) = *(_DWORD *)(unk_193C0F0 + 2812);
            break;
          case 198:
            v4 = --*(_DWORD *)(unk_193C0F0 + 2820) < 0;
            if ( v4 )
              *(_DWORD *)(unk_193C0F0 + 2820) = 2;
            break;
          case 199:
            *(_DWORD *)(unk_193C0F0 + 2824) ^= 1u;
            break;
          default:
            return;
        }
        break;
      case 32785:
        v7[0] = "CT32";
        v7[1] = "CT24";
        v7[2] = "CT16";
        v7[3] = "CT16S";
        v7[4] = "T8";
        v7[5] = "T4";
        v7[6] = "T8H";
        v7[7] = "T4HL";
        v7[8] = "T4HH";
        v7[9] = "Z32";
        v7[10] = "Z24";
        v7[11] = "Z16";
        v7[12] = "Z16S";
        sub_848820(54);
        sub_848860(3);
        sub_848880("%04x", *(_DWORD *)(unk_193C0F0 + 2788));
        sprintf(Buffer, "%d", *(_DWORD *)(unk_193C0F0 + 2792));
        sub_84A710(a1, 188, Buffer);
        sprintf(Buffer, "%s", (const char *)v7[*(_DWORD *)(unk_193C0F0 + 2796)]);
        sub_84A710(a1, 189, Buffer);
        sprintf(Buffer, "%d", *(_DWORD *)(unk_193C0F0 + 2800));
        sub_84A710(a1, 190, Buffer);
        sprintf(Buffer, "%d", *(_DWORD *)(unk_193C0F0 + 2804));
        sub_84A710(a1, 191, Buffer);
        sub_848820(54);
        sub_848860(81);
        sub_848880("%04x", *(_DWORD *)(unk_193C0F0 + 2808));
        sprintf(Buffer, "%d", *(_DWORD *)(unk_193C0F0 + 2812));
        sub_84A710(a1, 196, Buffer);
        sprintf(Buffer, "%d", *(_DWORD *)(unk_193C0F0 + 2816));
        sub_84A710(a1, 197, Buffer);
        v5 = *(_DWORD *)(unk_193C0F0 + 2820);
        if ( v5 )
        {
          v6 = v5 - 1;
          if ( v6 )
          {
            if ( v6 == 1 )
              sub_84A710(a1, 198, "x2");
          }
          else
          {
            sub_84A710(a1, 198, "x1.5");
          }
        }
        else
        {
          sub_84A710(a1, 198, "x1");
        }
        break;
      default:
        return;
    }
  }
}
