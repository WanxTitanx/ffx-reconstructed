// Function: sub_A7A000
// Address: 0xa7a000
// Size: 0x66
// Prototype: 

int __cdecl sub_A7A000(int a1, int a2, int *a3)
{
  int ChrPointer; // ebx
  float v5[4]; // [esp+Ch] [ebp-14h] BYREF

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v5[2] = FFX_TK_PopStackFloat(a1, a3);
  v5[1] = FFX_TK_PopStackFloat(a1, a3);
  v5[0] = FFX_TK_PopStackFloat(a1, a3);
  if ( ChrPointer )
    sub_835120(ChrPointer, v5);
  return 0;
}

