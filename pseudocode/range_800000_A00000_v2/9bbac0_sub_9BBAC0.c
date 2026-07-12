// Function: sub_9BBAC0
// Address: 0x9bbac0
int __thiscall sub_9BBAC0(void *this, int a2)
{
  if ( (*(_BYTE *)(a2 + 244) & 2) != 0 )
    return (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 80))(this, a2);
  else
    return sub_985860((int)this, a2);
}
