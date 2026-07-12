// Function: sub_A1B870
// Address: 0xa1b870
// Size: 0x80
// Prototype: 

int __thiscall sub_A1B870(int this, unsigned int a2, unsigned int a3)
{
  int v3; // esi
  int *v4; // esi
  int result; // eax

  if ( !*(_BYTE *)(this + 16) )
    return 0;
  v3 = *(_DWORD *)(this + 4016);
  if ( !v3 )
    return 1;
  if ( *(_BYTE *)(v3 + 4) )
    return 1;
  v4 = *(int **)v3;
  if ( !v4 )
    return 1;
  if ( v4[7] == a2 && v4[8] == a3
    || (!sub_596120(v4) || (result = sub_59CDD0(v4)) == 0) && (result = sub_4C41C0(v4, a2, a3, *v4, 0)) == 0 )
  {
    result = sub_A23080(a2, a3);
    if ( !result )
      return 0;
  }
  return result;
}

