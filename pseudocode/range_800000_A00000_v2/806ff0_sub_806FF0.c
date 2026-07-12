// Function: sub_806FF0
// Address: 0x806ff0
int __thiscall sub_806FF0(_DWORD *this)
{
  _DWORD *i_1; // ebx
  _DWORD *i; // esi
  int result; // eax

  i_1 = *(_DWORD **)(*this + 4);
  for ( i = i_1; !*((_BYTE *)i + 13); i_1 = i )
  {
    sub_806A90((void *)i[2]);
    i = (_DWORD *)*i;
    FFX_Memory_Free(i_1);
  }
  *(_DWORD *)(*this + 4) = *this;
  *(_DWORD *)*this = *this;
  result = *this;
  *(_DWORD *)(*this + 8) = *this;
  *(this + 1) = 0;
  return result;
}
