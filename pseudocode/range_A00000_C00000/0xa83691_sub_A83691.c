// Function: sub_A83691
// Address: 0xa83691
// Size: 0x39
// Prototype: 

int __cdecl sub_A83691(_QWORD *a1, int a2, _QWORD *a3, int a4)
{
  __int64 v5; // mm1
  __int64 v6; // mm2

  v5 = *(_QWORD *)((char *)a1 + a2);
  v6 = *(_QWORD *)((char *)a1 + 2 * a2);
  *a3 = *a1;
  *(_QWORD *)((char *)a3 + a4) = v5;
  *(_QWORD *)((char *)a3 + 2 * a4) = v6;
  *(_QWORD *)((char *)a3 + 2 * a4 + a4) = *(_QWORD *)((char *)a1 + 2 * a2 + a2);
  return a2;
}

