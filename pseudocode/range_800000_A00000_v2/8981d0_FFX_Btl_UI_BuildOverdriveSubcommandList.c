// Function: FFX_Btl_UI_BuildOverdriveSubcommandList
// Address: 0x8981d0
// [Jarvis naming goal 2026-06-17 pass2] Builds Overdrive submenu command IDs 0x1006.. from bitfields and auxiliary tables; caller is the Overdrive row builder.
int __cdecl FFX_Btl_UI_BuildOverdriveSubcommandList(int i, int a2)
{
  int v2; // esi
  unsigned __int16 v3; // ax
  int j; // edi
  int v5; // edx
  int k; // ecx
  unsigned __int16 v7; // ax
  int m; // edx
  unsigned __int16 v10; // [esp+Ch] [ebp-4h]
  unsigned __int16 v11; // [esp+Ch] [ebp-4h]

  v2 = 0;
  v3 = sub_78F980(i);
  v10 = v3;
  for ( j = 0; j < 12; ++j )
  {
    if ( j == 11 )
    {
      if ( sub_79AFD0(i) != 1 )
        goto LABEL_8;
      *(_WORD *)(a2 + 2 * v2) = 4113;
    }
    else
    {
      if ( ((v3 >> j) & 1) == 0 )
        goto LABEL_8;
      *(_WORD *)(a2 + 2 * v2) = j + 4102;
    }
    ++v2;
LABEL_8:
    v3 = v10;
  }
  v5 = sub_78FAD0(i);
  for ( k = 0; k < 13; ++k )
  {
    if ( *(_BYTE *)(v5 + k) )
      *(_WORD *)(a2 + 2 * v2++) = k + 4114;
  }
  v7 = sub_78F9A0(i);
  v11 = v7;
  for ( m = 0; m < 15; ++m )
  {
    if ( ((v7 >> m) & 1) != 0 )
      *(_WORD *)(a2 + 2 * v2++) = m + 4128;
    v7 = v11;
  }
  return v2;
}
