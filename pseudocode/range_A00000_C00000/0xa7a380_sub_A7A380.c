// Function: sub_A7A380
// Address: 0xa7a380
// Size: 0x45
// Prototype: 

int __cdecl sub_A7A380(int a1, int a2, int *a3)
{
  int v3; // esi
  int ChrPointer; // eax
  float v6; // [esp+Ch] [ebp-4h]

  v6 = FFX_TK_PopStackFloat(a1, a3);
  v3 = FFX_FieldVM_PopOperand(a1, a3);
  ChrPointer = FFX_TK_GetChrPointer(a1);
  if ( ChrPointer )
    sub_82AEB0(ChrPointer, v3, v6);
  return 0;
}

