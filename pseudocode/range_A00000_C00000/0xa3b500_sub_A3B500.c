// Function: sub_A3B500
// Address: 0xa3b500
// Size: 0x83
// Prototype: 

int __cdecl sub_A3B500(int a1, int a2)
{
  int v2; // edi
  int v3; // eax
  int v4; // eax
  bool v5; // zf
  const char *GDraw_Thrashing_vertex_memory; // eax

  v2 = *(_DWORD *)(a1 + 100);
  if ( v2 == a1 + 72 || !v2 )
    return 0;
  if ( (*(_BYTE *)(a1 + 12) & 1) != 0 )
  {
    v3 = *(_DWORD *)(v2 + 20);
    if ( v3 )
      IggyDiscardVertexBufferCallback(v3, *(_DWORD *)(a1 + 100));
  }
  if ( *(_QWORD *)(a1 + 416) < *(_QWORD *)(v2 + 40) )
  {
    v4 = *(_DWORD *)(a1 + 12);
    if ( (v4 & 2) == 0 )
    {
      v5 = (v4 & 1) == 0;
      GDraw_Thrashing_vertex_memory = "GDraw Thrashing vertex memory";
      if ( v5 )
        GDraw_Thrashing_vertex_memory = "GDraw Thrashing texture memory";
      IggyGDrawSendWarning(0, GDraw_Thrashing_vertex_memory);
      *(_DWORD *)(a1 + 12) |= 2u;
    }
  }
  sub_A3B480(v2, a2);
  return 1;
}

