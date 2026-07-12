// Function: sub_A28B60
// Address: 0xa28b60
// Size: 0x38

int __thiscall sub_A28B60(char *this, int a2, int a3, int a4)
{
  _BYTE v5[24]; // [esp+0h] [ebp-18h] BYREF

  IggyValuePathMakeArrayRef(v5, this + 8, a2); /*0xa28b71*/
  IggyValueGetStringUTF8RS(v5, 0, 0, a4, a3, &a2); /*0xa28b89*/
  return a2; /*0xa28b92*/
}