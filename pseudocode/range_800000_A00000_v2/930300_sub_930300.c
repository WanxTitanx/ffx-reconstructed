// Function: sub_930300
// Address: 0x930300
int __cdecl sub_930300(int a1)
{
  int v1; // esi
  int v2; // edi
  int result; // eax
  int v4; // [esp-4h] [ebp-Ch]

  v1 = a1;
  v2 = a1;
  if ( a1 )
  {
    do
    {
      result = sub_92ED90(v2);
      v2 = *(_DWORD *)(v2 + 8);
    }
    while ( v2 );
    do
    {
      if ( (*(_BYTE *)v1 & 4) != 0 )
      {
        v4 = v1;
        v1 = *(_DWORD *)(v1 + 8);
        result = sub_92ED50(v4);
      }
      else
      {
        v1 = *(_DWORD *)(v1 + 8);
      }
    }
    while ( v1 );
  }
  return result;
}
