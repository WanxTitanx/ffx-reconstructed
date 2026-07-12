// Function: sub_A28350
// Address: 0xa28350
// Size: 0xd9
// Prototype: int(void)

char __thiscall sub_A28350(int this)
{
  int n3; // eax
  DWORD v4; // [esp+4h] [ebp-4h] BYREF

  n3 = *(_DWORD *)(this + 228);
  if ( n3 && n3 != 3 )
  {
    *(_DWORD *)(this + 228) = 3;
    *(_DWORD *)(this + 236) = 1;
    sub_A3DEA0((_DWORD *)this);
    PhyreEvent_WaitForever((HANDLE *)(this + 692));
    PhyreEvent_Close((HANDLE *)(this + 692));
    *(_BYTE *)(this + 696) = 0;
    sub_41FD10(*(_DWORD *)(this + 272));
    sub_41E5D0();
    sub_A3E150(this + 280);
    sub_A3DEA0((_DWORD *)(this + 64));
    PhyreThread_Join((HANDLE *)(this + 200), &v4);
    PhyreThread_Close();
    *(_BYTE *)(this + 204) = 0;
    sub_409370(this + 304);
    sub_40A630();
    if ( *(_DWORD *)(this + 660) )
      sub_A278F0((_DWORD *)this);
    sub_A3DF20(this);
    sub_A3DF20(this + 64);
  }
  return 1;
}

