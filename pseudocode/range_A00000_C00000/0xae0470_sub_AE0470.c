// Function: sub_AE0470
// Address: 0xae0470
// Size: 0x4e
// Prototype: 

int sub_AE0470()
{
  char *RenderMiniMapFog; // eax

  RenderMiniMapFog = (char *)sub_42FC60(17, 2);
  if ( RenderMiniMapFog )
    strcpy(RenderMiniMapFog, "RenderMiniMapFog");
  RenderMiniMapFog = RenderMiniMapFog;
  return atexit(sub_AF9B60);
}

