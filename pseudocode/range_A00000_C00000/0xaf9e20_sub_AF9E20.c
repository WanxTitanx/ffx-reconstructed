// Function: sub_AF9E20
// Address: 0xaf9e20
// Size: 0xd8
// Prototype: void __cdecl()

void __cdecl sub_AF9E20()
{
  int v0; // ecx
  int v1; // eax

  v0 = unk_C902E4;
  MEMORY[0xC902D8] = &Phyre::PTTYCallback::`vftable';
  if ( (unk_C902E4 & 1) != 0 )
  {
    if ( (_DWORD *)MEMORY[0xC902E0] != &MEMORY[0xC902D8] )
      return;
    v1 = unk_C902DC;
  }
  else
  {
    v1 = unk_C902DC;
    v0 = unk_C902E4 | 1;
    unk_C902E4 |= 1u;
    if ( (unk_C902DC & 1) == 0 )
    {
      unk_C902DC |= 1u;
      MEMORY[0xC902D8] = &Phyre::PTTYCallback::`vftable';
      atexit(sub_AF9E20);
      v0 = unk_C902E4;
      v1 = unk_C902DC;
    }
    MEMORY[0xC902E0] = &MEMORY[0xC902D8];
  }
  if ( (v1 & 1) == 0 )
  {
    unk_C902DC = v1 | 1;
    MEMORY[0xC902D8] = &Phyre::PTTYCallback::`vftable';
    atexit(sub_AF9E20);
    v0 = unk_C902E4;
    v1 = unk_C902DC;
  }
  if ( (v0 & 1) == 0 )
  {
    unk_C902E4 = v0 | 1;
    if ( (v1 & 1) == 0 )
    {
      unk_C902DC = v1 | 1;
      MEMORY[0xC902D8] = &Phyre::PTTYCallback::`vftable';
      atexit(sub_AF9E20);
    }
  }
  MEMORY[0xC902E0] = &MEMORY[0xC902D8];
}

