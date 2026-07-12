// Function: sub_A0C7D0
// Address: 0xa0c7d0
// Size: 0x3f
// Prototype: 

int __cdecl sub_A0C7D0(int a1, int a2)
{
  int v2; // edx
  int n8; // ecx
  int result; // eax

  v2 = a2;
  if ( a2 )
  {
    n8 = a1 + 8;
    do
    {
      result = n8 - 8;
      if ( n8 != 8 )
      {
        *(float *)(n8 - 8) = 0.0;
        *(float *)(n8 - 4) = 0.0;
        *(float *)n8 = 0.0;
        *(_DWORD *)(n8 + 32) = 0;
        *(_DWORD *)(n8 + 36) = -1;
        *(float *)(n8 + 8) = 0.0;
        *(float *)(n8 + 12) = 0.0;
      }
      n8 += 48;
      --v2;
    }
    while ( v2 );
  }
  return result;
}

