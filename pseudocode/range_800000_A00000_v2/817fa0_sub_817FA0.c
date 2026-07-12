// Function: sub_817FA0
// Address: 0x817fa0
int __cdecl sub_817FA0(int a1, int a2)
{
  int v3; // edi
  int v4; // eax
  float v6; // [esp+10h] [ebp+8h]

  v3 = *(_DWORD *)(a1 + 544);
  v6 = sub_794FC0(*(unsigned __int8 *)(v3 + 24));
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0x1000 )
      return a2;
    v4 = a2;
    if ( v6 <= (double)*(float *)(v3 + 148) )
      return *(__int16 *)(v4 + 2) + v4;
  }
  else
  {
    v4 = a2;
    if ( v6 >= (double)*(float *)(v3 + 148) )
      return *(__int16 *)(v4 + 2) + v4;
  }
  return v4 + 4;
}
