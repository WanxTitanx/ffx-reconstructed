// Function: sub_A79B30
// Address: 0xa79b30
// Size: 0x3b
// Prototype: 

int __cdecl sub_A79B30(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  float v5; // [esp+8h] [ebp-4h]

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v5 = FFX_TK_PopStackFloat(a1, a3);
  if ( ChrPointer )
    sub_832690(ChrPointer, v5);
  return 0;
}

