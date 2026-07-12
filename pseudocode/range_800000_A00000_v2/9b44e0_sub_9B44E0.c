// Function: sub_9B44E0
// Address: 0x9b44e0
int __userpurge sub_9B44E0@<eax>(int a1@<ecx>, int a2@<edi>, int a3)
{
  sub_979F40();
  *(_DWORD *)a1 = &btRigidBody::`vftable';
  *(_BYTE *)(a1 + 520) = 1;
  *(_DWORD *)(a1 + 516) = 0;
  *(_DWORD *)(a1 + 508) = 0;
  *(_DWORD *)(a1 + 512) = 0;
  sub_9B5EC0(a1, a2, a1, a3);
  return a1;
}
