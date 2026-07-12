// Function: sub_A37C20
// Address: 0xa37c20
// Size: 0x391
// Prototype: 

_DWORD *__stdcall sub_A37C20(int a1, int a2, int a3)
{
  unsigned __int8 n5; // dl
  int v4; // esi
  int v5; // ebx
  int i_3; // eax
  int n28; // eax
  char *v8; // edi
  int v9; // eax
  char *v10; // eax
  int i; // ebx
  int v12; // esi
  int v13; // edx
  int v14; // edx
  char v15; // cl
  int i_2; // ecx
  int v17; // eax
  int v18; // ebx
  int v19; // esi
  int n4_2; // ecx
  int v21; // eax
  int v22; // eax
  const char *CreateTexture2D; // esi
  int v24; // eax
  _DWORD *v25; // ebx
  int i_4; // [esp+Ch] [ebp-178h]
  _DWORD *v28; // [esp+10h] [ebp-174h]
  int v29; // [esp+14h] [ebp-170h]
  char *v30; // [esp+18h] [ebp-16Ch]
  int v31; // [esp+1Ch] [ebp-168h] BYREF
  int v32; // [esp+20h] [ebp-164h]
  int v33; // [esp+24h] [ebp-160h] BYREF
  int n4; // [esp+28h] [ebp-15Ch]
  int n4_1; // [esp+2Ch] [ebp-158h]
  int i_1; // [esp+30h] [ebp-154h]
  _DWORD v37[4]; // [esp+34h] [ebp-150h] BYREF
  int n28_1; // [esp+44h] [ebp-140h]
  int v39; // [esp+48h] [ebp-13Ch]
  int v40; // [esp+4Ch] [ebp-138h]
  int v41; // [esp+50h] [ebp-134h]
  int n8; // [esp+54h] [ebp-130h]
  int v43; // [esp+58h] [ebp-12Ch]
  int v44; // [esp+5Ch] [ebp-128h]
  int v45; // [esp+60h] [ebp-124h] BYREF
  _BYTE v46[284]; // [esp+64h] [ebp-120h] BYREF

  v30 = 0;
  v33 = 0;
  v31 = 0;
  v45 = 0;
  memset(v46, 0, sizeof(v46));
  n5 = *(_BYTE *)(a3 + 4);
  v4 = *(unsigned __int16 *)(a3 + 6);
  v5 = *(unsigned __int16 *)(a3 + 8);
  i_3 = *(unsigned __int8 *)(a3 + 5);
  v32 = v4;
  v29 = v5;
  i_1 = i_3;
  n4_1 = 1;
  v37[0] = v4;
  v37[1] = v5;
  v37[2] = i_3;
  v37[3] = 1;
  n28_1 = 0;
  v39 = 1;
  v40 = 0;
  v41 = 1;
  n8 = 8;
  v43 = 0;
  v44 = 0;
  switch ( n5 )
  {
    case 0u:
      n4 = 4;
      n28 = 28;
      goto LABEL_8;
    case 9u:
      n4 = 8;
      n28 = 71;
      goto LABEL_7;
    case 0xAu:
      n28 = 74;
      goto LABEL_6;
    case 0xBu:
      n28 = 77;
LABEL_6:
      n4 = 16;
LABEL_7:
      n4_1 = 4;
LABEL_8:
      v8 = (char *)(a1 + *(_DWORD *)a3);
      n28_1 = n28;
      if ( n5 != 5 && n5 != 6 )
        goto LABEL_21;
      v9 = sub_A3C0F0(v4, v5, i_1);
      v10 = (char *)IggyGDrawMallocAnnotated(
                      2 * v9,
                      "r:\\hg_code\\middleware_w32\\iggysdk\\gdraw\\gdraw_d3d1x_shared.inl",
                      2475);
      v30 = v10;
      if ( v10 )
      {
        for ( i = 0; i < i_1; ++i )
        {
          v12 = v4 >> i;
          if ( v12 <= 1 )
            v12 = 1;
          v13 = v29 >> i;
          if ( v29 >> i <= 1 )
            v13 = 1;
          v14 = v12 * v13;
          if ( v14 > 0 )
          {
            do
            {
              v15 = *v8;
              v10[1] = *v8;
              *v10 = v15;
              ++v8;
              v10 += 2;
              --v14;
            }
            while ( v14 );
          }
          v4 = v32;
        }
        v8 = v30;
        v5 = v29;
LABEL_21:
        LOBYTE(i_2) = 0;
        i_4 = 0;
        if ( i_1 > 0 )
        {
          v28 = v46;
          do
          {
            v17 = v4 >> i_2;
            if ( v4 >> i_2 <= 1 )
              v17 = 1;
            v18 = v5 >> i_2;
            if ( v18 <= 1 )
              v18 = 1;
            v19 = (n4_1 + v17 - 1) / n4_1;
            *v28 = n4 * v19;
            n4_2 = n4_1;
            *(v28 - 1) = v8;
            v21 = (v18 + n4_2 - 1) / n4_2;
            v28 += 3;
            v5 = v29;
            i_2 = i_4 + 1;
            i_4 = i_2;
            v22 = n4 * v19 * v21;
            v4 = v32;
            v8 += v22;
          }
          while ( i_2 < i_1 );
        }
        CreateTexture2D = "CreateTexture2D";
        v24 = (*(int (__stdcall **)(_DWORD, _DWORD *, int *, int *))(*(_DWORD *)*dword_1A858B4 + 20))(
                *dword_1A858B4,
                v37,
                &v45,
                &v33);
        if ( v24 < 0
          || (CreateTexture2D = "CreateShaderResourceView for texture creation",
              v24 = (*(int (__stdcall **)(_DWORD, int, _DWORD, int *))(*(_DWORD *)*dword_1A858B4 + 28))(
                      *dword_1A858B4,
                      v33,
                      0,
                      &v31),
              v24 < 0) )
        {
          if ( v24 == -2147024882 )
            IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", CreateTexture2D, &byte_B8FBDB);
          else
            IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", CreateTexture2D, &byte_B8FBDB, v24);
          v25 = 0;
        }
        else
        {
          v25 = (_DWORD *)sub_A383A0(v31);
        }
        if ( v30 )
          IggyGDrawFree(v30);
        if ( v25 )
        {
          *v25 = v33;
          return v25;
        }
      }
      else
      {
        IggyGDrawSendWarning(0, "GDraw out of memory to store texture data to pass to D3D for %d x %d texture", v4, v5);
LABEL_40:
        v25 = 0;
      }
      if ( v31 )
        (*(void (__stdcall **)(int))(*(_DWORD *)v31 + 8))(v31);
      if ( v33 )
        (*(void (__stdcall **)(int))(*(_DWORD *)v33 + 8))(v33);
      return v25;
    default:
      IggyGDrawSendWarning(0, "GDraw .iggytex raw texture format %d not supported by hardware", n5);
      goto LABEL_40;
  }
}

