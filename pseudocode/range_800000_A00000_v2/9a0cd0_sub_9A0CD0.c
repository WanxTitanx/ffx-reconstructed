// Function: sub_9A0CD0
// Address: 0x9a0cd0
int __userpurge sub_9A0CD0@<eax>(int a1@<ecx>, int a2@<ebp>, int a3, int a4)
{
  int v4; // edx
  char v5; // al
  int v6; // eax
  int v8; // [esp-20h] [ebp-2Ch] BYREF
  int v9; // [esp-1Ch] [ebp-28h]
  int v10; // [esp-18h] [ebp-24h]
  int v11; // [esp-14h] [ebp-20h]
  int v12; // [esp-4h] [ebp-10h]
  int v13; // [esp+0h] [ebp-Ch]
  void *v14; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v13 = a2;
  v14 = retaddr;
  v4 = *(_DWORD *)(a1 + 28);
  v12 = a1;
  if ( v4 )
  {
    v5 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)v4 + 4))(v4, a3, a4);
    a1 = v12;
  }
  else
  {
    v5 = (*(_WORD *)(a3 + 4) & *(_WORD *)(a4 + 6)) != 0 && (*(_WORD *)(a3 + 6) & *(_WORD *)(a4 + 4)) != 0;
  }
  if ( v5
    && (*(_DWORD *)(a3 + 12) >= *(_DWORD *)(a4 + 12) ? (v8 = a4, v9 = a3) : (v8 = a3, v9 = a4),
        v10 = 0,
        v11 = 0,
        v6 = sub_9A0BB0((int *)(a1 + 4), &v8),
        v6 < *(_DWORD *)(v12 + 8)) )
  {
    return *(_DWORD *)(v12 + 16) + 16 * v6;
  }
  else
  {
    return 0;
  }
}
