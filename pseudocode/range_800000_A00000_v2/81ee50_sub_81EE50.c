// Function: sub_81EE50
// Address: 0x81ee50
void __cdecl sub_81EE50(int a1, int n2048)
{
  int n2; // esi
  int v3; // eax

  if ( a1 )
  {
    nullsub_33(0);
    dword_12F4DC0 = a1;
    unk_12F4DCC = 0;
    if ( n2048 <= 655360 )
    {
      n2 = 1;
      unk_12F4DC4 = unk_12F4E8C;
      n2048 = n2048;
    }
    else
    {
      unk_12F4DD0 = a1 + 0x80000;
      unk_12F4DD4 = unk_12F4E8C + 0x80000;
      n2 = 2;
      unk_12F4DC4 = unk_12F4E8C;
      n2048 = 0x80000;
      unk_12F4DD8 = n2048 - 0x80000;
      unk_12F4DDC = 0;
    }
    do
      v3 = sub_A44790(&dword_12F4DC0, n2);
    while ( !v3 );
    unk_12F4E90 = v3;
  }
}
