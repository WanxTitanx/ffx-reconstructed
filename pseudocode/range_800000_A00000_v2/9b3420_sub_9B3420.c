// Function: sub_9B3420
// Address: 0x9b3420
int __thiscall sub_9B3420(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  int result; // eax

  sub_9B3AD0();
  *a2 = *(this + 64);
  a2[1] = *(this + 65);
  a2[2] = *(this + 66);
  a2[3] = *(this + 67);
  *a3 = *(this + 68);
  a3[1] = *(this + 69);
  a3[2] = *(this + 70);
  result = *(this + 71);
  a3[3] = result;
  return result;
}
