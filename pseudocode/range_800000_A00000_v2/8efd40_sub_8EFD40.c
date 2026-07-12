// Function: sub_8EFD40
// Address: 0x8efd40
int __cdecl sub_8EFD40(int a1, int a2, int a3, int a4)
{
  *(_QWORD *)a1 = __PAIR64__(
                    (a2 >> 31) | (unsigned int)((a3 | (unsigned __int64)((__int64)a4 << 8)) >> 8),
                    a2 | ((a3 | (unsigned int)(a4 << 8)) << 24));
  *(_DWORD *)(a1 + 8) = 78;
  *(_DWORD *)(a1 + 12) = 0;
  return a1 + 16;
}
