// Function: sub_A28F00
// Address: 0xa28f00
// Size: 0x2e
// Prototype: int __stdcall(float, float, float, float)

int __thiscall sub_A28F00(float *this, float a2, float a3, float a4, float a5)
{
  *(this + 29) = a2;
  *(this + 30) = a3;
  *(this + 31) = a4;
  *(this + 32) = a5;
  return sub_A26970(unk_1984C6C, (int)this);
}

