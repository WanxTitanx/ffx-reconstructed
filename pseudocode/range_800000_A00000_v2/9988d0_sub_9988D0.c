// Function: sub_9988D0
// Address: 0x9988d0
int __thiscall sub_9988D0(int this, int a2, int a3, _DWORD *a4)
{
  int result; // eax

  sub_997B00((float *)this, a3);
  *a4 = *(_DWORD *)(this + 64);
  a4[1] = *(_DWORD *)(this + 68);
  a4[2] = *(_DWORD *)(this + 72);
  result = *(_DWORD *)(this + 76);
  a4[3] = result;
  return result;
}
