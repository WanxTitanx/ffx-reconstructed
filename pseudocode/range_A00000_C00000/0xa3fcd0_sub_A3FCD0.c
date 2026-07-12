// Function: sub_A3FCD0
// Address: 0xa3fcd0
// Size: 0x24
// Prototype: 

void __thiscall sub_A3FCD0(void **this)
{
  _BYTE v2[4]; // [esp+4h] [ebp-4h] BYREF

  sub_A41F50(v2, *(_DWORD *)*this, *this);
  FFX_Memory_Free(*this);
}

