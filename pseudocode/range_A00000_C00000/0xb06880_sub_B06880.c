// Function: sub_B06880
// Address: 0xb06880
// Size: 0x16
// Prototype: void __cdecl()

void __cdecl sub_B06880()
{
  if ( (RenderBeforeVFX_1 & 1) == 0 )
    Phyre_Memory_AlignedFree(RenderBeforeVFX_1);
}

