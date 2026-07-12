// Function: sub_A1B710
// Address: 0xa1b710
// Size: 0x69
// Prototype: 

int __usercall sub_A1B710@<eax>(_DWORD *a1@<ecx>, int a2@<ebx>)
{
  _DWORD *v3; // eax
  int v4; // eax
  int result; // eax

  v3 = (_DWORD *)a1[2];
  if ( v3 && *v3 )
  {
    v4 = sub_A161B0();
    result = sub_A185A0(a1, a2, v4, (int)&unk_1943DA0, v4);
    if ( result )
      return result;
    a1[1005] = sub_56CD50("FocusPlaneDistance");
    a1[1006] = sub_56CD50("FocusRange");
    a1[1007] = sub_56CD50("FocusBlurRange");
  }
  a1[3] = a1[2];
  return 0;
}

