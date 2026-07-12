// Function: sub_81F0E0
// Address: 0x81f0e0
int __cdecl sub_81F0E0(int a1)
{
  _DWORD *v2; // eax
  int v3; // edx
  int v4; // eax
  char *v5; // ecx

  if ( sub_A44740(&unk_12F4DE0, 4096, 0) >= 0 )
  {
    while ( sub_A44740(&unk_12F4E08, 4097, 0) >= 0 )
    {
      if ( unk_12F4E04 && unk_12F4E2C )
      {
        nullsub_33(0);
        v2 = off_C49458;
        unk_12F4F04 = 0;
        unk_12F4E38 = 0;
        unk_12F4E34 = 0;
        unk_12F4E9C = 0;
        n3_15 = 3;
        unk_12F4100 = a1;
        *(_DWORD *)off_C49458 = a1;
        v2[1] = &unk_12F4E40;
        sub_81CCE0(1);
        v3 = *(_DWORD *)off_C49460;
        unk_12F4F48 = *((_DWORD *)off_C49460 + 1);
        unk_12F4F4C = *((_DWORD *)off_C49460 + 2);
        unk_12F4E84 = *((_DWORD *)off_C49460 + 3);
        v4 = *((_DWORD *)off_C49460 + 4);
        dword_12F4E80 = v3;
        unk_12F4E8C = v4;
        n51200 = 51200;
        unk_12F4108 = 1;
        v5 = (char *)&dword_12F4E80;
        do
        {
          v5 -= 4;
          *(_DWORD *)v5 = 0;
        }
        while ( v5 != (char *)&unk_12F4E40 );
        return v3;
      }
      if ( sub_A44740(&unk_12F4DE0, 4096, 0) < 0 )
        return 0;
    }
  }
  return 0;
}
