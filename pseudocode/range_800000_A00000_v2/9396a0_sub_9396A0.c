// Function: sub_9396A0
// Address: 0x9396a0
int __cdecl sub_9396A0(int a1)
{
  int v1; // ebx
  int n16; // edi
  int *v3; // eax
  int n160; // esi
  int v5; // edx
  int v6; // esi
  int v7; // edx

  v1 = *(_DWORD *)(a1 + 4);
  n16 = 16;
  if ( v1 > 0 )
  {
    v3 = (int *)(*(_DWORD *)(a1 + 8) + 152);
    do
    {
      n160 = 160;
      if ( *v3 > 0 )
      {
        v5 = 4 * *v3;
        v6 = v5 + 160;
        v7 = v5 & 0xF;
        if ( v7 )
          v6 += 16 - v7;
        n160 = *(_DWORD *)(v3[2] + 48) * *(_DWORD *)(v3[2] + 52) + v6 + 32;
      }
      n16 += n160 + *(_DWORD *)(v3[9] + 48) * *(_DWORD *)(v3[9] + 52) + 48;
      v3 += 48;
      --v1;
    }
    while ( v1 );
  }
  return n16 + 56;
}
