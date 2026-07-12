// Function: sub_AA3E50
// Address: 0xaa3e50
// Size: 0x52
// Prototype: 

_QWORD *__cdecl sub_AA3E50(int a1, _DWORD *a2)
{
  _QWORD *v2; // esi
  _QWORD *v3; // eax

  v2 = calloc_0(1u, 0x20u);
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  *((_DWORD *)v2 + 1) = *a2;
  *(_DWORD *)v2 = a2[2];
  *((_DWORD *)v2 + 5) = a2;
  v3 = calloc_0(2u, 4u);
  *v3 = 0;
  *((_DWORD *)v2 + 2) = v3;
  return v2;
}

