// Function: sub_A79290
// Address: 0xa79290
// Size: 0x32

int __cdecl sub_A79290(int a1, int *a2)
{
  int v3; // [esp-4h] [ebp-8h]

  v3 = *a2; /*0xa7929b*/
  if ( !a2[2] ) /*0xa79297*/
    return sub_82A0C0(v3) == 0; /*0xa792be*/
  a2[3] = sub_82A0C0(v3); /*0xa792a7*/
  return 5; /*0xa792af*/
}