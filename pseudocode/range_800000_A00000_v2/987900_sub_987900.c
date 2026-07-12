// Function: sub_987900
// Address: 0x987900
void __thiscall sub_987900(_DWORD *this)
{
  int v2; // eax

  sub_9882D0();
  v2 = *(this + 8);
  if ( v2 )
  {
    if ( *((_BYTE *)this + 36) )
      sub_9D4D50(v2);
    *(this + 8) = 0;
  }
  *((_BYTE *)this + 36) = 1;
  *(this + 8) = 0;
  *(this + 6) = 0;
  *(this + 7) = 0;
}
