// Function: sub_AA19A0
// Address: 0xaa19a0
// Size: 0x25
// Prototype: int __cdecl(void *Block)

void __cdecl sub_AA19A0(void *Block)
{
  if ( Block )
  {
    memset(Block, 0, 0xC88u);
    free_1(Block);
  }
}

