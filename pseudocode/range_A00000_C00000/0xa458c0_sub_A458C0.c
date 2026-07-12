// Function: sub_A458C0
// Address: 0xa458c0
// Size: 0x22
// Prototype: 

char __cdecl sub_A458C0(char a1, int a2)
{
  char result; // al

  result = ~(1 << a1);
  *(_BYTE *)(unk_2305834 + 40 * a2 + 2089) &= result;
  return result;
}

