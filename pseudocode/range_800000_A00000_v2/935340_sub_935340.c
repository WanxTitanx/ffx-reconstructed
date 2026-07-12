// Function: sub_935340
// Address: 0x935340
void __cdecl sub_935340(int a1, int a2, int n159)
{
  int v3; // ecx
  int v4; // edi
  int v5; // eax
  int v7; // esi
  char Buffer[16]; // [esp+0h] [ebp-14h] BYREF

  v3 = unk_193C0F0;
  if ( unk_193C0F0 )
  {
    v4 = *(_DWORD *)(unk_193C0F0 + 4 * *(_DWORD *)(unk_193C0F0 + 2224) + 2160);
    switch ( a2 )
    {
      case 32769:
        sub_937780(a1, dword_C600F0);
        break;
      case 32771:
        if ( v4 != -1 )
        {
          FFX_BtlMenu_ResetActorCommandFlags(v4, 0);
          v3 = unk_193C0F0;
        }
        *(_DWORD *)(v3 + 64) = 0;
        break;
      case 32774:
        switch ( n159 )
        {
          case 153:
            if ( v4 != -1 )
            {
              v5 = sub_924F30(v4);
              sub_788380(v5, dword_C60A78[2 * *(_DWORD *)(unk_193C0F0 + 2264)]);
              *(_DWORD *)(unk_193C0F0 + 2272) = sub_836B70(v4);
            }
            break;
          case 154:
            sub_935690(-1);
            break;
          case 155:
            if ( --*(_DWORD *)(unk_193C0F0 + 2264) < 0 )
              *(_DWORD *)(unk_193C0F0 + 2264) = 104;
            break;
          case 156:
            ++*(_DWORD *)(unk_193C0F0 + 2264);
            if ( *(_DWORD *)(v3 + 2264) >= 0x69u )
              *(_DWORD *)(unk_193C0F0 + 2264) = 0;
            break;
          case 157:
            sub_935690(1);
            break;
          case 158:
            sub_93C2E0(unk_193C0F0 + 2280, unk_193C0F0 + 2260, 5, "Motion Speed", a1);
            break;
          case 159:
            *(_DWORD *)(unk_193C0F0 + 2268) = 1;
            *(_DWORD *)(unk_193C0F0 + 2276) = 1;
            break;
          default:
            return;
        }
        break;
      case 32778:
        if ( n159 == 158 )
        {
          *(_DWORD *)(unk_193C0F0 + 2260) = 0;
        }
        else if ( n159 == 159 )
        {
          *(_DWORD *)(unk_193C0F0 + 2268) = 0;
        }
        break;
      case 32785:
        if ( v4 != -1 )
        {
          if ( *(_DWORD *)(unk_193C0F0 + 2268) )
          {
            if ( *(_DWORD *)(unk_193C0F0 + 2276) )
            {
              sub_82B400(v4, 256);
              *(_DWORD *)(unk_193C0F0 + 2276) = 0;
            }
            else
            {
              sub_82B400(v4, 0);
            }
          }
          else
          {
            sub_82B400(v4, *(_DWORD *)(unk_193C0F0 + 2260));
          }
          v3 = unk_193C0F0;
        }
        sub_84A710(a1, 153, (&off_C60A7C)[2 * *(_DWORD *)(v3 + 2264)]);// "appear_00"
        sprintf(Buffer, "%d", *(_DWORD *)(unk_193C0F0 + 2260));
        sub_84A710(a1, 158, Buffer);
        if ( v4 != -1 )
        {
          v7 = sub_8398E0(v4) / 256;
          sub_848820(8);
          sub_848860(41);
          sub_848880("Frame:%d/%d", v7, *(_DWORD *)(unk_193C0F0 + 2272));
        }
        break;
      default:
        return;
    }
  }
}
