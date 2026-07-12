// Function: sub_A78E50
// Address: 0xa78e50
// Size: 0x32
// Prototype: 

int __cdecl sub_A78E50(int a1, int a2, int *a3)
{
  unsigned __int16 *ChrPointer; // edi
  int v4; // eax

  ChrPointer = (unsigned __int16 *)FFX_TK_GetChrPointer(a1);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  if ( ChrPointer )
    sub_8368B0(*ChrPointer, v4);
  return 0;
}

