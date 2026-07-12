// Function: sub_A92040
// Address: 0xa92040
// Size: 0x95
// Prototype: int __cdecl(void *)

int __cdecl sub_A92040(void **a1)
{
  void **v1; // ebx
  void **v2; // esi
  int n7; // edi
  void **v4; // esi
  _QWORD *v5; // ebx
  void **Block; // [esp+8h] [ebp-4h]

  v1 = a1;
  v2 = (void **)a1[26];
  Block = v2;
  sub_A920E0(a1);
  if ( a1[17] )
    free_1(a1[17]);
  if ( v2 )
  {
    n7 = 0;
    v4 = v2 + 3;
    do
    {
      v5 = *v4;
      if ( *((_DWORD *)*v4 + 2) )
        free_1(*((void **)*v4 + 2));
      *v5 = 0;
      v5[1] = 0;
      *((_DWORD *)v5 + 4) = 0;
      if ( n7 != 7 )
        free_1(*v4);
      ++n7;
      ++v4;
    }
    while ( n7 < 15 );
    free_1(Block);
    v1 = a1;
  }
  memset(v1, 0, 0x70u);
  return 0;
}

