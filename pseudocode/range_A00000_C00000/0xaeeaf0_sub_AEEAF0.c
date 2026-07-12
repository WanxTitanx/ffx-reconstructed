// Function: sub_AEEAF0
// Address: 0xaeeaf0
// Size: 0x4e
// Prototype: 

int sub_AEEAF0()
{
  char *RenderMiniMapFog; // eax

  RenderMiniMapFog = (char *)sub_42FC60(17, 2);
  if ( RenderMiniMapFog )
    strcpy(RenderMiniMapFog, "RenderMiniMapFog");
  RenderMiniMapFog_0 = RenderMiniMapFog;
  return atexit(sub_B06770);
}

