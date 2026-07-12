// Function: sub_89DE30
// Address: 0x89de30
const char *__cdecl sub_89DE30(const char *a1)
{
  const char *result; // eax
  unsigned int v2; // edx
  __int16 v3; // di
  int v4; // esi
  char v5; // cl

  result = a1;
  v2 = strlen(a1);
  if ( v2 )
  {
    v3 = word_133FA60[0];
    if ( (int)(word_133FA60[0] + v2) < 1984 )
    {
      v4 = &byte_133FA70[word_133FA60[0]] - a1;
      do
      {
        v5 = *result;
        result[v4] = *result;
        ++result;
      }
      while ( v5 );
      word_133FA60[0] = v2 + v3;
    }
  }
  return result;
}
