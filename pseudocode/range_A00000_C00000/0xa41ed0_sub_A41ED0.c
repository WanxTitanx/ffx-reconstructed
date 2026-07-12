// Function: sub_A41ED0
// Address: 0xa41ed0
// Size: 0x60
// Prototype: 

char __thiscall sub_A41ED0(int *this, int a2)
{
  int v3; // eax
  _DWORD v5[5]; // [esp+8h] [ebp-14h] BYREF

  v5[1] = sub_59E6C0();
  v5[0] = &Phyre::PInternal::PDeleteChildrenVisitor::`vftable';
  v3 = *this;
  v5[4] = 0;
  (*(void (__thiscall **)(int *, int, _DWORD *))(v3 + 60))(this, a2, v5);
  return 1;
}

