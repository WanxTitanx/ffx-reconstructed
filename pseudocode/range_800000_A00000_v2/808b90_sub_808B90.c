// Function: sub_808B90
// Address: 0x808b90
int sub_808B90()
{
  _DWORD *v0; // esi
  int n208; // edi
  int result; // eax

  v0 = &unk_12A2280;
  n208 = 208;
  do
  {
    result = *v0;
    if ( *v0 )
      result = sub_83C890(*v0);
    v0 += 8;
    --n208;
  }
  while ( n208 );
  return result;
}
