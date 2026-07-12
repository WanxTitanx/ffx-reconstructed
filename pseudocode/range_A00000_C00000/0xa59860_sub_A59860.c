// Function: sub_A59860
// Address: 0xa59860
// Size: 0x32
// Prototype: 

int __cdecl sub_A59860(int a1, int a2)
{
  int buf; // edx
  int result; // eax

  buf = buf;
  result = buf + 832 * a1;
  *(_WORD *)(result + 35) = 769;
  *(_BYTE *)(result + 37) = 1;
  *(_WORD *)(buf + 9984) = a1;
  *(_DWORD *)(buf + 9988) = a2;
  return result;
}

