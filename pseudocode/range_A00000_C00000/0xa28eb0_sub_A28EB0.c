// Function: sub_A28EB0
// Address: 0xa28eb0
// Size: 0x21
// Prototype: int(void)

int __thiscall sub_A28EB0(int this)
{
  int v1; // eax
  int result; // eax

  if ( !*(_BYTE *)(this + 112) )
    return 0;
  v1 = *(_DWORD *)(this + 104);
  if ( !v1 )
    return 0;
  if ( !*(_DWORD *)(this + 108) )
    return 0;
  result = sub_A3D9B0(v1);
  if ( !result )
    return 0;
  return result;
}

