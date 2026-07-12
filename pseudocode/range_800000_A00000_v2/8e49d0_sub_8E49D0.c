// Function: sub_8E49D0
// Address: 0x8e49d0
int sub_8E49D0()
{
  int result; // eax

  result = MEMORY[0x23CC128];
  if ( MEMORY[0x23CC128] )
  {
    *(_BYTE *)(MEMORY[0x23CC128] + 69) = 0;
    result = MEMORY[0x23CC128];
    *(_DWORD *)(MEMORY[0x23CC128] + 40) = 1;
  }
  return result;
}
