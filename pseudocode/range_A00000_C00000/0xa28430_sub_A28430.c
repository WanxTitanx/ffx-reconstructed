// Function: sub_A28430
// Address: 0xa28430
// Size: 0x5b

int __thiscall sub_A28430(int this)
{
  int result; // eax
  DWORD v3; // [esp+8h] [ebp-4h] BYREF

  sub_A28350(this); /*0xa28438*/
  *(_DWORD *)(this + 208) = 1; /*0xa2843d*/
  PhyreEvent_Set((HANDLE *)(this + 684)); /*0xa2844d*/
  PhyreThread_Join((HANDLE *)(this + 192), &v3); /*0xa2845c*/
  PhyreThread_Close(); /*0xa28467*/
  *(_BYTE *)(this + 196) = 0; /*0xa28472*/
  result = PhyreEvent_Close((HANDLE *)(this + 684)); /*0xa28479*/
  *(_BYTE *)(this + 688) = 0; /*0xa2847f*/
  return result; /*0xa2847e*/
}