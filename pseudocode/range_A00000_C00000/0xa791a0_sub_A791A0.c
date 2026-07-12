// Function: sub_A791A0
// Address: 0xa791a0
// Size: 0x35
// Prototype: 

int __cdecl sub_A791A0(int a1, int *a2)
{
  int v3; // [esp-8h] [ebp-Ch]
  int v4; // [esp-4h] [ebp-8h]

  v4 = a2[1];
  v3 = *a2;
  if ( !a2[2] )
    return sub_836AD0(v3, v4) == 0;
  a2[3] = sub_836AD0(v3, v4);
  return 5;
}

