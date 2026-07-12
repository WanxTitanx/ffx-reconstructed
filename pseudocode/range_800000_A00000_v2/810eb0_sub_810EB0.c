// Function: sub_810EB0
// Address: 0x810eb0
int __cdecl sub_810EB0(int a1, int a2, int a3, int a4)
{
  unsigned __int8 v4; // dl
  int v5; // eax
  char v6; // cl
  int v7; // edx

  v4 = *(_BYTE *)(a3 + 4);
  v5 = *(__int16 *)(a3 + 2) + a4;
  v6 = *(_BYTE *)(a3 + 5);
  *(_BYTE *)(v5 + 44) = v6;
  if ( v6 )
  {
    if ( v6 < 0 )
      v6 = -v6;
  }
  else
  {
    v6 = 1;
  }
  v7 = v4 - *(unsigned __int8 *)(v5 + 28);
  if ( v7 < 0 )
    v7 = -v7;
  *(_BYTE *)(a1 + 528) = v7 / (unsigned __int8)v6;
  return a3 + 6;
}
