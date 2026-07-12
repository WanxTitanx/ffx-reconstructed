// Function: sub_9A18D0
// Address: 0x9a18d0
int __userpurge sub_9A18D0@<eax>(_DWORD *a1@<ecx>, int a2@<edi>, int a3@<esi>, int a4, int a5, int a6)
{
  int v7; // eax
  int v8; // ecx
  int v9; // ecx
  int v10; // esi
  int v13; // [esp-Ch] [ebp-18h]
  int v14; // [esp-8h] [ebp-14h]
  int v15; // [esp-4h] [ebp-10h]

  if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, int, int))(*a1 + 52))(a1, a2, a3) )
    return 0;
  v7 = sub_9A0BB0(a1 + 1);
  v15 = v7;
  if ( v7 >= a1[2] )
    return 0;
  --unk_193F640;
  (*(void (__thiscall **)(_DWORD *, _DWORD, int))(*a1 + 28))(a1, *(_DWORD *)(a1[4] + 16 * v7 + 12), a6);
  v8 = a1[8];
  if ( v8 )
    (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)v8 + 8))(v8, a4, a5, a6);
  v9 = a1[3];
  v10 = v14;
  sub_979B00(v15, v9 - 1);
  --*(_DWORD *)(v10 + 4);
  return v13;
}
