// Function: sub_AF9B60
// Address: 0xaf9b60
// Size: 0x16
// Prototype: void __cdecl()

void __cdecl sub_AF9B60()
{
  if ( (RenderMiniMapFog & 1) == 0 )
    Phyre_Memory_AlignedFree(RenderMiniMapFog);
}

