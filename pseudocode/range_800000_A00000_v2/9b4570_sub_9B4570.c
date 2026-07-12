// Function: sub_9B4570
// Address: 0x9b4570
int __userpurge sub_9B4570@<eax>(int a1@<ecx>, int a2@<ebp>, int a3@<edi>, float a4, int a5, int a6, int a7)
{
  _DWORD v9[47]; // [esp+24h] [ebp-CCh] BYREF
  int v10; // [esp+E0h] [ebp-10h]
  int v11; // [esp+E4h] [ebp-Ch]
  void *v12; // [esp+E8h] [ebp-8h]
  int v13; // [esp+ECh] [ebp-4h] BYREF
  void *retaddr; // [esp+F0h] [ebp+0h]

  v11 = a2;
  v12 = retaddr;
  v10 = -1;
  v9[46] = &loc_AD9C2C;
  v9[45] = NtCurrentTeb()->NtTib.ExceptionList;
  v9[44] = &v13;
  sub_979F40();
  *(_DWORD *)a1 = &btRigidBody::`vftable';
  v10 = 0;
  *(_BYTE *)(a1 + 520) = 1;
  *(_DWORD *)(a1 + 516) = 0;
  *(_DWORD *)(a1 + 508) = 0;
  *(_DWORD *)(a1 + 512) = 0;
  LOBYTE(v10) = 1;
  sub_5E1260(a4, a5, a6, a7);
  sub_9B5EC0(a1, a3, a1, (int)v9);
  return a1;
}
