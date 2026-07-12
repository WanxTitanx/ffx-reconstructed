// Function: sub_A174F0
// Address: 0xa174f0
// Size: 0x55
// Prototype: 

char __stdcall sub_A174F0(int a1, int a2)
{
  int v2; // esi
  char result; // al

  v2 = sub_A09A40(a1);
  *(_DWORD *)(a2 + 4) = *(_DWORD *)(v2 + 4);
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(v2 + 8);
  *(_DWORD *)(a2 + 12) = *(_DWORD *)(v2 + 12);
  *(_BYTE *)(a2 + 16) = *(_BYTE *)(v2 + 16);
  result = *(_BYTE *)(v2 + 17);
  *(_BYTE *)(a2 + 17) = result;
  *(float *)(a2 + 20) = *(float *)(v2 + 20);
  *(float *)(a2 + 24) = *(float *)(v2 + 24);
  *(float *)(a2 + 28) = *(float *)(v2 + 28);
  *(float *)(a2 + 32) = *(float *)(v2 + 32);
  *(float *)(a2 + 36) = *(float *)(v2 + 36);
  return result;
}

