// Function: sub_A34CC0
// Address: 0xa34cc0
// Size: 0x9b0
// Prototype: 

int sub_A34CC0()
{
  _DWORD *v0; // ecx
  int n36; // esi
  int *v2; // esi
  int n608_2; // eax
  _DWORD *v4; // edx
  int *v5; // ebx
  _DWORD *v6; // ebx
  int v7; // eax
  int *v8; // esi
  int n608_3; // eax
  _DWORD *v10; // edx
  int *v11; // ebx
  _DWORD *v12; // ebx
  int v13; // eax
  int *v14; // esi
  int n608_4; // eax
  _DWORD *v16; // edx
  int *v17; // ebx
  _DWORD *v18; // ebx
  int v19; // eax
  _DWORD *v20; // edx
  int v21; // ebx
  _DWORD *v22; // esi
  int v23; // eax
  _DWORD *v24; // edx
  int v25; // ebx
  _DWORD *v26; // esi
  int v27; // eax
  _DWORD *v28; // ebx
  int v29; // eax
  int v30; // esi
  int **v31; // edx
  char *v32; // ecx
  int v33; // eax
  char *n1972_4; // ecx
  int *v35; // ecx
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int n608_1; // ecx
  double v40; // st7
  int v41; // eax
  int i; // esi
  int v43; // ecx
  int v44; // eax
  int v45; // eax
  int n1972; // ecx
  int n1972_2; // ebx
  _DWORD *CreateSamplerState; // esi
  int v49; // ecx
  int v50; // eax
  _DWORD *v51; // ebx
  _DWORD *v52; // esi
  int result; // eax
  int n1972_3; // ecx
  int v55; // eax
  int v56; // ebx
  int n2; // esi
  int v58; // edx
  int v59; // eax
  int v60; // ebx
  int n2_2; // edx
  _WORD *v62; // esi
  __int16 v63; // cx
  __int16 v64; // ax
  int v65; // eax
  int v66; // [esp-Ch] [ebp-1A0h]
  _DWORD v67[3]; // [esp+Ch] [ebp-188h] BYREF
  int v68; // [esp+18h] [ebp-17Ch]
  _DWORD *v69; // [esp+1Ch] [ebp-178h]
  int v70; // [esp+20h] [ebp-174h]
  int n1972_1; // [esp+24h] [ebp-170h]
  int n608; // [esp+28h] [ebp-16Ch]
  _BYTE v73[264]; // [esp+2Ch] [ebp-168h] BYREF
  _DWORD v74[13]; // [esp+134h] [ebp-60h] BYREF
  _DWORD v75[4]; // [esp+168h] [ebp-2Ch] BYREF
  int n24576; // [esp+178h] [ebp-1Ch] BYREF
  int v77; // [esp+17Ch] [ebp-18h]
  int n2_1; // [esp+180h] [ebp-14h]
  int v79; // [esp+184h] [ebp-10h]
  int v80; // [esp+188h] [ebp-Ch]
  int v81; // [esp+18Ch] [ebp-8h]

  v0 = dword_1A858B4;
  v69 = (_DWORD *)*dword_1A858B4;
  n36 = 0;
  while ( 1 )
  {
    sub_A35B40(&v0[n36 + 2], (char *)&off_C72F48 + n36 * 4);
    n36 += 2;
    if ( n36 >= 36 )
      break;
    v0 = dword_1A858B4;
  }
  v2 = (int *)&unk_C770B8;
  n608_2 = 152 - (_DWORD)&unk_C770B8;
  n608 = 152 - (_DWORD)&unk_C770B8;
  do
  {
    v4 = dword_1A858B4;
    v5 = (int *)((char *)v2 + n608_2 + (_DWORD)dword_1A858B4);
    *v5 = *v2;
    v5[1] = v2[1];
    n1972_1 = *v5;
    if ( n1972_1 )
    {
      v6 = v5 + 1;
      v7 = (*(int (__stdcall **)(_DWORD, int, _DWORD, _DWORD, _DWORD *))(*(_DWORD *)*v4 + 60))(*v4, n1972_1, *v6, 0, v6);
      if ( v7 < 0 )
      {
        if ( v7 == -2147024882 )
          IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "CreatePixelShader", &byte_B8FBDB);
        else
          IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "CreatePixelShader", &byte_B8FBDB, v7);
        *v6 = 0;
      }
    }
    n608_2 = n608;
    v2 += 2;
  }
  while ( (int)v2 < (int)dword_C77120 );
  v8 = (int *)&off_C806D8;
  n608_3 = 256 - (_DWORD)&off_C806D8;
  n608 = 256 - (_DWORD)&off_C806D8;
  do
  {
    v10 = dword_1A858B4;
    v11 = (int *)((char *)v8 + n608_3 + (_DWORD)dword_1A858B4);
    *v11 = *v8;
    v11[1] = v8[1];
    n1972_1 = *v11;
    if ( n1972_1 )
    {
      v12 = v11 + 1;
      v13 = (*(int (__stdcall **)(_DWORD, int, _DWORD, _DWORD, _DWORD *))(*(_DWORD *)*v10 + 60))(
              *v10,
              n1972_1,
              *v12,
              0,
              v12);
      if ( v13 < 0 )
      {
        if ( v13 == -2147024882 )
          IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "CreatePixelShader", &byte_B8FBDB);
        else
          IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "CreatePixelShader", &byte_B8FBDB, v13);
        *v12 = 0;
      }
    }
    n608_3 = n608;
    v8 += 2;
  }
  while ( (int)v8 < (int)dword_C807D8 );
  v14 = (int *)&unk_C842B8;
  n608_4 = 512 - (_DWORD)&unk_C842B8;
  n608 = 512 - (_DWORD)&unk_C842B8;
  do
  {
    v16 = dword_1A858B4;
    v17 = (int *)((char *)v14 + n608_4 + (_DWORD)dword_1A858B4);
    *v17 = *v14;
    v17[1] = v14[1];
    n1972_1 = *v17;
    if ( n1972_1 )
    {
      v18 = v17 + 1;
      v19 = (*(int (__stdcall **)(_DWORD, int, _DWORD, _DWORD, _DWORD *))(*(_DWORD *)*v16 + 60))(
              *v16,
              n1972_1,
              *v18,
              0,
              v18);
      if ( v19 < 0 )
      {
        if ( v19 == -2147024882 )
          IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "CreatePixelShader", &byte_B8FBDB);
        else
          IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "CreatePixelShader", &byte_B8FBDB, v19);
        *v18 = 0;
      }
    }
    n608_4 = n608;
    v14 += 2;
  }
  while ( (int)v14 < (int)dword_C84308 );
  v20 = dword_1A858B4;
  dword_1A858B4[148] = off_C847D8;
  v21 = v20[148];
  v20[149] = dword_C847DC;
  if ( v21 )
  {
    v22 = v20 + 149;
    v23 = (*(int (__stdcall **)(_DWORD, int, _DWORD, _DWORD, _DWORD *))(*(_DWORD *)*v20 + 60))(
            *v20,
            v21,
            v20[149],
            0,
            v20 + 149);
    if ( v23 < 0 )
    {
      if ( v23 == -2147024882 )
        IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "CreatePixelShader", &byte_B8FBDB);
      else
        IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "CreatePixelShader", &byte_B8FBDB, v23);
      *v22 = 0;
    }
  }
  v24 = dword_1A858B4;
  dword_1A858B4[150] = off_C84A8C;
  v25 = v24[150];
  v24[151] = dword_C84A90;
  if ( v25 )
  {
    v26 = v24 + 151;
    v27 = (*(int (__stdcall **)(_DWORD, int, _DWORD, _DWORD, _DWORD *))(*(_DWORD *)*v24 + 60))(
            *v24,
            v25,
            v24[151],
            0,
            v24 + 151);
    if ( v27 < 0 )
    {
      if ( v27 == -2147024882 )
        IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "CreatePixelShader", &byte_B8FBDB);
      else
        IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "CreatePixelShader", &byte_B8FBDB, v27);
      *v26 = 0;
    }
  }
  v28 = v69;
  v29 = 624 - (_DWORD)&off_C85A98;
  n608 = 608;
  v70 = 624 - (_DWORD)&off_C85A98;
  v30 = 0;
  do
  {
    v31 = (int **)dword_1A858B4;
    v32 = (char *)&off_C85A98 + v29;
    v33 = *(int *)((char *)&off_C85A98 + v30 * 4);
    n1972_4 = &v32[v30 * 4 + (_DWORD)dword_1A858B4];
    n1972_1 = (int)n1972_4;
    *(_DWORD *)n1972_4 = v33;
    *((_DWORD *)n1972_4 + 1) = dword_C85A9C[v30];
    v68 = *(_DWORD *)n1972_4;
    if ( v68 )
    {
      v35 = *v31;
      v36 = **v31;
      v66 = *(_DWORD *)(n1972_1 + 4);
      n1972_1 += 4;
      v37 = (*(int (__stdcall **)(int *, int, int, _DWORD, int))(v36 + 48))(v35, v68, v66, 0, n1972_1);
      if ( v37 < 0 )
      {
        if ( v37 == -2147024882 )
          IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "CreateVertexShader", &byte_B8FBDB);
        else
          IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "CreateVertexShader", &byte_B8FBDB, v37);
        *(_DWORD *)n1972_1 = 0;
      }
    }
    v38 = (*(int (__stdcall **)(_DWORD *, char **, int, _DWORD, int, int))(*v28 + 44))(
            v28,
            (&off_C6D4F4)[v30],
            dword_C6D4F8[v30],
            *(_UNKNOWN **)((char *)&off_C85A98 + v30 * 4),
            dword_C85A9C[v30],
            (int)dword_1A858B4 + n608);
    if ( v38 >= 0 )
    {
      n608_1 = n608;
    }
    else
    {
      if ( v38 == -2147024882 )
        IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "CreateInputLayout", &byte_B8FBDB);
      else
        IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "CreateInputLayout", &byte_B8FBDB, v38);
      n608_1 = n608;
      *(_DWORD *)((char *)dword_1A858B4 + n608) = 0;
    }
    v29 = v70;
    v30 += 2;
    n608 = n608_1 + 4;
  }
  while ( n608_1 + 4 < 620 );
  v40 = 0.0;
  v41 = 0;
  n608 = 0;
  for ( i = 491; i < 493; ++i )
  {
    v43 = *v28;
    *(float *)&n24576 = v40;
    v80 = v41;
    *(float *)&v77 = v40;
    v75[0] = 3;
    v75[1] = 1;
    v75[2] = 0;
    v75[3] = 0;
    n2_1 = 1;
    v79 = 1;
    v81 = 0;
    v44 = (*(int (__stdcall **)(_DWORD *, _DWORD *, _DWORD *))(v43 + 88))(v28, v75, &dword_1A858B4[i]);
    if ( v44 < 0 )
    {
      if ( v44 == -2147024882 )
        return IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "CreateRasterizerState", &byte_B8FBDB);
      else
        return IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "CreateRasterizerState", &byte_B8FBDB, v44);
    }
    v40 = 0.0;
    v41 = ++n608;
  }
  v45 = 0;
  n1972 = 1972;
  n608 = 0;
  n1972_1 = 1972;
  while ( 2 )
  {
    v70 = v45 != 0 ? 16 : 21;
    n1972_2 = n1972;
    CreateSamplerState = &unk_B7A884;
    do
    {
      memset(v74, 0, sizeof(v74));
      *(float *)&v74[12] = 3.4028235e38;
      v74[0] = v70;
      v49 = *v69;
      v74[1] = *CreateSamplerState;
      v74[2] = v74[1];
      v74[3] = 3;
      v74[5] = 1;
      v50 = (*(int (__stdcall **)(_DWORD *, _DWORD *, int))(v49 + 92))(v69, v74, (int)dword_1A858B4 + n1972_2);
      if ( v50 < 0 )
      {
        if ( v50 == -2147024882 )
          return IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "CreateSamplerState", &byte_B8FBDB);
        else
          return IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "CreateSamplerState", &byte_B8FBDB, v50);
      }
      ++CreateSamplerState;
      n1972_2 += 4;
    }
    while ( (int)CreateSamplerState < (int)"CreateSamplerState" );
    n1972 = n1972_1 + 16;
    v45 = ++n608;
    n1972_1 = n1972;
    if ( n1972 < 2004 )
      continue;
    break;
  }
  v51 = v69;
  n1972_1 = 2004;
  v52 = &unk_C85AB4;
  while ( 1 )
  {
    result = sub_A35670(v51, *(v52 - 1), *v52, v52[1]);
    n1972_3 = n1972_1;
    *(_DWORD *)((char *)dword_1A858B4 + n1972_1) = result;
    if ( !result )
      return result;
    v52 += 3;
    n1972_1 = n1972_3 + 4;
    if ( n1972_3 + 4 >= 2028 )
    {
      memset(v73, 0, sizeof(v73));
      v55 = (*(int (__stdcall **)(_DWORD *, _BYTE *, _DWORD *))(*v51 + 80))(v51, v73, dword_1A858B4 + 507);
      if ( v55 >= 0 )
      {
        v56 = 0;
        while ( 2 )
        {
          n2 = 0;
          v70 = v56 != 0;
          do
          {
            memset(v74, 0, sizeof(v74));
            if ( v56 || (v74[0] = 0, n2) )
              v74[0] = 1;
            v74[1] = v70;
            v58 = *v69;
            v74[2] = n2 != 0 ? 2 : 8;
            v74[3] = 0;
            v59 = (*(int (__stdcall **)(_DWORD *, _DWORD *, _DWORD *))(v58 + 84))(
                    v69,
                    v74,
                    &dword_1A858B4[2 * v56 + 508 + n2]);
            if ( v59 < 0 )
            {
              if ( v59 == -2147024882 )
                return IggyGDrawSendWarning(
                         0,
                         "GDraw D3D out of memory in %s%s",
                         "CreateDepthStencilState",
                         &byte_B8FBDB);
              else
                return IggyGDrawSendWarning(
                         0,
                         "GDraw D3D error in %s%s: 0x%08x",
                         "CreateDepthStencilState",
                         &byte_B8FBDB,
                         v59);
            }
            ++n2;
          }
          while ( n2 < 2 );
          if ( ++v56 < 2 )
            continue;
          break;
        }
        dword_1A858B4[609] = sub_A35A70(128, 4);
        dword_1A858B4[610] = sub_A35A70(64, 4);
        dword_1A858B4[611] = sub_A35A70(80, 4);
        dword_1A858B4[612] = sub_A35A70(80, 4);
        dword_1A858B4[613] = sub_A35A70(160, 4);
        v60 = IggyGDrawMallocAnnotated(
                24576,
                "r:\\hg_code\\middleware_w32\\iggysdk\\gdraw\\gdraw_d3d1x_shared.inl",
                2069);
        if ( v60 )
        {
          v79 = 0;
          v80 = 0;
          v81 = 0;
          v67[0] = v60;
          v67[1] = 0;
          v67[2] = 0;
          n24576 = 24576;
          v77 = 1;
          n2_1 = 2;
          n2_2 = 2;
          v62 = (_WORD *)(v60 + 4);
          do
          {
            v63 = n2_2 - 2;
            *(v62 - 1) = n2_2 - 1;
            *v62 = n2_2;
            v62[2] = n2_2;
            v64 = n2_2 + 1;
            n2_2 += 4;
            *(v62 - 2) = v63;
            v62[1] = v63;
            v62[3] = v64;
            v62 += 6;
          }
          while ( (unsigned __int16)n2_2 < 0x2002u );
          v65 = (*(int (__stdcall **)(_DWORD, int *, _DWORD *, _DWORD *))(*(_DWORD *)*dword_1A858B4 + 12))(
                  *dword_1A858B4,
                  &n24576,
                  v67,
                  dword_1A858B4 + 488);
          if ( v65 < 0 )
          {
            if ( v65 == -2147024882 )
              IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "CreateBuffer", " for constants");
            else
              IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "CreateBuffer", " for constants", v65);
            dword_1A858B4[488] = 0;
          }
          return IggyGDrawFree(v60);
        }
        else
        {
          result = (int)dword_1A858B4;
          dword_1A858B4[488] = 0;
        }
      }
      else if ( v55 == -2147024882 )
      {
        return IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "CreateBlendState", &byte_B8FBDB);
      }
      else
      {
        return IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "CreateBlendState", &byte_B8FBDB, v55);
      }
      return result;
    }
  }
}

