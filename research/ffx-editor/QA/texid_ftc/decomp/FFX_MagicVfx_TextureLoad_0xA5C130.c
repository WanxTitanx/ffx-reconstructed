// FFX MagicVfx: Texture load
int __cdecl FFX_MagicVfx_TextureLoad(
        __int64 [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg,
        int a2,
        int a3,
        unsigned __int64 a4,
        unsigned __int64 a5,
        int n2)
{
  int v6; // ebx
  int n2_1; // edx
  int v8; // ecx
  int v9; // esi
  int v10; // edi
  unsigned __int64 v11; // kr00_8
  int v13; // [esp+Ch] [ebp-1F78h]
  int v14; // [esp+10h] [ebp-1F74h]
  char *Source_1; // [esp+14h] [ebp-1F70h]
  int v16[30]; // [esp+18h] [ebp-1F6Ch] BYREF
  int v17[30]; // [esp+90h] [ebp-1EF4h] BYREF
  int v18[30]; // [esp+108h] [ebp-1E7Ch] BYREF
  char Source[7680]; // [esp+180h] [ebp-1E04h] BYREF

  memset(v17, 0, sizeof(v17)); /*0xa5c158*/
  memset(v18, 0, sizeof(v18)); /*0xa5c172*/
  v16[0] = 1; /*0xa5c18c*/
  memset(&v16[1], 0, 0x74u); /*0xa5c196*/
  v6 = *(__int16 *)(a2 + 16); /*0xa5c19b*/
  n2_1 = n2; /*0xa5c1a2*/
  v8 = 0; /*0xa5c1a5*/
  v9 = a2 + *(_DWORD *)(a2 + 4); /*0xa5c1aa*/
  v14 = 0; /*0xa5c1ac*/
  if ( v6 <= 0 ) /*0xa5c1b4*/
  {
LABEL_12:
    FFX_TextureSlot_MatrixInit([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg, 2 * (n2_1 != 0) + 8); /*0xa5c2c6*/
    FFX_Ps3Data_BuildTextureSlotRecord_LoadTime( /*0xa5c306*/
      [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg,
      v14,
      (int)v17,
      v18,
      Source,
      (int)v16);
    return 1; /*0xa5c323*/
  }
  v10 = v13; /*0xa5c1ba*/
  Source_1 = Source; /*0xa5c1c6*/
  while ( *(_BYTE *)(v9 + 1) != 3 ) /*0xa5c1d4*/
  {
LABEL_11:
    Source_1 += 256; /*0xa5c2a5*/
    v6 -= *(__int16 *)(v9 + 2); /*0xa5c2b3*/
    ++v8; /*0xa5c2b5*/
    v9 = v10; /*0xa5c2b6*/
    v14 = v8; /*0xa5c2b8*/
    if ( v6 <= 0 ) /*0xa5c2c0*/
      goto LABEL_12; /*0xa5c2c0*/
  }
  v17[v8] = 3 * *(__int16 *)(v9 + 2); /*0xa5c1e1*/
  v18[v8] = 3 * *(__int16 *)(v9 + 2); /*0xa5c1ef*/
  if ( n2_1 == 1 ) /*0xa5c1f9*/
  {
    v11 = a4; /*0xa5c1fe*/
  }
  else if ( n2_1 == 2 ) /*0xa5c206*/
  {
    v11 = a5; /*0xa5c20e*/
  }
  else
  {
    v11 = *(_QWORD *)(v9 + 8); /*0xa5c218*/
  }
  if ( FFX_Texture_ResolveDdsByDescriptor( /*0xa5c27c*/
         v11 & 0x3FFF,
         (v11 >> 20) & 0x3F,
         0,
         0,
         1 << ((v11 >> 26) & 0xF),
         1 << ((v11 >> 30) & 0xF),
         Source_1) )
  {
    v8 = v14; /*0xa5c290*/
    n2_1 = n2; /*0xa5c296*/
    v10 = v9 + 8 * (*(__int16 *)(v9 + 2) + 4 * *(__int16 *)(v9 + 2) + 2); /*0xa5c2a2*/
    goto LABEL_11; /*0xa5c2a2*/
  }
  dbgPrintf(); /*0xa5c349*/
  return 0; /*0xa5c313*/
}