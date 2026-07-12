// Function: sub_A8B2E0
// Address: 0xa8b2e0
// Size: 0x36
// Prototype: 

_QWORD *__cdecl sub_A8B2E0(_QWORD *a1, int a2)
{
  int v2; // ecx
  _QWORD *result; // eax

  v2 = 3 * a2;
  *a1 = 0x8080808080808080uLL;
  *(_QWORD *)((char *)a1 + a2) = 0x8080808080808080uLL;
  *(_QWORD *)((char *)a1 + 2 * a2) = 0x8080808080808080uLL;
  *(_QWORD *)((char *)a1 + v2) = 0x8080808080808080uLL;
  result = (_QWORD *)((char *)a1 + 4 * a2);
  *result = 0x8080808080808080uLL;
  *(_QWORD *)((char *)result + a2) = 0x8080808080808080uLL;
  *(_QWORD *)((char *)result + 2 * a2) = 0x8080808080808080uLL;
  *(_QWORD *)((char *)result + v2) = 0x8080808080808080uLL;
  return result;
}

