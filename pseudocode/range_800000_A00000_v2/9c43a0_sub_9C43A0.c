// Function: sub_9C43A0
// Address: 0x9c43a0
int __userpurge sub_9C43A0@<eax>(int a1@<ecx>, int a2@<ebp>, _DWORD *a3)
{
  _DWORD *v4; // eax
  int result; // eax
  _DWORD v6[7]; // [esp-10h] [ebp-1Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v6[4] = a2;
  v6[5] = retaddr;
  *(_BYTE *)(a1 + 195) = 1;
  *(_DWORD *)(a1 + 64) = *a3;
  *(_DWORD *)(a1 + 68) = a3[1];
  *(_DWORD *)(a1 + 72) = a3[2];
  *(_DWORD *)(a1 + 76) = a3[3];
  v4 = (_DWORD *)sub_9C3410((int)v6, (float *)(a1 + 64));
  *(_DWORD *)(a1 + 80) = *v4;
  *(_DWORD *)(a1 + 84) = v4[1];
  *(_DWORD *)(a1 + 88) = v4[2];
  result = v4[3];
  *(_DWORD *)(a1 + 92) = result;
  return result;
}
