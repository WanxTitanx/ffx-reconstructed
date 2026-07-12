// Function: sub_81F000
// Address: 0x81f000
int __cdecl sub_81F000(int a1, int a2)
{
  int n0x10000; // esi
  int result; // eax

  nullsub_33(0);
  n0x10000 = 1;
  do
  {
    if ( n0x10000 )
    {
      n0x10000 = 0;
    }
    else
    {
      n0x10000 = 0x10000;
      while ( n0x10000-- )
        ;
    }
    result = sub_A44770(unk_12F4E90);
  }
  while ( a2 && result >= 0 );
  return result;
}
