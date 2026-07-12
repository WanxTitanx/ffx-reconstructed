// Function: sub_89DDA0
// Address: 0x89dda0
int __cdecl sub_89DDA0(char a1, char a2)
{
  __int16 v2; // si
  int n1984; // eax
  __int16 v4; // si

  v2 = word_133FA60[0];
  n1984 = 1984;
  if ( word_133FA60[0] < 1984 )
  {
    byte_133FA70[word_133FA60[0]] = 8;
    v4 = v2 + 1;
    byte_133FA70[v4++] = a1 / 100;
    byte_133FA70[v4++] = a1 % 100;
    byte_133FA70[v4++] = a2 / 100;
    byte_133FA70[v4] = a2 % 100;
    word_133FA60[0] = v4 + 1;
    return v4;
  }
  return n1984;
}
