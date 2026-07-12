// Function: sub_AE04C0
// Address: 0xae04c0
// Size: 0x46
// Prototype: 

int sub_AE04C0()
{
  char *RenderBeforeVFX; // eax

  RenderBeforeVFX = (char *)sub_42FC60(16, 2);
  if ( RenderBeforeVFX )
    strcpy(RenderBeforeVFX, "RenderBeforeVFX");
  RenderBeforeVFX = RenderBeforeVFX;
  return atexit(sub_AF9B80);
}

