// Function: sub_A42FC0
// Address: 0xa42fc0
// Size: 0xc0
// Prototype: 

void *sub_A42FC0()
{
  void *result; // eax
  char Buffer; // [esp+0h] [ebp-14h] BYREF
  char v2; // [esp+1h] [ebp-13h]

  sub_782CC0(&Buffer);
  if ( unk_133C8D3 )
  {
    aHost0FfxProjPr[26] = Buffer;               // "host0:/ffx/proj/prog/cdidx/jp/cdrom.mdg"
    aHost0FfxProjPr[27] = v2;                   // "host0:/ffx/proj/prog/cdidx/jp/cdrom.mdg"
    Buffer_4 = Buffer;
    byte_C85E0B = v2;
    MEMORY[0x2310C68] = sub_A42A00(
                          (int)aHost0FfxProjPr, // "host0:/ffx/proj/prog/cdidx/jp/cdrom.mdg"
                          0);
    result = sub_A42A00((int)&unk_C85DF0, 0);
    unk_2310C6C = result;
    dword_2310C70 = 0;
  }
  else
  {
    MEMORY[0x2310C68] = sub_A42A00(
                          (int)aHost0FfxProjBa_2,// "host0:/ffx/proj/battle/jp/cddata/cdrom.mdg"
                          0);
    unk_2310C6C = sub_A42A00(
                    (int)aHost0FfxProjBa_3,     // "host0:/ffx/proj/battle/jp/cddata/cdrom.fid"
                    0);
    result = sub_A42AB0(
               (int)aHost0FfxProjBa_4,          // "host0:/ffx/proj/battle/jp/cddata/cdrom.fnd"
               0);
    dword_2310C70 = (int)result;
  }
  return result;
}

