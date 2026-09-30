// d6.c — REGENERATED 2026-09-15 via IDA MCP (session 2af7bb39, port 8747)
// WHY: the original d6.c was an empty failed decompile at 0x90F8E0 (recorded in
// d6.json by the BattleMap decomp wave); regenerated per the lost-work directive.
// addr: 0x90F8E0
// FFX GS: Process DMA packet if 272
int __cdecl FFX_GS_ProcessDmaPacketIf272(float *yiBGRender, _DWORD *lpBuffer)
{
  if ( lpBuffer[1] == 272 ) /*0x90f8ed*/
    FFX_GS_ProcessDmaPacketData(yiBGRender, lpBuffer); /*0x90f8f3*/
  return 0; /*0x90f8fd*/
}
// refs: FFX_GS_ProcessDmaPacketData@0x90f900
