// Function: sub_A8B410
// Address: 0xa8b410
// Size: 0x35
// Prototype: 

_QWORD *__cdecl sub_A8B410(__int64 *a1, int a2, __int64 *a3)
{
  __int64 v3; // mm1
  int v4; // ecx
  _QWORD *result; // eax

  v3 = *a3;
  v4 = 3 * a2;
  *a1 = *a3;
  *(__int64 *)((char *)a1 + a2) = v3;
  *(__int64 *)((char *)a1 + 2 * a2) = v3;
  *(__int64 *)((char *)a1 + v4) = v3;
  result = (__int64 *)((char *)a1 + 4 * a2);
  *result = v3;
  *(_QWORD *)((char *)result + a2) = v3;
  *(_QWORD *)((char *)result + 2 * a2) = v3;
  *(_QWORD *)((char *)result + v4) = v3;
  return result;
}

