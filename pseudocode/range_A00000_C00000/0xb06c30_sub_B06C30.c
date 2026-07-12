// Function: sub_B06C30
// Address: 0xb06c30
// Size: 0x16
// Prototype: void __cdecl()

void __cdecl sub_B06C30()
{
  if ( (RenderBeforeVFX_2 & 1) == 0 )
    Phyre_Memory_AlignedFree(RenderBeforeVFX_2);
}

