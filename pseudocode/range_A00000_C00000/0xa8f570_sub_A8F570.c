// Function: sub_A8F570
// Address: 0xa8f570
// Size: 0xda
// Prototype: 

int __fastcall sub_A8F570(int a1, _DWORD *a2)
{
  int *v3; // edi
  int v5; // ecx
  unsigned int v6; // eax
  int v7; // ecx
  unsigned int v8; // eax

  v3 = (int *)a2[7];
  if ( !v3 || *v3 < 64 || v3[1] < *v3 )
    return -129;
  sub_42E350(a1, 1, 8);
  sub_A90540(6);
  sub_42E350(a1, 0, 32);
  sub_42E350(a1, a2[1], 8);
  sub_42E350(a1, a2[2], 32);
  sub_42E350(a1, a2[3], 32);
  sub_42E350(a1, a2[4], 32);
  sub_42E350(a1, a2[5], 32);
  v5 = 0;
  v6 = *v3 - 1;
  if ( *v3 != 1 )
  {
    do
    {
      ++v5;
      v6 >>= 1;
    }
    while ( v6 );
  }
  sub_42E350(a1, v5, 4);
  v7 = 0;
  v8 = v3[1] - 1;
  if ( v3[1] != 1 )
  {
    do
    {
      ++v7;
      v8 >>= 1;
    }
    while ( v8 );
  }
  sub_42E350(a1, v7, 4);
  sub_42E350(a1, 1, 1);
  return 0;
}

