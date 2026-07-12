// Function: realloc
// Address: 0xa8d73c
// Size: 0x6
// Prototype: void *__cdecl(void *Block, size_t Size)

// attributes: thunk
void *__cdecl realloc(void *Block, size_t Size)
{
  return __imp_realloc(Block, Size);
}

