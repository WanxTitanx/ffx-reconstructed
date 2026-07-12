// Function: sub_A3A540
// Address: 0xa3a540
// Size: 0xaa
// Prototype: 

int __stdcall sub_A3A540(int a1, int a2, int a3, int a4, _DWORD *a5, int a6)
{
  int v6; // eax
  bool v7; // zf
  _DWORD *v8; // eax

  *a5 = IggyGDrawMallocAnnotated(a3, "r:\\hg_code\\middleware_w32\\iggysdk\\gdraw\\gdraw_d3d1x_shared.inl", 614);
  v6 = IggyGDrawMallocAnnotated(a4, "r:\\hg_code\\middleware_w32\\iggysdk\\gdraw\\gdraw_d3d1x_shared.inl", 615);
  v7 = *a5 == 0;
  a5[1] = v6;
  if ( !v7 )
  {
    if ( v6 )
    {
      v8 = (_DWORD *)sub_A3B210(dword_1A858B4[685], a3 + a4, a6);
      if ( v8 )
      {
        *v8 = 0;
        v8[1] = 0;
        a5[4] = v8;
        a5[2] = a3;
        a5[5] = a1;
        a5[3] = a4;
        return 1;
      }
    }
    if ( *a5 )
      IggyGDrawFree(*a5);
  }
  if ( a5[1] )
    IggyGDrawFree(a5[1]);
  return 0;
}

