// Function: sub_A16FE0
// Address: 0xa16fe0
// Size: 0x53
// Prototype: 

int __stdcall sub_A16FE0(int a1, _DWORD *a2)
{
  _DWORD *v2; // edi
  int result; // eax

  v2 = (_DWORD *)sub_A08590(a1);
  sub_9FF2C0(v2);
  a2[1004] = v2[1004];
  a2[1005] = v2[1005];
  a2[1006] = v2[1006];
  result = v2[1007];
  a2[1007] = result;
  return result;
}

