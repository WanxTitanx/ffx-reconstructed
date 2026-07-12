// Function: sub_8827F0
// Address: 0x8827f0
int __cdecl sub_8827F0(int a1, int a2)
{
  int v2; // ebx
  int v3; // ecx
  int v4; // eax
  int result; // eax
  int v6; // ecx
  int v7; // esi
  int v8; // edi
  int (*v9)(void); // eax
  int v10; // eax
  int v11; // [esp+Ch] [ebp-8h]
  int v12; // [esp+10h] [ebp-4h]
  int v13; // [esp+1Ch] [ebp+8h]
  int n30; // [esp+20h] [ebp+Ch]

  v13 = a1 + 4;
  v2 = a2 + 2;
  sub_86AF30(0);
  v3 = dword_1328AC0[unk_1328AB0] + word_C53414[4 * unk_1328AB0];
  v4 = unk_1328A64;
  if ( !unk_1328A64 && off_C53638 )
  {
    do
      ++v4;
    while ( *(&off_C53638 + 2 * v4) );
    unk_1328A64 = v4;
  }
  result = v4 - 1;
  v6 = v3 << 6;
  v11 = result;
  v7 = *(_DWORD *)((char *)&unk_1328AE8 + v6);
  *(_DWORD *)((char *)&unk_1328B04 + v6) = result;
  v12 = *(_DWORD *)((char *)&unk_1328ADC + v6);
  n30 = 0;
  v8 = v2 + 12;
  do
  {
    if ( result < v7 )
      break;
    sub_88FA60(v13, v2);
    sub_88F450(unk_1328A34, 0, *(&off_C53638 + 2 * v7));
    sub_88FA60(v13 + 102, v2);
    v9 = (int (*)(void))dword_C5363C[2 * v7];
    if ( v9 )
    {
      v10 = v9();
      sub_88F0B0(unk_1328A34, 0, v10);
    }
    if ( v7 == v12 )
      sub_88FAA0(2, 0, v13, v8, v13 + 356, v8);
    ++v7;
    v2 += 13;
    v8 += 13;
    ++n30;
    result = v11;
  }
  while ( n30 < 30 );
  return result;
}
