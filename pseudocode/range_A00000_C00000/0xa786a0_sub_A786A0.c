// Function: sub_A786A0
// Address: 0xa786a0
// Size: 0x3e

int __cdecl sub_A786A0(int a1, int a2, int *a3)
{
  __int16 v3; // bx
  int v4; // eax
  int ActorByIndex; // eax
  int ChrPointer; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3); /*0xa786b2*/
  v4 = FFX_FieldVM_PopOperand(a1, a3); /*0xa786b7*/
  ActorByIndex = FFX_Field_GetActorByIndex(v4); /*0xa786bd*/
  ChrPointer = FFX_TK_GetChrPointer(ActorByIndex); /*0xa786c3*/
  if ( ChrPointer ) /*0xa786cd*/
    sub_82B400(ChrPointer, v3); /*0xa786d1*/
  return 0; /*0xa786db*/
}