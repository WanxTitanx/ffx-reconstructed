// Function: sub_8E4A10
// Address: 0x8e4a10
__int16 __cdecl sub_8E4A10(__int16 a1)
{
  __int16 result; // ax

  if ( MEMORY[0x23CC128] )
  {
    *(_WORD *)(MEMORY[0x23CC128] + 56) = a1;
    return a1;
  }
  return result;
}
