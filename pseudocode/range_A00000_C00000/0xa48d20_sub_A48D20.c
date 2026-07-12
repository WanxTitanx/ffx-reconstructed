// Function: sub_A48D20
// Address: 0xa48d20
// Size: 0x41
// Prototype: int __cdecl(int, float)

int __cdecl sub_A48D20(int a1, float a2)
{
  int result; // eax

  result = sub_A48D70(a1, a2);
  if ( !*(_DWORD *)(dword_2305834[0] + 71088) )
  {
    *(_DWORD *)(dword_2305834[0] + 71088) = *(_DWORD *)(dword_2305834[0] + 71080);
    result = dword_2305834[0];
    *(_DWORD *)(dword_2305834[0] + 71080) = sub_A59E80;
  }
  return result;
}

