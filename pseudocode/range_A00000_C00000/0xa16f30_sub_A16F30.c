// Function: sub_A16F30
// Address: 0xa16f30
// Size: 0x4f
// Prototype: 

int __stdcall sub_A16F30(int a1, int *a2)
{
  _DWORD *v2; // eax
  int v3; // edi
  int v4; // ebx
  int result; // eax

  v2 = (_DWORD *)sub_A081B0(a1);
  v3 = *v2 & 0x7FFFFFFF;
  v4 = sub_A033E0(v3, v2[1]);
  result = a2[1];
  if ( result != v4 && *a2 >= 0 )
    result = Phyre_Memory_AlignedFree(a2[1]);
  *a2 = v3;
  a2[1] = v4;
  return result;
}

