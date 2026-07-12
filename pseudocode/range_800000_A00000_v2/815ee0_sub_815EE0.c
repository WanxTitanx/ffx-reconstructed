// Function: sub_815EE0
// Address: 0x815ee0
int __cdecl sub_815EE0(int a1, int a2)
{
  int v2; // esi
  char *v3; // ecx
  int n4096; // eax
  int v6; // eax

  v2 = *(_DWORD *)(a1 + 544);
  v3 = (char *)&unk_12A40C0 + 32 * *(unsigned __int16 *)(v2 + 20);
  n4096 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0 )
  {
    v6 = (unsigned __int8)v3[16];
    goto LABEL_8;
  }
  if ( n4096 == 4096 )
  {
    v6 = *(unsigned __int8 *)(v2 + 24);
LABEL_8:
    FFX_Btl_DispatchDamageToTargetSlots(*(_DWORD *)v3, v6, (unsigned __int16)(*(_WORD *)(a1 + 538) & 0x800) >> 10);
    return a2 + 2;
  }
  if ( n4096 != 0x2000 )
    return a2;
  sub_79B000(*(_DWORD *)v3, *(unsigned __int8 *)(v2 + 24));
  return a2 + 2;
}
