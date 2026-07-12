// Function: sub_AA0450
// Address: 0xaa0450
// Size: 0x25
// Prototype: int __cdecl(void *Block)

void __cdecl sub_AA0450(void *Block)
{
  if ( Block )
  {
    memset(Block, 0, 0xB18u);
    free_1(Block);
  }
}

