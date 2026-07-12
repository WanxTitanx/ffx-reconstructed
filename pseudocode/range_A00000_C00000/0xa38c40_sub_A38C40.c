// Function: sub_A38C40
// Address: 0xa38c40
// Size: 0x5bc
// Prototype: 

int __usercall sub_A38C40@<eax>(int a1@<ebx>, int a2@<edi>, int a3, int *a4, int a5, int a6, int a7)
{
  int *v7; // esi
  int result; // eax
  int v9; // ebx
  _DWORD *v10; // ecx
  _DWORD *v11; // edi
  int v12; // esi
  int v13; // ecx
  float v14; // ebx
  int v15; // eax
  int v16; // ebx
  int v17; // eax
  int v18; // ecx
  float v19; // eax
  float v20; // edx
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  float *v24; // ecx
  int v25; // esi
  float v26; // eax
  int v27; // ecx
  int v28; // eax
  _DWORD *v29; // esi
  int v30; // esi
  int v31; // eax
  int v32; // edx
  int *v33; // esi
  int v34; // eax
  int v35; // edx
  int *v36; // esi
  int v37; // eax
  float *v38; // esi
  _DWORD *v39; // eax
  double v40; // st7
  double v41; // st7
  _DWORD *v42; // eax
  int v43; // edx
  int v44; // eax
  int v45; // esi
  int v46; // eax
  int v47; // ecx
  _DWORD *v48; // edx
  int v49; // edi
  int v50; // ebx
  float v51; // edx
  float v52; // ecx
  bool v53; // zf
  int *v54; // edi
  float v55; // [esp+9Ch] [ebp-44h]
  float v56; // [esp+A0h] [ebp-40h]
  float v57; // [esp+A4h] [ebp-3Ch]
  _DWORD v60[4]; // [esp+B4h] [ebp-2Ch] BYREF
  int v61; // [esp+C4h] [ebp-1Ch] BYREF
  float v62; // [esp+C8h] [ebp-18h]
  int v63; // [esp+CCh] [ebp-14h] BYREF
  int v64; // [esp+D0h] [ebp-10h] BYREF
  int v65; // [esp+D4h] [ebp-Ch] BYREF
  float v66; // [esp+D8h] [ebp-8h]
  float v67; // [esp+DCh] [ebp-4h]

  v7 = (int *)(dword_1A858B4[683] + 28);
  if ( !dword_1A858B4[438] || !dword_1A858B4[439] )
    return IggyGDrawSendWarning(0, "GDraw warning: w=0,h=0 rendertarget");
  if ( v7 >= dword_1A858B4 + 683 )
    return IggyGDrawSendWarning(0, "GDraw rendertarget nesting exceeds MAX_RENDER_STACK_DEPTH");
  result = sub_A3B610(a7);
  v9 = result;
  v63 = result;
  if ( result )
  {
    v10 = dword_1A858B4;
    v7[5] = 3;
    *v7 = result;
    v10[683] += 28;
    *(_DWORD *)(v10[683] + 24) = 0;
    sub_A3C570(a7);
    v11 = dword_1A858B4;
    v12 = (v9 - (int)dword_1A858B4 - 1080) / 56;
    if ( a4 )
    {
      if ( dword_1A858B4[446] )
      {
        v13 = 0;
        v14 = 0.0;
      }
      else
      {
        v14 = *((float *)dword_1A858B4 + 444);
        v13 = dword_1A858B4[445];
      }
      v15 = *a4 - LODWORD(v14);
      v66 = v14;
      v65 = v13;
      v16 = v15 <= 0 ? 0 : v15;
      v17 = a4[1];
      LODWORD(v67) = a4[2] - LODWORD(v66);
      v18 = (v17 - v13) & ((v17 - v13 <= 0) - 1);
      v19 = *((float *)dword_1A858B4 + 440);
      v64 = v18;
      if ( SLODWORD(v67) >= SLODWORD(v19) )
        v67 = v19;
      v20 = *((float *)dword_1A858B4 + 441);
      LODWORD(v66) = a4[3] - v65;
      if ( SLODWORD(v66) >= SLODWORD(v20) )
        v66 = v20;
      v60[0] = (v16 - 2) & ((v16 - 2 <= 0) - 1);
      v21 = (v18 - 2) & ((v18 - 2 <= 0) - 1);
      v22 = LODWORD(v67) + 2;
      v60[1] = v21;
      v65 = LODWORD(v67) + 2;
      if ( LODWORD(v67) + 2 >= dword_1A858B4[432] )
      {
        v22 = dword_1A858B4[432];
        v65 = v22;
      }
      v60[2] = v22;
      v23 = LODWORD(v66) + 2;
      if ( LODWORD(v66) + 2 >= dword_1A858B4[433] )
        v23 = dword_1A858B4[433];
      v60[3] = v23;
      if ( v65 <= ((v16 - 2) & ((v16 - 2 <= 0) - 1)) || v23 <= v21 )
      {
        v27 = v63;
        dword_1A858B4[683] -= 28;
        if ( *(_DWORD **)(v27 + 24) == v11 + 164 )
          return sub_A39F00(v27);
        else
          return sub_A3B480(v27, a7);
      }
      sub_A3BD40(v60, a7);
      v24 = (float *)dword_1A858B4;
      dword_1A858B4[4 * v12 + 396] = v16;
      v25 = 2 * v12;
      LODWORD(v24[2 * v25 + 397]) = v64;
      v24[2 * v25 + 398] = v67;
      v26 = v66;
    }
    else
    {
      (*(void (__stdcall **)(_DWORD, _DWORD, void *))(*(_DWORD *)dword_1A858B4[1] + 200))(
        dword_1A858B4[1],
        *(_DWORD *)(*(_DWORD *)dword_1A858B4[683] + 8),
        &unk_B7A3F8);
      v24 = (float *)dword_1A858B4;
      v28 = 2 * (v12 + 99);
      v25 = 2 * v12;
      dword_1A858B4[2 * v28] = 0;
      v24[2 * v25 + 397] = 0.0;
      v24[2 * v25 + 398] = v24[432];
      v26 = v24[433];
    }
    v24[2 * v25 + 399] = v26;
    if ( *((_DWORD *)v24 + 446) )
    {
      sub_A3CE00(0, 0, *((_DWORD *)v24 + 440), *((_DWORD *)v24 + 441));
      v29 = dword_1A858B4;
      sub_A3C450(0, dword_1A858B4[440], dword_1A858B4[441], 0);
    }
    else
    {
      sub_A3CD30();
      sub_A3C350();
      v29 = dword_1A858B4;
    }
    v30 = v29[1];
    v31 = *(_DWORD *)(a3 + 28);
    if ( v31 )
    {
      (*(void (__stdcall **)(int, _DWORD, int, int, int, int))(*(_DWORD *)v30 + 32))(v30, 0, 1, v31 + 4, a2, a1);
      (*(void (__stdcall **)(int, _DWORD, int, _DWORD *))(*(_DWORD *)v30 + 40))(v30, 0, 1, dword_1A858B4 + 493);
    }
    else
    {
      v63 = 0;
      (*(void (__stdcall **)(int, _DWORD, int, int *, int, int))(*(_DWORD *)v30 + 32))(v30, 0, 1, &v63, a2, a1);
    }
    v32 = *(_DWORD *)(a3 + 32);
    v33 = (int *)dword_1A858B4[1];
    if ( v32 )
    {
      (*(void (__stdcall **)(int *, int, int, int))(*v33 + 32))(v33, 1, 1, v32 + 4);
      (*(void (__stdcall **)(int *, int, int, _DWORD *))(*v33 + 40))(v33, 1, 1, dword_1A858B4 + 493);
    }
    else
    {
      v34 = *v33;
      v64 = 0;
      (*(void (__stdcall **)(int *, int, int, int *))(v34 + 32))(v33, 1, 1, &v64);
    }
    v35 = *(_DWORD *)(a3 + 36);
    v36 = (int *)dword_1A858B4[1];
    if ( v35 )
    {
      (*(void (__stdcall **)(int *, int, int, int))(*v36 + 32))(v36, 2, 1, v35 + 4);
      (*(void (__stdcall **)(int *, int, int, _DWORD *))(*v36 + 40))(v36, 2, 1, dword_1A858B4 + 493);
    }
    else
    {
      v37 = *v36;
      v65 = 0;
      (*(void (__stdcall **)(int *, int, int, int *))(v37 + 32))(v36, 2, 1, &v65);
    }
    (*(void (__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 36))(
      dword_1A858B4[1],
      dword_1A858B4[32 * a6 + 65 + 2 * *(unsigned __int8 *)(a3 + 15)]);
    v38 = (float *)sub_A3CEC0(dword_1A858B4[611]);
    sub_A3C1B0(v38, *(_DWORD *)(a3 + 28));
    sub_A3C1B0(v38 + 4, *(_DWORD *)(a3 + 32));
    v66 = *(float *)(a3 + 140);
    v39 = dword_1A858B4;
    v67 = *(float *)(a3 + 144);
    v62 = *(float *)(a3 + 148);
    v38[8] = *(float *)(a3 + 136);
    v38[9] = v66;
    v38[10] = v67;
    v38[11] = v62;
    v62 = *(float *)(a3 + 172);
    v66 = *(float *)(a3 + 176);
    v67 = *(float *)(a3 + 180);
    v38[12] = *(float *)(a3 + 168);
    v38[13] = v62;
    v38[14] = v66;
    v38[15] = v67;
    v40 = -*(float *)(a3 + 156);
    v62 = (float)(int)v39[433];
    v66 = v40 / v62;
    v67 = *(float *)(a3 + 160);
    v41 = -*(float *)(a3 + 152);
    v62 = (float)(int)dword_1A858B4[432];
    v42 = dword_1A858B4;
    v38[16] = v41 / v62;
    v38[17] = v66;
    v38[18] = v67;
    v38[19] = 0.0;
    v43 = v42[611];
    v44 = v42[1];
    v61 = v43;
    (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v44 + 60))(v44, v43, 0);
    (*(void (__stdcall **)(_DWORD, int, int, int *))(*(_DWORD *)dword_1A858B4[1] + 64))(dword_1A858B4[1], 1, 1, &v61);
    v45 = a7;
    v62 = (float)a4[3];
    v57 = v62;
    v62 = (float)a4[2];
    v56 = v62;
    v62 = (float)a4[1];
    v55 = v62;
    v62 = (float)*a4;
    sub_A36090(a5, a7, v62, v55, v56, v57);
    v46 = *(_DWORD *)(a3 + 36);
    v47 = *(_DWORD *)(a3 + 32);
    v66 = *(float *)(a3 + 28);
    v48 = dword_1A858B4;
    v49 = dword_1A858B4[688];
    v67 = *((float *)dword_1A858B4 + 689);
    v50 = a3;
    if ( v66 != 0.0 )
    {
      v51 = v66;
      *(_DWORD *)(LODWORD(v66) + 40) = v49;
      *(float *)(LODWORD(v51) + 44) = v67;
      v50 = a3;
      v48 = dword_1A858B4;
    }
    if ( v47 )
    {
      *(float *)(v47 + 44) = v67;
      v45 = a7;
      *(_DWORD *)(v47 + 40) = v49;
    }
    if ( v46 )
    {
      v52 = v67;
      *(_DWORD *)(v46 + 40) = v49;
      *(float *)(v46 + 44) = v52;
    }
    v53 = v48[438] == 0;
    v54 = (int *)v48[683];
    v48[683] = v54 - 7;
    if ( v53 || !v48[439] || v54 >= v48 + 683 )
    {
      *(_DWORD *)(v50 + 28) = 0;
      return 0;
    }
    else
    {
      sub_A3C570(v45);
      sub_A3CD30();
      sub_A3C350();
      result = *v54;
      *(_DWORD *)(v50 + 28) = *v54;
    }
  }
  return result;
}

