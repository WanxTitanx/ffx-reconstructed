// Function: sub_A8E620
// Address: 0xa8e620
// Size: 0x1c
// Prototype: int __thiscall(_DWORD)

int __thiscall sub_A8E620(int this)
{
  *(_BYTE *)(this + 16) = 1;
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 4) = 0;
  *(_DWORD *)(this + 8) = 0;
  return this;
}

