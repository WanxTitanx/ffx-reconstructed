// Function: sub_AEECA0
// Address: 0xaeeca0
// Size: 0x46
// Prototype: 

int sub_AEECA0()
{
  char *RenderBeforeVFX; // eax

  RenderBeforeVFX = (char *)sub_42FC60(16, 2);
  if ( RenderBeforeVFX )
    strcpy(RenderBeforeVFX, "RenderBeforeVFX");
  RenderBeforeVFX_1 = RenderBeforeVFX;
  return atexit(sub_B06880);
}

