// Function: sub_A430C0
// Address: 0xa430c0
// Size: 0x36
// Prototype: 

void *sub_A430C0()
{
  char Buffer[16]; // [esp+0h] [ebp-14h] BYREF

  sub_782CC0(Buffer);
  return sub_A42A00(
           (int)aHost0FfxProjPr_1,              // "host0:/ffx/proj/prog/cdidx/jp/sizetbl.bin"
           0);
}

