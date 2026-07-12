// Function: sub_81C570
// Address: 0x81c570
int __cdecl sub_81C570(int a1, int a2)
{
  int v2; // esi
  int v3; // eax

  v2 = *(_DWORD *)(a1 + 544);
  v3 = sub_7E3720(*(_DWORD *)(a1 + 4 * *(unsigned __int8 *)(v2 + 30) + 864), 4, *(unsigned __int16 *)(a2 + 2));
  *(_BYTE *)(v2 + 187) = 2;
  *(_DWORD *)(v2 + 224) = unknown_libname_742(v3);
  *(_DWORD *)(v2 + 192) = sub_480080;
  *(_BYTE *)(v2 + 168) = (*(__int16 *)(a1 + 538) >> 13) & 7;
  *(_BYTE *)(v2 + 169) = (*(__int16 *)(a1 + 538) >> 9) & 7;
  sub_800C80(a1 + 768, *(_WORD *)(a1 + 532));
  return a2 + 4;
}
