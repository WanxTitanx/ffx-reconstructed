// Function: sub_A173E0
// Address: 0xa173e0
// Size: 0x33
// Prototype: 

char __stdcall sub_A173E0(int a1, int a2)
{
  int v2; // eax
  char result; // al

  v2 = sub_A097B0(a1);
  *(_DWORD *)(a2 + 4) = *(_DWORD *)(v2 + 4);
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(v2 + 8);
  *(_DWORD *)(a2 + 12) = *(_DWORD *)(v2 + 12);
  *(_BYTE *)(a2 + 16) = *(_BYTE *)(v2 + 16);
  result = *(_BYTE *)(v2 + 17);
  *(_BYTE *)(a2 + 17) = result;
  return result;
}

