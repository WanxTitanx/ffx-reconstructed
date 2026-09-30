// LoadVfxResourceFileList — loads VFX resource file list
int __thiscall LoadVfxResourceFileList(_DWORD *this, int n2, char *Src, char a4)
{
  char *Src_1; // edi
  const char *v6; // eax
  char *v7; // edx
  int *StreamReaderWithErrorDialog; // eax
  DWORD SizeSafe; // esi
  int *lpBuffer; // ebx
  size_t Size_2; // ecx
  void **ptr_new_for_once_1; // eax
  size_t Size_1; // ecx
  unsigned int v14; // ecx
  char v15; // al
  unsigned int n0x100; // ecx
  int v17; // esi
  unsigned int v18; // edi
  int InstanceCount; // ebx
  int v20; // eax
  void **ptr_new_for_once_2; // eax
  char *v22; // edi
  void **ptr_new_for_once_3; // eax
  void **ptr_new_for_once_4; // eax
  int Global; // eax
  unsigned int p_InstanceCount_1; // ecx
  bool v27; // sf
  const char *Source; // esi
  char *v29; // eax
  int v30; // edi
  unsigned int n0x100_1; // edi
  char v32; // al
  unsigned int n0x100_2; // esi
  unsigned int slotIdx; // esi
  unsigned int slotIdx_1; // ecx
  _DWORD *v36; // edi
  _DWORD *v37; // eax
  _DWORD *this_2; // edx
  _DWORD *this_3; // edx
  int v40; // ecx
  _DWORD *v41; // esi
  int v42; // ecx
  _DWORD *v43; // esi
  int v44; // ecx
  _DWORD *v45; // esi
  _DWORD *v46; // ecx
  int v47; // eax
  int FileCache; // eax
  int v49; // edi
  _DWORD *this_4; // ecx
  char *Str_1; // edi
  _DWORD *p_this_1; // edx
  size_t Size_3; // [esp-30h] [ebp-3BCh]
  unsigned __int64 v55; // [esp-8h] [ebp-394h]
  int v56[12]; // [esp+10h] [ebp-37Ch] BYREF
  int strPtrArray; // [esp+40h] [ebp-34Ch] BYREF
  char *Str; // [esp+44h] [ebp-348h]
  int InstanceCount_1; // [esp+48h] [ebp-344h] BYREF
  int InstanceCount_2; // [esp+4Ch] [ebp-340h]
  unsigned int v61; // [esp+50h] [ebp-33Ch]
  size_t Size; // [esp+54h] [ebp-338h] BYREF
  int p_InstanceCount; // [esp+58h] [ebp-334h] BYREF
  _DWORD *p_this; // [esp+5Ch] [ebp-330h] BYREF
  _DWORD *this_1; // [esp+60h] [ebp-32Ch]
  void *ptr_new_for_once[4]; // [esp+64h] [ebp-328h] BYREF
  unsigned int v67; // [esp+74h] [ebp-318h]
  unsigned int n15; // [esp+78h] [ebp-314h]
  char v69[256]; // [esp+7Ch] [ebp-310h] BYREF
  char Buffer[256]; // [esp+17Ch] [ebp-210h] BYREF
  char Destination[256]; // [esp+27Ch] [ebp-110h] BYREF
  int v72; // [esp+388h] [ebp-4h]

  this_1 = this; /*0x665930*/
  Src_1 = Src; /*0x665936*/
  n15 = 15; /*0x665946*/
  v67 = 0; /*0x665950*/
  LOBYTE(ptr_new_for_once[0]) = 0; /*0x66595a*/
  Engine_String_assign_range(ptr_new_for_once, &Format__0, 0); /*0x665961*/
  v72 = 0; /*0x665969*/
  v6 = (const char *)FFX_ResourceTree_FindByNameDescending((int)this, Src); /*0x665970*/
  v7 = (char *)v6; /*0x665975*/
  if ( v6 ) /*0x665979*/
  {
    if ( *v6 ) /*0x665a93*/
      Size_1 = strlen(v6); /*0x665a9e*/
    else
      Size_1 = 0; /*0x665a98*/
    Phyre_String_AppendData((char *)ptr_new_for_once, v7, Size_1); /*0x665ab2*/
  }
  else
  {
    if ( !Phyre_File_ReadEntireFile_ww(Src) ) /*0x665980*/
      goto LABEL_96; /*0x665980*/
    StreamReaderWithErrorDialog = FFX_FileIO_CreateStreamReaderWithErrorDialog(Src, (wchar_t *)1); /*0x665993*/
    p_this = StreamReaderWithErrorDialog; /*0x66599b*/
    if ( !StreamReaderWithErrorDialog ) /*0x6659a3*/
      goto LABEL_96; /*0x6659a3*/
    SizeSafe = FFX_FileIO_PStreamWriter_GetSizeSafe(StreamReaderWithErrorDialog); /*0x6659af*/
    lpBuffer = FFX_GameAllocWrapper_structural(SizeSafe + 1); /*0x6659ba*/
    *((_BYTE *)lpBuffer + SizeSafe) = 0; /*0x6659bd*/
    FFX_FileIO_PFileStream_ReadSafe((void **)p_this, (char *)lpBuffer, SizeSafe); /*0x6659c9*/
    if ( *(_BYTE *)lpBuffer ) /*0x6659d1*/
      Size_2 = strlen((const char *)lpBuffer); /*0x6659dc*/
    else
      Size_2 = 0; /*0x6659d6*/
    Phyre_String_AppendData((char *)ptr_new_for_once, (char *)lpBuffer, Size_2); /*0x6659f1*/
    FFX_AsyncQ_BacktraceFreeAndHeapFree((unsigned int)lpBuffer); /*0x6659f7*/
    FFX_FileIO_StreamWriterCloseAndFree(p_this); /*0x6659fd*/
    mkvparser_Track_IsEnabled((int **)&Size, Src); /*0x665a0c*/
    ptr_new_for_once_1 = (void **)ptr_new_for_once[0]; /*0x665a18*/
    LOBYTE(v72) = 1; /*0x665a1e*/
    if ( n15 < 0x10 ) /*0x665a22*/
      ptr_new_for_once_1 = ptr_new_for_once; /*0x665a24*/
    mkvparser_Track_IsEnabled((int **)&p_InstanceCount, (const char *)ptr_new_for_once_1); /*0x665a31*/
    LOBYTE(v72) = 2; /*0x665a50*/
    FFX_Allocator_AllocAndInsertToTree(this_1 + 17237, &Size, &p_InstanceCount); /*0x665a54*/
    LOBYTE(v72) = 1; /*0x665a63*/
    if ( (p_InstanceCount & 1) == 0 ) /*0x665a6a*/
      Engine_AlignedFree((void *)p_InstanceCount); /*0x665a6d*/
    LOBYTE(v72) = 0; /*0x665a7f*/
    if ( (Size & 1) == 0 ) /*0x665a86*/
      Engine_AlignedFree((void *)Size); /*0x665a89*/
  }
  v14 = strlen(Src); /*0x665ab7*/
  do /*0x665adb*/
  {
    v15 = *Src_1; /*0x665ad1*/
    Src_1[v69 - Src] = *Src_1; /*0x665ad3*/
    ++Src_1; /*0x665ad6*/
  }
  while ( v15 ); /*0x665adb*/
  for ( ; v69[v14] != 47; --v14 ) /*0x665ae5*/
    ; /*0x665af0*/
  n0x100 = v14 + 1; /*0x665afb*/
  if ( n0x100 >= 0x100 ) /*0x665b02*/
LABEL_88:
    __report_rangecheckfailure(); /*0x66606c*/
  v17 = 0; /*0x665b08*/
  v69[n0x100] = 0; /*0x665b0a*/
  v18 = 0; /*0x665b12*/
  InstanceCount_2 = 0; /*0x665b14*/
  v61 = 0; /*0x665b1a*/
  InstanceCount = 0; /*0x665b20*/
  LOBYTE(v72) = 3; /*0x665b22*/
  InstanceCount_1 = 0; /*0x665b26*/
  while ( 1 ) /*0x665b30*/
  {
    HIDWORD(v55) = 1; /*0x665b30*/
    LODWORD(v55) = v17 + 1; /*0x665b35*/
    v20 = Engine_String_find((char *)ptr_new_for_once, "\n", v55); /*0x665b41*/
    v17 = v20; /*0x665b46*/
    if ( v20 == -1 || v20 == v18 ) /*0x665b4f*/
      break; /*0x665b4f*/
    ptr_new_for_once_2 = (void **)ptr_new_for_once[0]; /*0x665b58*/
    if ( n15 < 0x10 ) /*0x665b5e*/
      ptr_new_for_once_2 = ptr_new_for_once; /*0x665b60*/
    ++InstanceCount; /*0x665b66*/
    v22 = (char *)ptr_new_for_once_2 + v18; /*0x665b67*/
    InstanceCount_1 = InstanceCount; /*0x665b69*/
    if ( InstanceCount > InstanceCount_2 ) /*0x665b75*/
    {
      IntArray_Reserve_A((const void **)&InstanceCount_1, InstanceCount + 2 + InstanceCount / 8); /*0x665b8e*/
      InstanceCount = InstanceCount_1; /*0x665b93*/
    }
    if ( v61 + 4 * InstanceCount != 4 ) /*0x665ba5*/
      *(_DWORD *)(v61 + 4 * InstanceCount - 4) = v22; /*0x665ba7*/
    v18 = v17 + 1; /*0x665ba9*/
  }
  if ( v67 > v18 ) /*0x665bb4*/
  {
    ptr_new_for_once_3 = (void **)ptr_new_for_once[0]; /*0x665bbd*/
    if ( n15 < 0x10 ) /*0x665bc3*/
      ptr_new_for_once_3 = ptr_new_for_once; /*0x665bc5*/
    if ( *((_BYTE *)ptr_new_for_once_3 + v18) ) /*0x665bcb*/
    {
      ptr_new_for_once_4 = (void **)ptr_new_for_once[0]; /*0x665bd8*/
      if ( n15 < 0x10 ) /*0x665bde*/
        ptr_new_for_once_4 = ptr_new_for_once; /*0x665be0*/
      p_this = (void **)((char *)ptr_new_for_once_4 + v18); /*0x665be8*/
      FFX_PtrArray_PushBack((const void **)&InstanceCount_1, &p_this); /*0x665bfb*/
      InstanceCount = InstanceCount_1; /*0x665c00*/
    }
  }
  Size = 0; /*0x665c0a*/
  if ( a4 ) /*0x665c14*/
  {
    Global = AsyncQueue_GetGlobal(); /*0x665c17*/
    Size = (size_t)FFX_DynArray_AllocSlot(Global, InstanceCount); /*0x665c23*/
  }
  p_InstanceCount_1 = 0; /*0x665c29*/
  p_InstanceCount = 0; /*0x665c2b*/
  v27 = InstanceCount < 0; /*0x665c31*/
  if ( !InstanceCount ) /*0x665c33*/
  {
LABEL_80:
    if ( v27 && InstanceCount_2 < 0 ) /*0x666013*/
      IntArray_Reserve_A((const void **)&InstanceCount_1, 0); /*0x66601d*/
    if ( v61 ) /*0x66602a*/
      Engine_HeapFreeThunk(v61); /*0x66602d*/
    if ( n15 >= 0x10 ) /*0x66603c*/
      FFX_Heap_Free(ptr_new_for_once[0]); /*0x666044*/
    return 0; /*0x666069*/
  }
  while ( 1 ) /*0x665c4b*/
  {
    Source = *(const char **)(v61 + 4 * p_InstanceCount_1); /*0x665c4b*/
    v29 = strstr(Source, "\n"); /*0x665c4f*/
    if ( v29 ) /*0x665c5c*/
    {
      v30 = v29 - Source; /*0x665c71*/
      strncpy(Destination, Source, v29 - Source); /*0x665c7c*/
      n0x100_1 = v30 - 1; /*0x665c82*/
      if ( n0x100_1 >= 0x100 ) /*0x665c8c*/
        goto LABEL_88; /*0x665c8c*/
      Destination[n0x100_1] = 0; /*0x665c92*/
    }
    else
    {
      if ( p_InstanceCount != InstanceCount - 1 ) /*0x665c67*/
        goto LABEL_78; /*0x665c67*/
      strncpy(Destination, Source, strlen(Source)); /*0x665cb3*/
      n0x100_2 = strlen(Source); /*0x665cbc*/
      if ( n0x100_2 >= 0x100 ) /*0x665ccf*/
        goto LABEL_88; /*0x665ccf*/
      Destination[n0x100_2] = v32; /*0x665cd5*/
    }
    sprintf(Buffer, "%s%s%s", v69, "D3D11/", Destination); /*0x665cfb*/
    Phyre_PStreamReaderFile_ctor(v56, Buffer); /*0x665d11*/
    LOBYTE(v72) = 4; /*0x665d1c*/
    if ( !Phyre_SectionData_GetPointerFromOffset((char *)v56) ) /*0x665d20*/
      break; /*0x665d20*/
    Phyre_SectionData_GetPointer((char *)v56); /*0x665d33*/
    Str = (char *)FFX_GameAllocWrapper_structural(strlen(Destination) + 1); /*0x665d5b*/
    strcpy(Str, Destination); /*0x665d68*/
    p_this = FFX_GameAllocWrapper_structural(strlen(Buffer) + 1); /*0x665d9a*/
    strcpy((char *)p_this, Buffer); /*0x665da7*/
    slotIdx = 0; /*0x665db9*/
    slotIdx_1 = this_1[13]; /*0x665dbb*/
    v36 = this_1 + 13; /*0x665dbe*/
    if ( !slotIdx_1 ) /*0x665dc3*/
      goto LABEL_56; /*0x665dc3*/
    v37 = (_DWORD *)this_1[15]; /*0x665dc8*/
    while ( *v37 ) /*0x665dd3*/
    {
      ++slotIdx; /*0x665dd5*/
      ++v37; /*0x665dd6*/
      if ( slotIdx >= slotIdx_1 ) /*0x665ddb*/
        goto LABEL_56; /*0x665ddb*/
    }
    *(_DWORD *)(this_1[15] + 4 * slotIdx) = &Format__0; /*0x665ddf*/
    this_2 = this_1; /*0x665de6*/
    *(_DWORD *)(this_1[21] + 4 * slotIdx) = &Format__0; /*0x665def*/
    *(_DWORD *)(this_2[24] + 4 * slotIdx) = 0; /*0x665df9*/
    if ( slotIdx == -1 ) /*0x665e03*/
    {
LABEL_56:
      if ( ++*v36 > v36[1] ) /*0x665e10*/
        IntArray_Reserve_A((const void **)v36, *v36 + 2 + *v36 / 8); /*0x665e25*/
      if ( v36[2] + 4 * *v36 != 4 ) /*0x665e35*/
        *(_DWORD *)(v36[2] + 4 * *v36 - 4) = &Format__0; /*0x665e37*/
      this_3 = this_1; /*0x665e3d*/
      ++this_1[19]; /*0x665e43*/
      v40 = this_3[19]; /*0x665e46*/
      v41 = this_3 + 19; /*0x665e4c*/
      if ( v40 > this_3[20] ) /*0x665e4f*/
      {
        IntArray_Reserve_A((const void **)v41, v40 + 2 + v40 / 8); /*0x665e64*/
        this_3 = this_1; /*0x665e69*/
      }
      if ( v41[2] + 4 * *v41 != 4 ) /*0x665e7a*/
        *(_DWORD *)(v41[2] + 4 * *v41 - 4) = &Format__0; /*0x665e7c*/
      v42 = ++this_3[22]; /*0x665e85*/
      v43 = this_3 + 22; /*0x665e8b*/
      if ( v42 > this_3[23] ) /*0x665e8e*/
      {
        Phyre_Vector_ReserveInt((const void **)v43, v42 + 2 + v42 / 8); /*0x665ea3*/
        this_3 = this_1; /*0x665ea8*/
      }
      if ( v43[2] + 4 * *v43 != 4 ) /*0x665eb9*/
        *(_DWORD *)(v43[2] + 4 * *v43 - 4) = 0; /*0x665ebb*/
      v44 = ++this_3[16]; /*0x665ec4*/
      v45 = this_3 + 16; /*0x665eca*/
      if ( v44 > this_3[17] ) /*0x665ecd*/
        Struct20Array_Reserve((const void **)v45, v44 + 2 + v44 / 8); /*0x665ee2*/
      v46 = (_DWORD *)(v45[2] + 4 * (5 * *v45 - 5)); /*0x665ef2*/
      if ( v46 ) /*0x665ef7*/
      {
        *v46 = v56[7]; /*0x665eff*/
        v46[1] = v56[8]; /*0x665f07*/
        v46[2] = v56[9]; /*0x665f10*/
        v46[3] = v56[10]; /*0x665f19*/
        v46[4] = v56[11]; /*0x665f22*/
      }
      slotIdx = *v36 - 1; /*0x665f27*/
    }
    if ( a4 ) /*0x665f2c*/
    {
      Size_3 = Size; /*0x665f59*/
      v47 = AsyncQueue_GetGlobal(); /*0x665f5f*/
      AsyncQueue_PushTask(v47, Size_3, Buffer, (int)FFX_AsyncQ_ShaderParseResourceName, 4); /*0x665f65*/
    }
    else
    {
      strPtrArray = 0; /*0x665f76*/
      FileCache = FFX_TexAnim_GetFileCache(); /*0x665f80*/
      strPtrArray = Phyre_Shader_LoadFromPath(FileCache, Buffer); /*0x665f8c*/
      GetGlobalSystemContext(); /*0x665f92*/
      v49 = FFX_Shader_ResolveAndRefStrings(&strPtrArray, 1); /*0x665fa5*/
      if ( v49 ) /*0x665fac*/
      {
        LOBYTE(v72) = 3; /*0x666077*/
        Phyre_PStreamReaderFile_dtor(v56); /*0x66607b*/
        if ( v61 ) /*0x666088*/
          Engine_HeapFreeThunk(v61); /*0x66608b*/
        if ( n15 >= 0x10 ) /*0x66609a*/
          FFX_Heap_Free(ptr_new_for_once[0]); /*0x6660a2*/
        return v49; /*0x6660ac*/
      }
      this_4 = this_1; /*0x665fb2*/
      Str_1 = Str; /*0x665fb8*/
      p_this_1 = p_this; /*0x665fc1*/
      *(_DWORD *)(this_1[24] + 4 * slotIdx) = 1; /*0x665fc7*/
      *(_DWORD *)(this_4[15] + 4 * slotIdx) = Str_1; /*0x665fd5*/
      *(_DWORD *)(this_4[21] + 4 * slotIdx) = p_this_1; /*0x665fdc*/
      FFX_Shader_ParseResourceName(slotIdx, n2, Str_1); /*0x665fdf*/
    }
    LOBYTE(v72) = 3; /*0x665fea*/
    Phyre_PStreamReaderFile_dtor(v56); /*0x665fee*/
LABEL_78:
    p_InstanceCount_1 = p_InstanceCount + 1; /*0x665ff3*/
    p_InstanceCount = p_InstanceCount_1; /*0x665ffa*/
    if ( p_InstanceCount_1 >= InstanceCount ) /*0x666002*/
    {
      v27 = InstanceCount < 0; /*0x666008*/
      goto LABEL_80; /*0x666008*/
    }
  }
  LOBYTE(v72) = 3; /*0x6660ae*/
  Phyre_PStreamReaderFile_dtor(v56); /*0x6660b2*/
  if ( v61 ) /*0x6660bf*/
    Engine_HeapFreeThunk(v61); /*0x6660c2*/
LABEL_96:
  if ( n15 >= 0x10 ) /*0x6660d1*/
    FFX_Heap_Free(ptr_new_for_once[0]); /*0x6660d9*/
  return 5; /*0x66604e*/
}