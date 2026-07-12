// Function: sub_A78FB0
// Address: 0xa78fb0
// Size: 0x72
// Prototype: 

int __cdecl sub_A78FB0(int a1, int a2, int *a3)
{
  int ChrPointer; // ebx
  float v5; // [esp+1Ch] [ebp-10h]
  float v6; // [esp+20h] [ebp-Ch]
  float v7; // [esp+24h] [ebp-8h]
  int v8; // [esp+28h] [ebp-4h]

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v8 = FFX_FieldVM_PopOperand(a1, a3);
  v7 = FFX_TK_PopStackFloat(a1, a3);
  v6 = FFX_TK_PopStackFloat(a1, a3);
  v5 = FFX_TK_PopStackFloat(a1, a3);
  if ( ChrPointer )
    sub_82B650(ChrPointer, v5, v6, v7, v8);
  return 0;
}

