// FFX FieldMap: Load and process field VPA
int __cdecl FFX_FieldMap_LoadAndProcessFieldVpa(char *Str)
{
  int *v1; // eax
  int *v2; // ebx
  size_t Size; // esi
  int *lpBuffer; // edi
  int v6[256]; // [esp+8h] [ebp-1004h] BYREF
  char v7[1024]; // [esp+408h] [ebp-C04h] BYREF
  char Buffer[1024]; // [esp+808h] [ebp-804h] BYREF
  char v9[1024]; // [esp+C08h] [ebp-404h] BYREF

  FFX_FieldMap_ResetState(); /*0x90969c*/
  FFX_GenericStub_Return0(); /*0x9096a5*/
  FFX_FieldMap_InitFieldPtrState(yiBGRender); /*0x9096af*/
  unk_1934EDC = -1; /*0x9096b6*/
  flag = -1; /*0x9096c0*/
  Sg_MapSetPtr(0); /*0x9096ca*/
  FFX_FieldMap_SplitFilePath(Str, v9, (int)v7, v6); /*0x9096e5*/
  sprintf(Buffer, "host0:%s%s.vpa", v9, v7); /*0x909704*/
  v1 = FFX_FileSystem_BuildFFXPs2Path((int)Buffer, (wchar_t *)1); /*0x909713*/
  v2 = v1; /*0x909718*/
  if ( v1 ) /*0x90971f*/
  {
    Size = FFX_File_SeekWrapper(v1, 0, 2u); /*0x909731*/
    FFX_File_SeekWrapper(v2, 0, 0); /*0x909733*/
    lpBuffer = FFX_Heap_AllocGameArena_Thunk(Size); /*0x90973e*/
    FFX_File_ReadWrapper((void **)v2, lpBuffer, Size); /*0x909743*/
    FFX_Mem_FreeWrapper(v2); /*0x909749*/
    if ( lpBuffer ) /*0x909753*/
    {
      FFX_GS_ProcessDmaPacketIf272(yiBGRender, lpBuffer); /*0x90975b*/
      word_18DED08 |= 0x11u; /*0x909760*/
      MEMORY[0x19138A8][0] = (int)lpBuffer; /*0x90976c*/
      unk_18DED0C = -1; /*0x909772*/
      FFX_FieldMap_ProcessSchedSlots(yiBGRender); /*0x90977c*/
    }
  }
  unk_1934ED4 = -1; /*0x90978b*/
  unk_1934ED8 = -1; /*0x909795*/
  unk_1934EDC = -1; /*0x90979f*/
  flag = -1; /*0x9097a9*/
  return 0; /*0x909785*/
}