// Function: sub_9B11D0
// Address: 0x9b11d0
int __thiscall sub_9B11D0(_DWORD *this, int a2, int a3)
{
  int v3; // eax
  int v5; // [esp-4h] [ebp-Ch]

  *(_DWORD *)(a2 + 4 * *(_DWORD *)(a2 + 32) + 16) = 0;
  *(_DWORD *)(a2 + 4 * *(_DWORD *)(a2 + 32)) = *(this + --*(this + 96) + 92);
  v3 = *(_DWORD *)(a2 + 32) + 1;
  v5 = *(_DWORD *)(a2 + 4 * v3 - 4);
  *(_DWORD *)(a2 + 32) = v3;
  return sub_9B1530(a3, v5);
}
