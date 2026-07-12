// Function: sub_9364D0
// Address: 0x9364d0
void __cdecl sub_9364D0(int a1, int n32774, int n13)
{
  int v3; // ecx
  BOOL v4; // eax

  v3 = unk_193C0F0;
  if ( unk_193C0F0 && unk_193BF80 && *(_DWORD *)unk_193BF80 )
  {
    if ( n32774 == 32769 )
    {
      sub_937780(a1, dword_C5EA30);
    }
    else if ( n32774 == 32771 )
    {
      *(_DWORD *)(unk_193C0F0 + 8) = 0;
    }
    else if ( n32774 == 32774 && n13 )
    {
      if ( (unsigned int)(n13 - 13) <= 3 )
      {
        v4 = n13 != 13 && n13 != 15;
        *(_DWORD *)(unk_193C0F0 + 100) = v4;
        sprintf_w();
        sub_937B20();
        if ( n13 < 15 )
          sub_939B10();
        else
          sub_938FD0();
        v3 = unk_193C0F0;
      }
      sub_937F50((_DWORD *)(v3 + 8));
    }
  }
}
