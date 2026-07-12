// Function: sub_A7A640
// Address: 0xa7a640
// Size: 0x37
// Prototype: 

int __cdecl sub_A7A640(int a1, int a2, int *a3)
{
  int ChrPointer; // eax
  float v5; // [esp+4h] [ebp-4h]

  v5 = FFX_TK_PopStackFloat(a1, a3);
  ChrPointer = FFX_TK_GetChrPointer(a1);
  if ( ChrPointer )
    sub_830D30(ChrPointer, v5);
  return 0;
}

