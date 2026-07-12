// Function: sub_8F9B60
// Address: 0x8f9b60
_DWORD *__cdecl sub_8F9B60(int n30, int n42, int n122, int n39, int a5, int a6)
{
  int v7; // [esp+0h] [ebp-4h]

  if ( n122 < 16 )
    n122 = 16;
  v7 = sub_8FA4F0(200) + 4;
  sub_903B70(200, n30, n42, 0, 0, a5, a5);
  sub_903B70(201, *(unsigned __int16 *)(v7 + 4) + n30, n42, n122 - *(unsigned __int16 *)(v7 + 4), 0, a5, a6);
  sub_903B70(202, n30, *(unsigned __int16 *)(v7 + 6) + n42, 0, n39 - *(unsigned __int16 *)(v7 + 6), a5, a5);
  sub_903B70(
    203,
    *(unsigned __int16 *)(v7 + 4) + n30,
    n42 + *(unsigned __int16 *)(v7 + 6),
    n122 - *(unsigned __int16 *)(v7 + 4),
    n39 - *(unsigned __int16 *)(v7 + 6),
    a5,
    a6);
  return sub_8F3A30();
}
