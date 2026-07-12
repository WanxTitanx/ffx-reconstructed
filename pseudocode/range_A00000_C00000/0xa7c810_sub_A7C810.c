// Function: sub_A7C810
// Address: 0xa7c810
// Size: 0x2c
// Prototype: 

__int16 __cdecl sub_A7C810(int a1, int a2, __int16 a3, __int16 a4)
{
  __int16 result; // ax
  int v5; // edx

  if ( a2 )
  {
    result = a1;
    v5 = unk_22FB4DC[a1];
    if ( v5 )
    {
      *(_WORD *)(v5 + a2 + 8) = a3;
      *(_WORD *)(v5 + a2 + 10) = a4;
      return a4;
    }
  }
  return result;
}

