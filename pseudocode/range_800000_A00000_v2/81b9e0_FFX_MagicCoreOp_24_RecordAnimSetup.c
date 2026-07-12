// Function: FFX_MagicCoreOp_24_RecordAnimSetup
// Address: 0x81b9e0
// [Jarvis naming goal 2026-06-17] Magic core opcode 0x24/0x25 handler: record animation/setup path; allocates animation data, stores callback and record fields.
int __cdecl FFX_MagicCoreOp_24_RecordAnimSetup(int a1, int a2)
{
  int v2; // ebx
  int v3; // esi

  v2 = *(_DWORD *)(a1 + 544);
  v3 = sub_7E3720(*(_DWORD *)(a1 + 4 * *(unsigned __int8 *)(v2 + 30) + 864), 4, *(unsigned __int16 *)(a2 + 2));
  *(_BYTE *)(v2 + 187) = 1;
  *(_DWORD *)(v2 + 224) = v3;
  *(_DWORD *)(v2 + 192) = sub_480080;
  *(_DWORD *)(v2 + 196) = 0;
  *(_DWORD *)(v2 + 242) = 256;
  *(_BYTE *)(v2 + 168) = (*(__int16 *)(a1 + 538) >> 13) & 7;
  *(_BYTE *)(v2 + 169) = (*(__int16 *)(a1 + 538) >> 9) & 7;
  *(_BYTE *)(v2 + 170) = *(_BYTE *)(a1 + 538) - 36;
  sub_800C80(a1 + 768, *(_WORD *)(a1 + 532));
  *(_DWORD *)(v2 + 228) = v3 + 16;
  *(_DWORD *)(v2 + 232) = v3 + *(__int16 *)(v3 + 16);
  *(_WORD *)(v2 + 240) = 512;
  *(_DWORD *)(v2 + 236) = &unk_200FFFF;
  return a2 + 4;
}
