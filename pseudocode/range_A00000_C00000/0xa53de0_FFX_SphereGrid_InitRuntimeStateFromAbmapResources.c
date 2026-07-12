// Function: FFX_SphereGrid_InitRuntimeStateFromAbmapResources
// Address: 0xa53de0
// Size: 0x77d
// Prototype: int __cdecl(__int16 *)

// [Jarvis naming goal 2026-06-17] Seeds/rebuilds Sphere Grid runtime state from ABMAP resources 17/18/19.
int __cdecl FFX_SphereGrid_InitRuntimeStateFromAbmapResources(__int16 *n7_2)
{
  __int16 *n7_3; // edi
  int *v2; // ebx
  int i; // ebx
  void *v4; // eax
  int v5; // edi
  size_t nNumberOfBytesToRead; // esi
  void *lpBuffer; // eax
  int v8; // eax
  void (__cdecl **CoreWorkPtr)(int); // esi
  int v10; // edx
  int v11; // ecx
  int n7; // esi
  int v13; // eax
  unsigned __int16 *v14; // eax
  unsigned __int16 v15; // dx
  __int16 *v16; // edi
  int j; // ecx
  int v18; // eax
  __int16 v19; // ax
  _DWORD v21[6]; // [esp+Ch] [ebp-7A4h]
  int v22; // [esp+24h] [ebp-78Ch]
  int v23; // [esp+28h] [ebp-788h]
  int v24; // [esp+2Ch] [ebp-784h]
  int v25; // [esp+30h] [ebp-780h]
  int v26; // [esp+34h] [ebp-77Ch]
  int v27; // [esp+38h] [ebp-778h]
  int v28; // [esp+3Ch] [ebp-774h]
  int v29; // [esp+40h] [ebp-770h]
  int v30; // [esp+44h] [ebp-76Ch]
  int v31; // [esp+48h] [ebp-768h]
  int v32; // [esp+50h] [ebp-760h]
  int v33; // [esp+54h] [ebp-75Ch]
  int v34; // [esp+58h] [ebp-758h]
  int v35; // [esp+5Ch] [ebp-754h]
  int v36; // [esp+60h] [ebp-750h]
  int v37; // [esp+64h] [ebp-74Ch]
  int v38; // [esp+68h] [ebp-748h]
  int v39; // [esp+6Ch] [ebp-744h]
  int v40; // [esp+70h] [ebp-740h]
  int v41; // [esp+74h] [ebp-73Ch]
  int v42; // [esp+78h] [ebp-738h]
  int v43; // [esp+7Ch] [ebp-734h]
  int v44; // [esp+80h] [ebp-730h]
  int v45; // [esp+84h] [ebp-72Ch]
  int v46; // [esp+88h] [ebp-728h]
  int v47; // [esp+8Ch] [ebp-724h]
  int v48; // [esp+90h] [ebp-720h]
  int v49; // [esp+94h] [ebp-71Ch]
  int v50; // [esp+98h] [ebp-718h]
  int v51; // [esp+9Ch] [ebp-714h]
  int v52; // [esp+A0h] [ebp-710h]
  int v53; // [esp+A4h] [ebp-70Ch]
  int v54; // [esp+A8h] [ebp-708h]
  int v55; // [esp+ACh] [ebp-704h]
  int v56; // [esp+B0h] [ebp-700h]
  int v57; // [esp+B4h] [ebp-6FCh]
  int v58; // [esp+B8h] [ebp-6F8h]
  int v59; // [esp+BCh] [ebp-6F4h]
  int v60; // [esp+C0h] [ebp-6F0h]
  int v61; // [esp+C4h] [ebp-6ECh]
  int v62; // [esp+C8h] [ebp-6E8h]
  int v63; // [esp+CCh] [ebp-6E4h]
  int v64; // [esp+D0h] [ebp-6E0h]
  int v65; // [esp+D4h] [ebp-6DCh]
  int v66; // [esp+D8h] [ebp-6D8h]
  int v67; // [esp+DCh] [ebp-6D4h]
  int v68; // [esp+E0h] [ebp-6D0h]
  int v69; // [esp+E4h] [ebp-6CCh]
  int v70; // [esp+E8h] [ebp-6C8h]
  int v71; // [esp+ECh] [ebp-6C4h]
  int v72; // [esp+F0h] [ebp-6C0h]
  int v73; // [esp+F4h] [ebp-6BCh]
  int v74; // [esp+F8h] [ebp-6B8h]
  int v75; // [esp+FCh] [ebp-6B4h]
  int v76; // [esp+100h] [ebp-6B0h]
  int v77; // [esp+104h] [ebp-6ACh]
  int v78; // [esp+108h] [ebp-6A8h]
  int v79; // [esp+10Ch] [ebp-6A4h]
  int v80; // [esp+110h] [ebp-6A0h]
  int v81; // [esp+114h] [ebp-69Ch]
  int v82; // [esp+118h] [ebp-698h]
  int v83; // [esp+11Ch] [ebp-694h]
  int v84; // [esp+120h] [ebp-690h]
  int *v85; // [esp+124h] [ebp-68Ch]
  __int16 *n7_1; // [esp+128h] [ebp-688h]
  __int16 n49; // [esp+12Ch] [ebp-684h] BYREF
  unsigned __int16 v88; // [esp+12Eh] [ebp-682h]
  _BYTE v89[1144]; // [esp+134h] [ebp-67Ch]
  char v90[256]; // [esp+5ACh] [ebp-204h] BYREF
  char Buffer[256]; // [esp+6ACh] [ebp-104h] BYREF

  n7_3 = n7_2;
  n7_1 = n7_2;
  v2 = (int *)sub_785350();
  v85 = v2;
  if ( !unk_1A85F60 )
  {
    for ( i = 0; i < 70; ++i )
    {
      sprintf(Buffer, "%s/%s", "/ffx_ps2/ffx/eiichi_abmap_data", off_C85EF0[i]);// "par/dna.pdt"
      FFX_FileIO_UnifyFilename(Buffer, v90, 256);
      sprintf_s(Buffer, 0xFEu, "%s", v90);
      v4 = FFX_FileIO_DeviceOpen((char)Buffer, 1);
      v5 = (int)v4;
      if ( v4 )
      {
        nNumberOfBytesToRead = sub_6798C0((int)v4, 0, 2u);
        sub_6798C0(v5, 0, 0);
        lpBuffer = (void *)sub_687190(nNumberOfBytesToRead, (void *)0x10);
        v21[i] = lpBuffer;
        FFX_FileIO_DeviceRead(v5, lpBuffer, nNumberOfBytesToRead);
        FFX_FileIO_DeviceClose(v5);
      }
      nullsub_34();
    }
    dword_2305800 = (_BYTE *)v21[0];
    unk_23057FC = v21[1];
    unk_23057F8 = v21[2];
    unk_23057F4 = v21[3];
    unk_23057F0 = v21[4];
    unk_23057EC = v21[5];
    unk_23057E8 = v22;
    unk_23057E4 = v23;
    unk_23057CC = v29;
    unk_1A85F94 = v29;
    unk_23057C8 = v30;
    unk_1A85FE4 = v30;
    unk_23057C4 = v31;
    unk_23057BC = v32;
    unk_23057B8 = v33;
    unk_23057B4 = v34;
    unk_23057B0 = v35;
    unk_23057AC = v36;
    unk_23057A8 = v37;
    unk_23057A4 = v38;
    unk_23057A0 = v39;
    unk_230579C = v40;
    unk_2305798 = v41;
    unk_23057E0 = v24;
    unk_2305794 = v42;
    dword_1A85F78[0] = v22;
    unk_2305790 = v43;
    unk_1A85F7C = v23;
    unk_23057DC = v25;
    unk_23057D8 = v26;
    unk_23057D4 = v27;
    unk_23057D0 = v28;
    unk_1A85F84 = v25;
    unk_1A85F88 = v26;
    unk_1A85F8C = v27;
    unk_1A85F90 = v28;
    unk_230578C = v44;
    unk_1A85F80 = v24;
    unk_2305788 = v45;
    unk_2305784 = v46;
    unk_2305780 = v47;
    unk_230577C = v48;
    unk_2305778 = v49;
    unk_2305770 = v51;
    unk_230576C = v52;
    unk_2305768 = v53;
    unk_2305764 = v54;
    unk_2305760 = v55;
    unk_230575C = v56;
    unk_2305758 = v57;
    unk_2305754 = v58;
    unk_2305750 = v59;
    unk_230574C = v60;
    unk_2305748 = v61;
    unk_2305744 = v62;
    unk_2305740 = v63;
    unk_1A85F98 = v45;
    unk_1A85FB0 = v51;
    unk_1A85FB4 = v52;
    unk_1A85FB8 = v53;
    unk_1A85FBC = v54;
    unk_1A85FC0 = v55;
    unk_1A85FC4 = v56;
    unk_1A85FC8 = v57;
    unk_1A85FCC = v58;
    unk_1A85FD0 = v59;
    unk_1A85FD4 = v60;
    unk_1A85FD8 = v61;
    unk_1A85FDC = v62;
    unk_1A85FE0 = v63;
    unk_230573C = v64;
    unk_2305724 = v70;
    unk_2305720 = v71;
    unk_230571C = v72;
    unk_2305774 = v50;
    unk_1A85F9C = v46;
    unk_1A85FA0 = v47;
    unk_1A85FA4 = v48;
    unk_1A85FA8 = v49;
    unk_1A85FAC = v50;
    unk_2305718 = v73;
    unk_2305738 = v65;
    unk_2305734 = v66;
    unk_2305730 = v67;
    unk_230572C = v68;
    unk_2305728 = v69;
    unk_2305714 = v74;
    unk_2305710 = v75;
    unk_230570C = v76;
    unk_2305708 = v77;
    unk_2305704 = v78;
    unk_2305700 = v79;
    unk_23056FC = v80;
    unk_23056F8 = v81;
    unk_23056F4 = v82;
    unk_1A85FE8 = v64;
    unk_1A86000 = v70;
    unk_1A86004 = v71;
    unk_1A86008 = v72;
    unk_1A8600C = v73;
    unk_1A86010 = v74;
    unk_1A86014 = v75;
    unk_1A86018 = v76;
    unk_1A8601C = v77;
    unk_1A86020 = v78;
    unk_1A86024 = v79;
    unk_1A86028 = v80;
    unk_1A8602C = v81;
    unk_1A86030 = v82;
    unk_23056F0 = v83;
    unk_1A85FF8 = v68;
    n7_3 = n7_1;
    unk_1A85FFC = v69;
    v2 = v85;
    unk_1A85FEC = v65;
    unk_1A85FF0 = v66;
    unk_1A85FF4 = v67;
    unk_23056EC = v84;
    unk_1A85F60 = 1;
  }
  v8 = (*v2 >> 14) & 3;
  unk_1A85F70 = 0;
  if ( v8 )
  {
    if ( v8 == 1 )
    {
      CoreWorkPtr = (void (__cdecl **)(int))FFX_Btl_GetCoreWorkPtr();
      CoreWorkPtr[4](37);
      ((void (__cdecl *)(int, __int16 *, _DWORD, _DWORD))*CoreWorkPtr)(18, &n49, 0, 0);
    }
    else
    {
      CoreWorkPtr = (void (__cdecl **)(int))FFX_Btl_GetCoreWorkPtr();
      CoreWorkPtr[4](37);
      ((void (__cdecl *)(int, __int16 *, _DWORD, _DWORD))*CoreWorkPtr)(19, &n49, 0, 0);
    }
  }
  else
  {
    CoreWorkPtr = (void (__cdecl **)(int))FFX_Btl_GetCoreWorkPtr();
    CoreWorkPtr[4](37);
    ((void (__cdecl *)(int, __int16 *, _DWORD, _DWORD))*CoreWorkPtr)(17, &n49, 0, 0);
  }
  CoreWorkPtr[2](0);
  memset(n7_3, 0, 0x1320u);
  if ( n49 == 49 )
  {
    v10 = v88;
    v11 = 0;
    if ( v88 )
    {
      do
      {
        LOBYTE(n7_3[v11]) = v89[v11];
        ++v11;
      }
      while ( v11 < v10 );
    }
  }
  n7 = 0;
  n7_1 = 0;
  do
  {
    v13 = (*v2 >> 14) & 3;
    if ( v13 )
    {
      if ( v13 == 1 )
        v14 = (unsigned __int16 *)*(&off_C86CA4 + n7);
      else
        v14 = (unsigned __int16 *)*(&off_C86CEC + n7);
    }
    else
    {
      v14 = (unsigned __int16 *)*(&off_C86C5C + n7);
    }
    v15 = *v14;
    if ( *v14 != 0xFFFF )
    {
      do
      {
        HIBYTE(n7_3[v15]) |= 1 << n7;
        v15 = v14[1];
        ++v14;
      }
      while ( v15 != 0xFFFF );
      n7 = (int)n7_1;
      v2 = v85;
    }
    n7_1 = (__int16 *)++n7;
  }
  while ( n7 < 7 );
  v16 = n7_3 + 1920;
  for ( j = 0; j < 7; ++j )
  {
    v18 = (*v2 >> 14) & 3;
    if ( v18 )
    {
      if ( v18 == 1 )
        v19 = word_C86C10[j];
      else
        v19 = word_C86C20[j];
    }
    else
    {
      v19 = word_C86C00[j];
    }
    *v16++ = v19;
  }
  return FFX_Abmap_RecomputePartyStatsAndLearnedMoves();
}

