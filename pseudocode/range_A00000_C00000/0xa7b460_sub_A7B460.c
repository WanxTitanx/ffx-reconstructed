// Function: sub_A7B460
// Address: 0xa7b460
// Size: 0xb0
// Prototype: _DWORD __cdecl(int, int n15, int)

int __cdecl sub_A7B460(int a1, int n15, int a3)
{
  int n15a_1; // ecx
  int v5; // ebx
  int v6; // edx
  int *v7; // edx
  int v8; // esi
  int v9; // eax
  int v10; // ebx
  _DWORD *v11; // edi
  int v12; // eax
  int v14; // [esp+4h] [ebp-Ch]
  int v15; // [esp+8h] [ebp-8h]
  int *v16; // [esp+Ch] [ebp-4h]
  int n15a; // [esp+1Ch] [ebp+Ch]

  if ( !n15 )
    return 0;
  n15a_1 = unk_22FB4DC[a1];
  n15a = n15a_1;
  if ( !n15a_1 )
    return 0;
  v5 = n15a_1 + n15;
  v14 = n15a_1 + n15;
  if ( !(n15a_1 + n15) )
    return 0;
  v6 = *(_DWORD *)(v5 + 4);
  if ( v6 >= 0 )
    return 0;
  unk_22FB4FC = *(__int16 *)(v5 + 8);
  v7 = (int *)(n15a_1 + (v6 & 0x3FFFFFFF));
  unk_22FB500 = *(__int16 *)(v5 + 10);
  v8 = *v7;
  v9 = n15a_1 + *(_DWORD *)(n15a_1 + 128);
  v10 = 0;
  v16 = v7;
  v15 = v9;
  v11 = v7 + 1;
  if ( *v7 <= 0 )
    goto LABEL_8;
  do
  {
    v12 = sub_A7B510(n15a_1, v7, v11, v9, a3);
    n15a_1 = n15a;
    v7 = v16;
    v10 |= v12;
    v9 = v15;
    --v8;
    v11 += 5;
  }
  while ( v8 > 0 );
  if ( !v10 )
LABEL_8:
    *(_DWORD *)(v14 + 4) &= ~0x40000000u;
  return v10;
}

