// Function: sub_9A2EF0
// Address: 0x9a2ef0
int __userpurge sub_9A2EF0@<eax>(int a1@<ecx>, int a2@<ebp>, _DWORD *a3, _DWORD *a4, int a5)
{
  _DWORD v7[11]; // [esp-30h] [ebp-3Ch] BYREF
  _DWORD v8[4]; // [esp-4h] [ebp-10h] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v8[1] = a2;
  v8[2] = retaddr;
  v8[0] = a5;
  v7[0] = *a3;
  v7[1] = a3[1];
  v7[2] = a3[2];
  v7[3] = a3[3];
  v7[4] = *a4;
  v7[5] = a4[1];
  v7[6] = a4[2];
  v7[7] = a4[3];
  sub_9A2090(*(_DWORD *)(a1 + 4), v7, v8);
  return sub_9A2090(*(_DWORD *)(a1 + 44), v7, v8);
}
