// Function: sub_A59680
// Address: 0xa59680
// Size: 0x43
// Prototype: _DWORD __cdecl(int n8)

int __cdecl sub_A59680(int n8)
{
  _WORD *v1; // ecx
  int result; // eax

  v1 = (_WORD *)(buf + 832 * n8);
  v1[4] = *v1;
  v1[5] = v1[1];
  v1[6] = v1[2];
  v1[7] = v1[3];
  v1[10] = v1[8];
  result = (unsigned __int16)v1[9];
  v1[11] = result;
  return result;
}

