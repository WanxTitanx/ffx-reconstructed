// Function: sub_A2A400
// Address: 0xa2a400
// Size: 0x35
// Prototype: 

int __thiscall sub_A2A400(_DWORD *this, int a2)
{
  int v2; // eax
  int v4; // [esp-4h] [ebp-4h]

  v2 = *(this + 86);
  *(this + 89) = a2;
  v4 = *(_DWORD *)(a2 + 316);
  *(_DWORD *)(a2 + 72) = *(_DWORD *)(v2 + 52);
  return sub_5B9C30(this + 41, *(this + 45), 0, v4);
}

