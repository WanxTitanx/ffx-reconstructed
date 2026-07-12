// Function: sub_B05D10
// Address: 0xb05d10
// Size: 0x48
// Prototype: void __cdecl()

void __cdecl sub_B05D10()
{
  nullsub_26(&unk_CC05C0);
  if ( dword_CC05B4 >= 0 && unk_CC05B8 )
    Phyre_Memory_AlignedFree(unk_CC05B8);
  unk_CC05B8 = 0;
  dword_CC05B4 = 0;
  nullsub_219(&unk_CC0598);
}

