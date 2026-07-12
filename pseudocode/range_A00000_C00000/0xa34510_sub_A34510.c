// Function: sub_A34510
// Address: 0xa34510
// Size: 0x4f
// Prototype: 

int __stdcall sub_A34510(int a1, int *a2)
{
  int v2; // eax
  int v3; // edi
  _DWORD *v4; // ebx
  int result; // eax

  v2 = sub_A338A0(a1);
  v3 = *(_DWORD *)v2 & 0x7FFFFFFF;
  v4 = sub_A33480(v3, *(_DWORD **)(v2 + 4));
  result = a2[1];
  if ( (_DWORD *)result != v4 && *a2 >= 0 )
    result = Phyre_Memory_AlignedFree(a2[1]);
  *a2 = v3;
  a2[1] = (int)v4;
  return result;
}

