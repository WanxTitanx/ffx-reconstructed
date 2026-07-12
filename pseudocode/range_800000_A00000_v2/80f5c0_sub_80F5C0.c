// Function: sub_80F5C0
// Address: 0x80f5c0
int __cdecl sub_80F5C0(int a1, int n2, int a3)
{
  int result; // eax
  int v4; // ebx
  int v5; // ecx
  int v6; // esi
  __int16 v7; // dx
  int v8; // edi
  _WORD *p_n8; // ebx
  int v10; // edi
  int v11; // eax
  int v12; // [esp+0h] [ebp-14h]
  int v13; // [esp+4h] [ebp-10h]
  int v14; // [esp+8h] [ebp-Ch]
  int v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]

  result = sub_800E80(0, 0, 18, 1);
  if ( result )
  {
    v4 = *(_DWORD *)(result + 188);
    v5 = **(_DWORD **)(v4 + 4);
    v6 = a1 + 16;
    *(_DWORD *)a1 = **(_DWORD **)v4;
    *(_BYTE *)(a1 + 6) = n2;
    v7 = 0;
    v8 = a1 + 16 + 16 * *(unsigned __int16 *)(v4 + 14);
    v12 = v4;
    v15 = v5;
    v14 = 0;
    v16 = v8;
    v13 = 0;
    if ( *(_WORD *)(v4 + 14) )
    {
      p_n8 = (_WORD *)(v4 + 292);
      do
      {
        if ( sub_82AE50(v5, (unsigned __int16)*p_n8) )
          *(_WORD *)(v6 + 8) |= 1u;
        *(_DWORD *)v6 = unknown_libname_742(v8);
        *(_DWORD *)(v6 + 4) = unknown_libname_742(p_n8 + 14);
        *(_WORD *)(v6 + 10) = *p_n8;
        v10 = sub_8304D0(v15, (unsigned __int16)*p_n8);
        sub_830510(v15, (unsigned __int16)*p_n8, v16);
        v11 = v16 + ((v10 + 15) & 0xFFFFFF0);
        if ( n2 == 2 )
          v11 = sub_A69F10(v16, v16 + ((v10 + 15) & 0xFFFFFF0), a3);
        v8 = v11;
        v7 = v14 + 1;
        p_n8 += 48;
        v6 += 16;
        ++v13;
        v5 = v15;
        v16 = v11;
        ++v14;
      }
      while ( v13 < *(unsigned __int16 *)(v12 + 14) );
    }
    *(_WORD *)(a1 + 4) = v7;
    return a1;
  }
  return result;
}
