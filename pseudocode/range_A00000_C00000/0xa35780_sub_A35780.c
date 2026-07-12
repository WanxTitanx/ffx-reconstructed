// Function: sub_A35780
// Address: 0xa35780
// Size: 0x2e3
// Prototype: 

_DWORD *__cdecl sub_A35780(int a1, int a2, int a3, int a4)
{
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  int v9; // esi
  int v10; // ebx
  int v11; // eax
  int v12; // edi
  _DWORD *v13; // esi
  void *v15; // [esp+8h] [ebp-4h]

  v4 = (_DWORD *)IggyGDrawMallocAnnotated(
                   2768,
                   "r:\\hg_code\\middleware_w32\\iggysdk\\gdraw\\gdraw_d3d1x_shared.inl",
                   2265);
  v5 = v4;
  dword_1A858B4 = v4;
  if ( v4 )
  {
    memset(v4, 0, 0xAD0u);
    v5[432] = a3;
    v5[433] = a4;
    *v5 = a1;
    v5[1] = a2;
    v6 = dword_C6D450;
    v15 = off_C6D454;
    v7 = IggyGDrawMallocAnnotated(
           56 * dword_C6D450 + 424,
           "r:\\hg_code\\middleware_w32\\iggysdk\\gdraw\\gdraw_d3d1x_shared.inl",
           2152);
    v8 = v7;
    if ( v7 )
    {
      sub_A39BC0(v7, v6, v15);
      *(_DWORD *)(v8 + 12) &= ~1u;
    }
    dword_1A858B4[684] = v8;
    v9 = dword_C6D458;
    v10 = dword_C6D45C;
    v11 = IggyGDrawMallocAnnotated(
            56 * dword_C6D458 + 424,
            "r:\\hg_code\\middleware_w32\\iggysdk\\gdraw\\gdraw_d3d1x_shared.inl",
            2152);
    v12 = v11;
    if ( v11 )
    {
      sub_A39BC0(v11, v9, v10);
      *(_DWORD *)(v12 + 12) |= 1u;
    }
    v13 = dword_1A858B4;
    dword_1A858B4[685] = v12;
    sub_A39BC0(v13 + 164, dword_C6D448, off_C6D44C);
    if ( v13[684] && v13[685] )
    {
      if ( sub_A34B10(dword_C6D464) )
      {
        sub_A34CC0();
        psub_A3ABE0 = sub_A3ABE0;
        psub_A39900 = sub_A39900;
        psub_A38480 = sub_A38480;
        psub_A384B0 = sub_A384B0;
        nullsub_193_0 = nullsub_193;
        nullsub_194_0 = nullsub_194;
        psub_A3A820 = sub_A3A820;
        nullsub_192_0 = nullsub_192;
        psub_A3AC90 = sub_A3AC90;
        psub_A3AFB0 = sub_A3AFB0;
        psub_A387E0 = sub_A387E0;
        psub_A39200 = sub_A39200;
        psub_A3A9F0 = sub_A3A9F0;
        psub_A37410 = sub_A37410;
        psub_A373C0 = sub_A373C0;
        psub_A3A070 = sub_A3A070;
        psub_A3A530 = sub_A3A530;
        psub_A3A200 = sub_A3A200;
        psub_A3B0C0 = sub_A3B0C0;
        psub_A3B160 = sub_A3B160;
        psub_A3B100 = sub_A3B100;
        psub_A398A0 = sub_A398A0;
        psub_A3B050 = sub_A3B050;
        psub_A37C20 = sub_A37C20;
        psub_A37AC0 = sub_A37AC0;
        psub_A3A540 = sub_A3A540;
        psub_A3A7A0 = sub_A3A7A0;
        psub_A3A5F0 = sub_A3A5F0;
        psub_A3B010 = sub_A3B010;
        psub_A398E0 = sub_A398E0;
        psub_A3B090 = sub_A3B090;
        psub_A3ABC0 = sub_A3ABC0;
        psub_A3A9B0 = sub_A3A9B0;
        return &psub_A39900;
      }
      v13 = dword_1A858B4;
    }
    if ( v13 )
    {
      if ( v13[684] )
      {
        IggyGDrawFree(v13[684]);
        v13 = dword_1A858B4;
      }
      if ( v13[685] )
      {
        IggyGDrawFree(v13[685]);
        v13 = dword_1A858B4;
      }
      IggyGDrawFree(v13);
      dword_1A858B4 = 0;
    }
  }
  return 0;
}

