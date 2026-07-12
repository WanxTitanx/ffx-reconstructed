// Function: sub_933CC0
// Address: 0x933cc0
void __cdecl sub_933CC0(int a1, int a2, int a3)
{
  int v3; // ecx
  int n99; // eax
  int v5; // esi
  int v6; // eax
  int v8; // eax
  int v9; // eax
  const char *ON; // eax
  char Buffer[16]; // [esp+0h] [ebp-14h] BYREF

  v3 = unk_193C0F0;
  if ( unk_193C0F0 )
  {
    switch ( a2 )
    {
      case 32769:
        sub_937780(a1, &unk_C5F828);
        break;
      case 32771:
        *(_DWORD *)(unk_193C0F0 + 48) = 0;
        break;
      case 32774:
        switch ( a3 )
        {
          case 'j':
            ++*(_DWORD *)(unk_193C0F0 + 1532);
            if ( *(int *)(v3 + 1532) > 99 )
              *(_DWORD *)(unk_193C0F0 + 1532) = 0;
            break;
          case 'k':
            *(_DWORD *)(unk_193C0F0 + 1532) += 10;
            n99 = *(_DWORD *)(unk_193C0F0 + 1532);
            if ( n99 > 99 )
              *(_DWORD *)(unk_193C0F0 + 1532) = n99 - 100;
            break;
          case 'l':
            sub_7297F0(*(_WORD *)(unk_193C0F0 + 1532));
            break;
          case 'm':
            sub_729750(*(_WORD *)(unk_193C0F0 + 1532));
            break;
          case 'n':
            sub_7296A0(*(_WORD *)(unk_193C0F0 + 1532));
            break;
          case 'o':
            sub_729660(*(_WORD *)(unk_193C0F0 + 1532));
            break;
          case 'p':
            sub_729900(*(_WORD *)(unk_193C0F0 + 1532));
            break;
          case 'r':
            unk_CEC1E0 ^= 1u;
            break;
          case 's':
            sub_93A7E0();
            sub_938340();
            break;
          case 't':
            sub_937EF0(unk_193C0F0 + 52, 8, 8, 120, 197, 6, sub_932F20, "FP Adj.", a1);
            break;
          case 'u':
            sub_919B70();
            break;
          case 'v':
            v5 = *(_DWORD *)(unk_193C0F0 + 4 * *(_DWORD *)(unk_193C0F0 + 2224) + 2160);
            if ( *(_DWORD *)(unk_193C0F0 + 2228) )
            {
              v6 = sub_8356E0(v5, *(_DWORD *)(unk_193C0F0 + 2256), 0);
              v3 = unk_193C0F0;
            }
            else
            {
              v6 = *(_DWORD *)(unk_193C0F0 + 2244);
            }
            sub_72A620(*(_DWORD *)(v3 + 1532), v5, v6);
            sub_7297F0(*(_WORD *)(unk_193C0F0 + 1532));
            break;
          case 'w':
            sub_729620(*(_WORD *)(unk_193C0F0 + 1532));
            break;
          default:
            return;
        }
        break;
      case 32778:
        switch ( a3 )
        {
          case 'j':
            if ( --*(_DWORD *)(unk_193C0F0 + 1532) < 0 )
              *(_DWORD *)(unk_193C0F0 + 1532) = 99;
            break;
          case 'k':
            *(_DWORD *)(unk_193C0F0 + 1532) -= 10;
            v8 = *(_DWORD *)(unk_193C0F0 + 1532);
            if ( v8 < 0 )
              *(_DWORD *)(unk_193C0F0 + 1532) = v8 + 100;
            break;
          case 'm':
          case 'v':
            sub_7296E0(*(_WORD *)(unk_193C0F0 + 1532));
            break;
          case 'w':
            sub_7295E0(*(_WORD *)(unk_193C0F0 + 1532));
            break;
          default:
            return;
        }
        break;
      case 32785:
        sprintf(Buffer, "%d", *(_DWORD *)(unk_193C0F0 + 1532));
        sub_84A710(a1, 106, Buffer);
        v9 = sub_72A850(*(_WORD *)(unk_193C0F0 + 1532));
        sprintf(Buffer, "%d", v9);
        sub_84A710(a1, 113, Buffer);
        ON = "ON";
        if ( !unk_CEC1E0 )
          ON = "OFF";
        sub_84A710(a1, 114, ON);
        break;
      default:
        return;
    }
  }
}
