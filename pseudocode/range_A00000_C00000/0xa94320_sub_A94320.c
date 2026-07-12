// Function: sub_A94320
// Address: 0xa94320
// Size: 0x62
// Prototype: int __thiscall(_DWORD)

int __thiscall sub_A94320(void *this)
{
  unsigned int v1; // ecx
  unsigned int v2; // edx
  unsigned int v3; // ecx
  unsigned int v4; // edx

  v1 = __ROL4__(this, 16);
  v2 = (v1 << 8) ^ (unsigned int)&unk_FF00FF & ((v1 << 8) ^ (v1 >> 8));
  v3 = (16 * v2) ^ ((16 * v2) ^ (v2 >> 4)) & 0xF0F0F0F;
  v4 = (4 * v3) ^ ((4 * v3) ^ (v3 >> 2)) & 0x33333333;
  return (2 * v4) ^ ((2 * v4) ^ (v4 >> 1)) & 0x55555555;
}

