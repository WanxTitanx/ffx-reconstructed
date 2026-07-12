// Function: sub_A1B6E0
// Address: 0xa1b6e0
// Size: 0x2f
// Prototype: 

int __usercall sub_A1B6E0@<eax>(_DWORD *a1@<ecx>, int a2@<ebx>)
{
  _DWORD *v3; // eax
  int v4; // eax
  int result; // eax

  v3 = (_DWORD *)a1[2];
  if ( !v3 || !*v3 || (v4 = sub_A161B0(), (result = sub_A1A4F0(a1, a2, (int)&unk_1943DA0, v4)) == 0) )
  {
    a1[3] = a1[2];
    return 0;
  }
  return result;
}

