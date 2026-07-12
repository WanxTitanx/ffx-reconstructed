// Function: sub_B06860
// Address: 0xb06860
// Size: 0x16
// Prototype: void __cdecl()

void __cdecl sub_B06860()
{
  if ( (RenderMiniMapFog_1 & 1) == 0 )
    Phyre_Memory_AlignedFree(RenderMiniMapFog_1);
}

