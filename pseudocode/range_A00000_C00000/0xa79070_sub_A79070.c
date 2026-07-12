// Function: sub_A79070
// Address: 0xa79070
// Size: 0x36
// Prototype: 

int __cdecl sub_A79070(int a1, int *a2)
{
  int v3; // [esp-8h] [ebp-Ch]
  int v4; // [esp-4h] [ebp-8h]

  v4 = a2[1];
  v3 = *a2;
  if ( a2[2] )
  {
    a2[3] = sub_836AD0(v3, v4);
    return 5;
  }
  if ( !sub_836AD0(v3, v4) )
    return 5;
  return 0;
}

