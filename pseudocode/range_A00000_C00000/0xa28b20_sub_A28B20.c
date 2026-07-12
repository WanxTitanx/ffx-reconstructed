// Function: sub_A28B20
// Address: 0xa28b20
// Size: 0x32

int __thiscall sub_A28B20(char *this, int a2)
{
  _BYTE v3[24]; // [esp+0h] [ebp-18h] BYREF

  IggyValuePathMakeArrayRef(v3, this + 8, a2); /*0xa28b31*/
  IggyValueGetS32RS(v3, 0, 0, &a2); /*0xa28b43*/
  return a2; /*0xa28b4c*/
}