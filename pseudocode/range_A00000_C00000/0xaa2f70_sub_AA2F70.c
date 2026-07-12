// Function: sub_AA2F70
// Address: 0xaa2f70
// Size: 0x25
// Prototype: int __cdecl(void *Block)

void __cdecl sub_AA2F70(void *Block)
{
  if ( Block )
  {
    memset(Block, 0, 0x460u);
    free_1(Block);
  }
}

