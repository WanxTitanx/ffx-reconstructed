// Function: sub_8141D0
// Address: 0x8141d0
int __cdecl sub_8141D0(__int64 a1, int a2, char n72)
{
  int n16; // eax
  int v5; // [esp+0h] [ebp-110h] BYREF
  int n768; // [esp+4h] [ebp-10Ch] BYREF
  int n258; // [esp+8h] [ebp-108h] BYREF
  char Source[256]; // [esp+Ch] [ebp-104h] BYREF

  n16 = 0;
  n258 = 0;
  n768 = 0;
  v5 = 0;
  if ( n72 == 66 )
  {
    n16 = 16;
  }
  else if ( n72 == 72 )
  {
    n16 = 2;
  }
  FFX_MagicCoreOp_CreateModelTexturedVtxFormat(a1, n16);
  strcpy(Source, "NoTexture");
  n258 = 258;
  n768 = 768;
  FFX_Ps3Data_BuildTextureSlotRecord_LoadTime(a1, 1, (int)&n258, &n768, Source, (int)&v5);
  sub_645930(a1);
  return sub_6458C0(a1, HIDWORD(a1), 1);
}
