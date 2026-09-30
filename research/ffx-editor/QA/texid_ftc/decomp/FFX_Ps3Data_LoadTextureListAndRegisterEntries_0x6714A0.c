// FFX: PS3Data loads texture list and registers entries structural — loads texture list and registers entries
// FFX Ps3Data: Load texture list and register entries
int __thiscall FFX_Ps3Data_LoadTextureListAndRegisterEntries_structural(int this, char *ArgList, int n1024)
{
  const char *ArgList_1; // esi
  unsigned int v5; // esi
  int StreamReaderWithErrorDialog_4; // ecx
  int v7; // edi
  int FileCache; // eax
  unsigned int v9; // esi
  char *(__cdecl *__imp_strstr)(const char *, const char *); // edi
  int StreamReaderWithErrorDialog_5; // ecx
  const char *v12; // eax
  char *v13; // eax
  int v14; // edi
  int v15; // eax
  const char *v16; // eax
  char *v17; // edx
  int *StreamReaderWithErrorDialog; // eax
  DWORD SizeSafe; // esi
  int *lpBuffer; // edi
  size_t Size; // ecx
  unsigned int v23; // ecx
  char *v24; // edx
  char v25; // al
  unsigned int n0x100; // ecx
  int v27; // esi
  unsigned int v28; // edi
  int StreamReaderWithErrorDialog_6; // ebx
  int v30; // eax
  void **ptr_new_for_once_1; // eax
  char *v32; // edi
  _DWORD *p_this_1; // ebx
  void **ptr_new_for_once_2; // eax
  void **ptr_new_for_once_3; // eax
  unsigned int StreamReaderWithErrorDialog_2; // esi
  bool v37; // sf
  const char *Source; // esi
  char *v39; // eax
  int v40; // edi
  unsigned int n0x100_2; // edi
  char v42; // al
  unsigned int n0x100_1; // esi
  int v44; // eax
  int v45; // eax
  int v46; // eax
  int v47; // eax
  unsigned int j; // esi
  const char *v49; // eax
  int v50; // eax
  unsigned int i; // edi
  int v52; // esi
  const char *v53; // eax
  int v54; // eax
  unsigned __int64 v55; // [esp-8h] [ebp-35Ch]
  int *i_1; // [esp-4h] [ebp-358h]
  int *i_2; // [esp-4h] [ebp-358h]
  int *i_3; // [esp-4h] [ebp-358h]
  _DWORD *p_this; // [esp+18h] [ebp-33Ch] BYREF
  char *StreamReaderWithErrorDialog_3; // [esp+1Ch] [ebp-338h] BYREF
  int StreamReaderWithErrorDialog_7; // [esp+20h] [ebp-334h]
  unsigned int v62; // [esp+24h] [ebp-330h]
  int StreamReaderWithErrorDialog_1; // [esp+28h] [ebp-32Ch]
  void *ptr_new_for_once[4]; // [esp+2Ch] [ebp-328h] BYREF
  unsigned int v65; // [esp+3Ch] [ebp-318h]
  unsigned int n15; // [esp+40h] [ebp-314h]
  int Buffer[64]; // [esp+44h] [ebp-310h] BYREF
  char v68[256]; // [esp+144h] [ebp-210h] BYREF
  char Destination[256]; // [esp+244h] [ebp-110h] BYREF
  int v70; // [esp+350h] [ebp-4h]

  p_this = (_DWORD *)this; /*0x6714d0*/
  ArgList_1 = ArgList; /*0x6714dc*/
  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(this + 208) + 8))(*(_DWORD *)(this + 208)); /*0x6714e7*/
  Phyre_RenderThread_PostJobFromCpu(); /*0x6714f0*/
  if ( (unsigned int)(n1024 - 630) <= 7 ) /*0x671507*/
    *(_BYTE *)(this + 64260) = 1; /*0x671509*/
  if ( (unsigned int)(n1024 - 622) <= 7 ) /*0x671519*/
    *(_BYTE *)(this + 64260) = 0; /*0x67151b*/
  if ( n1024 == 1024 ) /*0x671528*/
  {
    v5 = 0; /*0x67152e*/
    if ( *(_DWORD *)(this + 76) ) /*0x671530*/
    {
      StreamReaderWithErrorDialog_4 = 0; /*0x671539*/
      StreamReaderWithErrorDialog_1 = 0; /*0x67153b*/
      do /*0x6715bb*/
      {
        v7 = 4 * v5; /*0x671544*/
        if ( *(_DWORD *)(4 * v5 + *(_DWORD *)(this + 96)) /*0x67155d*/
          && v5 < *(_DWORD *)(this + 64)
          && *(_DWORD *)(StreamReaderWithErrorDialog_4 + *(_DWORD *)(this + 72)) == 1 )
        {
          i_1 = *(int **)(*(_DWORD *)(this + 84) + 4 * v5); /*0x671562*/
          FileCache = FFX_TexAnim_GetFileCache(); /*0x671565*/
          TextureMap_RemoveByHash(FileCache, i_1); /*0x67156c*/
          FFX_Heap_Free(*(void **)(v7 + *(_DWORD *)(this + 60))); /*0x671577*/
          FFX_Heap_Free(*(void **)(*(_DWORD *)(this + 84) + 4 * v5)); /*0x671582*/
          StreamReaderWithErrorDialog_4 = StreamReaderWithErrorDialog_1; /*0x67158a*/
          *(_DWORD *)(v7 + *(_DWORD *)(this + 60)) = 0; /*0x671590*/
          *(_DWORD *)(v7 + *(_DWORD *)(this + 84)) = 0; /*0x67159d*/
          *(_DWORD *)(v7 + *(_DWORD *)(this + 96)) = 0; /*0x6715a7*/
        }
        ++v5; /*0x6715ae*/
        StreamReaderWithErrorDialog_4 += 20; /*0x6715af*/
        StreamReaderWithErrorDialog_1 = StreamReaderWithErrorDialog_4; /*0x6715b2*/
      }
      while ( v5 < *(_DWORD *)(this + 76) ); /*0x6715bb*/
    }
    return 0; /*0x6715bb*/
  }
  if ( n1024 != -1 && (n1024 < 622 || n1024 > 637) ) /*0x6715d9*/
  {
    v9 = 0; /*0x6715df*/
    if ( !*(_DWORD *)(this + 76) ) /*0x6715e4*/
      return 0; /*0x671d1d*/
    __imp_strstr = strstr; /*0x6715ea*/
    StreamReaderWithErrorDialog_5 = 0; /*0x6715f0*/
    StreamReaderWithErrorDialog_1 = 0; /*0x6715f2*/
    while ( *(_BYTE *)(this + 64260) ) /*0x671600*/
    {
      v12 = *(const char **)(*(_DWORD *)(this + 84) + 4 * v9); /*0x67160c*/
      if ( !v12 ) /*0x671611*/
        break; /*0x671611*/
      if ( __imp_strstr(v12, "00001_19_0_0_1_1.dds.phyre") /*0x671631*/
        || __imp_strstr(*(const char **)(*(_DWORD *)(this + 84) + 4 * v9), "00002_19_0_0_1_1.dds.phyre") )
      {
        StreamReaderWithErrorDialog_5 = StreamReaderWithErrorDialog_1; /*0x6716e3*/
      }
      else
      {
        v13 = __imp_strstr(*(const char **)(*(_DWORD *)(this + 84) + 4 * v9), "00003_19_0_0_1_1.dds.phyre"); /*0x671649*/
        StreamReaderWithErrorDialog_5 = StreamReaderWithErrorDialog_1; /*0x67164b*/
        if ( !v13 ) /*0x671656*/
          break; /*0x671656*/
      }
LABEL_29:
      ++v9; /*0x6716cb*/
      StreamReaderWithErrorDialog_5 += 20; /*0x6716cc*/
      StreamReaderWithErrorDialog_1 = StreamReaderWithErrorDialog_5; /*0x6716cf*/
      if ( v9 >= *(_DWORD *)(this + 76) ) /*0x6716d8*/
        return 0; /*0x6716d8*/
    }
    v14 = 4 * v9; /*0x671658*/
    if ( *(_DWORD *)(4 * v9 + *(_DWORD *)(this + 96)) /*0x671674*/
      && v9 < *(_DWORD *)(this + 64)
      && *(_DWORD *)(StreamReaderWithErrorDialog_5 + *(_DWORD *)(this + 72)) == 2 )
    {
      i_2 = *(int **)(*(_DWORD *)(this + 84) + 4 * v9); /*0x671679*/
      v15 = FFX_TexAnim_GetFileCache(); /*0x67167c*/
      TextureMap_RemoveByHash(v15, i_2); /*0x671683*/
      FFX_Heap_Free(*(void **)(v14 + *(_DWORD *)(this + 60))); /*0x67168e*/
      FFX_Heap_Free(*(void **)(*(_DWORD *)(this + 84) + 4 * v9)); /*0x671699*/
      StreamReaderWithErrorDialog_5 = StreamReaderWithErrorDialog_1; /*0x6716a1*/
      *(_DWORD *)(v14 + *(_DWORD *)(this + 60)) = 0; /*0x6716a7*/
      *(_DWORD *)(v14 + *(_DWORD *)(this + 84)) = 0; /*0x6716b4*/
      *(_DWORD *)(v14 + *(_DWORD *)(this + 96)) = 0; /*0x6716be*/
    }
    __imp_strstr = strstr; /*0x6716c5*/
    goto LABEL_29; /*0x6716c5*/
  }
  n15 = 15; /*0x6716f8*/
  v65 = 0; /*0x671702*/
  LOBYTE(ptr_new_for_once[0]) = 0; /*0x67170c*/
  Engine_String_assign_range(ptr_new_for_once, &Format__0, 0); /*0x671713*/
  v70 = 0; /*0x67171b*/
  v16 = (const char *)FFX_ResourceTree_FindByNameDescending(this, ArgList); /*0x671722*/
  v17 = (char *)v16; /*0x671727*/
  if ( v16 ) /*0x67172b*/
  {
    if ( *v16 ) /*0x6717d4*/
      Size = strlen(v16); /*0x6717df*/
    else
      Size = 0; /*0x6717d9*/
    Phyre_String_AppendData((char *)ptr_new_for_once, v17, Size); /*0x6717f3*/
    goto LABEL_44; /*0x6717f3*/
  }
  if ( Phyre_File_ReadEntireFile_ww(ArgList) )
  {
    StreamReaderWithErrorDialog = FFX_FileIO_CreateStreamReaderWithErrorDialog(ArgList, (wchar_t *)1); /*0x671762*/
    StreamReaderWithErrorDialog_1 = (int)StreamReaderWithErrorDialog; /*0x67176a*/
    if ( !StreamReaderWithErrorDialog ) /*0x671772*/
    {
      Engine_String_copy_ctor(ptr_new_for_once); /*0x67177a*/
      return 5; /*0x671784*/
    }
    SizeSafe = FFX_FileIO_PStreamWriter_GetSizeSafe(StreamReaderWithErrorDialog); /*0x67178f*/
    lpBuffer = FFX_GameAllocWrapper_structural(SizeSafe + 1); /*0x67179a*/
    *((_BYTE *)lpBuffer + SizeSafe) = 0; /*0x67179d*/
    FFX_FileIO_PFileStream_ReadSafe((void **)StreamReaderWithErrorDialog_1, (char *)lpBuffer, SizeSafe); /*0x6717a9*/
    Phyre_String_AppendStr((char *)ptr_new_for_once, (char *)lpBuffer); /*0x6717b8*/
    FFX_AsyncQ_BacktraceFreeAndHeapFree((unsigned int)lpBuffer); /*0x6717be*/
    FFX_FileIO_StreamWriterCloseAndFree((void *)StreamReaderWithErrorDialog_1); /*0x6717c4*/
    ArgList_1 = ArgList; /*0x6717c9*/
LABEL_44:
    v23 = strlen(ArgList_1); /*0x6717f8*/
    v24 = (char *)(v68 - ArgList_1); /*0x67180f*/
    do /*0x67181b*/
    {
      v25 = *ArgList_1; /*0x671811*/
      ArgList_1[(_DWORD)v24] = *ArgList_1; /*0x671813*/
      ++ArgList_1; /*0x671816*/
    }
    while ( v25 ); /*0x67181b*/
    for ( ; v68[v23] != 47; --v23 ) /*0x671825*/
      ; /*0x671830*/
    n0x100 = v23 + 1; /*0x67183b*/
    if ( n0x100 >= 0x100 ) /*0x671842*/
LABEL_111:
      __report_rangecheckfailure(); /*0x671d20*/
    v27 = 0; /*0x671848*/
    v68[n0x100] = 0; /*0x67184a*/
    v28 = 0; /*0x671852*/
    StreamReaderWithErrorDialog_7 = 0; /*0x671854*/
    v62 = 0; /*0x67185a*/
    StreamReaderWithErrorDialog_6 = 0; /*0x671860*/
    LOBYTE(v70) = 1; /*0x671862*/
    StreamReaderWithErrorDialog_3 = 0; /*0x671866*/
    while ( 1 ) /*0x671870*/
    {
      HIDWORD(v55) = 1; /*0x671870*/
      LODWORD(v55) = v27 + 1; /*0x671875*/
      v30 = Engine_String_find((char *)ptr_new_for_once, "\n", v55); /*0x671881*/
      v27 = v30; /*0x671886*/
      if ( v30 == -1 || v30 == v28 ) /*0x67188f*/
        break; /*0x67188f*/
      ptr_new_for_once_1 = (void **)ptr_new_for_once[0]; /*0x671898*/
      if ( n15 < 0x10 ) /*0x67189e*/
        ptr_new_for_once_1 = ptr_new_for_once; /*0x6718a0*/
      ++StreamReaderWithErrorDialog_6; /*0x6718a6*/
      v32 = (char *)ptr_new_for_once_1 + v28; /*0x6718a7*/
      StreamReaderWithErrorDialog_3 = (char *)StreamReaderWithErrorDialog_6; /*0x6718a9*/
      if ( StreamReaderWithErrorDialog_6 > StreamReaderWithErrorDialog_7 ) /*0x6718b5*/
      {
        IntArray_Reserve_A( /*0x6718ce*/
          (const void **)&StreamReaderWithErrorDialog_3,
          StreamReaderWithErrorDialog_6 + 2 + StreamReaderWithErrorDialog_6 / 8);
        StreamReaderWithErrorDialog_6 = (int)StreamReaderWithErrorDialog_3; /*0x6718d3*/
      }
      if ( v62 + 4 * StreamReaderWithErrorDialog_6 != 4 ) /*0x6718e5*/
        *(_DWORD *)(v62 + 4 * StreamReaderWithErrorDialog_6 - 4) = v32; /*0x6718e7*/
      v28 = v27 + 1; /*0x6718e9*/
    }
    p_this_1 = p_this; /*0x6718ee*/
    if ( v65 > v28 ) /*0x6718fa*/
    {
      ptr_new_for_once_2 = (void **)ptr_new_for_once[0]; /*0x671903*/
      if ( n15 < 0x10 ) /*0x671909*/
        ptr_new_for_once_2 = ptr_new_for_once; /*0x67190b*/
      if ( *((_BYTE *)ptr_new_for_once_2 + v28) ) /*0x671911*/
      {
        ptr_new_for_once_3 = (void **)ptr_new_for_once[0]; /*0x67191e*/
        if ( n15 < 0x10 ) /*0x671924*/
          ptr_new_for_once_3 = ptr_new_for_once; /*0x671926*/
        p_this = (void **)((char *)ptr_new_for_once_3 + v28); /*0x67192e*/
        FFX_PtrArray_PushBack((const void **)&StreamReaderWithErrorDialog_3, &p_this); /*0x671941*/
      }
    }
    StreamReaderWithErrorDialog_2 = 0; /*0x67194c*/
    StreamReaderWithErrorDialog_1 = 0; /*0x67194e*/
    v37 = (int)StreamReaderWithErrorDialog_3 < 0; /*0x671954*/
    if ( !StreamReaderWithErrorDialog_3 ) /*0x671956*/
    {
LABEL_93:
      if ( v37 && StreamReaderWithErrorDialog_7 < 0 ) /*0x671b9c*/
        IntArray_Reserve_A((const void **)&StreamReaderWithErrorDialog_3, 0); /*0x671ba6*/
      StreamReaderWithErrorDialog_3 = 0; /*0x671bae*/
      if ( n1024 >= 622 && n1024 <= 629 ) /*0x671bc6*/
      {
        for ( i = 0; i < p_this_1[19]; ++i ) /*0x671bee*/
        {
          v52 = 4 * i; /*0x671c03*/
          v53 = *(const char **)(4 * i + p_this_1[21]); /*0x671c0a*/
          if ( v53 /*0x671c4b*/
            && (strstr(v53, "00001_19_0_0_1_1.dds.phyre")
             || strstr(*(const char **)(v52 + p_this_1[21]), "00002_19_0_0_1_1.dds.phyre")
             || strstr(*(const char **)(v52 + p_this_1[21]), "00003_19_0_0_1_1.dds.phyre")) )
          {
            i_3 = *(int **)(p_this_1[21] + 4 * i); /*0x671c5b*/
            v54 = FFX_TexAnim_GetFileCache(); /*0x671c5e*/
            TextureMap_RemoveByHash(v54, i_3); /*0x671c65*/
            FFX_Heap_Free(*(void **)(v52 + p_this_1[15])); /*0x671c70*/
            FFX_Heap_Free(*(void **)(p_this_1[21] + 4 * i)); /*0x671c7b*/
            *(_DWORD *)(v52 + p_this_1[15]) = 0; /*0x671c86*/
            *(_DWORD *)(v52 + p_this_1[21]) = 0; /*0x671c90*/
            *(_DWORD *)(v52 + p_this_1[24]) = 0; /*0x671c9a*/
          }
        }
        FFX_Texture_RegisterTextureSamplers(); /*0x671cae*/
      }
      if ( v62 ) /*0x671cde*/
        Engine_HeapFreeThunk(v62); /*0x671ce1*/
      if ( n15 >= 0x10 ) /*0x671cf0*/
        FFX_Heap_Free(ptr_new_for_once[0]); /*0x671cf8*/
      return 0; /*0x671cf8*/
    }
    while ( 1 ) /*0x67196b*/
    {
      Source = *(const char **)(v62 + 4 * StreamReaderWithErrorDialog_2); /*0x67196b*/
      v39 = strstr(Source, "\n"); /*0x67196f*/
      if ( v39 ) /*0x67197c*/
        break; /*0x67197c*/
      if ( (char *)StreamReaderWithErrorDialog_1 == StreamReaderWithErrorDialog_3 - 1 ) /*0x67198b*/
      {
        strncpy(Destination, Source, strlen(Source)); /*0x6719d7*/
        n0x100_1 = strlen(Source); /*0x6719e0*/
        if ( n0x100_1 >= 0x100 ) /*0x6719f2*/
          goto LABEL_111; /*0x6719f2*/
        Destination[n0x100_1] = v42; /*0x6719f8*/
        goto LABEL_74; /*0x6719f8*/
      }
LABEL_91:
      StreamReaderWithErrorDialog_2 = StreamReaderWithErrorDialog_1 + 1; /*0x671b76*/
      StreamReaderWithErrorDialog_1 = StreamReaderWithErrorDialog_2; /*0x671b83*/
      if ( StreamReaderWithErrorDialog_2 >= (unsigned int)StreamReaderWithErrorDialog_3 ) /*0x671b8b*/
      {
        v37 = (int)StreamReaderWithErrorDialog_3 < 0; /*0x671b91*/
        goto LABEL_93; /*0x671b91*/
      }
    }
    v40 = v39 - Source; /*0x671995*/
    strncpy(Destination, Source, v39 - Source); /*0x6719a0*/
    n0x100_2 = v40 - 1; /*0x6719a6*/
    if ( n0x100_2 >= 0x100 ) /*0x6719b0*/
      goto LABEL_111; /*0x6719b0*/
    Destination[n0x100_2] = 0; /*0x6719b6*/
LABEL_74:
    if ( (unsigned int)(n1024 - 630) > 7 ) /*0x671a06*/
      goto LABEL_84; /*0x671a06*/
    v44 = strcmp(Destination, "00001_19_0_0_1_1.dds.phyre"); /*0x671a1b*/
    if ( v44 )
      v44 = v44 < 0 ? -1 : 1;
    if ( v44 )
    {
      v45 = strcmp(Destination, "00002_19_0_0_1_1.dds.phyre"); /*0x671a54*/
      if ( v45 )
        v45 = v45 < 0 ? -1 : 1;
      if ( v45 )
      {
        v46 = strcmp(Destination, "00003_19_0_0_1_1.dds.phyre"); /*0x671a8c*/
        if ( v46 )
          v46 = v46 < 0 ? -1 : 1;
        if ( v46 )
        {
LABEL_84:
          sprintf((char *const)Buffer, "%s%s%s", v68, "D3D11/", Destination); /*0x671ad4*/
          v47 = FFX_TexAnim_GetFileCache(); /*0x671ae4*/
          TextureMap_RemoveByHash(v47, Buffer); /*0x671aeb*/
          for ( j = 0; j < p_this_1[19]; ++j )
          {
            v49 = *(const char **)(p_this_1[21] + 4 * j); /*0x671b03*/
            if ( v49 )
            {
              v50 = strcmp(v49, (const char *)Buffer); /*0x671b14*/
              if ( v50 )
                v50 = v50 < 0 ? -1 : 1;
              if ( !v50 ) /*0x671b37*/
              {
                FFX_Heap_Free(*(void **)(p_this_1[15] + 4 * j)); /*0x671b3f*/
                FFX_Heap_Free(*(void **)(p_this_1[21] + 4 * j)); /*0x671b4a*/
                *(_DWORD *)(p_this_1[15] + 4 * j) = 0; /*0x671b55*/
                *(_DWORD *)(p_this_1[21] + 4 * j) = 0; /*0x671b5f*/
                *(_DWORD *)(p_this_1[24] + 4 * j) = 0; /*0x671b69*/
              }
            }
          }
        }
      }
    }
    goto LABEL_91; /*0x671b74*/
  }
  if ( n15 >= 0x10 ) /*0x671745*/
    FFX_Heap_Free(ptr_new_for_once[0]); /*0x67174d*/
  return 5; /*0x671d02*/
}