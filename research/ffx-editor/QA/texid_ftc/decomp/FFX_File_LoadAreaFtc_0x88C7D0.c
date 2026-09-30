// [Jarvis lot34] Subagent-harvested loader/descriptor lot from repo docs; validated in live IDA before promotion.
// FFX File: Load area FTC
char *__cdecl FFX_File_LoadAreaFtc(char *Str)
{
  char *v1; // eax
  int *StreamReaderWithErrorDialog; // ebx
  DWORD nNumberOfBytesToRead; // edi
  char *lpBuffer; // esi
  const char *%sjppc/; // [esp-8h] [ebp-1D8h]
  char Buffer_1[256]; // [esp+Ch] [ebp-1C4h] BYREF
  char ArgList[128]; // [esp+10Ch] [ebp-C4h] BYREF
  char Buffer[64]; // [esp+18Ch] [ebp-44h] BYREF

  switch ( FFX_JobSchedule_GetThreadDataPlus4() ) /*0x88c7f3*/
  {
    case 0: /*0x88c7f3*/
      %sjppc/ = "%sjppc/"; /*0x88c7ff*/
      break; /*0x88c804*/
    case 2: /*0x88c7f3*/
      %sjppc/ = "%sfrpc/"; /*0x88c80b*/
      break; /*0x88c810*/
    case 3: /*0x88c7f3*/
      %sjppc/ = "%ssppc/"; /*0x88c817*/
      break; /*0x88c81c*/
    case 4: /*0x88c7f3*/
      %sjppc/ = "%sdepc/"; /*0x88c823*/
      break; /*0x88c828*/
    case 5: /*0x88c7f3*/
      %sjppc/ = "%sitpc/"; /*0x88c82f*/
      break; /*0x88c834*/
    case 9: /*0x88c7f3*/
      %sjppc/ = "%skrpc/"; /*0x88c83b*/
      break; /*0x88c840*/
    case 10: /*0x88c7f3*/
      %sjppc/ = "%schpc/"; /*0x88c847*/
      break; /*0x88c84c*/
    default:
      %sjppc/ = "%suspc/"; /*0x88c853*/
      break; /*0x88c853*/
  }
  sprintf(Buffer, %sjppc/, "/ffx_ps2/ffx/master/new_"); /*0x88c862*/
  if ( strstr(Str, "_") ) /*0x88c873*/
  {
    sprintf(ArgList, "%sbattle/btl/%s/%s.ftc", Buffer, Str, Str); /*0x88c88e*/
  }
  else if ( strstr(Str, "base") ) /*0x88c89e*/
  {
    sprintf(ArgList, "%smenu/base.ftc", Buffer); /*0x88c8b7*/
  }
  else if ( strstr(Str, "newkit") ) /*0x88c8c4*/
  {
    sprintf(ArgList, "%smenu/newkit.ftc", Buffer); /*0x88c8dd*/
  }
  else if ( strstr(Str, "help") ) /*0x88c8ea*/
  {
    sprintf(ArgList, "%shelp/help.ftc", Buffer); /*0x88c903*/
  }
  else
  {
    v1 = strstr(Str, SubStr_2); /*0x88c910*/
    sprintf(ArgList, "%sevent/obj_ps3/%s%s.ftc", Buffer, Str, v1); /*0x88c924*/
  }
  FFX_FileSystem_BuildDataPath(ArgList, Buffer_1, 256); /*0x88c93c*/
  sprintf_s(ArgList, 0x7Fu, (const char *const)&g_vtable_PTTYCallback_Phyre.slot2, Buffer_1); /*0x88c956*/
  if ( Phyre_File_ReadEntireFile_ww(ArgList) ) /*0x88c963*/
  {
    StreamReaderWithErrorDialog = FFX_FileIO_CreateStreamReaderWithErrorDialog(ArgList, (wchar_t *)1); /*0x88c97d*/
    nNumberOfBytesToRead = (FFX_FileIO_PStreamWriter_GetSizeSafe(StreamReaderWithErrorDialog) + 15) & 0xFFFFFFF0; /*0x88c98a*/
    SgMem_SetAlignment(64); /*0x88c98d*/
    lpBuffer = (char *)FFX_Heap_AllocGameArenaDebugFill_wrapper( /*0x88c9ac*/
                         ((((int)(nNumberOfBytesToRead + 2047) >> 31) & 0x7FF) + nNumberOfBytesToRead + 2047)
                       & 0xFFFFF800);
    *(_DWORD *)lpBuffer = 0; /*0x88c9b1*/
    FFX_FileIO_PFileStream_ReadSafe((void **)StreamReaderWithErrorDialog, lpBuffer, nNumberOfBytesToRead); /*0x88c9b7*/
    FFX_FileIO_StreamWriterCloseAndFree(StreamReaderWithErrorDialog); /*0x88c9bd*/
    return lpBuffer; /*0x88c9c5*/
  }
  else
  {
    dbgPrintf(); /*0x88c9de*/
    return 0; /*0x88c9ed*/
  }
}
