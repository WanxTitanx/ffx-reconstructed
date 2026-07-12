// Function: sub_A9D640
// Address: 0xa9d640
// Size: 0x3e
// Prototype: int __thiscall(_DWORD)

void __thiscall sub_A9D640(void **this)
{
  if ( this )
  {
    if ( *(this + 2) )
      free_1(*(this + 2));
    if ( *(this + 3) )
      free_1(*(this + 3));
    *(_QWORD *)this = 0;
    *((_QWORD *)this + 1) = 0;
    *(this + 4) = 0;
  }
}

