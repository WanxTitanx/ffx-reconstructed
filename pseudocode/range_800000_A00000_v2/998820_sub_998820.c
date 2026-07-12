// Function: sub_998820
// Address: 0x998820
int __thiscall sub_998820(void *this, int a2, int a3, int a4)
{
  (*(void (__thiscall **)(void *, int, int))(*(_DWORD *)this + 92))(this, a2, a3);
  return (*(int (__thiscall **)(void *, int, int))(*(_DWORD *)this + 92))(this, (a2 + 1) % 3, a4);
}
