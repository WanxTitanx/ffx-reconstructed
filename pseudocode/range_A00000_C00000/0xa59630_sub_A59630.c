// Function: sub_A59630
// Address: 0xa59630
// Size: 0x45
// Prototype: _DWORD __cdecl(int ItemCount, int, int, char)

int __cdecl sub_A59630(int ItemCount, int a2, int a3, char a4)
{
  float v5; // [esp+4h] [ebp-10h]
  float v6; // [esp+24h] [ebp+10h]
  float v7; // [esp+24h] [ebp+10h]

  v6 = (float)a3;
  v5 = v6;
  v7 = (float)a2;
  return sub_905660(ItemCount, v7, v5, a4, 0.80000001, 0.5);
}

