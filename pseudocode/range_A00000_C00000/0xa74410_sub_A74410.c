// Function: sub_A74410
// Address: 0xa74410
// Size: 0xce
// Prototype: 

int __cdecl sub_A74410(int a1, int a2)
{
  int result; // eax
  _WORD *v3; // ebx
  int v4; // esi
  int v5; // edi
  __int64 v6; // [esp-40h] [ebp-48h]
  __int64 v7; // [esp-10h] [ebp-18h]
  int v8; // [esp+4h] [ebp-4h]

  result = a2;
  v8 = *(_DWORD *)(a1 + 544);
  if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0 )
  {
    v3 = (_WORD *)(a2 + *(__int16 *)(a2 + 4));
    v4 = sub_7E3720(
           *(_DWORD *)(a1 + 4 * *(unsigned __int8 *)(*(_DWORD *)(a1 + 544) + 30) + 864),
           4,
           *(__int16 *)(a2 + 2));
    v5 = sub_7FF6A0(*(_DWORD *)(a1 + 936), (*(__int16 *)(v4 + 16) << 8) + 32);
    *(_DWORD *)(v8 + 188) = v5;
    *(_WORD *)(v5 + 18) = *v3;
    *(_DWORD *)(v8 + 168) = v3;
    sub_A744E0(v4, v5, v3);
    *(_BYTE *)(v8 + 187) = -126;
    sub_800C80(a1 + 768, *(_WORD *)(a1 + 532));
    HIDWORD(v6) = v8;
    LODWORD(v6) = 0;
    if ( sub_A73C20(v6, (_DWORD *)v5, 10) )
    {
      HIDWORD(v7) = v8;
      LODWORD(v7) = 0;
      sub_645930(v7);
    }
    return a2 + 6;
  }
  return result;
}

