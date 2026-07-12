// Function: sub_98ED80
// Address: 0x98ed80
int __thiscall sub_98ED80(int this, int a2, float *a3, float *a4, float *a5, float *a6)
{
  int v7; // [esp-4h] [ebp-4h]
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  v7 = *(_DWORD *)(this + 68);
  if ( *(_BYTE *)(this + 72) )
    return sub_990D40(this, (int)&savedregs, a2, a3, a4, a5, a6, 0, v7);
  else
    return sub_991A10(a2, a3, a4, a5, a6, 0, v7);
}
