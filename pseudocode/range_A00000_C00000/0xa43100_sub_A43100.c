// Function: sub_A43100
// Address: 0xa43100
// Size: 0x2a
// Prototype: 

void *sub_A43100()
{
  void *result; // eax

  result = sub_A42A00(
             (int)aHost0FfxProjPr_2,            // "host0:/ffx/proj/prog/cdidx/jp/sizetbl.vita.bin"
             &dword_1128A94);
  dword_1128A94 = (int)dword_1128A94 / 4;
  return result;
}

