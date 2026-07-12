// Function: sub_AEF7C0
// Address: 0xaef7c0
// Size: 0x4e
// Prototype: 

int sub_AEF7C0()
{
  char *RenderMiniMapFog; // eax

  RenderMiniMapFog = (char *)sub_42FC60(17, 2);
  if ( RenderMiniMapFog )
    strcpy(RenderMiniMapFog, "RenderMiniMapFog");
  RenderMiniMapFog_2 = RenderMiniMapFog;
  return atexit(sub_B06C10);
}

