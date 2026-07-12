// Function: sub_A3D9B0
// Address: 0xa3d9b0
// Size: 0x3a
// Prototype: 

int __thiscall sub_A3D9B0(void *this, int a2)
{
  int result; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // [esp+4h] [ebp-4h] BYREF

  v5 = 0;
  result = sub_5B5AE0(sub_A3D6D0, 8, &v5);
  if ( !result )
  {
    v4 = v5;
    *v5 = this;
    v4[1] = sub_A3D9F0;
    return 0;
  }
  return result;
}

