// Function: sub_AF9B80
// Address: 0xaf9b80
// Size: 0x16
// Prototype: void __cdecl()

void __cdecl sub_AF9B80()
{
  if ( (RenderBeforeVFX & 1) == 0 )
    Phyre_Memory_AlignedFree(RenderBeforeVFX);
}

