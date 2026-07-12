// Function: sub_A77A10
// Address: 0xa77a10
// Size: 0x53
// Prototype: 

int __cdecl sub_A77A10(int a1, int a2, int *a3)
{
  float v4; // [esp+14h] [ebp-Ch]
  float v5; // [esp+18h] [ebp-8h]
  float v6; // [esp+1Ch] [ebp-4h]

  v6 = FFX_TK_PopStackFloat(a1, a3);
  v5 = FFX_TK_PopStackFloat(a1, a3);
  v4 = FFX_TK_PopStackFloat(a1, a3);
  sub_824EC0(v4, v5, v6);
  return 0;
}

