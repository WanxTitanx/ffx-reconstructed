// Function: sub_931E90
// Address: 0x931e90
void __cdecl sub_931E90(int a1, int a2, int a3)
{
  int v3; // ecx
  int v4; // ecx
  int v5; // eax
  bool v6; // sf
  int v7; // edx
  int v8; // eax
  int v9; // ecx
  char Buffer[16]; // [esp+0h] [ebp-14h] BYREF

  v3 = unk_193C0F0;
  if ( unk_193C0F0 )
  {
    switch ( a2 )
    {
      case 32769:
        sub_937780(a1, &unk_C5FF68);
        sub_932320();
        break;
      case 32771:
        *(_DWORD *)(unk_193C0F0 + 60) = 0;
        break;
      case 32774:
        switch ( a3 )
        {
          case 146:
            ++*(_DWORD *)(unk_193C0F0 + 2224);
            if ( *(_DWORD *)(v3 + 2224) >= *(_DWORD *)(unk_193C0F0 + 2084) )
              *(_DWORD *)(unk_193C0F0 + 2224) = 0;
            goto LABEL_8;
          case 147:
            *(_DWORD *)(unk_193C0F0 + 2228) ^= 1u;
            return;
          case 148:
            *(_DWORD *)(unk_193C0F0 + 2236) = 0;
            *(_DWORD *)(unk_193C0F0 + 2240) += 10;
            v4 = unk_193C0F0;
            if ( *(_DWORD *)(unk_193C0F0 + 2240) < *(_DWORD *)(unk_193C0F0 + 2232) )
              goto LABEL_13;
            *(_DWORD *)(unk_193C0F0 + 2240) = 0;
            goto LABEL_12;
          case 149:
            *(_DWORD *)(unk_193C0F0 + 2236) = 1;
            v5 = unk_193C0F0;
            ++*(_DWORD *)(unk_193C0F0 + 2244);
            if ( *(_DWORD *)(v5 + 2244) >= *(_DWORD *)(unk_193C0F0 + 2232) )
              *(_DWORD *)(unk_193C0F0 + 2244) = 0;
            return;
          case 150:
            ++*(_DWORD *)(unk_193C0F0 + 2256);
            if ( *(_DWORD *)(v3 + 2256) >= *(_DWORD *)(unk_193C0F0 + 2252) )
              *(_DWORD *)(unk_193C0F0 + 2256) = 0;
            return;
          case 151:
            sub_937EF0(unk_193C0F0 + 64, 8, 8, 120, 77, 6, sub_935340, "Motion", a1);
            return;
          case 152:
            sub_937EF0(unk_193C0F0 + 68, 8, 8, 120, 194, 6, sub_935970, "Particle", a1);
            return;
          default:
            return;
        }
      case 32778:
        switch ( a3 )
        {
          case 146:
            v6 = --*(_DWORD *)(unk_193C0F0 + 2224) < 0;
            if ( v6 )
              *(_DWORD *)(unk_193C0F0 + 2224) = *(_DWORD *)(unk_193C0F0 + 2084) - 1;
LABEL_8:
            sub_932470();
            break;
          case 148:
            *(_DWORD *)(unk_193C0F0 + 2236) = 0;
            *(_DWORD *)(unk_193C0F0 + 2240) -= 10;
            v4 = unk_193C0F0;
            if ( *(int *)(unk_193C0F0 + 2240) < 0 )
            {
              *(_DWORD *)(unk_193C0F0 + 2240) = *(_DWORD *)(unk_193C0F0 + 2232) - 1;
LABEL_12:
              v4 = unk_193C0F0;
            }
LABEL_13:
            *(_DWORD *)(v4 + 2244) = *(_DWORD *)(v4 + 2240);
            break;
          case 149:
            *(_DWORD *)(unk_193C0F0 + 2236) = 1;
            v6 = --*(_DWORD *)(unk_193C0F0 + 2244) < 0;
            if ( v6 )
              *(_DWORD *)(unk_193C0F0 + 2244) = *(_DWORD *)(unk_193C0F0 + 2232) - 1;
            break;
          case 150:
            v6 = --*(_DWORD *)(unk_193C0F0 + 2256) < 0;
            if ( v6 )
              *(_DWORD *)(unk_193C0F0 + 2256) = *(_DWORD *)(unk_193C0F0 + 2252) - 1;
            break;
          default:
            return;
        }
        break;
      case 32785:
        sprintf(Buffer, "%d", *(_DWORD *)(unk_193C0F0 + 4 * *(_DWORD *)(unk_193C0F0 + 2224) + 2096));
        sub_84A710(a1, 146, Buffer);
        if ( *(_DWORD *)(unk_193C0F0 + 2228) )
          sub_84A710(a1, 147, "OptP");
        else
          sub_84A710(a1, 147, "Elem");
        sub_848820(54);
        sub_848860(28);
        sub_848880("%d", *(_DWORD *)(unk_193C0F0 + 2232));
        v7 = *(_DWORD *)(unk_193C0F0 + 2240);
        v8 = *(_DWORD *)(unk_193C0F0 + 2232);
        v9 = v7 + 9;
        if ( v7 + 9 >= v8 )
          v9 = v8 - 1;
        sprintf(Buffer, "%d-%d", v7, v9);
        sub_84A710(a1, 148, Buffer);
        sprintf(Buffer, "%d", *(_DWORD *)(unk_193C0F0 + 2244));
        sub_84A710(a1, 149, Buffer);
        sub_848820(54);
        sub_848860(67);
        sub_848880("%d", *(_DWORD *)(unk_193C0F0 + 2252));
        sprintf(Buffer, "%d", *(_DWORD *)(unk_193C0F0 + 2256));
        sub_84A710(a1, 150, Buffer);
        break;
      default:
        return;
    }
  }
}
