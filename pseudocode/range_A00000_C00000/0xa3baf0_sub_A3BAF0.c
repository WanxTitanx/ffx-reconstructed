// Function: sub_A3BAF0
// Address: 0xa3baf0
// Size: 0x198
// Prototype: 

int __thiscall sub_A3BAF0(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // edx
  int v4; // esi
  _DWORD *v6; // eax
  int v8; // edi
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  unsigned int v12; // edi
  _WORD v13[24]; // [esp+8h] [ebp-34h] BYREF
  _DWORD *this_1; // [esp+38h] [ebp-4h]

  v3 = a2[28];
  v4 = a2[27];
  this_1 = this;
  if ( !v4 || !v3 )
    return 21;
  if ( a2 != (_DWORD *)-496 )
  {
    v6 = sub_A35780(v4, v3, a2[128], a2[129]);
    *this = v6;
    if ( !v6 )
      return 9;
  }
  v8 = *(_DWORD *)(a3 + 16);
  v9 = *(_DWORD *)(a3 + 20);
  memset(v13, 0, sizeof(v13));
  if ( dword_C6D458 != v9 || dword_C6D45C != v8 )
  {
    dword_C6D458 = v9;
    dword_C6D45C = v8;
    if ( dword_1A858B4 )
    {
      v10 = dword_1A858B4[685];
      if ( v10 )
      {
        sub_A3B380(v10, (int)v13);
        IggyGDrawFree(dword_1A858B4[685]);
      }
      v11 = sub_A3BCD0(2);
      dword_1A858B4[685] = v11;
      if ( !v11 )
        return 9;
    }
  }
  if ( !sub_A38180(1, *(_DWORD *)(a3 + 28), *(void **)(a3 + 24)) || !sub_A38180(0, *(_DWORD *)(a3 + 4), *(void **)a3) )
    return 9;
  v12 = *(_DWORD *)(a3 + 8);
  if ( dword_C6D460 != *(_DWORD *)(a3 + 12) || dword_C6D464 != v12 )
  {
    dword_C6D460 = *(_DWORD *)(a3 + 12);
    dword_C6D464 = v12;
    if ( dword_1A858B4 )
    {
      sub_A3D280();
      sub_A34910(dword_1A858B4 + 614);
      sub_A34910(dword_1A858B4 + 618);
      if ( !sub_A34B10(v12) )
        return 9;
    }
  }
  IggySetGDraw(*this_1);
  return 0;
}

