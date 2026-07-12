// Function: sub_935820
// Address: 0x935820
void __cdecl sub_935820(int a1, int a2, int a3)
{
  int v3; // esi
  unsigned __int8 n0x63; // al
  char v5; // al

  if ( unk_193C0F0 && unk_193BF80 && *(_DWORD *)unk_193BF80 )
  {
    v3 = 192 * *(_DWORD *)(unk_193C0F0 + 648) + *(_DWORD *)(*(_DWORD *)(*(_DWORD *)unk_193BF80 + 8) + 8) + 176;
    switch ( a2 )
    {
      case 32769:
        sub_937780(a1, dword_C5F000);
        break;
      case 32771:
        *(_DWORD *)(unk_193C0F0 + 20) = 0;
        break;
      case 32774:
        if ( v3 )
        {
          switch ( a3 )
          {
            case '3':
              if ( ++*(_BYTE *)(v3 + 10) >= 3u )
                *(_BYTE *)(v3 + 10) = 0;
              break;
            case '4':
              v5 = *(_BYTE *)(v3 + 11);
              if ( v5 )
                *(_BYTE *)(v3 + 11) = v5 - 1;
              break;
            case '5':
              n0x63 = *(_BYTE *)(v3 + 11);
              if ( n0x63 < 0x63u )
                *(_BYTE *)(v3 + 11) = n0x63 + 1;
              break;
          }
        }
        break;
      case 32785:
        if ( v3 )
        {
          if ( *(_BYTE *)(v3 + 10) )
          {
            if ( *(_BYTE *)(v3 + 10) == 1 )
            {
              sub_84A710(a1, 51, "Roll");
            }
            else if ( *(_BYTE *)(v3 + 10) == 2 )
            {
              sub_84A710(a1, 51, "Shift");
            }
          }
          else
          {
            sub_84A710(a1, 51, "-");
          }
          sub_848820(71);
          sub_848860(14);
          sub_848880("%02d", *(unsigned __int8 *)(v3 + 11));
        }
        break;
      default:
        return;
    }
  }
}
