// Function: sub_A78A80
// Address: 0xa78a80
// Size: 0x32
// Prototype: 

int __cdecl sub_A78A80(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  unsigned __int8 v4; // al

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  if ( ChrPointer )
    return FFX_BtlMenu_ResetActorModelCommandState(ChrPointer, v4);
  else
    return 0;
}

