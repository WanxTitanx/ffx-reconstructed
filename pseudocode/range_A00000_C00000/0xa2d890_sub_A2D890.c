// Function: sub_A2D890
// Address: 0xa2d890
// Size: 0x22
// Prototype: 

const void *__stdcall sub_A2D890(int a1, void *dst)
{
  const void *src; // eax

  src = (const void *)sub_A2CA30(a1);
  qmemcpy(dst, src, 0x30u);
  return src;
}

