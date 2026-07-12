// Function: sub_A265A0
// Address: 0xa265a0
// Size: 0x42

unsigned int __thiscall sub_A265A0(_DWORD *this)
{
  unsigned int v2; // edi
  unsigned int result; // eax

  v2 = 0; /*0xa265a4*/
  if ( (*(this + 2) & 0x7FFFFFFF) != 0 ) /*0xa265ad*/
  {
    do /*0xa265dd*/
    {
      if ( *(_DWORD *)(*(this + 3) + 4 * v2) ) /*0xa265b3*/
        sub_A28F40(*(this + 6), *(this + 11) - *(this + 7) - *(this + 9), *(this + 8), *(this + 9)); /*0xa265cd*/
      ++v2; /*0xa265d5*/
      result = *(this + 2) & 0x7FFFFFFF; /*0xa265d6*/
    }
    while ( v2 < result ); /*0xa265dd*/
  }
  return result; /*0xa265df*/
}