// Function: FFX_TK_Op_SetVisualScale
// Address: 0xa78b30
// Size: 0x40
// Prototype: double __cdecl(int, int, int)

double __cdecl FFX_TK_Op_SetVisualScale(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  float v5; // [esp+8h] [ebp-4h]

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v5 = FFX_TK_PopStackFloat(a1, a3);
  if ( ChrPointer )
    return FFX_Chr_SetVisualScale(ChrPointer, v5);
  else
    return 0.0;
}

