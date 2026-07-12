// Function: sub_81C370
// Address: 0x81c370
int __cdecl sub_81C370(int a1, int a2)
{
  int v2; // edx
  __int16 v3; // si
  int result; // eax

  v2 = *(_DWORD *)(a1 + 544);
  v3 = *(_WORD *)(a2 + 2);
  result = a2 + 4;
  if ( (*(_WORD *)(a1 + 538) & 0x1000) != 0 )
    *(_WORD *)(v2 + 196) = v3;
  else
    *(_WORD *)(v2 + 198) = v3;
  return result;
}
