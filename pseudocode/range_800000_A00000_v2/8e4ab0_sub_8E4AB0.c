// Function: sub_8E4AB0
// Address: 0x8e4ab0
int sub_8E4AB0()
{
  int result; // eax

  result = MEMORY[0x23CC128];
  if ( MEMORY[0x23CC128] )
    return sub_8E4AD0(MEMORY[0x23CC128]);
  return result;
}
