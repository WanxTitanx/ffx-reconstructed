// Function: sub_A54760
// Address: 0xa54760
// Size: 0x78
// Prototype: int()

int sub_A54760()
{
  int result; // eax
  int v1; // eax

  unk_1A85F70 = 0;
  sub_7FEFB0(0);
  result = sub_7E5120(0);
  if ( !unk_1A85F64 )
  {
    v1 = (int)dword_2305800;
    unk_1A85F64 = 1;
    if ( !*dword_2305800 )
    {
      *((_WORD *)dword_2305800 + 2) = 0;
      *((_WORD *)dword_2305800 + 4) = 0;
      *((_WORD *)dword_2305800 + 3) = 0;
      *((_WORD *)dword_2305800 + 5) = 0;
      *((_WORD *)dword_2305800 + 6) = 0;
      v1 = (int)dword_2305800;
    }
    // "pppKeThRes48"
    return FFX_MagicHost_RelocatePppResourceBlob(v1, (int)&off_C86080);
  }
  return result;
}

