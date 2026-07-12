// Function: sub_A17420
// Address: 0xa17420
// Size: 0x61
// Prototype: 

int __stdcall sub_A17420(int a1, int *a2)
{
  _DWORD *v2; // edi
  int v3; // ebx
  int v4; // eax
  int v5; // edx
  int result; // eax
  int v7; // [esp+14h] [ebp+8h]

  v2 = (_DWORD *)sub_A09890(a1);
  v3 = *v2 & 0x7FFFFFFF;
  v4 = sub_A033E0(v3, v2[1]);
  v5 = a2[1];
  v7 = v4;
  if ( v5 != v4 && *a2 >= 0 )
  {
    Phyre_Memory_AlignedFree(v5);
    v4 = v7;
  }
  *a2 = v3;
  a2[1] = v4;
  a2[2] = v2[2];
  result = v2[3];
  a2[3] = result;
  return result;
}

