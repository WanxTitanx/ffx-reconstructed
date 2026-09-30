// FFX: Font draws text — draws text using game font
// FFX Font: Draw text
// Font text drawer. Draws text using PBitmapFont with SDF (Signed Distance Field) rendering. Supports multiple font sizes, colors, and special character codes. Font textures in ps3data/fonts/.
char *__cdecl FFX_Font_DrawText(__int16 n15648, unsigned __int8 a2, __int16 a3, __int16 a4, _DWORD *a5)
{
  FFXBattleState *v5; // ecx
  int v6; // esi
  __int16 n8; // ax
  __int16 v8; // dx
  char *_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d; // edi
  int v10; // ebx
  int v11; // eax
  int v12; // ecx
  char v13; // al
  FFXBattleState *v14; // eax
  const char *_Font/D3D11/shadow_0_0.dds.phyre_; // esi
  unsigned int count; // edx
  char *_Font/D3D11/shadow_0_0.dds.phyre__1; // edi
  char v18; // al
  FFXBattleState *v19; // eax
  void **p_g_FFX_FontPath_menu_us_base_ftc_shadow_0_0_dds; // edx
  int v21; // eax
  int v22; // eax
  char **_/FFX_Data/GameData/PS3Data/help/help_ftc/D3D11/font_0_0.dds.ph; // edi
  int CurrentId; // eax
  int v25; // eax
  char **_/FFX_Data/GameData/PS3Data/menu/newkit_ftc/D3D11/shadow_0_0.dd; // edi
  char **_/FFX_Data/GameData/PS3Data/menu/subfont/D3D11/shadow_0_0.dds.p; // edi
  char *BattleFontFullName; // [esp-4h] [ebp-10h]
  __int16 v30; // [esp+20h] [ebp+14h]
  FFXBattleState *v31; // [esp+20h] [ebp+14h]

  LOWORD(v5) = a4; /*0x8acf03*/
  v6 = -1; /*0x8acf0c*/
  if ( a4 ) /*0x8acf13*/
    LOBYTE(n8) = a2 >> 4; /*0x8acf19*/
  else
    LOBYTE(n8) = a2 & 0xF; /*0x8acf15*/
  n8 = (unsigned __int8)n8; /*0x8acf1c*/
  if ( (unsigned __int8)n8 >= 8u ) /*0x8acf23*/
  {
    n8 = (unsigned __int8)n8 - 8; /*0x8acf29*/
    v8 = 1; /*0x8acf2c*/
  }
  else
  {
    v8 = 0; /*0x8acf25*/
  }
  _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = (char *)(unsigned __int16)(2 * n8); /*0x8acf33*/
  v30 = 2 * n8; /*0x8acf3a*/
  if ( n15648 > 15648 ) /*0x8acf42*/
  {
    switch ( n15648 ) /*0x8ad272*/
    {
      case 15664: /*0x8ad272*/
        if ( v8 || (_WORD)v5 ) /*0x8ad2be*/
        {
          v6 = a3 + (__int16)_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d; /*0x8ad2e4*/
          v10 = 1; /*0x8ad2e6*/
          _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = (char *)*(&_FFX_Data_GameData_PS3Data_menu_kr_base_ftc_D3D11_shadow_0_0_d /*0x8ad2eb*/
                                                                                    + v6);// "/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.dds.phyre"
        }
        else
        {
          v10 = 0; /*0x8ad2c7*/
          v6 = a3 + (__int16)_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d; /*0x8ad2ce*/
          _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = (char *)*(&_FFX_Data_GameData_PS3Data_menu_kr_base_ftc_D3D11_font_0_0_dds /*0x8ad2d0*/
                                                                                    + v6);// "/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/font_0_0.dds.phyre"
        }
        goto LABEL_87; /*0x8ad2d3*/
      case 15680: /*0x8ad272*/
        if ( v8 || (_WORD)v5 ) /*0x8ad281*/
        {
          v6 = a3 + (__int16)_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d; /*0x8ad2a7*/
          v10 = 1; /*0x8ad2a9*/
          _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = (char *)*(&g_FFX_FontPath_menu_us_base_ftc_shadow_0_0_dds /*0x8ad2ae*/
                                                                                    + v6);// "/FFX_Data/GameData/PS3Data/menu_us/base_ftc/D3D11/shadow_0_0.dds.phyre"
        }
        else
        {
          v10 = 0; /*0x8ad28a*/
          v6 = a3 + (__int16)_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d; /*0x8ad291*/
          _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = (char *)*(&g_FFX_FontPath_menu_us_base_ftc_font_0_0_dds /*0x8ad293*/
                                                                                    + v6);// "/FFX_Data/GameData/PS3Data/menu_us/base_ftc/D3D11/font_0_0.dds.phyre"
        }
        goto LABEL_87; /*0x8ad296*/
      case 15712: /*0x8ad272*/
        v10 = (__int16)v5; /*0x8ad2f3*/
        CurrentId = FFX_Locale_GetCurrentId((_WORD)v5); /*0x8ad2f6*/
        if ( CurrentId ) /*0x8ad2fe*/
        {
          v25 = CurrentId - 9; /*0x8ad300*/
          if ( v25 ) /*0x8ad303*/
          {
            if ( v25 == 1 ) /*0x8ad306*/
            {
              v6 = a3 + (__int16)_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d; /*0x8ad31b*/
              if ( v10 ) /*0x8ad30a*/
                _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = off_C59B40[a3];// "/FFX_Data/GameData/PS3Data/menu_ch/newkit_ftc/D3D11/shadow_0_0.dds.phyre" /*0x8ad31d*/
              else
                _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = off_C59A40[a3];// "/FFX_Data/GameData/PS3Data/menu_ch/newkit_ftc/D3D11/font_0_0.dds.phyre" /*0x8ad336*/
            }
            else
            {
              _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = *(char **)&_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d[4 * a3]; /*0x8ad348*/
              v6 = a3 + v30; /*0x8ad34b*/
            }
          }
          else
          {
            v6 = a3 + (__int16)_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d; /*0x8ad362*/
            if ( v10 ) /*0x8ad351*/
              _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = off_C59B80[a3];// "/FFX_Data/GameData/PS3Data/menu_kr/newkit_ftc/D3D11/shadow_0_0.dds.phyre" /*0x8ad364*/
            else
              _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = off_C59AC0[a3];// "/FFX_Data/GameData/PS3Data/menu_kr/newkit_ftc/D3D11/font_0_0.dds.phyre" /*0x8ad37a*/
          }
        }
        else
        {
          _/FFX_Data/GameData/PS3Data/menu/newkit_ftc/D3D11/shadow_0_0.dd = _FFX_Data_GameData_PS3Data_menu_newkit_ftc_D3D11_shadow_0_0_dd;// "/FFX_Data/GameData/PS3Data/menu/newkit_ftc/D3D11/shadow_0_0.dds.phyre" /*0x8ad37f*/
          if ( !v10 ) /*0x8ad386*/
            _/FFX_Data/GameData/PS3Data/menu/newkit_ftc/D3D11/shadow_0_0.dd = _FFX_Data_GameData_PS3Data_menu_newkit_ftc_D3D11_shadow_0_0_dd_0;// "/FFX_Data/GameData/PS3Data/menu/newkit_ftc/D3D11/font_0_0.dds.phyre" /*0x8ad388*/
          _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = _/FFX_Data/GameData/PS3Data/menu/newkit_ftc/D3D11/shadow_0_0.dd[a3]; /*0x8ad394*/
          v6 = a3 + v30; /*0x8ad39a*/
        }
        goto LABEL_87; /*0x8ad320*/
      case 15744: /*0x8ad272*/
        v10 = (__int16)v5; /*0x8ad39e*/
        _/FFX_Data/GameData/PS3Data/menu/subfont/D3D11/shadow_0_0.dds.p = _FFX_Data_GameData_PS3Data_menu_subfont_D3D11_shadow_0_0_dds_p;// "/FFX_Data/GameData/PS3Data/menu/subfont/D3D11/shadow_0_0.dds.phyre" /*0x8ad3a1*/
        if ( !(_WORD)v5 ) /*0x8ad3a8*/
          _/FFX_Data/GameData/PS3Data/menu/subfont/D3D11/shadow_0_0.dds.p = _FFX_Data_GameData_PS3Data_menu_subfont_D3D11_shadow_0_0_dds_p_0;// "/FFX_Data/GameData/PS3Data/menu/subfont/D3D11/font_0_0.dds.phyre" /*0x8ad3aa*/
        v6 = a2; /*0x8ad3af*/
        _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = _/FFX_Data/GameData/PS3Data/menu/subfont/D3D11/shadow_0_0.dds.p[a2]; /*0x8ad3b3*/
        goto LABEL_87; /*0x8ad3b3*/
      default:
        goto LABEL_89;
    }
  }
  if ( n15648 == 15648 ) /*0x8acf48*/
  {
    if ( v8 || (_WORD)v5 ) /*0x8ad228*/
    {
      v6 = a3 + (__int16)_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d; /*0x8ad24e*/
      v10 = 1; /*0x8ad250*/
      _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = (char *)*(&FFX_Menu2D_Global_C59728 + v6);// "/FFX_Data/GameData/PS3Data/menu_cn/base_ftc/D3D11/shadow_0_0.dds.phyre" /*0x8ad255*/
    }
    else
    {
      v10 = 0; /*0x8ad231*/
      v6 = a3 + (__int16)_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d; /*0x8ad238*/
      _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = (char *)*(&FFX_Menu2D_Global_C596A8 + v6);// "/FFX_Data/GameData/PS3Data/menu_cn/base_ftc/D3D11/font_0_0.dds.phyre" /*0x8ad23a*/
    }
    goto LABEL_87; /*0x8ad23d*/
  }
  if ( n15648 > 15617 ) /*0x8acf53*/
  {
    if ( n15648 == 15632 ) /*0x8ad1dd*/
    {
      if ( v8 || (_WORD)v5 ) /*0x8ad1eb*/
      {
        v6 = a3 + (__int16)_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d; /*0x8ad211*/
        v10 = 1; /*0x8ad213*/
        _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = (char *)*(&_FFX_Data_GameData_PS3Data_menu_ch_base_ftc_D3D11_shadow_0_0_d /*0x8ad218*/
                                                                                  + v6);// "/FFX_Data/GameData/PS3Data/menu_ch/base_ftc/D3D11/shadow_0_0.dds.phyre"
      }
      else
      {
        v10 = 0; /*0x8ad1f4*/
        v6 = a3 + (__int16)_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d; /*0x8ad1fb*/
        _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = (char *)*(&_FFX_Data_GameData_PS3Data_menu_ch_base_ftc_D3D11_font_0_0_dds /*0x8ad1fd*/
                                                                                  + v6);// "/FFX_Data/GameData/PS3Data/menu_ch/base_ftc/D3D11/font_0_0.dds.phyre"
      }
      goto LABEL_87; /*0x8ad200*/
    }
    goto LABEL_89; /*0x8ad1dd*/
  }
  switch ( n15648 ) /*0x8acf59*/
  {
    case 15617: /*0x8acf59*/
      v10 = (__int16)v5; /*0x8ad11a*/
      v21 = FFX_Locale_GetCurrentId((_WORD)v5); /*0x8ad11d*/
      if ( v21 ) /*0x8ad125*/
      {
        v22 = v21 - 9; /*0x8ad12b*/
        if ( v22 ) /*0x8ad12e*/
        {
          if ( v22 == 1 ) /*0x8ad131*/
          {
            v6 = a3 + (__int16)_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d; /*0x8ad146*/
            if ( v10 ) /*0x8ad135*/
              _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = (&MES_HELP_EXTRAFONT_SHADOW_CH_PATH)[a3];// "/FFX_Data/GameData/PS3Data/help_ch/help_ftc/D3D11/shadow_0_0.dds.phyre" /*0x8ad148*/
            else
              _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = (&off_C598B8)[a3];// "/FFX_Data/GameData/PS3Data/help_ch/help_ftc/D3D11/font_0_0.dds.phyre" /*0x8ad161*/
          }
          else
          {
            _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = *(char **)&_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d[4 * a3]; /*0x8ad176*/
            v6 = a3 + v30; /*0x8ad179*/
          }
        }
        else
        {
          v6 = a3 + (__int16)_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d; /*0x8ad193*/
          if ( v10 ) /*0x8ad182*/
            _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = (&MES_HELP_EXTRAFONT_SHADOW_KR_PATH)[a3];// "/FFX_Data/GameData/PS3Data/help_kr/help_ftc/D3D11/shadow_0_0.dds.phyre" /*0x8ad195*/
          else
            _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = (&off_C598F8)[a3];// "/FFX_Data/GameData/PS3Data/help_kr/help_ftc/D3D11/font_0_0.dds.phyre" /*0x8ad1ae*/
        }
      }
      else
      {
        _/FFX_Data/GameData/PS3Data/help/help_ftc/D3D11/font_0_0.dds.ph = &MES_HELP_EXTRAFONT_SHADOW_PATH;// "/FFX_Data/GameData/PS3Data/help/help_ftc/D3D11/shadow_0_0.dds.phyre" /*0x8ad1b6*/
        if ( !v10 ) /*0x8ad1bd*/
          _/FFX_Data/GameData/PS3Data/help/help_ftc/D3D11/font_0_0.dds.ph = &off_C59878;// "/FFX_Data/GameData/PS3Data/help/help_ftc/D3D11/font_0_0.dds.phyre" /*0x8ad1bf*/
        _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = _/FFX_Data/GameData/PS3Data/help/help_ftc/D3D11/font_0_0.dds.ph[a3]; /*0x8ad1cb*/
        v6 = a3 + v30; /*0x8ad1d1*/
      }
      break;
    case 15360: /*0x8acf59*/
      v10 = v8 || (_WORD)v5; /*0x8ad0bd*/
      if ( FFX_Locale_GetLanguageId_Thunk() ) /*0x8ad0c2*/
      {
        p_g_FFX_FontPath_menu_us_base_ftc_shadow_0_0_dds = &g_FFX_FontPath_menu_us_base_ftc_shadow_0_0_dds;// "/FFX_Data/GameData/PS3Data/menu_us/base_ftc/D3D11/shadow_0_0.dds.phyre" /*0x8ad0fb*/
        if ( !v10 ) /*0x8ad102*/
          p_g_FFX_FontPath_menu_us_base_ftc_shadow_0_0_dds = &g_FFX_FontPath_menu_us_base_ftc_font_0_0_dds;// "/FFX_Data/GameData/PS3Data/menu_us/base_ftc/D3D11/font_0_0.dds.phyre" /*0x8ad104*/
        v6 = a3 + (__int16)_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d; /*0x8ad110*/
        _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = (char *)p_g_FFX_FontPath_menu_us_base_ftc_shadow_0_0_dds[v6]; /*0x8ad112*/
      }
      else
      {
        v6 = a3 + (__int16)_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d; /*0x8ad0db*/
        if ( v10 ) /*0x8ad0cd*/
          _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = (char *)*(&g_FFX_FontPath_menu_base_ftc_shadow_0_0_dds /*0x8ad0dd*/
                                                                                    + v6);// "/FFX_Data/GameData/PS3Data/menu/base_ftc/D3D11/shadow_0_0.dds.phyre"
        else
          _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = (char *)*(&g_FFX_FontPath_menu_base_ftc_font_0_0_dds /*0x8ad0f3*/
                                                                                    + v6);// "/FFX_Data/GameData/PS3Data/menu/base_ftc/D3D11/font_0_0.dds.phyre"
      }
      break;
    case 15616: /*0x8acf59*/
      v10 = v8 || (_WORD)v5; /*0x8acf83*/
      v11 = FFX_Battle_QueueGateCheck(v5); /*0x8acf88*/
      v12 = 0; /*0x8acf8d*/
      if ( v11 ) /*0x8acf91*/
      {
        do /*0x8ad031*/
        {
          v18 = BattleFontSubPath[v12]; /*0x8ad020*/
          BattleFontFullName[v12++] = v18; /*0x8ad026*/
        }
        while ( v18 ); /*0x8ad031*/
        v19 = (FFXBattleState *)((__int16)_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d + a3); /*0x8ad03a*/
        v31 = v19; /*0x8ad03c*/
        if ( v10 ) /*0x8ad041*/
          _Font/D3D11/shadow_0_0.dds.phyre_ = FONT_SHADOW_NAME[(_DWORD)v19];// "Font/D3D11/shadow_0_0.dds.phyre" /*0x8ad04a*/
        else
          _Font/D3D11/shadow_0_0.dds.phyre_ = FONT_NAME[(_DWORD)v19];// "Font/D3D11/font_0_0.dds.phyre" /*0x8ad071*/
        count = strlen(_Font/D3D11/shadow_0_0.dds.phyre_) + 1; /*0x8ad05c*/
        _Font/D3D11/shadow_0_0.dds.phyre__1 = &BattleFontFullName[strlen(BattleFontFullName)]; /*0x8ad05e*/
        BattleFontFullName = BattleFontFullName; /*0x8ad08a*/
      }
      else
      {
        do /*0x8acfb1*/
        {
          v13 = EventFontSubPath[v12]; /*0x8acfa0*/
          EventFontFullName[v12++] = v13; /*0x8acfa6*/
        }
        while ( v13 ); /*0x8acfb1*/
        v14 = (FFXBattleState *)((__int16)_/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d + a3); /*0x8acfba*/
        v31 = v14; /*0x8acfbc*/
        if ( v10 ) /*0x8acfc1*/
          _Font/D3D11/shadow_0_0.dds.phyre_ = FONT_SHADOW_NAME[(_DWORD)v14];// "Font/D3D11/shadow_0_0.dds.phyre" /*0x8acfca*/
        else
          _Font/D3D11/shadow_0_0.dds.phyre_ = FONT_NAME[(_DWORD)v14];// "Font/D3D11/font_0_0.dds.phyre" /*0x8acff9*/
        count = strlen(_Font/D3D11/shadow_0_0.dds.phyre_) + 1; /*0x8acfdc*/
        _Font/D3D11/shadow_0_0.dds.phyre__1 = &EventFontFullName[strlen(EventFontFullName)]; /*0x8acfde*/
        BattleFontFullName = EventFontFullName; /*0x8acfe8*/
      }
      qmemcpy(_Font/D3D11/shadow_0_0.dds.phyre__1, _Font/D3D11/shadow_0_0.dds.phyre_, count); /*0x8ad094*/
      v6 = (int)v31; /*0x8ad0a2*/
      _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d = FFX_Menu_MenuTransitionCb(BattleFontFullName); /*0x8ad0a5*/
      break; /*0x8ad0aa*/
    default:
LABEL_89:
      dbgPrintf(); /*0x8ad3de*/
      goto LABEL_90; /*0x8ad3e3*/
  }
LABEL_87:
  if ( v10 ) /*0x8ad3b8*/
  {
    *a5 = dword_B5F8D8[2 * (v6 / 2)]; /*0x8ad3cb*/
    a5[1] = dword_B5F8DC[2 * (v6 / 2)]; /*0x8ad3d8*/
    return _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d; /*0x8ad3dd*/
  }
LABEL_90:
  *a5 = dword_B5F898[2 * (v6 / 2)]; /*0x8ad3ee*/
  a5[1] = dword_B5F89C[2 * (v6 / 2)]; /*0x8ad408*/
  return _/FFX_Data/GameData/PS3Data/menu_kr/base_ftc/D3D11/shadow_0_0.d; /*0x8ad3d6*/
}