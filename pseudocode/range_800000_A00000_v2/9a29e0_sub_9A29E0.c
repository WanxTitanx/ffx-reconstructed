// Function: sub_9A29E0
// Address: 0x9a29e0
char *__thiscall sub_9A29E0(char *this, void *a2)
{
  void *v3; // ecx
  void *v4; // eax
  void *v5; // eax

  *(_DWORD *)this = &btDbvtBroadphase::`vftable';
  `eh vector constructor iterator'(
    this + 4,
    0x28u,
    2,
    (void (__thiscall *)(void *))sub_987770,
    (void (__thiscall *)(void *))sub_987900);
  v3 = a2;
  *(_WORD *)(this + 153) = 256;
  *(this + 152) = a2 == 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 31) = 0;
  *((_DWORD *)this + 27) = 1;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 29) = 10;
  *((_DWORD *)this + 30) = 1;
  *((_DWORD *)this + 32) = 0;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 34) = 0;
  if ( !a2 )
  {
    v4 = (void *)sub_9D4CE0(76, 16);
    if ( v4 )
      v5 = sub_9A01E0(v4);
    else
      v5 = 0;
    v3 = v5;
  }
  *((_DWORD *)this + 24) = v3;
  *((_DWORD *)this + 37) = 0;
  *((_DWORD *)this + 35) = 0;
  *((_DWORD *)this + 36) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  return this;
}
