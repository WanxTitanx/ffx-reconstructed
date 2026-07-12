// Function: sub_8FD960
// Address: 0x8fd960
void __cdecl sub_8FD960(int src, int a2)
{
  int n3; // eax
  int dst[7]; // [esp+Ch] [ebp-1Ch] BYREF

  n3 = *(unsigned __int8 *)(src + 26);
  qmemcpy(dst, (const void *)src, sizeof(dst));
  *(float *)&dst[2] = *(float *)&dst[2] + 1.0;
  if ( n3 == 3 )
  {
    sub_8FCE90((int *)src, (__int16 *)a2);
    sub_8FCE90(dst, (__int16 *)a2);
    sub_8FD0A0((int *)src, (__int16 *)a2);
    sub_8FD0A0(dst, (__int16 *)a2);
  }
  else
  {
    sub_8FD9F0(src, a2);
    sub_8FD9F0(dst, a2);
    sub_8FDC00(src, a2);
    sub_8FDC00(dst, a2);
  }
  *(float *)(src + 4) = *(float *)(a2 + 28) + 1.5 + *(float *)(src + 4);
}
