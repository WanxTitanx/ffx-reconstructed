// Function: sub_A54AB0
// Address: 0xa54ab0
// Size: 0x81
// Prototype: int(void)

int __usercall sub_A54AB0@<eax>(int a1@<esi>)
{
  void *v1; // esi
  size_t KernelFile; // eax
  void *v3; // esi
  size_t Size; // eax
  int v6; // [esp-38h] [ebp-38h]
  int v7; // [esp-20h] [ebp-20h]
  int v8; // [esp-1Ch] [ebp-1Ch]

  if ( FFX_Kernel_GetStubZero() )
    unk_2310C50(7);
  else
    unk_2310C50(13);
  v1 = (void *)FFX_Memory_Alloc(0x25800u, a1);
  KernelFile = FFX_Kernel_ReadKernelFile((int)"sphere", v1);
  memcpy(unk_1A860E4, v1, KernelFile);
  FFX_Memory_Delete((int)v1, v8);
  v3 = (void *)FFX_Memory_Alloc(0x25800u, v7);
  Size = FFX_Kernel_ReadKernelFile((int)"panel", v3);
  memcpy(unk_1A860E0, v3, Size);
  FFX_Memory_Delete((int)v3, v6);
  unk_2310C48(0);
  return nullsub_33(0);
}

