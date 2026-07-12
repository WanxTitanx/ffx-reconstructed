// Function: sub_A54810
// Address: 0xa54810
// Size: 0x50
// Prototype: 

int sub_A54810()
{
  void *v0; // ebx
  size_t KernelFile; // edi
  size_t v2; // esi
  int v4; // [esp-1Ch] [ebp-28h]
  int v5; // [esp-18h] [ebp-24h]
  int v6; // [esp-14h] [ebp-20h]
  int v7; // [esp+0h] [ebp-Ch]

  v0 = (void *)FFX_Memory_Alloc(0x25800u, v7);
  KernelFile = FFX_Kernel_ReadKernelFile((int)"sphere", v0);
  v2 = FFX_Kernel_ReadKernelFile((int)"panel", v0);
  FFX_Memory_Delete((int)v0, v6);
  unk_1A860E4 = (void *)FFX_Memory_Alloc(KernelFile, v5);
  unk_1A860E0 = (void *)FFX_Memory_Alloc(v2, v4);
  return sub_A54AB0();
}

