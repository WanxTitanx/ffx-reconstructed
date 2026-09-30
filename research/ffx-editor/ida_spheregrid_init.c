// FFX SphereGrid: Init runtime state from abmap resources
// Sphere Grid runtime state initializer. Loads ABMAP (Ability Map) resources from ps3data/menu/abmap/. Initializes ability node tree, stat bonus nodes, ability unlock flags. ABMAP data format: dat00 (main), dat12 (secondary).
void __cdecl FFX_SphereGrid_InitRuntimeStateFromAbmapResources(__int16 *n7)
{
  __int16 *n7_1; // edi
  int *RuntimeContextPtr; // ebx
  int i; // ebx
  int *StreamReaderWithErrorDialog; // eax
  int *StreamReaderWithErrorDialog_1; // edi
  size_t nNumberOfBytesToRead; // esi
  void *lpBuffer; // eax
  int v8; // eax
  int (__cdecl **WalkStructSkyDataPtr)(_DWORD, _DWORD, _DWORD, _DWORD); // esi
  int v10; // edx
  int v11; // ecx
  int n7_3; // esi
  int v13; // eax
  unsigned __int16 *v14; // eax
  void *abmapContext; // edx
  __int16 *v16; // edi
  int j; // ecx
  int v18; // eax
  __int16 v19; // ax
  _DWORD v20[6]; // [esp+Ch] [ebp-7A4h]
  int v21; // [esp+24h] [ebp-78Ch]
  int v22; // [esp+28h] [ebp-788h]
  int v23; // [esp+2Ch] [ebp-784h]
  int v24; // [esp+30h] [ebp-780h]
  int v25; // [esp+34h] [ebp-77Ch]
  int v26; // [esp+38h] [ebp-778h]
  int v27; // [esp+3Ch] [ebp-774h]
  int v28; // [esp+40h] [ebp-770h]
  int v29; // [esp+44h] [ebp-76Ch]
  int v30; // [esp+48h] [ebp-768h]
  int v31; // [esp+50h] [ebp-760h]
  int v32; // [esp+54h] [ebp-75Ch]
  int v33; // [esp+58h] [ebp-758h]
  int v34; // [esp+5Ch] [ebp-754h]
  int v35; // [esp+60h] [ebp-750h]
  int v36; // [esp+64h] [ebp-74Ch]
  int v37; // [esp+68h] [ebp-748h]
  int v38; // [esp+6Ch] [ebp-744h]
  int v39; // [esp+70h] [ebp-740h]
  int v40; // [esp+74h] [ebp-73Ch]
  int v41; // [esp+78h] [ebp-738h]
  int v42; // [esp+7Ch] [ebp-734h]
  int v43; // [esp+80h] [ebp-730h]
  int v44; // [esp+84h] [ebp-72Ch]
  int v45; // [esp+88h] [ebp-728h]
  int v46; // [esp+8Ch] [ebp-724h]
  int v47; // [esp+90h] [ebp-720h]
  int v48; // [esp+94h] [ebp-71Ch]
  int v49; // [esp+98h] [ebp-718h]
  int v50; // [esp+9Ch] [ebp-714h]
  int v51; // [esp+A0h] [ebp-710h]
  int v52; // [esp+A4h] [ebp-70Ch]
  int v53; // [esp+A8h] [ebp-708h]
  int v54; // [esp+ACh] [ebp-704h]
  int v55; // [esp+B0h] [ebp-700h]
  int v56; // [esp+B4h] [ebp-6FCh]
  int v57; // [esp+B8h] [ebp-6F8h]
  int v58; // [esp+BCh] [ebp-6F4h]
  int v59; // [esp+C0h] [ebp-6F0h]
  int v60; // [esp+C4h] [ebp-6ECh]
  int v61; // [esp+C8h] [ebp-6E8h]
  int v62; // [esp+CCh] [ebp-6E4h]
  int v63; // [esp+D0h] [ebp-6E0h]
  int v64; // [esp+D4h] [ebp-6DCh]
  int v65; // [esp+D8h] [ebp-6D8h]
  int v66; // [esp+DCh] [ebp-6D4h]
  int v67; // [esp+E0h] [ebp-6D0h]
  int v68; // [esp+E4h] [ebp-6CCh]
  int v69; // [esp+E8h] [ebp-6C8h]
  int v70; // [esp+ECh] [ebp-6C4h]
  int v71; // [esp+F0h] [ebp-6C0h]
  int v72; // [esp+F4h] [ebp-6BCh]
  int v73; // [esp+F8h] [ebp-6B8h]
  int v74; // [esp+FCh] [ebp-6B4h]
  int v75; // [esp+100h] [ebp-6B0h]
  int v76; // [esp+104h] [ebp-6ACh]
  int v77; // [esp+108h] [ebp-6A8h]
  int v78; // [esp+10Ch] [ebp-6A4h]
  int v79; // [esp+110h] [ebp-6A0h]
  int v80; // [esp+114h] [ebp-69Ch]
  int v81; // [esp+118h] [ebp-698h]
  int v82; // [esp+11Ch] [ebp-694h]
  int v83; // [esp+120h] [ebp-690h]
  int *RuntimeContextPtr_1; // [esp+124h] [ebp-68Ch]
  __int16 *n7_2; // [esp+128h] [ebp-688h]
  __int16 n49; // [esp+12Ch] [ebp-684h] BYREF
  unsigned __int16 v87; // [esp+12Eh] [ebp-682h]
  _BYTE v88[1144]; // [esp+134h] [ebp-67Ch]
  char v89[256]; // [esp+5ACh] [ebp-204h] BYREF
  char Buffer[256]; // [esp+6ACh] [ebp-104h] BYREF

  n7_1 = n7; // [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass. /*0xa53df6*/
  n7_2 = n7; /*0xa53df9*/
  RuntimeContextPtr = FFX_Battle_GetRuntimeContextPtr(); /*0xa53e0b*/
  RuntimeContextPtr_1 = RuntimeContextPtr; /*0xa53e0d*/
  if ( !unk_1A85F60 ) /*0xa53e13*/
  {
    for ( i = 0; i < 70; ++i ) /*0xa53e19*/
    {
      sprintf(Buffer, "%s/%s", "/ffx_ps2/ffx/eiichi_abmap_data", FFX_SphereGrid_Global_C85EF0[i]);// "par/dna.pdt" /*0xa53e37*/
      FFX_FileSystem_BuildDataPath(Buffer, v89, 256); /*0xa53e50*/
      sprintf_s(Buffer, 0xFEu, (const char *const)&g_vtable_PTTYCallback_Phyre.slot2, v89); /*0xa53e6d*/
      StreamReaderWithErrorDialog = FFX_FileIO_CreateStreamReaderWithErrorDialog(Buffer, (wchar_t *)1); /*0xa53e7c*/
      StreamReaderWithErrorDialog_1 = StreamReaderWithErrorDialog; /*0xa53e81*/
      if ( StreamReaderWithErrorDialog ) /*0xa53e88*/
      {
        nNumberOfBytesToRead = FFX_FileIO_PFileStream_SeekSafe(StreamReaderWithErrorDialog, 0, 2u); /*0xa53eaf*/
        FFX_FileIO_PFileStream_SeekSafe(StreamReaderWithErrorDialog_1, 0, 0); /*0xa53eb1*/
        lpBuffer = (void *)FFX_Heap_Alloc(nNumberOfBytesToRead, (void *)0x10); /*0xa53eb9*/
        v20[i] = lpBuffer; /*0xa53ec1*/
        FFX_FileIO_PFileStream_ReadSafe((void **)StreamReaderWithErrorDialog_1, lpBuffer, nNumberOfBytesToRead); /*0xa53ec8*/
        FFX_FileIO_StreamWriterCloseAndFree(StreamReaderWithErrorDialog_1); /*0xa53ece*/
      }
      dbgPrintf(); /*0xa53e96*/
    }
    MEMORY[0x2305800] = (_DWORD *)v20[0]; /*0xa53efd*/
    unk_23057FC = v20[1]; /*0xa53f08*/
    unk_23057F8 = v20[2]; /*0xa53f13*/
    unk_23057F4 = v20[3]; /*0xa53f1e*/
    unk_23057F0 = v20[4]; /*0xa53f29*/
    dword_23057EC = v20[5]; /*0xa53f34*/
    unk_23057E8 = v21; /*0xa53f3f*/
    unk_23057E4 = v22; /*0xa53f4a*/
    unk_23057CC = v28; /*0xa53f55*/
    unk_1A85F94 = v28; /*0xa53f5a*/
    unk_23057C8 = v29; /*0xa53f65*/
    unk_1A85FE4 = v29; /*0xa53f6a*/
    unk_23057C4 = v30; /*0xa53f75*/
    unk_23057BC = v31; /*0xa53f80*/
    unk_23057B8 = v32; /*0xa53f8b*/
    unk_23057B4 = v33; /*0xa53f9c*/
    unk_23057B0 = v34; /*0xa53fbf*/
    unk_23057AC = v35; /*0xa53fca*/
    unk_23057A8 = v36; /*0xa53fd5*/
    unk_23057A4 = v37; /*0xa53fe0*/
    unk_23057A0 = v38; /*0xa53feb*/
    unk_230579C = v39; /*0xa53ff6*/
    unk_2305798 = v40; /*0xa54001*/
    unk_23057E0 = v23; /*0xa5400c*/
    unk_2305794 = v41; /*0xa54018*/
    unk_1A85F78[0] = v21; /*0xa54023*/
    unk_2305790 = v42; /*0xa5402f*/
    unk_1A85F7C = v22; /*0xa5403a*/
    unk_23057DC = v24; /*0xa54046*/
    unk_23057D8 = v25; /*0xa5404c*/
    unk_23057D4 = v26; /*0xa54052*/
    unk_23057D0 = v27; /*0xa54058*/
    unk_1A85F84 = v24; /*0xa5405e*/
    unk_1A85F88 = v25; /*0xa5406a*/
    unk_1A85F8C = v26; /*0xa54076*/
    unk_1A85F90 = v27; /*0xa54082*/
    unk_230578C = v43; /*0xa5408e*/
    unk_1A85F80 = v23; /*0xa54099*/
    unk_2305788 = v44; /*0xa540a5*/
    unk_2305784 = v45; /*0xa540aa*/
    unk_2305780 = v46; /*0xa540b0*/
    unk_230577C = v47; /*0xa540b6*/
    unk_2305778 = v48; /*0xa540bc*/
    unk_2305770 = v50; /*0xa540c8*/
    unk_230576C = v51; /*0xa540d3*/
    unk_2305768 = v52; /*0xa540de*/
    unk_2305764 = v53; /*0xa540e9*/
    unk_2305760 = v54; /*0xa540f4*/
    unk_230575C = v55; /*0xa540ff*/
    unk_2305758 = v56; /*0xa5410a*/
    unk_2305754 = v57; /*0xa54115*/
    unk_2305750 = v58; /*0xa54120*/
    unk_230574C = v59; /*0xa5412b*/
    unk_2305748 = v60; /*0xa54136*/
    unk_2305744 = v61; /*0xa54141*/
    unk_2305740 = v62; /*0xa5414c*/
    unk_1A85F98[0] = v44; /*0xa54157*/
    unk_1A85FB0 = v50; /*0xa54162*/
    unk_1A85FB4 = v51; /*0xa5416d*/
    unk_1A85FB8 = v52; /*0xa54178*/
    unk_1A85FBC = v53; /*0xa54183*/
    unk_1A85FC0 = v54; /*0xa5418e*/
    unk_1A85FC4 = v55; /*0xa54199*/
    unk_1A85FC8 = v56; /*0xa541a4*/
    unk_1A85FCC = v57; /*0xa541af*/
    unk_1A85FD0 = v58; /*0xa541ba*/
    unk_1A85FD4 = v59; /*0xa541c5*/
    unk_1A85FD8 = v60; /*0xa541d0*/
    unk_1A85FDC = v61; /*0xa541db*/
    unk_1A85FE0 = v62; /*0xa541e6*/
    unk_230573C = v63; /*0xa541f1*/
    unk_2305724 = v69; /*0xa541fc*/
    unk_2305720 = v70; /*0xa54207*/
    unk_230571C = v71; /*0xa54212*/
    unk_2305774 = v49; /*0xa5421d*/
    unk_1A85F9C = v45; /*0xa54223*/
    unk_1A85FA0 = v46; /*0xa5422f*/
    unk_1A85FA4 = v47; /*0xa5423b*/
    unk_1A85FA8 = v48; /*0xa54247*/
    unk_1A85FAC = v49; /*0xa54253*/
    unk_2305718 = v72; /*0xa5425f*/
    unk_2305738 = v64; /*0xa5426a*/
    unk_2305734 = v65; /*0xa54270*/
    unk_2305730 = v66; /*0xa54276*/
    unk_230572C = v67; /*0xa5427c*/
    unk_2305728 = v68; /*0xa54282*/
    unk_2305714 = v73; /*0xa54288*/
    unk_2305710 = v74; /*0xa54293*/
    unk_230570C = v75; /*0xa5429e*/
    unk_2305708 = v76; /*0xa542a9*/
    unk_2305704 = v77; /*0xa542b4*/
    unk_2305700 = v78; /*0xa542bf*/
    unk_23056FC = v79; /*0xa542ca*/
    unk_23056F8 = v80; /*0xa542d5*/
    unk_23056F4 = v81; /*0xa542e0*/
    unk_1A85FE8[0] = v63; /*0xa542eb*/
    unk_1A86000 = v69; /*0xa542f6*/
    unk_1A86004 = v70; /*0xa54301*/
    unk_1A86008 = v71; /*0xa5430c*/
    unk_1A8600C = v72; /*0xa54317*/
    unk_1A86010 = v73; /*0xa54322*/
    unk_1A86014 = v74; /*0xa5432d*/
    unk_1A86018 = v75; /*0xa54338*/
    unk_1A8601C = v76; /*0xa54343*/
    unk_1A86020 = v77; /*0xa5434e*/
    unk_1A86024 = v78; /*0xa54359*/
    unk_1A86028 = v79; /*0xa54364*/
    unk_1A8602C = v80; /*0xa5436f*/
    unk_1A86030 = v81; /*0xa5437a*/
    unk_23056F0 = v82; /*0xa54385*/
    unk_1A85FF8 = v67; /*0xa54390*/
    n7_1 = n7_2; /*0xa54396*/
    unk_1A85FFC = v68; /*0xa5439c*/
    RuntimeContextPtr = RuntimeContextPtr_1; /*0xa543a2*/
    unk_1A85FEC = v64; /*0xa543a8*/
    unk_1A85FF0 = v65; /*0xa543ae*/
    unk_1A85FF4 = v66; /*0xa543b4*/
    unk_23056EC = v83; /*0xa543ba*/
    unk_1A85F60 = 1; /*0xa543bf*/
  }
  v8 = (*RuntimeContextPtr >> 14) & 3; /*0xa543ce*/
  IsOpen = 0; /*0xa543d1*/
  if ( v8 ) /*0xa543de*/
  {
    if ( v8 == 1 ) /*0xa543e1*/
    {
      WalkStructSkyDataPtr = FFX_Mscd_GetWalkStructSkyDataPtr(); /*0xa54405*/
      ((void (__cdecl *)(int))WalkStructSkyDataPtr[4])(37); /*0xa5440c*/
      (*WalkStructSkyDataPtr)(18, &n49, 0, 0); /*0xa5441b*/
    }
    else
    {
      WalkStructSkyDataPtr = FFX_Mscd_GetWalkStructSkyDataPtr(); /*0xa543e8*/
      ((void (__cdecl *)(int))WalkStructSkyDataPtr[4])(37); /*0xa543ef*/
      (*WalkStructSkyDataPtr)(19, &n49, 0, 0); /*0xa543fe*/
    }
  }
  else
  {
    WalkStructSkyDataPtr = FFX_Mscd_GetWalkStructSkyDataPtr(); /*0xa54422*/
    ((void (__cdecl *)(int))WalkStructSkyDataPtr[4])(37); /*0xa54429*/
    (*WalkStructSkyDataPtr)(17, &n49, 0, 0); /*0xa5443a*/
  }
  ((void (__cdecl *)(_DWORD))WalkStructSkyDataPtr[2])(0); /*0xa54441*/
  memset(n7_1, 0, 0x1320u); /*0xa5444e*/
  if ( n49 == 49 ) /*0xa5445e*/
  {
    v10 = v87; /*0xa54460*/
    v11 = 0; /*0xa54467*/
    if ( v87 ) /*0xa5446b*/
    {
      do /*0xa5447d*/
      {
        LOBYTE(n7_1[v11]) = v88[v11]; /*0xa54477*/
        ++v11; /*0xa5447a*/
      }
      while ( v11 < v10 ); /*0xa5447d*/
    }
  }
  n7_3 = 0; /*0xa5447f*/
  n7_2 = 0; /*0xa54481*/
  do /*0xa54501*/
  {
    v13 = (*RuntimeContextPtr >> 14) & 3; /*0xa54495*/
    if ( v13 ) /*0xa5449b*/
    {
      if ( v13 == 1 ) /*0xa5449e*/
        v14 = (unsigned __int16 *)*(&FFX_SphereGrid_Global_C86CA4 + n7_3); /*0xa544a9*/
      else
        v14 = (unsigned __int16 *)*(&FFX_SphereGrid_Global_C86CEC + n7_3); /*0xa544a0*/
    }
    else
    {
      v14 = (unsigned __int16 *)*(&FFX_SphereGrid_Global_C86C5C + n7_3); /*0xa544b2*/
    }
    abmapContext = (void *)*v14; /*0xa544b9*/
    if ( (_WORD)abmapContext != 0xFFFF ) /*0xa544bf*/
    {
      do /*0xa544e4*/
      {
        HIBYTE(n7_1[(unsigned __int16)abmapContext]) |= 1 << n7_3; /*0xa544d3*/
        abmapContext = (void *)v14[1]; /*0xa544d7*/
        ++v14; /*0xa544de*/
      }
      while ( (_WORD)abmapContext != 0xFFFF ); /*0xa544e4*/
      n7_3 = (int)n7_2; /*0xa544e6*/
      RuntimeContextPtr = RuntimeContextPtr_1; /*0xa544ec*/
    }
    n7_2 = (__int16 *)++n7_3; /*0xa544f8*/
  }
  while ( n7_3 < 7 ); /*0xa54501*/
  v16 = n7_1 + 1920; /*0xa54503*/
  for ( j = 0; j < 7; ++j ) /*0xa54509*/
  {
    v18 = (*RuntimeContextPtr >> 14) & 3; /*0xa54515*/
    if ( v18 ) /*0xa5451b*/
    {
      if ( v18 == 1 ) /*0xa5451e*/
        v19 = FFX_SphereGrid_Global_C86C10[j]; /*0xa54529*/
      else
        v19 = FFX_SphereGrid_Global_C86C20[j]; /*0xa54520*/
    }
    else
    {
      v19 = FFX_SphereGrid_Global_C86C00[j]; /*0xa54532*/
    }
    *v16++ = v19; /*0xa54539*/
  }
  FFX_Abmap_RecomputePartyStatsAndLearnedMoves((FFX_CharacterId)(j * 2), abmapContext); /*0xa54547*/
}
