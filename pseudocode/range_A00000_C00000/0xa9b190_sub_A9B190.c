// Function: sub_A9B190
// Address: 0xa9b190
// Size: 0x73
// Prototype: int __fastcall(_DWORD, _DWORD)

int *__fastcall sub_A9B190(int *a1, int a2)
{
  int v3; // esi
  void *v4; // edi
  void *v5; // edi
  int *result; // eax

  v3 = 3 * a2;
  *a1 = a2;
  v4 = calloc_0(3 * a2, 4u);
  memset(v4, 0, 4 * v3);
  a1[1] = (int)v4;
  v5 = calloc_0(0x20u, 4u);
  result = (int *)memset(v5, 0, 0x80u);
  a1[2] = (int)v5;
  if ( a2 != 1 )
    return sub_A9AF90(a2, a1[1] + 4 * a2, (int *)v5);
  return result;
}

