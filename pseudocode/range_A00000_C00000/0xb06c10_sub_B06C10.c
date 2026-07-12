// Function: sub_B06C10
// Address: 0xb06c10
// Size: 0x16
// Prototype: void __cdecl()

void __cdecl sub_B06C10()
{
  if ( (RenderMiniMapFog_2 & 1) == 0 )
    Phyre_Memory_AlignedFree(RenderMiniMapFog_2);
}

