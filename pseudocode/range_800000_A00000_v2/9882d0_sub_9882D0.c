// Function: sub_9882D0
// Address: 0x9882d0
int __thiscall sub_9882D0(_DWORD *this)
{
  int v2; // edi
  int result; // eax

  v2 = *this;
  if ( *this )
  {
    if ( *(_DWORD *)(v2 + 40) )
    {
      sub_989700(this, *(_DWORD *)(v2 + 36));
      sub_989700(this, *(_DWORD *)(v2 + 40));
    }
    if ( v2 == *this )
      *this = 0;
    sub_9D4D50(*(this + 1));
    *(this + 1) = v2;
  }
  sub_9D4D50(*(this + 1));
  *(this + 1) = 0;
  *(this + 2) = -1;
  result = *(this + 8);
  if ( result )
  {
    if ( *((_BYTE *)this + 36) )
      result = sub_9D4D50(*(this + 8));
    *(this + 8) = 0;
  }
  *((_BYTE *)this + 36) = 1;
  *(this + 8) = 0;
  *(this + 6) = 0;
  *(this + 7) = 0;
  *(this + 4) = 0;
  return result;
}
