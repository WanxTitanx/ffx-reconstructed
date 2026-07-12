// Function: sub_A41930
// Address: 0xa41930
// Size: 0x54

_DWORD *__thiscall sub_A41930(void *this, int a2)
{
  _DWORD *v2; // esi
  _DWORD *result; // eax

  v2 = *(_DWORD **)(a2 + 8); /*0xa41937*/
  *(_DWORD *)(a2 + 8) = *v2; /*0xa4193c*/
  if ( !*(_BYTE *)(*v2 + 13) ) /*0xa41941*/
    *(_DWORD *)(*v2 + 4) = a2; /*0xa41947*/
  v2[1] = *(_DWORD *)(a2 + 4); /*0xa4194d*/
  result = *(_DWORD **)this; /*0xa41950*/
  if ( a2 == *(_DWORD *)(*(_DWORD *)this + 4) ) /*0xa41955*/
  {
    result[1] = v2; /*0xa41957*/
    *v2 = a2; /*0xa4195a*/
    *(_DWORD *)(a2 + 4) = v2; /*0xa4195c*/
  }
  else
  {
    result = *(_DWORD **)(a2 + 4); /*0xa41964*/
    if ( a2 == *result ) /*0xa41969*/
      *result = v2; /*0xa4196b*/
    else
      result[2] = v2; /*0xa41977*/
    *v2 = a2; /*0xa4196d*/
    *(_DWORD *)(a2 + 4) = v2; /*0xa4196f*/
  }
  return result; /*0xa4195f*/
}