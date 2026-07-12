// Function: sub_A1B300
// Address: 0xa1b300
// Size: 0x8a
// Prototype: 

int __thiscall sub_A1B300(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // ebx
  unsigned int v5; // eax
  char *v6; // ecx
  char *v7; // edi

  if ( (_UNKNOWN *)*this == &unk_CA34CC )
    return 7;
  if ( (unsigned __int8)sub_596130() || (result = sub_58DCE0(this)) == 0 )
  {
    v4 = *(this + 2);
    v5 = *(this + 10) & 0x7FFFFFFF;
    if ( v5 <= 1 )
    {
      if ( v5 )
        v6 = (char *)(this + 11);
      else
        v6 = 0;
    }
    else
    {
      v6 = (char *)*(this + 11);
    }
    v7 = &v6[20 * v4];
    while ( *((int *)v7 + 4) > 0 )
      PhyreThread_Sleep(1u);
    result = sub_597060(v4, a2);
    if ( !result )
      *((_BYTE *)this + 4) = 1;
  }
  return result;
}

