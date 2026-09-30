// FFX Menu: Tab selector input callback
int __cdecl FFX_Menu_TabSelectorInputCb(int a1)
{
  if ( *(_WORD *)(a1 + 4) < 0xC8u ) /*0x8ac0f0*/
    return 1; /*0x8ac230*/
  dbgPrintf(); /*0x8ac100*/
  *((_DWORD *)&unk_1841D60 + 4 * *(unsigned __int16 *)(a1 + 8)) = a1 + *(_DWORD *)(a1 + 32); /*0x8ac114*/
  *((_DWORD *)&unk_1841D68 + 4 * *(unsigned __int16 *)(a1 + 8)) = *(_DWORD *)(a1 + 36); /*0x8ac124*/
  *((_WORD *)&unk_1841D6C + 8 * *(unsigned __int16 *)(a1 + 8)) = *(_WORD *)(a1 + 40); /*0x8ac135*/
  *((_WORD *)&unk_1841D6E + 8 * *(unsigned __int16 *)(a1 + 8)) = *(_WORD *)(a1 + 42); /*0x8ac147*/
  if ( !*(_WORD *)(a1 + 8) ) /*0x8ac14e*/
  {
    memcpy(&unk_184B5D0, (const void *)(a1 + *(_DWORD *)(a1 + 32)), *(_DWORD *)(a1 + 36)); /*0x8ac163*/
    *((_DWORD *)&unk_1841D60 + 4 * *(unsigned __int16 *)(a1 + 8)) = &unk_184B5D0; /*0x8ac172*/
  }
  if ( *(_WORD *)(a1 + 8) == 4 ) /*0x8ac181*/
  {
    memcpy(&unk_185B5D0, (const void *)(a1 + *(_DWORD *)(a1 + 32)), *(_DWORD *)(a1 + 36)); /*0x8ac191*/
    *((_DWORD *)&unk_1841D60 + 4 * *(unsigned __int16 *)(a1 + 8)) = &unk_185B5D0; /*0x8ac1a0*/
  }
  switch ( *(_WORD *)(a1 + 8) ) /*0x8ac1b3*/
  {
    case 0: /*0x8ac1b3*/
      unk_1841D64 = &unk_1864DD0; /*0x8ac1ba*/
      break; /*0x8ac1c4*/
    case 1: /*0x8ac1b3*/
      unk_1841D74 = &unk_1865680; /*0x8ac1c6*/
      break; /*0x8ac1d0*/
    case 2: /*0x8ac1b3*/
      unk_1841D84 = &unk_1865800; /*0x8ac1d2*/
      break; /*0x8ac1dc*/
    case 3: /*0x8ac1b3*/
      unk_1841D94 = &unk_1865980; /*0x8ac1de*/
      break; /*0x8ac1e8*/
    case 4: /*0x8ac1b3*/
      unk_1841DA4 = &unk_18655B0; /*0x8ac1ea*/
      break; /*0x8ac1f4*/
    case 5: /*0x8ac1b3*/
      unk_1841DB4 = &unk_1865B20; /*0x8ac1f6*/
      break; /*0x8ac1f6*/
    default:
      *((_DWORD *)&unk_1841D64 + 4 * *(unsigned __int16 *)(a1 + 8)) = 0; /*0x8ac226*/
      return 1; /*0x8ac226*/
  }
  memcpy( /*0x8ac216*/
    *((void **)&unk_1841D64 + 4 * *(unsigned __int16 *)(a1 + 8)),
    (const void *)(a1 + *(_DWORD *)(a1 + 48)),
    *(_DWORD *)(a1 + 16));
  return 0; /*0x8ac220*/
}