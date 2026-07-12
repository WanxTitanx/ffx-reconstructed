// Function: sub_A60EF0
// Address: 0xa60ef0
// Size: 0x17
// Prototype: int __cdecl(int, float)

int __cdecl sub_A60EF0(int a1, float a2)
{
  *((float *)&unk_12A14D0 + 96 * a1) = a2; /*0xa60eff*/
  return 384 * a1; /*0xa60f05*/
}