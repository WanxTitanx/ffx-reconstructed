// Function: sub_A3B610
// Address: 0xa3b610
// Size: 0x22f
// Prototype: 

_DWORD *__cdecl sub_A3B610(int a1)
{
  _DWORD *v1; // ebx
  _DWORD *v2; // esi
  int n5; // eax
  int v5; // edi
  _DWORD *v6; // eax
  _DWORD *v7; // esi
  int v8; // ebx
  int v9; // ecx
  int v10; // ecx
  const char *CreateTexture2D; // [esp+Ch] [ebp-34h]
  _DWORD v12[11]; // [esp+10h] [ebp-30h] BYREF

  v1 = dword_1A858B4;
  v2 = (_DWORD *)dword_1A858B4[189];
  if ( v2 == dword_1A858B4 + 182 || !v2 )
  {
    v5 = 4 * dword_1A858B4[433] * dword_1A858B4[432];
    if ( dword_1A858B4[164] >= v5 )
    {
      v6 = sub_A39A30((int)(dword_1A858B4 + 164));
      v7 = v6;
      if ( v6 )
      {
        v12[0] = v1[432];
        v12[1] = v1[433];
        v12[2] = 1;
        v12[3] = 1;
        v12[4] = 28;
        v12[5] = 1;
        v12[6] = 0;
        v12[7] = 0;
        v12[8] = 40;
        v12[9] = 0;
        v12[10] = 0;
        *v6 = 0;
        v6[1] = 0;
        v6[2] = 0;
        v8 = (*(int (__stdcall **)(_DWORD, _DWORD *, _DWORD, _DWORD *))(*(_DWORD *)*v1 + 20))(*v1, v12, 0, v6);
        CreateTexture2D = "CreateTexture2D";
        if ( v8 < 0
          || (v8 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD *))(*(_DWORD *)*dword_1A858B4 + 28))(
                     *dword_1A858B4,
                     *v7,
                     0,
                     v7 + 1),
              CreateTexture2D = "CreateTexture2D",
              v8 < 0)
          || (v8 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD *))(*(_DWORD *)*dword_1A858B4 + 36))(
                     *dword_1A858B4,
                     *v7,
                     0,
                     v7 + 2),
              CreateTexture2D = "CreateRenderTargetView",
              v8 < 0) )
        {
          if ( *v7 )
          {
            (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v7 + 8))(*v7);
            *v7 = 0;
          }
          v9 = v7[1];
          if ( v9 )
          {
            (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v9 + 8))(v7[1]);
            v7[1] = 0;
          }
          v10 = v7[2];
          if ( v10 )
          {
            (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v10 + 8))(v7[2]);
            v7[2] = 0;
          }
          sub_A39B00(v7);
          sub_A3C170(v8, CreateTexture2D, " creating rendertarget");
          return 0;
        }
        else
        {
          sub_A39A90((int)v7, v5, 1, 2);
          *(_WORD *)a1 |= 4u;
          ++*(_WORD *)(a1 + 10);
          *(_DWORD *)(a1 + 28) += v5;
          return v7;
        }
      }
      else
      {
        IggyGDrawSendWarning(0, "GDraw rendertarget allocation failed: hit handle limit");
        return 0;
      }
    }
    else
    {
      IggyGDrawSendWarning(0, "GDraw rendertarget allocation failed: hit size limit of %d bytes", dword_1A858B4[165]);
      return 0;
    }
  }
  else
  {
    n5 = v2[12] >> 28;
    if ( n5 != 5 && v2[5] == 1 && n5 == 1 )
      sub_A3A010(v2, 2);
    return v2;
  }
}

