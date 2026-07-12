// Function: sub_9B11A0
// Address: 0x9b11a0
int __cdecl sub_9B11A0(_DWORD *a1, int a2)
{
  int result; // eax

  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = *a1;
  result = *a1;
  if ( *a1 )
    *(_DWORD *)(result + 48) = a2;
  *a1 = a2;
  ++a1[1];
  return result;
}
