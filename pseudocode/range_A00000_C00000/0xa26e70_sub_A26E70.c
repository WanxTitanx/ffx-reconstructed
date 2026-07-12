// Function: sub_A26E70
// Address: 0xa26e70
// Size: 0xbb
// Prototype: 

int __thiscall sub_A26E70(int this)
{
  ((void (*)(void))sub_A3DD20)();
  sub_A3DD20(this + 64);
  sub_A3DD20(this + 128);
  unknown_libname_27(this + 192);
  *(_BYTE *)(this + 196) = 0;
  unknown_libname_27(this + 200);
  *(_BYTE *)(this + 204) = 0;
  sub_A3E030(this + 280);
  Phyre_ZeroDword((_DWORD *)(this + 684));
  *(_BYTE *)(this + 688) = 0;
  Phyre_ZeroDword((_DWORD *)(this + 692));
  *(_BYTE *)(this + 696) = 0;
  return this;
}

