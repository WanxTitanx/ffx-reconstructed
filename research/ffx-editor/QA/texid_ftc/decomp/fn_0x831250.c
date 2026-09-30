// FFX Ps3Data: Resolve texture slot
int __cdecl FFX_Ps3Data_ResolveTextureSlot(int a1)
{
  return FFX_Ps3Data_BuildSlotDmaPacket(*(_DWORD *)(a1 + 1764), *(__int16 *)(a1 + 1768)); /*0x83126f*/
}