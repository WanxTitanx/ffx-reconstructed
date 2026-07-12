// Function: sub_B06CB0
// Address: 0xb06cb0
// Size: 0x50
// Prototype: void __cdecl()

void __cdecl sub_B06CB0()
{
  void **v0; // esi
  char v1; // [esp+7h] [ebp-1h] BYREF

  FFX_TexCache_FreeDeferredQueue(&MEMORY[0xCCC840]);
  v0 = MEMORY[0xCCC840];
  sub_680AD0(&v1);
  nullsub_64(v0);
  sub_680AD0(&v1);
  nullsub_64(v0 + 1);
  sub_680AD0(&v1);
  FFX_Memory_Free(v0);
}

