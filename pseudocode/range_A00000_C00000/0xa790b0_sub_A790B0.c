// Function: sub_A790B0
// Address: 0xa790b0
// Size: 0x65
// Prototype: 

int __cdecl sub_A790B0(int a1, int a2, int *a3)
{
  int ChrPointer; // ebx
  float v5; // [esp+18h] [ebp-Ch]
  float v6; // [esp+1Ch] [ebp-8h]
  float v7; // [esp+20h] [ebp-4h]

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v7 = FFX_TK_PopStackFloat(a1, a3);
  v6 = FFX_TK_PopStackFloat(a1, a3);
  v5 = FFX_TK_PopStackFloat(a1, a3);
  if ( ChrPointer )
    sub_82B440(ChrPointer, v5, v6, v7);
  return 0;
}

