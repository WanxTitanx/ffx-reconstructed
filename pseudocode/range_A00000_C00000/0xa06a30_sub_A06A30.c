// Function: sub_A06A30
// Address: 0xa06a30
// Size: 0x7d
// Prototype: 

int __cdecl sub_A06A30(int a1, unsigned int a2, unsigned int a3, int a4, char a5, char a6, int *a7)
{
  int *v7; // esi
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  int result; // eax
  int v11; // eax

  v7 = a7;
  if ( !a7 )
    v7 = (int *)&a7;
  *v7 = 0;
  v8 = (_DWORD *)sub_4410E0(1, (int)&unk_CA37D0, 0);
  v9 = v8;
  if ( !v8 )
    return 0;
  v11 = sub_4C41C0(v8, a2, a3, a4, 0);
  *v7 = v11;
  if ( v11 )
    return 0;
  v9[5] &= ~2u;
  *((_BYTE *)v9 + 5) = a5;
  sub_4C4350(v9);
  result = sub_64AFA0(v9);
  if ( !result )
    return 0;
  *(_BYTE *)(result + 5) = a6;
  *(_DWORD *)(result + 12) = "PPostProcessUtils";
  return result;
}

