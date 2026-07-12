// Function: FFX_BtlHud_AnimationIsActive
// Address: 0xa7bb90
// Size: 0x29
// Prototype: int __cdecl(int n2, int)

int __cdecl FFX_BtlHud_AnimationIsActive(int n2, int a2)
{
  int v2; // eax
  int result; // eax

  if ( !a2 )
    return 0;
  v2 = unk_22FB4DC[n2];
  if ( !v2 )
    return 0;
  result = a2 + v2;
  if ( !result || (*(_DWORD *)(result + 4) & 0x40000000) != 0 )
    return 0;
  return result;
}

