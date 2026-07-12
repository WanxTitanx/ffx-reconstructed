// Function: sub_A32360
// Address: 0xa32360
// Size: 0x3f
// Prototype: 

int __thiscall sub_A32360(int (**this)(void), int a2, void *a3, _DWORD *a4, int a5)
{
  int v5; // eax

  if ( !a2 )
    return 0;
  v5 = (*(this + 1))();
  if ( !a4 || a3 != &unk_C92091 )
    return 0;
  *a4 = 0;
  a4[1] = v5;
  return 1;
}

