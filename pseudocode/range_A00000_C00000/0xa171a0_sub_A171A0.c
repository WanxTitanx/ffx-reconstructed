// Function: sub_A171A0
// Address: 0xa171a0
// Size: 0x5f
// Prototype: 

int __stdcall sub_A171A0(int a1, _DWORD *a2)
{
  _DWORD *v2; // edi
  int result; // eax

  v2 = (_DWORD *)sub_A08E50(a1);
  sub_9FFD70(v2);
  a2[30] = v2[30];
  a2[31] = v2[31];
  a2[32] = v2[32];
  a2[33] = v2[33];
  a2[34] = v2[34];
  result = v2[35];
  a2[35] = result;
  return result;
}

