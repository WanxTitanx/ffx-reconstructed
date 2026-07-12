// Function: sub_99E7E0
// Address: 0x99e7e0
int __thiscall sub_99E7E0(int this, _DWORD *a2, _DWORD *a3, int a4)
{
  int result; // eax

  *(_DWORD *)(this + 16) = *a2;
  *(_DWORD *)(this + 20) = a2[1];
  *(_DWORD *)(this + 24) = a2[2];
  *(_DWORD *)(this + 28) = a2[3];
  *(_DWORD *)(this + 32) = *a3;
  *(_DWORD *)(this + 36) = a3[1];
  *(_DWORD *)(this + 40) = a3[2];
  result = a3[3];
  *(_DWORD *)(this + 44) = result;
  *(_DWORD *)(this + 48) = a4;
  *(_BYTE *)(this + 52) = 1;
  return result;
}
