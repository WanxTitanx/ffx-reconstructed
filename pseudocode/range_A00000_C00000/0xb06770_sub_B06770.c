// Function: sub_B06770
// Address: 0xb06770
// Size: 0x16
// Prototype: void __cdecl()

void __cdecl sub_B06770()
{
  if ( (RenderMiniMapFog_0 & 1) == 0 )
    Phyre_Memory_AlignedFree(RenderMiniMapFog_0);
}

