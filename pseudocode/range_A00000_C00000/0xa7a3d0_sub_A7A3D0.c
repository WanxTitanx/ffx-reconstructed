// Function: sub_A7A3D0
// Address: 0xa7a3d0
// Size: 0x40
// Prototype: 

double __cdecl sub_A7A3D0(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  float v5; // [esp+8h] [ebp-4h]

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v5 = FFX_TK_PopStackFloat(a1, a3);
  if ( !ChrPointer )
    return 0.0;
  sub_82B1D0(ChrPointer, v5);
  return v5;
}

