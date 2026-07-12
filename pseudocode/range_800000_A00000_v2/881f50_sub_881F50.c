// Function: sub_881F50
// Address: 0x881f50
int __cdecl sub_881F50(int a1, int a2)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int result; // eax
  int v7; // edi
  int v8; // ecx
  int v9; // esi
  int v10; // edi
  int v11; // [esp+Ch] [ebp-8h]
  int v12; // [esp+10h] [ebp-4h]
  int v13; // [esp+1Ch] [ebp+8h]
  int n30; // [esp+20h] [ebp+Ch]

  v13 = a1 + 4;
  v2 = a2 + 2;
  v3 = *(_DWORD *)(sub_86AF30(0) + 72);
  v4 = dword_1328AC0[unk_1328AB0] + word_C53414[4 * unk_1328AB0];
  if ( v3 )
    v5 = sub_86AC80(v3);
  else
    v5 = 0;
  result = v5 + 15;
  v7 = v4 << 6;
  v11 = result;
  v8 = *(_DWORD *)((char *)&unk_1328ADC + v7);
  v9 = *(_DWORD *)((char *)&unk_1328AE8 + v7);
  *(_DWORD *)((char *)&unk_1328B04 + v7) = result;
  v12 = v8;
  n30 = 0;
  v10 = v2 + 12;
  do
  {
    if ( result < v9 )
      break;
    sub_882010(v13, v2, v9);
    if ( v9 == v12 )
      sub_88FAA0(2, 0, v13, v10, v13 + 356, v10);
    ++v9;
    v2 += 13;
    v10 += 13;
    ++n30;
    result = v11;
  }
  while ( n30 < 30 );
  return result;
}
