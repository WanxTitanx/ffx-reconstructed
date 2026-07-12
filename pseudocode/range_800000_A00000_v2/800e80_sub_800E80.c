// Function: sub_800E80
// Address: 0x800e80
int __cdecl sub_800E80(int a1, int a2, char a3, int a4)
{
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  __int16 *v7; // edx
  int v8; // edi
  __int16 v9; // ax
  int v10; // ebx
  int v11; // ecx

  v4 = a1;
  if ( a1 )
  {
    v6 = a2;
    v5 = a4;
  }
  else
  {
    v4 = unk_12A4080;
    v5 = 1;
    v6 = *(_DWORD *)(unk_12A4080 + 32);
  }
  v7 = *(__int16 **)(v4 + 28);
  v8 = *(unsigned __int8 *)(v6 + 30);
  v9 = *v7;
  if ( *v7 < 0 )
    return 0;
  v10 = *(_DWORD *)(v4 + 32);
  while ( 1 )
  {
    v11 = v10 + (v9 << 8);
    if ( *(_BYTE *)(v11 + 187) == a3 && (v5 || *(unsigned __int8 *)(v11 + 30) == v8) )
      break;
    v9 = v7[1];
    ++v7;
    if ( v9 < 0 )
      return 0;
  }
  return v10 + (v9 << 8);
}
