// Function: sub_9323B0
// Address: 0x9323b0
int sub_9323B0()
{
  int i; // esi
  int v1; // eax
  int j; // esi
  int result; // eax

  for ( i = 20; i <= 27; ++i )
  {
    v1 = sub_795090(i);
    if ( v1 )
    {
      ++*(_DWORD *)(unk_193C0F0 + 2088);
      *(_DWORD *)(unk_193C0F0 + 4 * *(_DWORD *)(unk_193C0F0 + 2084) + 2096) = i;
      *(_DWORD *)(unk_193C0F0 + 4 * (*(_DWORD *)(unk_193C0F0 + 2084))++ + 2160) = v1;
    }
  }
  for ( j = 0; j <= 14; ++j )
  {
    result = sub_795090(j);
    if ( result )
    {
      ++*(_DWORD *)(unk_193C0F0 + 2092);
      *(_DWORD *)(unk_193C0F0 + 4 * *(_DWORD *)(unk_193C0F0 + 2084) + 2096) = j;
      *(_DWORD *)(unk_193C0F0 + 4 * *(_DWORD *)(unk_193C0F0 + 2084) + 2160) = result;
      result = unk_193C0F0;
      ++*(_DWORD *)(unk_193C0F0 + 2084);
    }
  }
  return result;
}
