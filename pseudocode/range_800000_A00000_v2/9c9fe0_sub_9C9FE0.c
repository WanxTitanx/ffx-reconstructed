// Function: sub_9C9FE0
// Address: 0x9c9fe0
void __thiscall sub_9C9FE0(int this, _DWORD *a2)
{
  int v4; // edx
  int savedregs; // [esp+4h] [ebp+0h] BYREF
  float v6; // [esp+Ch] [ebp+8h]

  if ( *(_BYTE *)(this + 563) )
  {
    *a2 = 0;
    a2[1] = 0;
  }
  else
  {
    *a2 = 3;
    a2[1] = 3;
    sub_9C65C0(
      this,
      (int)&savedregs,
      (float *)(*(_DWORD *)(this + 20) + 16),
      (float *)(*(_DWORD *)(this + 24) + 16),
      (float *)(*(_DWORD *)(this + 20) + 272),
      (float *)(*(_DWORD *)(this + 24) + 272));
    if ( *(_BYTE *)(this + 562) )
    {
      ++*a2;
      --a2[1];
      v6 = *(float *)(this + 492);
      v4 = a2[1];
      if ( v6 > (double)*(float *)(this + 480) && v6 > (double)*(float *)(this + 484) )
      {
        ++*a2;
        a2[1] = v4 - 1;
      }
    }
    if ( *(_BYTE *)(this + 561) )
    {
      ++*a2;
      --a2[1];
    }
  }
}
