// Function: sub_930430
// Address: 0x930430
int __cdecl sub_930430(int a1)
{
  int result; // eax

  result = sub_787900(*(_DWORD *)(a1 + 16 * *(_DWORD *)(a1 + 172) + 44));
  if ( result == -1 )
    return sub_92EE00(a1);
  return result;
}
