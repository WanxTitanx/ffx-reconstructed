// Function: sub_A3E4F0
// Address: 0xa3e4f0
// Size: 0xa8
// Prototype: 

int *__cdecl sub_A3E4F0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int *v7; // eax
  int *v8; // esi

  v7 = (int *)sub_42FC20(44);
  v8 = v7;
  if ( v7 )
    sub_A3D3C0(v7);
  else
    v8 = 0;
  if ( !v8 || !sub_A3D900(v8, a1, a2, a3, a4, a5, a6, a7) )
    return v8;
  sub_A3D4D0(v8);
  Phyre_Memory_AlignedFree((int)v8);
  return 0;
}

