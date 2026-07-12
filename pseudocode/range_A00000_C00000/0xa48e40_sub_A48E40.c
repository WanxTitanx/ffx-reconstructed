// Function: sub_A48E40
// Address: 0xa48e40
// Size: 0x8b
// Prototype: int __cdecl(int, float)

int __cdecl sub_A48E40(int a1, float a2)
{
  int result; // eax

  if ( a1 == *(unsigned __int16 *)(dword_2305834[0] + 70396) )
  {
    sub_A5ACA0();
    result = unk_1A86108;
    *(_WORD *)(unk_1A86108 + 5859) = 769;
    *(_BYTE *)(result + 5861) = 1;
    *(_WORD *)(result + 9984) = 7;
    *(_DWORD *)(result + 9988) = sub_A56330;
    *(_BYTE *)(result + 5860) |= 8u;
  }
  else
  {
    result = sub_A48D70(a1, a2);
    if ( !*(_DWORD *)(dword_2305834[0] + 71088) )
    {
      *(_DWORD *)(dword_2305834[0] + 71088) = *(_DWORD *)(dword_2305834[0] + 71080);
      result = dword_2305834[0];
      *(_DWORD *)(dword_2305834[0] + 71080) = sub_A5A020;
    }
  }
  return result;
}

