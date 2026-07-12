// Function: sub_A3B210
// Address: 0xa3b210
// Size: 0xf7
// Prototype: 

_DWORD *__cdecl sub_A3B210(int a1, int a2, int a3)
{
  const char *GDraw_Out_of_static_vertex_buffer_%s_1; // eax
  const char *GDraw_Out_of_static_vertex_buffer_%s; // eax
  _DWORD *v5; // ecx
  _DWORD *v6; // edi
  int v7; // edx
  int v8; // eax
  const char *GDraw_Out_of_static_vertex_buffer_%s_2; // eax

  if ( a2 <= *(_DWORD *)(a1 + 4) )
  {
    if ( *(_DWORD *)a1 < a2 )
    {
      while ( sub_A3B500(a1, a3) )
      {
        if ( *(_DWORD *)a1 >= a2 )
          goto LABEL_12;
      }
      GDraw_Out_of_static_vertex_buffer_%s = "GDraw Out of static vertex buffer %s";
      if ( (*(_BYTE *)(a1 + 12) & 1) == 0 )
        GDraw_Out_of_static_vertex_buffer_%s = "GDraw Out of texture %s";
      IggyGDrawSendWarning(0, GDraw_Out_of_static_vertex_buffer_%s, "memory");
    }
  }
  else
  {
    GDraw_Out_of_static_vertex_buffer_%s_1 = "GDraw Out of static vertex buffer %s";
    if ( (*(_BYTE *)(a1 + 12) & 1) == 0 )
      GDraw_Out_of_static_vertex_buffer_%s_1 = "GDraw Out of texture %s";
    IggyGDrawSendWarning(0, GDraw_Out_of_static_vertex_buffer_%s_1, "memory (single resource larger than entire pool)");
  }
LABEL_12:
  v5 = *(_DWORD **)(a1 + 44);
  v6 = 0;
  if ( v5 != (_DWORD *)(a1 + 16) )
  {
    v6 = *(_DWORD **)(a1 + 44);
    v7 = v5[6];
    *(_DWORD *)(v5[8] + 28) = v5[7];
    *(_DWORD *)(v5[7] + 32) = v6[8];
    v7 += 352;
    v6[7] = v7;
    v8 = *(_DWORD *)(v7 + 32);
    v6[8] = v8;
    *(_DWORD *)(v8 + 28) = v6;
    *(_DWORD *)(v6[7] + 32) = v6;
    v6[12] = 1610612736;
    v6[5] = 0;
  }
  if ( !v6 )
  {
    if ( sub_A3B500(a1, a3) )
    {
      v6 = sub_A39A30(a1);
      if ( !v6 )
      {
        GDraw_Out_of_static_vertex_buffer_%s_2 = "GDraw Out of static vertex buffer %s";
        if ( (*(_BYTE *)(a1 + 12) & 1) == 0 )
          GDraw_Out_of_static_vertex_buffer_%s_2 = "GDraw Out of texture %s";
        IggyGDrawSendWarning(0, GDraw_Out_of_static_vertex_buffer_%s_2, "handles");
      }
    }
  }
  return v6;
}

