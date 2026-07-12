// Function: sub_A34560
// Address: 0xa34560
// Size: 0x5b
// Prototype: 

int __stdcall sub_A34560(int a1, int *a2)
{
  int v2; // ebx
  int v3; // edi
  _DWORD *v4; // eax
  int v5; // edx
  int result; // eax
  _DWORD *v7; // [esp+14h] [ebp+8h]

  v2 = sub_A339E0(a1);
  v3 = *(_DWORD *)v2 & 0x7FFFFFFF;
  v4 = sub_A33480(v3, *(_DWORD **)(v2 + 4));
  v5 = a2[1];
  v7 = v4;
  if ( (_DWORD *)v5 != v4 && *a2 >= 0 )
  {
    Phyre_Memory_AlignedFree(v5);
    v4 = v7;
  }
  *a2 = v3;
  a2[1] = (int)v4;
  result = *(_DWORD *)(v2 + 8);
  a2[2] = result;
  return result;
}

