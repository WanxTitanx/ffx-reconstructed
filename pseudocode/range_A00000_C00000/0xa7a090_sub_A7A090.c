// Function: sub_A7A090
// Address: 0xa7a090
// Size: 0x85
// Prototype: 

int __cdecl sub_A7A090(int a1, int a2, int *a3)
{
  int ChrPointer; // ebx
  float v5; // [esp+10h] [ebp-8h]
  float v6; // [esp+10h] [ebp-8h]
  float v7; // [esp+14h] [ebp-4h]
  float v8; // [esp+14h] [ebp-4h]

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v7 = FFX_TK_PopStackFloat(a1, a3);
  v5 = FFX_TK_PopStackFloat(a1, a3);
  if ( ChrPointer )
  {
    v8 = v7 * 3.141592025756836 / 180.0;
    sub_A7AE20(v8);
    v6 = v5 * 3.141592025756836 / 180.0;
    sub_A7AE20(v6);
    sub_835070(ChrPointer, v6, v8);
  }
  return 0;
}

