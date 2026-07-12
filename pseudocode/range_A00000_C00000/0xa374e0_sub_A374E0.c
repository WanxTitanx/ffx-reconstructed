// Function: sub_A374E0
// Address: 0xa374e0
// Size: 0x428
// Prototype: 

int __usercall sub_A374E0@<eax>(int a1@<ebx>, int a2@<edi>, int a3, int *a4, int a5, int a6)
{
  int *v6; // esi
  int result; // eax
  int v8; // ebx
  _DWORD *v9; // ecx
  _DWORD *v10; // edi
  int v11; // ecx
  int *v12; // ebx
  int v13; // esi
  float v14; // ecx
  int v15; // edx
  int v16; // eax
  int v17; // ebx
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  float v21; // eax
  int v22; // eax
  _DWORD *v23; // ecx
  int v24; // esi
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  _DWORD *v28; // esi
  int v29; // esi
  int v30; // eax
  void *dst; // edi
  _DWORD *v32; // eax
  int v33; // edx
  int v34; // eax
  _DWORD *v35; // ecx
  int v36; // edx
  bool v37; // zf
  int *v38; // esi
  float v39; // [esp+5Ch] [ebp-3Ch]
  float v40; // [esp+60h] [ebp-38h]
  float v41; // [esp+64h] [ebp-34h]
  _DWORD v44[4]; // [esp+74h] [ebp-24h] BYREF
  int v45; // [esp+84h] [ebp-14h] BYREF
  int v46; // [esp+88h] [ebp-10h] BYREF
  float v47; // [esp+8Ch] [ebp-Ch]
  int v48; // [esp+90h] [ebp-8h]
  int v49; // [esp+94h] [ebp-4h]

  v6 = (int *)(dword_1A858B4[683] + 28);
  if ( !dword_1A858B4[438] || !dword_1A858B4[439] )
    return IggyGDrawSendWarning(0, "GDraw warning: w=0,h=0 rendertarget");
  if ( v6 >= dword_1A858B4 + 683 )
    return IggyGDrawSendWarning(0, "GDraw rendertarget nesting exceeds MAX_RENDER_STACK_DEPTH");
  result = sub_A3B610(a6);
  v8 = result;
  v45 = result;
  if ( result )
  {
    v9 = dword_1A858B4;
    v6[5] = 3;
    *v6 = result;
    v9[683] += 28;
    *(_DWORD *)(v9[683] + 24) = 0;
    sub_A3C570(a6);
    v10 = dword_1A858B4;
    v11 = v8;
    v12 = a4;
    v13 = (v11 - (int)dword_1A858B4 - 1080) / 56;
    if ( a4 )
    {
      if ( dword_1A858B4[446] )
      {
        v14 = 0.0;
        v15 = 0;
      }
      else
      {
        v15 = dword_1A858B4[444];
        v14 = *((float *)dword_1A858B4 + 445);
      }
      v16 = *a4 - v15;
      v47 = v14;
      v48 = v15;
      v17 = v16 <= 0 ? 0 : v16;
      v18 = (a4[1] - LODWORD(v14)) & ((a4[1] - LODWORD(v14) <= 0) - 1);
      v46 = v18;
      v49 = a4[2] - v15;
      if ( v49 >= dword_1A858B4[440] )
        v49 = dword_1A858B4[440];
      v19 = dword_1A858B4[441];
      v48 = a4[3] - LODWORD(v47);
      if ( v48 >= v19 )
        v48 = v19;
      v44[0] = (v17 - 2) & ((v17 - 2 <= 0) - 1);
      v20 = (v18 - 2) & ((v18 - 2 <= 0) - 1);
      LODWORD(v21) = v49 + 2;
      v44[1] = v20;
      LODWORD(v47) = v49 + 2;
      if ( v49 + 2 >= dword_1A858B4[432] )
      {
        v21 = *((float *)dword_1A858B4 + 432);
        v47 = v21;
      }
      *(float *)&v44[2] = v21;
      v22 = v48 + 2;
      if ( v48 + 2 >= dword_1A858B4[433] )
        v22 = dword_1A858B4[433];
      v44[3] = v22;
      if ( SLODWORD(v47) <= ((v17 - 2) & ((v17 - 2 <= 0) - 1)) || v22 <= v20 )
      {
        v26 = v45;
        dword_1A858B4[683] -= 28;
        if ( *(_DWORD **)(v26 + 24) == v10 + 164 )
          return sub_A39F00(v26);
        else
          return sub_A3B480(v26, a6);
      }
      sub_A3BD40(v44, a6);
      v23 = dword_1A858B4;
      dword_1A858B4[4 * v13 + 396] = v17;
      v12 = a4;
      v24 = 2 * v13;
      v23[2 * v24 + 397] = v46;
      v23[2 * v24 + 398] = v49;
      v25 = v48;
    }
    else
    {
      (*(void (__stdcall **)(_DWORD, _DWORD, void *))(*(_DWORD *)dword_1A858B4[1] + 200))(
        dword_1A858B4[1],
        *(_DWORD *)(*(_DWORD *)dword_1A858B4[683] + 8),
        &unk_B7A3F8);
      v23 = dword_1A858B4;
      v27 = 2 * (v13 + 99);
      v24 = 2 * v13;
      dword_1A858B4[2 * v27] = 0;
      v23[2 * v24 + 397] = 0;
      v23[2 * v24 + 398] = v23[432];
      v25 = v23[433];
    }
    v23[2 * v24 + 399] = v25;
    if ( v23[446] )
    {
      sub_A3CE00(0, 0, v23[440], v23[441]);
      v28 = dword_1A858B4;
      sub_A3C450(0, dword_1A858B4[440], dword_1A858B4[441], 0);
    }
    else
    {
      sub_A3CD30();
      sub_A3C350();
      v28 = dword_1A858B4;
    }
    v29 = v28[1];
    v30 = *(_DWORD *)(a3 + 28);
    if ( v30 )
    {
      (*(void (__stdcall **)(int, _DWORD, int, int, int, int))(*(_DWORD *)v29 + 32))(v29, 0, 1, v30 + 4, a2, a1);
      (*(void (__stdcall **)(int, _DWORD, int, _DWORD *))(*(_DWORD *)v29 + 40))(v29, 0, 1, dword_1A858B4 + 493);
    }
    else
    {
      v45 = 0;
      (*(void (__stdcall **)(int, _DWORD, int, int *, int, int))(*(_DWORD *)v29 + 32))(v29, 0, 1, &v45, a2, a1);
    }
    (*(void (__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 36))(dword_1A858B4[1], dword_1A858B4[149]);
    dst = (void *)sub_A3CEC0(dword_1A858B4[612]);
    v32 = dword_1A858B4;
    qmemcpy(dst, (const void *)(a3 + 136), 0x50u);
    v33 = v32[612];
    v34 = v32[1];
    v46 = v33;
    (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v34 + 60))(v34, v33, 0);
    (*(void (__stdcall **)(_DWORD, int, int, int *))(*(_DWORD *)dword_1A858B4[1] + 64))(dword_1A858B4[1], 1, 1, &v46);
    v47 = (float)v12[3];
    v41 = v47;
    v47 = (float)v12[2];
    v40 = v47;
    v47 = (float)v12[1];
    v39 = v47;
    v47 = (float)*v12;
    sub_A36090(a5, a6, v47, v39, v40, v41);
    v35 = dword_1A858B4;
    v36 = *(_DWORD *)(a3 + 28);
    if ( v36 )
    {
      *(_DWORD *)(v36 + 40) = dword_1A858B4[688];
      *(_DWORD *)(v36 + 44) = v35[689];
    }
    v37 = v35[438] == 0;
    v38 = (int *)v35[683];
    v35[683] = v38 - 7;
    if ( v37 || !v35[439] || v38 >= v35 + 683 )
    {
      *(_DWORD *)(a3 + 28) = 0;
      return 0;
    }
    else
    {
      sub_A3C570(a6);
      sub_A3CD30();
      sub_A3C350();
      result = *v38;
      *(_DWORD *)(a3 + 28) = *v38;
    }
  }
  return result;
}

