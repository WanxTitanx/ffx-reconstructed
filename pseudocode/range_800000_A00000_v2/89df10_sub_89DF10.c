// Function: sub_89DF10
// Address: 0x89df10
int __cdecl sub_89DF10(_BYTE *a1)
{
  _BYTE *v1; // eax
  int i; // esi

  v1 = a1;
  for ( i = 0; *v1; v1 = (_BYTE *)sub_8DFD70(v1) )
    i += 12;
  return i - 2;
}
