// Function: sub_9A4180
// Address: 0x9a4180
int __thiscall sub_9A4180(int *this, const void *src)
{
  int n4; // ebx
  int v4; // ecx

  n4 = *(this + 294);
  if ( n4 == 4 )
  {
    n4 = sub_9A4820(src);
    v4 = *(this + 72 * n4 + 31);
    if ( v4 && unk_193F644 )
    {
      unk_193F644(v4);
      *(this + 72 * n4 + 31) = 0;
    }
  }
  else
  {
    *(this + 294) = n4 + 1;
  }
  if ( n4 < 0 )
    n4 = 0;
  qmemcpy(this + 72 * n4 + 4, src, 0x120u);
  return n4;
}
