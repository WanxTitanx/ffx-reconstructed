// FFX Ps3Data: Commit slot records
void __cdecl FFX_Ps3Data_CommitSlotRecords(int a1)
{
  FFX_Ps3Data_BuildSlotDmaPacket(*(_DWORD *)(a1 + 1772), *(__int16 *)(a1 + 1776)); /*0x831398*/
  FFX_Scene_AsyncDmaTransfer(a1); /*0x83139e*/
}