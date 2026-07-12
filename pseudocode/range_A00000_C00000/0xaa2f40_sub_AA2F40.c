// Function: sub_AA2F40
// Address: 0xaa2f40
// Size: 0x25
// Prototype: int __cdecl(void *Block)

void __cdecl sub_AA2F40(void *Block)
{
  if ( Block )
  {
    memset(Block, 0, 0x520u);
    free_1(Block);
  }
}

