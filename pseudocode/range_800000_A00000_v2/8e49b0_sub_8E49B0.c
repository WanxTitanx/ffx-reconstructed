// Function: sub_8E49B0
// Address: 0x8e49b0
int sub_8E49B0()
{
  int result; // eax

  if ( MEMORY[0x23CC128] )
    return sub_8AAE60(*(_DWORD *)(MEMORY[0x23CC128] + 12 * *(__int16 *)(MEMORY[0x23CC128] + 72) + 92));
  return result;
}
