// Function: sub_A3E440
// Address: 0xa3e440
// Size: 0xa2
// Prototype: int __cdecl(int, int, int, int, char ArgList)

int *__cdecl sub_A3E440(int a1, int a2, int a3, int a4, const char *ArgList)
{
  int *v5; // eax
  int *v6; // esi

  v5 = (int *)sub_42FC20(44);
  v6 = v5;
  if ( v5 )
    sub_A3D3C0(v5);
  else
    v6 = 0;
  if ( !v6 || !sub_A3D850(v6, ArgList, a1, a2, a3, a4) )
    return v6;
  sub_A3D4D0(v6);
  Phyre_Memory_AlignedFree((int)v6);
  return 0;
}

