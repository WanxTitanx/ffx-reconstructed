// Function: sub_A7A340
// Address: 0xa7a340
// Size: 0x40
// Prototype: 

double __cdecl sub_A7A340(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  float v5; // [esp+8h] [ebp-4h]

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v5 = FFX_TK_PopStackFloat(a1, a3);
  if ( !ChrPointer )
    return 0.0;
  sub_82B900(ChrPointer, v5);
  return v5;
}

