// Function: sub_989750
// Address: 0x989750
int __thiscall sub_989750(int *this, _DWORD *dst)
{
  int result; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  sub_989780((int)&savedregs, this, dst);
  result = sub_9D4D50(*(this + 1));
  --*(this + 3);
  *(this + 1) = (int)dst;
  return result;
}
