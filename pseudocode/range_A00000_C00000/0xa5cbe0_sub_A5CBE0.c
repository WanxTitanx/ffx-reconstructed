// Function: sub_A5CBE0
// Address: 0xa5cbe0
// Size: 0x8f
// Prototype: 

int __cdecl sub_A5CBE0(int a1, int a2, int n4)
{
  float v4; // [esp+0h] [ebp-30h]
  float v5[5]; // [esp+4h] [ebp-2Ch]
  float v6[5]; // [esp+18h] [ebp-18h]

  v6[0] = 1.0;
  v6[1] = 1.0;
  v6[2] = 1.5;
  v6[3] = 3.0;
  v6[4] = 5.0;
  v5[4] = 5.0;
  v5[0] = 1.0;
  v5[1] = 1.0;
  v5[2] = 1.5;
  v5[3] = 3.0;
  if ( n4 == 4 )
    return 100000;
  v4 = (float)(a1 + 50);
  return (int)(v6[a2] * v4 * v5[n4]);
}

