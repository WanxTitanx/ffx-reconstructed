// Function: sub_A3B380
// Address: 0xa3b380
// Size: 0xfa
// Prototype: 

_DWORD *__cdecl sub_A3B380(int a1, int a2)
{
  _DWORD *result; // eax
  int v3; // esi
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  const char *GDraw_Thrashing_vertex_memory; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // edx
  int v11; // eax

  *(_DWORD *)(a1 + 12) |= 2u;
  result = sub_A39F60(a1);
  while ( 1 )
  {
    v3 = *(_DWORD *)(a1 + 100);
    if ( v3 == a1 + 72 || !v3 )
      break;
    if ( (*(_BYTE *)(a1 + 12) & 1) != 0 )
    {
      v4 = *(_DWORD *)(v3 + 20);
      if ( v4 )
        IggyDiscardVertexBufferCallback(v4, *(_DWORD *)(a1 + 100));
    }
    if ( *(_QWORD *)(a1 + 416) < *(_QWORD *)(v3 + 40) )
    {
      v5 = *(_DWORD *)(a1 + 12);
      if ( (v5 & 2) == 0 )
      {
        v6 = (v5 & 1) == 0;
        GDraw_Thrashing_vertex_memory = "GDraw Thrashing vertex memory";
        if ( v6 )
          GDraw_Thrashing_vertex_memory = "GDraw Thrashing texture memory";
        IggyGDrawSendWarning(0, GDraw_Thrashing_vertex_memory);
        *(_DWORD *)(a1 + 12) |= 2u;
      }
    }
    sub_A34BC0((_DWORD *)v3);
    *(_WORD *)a2 |= 8u;
    ++*(_WORD *)(a2 + 6);
    *(_DWORD *)(a2 + 32) += *(_DWORD *)(v3 + 48) & 0xFFFFFFF;
    **(_DWORD **)(v3 + 24) += *(_DWORD *)(v3 + 48) & 0xFFFFFFF;
    v8 = *(_DWORD *)(v3 + 32);
    v9 = *(_DWORD *)(v3 + 28);
    *(_DWORD *)(v3 + 48) &= 0xF0000000;
    v10 = *(_DWORD *)(v3 + 24);
    *(_DWORD *)(v3 + 20) = 0;
    *(_DWORD *)(v8 + 28) = v9;
    *(_DWORD *)(*(_DWORD *)(v3 + 28) + 32) = *(_DWORD *)(v3 + 32);
    v10 += 16;
    *(_DWORD *)(v3 + 28) = v10;
    v11 = *(_DWORD *)(v10 + 32);
    *(_DWORD *)(v3 + 32) = v11;
    *(_DWORD *)(v11 + 28) = v3;
    result = *(_DWORD **)(v3 + 28);
    result[8] = v3;
    *(_DWORD *)(v3 + 48) &= 0xFFFFFFFu;
  }
  return result;
}

