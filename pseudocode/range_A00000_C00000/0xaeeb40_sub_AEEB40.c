// Function: sub_AEEB40
// Address: 0xaeeb40
// Size: 0x46
// Prototype: 

int sub_AEEB40()
{
  char *RenderBeforeVFX; // eax

  RenderBeforeVFX = (char *)sub_42FC60(16, 2);
  if ( RenderBeforeVFX )
    strcpy(RenderBeforeVFX, "RenderBeforeVFX");
  RenderBeforeVFX_0 = RenderBeforeVFX;
  return atexit(sub_B06790);
}

