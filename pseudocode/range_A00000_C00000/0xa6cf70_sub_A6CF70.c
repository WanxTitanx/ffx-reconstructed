// Function: sub_A6CF70
// Address: 0xa6cf70
// Size: 0x39
// Prototype: 

int __cdecl sub_A6CF70(int a1, int a2, int a3)
{
  int v3; // ecx
  __int64 v4; // rax

  v3 = *(_DWORD *)(a3 + 912);
  v4 = 0;
  if ( *(__int16 *)(a1 + 20) > 0 )
  {
    do
    {
      *(float *)(v3 + 12) = 1.0;
      ++HIDWORD(v4);
      *(float *)(v3 + 8) = 1.0;
      v3 += 16;
      *(float *)(v3 - 12) = 1.0;
      *(float *)(v3 - 16) = 1.0;
      LODWORD(v4) = *(__int16 *)(a1 + 20);
    }
    while ( SHIDWORD(v4) < (int)v4 );
  }
  return v4;
}

