// Function: sub_A654F0
// Address: 0xa654f0
// Size: 0x7c
// Prototype: 

int __cdecl sub_A654F0(unsigned __int16 a1, unsigned __int16 a2)
{
  int v2; // ebx
  int n12; // edi
  __int16 v4; // si
  int v5; // ebx
  int result; // eax

  sub_7E64F0(2, 4);
  v2 = a2 + 4 * a1;
  n12 = 12;
  v4 = word_22D9870[v2] - 12;
  v5 = 16 * v2;
  do
  {
    result = **((_WORD **)&unk_22C9870 + v5 + (v4 & 0xF)) & 0x1FF;
    if ( (_WORD)result )
    {
      result = dword_C88690[(__int16)result];
      if ( result )
        result = ((int (__cdecl *)(_DWORD))result)(*((_DWORD *)&unk_22C9870 + v5 + (v4 & 0xF)));
    }
    LOBYTE(v4) = v4 + 1;
    --n12;
  }
  while ( n12 );
  return result;
}

