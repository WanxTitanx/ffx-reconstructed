// Function: sub_988720
// Address: 0x988720
int __cdecl sub_988720(int a1)
{
  int v1; // edi
  int v2; // esi

  v1 = *(_DWORD *)(a1 + 40);
  if ( !v1 )
    return 1;
  v2 = sub_988720(*(_DWORD *)(a1 + 36));
  return v2 + sub_988720(v1);
}
