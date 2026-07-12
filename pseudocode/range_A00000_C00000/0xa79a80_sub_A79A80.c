// Function: sub_A79A80
// Address: 0xa79a80
// Size: 0x6d
// Prototype: 

int __cdecl sub_A79A80(int a1, int a2, int *a3)
{
  int ChrPointer; // ebx
  float v5; // [esp+10h] [ebp-8h]
  float v6; // [esp+10h] [ebp-8h]
  float v7; // [esp+14h] [ebp-4h]

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v7 = FFX_TK_PopStackFloat(a1, a3);
  v5 = FFX_TK_PopStackFloat(a1, a3);
  if ( ChrPointer )
  {
    v6 = v5 * 3.141592025756836 / 180.0;
    sub_A7AE20(v6);
    sub_835870(ChrPointer, v6, v7);
  }
  return 0;
}

