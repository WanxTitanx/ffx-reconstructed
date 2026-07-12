// Function: FFX_Abmap_RunPlacementFx
// Address: 0xa45930
// Size: 0xae
// Prototype: void __cdecl(int)

void __cdecl FFX_Abmap_RunPlacementFx(int a1)
{
  if ( *(_WORD *)(a1 + 30) )
  {
    sub_6ED4A0(&unk_230FE60, unk_2305834 + 70560);
    sub_6ED4A0(&unk_230FF60, unk_2305834 + 70688);
    unk_230FE98 = unk_230FE98 + 29184.0;
    sub_7174F0((float *)a1);
    sub_6ED700(&unk_230FF20, &unk_230FF60, &unk_230FFA0);
    sub_6ED4A0(&unk_230FE20, &unk_230FF20);
    *(_DWORD *)off_C3A4C4 = &unk_1A86034;
    if ( FFX_Menu2D_FlushCaptureBatch48(a1, 48) )
    {
      *(_DWORD *)off_C3A4C4 = &unk_1A86034;
      FFX_MagicHost_ClearResourceBufferList(a1);
      *(_WORD *)(a1 + 30) = 0;
    }
  }
}

