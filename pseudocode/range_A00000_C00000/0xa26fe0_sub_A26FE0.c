// Function: sub_A26FE0
// Address: 0xa26fe0
// Size: 0x53
// Prototype: int __cdecl(void *, int, void *Src, int, size_t Size, int)

void *__cdecl sub_A26FE0(char *a1, int a2, char *Src, int a4, size_t Size, int a6)
{
  int v6; // esi
  size_t Size_1; // ecx
  void *result; // eax
  char *v9; // ebx
  char *Src_1; // edi

  v6 = a6;
  if ( a6 )
  {
    Size_1 = Size;
    if ( Size )
    {
      if ( a4 == a2 )
      {
        return memcpy(a1, Src, a6 * a4);
      }
      else
      {
        v9 = a1;
        Src_1 = Src;
        do
        {
          result = memcpy(v9, Src_1, Size_1);
          v9 += a2;
          Src_1 += a4;
          Size_1 = Size;
          --v6;
        }
        while ( v6 );
      }
    }
  }
  return result;
}

