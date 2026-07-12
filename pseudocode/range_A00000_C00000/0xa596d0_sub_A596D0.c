// Function: sub_A596D0
// Address: 0xa596d0
// Size: 0x3f
// Prototype: _DWORD __cdecl(int n7)

int __cdecl sub_A596D0(int n7)
{
  int v1; // ecx
  int result; // eax

  v1 = buf + 832 * n7;
  *(_WORD *)(v1 + 42) = *(_WORD *)(v1 + 8);
  *(_WORD *)(v1 + 44) = *(_WORD *)(v1 + 10);
  *(_WORD *)(v1 + 46) = *(_WORD *)(v1 + 12);
  result = *(unsigned __int16 *)(v1 + 14);
  *(_WORD *)(v1 + 48) = result;
  *(_BYTE *)(v1 + 50) = 0;
  *(_DWORD *)(v1 + 52) = sub_A5A170;
  return result;
}

