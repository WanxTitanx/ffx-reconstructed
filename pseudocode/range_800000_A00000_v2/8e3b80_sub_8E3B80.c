// Function: sub_8E3B80
// Address: 0x8e3b80
int __cdecl sub_8E3B80(__int16 a1)
{
  int result; // eax

  result = MEMORY[0x23CC128];
  if ( MEMORY[0x23CC128] )
  {
    *(_BYTE *)(MEMORY[0x23CC128] + 69) = 1;
    *(_WORD *)(MEMORY[0x23CC128] + 44) = a1;
    *(_WORD *)(MEMORY[0x23CC128] + 72) = a1;
    result = MEMORY[0x23CC128];
    *(_DWORD *)(MEMORY[0x23CC128] + 40) = 6;
  }
  return result;
}
