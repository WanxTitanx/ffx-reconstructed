// Function: sub_AEEC50
// Address: 0xaeec50
// Size: 0x4e
// Prototype: 

int sub_AEEC50()
{
  char *RenderMiniMapFog; // eax

  RenderMiniMapFog = (char *)sub_42FC60(17, 2);
  if ( RenderMiniMapFog )
    strcpy(RenderMiniMapFog, "RenderMiniMapFog");
  RenderMiniMapFog_1 = RenderMiniMapFog;
  return atexit(sub_B06860);
}

