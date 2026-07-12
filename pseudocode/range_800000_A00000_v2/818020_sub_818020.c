// Function: sub_818020
// Address: 0x818020
int __cdecl sub_818020(int a1, int a2)
{
  int v2; // ebx
  int v3; // esi
  int v4; // eax
  double v5; // st7
  int result; // eax
  float v7; // [esp+10h] [ebp+Ch]

  v2 = *(_DWORD *)(a1 + 544);
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
    return a2;
  v3 = *(unsigned __int16 *)(a2 + 4);
  v4 = sub_800F80((_DWORD *)(a1 + 768), v2, *(_WORD *)(a2 + 2));
  v5 = sub_7E7ED0(v2 + 144, v4 + 144);
  result = a2 + 6;
  v7 = v5 * 16.0;
  *(float *)(v3 + v2) = v7;
  return result;
}
