// Function: sub_8008E0
// Address: 0x8008e0
int __cdecl sub_8008E0(int a1)
{
  int v1; // esi

  if ( *(_BYTE *)(a1 + 187) == 3 && *(_DWORD *)(a1 + 188) )
  {
    *(_DWORD *)off_C3A4C4 = &unk_12F2030;
    v1 = *(_DWORD *)(a1 + 188);
    *(_DWORD *)off_C3A4C4 = &unk_12F2030;
    FFX_MagicHost_ClearResourceBufferList(v1);
    dword_12E9C30[*(unsigned __int16 *)(v1 + 30)] = 0;
    *(_BYTE *)(a1 + 187) = 0;
    *(_DWORD *)(a1 + 188) = 0;
  }
  return 0;
}
