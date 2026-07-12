// Function: sub_A3A5F0
// Address: 0xa3a5f0
// Size: 0x1a2
// Prototype: 

_DWORD *__stdcall sub_A3A5F0(_DWORD *a1, int a2)
{
  _DWORD *v2; // edi
  int v3; // eax
  int v4; // esi
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  _DWORD v9[3]; // [esp+Ch] [ebp-4Ch] BYREF
  _DWORD v10[3]; // [esp+18h] [ebp-40h] BYREF
  _DWORD v11[6]; // [esp+24h] [ebp-34h] BYREF
  _DWORD v12[6]; // [esp+3Ch] [ebp-1Ch] BYREF

  v11[0] = a1[2];
  v9[0] = *a1;
  v2 = (_DWORD *)a1[4];
  v12[0] = a1[3];
  v10[0] = a1[1];
  v3 = *dword_1A858B4;
  v11[1] = 1;
  v11[2] = 1;
  memset(&v11[3], 0, 12);
  v9[1] = 0;
  v9[2] = 0;
  v12[1] = 1;
  v12[2] = 2;
  memset(&v12[3], 0, 12);
  v10[1] = 0;
  v10[2] = 0;
  v4 = (*(int (__stdcall **)(int, _DWORD *, _DWORD *, _DWORD *))(*(_DWORD *)v3 + 12))(v3, v11, v9, v2);
  if ( v4 < 0
    || (v4 = (*(int (__stdcall **)(_DWORD, _DWORD *, _DWORD *, _DWORD *))(*(_DWORD *)*dword_1A858B4 + 12))(
               *dword_1A858B4,
               v12,
               v10,
               v2 + 1),
        v4 < 0) )
  {
    if ( *v2 )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v2 + 8))(*v2);
      *v2 = 0;
    }
    v5 = v2[1];
    if ( v5 )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 8))(v2[1]);
      v2[1] = 0;
    }
    v6 = v2[6];
    *(_DWORD *)(v2[8] + 28) = v2[7];
    *(_DWORD *)(v2[7] + 32) = v2[8];
    v6 += 16;
    v2[7] = v6;
    v7 = *(_DWORD *)(v6 + 32);
    v2[8] = v7;
    *(_DWORD *)(v7 + 28) = v2;
    *(_DWORD *)(v2[7] + 32) = v2;
    v2[12] &= 0xFFFFFFFu;
    v2 = 0;
    if ( v4 == -2147024882 )
      IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "CreateBuffer", " creating vertex buffer");
    else
      IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "CreateBuffer", " creating vertex buffer", v4);
  }
  else
  {
    sub_A39A90((int)v2, a1[3] + a1[2], a1[5], 2);
  }
  IggyGDrawFree(*a1);
  IggyGDrawFree(a1[1]);
  return v2;
}

