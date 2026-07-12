// Function: sub_A37960
// Address: 0xa37960
// Size: 0x15b
// Prototype: 

void sub_A37960()
{
  _DWORD *v0; // esi
  _DWORD *v1; // esi
  int v2; // ecx
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  _WORD v9[24]; // [esp+4h] [ebp-30h] BYREF

  v0 = dword_1A858B4;
  if ( dword_1A858B4 )
  {
    if ( *dword_1A858B4 )
    {
      memset(v9, 0, sizeof(v9));
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_1A858B4[1] + 440))(dword_1A858B4[1]);
      sub_A3CFC0();
      sub_A35C90();
      v1 = dword_1A858B4;
      v2 = dword_1A858B4[486];
      if ( v2 )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(dword_1A858B4[486]);
        v1[486] = 0;
        v1 = dword_1A858B4;
      }
      v3 = v1[487];
      if ( v3 )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 8))(v1[487]);
        v1[487] = 0;
        v1 = dword_1A858B4;
      }
      v4 = v1[614];
      if ( v4 )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v4 + 8))(v1[614]);
        v1[614] = 0;
        v1 = dword_1A858B4;
      }
      v5 = v1[618];
      if ( v5 )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 8))(v1[618]);
        v1[618] = 0;
      }
      sub_A36300(v9);
      v0 = dword_1A858B4;
      v6 = dword_1A858B4[684];
      if ( v6 )
      {
        sub_A3B380(v6, v9);
        v0 = dword_1A858B4;
      }
      v7 = v0[685];
      if ( v7 )
      {
        sub_A3B380(v7, v9);
        v0 = dword_1A858B4;
      }
      *v0 = 0;
    }
    v8 = v0[684];
    if ( v8 )
    {
      IggyGDrawFree(v8);
      v0 = dword_1A858B4;
    }
    if ( v0[685] )
    {
      IggyGDrawFree(v0[685]);
      v0 = dword_1A858B4;
    }
    IggyGDrawFree(v0);
    dword_1A858B4 = 0;
  }
}

