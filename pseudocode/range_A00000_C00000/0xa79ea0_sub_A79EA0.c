// Function: sub_A79EA0
// Address: 0xa79ea0
// Size: 0x4d
// Prototype: 

int __cdecl sub_A79EA0(int a1, int a2, int *a3)
{
  int ChrPointer; // ebx
  float v5; // [esp+10h] [ebp-8h]
  int v6; // [esp+14h] [ebp-4h]

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v6 = FFX_FieldVM_PopOperand(a1, a3);
  v5 = FFX_TK_PopStackFloat(a1, a3);
  if ( ChrPointer )
    FFX_BtlChr_SetHPValueFloatTransition(ChrPointer, v5, v6);
  return 0;
}

