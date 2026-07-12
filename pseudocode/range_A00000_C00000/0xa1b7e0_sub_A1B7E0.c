// Function: sub_A1B7E0
// Address: 0xa1b7e0
// Size: 0x2f
// Prototype: 

int __usercall sub_A1B7E0@<eax>(_DWORD *a1@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  _DWORD *v4; // eax
  int v5; // eax
  int result; // eax

  v4 = (_DWORD *)a1[2];
  if ( !v4 || !*v4 || (v5 = sub_A161B0(), (result = sub_A18C80(a1, a2, a3, (int)&unk_1943DA0, v5)) == 0) )
  {
    a1[3] = a1[2];
    return 0;
  }
  return result;
}

