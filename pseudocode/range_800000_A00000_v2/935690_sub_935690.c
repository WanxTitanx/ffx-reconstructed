// Function: sub_935690
// Address: 0x935690
int __cdecl sub_935690(int a1)
{
  int v1; // edx
  int v2; // ecx
  int v3; // eax
  int n0x1A; // edx
  int n26; // ecx
  int v6; // ecx
  int result; // eax

  v1 = 0;
  v2 = dword_C60A78[2 * *(_DWORD *)(unk_193C0F0 + 2264)];
  v3 = 0;
  while ( v2 < dword_C60DC0[v3] || v2 >= dword_C60DC4[v3] )
  {
    if ( (unsigned int)++v3 >= 0x1B )
      goto LABEL_7;
  }
  v1 = v3;
LABEL_7:
  n0x1A = a1 + v1;
  if ( n0x1A >= 0 )
    n26 = (unsigned int)n0x1A <= 0x1A ? n0x1A : 0;
  else
    n26 = 26;
  v6 = dword_C60DC0[n26];
  result = 0;
  while ( dword_C60A78[2 * result] != v6 )
  {
    if ( (unsigned int)++result >= 0x69 )
      return result;
  }
  *(_DWORD *)(unk_193C0F0 + 2264) = result;
  return result;
}
