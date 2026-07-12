// Function: sub_AA4200
// Address: 0xaa4200
// Size: 0x22
// Prototype: int __cdecl(void *Block)

void __cdecl sub_AA4200(void *Block)
{
  if ( Block )
  {
    memset(Block, 0, 0x60u);
    free_1(Block);
  }
}

