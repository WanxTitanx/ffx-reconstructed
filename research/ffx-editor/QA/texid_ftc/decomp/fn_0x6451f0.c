// FFX Ps3Data: Build texture slot record at load time
int __cdecl FFX_Ps3Data_BuildTextureSlotRecord_LoadTime(__int64 a1, int a2, int a3, _DWORD *a4, char *Source, int a6)
{
  int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg; // eax
  int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1; // esi
  _DWORD *v8; // ecx
  _DWORD *v9; // edx
  const char *Source_1; // edi
  int v11; // ebx
  int *v12; // eax
  int ActiveSlot; // eax
  int v14; // edi
  int v15; // edx
  char *Source_2; // ecx
  _BYTE *v17; // edx
  char v18; // al
  bool v19; // zf
  int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_3; // [esp+0h] [ebp-Ch] BYREF
  void *v21; // [esp+4h] [ebp-8h] BYREF
  int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_2; // [esp+8h] [ebp-4h]
  char v23; // [esp+1Bh] [ebp+Fh]
  int v24; // [esp+20h] [ebp+14h]

  [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = HIDWORD(a1) | a1;// [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass. /*0x6451fe*/
  if ( a1 )
  {
    [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = FFX_TextureSlot_FindOrCacheByKeyEx( /*0x64520f*/
                                                                        (unsigned int *)host,
                                                                        a1,
                                                                        HIDWORD(a1));
    [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 = [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg; /*0x645214*/
    [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_2 = [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg; /*0x645216*/
    if ( [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg )
    {
      *(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg + 144) = a2; /*0x645225*/
      v23 = 0; /*0x64522b*/
      if ( a2 == 1
        && FFX_TextureSlot_AllocSlot(
             (int *)host,
             &v21,
             &[Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_3) )
      {
        v8 = v21; /*0x64524b*/
        [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_3; /*0x64524e*/
        *(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 + 148) = v21; /*0x645251*/
        v8[8] = [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg; /*0x645257*/
        v23 = 1; /*0x64525a*/
      }
      else
      {
        [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = (int)FFX_GameAllocWrapper_structural(
                                                                                 (108
                                                                                * (unsigned __int64)(unsigned int)a2) >> 32 != 0
                                                                               ? -1
                                                                               : 108 * a2);
        *(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 + 148) = [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg; /*0x64527b*/
      }
      if ( a2 > 0 ) /*0x645283*/
      {
        v9 = a4; /*0x645289*/
        v24 = a3 - (_DWORD)a4; /*0x64528f*/
        Source_1 = Source; /*0x645292*/
        v11 = 0; /*0x645296*/
        [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_3 = a6 - (_DWORD)a4; /*0x64529a*/
        do /*0x645414*/
        {
          *(_DWORD *)(*(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 + 148) + v11 + 4) = *(_DWORD *)((char *)v9 + v24); /*0x6452b0*/
          *(_DWORD *)(*(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 + 148) + v11 + 8) = *v9; /*0x6452bc*/
          *(_DWORD *)(*(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 + 148) + v11 + 100) = *(_DWORD *)((char *)v9 + v24); /*0x6452cc*/
          *(_DWORD *)(*(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 + 148) + v11 + 104) = *v9; /*0x6452d8*/
          if ( !v23 ) /*0x6452dc*/
          {
            v12 = FFX_GameAllocWrapper_structural(strlen(Source_1) + 1); /*0x6452f0*/
            v9 = a4; /*0x6452fb*/
            *(_DWORD *)(*(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 + 148) + v11 + 32) = v12; /*0x645301*/
          }
          if ( a6 ) /*0x645309*/
            *(_DWORD *)(v11 + *(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 + 148)) = *(_DWORD *)((char *)v9 + [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_3); /*0x645317*/
          ActiveSlot = FFX_Shader_GetActiveSlot((void *)MEMORY[0xCDEDE0]); /*0x645320*/
          v14 = 7 * ActiveSlot; /*0x64533b*/
          *(_DWORD *)(v11 /*0x645349*/
                    + *(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_2 + 148)
                    + 4 * v14
                    + 44) = *(_DWORD *)(*(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_2
                                                  + 148)
                                      + v11
                                      + 4);
          [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 = [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_2; /*0x64534f*/
          v15 = v11 + 28 * (ActiveSlot ^ 1); /*0x645352*/
          *(_DWORD *)(*(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_2 + 148) + v15 + 44) = 0; /*0x64535b*/
          *(_DWORD *)(v11 /*0x645372*/
                    + *(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 + 148)
                    + 4 * v14
                    + 48) = *(_DWORD *)(v11
                                      + *(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1
                                                  + 148)
                                      + 8);
          *(_DWORD *)(*(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 + 148) + v15 + 48) = 0; /*0x64537f*/
          *(_DWORD *)(*(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 + 148) + v11 + 52) = 0; /*0x64538d*/
          *(_DWORD *)(*(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 + 148) + v11 + 80) = 0; /*0x64539b*/
          if ( v23 ) /*0x6453a3*/
          {
            Source_2 = Source; /*0x6453d7*/
            v17 = *(_BYTE **)(*(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 + 148) /*0x6453d9*/
                            + v11
                            + 32);
            do /*0x6453ec*/
            {
              v18 = *Source_2; /*0x6453e0*/
              *v17++ = *Source_2++; /*0x6453e2*/
            }
            while ( v18 ); /*0x6453ec*/
          }
          else
          {
            strncpy( /*0x6453c6*/
              *(char **)(*(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 + 148) + v11 + 32),
              Source,
              strlen(Source) + 1);
          }
          [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg = *(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 /*0x6453ee*/
                                                                                      + 148);
          *(_DWORD *)([Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg + v11 + 36) = 1; /*0x6453f7*/
          v9 = a4 + 1; /*0x6453ff*/
          Source_1 = Source + 256; /*0x645402*/
          v11 += 108; /*0x645408*/
          v19 = a2-- == 1; /*0x64540b*/
          ++a4; /*0x64540e*/
          Source += 256; /*0x645411*/
        }
        while ( !v19 ); /*0x645414*/
      }
    }
  }
  return [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg; /*0x64541d*/
}