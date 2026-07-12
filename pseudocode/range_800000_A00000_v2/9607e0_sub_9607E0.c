// Function: sub_9607E0
// Address: 0x9607e0
int __cdecl sub_9607E0(int a1)
{
  int v1; // esi
  int result; // eax

  v1 = sub_94C920(a1, 2);
  sub_94CB30(a1, 1, 6);
  result = sub_94B180(a1, 1, v1);
  if ( result )
  {
    sub_94B770(a1, result);
    sub_94B250(a1, -2);
    return 2;
  }
  return result;
}
