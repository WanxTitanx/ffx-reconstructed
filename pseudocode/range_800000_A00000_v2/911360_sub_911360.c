// Function: sub_911360
// Address: 0x911360
int sub_911360()
{
  int i; // ebx
  int result; // eax

  for ( i = 0; i < 1024; ++i )
  {
    if ( (i & 0xF) == 0 )
      result = sub_62FA40(0);
  }
  return result;
}
