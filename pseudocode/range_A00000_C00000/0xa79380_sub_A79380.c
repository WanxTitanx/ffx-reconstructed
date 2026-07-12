// Function: sub_A79380
// Address: 0xa79380
// Size: 0x32
// Prototype: 

int __cdecl sub_A79380(int a1, int *a2)
{
  int v3; // [esp-4h] [ebp-8h]

  v3 = *a2;
  if ( !a2[2] )
    return sub_82A0C0(v3) == 0;
  a2[3] = sub_82A0C0(v3);
  return 5;
}

