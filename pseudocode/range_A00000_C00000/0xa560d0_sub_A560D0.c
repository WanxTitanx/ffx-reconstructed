// Function: sub_A560D0
// Address: 0xa560d0
// Size: 0x83
// Prototype: 

int __cdecl sub_A560D0(int a1, int a2, int a3, int a4)
{
  bool v4; // zf
  int v5; // eax

  if ( !a4 )
    return sub_A59950();
  v4 = unk_1A85F74 == 0;
  v5 = unk_1A86108;
  *(_BYTE *)(unk_1A86108 + 6691) = 1;
  *(_DWORD *)(v5 + 6698) = &unk_1640030;
  *(_BYTE *)(v5 + 6706) = 0;
  *(_DWORD *)(v5 + 6708) = sub_A5A080;
  if ( v4 )
    *(_DWORD *)(v5 + 6702) = 1310896;
  else
    *(_DWORD *)(v5 + 6702) = 1310864;
  return sub_A5B980(
           *(unsigned __int8 *)(dword_2305834[0] + 71100),
           *(unsigned __int16 *)(dword_2305834[0] + 80 * *(unsigned __int8 *)(dword_2305834[0] + 71100) + 69836),
           *(unsigned __int16 *)(a2 + 8));
}

