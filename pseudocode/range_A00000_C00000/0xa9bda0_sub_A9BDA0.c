// Function: sub_A9BDA0
// Address: 0xa9bda0
// Size: 0x68
// Prototype: 

int __fastcall sub_A9BDA0(int a1, int a2)
{
  int result; // eax
  int v3; // edx

  memmove(
    *(void **)(a1 + 160),
    (const void *)(*(_DWORD *)(a1 + 160) + 4 * (a2 / *(_DWORD *)(a1 + 8))),
    4 * (*(_DWORD *)(a1 + 168) / *(_DWORD *)(a1 + 8) - a2 / *(_DWORD *)(a1 + 8)) + 8);
  result = a1;
  v3 = *(_DWORD *)(a1 + 172);
  *(_DWORD *)(a1 + 168) -= a2;
  if ( v3 >= 0 )
    *(_DWORD *)(a1 + 172) = v3 - a2;
  *(_DWORD *)(a1 + 176) -= a2;
  return result;
}

