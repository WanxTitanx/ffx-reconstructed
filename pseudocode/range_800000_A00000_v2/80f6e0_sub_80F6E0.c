// Function: sub_80F6E0
// Address: 0x80f6e0
int __cdecl sub_80F6E0(int n2)
{
  int result; // eax
  int v2; // ecx
  int v3; // edx
  int v4; // ebx
  int v5; // edi
  unsigned __int16 *v6; // esi
  unsigned int v7; // ecx
  unsigned int v8; // eax
  int v9; // [esp+0h] [ebp-8h]
  int v10; // [esp+4h] [ebp-4h]

  result = sub_800E80(0, 0, 18, 1);
  if ( result )
  {
    v2 = *(_DWORD *)(result + 188);
    v3 = **(_DWORD **)(v2 + 4);
    v4 = 0;
    v5 = 0;
    v10 = v2;
    v9 = v3;
    if ( *(_WORD *)(v2 + 14) )
    {
      v6 = (unsigned __int16 *)(v2 + 292);
      do
      {
        v7 = (sub_8304D0(v3, *v6) + 15) & 0xFFFFFF0;
        v8 = 0;
        if ( n2 == 2 )
          v8 = (12 * (v7 / 0x1C) + 15) & 0xFFFFFF0;
        v3 = v9;
        v4 += v8 + v7;
        ++v5;
        v6 += 48;
      }
      while ( v5 < *(unsigned __int16 *)(v10 + 14) );
    }
    return v4;
  }
  return result;
}
