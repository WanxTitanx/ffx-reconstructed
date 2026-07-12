// Function: sub_932570
// Address: 0x932570
int sub_932570()
{
  int result; // eax

  sub_826E30();
  for ( result = sub_826DF0(); result; result = sub_826DF0() )
  {
    *(_DWORD *)(unk_193C0F0 + 4 * *(_DWORD *)(unk_193C0F0 + 2084) + 2096) = *(_DWORD *)(unk_193C0F0 + 2084);
    *(_DWORD *)(unk_193C0F0 + 4 * (*(_DWORD *)(unk_193C0F0 + 2084))++ + 2160) = result;
  }
  return result;
}
