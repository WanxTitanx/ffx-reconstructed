// Function: sub_A42690
// Address: 0xa42690
// Size: 0x65

unsigned int __thiscall sub_A42690(unsigned int *this, unsigned int *a2)
{
  unsigned int result; // eax
  int v4; // edi
  unsigned int *v5; // ecx
  unsigned int *v6; // ecx

  result = *(this + 1); /*0xa42697*/
  if ( (unsigned int)a2 >= result || *this > (unsigned int)a2 ) /*0xa426a5*/
  {
    if ( result == *(this + 2) ) /*0xa426d5*/
      result = sub_A41AA0(this, 1u); /*0xa426db*/
    v6 = (unsigned int *)*(this + 1); /*0xa426e0*/
    if ( v6 ) /*0xa426e5*/
    {
      result = *a2; /*0xa426e7*/
      *v6 = *a2; /*0xa426e9*/
    }
  }
  else
  {
    v4 = (int)((int)a2 - *this) >> 2; /*0xa426a9*/
    if ( result == *(this + 2) ) /*0xa426af*/
      result = sub_A41AA0(this, 1u); /*0xa426b5*/
    v5 = (unsigned int *)*(this + 1); /*0xa426ba*/
    if ( v5 ) /*0xa426bf*/
    {
      result = *(_DWORD *)(*this + 4 * v4); /*0xa426c3*/
      *v5 = result; /*0xa426c6*/
      *(this + 1) += 4; /*0xa426c8*/
      return result; /*0xa426cf*/
    }
  }
  *(this + 1) += 4; /*0xa426eb*/
  retu... [1025 chars total]