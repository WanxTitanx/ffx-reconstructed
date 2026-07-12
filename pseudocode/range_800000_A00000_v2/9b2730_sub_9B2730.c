// Function: sub_9B2730
// Address: 0x9b2730
int __cdecl sub_9B2730(_DWORD *a1, int a2)
{
  int v2; // ecx
  int result; // eax
  int v4; // ecx

  v2 = *(_DWORD *)(a2 + 52);
  if ( v2 )
  {
    result = *(_DWORD *)(a2 + 48);
    *(_DWORD *)(v2 + 48) = result;
  }
  v4 = *(_DWORD *)(a2 + 48);
  if ( v4 )
  {
    result = *(_DWORD *)(a2 + 52);
    *(_DWORD *)(v4 + 52) = result;
  }
  if ( a2 == *a1 )
  {
    result = *(_DWORD *)(a2 + 52);
    *a1 = result;
  }
  --a1[1];
  return result;
}
