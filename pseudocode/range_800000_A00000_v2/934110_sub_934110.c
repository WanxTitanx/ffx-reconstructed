// Function: sub_934110
// Address: 0x934110
void __cdecl sub_934110(int a1, int a2, int n145)
{
  int v3; // esi
  int v4; // eax
  int v5; // eax
  char Buffer[16]; // [esp+0h] [ebp-14h] BYREF

  if ( unk_193C0F0 )
  {
    if ( unk_193BF80 )
    {
      v3 = *(_DWORD *)(unk_193BF80 + 4);
      if ( v3 )
      {
        switch ( a2 )
        {
          case 32769:
            sub_937780(a1, &unk_C5FEC0);
            break;
          case 32771:
            *(_DWORD *)(unk_193C0F0 + 56) = 0;
            break;
          case 32774:
            if ( n145 == 143 )
            {
              v4 = sub_91D480(v3);
              sub_91D930(v3, v4 + 1 >= 5 ? 0 : v4 + 1);
            }
            else if ( n145 == 145 )
            {
              sub_938570();
            }
            break;
          case 32785:
            v5 = sub_91D480(v3);
            sprintf(Buffer, "%d", v5);
            sub_84A710(a1, 143, Buffer);
            break;
          default:
            return;
        }
      }
    }
  }
}
