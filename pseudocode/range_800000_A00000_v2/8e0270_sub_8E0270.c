// Function: sub_8E0270
// Address: 0x8e0270
int __cdecl sub_8E0270(int a1)
{
  *(_WORD *)(a1 + 46) = 2;
  if ( !**(_BYTE **)(a1 + 152) )
    *(_WORD *)(a1 + 46) = 3;
  *(_DWORD *)(a1 + 288) = sub_8E0270;
  return 0;
}
