// Function: sub_984040
// Address: 0x984040
char __userpurge sub_984040@<al>(_DWORD *a1@<ecx>, int a2@<ebp>, int *a3)
{
  int v4; // esi
  int v5; // esi
  void (__thiscall **v6)(_DWORD *, _DWORD); // edx
  int v8; // [esp-40h] [ebp-110h]
  int v9; // [esp-38h] [ebp-108h]
  _DWORD *v10; // [esp-24h] [ebp-F4h]
  int v11; // [esp-20h] [ebp-F0h]
  _DWORD v12[55]; // [esp-1Ch] [ebp-ECh] BYREF
  int v13; // [esp+C0h] [ebp-10h]
  int v14; // [esp+C4h] [ebp-Ch]
  void *v15; // [esp+C8h] [ebp-8h]
  int v16; // [esp+CCh] [ebp-4h] BYREF
  void *retaddr; // [esp+D0h] [ebp+0h]

  v14 = a2;
  v15 = retaddr;
  v13 = -1;
  v12[54] = &loc_AD8BAB;
  v12[53] = NtCurrentTeb()->NtTib.ExceptionList;
  v12[52] = &v16;
  v11 = *a3;
  v4 = *a3;
  if ( *a3 != a1[1] )
  {
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a1[3] + 4))(a1[3], *(_DWORD *)(v11 + 200)) )
    {
      v10 = (_DWORD *)(*(int (__thiscall **)(_DWORD, _DWORD, int, _DWORD))(**(_DWORD **)(a1[2] + 24) + 4))(
                        *(_DWORD *)(a1[2] + 24),
                        a1[1],
                        v4,
                        0);
      if ( v10 )
      {
        v5 = a1[3];
        sub_9A4C60(a1[1], v11);
        v12[0] = &btBridgedManifoldResult::`vftable';
        v12[44] = v5;
        v6 = (void (__thiscall **)(_DWORD *, _DWORD))*v10;
        v9 = a1[2] + 28;
        v8 = a1[1];
        v13 = 0;
        ((void (__thiscall *)(_DWORD *, int, int, int, _DWORD *))v6[1])(v10, v8, v11, v9, v12);
        (*(void (__thiscall **)(_DWORD *, _DWORD))*v10)(v10, 0);
        (*(void (__thiscall **)(_DWORD, _DWORD *))(**(_DWORD **)(a1[2] + 24) + 48))(*(_DWORD *)(a1[2] + 24), v10);
      }
    }
  }
  return 1;
}
