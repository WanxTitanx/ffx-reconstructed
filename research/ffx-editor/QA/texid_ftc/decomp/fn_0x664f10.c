// FFX MagicHost: Load texture list
void __fastcall FFX_MagicHost_LoadTexList(FFXMagicHost *host, const char *listName)
{
  int source_copy_40; // ecx
  int *p_source_copy_40; // edx
  int source_copy_2; // ebx
  unsigned int source_copy_1; // eax
  _DWORD *buffer_chain_head; // ecx
  int v8; // ecx
  const char *v9; // esi
  const char *v10; // eax
  int source_copy; // [esp+10h] [ebp-208h]
  char Buffer_1[256]; // [esp+14h] [ebp-204h] BYREF
  char Buffer[256]; // [esp+114h] [ebp-104h] BYREF
  int n670; // [esp+220h] [ebp+8h]

  FFX_FileSystem_BuildDataPath("/FFX_Data/GameData/PS3Data/magic", Buffer_1, 256); /*0x664f39*/
  source_copy_40 = host->source_copy_40; /*0x664f3e*/
  p_source_copy_40 = &host->source_copy_40; /*0x664f44*/
  source_copy_2 = -1; /*0x664f4a*/
  source_copy_1 = 0; /*0x664f4d*/
  source_copy = source_copy_40; /*0x664f4f*/
  if ( !source_copy_40 ) /*0x664f57*/
    goto LABEL_10; /*0x664f57*/
  buffer_chain_head = (_DWORD *)host->buffer_chain_head; /*0x664f59*/
  do /*0x664f77*/
  {
    if ( *buffer_chain_head ) /*0x664f60*/
    {
      if ( *buffer_chain_head == n670 ) /*0x664f6c*/
        return; /*0x664f6c*/
    }
    else
    {
      source_copy_2 = source_copy_1; /*0x664f66*/
    }
    p_source_copy_40 = &host->source_copy_40; /*0x664f6e*/
    ++source_copy_1; /*0x664f71*/
    ++buffer_chain_head; /*0x664f72*/
  }
  while ( source_copy_1 < host->source_copy_40 ); /*0x664f77*/
  if ( source_copy_2 < 0 ) /*0x664f7b*/
  {
    source_copy_40 = source_copy; /*0x664f9a*/
LABEL_10:
    v8 = source_copy_40 + 1; /*0x664fa0*/
    *p_source_copy_40 = v8; /*0x664fa1*/
    if ( v8 > p_source_copy_40[1] ) /*0x664fa6*/
    {
      Phyre_Vector_ReserveInt((const void **)&host->source_copy_40, v8 + 2 + v8 / 8); /*0x664fbc*/
      p_source_copy_40 = &host->source_copy_40; /*0x664fc1*/
    }
    if ( p_source_copy_40[2] + 4 * *p_source_copy_40 != 4 ) /*0x664fcf*/
      *(_DWORD *)(p_source_copy_40[2] + 4 * *p_source_copy_40 - 4) = n670; /*0x664fd1*/
    goto LABEL_14; /*0x664fd1*/
  }
  *(_DWORD *)(host->buffer_chain_head + 4 * source_copy_2) = n670; /*0x664f80*/
LABEL_14:
  if ( host[172].field110 == (host[172].field110 & 1) ) /*0x664fe3*/
  {
    LOBYTE(host->next_drawable_ptr) = 1; /*0x664fe7*/
  }
  else
  {
    if ( !*(_DWORD *)(JobSchedule_SetPriority() + 4) /*0x665027*/
      || *(_DWORD *)(JobSchedule_SetPriority() + 4) == 9
      || *(_DWORD *)(JobSchedule_SetPriority() + 4) == 10
      || !FFX_Magic_IsTexListIdSpecial(n670) )
    {
      sprintf(Buffer, "%s/%s/tex/TexList.txt", Buffer_1, (const char *)(host[172].field110 - (host[172].field110 & 1))); /*0x66508d*/
    }
    else
    {
      v9 = (const char *)(host[172].field110 - (host[172].field110 & 1)); /*0x665040*/
      v10 = FFX_Locale_IdToString(); /*0x665042*/
      sprintf(Buffer, "%s/%s/tex_%s/TexList.txt", Buffer_1, v9, v10); /*0x66505c*/
    }
    LOBYTE(host->next_drawable_ptr) = 0; /*0x665096*/
    if ( Global_CCB464_Getter() ) /*0x66509a*/
      FFX_MagicHost_PushStringAsync(2, Buffer); /*0x6650ae*/
    else
      LoadVfxResourceFileList(host, 2, Buffer, 0); /*0x6650cb*/
  }
}