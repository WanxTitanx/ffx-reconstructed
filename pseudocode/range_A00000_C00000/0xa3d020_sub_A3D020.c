// Function: sub_A3D020
// Address: 0xa3d020
// Size: 0x1cc
// Prototype: 

int __cdecl sub_A3D020(int a1, int a2, unsigned __int8 a3, unsigned __int8 a4)
{
  int v4; // esi
  _DWORD *v5; // ebx
  int n32; // eax
  _DWORD *v7; // ecx
  unsigned int v8; // edi
  int n32_1; // ecx
  _DWORD *v10; // edx
  int n32_2; // eax
  int v12; // edi
  int v13; // ecx
  int v14; // eax
  _DWORD *v15; // eax
  int v17; // [esp-Ch] [ebp-60h]
  _DWORD *v18; // [esp+10h] [ebp-44h]
  int v19; // [esp+14h] [ebp-40h]
  int n32_3; // [esp+18h] [ebp-3Ch]
  _BYTE v21[12]; // [esp+1Ch] [ebp-38h] BYREF
  int v22; // [esp+28h] [ebp-2Ch]
  unsigned __int8 v23; // [esp+2Ch] [ebp-28h]
  unsigned __int8 v24; // [esp+2Dh] [ebp-27h]
  int v25; // [esp+30h] [ebp-24h]
  int v26; // [esp+34h] [ebp-20h]
  int n3; // [esp+38h] [ebp-1Ch]
  int n3_1; // [esp+3Ch] [ebp-18h]
  int v29; // [esp+40h] [ebp-14h]
  int v30; // [esp+44h] [ebp-10h]
  int n3_2; // [esp+48h] [ebp-Ch]
  int n3_3; // [esp+4Ch] [ebp-8h]

  v4 = a2 | (2 * (a1 | ((a3 | (a4 << 8)) << 7)));
  v5 = dword_1A858B4;
  ++dword_1A858B4[608];
  n32_3 = 0;
  v19 = v5[608];
  n32 = 0;
  v7 = v5 + 512;
  do
  {
    if ( *v7 == v4 )
    {
      v5[n32 + 576] = v5[608];
      return v5[n32 + 544];
    }
    ++n32;
    ++v7;
  }
  while ( n32 < 32 );
  v8 = 0;
  n32_1 = 0;
  v10 = v5 + 576;
  while ( *(v10 - 32) )
  {
    if ( v19 - *v10 <= v8 )
    {
      n32_2 = n32_3;
    }
    else
    {
      v8 = v19 - *v10;
      n32_2 = n32_1;
      n32_3 = n32_1;
    }
    ++n32_1;
    ++v10;
    if ( n32_1 >= 32 )
      goto LABEL_12;
  }
  n32_2 = n32_1;
  n32_3 = n32_1;
LABEL_12:
  v12 = 4 * n32_2 + 2176;
  v13 = *(_DWORD *)((char *)v5 + v12);
  v18 = (_DWORD *)((char *)v5 + v12);
  if ( v13 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v13 + 8))(v13);
    v5 = dword_1A858B4;
    *v18 = 0;
  }
  v17 = v5[2 * a1 + 508 + a2];
  (*(void (__stdcall **)(int, _BYTE *))(*(_DWORD *)v17 + 28))(v17, v21);
  v23 = a3;
  v24 = a4;
  v22 = 1;
  v25 = 1;
  v26 = 1;
  n3 = 3;
  n3_1 = 3;
  v29 = 1;
  v30 = 1;
  n3_2 = 3;
  n3_3 = 3;
  v14 = (*(int (__stdcall **)(_DWORD, _BYTE *, char *))(*(_DWORD *)*dword_1A858B4 + 84))(
          *dword_1A858B4,
          v21,
          (char *)dword_1A858B4 + v12);
  if ( v14 < 0 )
  {
    if ( v14 == -2147024882 )
      IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "CreateDepthStencilState", &byte_B8FBDB);
    else
      IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "CreateDepthStencilState", &byte_B8FBDB, v14);
  }
  v15 = dword_1A858B4;
  dword_1A858B4[n32_3 + 512] = v4;
  v15[n32_3 + 576] = v19;
  return *(_DWORD *)((char *)v15 + v12);
}

