// Function: FFX_BtlHud_GetAnimDataField
// Address: 0xa7b8c0
// Size: 0x28
// Prototype: int __cdecl(int, int, int)

int __cdecl FFX_BtlHud_GetAnimDataField(int a1, int a2, int a3)
{
  int v4; // edx

  if ( a2 >= 0 && (v4 = unk_22FB4DC[a1]) != 0 )
    return *(_DWORD *)(v4 + 4 * a3 + a2 + 4);
  else
    return 0;
}

