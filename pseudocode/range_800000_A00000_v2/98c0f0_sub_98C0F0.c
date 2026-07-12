// Function: sub_98C0F0
// Address: 0x98c0f0
int __thiscall sub_98C0F0(int this, int a2, int a3)
{
  _DWORD *v3; // edx
  _DWORD *v4; // ecx
  int result; // eax

  if ( *(_BYTE *)(this + 72) )
  {
    v3 = (_DWORD *)(16 * a3 + *(_DWORD *)(this + 128));
    v4 = (_DWORD *)(16 * a2 + *(_DWORD *)(this + 148));
    *v4 = *v3;
    v4[1] = v3[1];
    v4[2] = v3[2];
    result = v3[3];
    v4[3] = result;
  }
  else
  {
    qmemcpy((void *)((a2 << 6) + *(_DWORD *)(this + 108)), (const void *)((a3 << 6) + *(_DWORD *)(this + 88)), 0x40u);
    return a2 << 6;
  }
  return result;
}
