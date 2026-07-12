// Function: sub_98B720
// Address: 0x98b720
// bad sp value at call has been detected, the output may be wrong!
void __userpurge sub_98B720(int a1@<ecx>, int a2@<ebp>, int a3, _DWORD *a4, _DWORD *a5)
{
  int v5; // eax
  int *v6; // ecx
  int v7; // eax
  _DWORD v8[15]; // [esp-40h] [ebp-4Ch] BYREF
  int v9; // [esp-4h] [ebp-10h]
  int v10; // [esp+0h] [ebp-Ch]
  void *v11; // [esp+4h] [ebp-8h]
  int v12; // [esp+8h] [ebp-4h] BYREF
  void *retaddr; // [esp+Ch] [ebp+0h]

  v10 = a2;
  v11 = retaddr;
  v9 = -1;
  v8[14] = &loc_AD8F38;
  v8[13] = NtCurrentTeb()->NtTib.ExceptionList;
  v8[12] = &v12;
  v8[1] = a3;
  v8[4] = *a4;
  v8[5] = a4[1];
  v8[6] = a4[2];
  v8[7] = a4[3];
  v8[8] = *a5;
  v8[9] = a5[1];
  v8[10] = a5[2];
  v5 = a5[3];
  v8[0] = &`btTriangleMeshShape::processAllTriangles'::`2'::FilteredCallback::`vftable';
  v8[11] = v5;
  v6 = *(int **)(a1 + 48);
  v7 = *v6;
  v9 = 0;
  (*(void (__thiscall **)(int *, _DWORD *, _DWORD *, _DWORD *))(v7 + 4))(v6, v8, a4, a5);
  v9 = -1;
  sub_98ACA0(v8);
}
