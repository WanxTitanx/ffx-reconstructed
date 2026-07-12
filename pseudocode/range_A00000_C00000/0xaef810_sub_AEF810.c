// Function: sub_AEF810
// Address: 0xaef810
// Size: 0x46
// Prototype: 

int sub_AEF810()
{
  char *RenderBeforeVFX; // eax

  RenderBeforeVFX = (char *)sub_42FC60(16, 2);
  if ( RenderBeforeVFX )
    strcpy(RenderBeforeVFX, "RenderBeforeVFX");
  RenderBeforeVFX_2 = RenderBeforeVFX;
  return atexit(sub_B06C30);
}

