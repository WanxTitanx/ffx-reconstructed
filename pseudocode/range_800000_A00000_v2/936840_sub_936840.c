// Function: sub_936840
// Address: 0x936840
void __cdecl sub_936840(int a1, int a2, int n183)
{
  int v3; // edx
  int v4; // esi
  int v5; // edi
  char Buffer[16]; // [esp+0h] [ebp-14h] BYREF

  if ( unk_193C0F0 )
  {
    if ( unk_193BF80 )
    {
      if ( *(_DWORD *)unk_193BF80 )
      {
        v3 = *(_DWORD *)(*(_DWORD *)unk_193BF80 + 8);
        if ( v3 )
        {
          v4 = *(_DWORD *)(unk_193C0F0 + 2784);
          v5 = *(_DWORD *)(v3 + 8) + 192 * v4;
          switch ( a2 )
          {
            case 32769:
              sub_937780(a1, dword_C605E0);
              break;
            case 32771:
              *(_DWORD *)(unk_193C0F0 + 72) = 0;
              break;
            case 32774:
              if ( n183 == 183 )
              {
                *(_DWORD *)(unk_193C0F0 + 2784) = v4 + 1;
                if ( v4 + 1 >= *(_DWORD *)(v3 + 4) )
                  *(_DWORD *)(unk_193C0F0 + 2784) = 0;
              }
              break;
            case 32778:
              if ( n183 == 183 )
              {
                *(_DWORD *)(unk_193C0F0 + 2784) = v4 - 1;
                if ( v4 - 1 < 0 )
                  *(_DWORD *)(unk_193C0F0 + 2784) = *(_DWORD *)(v3 + 4) - 1;
              }
              break;
            case 32785:
              sprintf(Buffer, "%d", v4);
              sub_84A710(a1, 183, Buffer);
              sub_848820(54);
              sub_848860(15);
              sub_848880("%d", *(_DWORD *)(v5 + 4));
              sub_848820(54);
              sub_848860(28);
              sub_848880("%d", *(_DWORD *)(v5 + 8));
              break;
            default:
              return;
          }
        }
      }
    }
  }
}
