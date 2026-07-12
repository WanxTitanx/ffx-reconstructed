// Function: sub_806E30
// Address: 0x806e30
_DWORD *__thiscall sub_806E30(void *this, _DWORD *a2)
{
  int v2; // esi
  int v3; // eax
  _DWORD *result; // eax

  v2 = *a2;
  *a2 = *(_DWORD *)(*a2 + 8);
  v3 = *(_DWORD *)(v2 + 8);
  if ( !*(_BYTE *)(v3 + 13) )
    *(_DWORD *)(v3 + 4) = a2;
  *(_DWORD *)(v2 + 4) = a2[1];
  result = *(_DWORD **)this;
  if ( a2 == *(_DWORD **)(*(_DWORD *)this + 4) )
  {
    result[1] = v2;
    *(_DWORD *)(v2 + 8) = a2;
    a2[1] = v2;
  }
  else
  {
    result = (_DWORD *)a2[1];
    if ( a2 == (_DWORD *)result[2] )
      result[2] = v2;
    else
      *result = v2;
    *(_DWORD *)(v2 + 8) = a2;
    a2[1] = v2;
  }
  return result;
}
