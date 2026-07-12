// Function: sub_A83630
// Address: 0xa83630
// Size: 0x61
// Prototype: 

int __cdecl sub_A83630(_QWORD *a1, int a2, _QWORD *a3, int a4)
{
  __int64 v5; // mm1
  __int64 v6; // mm2
  _QWORD *v7; // esi
  _QWORD *v8; // edi
  __int64 v9; // mm4
  __int64 v10; // mm5
  char *v11; // esi
  char *v12; // edi
  __int64 v13; // mm1

  v5 = *(_QWORD *)((char *)a1 + a2);
  v6 = *(_QWORD *)((char *)a1 + 2 * a2);
  *a3 = *a1;
  v7 = (_QWORD *)((char *)a1 + 2 * a2 + a2);
  *(_QWORD *)((char *)a3 + a4) = v5;
  *(_QWORD *)((char *)a3 + 2 * a4) = v6;
  v8 = (_QWORD *)((char *)a3 + 2 * a4 + a4);
  v9 = *(_QWORD *)((char *)v7 + a2);
  v10 = *(_QWORD *)((char *)v7 + 2 * a2);
  *v8 = *v7;
  v11 = (char *)v7 + 2 * a2;
  *(_QWORD *)((char *)v8 + a4) = v9;
  *(_QWORD *)((char *)v8 + 2 * a4) = v10;
  v12 = (char *)v8 + 2 * a4;
  v13 = *(_QWORD *)&v11[2 * a2];
  *(_QWORD *)&v12[a4] = *(_QWORD *)&v11[a2];
  *(_QWORD *)&v12[2 * a4] = v13;
  return a2;
}

