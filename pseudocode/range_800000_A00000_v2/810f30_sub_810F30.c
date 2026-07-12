// Function: sub_810F30
// Address: 0x810f30
int __cdecl sub_810F30(int a1, int a2, int a3, int a4)
{
  __int16 v4; // ax
  __int16 v5; // bx

  v4 = *(_WORD *)(a3 + 4);
  v5 = *(_WORD *)(a3 + 2);
  if ( v4 == -1 )
    v4 = *(_WORD *)(*(_DWORD *)(a4 + 4) + 4) - v5;
  if ( v4 )
    LOBYTE(v4) = sub_7E34D0(v4);
  *(_BYTE *)(a4 + 11) = v5 + v4;
  *(_BYTE *)(a4 + 10) = 1;
  return a3 + 6;
}
