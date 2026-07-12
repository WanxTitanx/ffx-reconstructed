// Function: sub_9C4320
// Address: 0x9c4320
int __userpurge sub_9C4320@<eax>(int a1@<ecx>, int a2@<ebp>, _DWORD *a3, int a4)
{
  _DWORD *v5; // eax
  int result; // eax
  _DWORD v7[7]; // [esp-10h] [ebp-1Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v7[4] = a2;
  v7[5] = retaddr;
  *(_BYTE *)(a1 + 195) = 0;
  *(_DWORD *)(a1 + 64) = *a3;
  *(_DWORD *)(a1 + 68) = a3[1];
  *(_DWORD *)(a1 + 72) = a3[2];
  *(_DWORD *)(a1 + 76) = a3[3];
  v5 = (_DWORD *)sub_9C3410((int)v7, (float *)(a1 + 64));
  *(_DWORD *)(a1 + 80) = *v5;
  *(_DWORD *)(a1 + 84) = v5[1];
  *(_DWORD *)(a1 + 88) = v5[2];
  result = v5[3];
  *(_DWORD *)(a1 + 92) = result;
  *(_DWORD *)(a1 + 196) = a4;
  return result;
}
