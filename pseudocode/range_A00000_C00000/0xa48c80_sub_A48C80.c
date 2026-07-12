// Function: sub_A48C80
// Address: 0xa48c80
// Size: 0x96
// Prototype: 

int __cdecl sub_A48C80(int a1, __int16 a2)
{
  int result; // eax

  *(_WORD *)(dword_2305834[0] + 71218) = *(_WORD *)(dword_2305834[0] + 80 * a1 + 69836);
  *(_WORD *)(dword_2305834[0] + 71216) = *(_WORD *)(dword_2305834[0] + 71218);
  *(_WORD *)(dword_2305834[0] + 71220) = a2;
  *(float *)(dword_2305834[0] + 71200) = 1.0;
  *(float *)(dword_2305834[0] + 71204) = 0.0;
  result = dword_2305834[0];
  *(_BYTE *)(dword_2305834[0] + 71224) = a1;
  if ( !*(_DWORD *)(dword_2305834[0] + 71088) )
  {
    *(_DWORD *)(dword_2305834[0] + 71088) = *(_DWORD *)(dword_2305834[0] + 71080);
    result = dword_2305834[0];
    *(_DWORD *)(dword_2305834[0] + 71080) = sub_A59990;
  }
  return result;
}

