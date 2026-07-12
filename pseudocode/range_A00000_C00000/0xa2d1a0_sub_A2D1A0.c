// Function: sub_A2D1A0
// Address: 0xa2d1a0
// Size: 0x53
// Prototype: 

int __cdecl sub_A2D1A0(int a1, int a2)
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
        *(float *)(n8 + 12) = 0.0;
        *(_DWORD *)(n8 - 8) = 0;
        *(float *)(n8 + 16) = 0.0;
        *(_DWORD *)(n8 - 4) = 0;
        *(_DWORD *)n8 = 0;
        *(_BYTE *)(n8 + 36) = 0;
        *(float *)(n8 + 8) = 0.0;
        *(float *)(n8 + 4) = 0.0;
        *(float *)(n8 + 24) = 0.0;
        *(float *)(n8 + 20) = 0.0;
        *(float *)(n8 + 32) = 0.0;
        *(float *)(n8 + 28) = 0.0;
      }
      n8 += 48;
      --v2;
    }
    while ( v2 );
  }
  return result;
}

