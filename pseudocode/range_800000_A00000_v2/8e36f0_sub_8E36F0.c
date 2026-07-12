// Function: sub_8E36F0
// Address: 0x8e36f0
int sub_8E36F0()
{
  int result; // eax

  result = MEMORY[0x23CC128];
  if ( MEMORY[0x23CC128] )
  {
    *(_BYTE *)(MEMORY[0x23CC128] + 65) = 1;
    MEMORY[0x23CC128] = 0;
  }
  return result;
}
