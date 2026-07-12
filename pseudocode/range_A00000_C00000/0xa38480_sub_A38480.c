// Function: sub_A38480
// Address: 0xa38480
// Size: 0x23
// Prototype: 

int __stdcall sub_A38480(_DWORD *a1, _DWORD *a2)
{
  int result; // eax

  *a2 = a1[3];
  a2[1] = a1[4];
  result = a1[12] & 0xFFFFFFF;
  a2[2] = result;
  return result;
}

