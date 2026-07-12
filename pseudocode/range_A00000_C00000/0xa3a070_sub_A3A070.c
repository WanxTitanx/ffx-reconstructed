// Function: sub_A3A070
// Address: 0xa3a070
// Size: 0x183
// Prototype: 

int __stdcall sub_A3A070(int a1, int n0x4000, int n0x4000_1, int a4, int a5, _DWORD *a6, int a7)
{
  int v8; // esi
  int v9; // edx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  _DWORD *v13; // eax
  int v15; // [esp+10h] [ebp-4h]
  int n4; // [esp+20h] [ebp+Ch]
  int n61; // [esp+28h] [ebp+14h]

  v8 = 0;
  v15 = 0;
  if ( n0x4000 >= 0x4000 || n0x4000_1 >= 0x4000 )
  {
    IggyGDrawSendWarning(0, "GDraw texture size too large (%d x %d), dimension limit is 16384", n0x4000, n0x4000_1);
    return 0;
  }
  if ( a4 )
  {
    n61 = 61;
    n4 = 1;
  }
  else
  {
    n61 = 28;
    n4 = 4;
  }
  do
  {
    v9 = n0x4000 >> v8;
    if ( n0x4000 >> v8 <= 1 )
      v9 = 1;
    v10 = n0x4000_1 >> v8;
    if ( n0x4000_1 >> v8 <= 1 )
      v10 = 1;
    v11 = n4 * v9 * v10 + v15;
    ++v8;
    v15 = v11;
  }
  while ( (a5 & 1) != 0 && (n0x4000 >> v8 || n0x4000_1 >> v8) );
  v12 = IggyGDrawMallocAnnotated(v11, "r:\\hg_code\\middleware_w32\\iggysdk\\gdraw\\gdraw_d3d1x_shared.inl", 434);
  *a6 = v12;
  if ( !v12 )
  {
    IggyGDrawSendWarning(
      0,
      "GDraw out of memory to store texture data to pass to D3D for %d x %d texture",
      n0x4000,
      n0x4000_1);
    return 0;
  }
  v13 = (_DWORD *)sub_A3B210(dword_1A858B4[684], v15, a7);
  if ( v13 )
  {
    v13[3] = n0x4000;
    v13[4] = n0x4000_1;
    *v13 = 0;
    v13[1] = 0;
    v13[2] = 0;
    a6[6] = v13;
    a6[7] = a1;
    a6[16] = a5;
    a6[17] = n61;
    a6[18] = v15;
    a6[20] = n4;
    a6[14] = n0x4000;
    a6[19] = v8;
    a6[2] = n0x4000 * n4;
    a6[3] = 0;
    a6[15] = n0x4000_1;
    a6[1] = n0x4000_1;
    return 1;
  }
  else
  {
    IggyGDrawFree(*a6);
    return 0;
  }
}

