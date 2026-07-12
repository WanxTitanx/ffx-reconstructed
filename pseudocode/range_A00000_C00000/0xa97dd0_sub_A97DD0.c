// Function: sub_A97DD0
// Address: 0xa97dd0
// Size: 0x26
// Prototype: int __fastcall(size_t Count, size_t Size)

void *__fastcall sub_A97DD0(size_t Count, size_t Size)
{
  void *v4; // esi

  v4 = calloc_0(Count, Size);
  memset(v4, 0, Size * Count);
  return v4;
}

