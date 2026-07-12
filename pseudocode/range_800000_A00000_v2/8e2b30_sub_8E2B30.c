// Function: sub_8E2B30
// Address: 0x8e2b30
int __cdecl sub_8E2B30(int a1)
{
  int v1; // eax
  bool v2; // sf
  int n128; // eax

  v1 = *(_DWORD *)(a1 + 104);
  v2 = v1 + *(_DWORD *)(a1 + 100) < 0;
  *(_DWORD *)(a1 + 100) += v1;
  n128 = v2 ? 0 : *(_DWORD *)(a1 + 100);
  *(_DWORD *)(a1 + 100) = n128;
  if ( n128 > 128 )
    *(_DWORD *)(a1 + 100) = 128;
  return n128;
}
