// Function: sub_98A770
// Address: 0x98a770
int __thiscall sub_98A770(int *this, void *dst, const void *src)
{
  int v4; // eax
  int i_1; // esi
  int i; // ecx

  v4 = sub_989780(this, dst);
  if ( v4 )
  {
    i_1 = *(this + 2);
    if ( i_1 < 0 )
    {
      v4 = *this;
    }
    else
    {
      for ( i = 0; i < i_1; v4 = *(_DWORD *)(v4 + 32) )
      {
        if ( !*(_DWORD *)(v4 + 32) )
          break;
        ++i;
      }
    }
  }
  qmemcpy(dst, src, 0x20u);
  return sub_988D30(this, v4, dst);
}
