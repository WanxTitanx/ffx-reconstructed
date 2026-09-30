// ===== xref:mem_s_392930_1d7e :: _lambda_35d4fc73e1a8a511f03c88debc717f0c_::operator() @ 0x100017c0 (ref 0x100017d9) =====
unsigned int __thiscall lambda_35d4fc73e1a8a511f03c88debc717f0c_::operator()(
        UNX_KillMeNow::__l8::<lambda_35d4fc73e1a8a511f03c88debc717f0c> *this,
        void *__formal)
{
  SK_ICommandProcessor *CommandProcessor; // eax
  HANDLE CurrentThread; // eax
  char v5; // [esp+0h] [ebp-54h] BYREF
  std::string v6; // [esp+8h] [ebp-4Ch] BYREF
  std::string v7; // [esp+20h] [ebp-34h] BYREF
  std::string v8; // [esp+38h] [ebp-1Ch] BYREF

  Sleep(0x1388u);
  CommandProcessor = SK_GetCommandProcessor();
  CommandProcessor->ProcessCommandLine(CommandProcessor, (SK_ICommandResult *)&v5, "mem s 392930 1d7e");
  std::string::_Tidy_deallocate(&v8);
  std::string::_Tidy_deallocate(&v7);
  std::string::_Tidy_deallocate(&v6);
  CurrentThread = GetCurrentThread();
  CloseHandle(CurrentThread);
  return 0;
}


// ===== xref:mem_s_392930_1d7e :: _lambda_35d4fc73e1a8a511f03c88debc717f0c_::_lambda_invoker_stdcall_ @ 0x10001830 (ref 0x10001849) =====
unsigned int __stdcall lambda_35d4fc73e1a8a511f03c88debc717f0c_::_lambda_invoker_stdcall_(void *__p1)
{
  SK_ICommandProcessor *CommandProcessor; // eax
  HANDLE CurrentThread; // eax
  char v4; // [esp+0h] [ebp-54h] BYREF
  std::string v5; // [esp+8h] [ebp-4Ch] BYREF
  std::string v6; // [esp+20h] [ebp-34h] BYREF
  std::string v7; // [esp+38h] [ebp-1Ch] BYREF

  Sleep(0x1388u);
  CommandProcessor = SK_GetCommandProcessor();
  CommandProcessor->ProcessCommandLine(CommandProcessor, (SK_ICommandResult *)&v4, "mem s 392930 1d7e");
  std::string::_Tidy_deallocate(&v7);
  std::string::_Tidy_deallocate(&v6);
  std::string::_Tidy_deallocate(&v5);
  CurrentThread = GetCurrentThread();
  CloseHandle(CurrentThread);
  return 0;
}


// ===== xref:mem_s_392930_1deb :: ?UNX_KillMeNow@@YA_NXZ @ 0x1001e070 (ref 0x1001e3ea) =====
char __cdecl UNX_KillMeNow()
{
  SK_ICommandProcessor *v0; // eax
  char *Ptr; // ecx
  char *_Ptr; // eax
  char *_Ptr_1; // ecx
  char *_Ptr_2; // eax
  char *_Ptr_3; // ecx
  char *_Ptr_4; // eax
  SK_ICommandProcessor *v7; // eax
  char *_Ptr_5; // ecx
  char *_Ptr_6; // eax
  char *_Ptr_7; // ecx
  char *_Ptr_8; // eax
  char *_Ptr_9; // ecx
  char *_Ptr_10; // eax
  SK_ICommandProcessor *CommandProcessor; // eax
  _BYTE v16[8]; // [esp+0h] [ebp-54h] BYREF
  std::string v17; // [esp+8h] [ebp-4Ch] BYREF
  std::string v18; // [esp+20h] [ebp-34h] BYREF
  std::string block; // [esp+38h] [ebp-1Ch] BYREF

  if ( game_type == GAME_FFX )
  {
    if ( UNX_IsInBattle() )
    {
      ffx.party->vitals.current.HP = 0;
      ffx.party[1].vitals.current.HP = 0;
      ffx.party[2].vitals.current.HP = 0;
      ffx.party[3].vitals.current.HP = 0;
      ffx.party[4].vitals.current.HP = 0;
      ffx.party[5].vitals.current.HP = 0;
      ffx.party[6].vitals.current.HP = 0;
      ffx.party[7].vitals.current.HP = 0;
      CommandProcessor = SK_GetCommandProcessor();
      CommandProcessor->ProcessCommandLine(CommandProcessor, (SK_ICommandResult *)v16, "mem s 392930 1deb");
      std::string::_Tidy_deallocate(&block);
      std::string::_Tidy_deallocate(&v18);
      std::string::_Tidy_deallocate(&v17);
      CreateThread(0, 0, lambda_35d4fc73e1a8a511f03c88debc717f0c_::_lambda_invoker_stdcall_, 0, 0, 0);
      return 1;
    }
    _InterlockedExchange((volatile __int32 *)&queue_death, 1);
    return 1;
  }
  if ( game_type != GAME_FFX2 )
    return 1;
  ffx2.party->vitals.current.HP = 0;
  ffx2.party[1].vitals.current.HP = 0;
  ffx2.party[2].vitals.current.HP = 0;
  ffx2.party[3].vitals.current.HP = 0;
  ffx2.party[4].vitals.current.HP = 0;
  ffx2.party[5].vitals.current.HP = 0;
  ffx2.party[6].vitals.current.HP = 0;
  ffx2.party[7].vitals.current.HP = 0;
  v0 = SK_GetCommandProcessor();
  v0->ProcessCommandLine(v0, (SK_ICommandResult *)v16, "mem b 9F7880 1");
  if ( block._Mypair._Myval2._Myres >= 0x10 )
  {
    Ptr = block._Mypair._Myval2._Bx._Ptr;
    if ( block._Mypair._Myval2._Myres + 1 >= 0x1000 )
    {
      if ( (block._Mypair._Myval2._Bx._Buf[0] & 0x1F) != 0 )
        __invalid_parameter_noinfo_noreturn();
      _Ptr = (char *)*((_DWORD *)block._Mypair._Myval2._Bx._Ptr - 1);
      if ( _Ptr >= block._Mypair._Myval2._Bx._Ptr )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)(block._Mypair._Myval2._Bx._Ptr - _Ptr) < 4 )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)(block._Mypair._Myval2._Bx._Ptr - _Ptr) > 0x23 )
        __invalid_parameter_noinfo_noreturn();
      Ptr = (char *)*((_DWORD *)block._Mypair._Myval2._Bx._Ptr - 1);
    }
    operator delete(Ptr);
  }
  block._Mypair._Myval2._Mysize = 0;
  block._Mypair._Myval2._Myres = 15;
  block._Mypair._Myval2._Bx._Buf[0] = 0;
  if ( v18._Mypair._Myval2._Myres >= 0x10 )
  {
    _Ptr_1 = v18._Mypair._Myval2._Bx._Ptr;
    if ( v18._Mypair._Myval2._Myres + 1 >= 0x1000 )
    {
      if ( (v18._Mypair._Myval2._Bx._Buf[0] & 0x1F) != 0 )
        __invalid_parameter_noinfo_noreturn();
      _Ptr_2 = (char *)*((_DWORD *)v18._Mypair._Myval2._Bx._Ptr - 1);
      if ( _Ptr_2 >= v18._Mypair._Myval2._Bx._Ptr )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)(v18._Mypair._Myval2._Bx._Ptr - _Ptr_2) < 4 )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)(v18._Mypair._Myval2._Bx._Ptr - _Ptr_2) > 0x23 )
        __invalid_parameter_noinfo_noreturn();
      _Ptr_1 = (char *)*((_DWORD *)v18._Mypair._Myval2._Bx._Ptr - 1);
    }
    operator delete(_Ptr_1);
  }
  v18._Mypair._Myval2._Mysize = 0;
  v18._Mypair._Myval2._Myres = 15;
  v18._Mypair._Myval2._Bx._Buf[0] = 0;
  if ( v17._Mypair._Myval2._Myres >= 0x10 )
  {
    _Ptr_3 = v17._Mypair._Myval2._Bx._Ptr;
    if ( v17._Mypair._Myval2._Myres + 1 >= 0x1000 )
    {
      if ( (v17._Mypair._Myval2._Bx._Buf[0] & 0x1F) != 0 )
        __invalid_parameter_noinfo_noreturn();
      _Ptr_4 = (char *)*((_DWORD *)v17._Mypair._Myval2._Bx._Ptr - 1);
      if ( _Ptr_4 >= v17._Mypair._Myval2._Bx._Ptr )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)(v17._Mypair._Myval2._Bx._Ptr - _Ptr_4) < 4 )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)(v17._Mypair._Myval2._Bx._Ptr - _Ptr_4) > 0x23 )
        __invalid_parameter_noinfo_noreturn();
      _Ptr_3 = (char *)*((_DWORD *)v17._Mypair._Myval2._Bx._Ptr - 1);
    }
    operator delete(_Ptr_3);
  }
  Sleep(0x21u);
  v7 = SK_GetCommandProcessor();
  v7->ProcessCommandLine(v7, (SK_ICommandResult *)v16, "mem b 9F7880 0");
  if ( block._Mypair._Myval2._Myres >= 0x10 )
  {
    _Ptr_5 = block._Mypair._Myval2._Bx._Ptr;
    if ( block._Mypair._Myval2._Myres + 1 >= 0x1000 )
    {
      if ( (block._Mypair._Myval2._Bx._Buf[0] & 0x1F) != 0 )
        __invalid_parameter_noinfo_noreturn();
      _Ptr_6 = (char *)*((_DWORD *)block._Mypair._Myval2._Bx._Ptr - 1);
      if ( _Ptr_6 >= block._Mypair._Myval2._Bx._Ptr )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)(block._Mypair._Myval2._Bx._Ptr - _Ptr_6) < 4 )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)(block._Mypair._Myval2._Bx._Ptr - _Ptr_6) > 0x23 )
        __invalid_parameter_noinfo_noreturn();
      _Ptr_5 = (char *)*((_DWORD *)block._Mypair._Myval2._Bx._Ptr - 1);
    }
    operator delete(_Ptr_5);
  }
  block._Mypair._Myval2._Mysize = 0;
  block._Mypair._Myval2._Myres = 15;
  block._Mypair._Myval2._Bx._Buf[0] = 0;
  if ( v18._Mypair._Myval2._Myres >= 0x10 )
  {
    _Ptr_7 = v18._Mypair._Myval2._Bx._Ptr;
    if ( v18._Mypair._Myval2._Myres + 1 >= 0x1000 )
    {
      if ( (v18._Mypair._Myval2._Bx._Buf[0] & 0x1F) != 0 )
        __invalid_parameter_noinfo_noreturn();
      _Ptr_8 = (char *)*((_DWORD *)v18._Mypair._Myval2._Bx._Ptr - 1);
      if ( _Ptr_8 >= v18._Mypair._Myval2._Bx._Ptr )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)(v18._Mypair._Myval2._Bx._Ptr - _Ptr_8) < 4 )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)(v18._Mypair._Myval2._Bx._Ptr - _Ptr_8) > 0x23 )
        __invalid_parameter_noinfo_noreturn();
      _Ptr_7 = (char *)*((_DWORD *)v18._Mypair._Myval2._Bx._Ptr - 1);
    }
    operator delete(_Ptr_7);
  }
  v18._Mypair._Myval2._Mysize = 0;
  v18._Mypair._Myval2._Myres = 15;
  v18._Mypair._Myval2._Bx._Buf[0] = 0;
  if ( v17._Mypair._Myval2._Myres >= 0x10 )
  {
    _Ptr_9 = v17._Mypair._Myval2._Bx._Ptr;
    if ( v17._Mypair._Myval2._Myres + 1 >= 0x1000 )
    {
      if ( (v17._Mypair._Myval2._Bx._Buf[0] & 0x1F) != 0 )
        __invalid_parameter_noinfo_noreturn();
      _Ptr_10 = (char *)*((_DWORD *)v17._Mypair._Myval2._Bx._Ptr - 1);
      if ( _Ptr_10 >= v17._Mypair._Myval2._Bx._Ptr )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)(v17._Mypair._Myval2._Bx._Ptr - _Ptr_10) < 4 )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)(v17._Mypair._Myval2._Bx._Ptr - _Ptr_10) > 0x23 )
        __invalid_parameter_noinfo_noreturn();
      _Ptr_9 = (char *)*((_DWORD *)v17._Mypair._Myval2._Bx._Ptr - 1);
    }
    operator delete(_Ptr_9);
  }
  Sleep(0);
  return 1;
}


// ===== xref:Full_Party_AP :: ?UNX_SummarizeCheats@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@K@Z @ 0x1001dcb0 (ref 0x1001dd39) =====
// positive sp value has been detected, the output may be wrong!
std::string *__fastcall UNX_SummarizeCheats(std::string *a1, unsigned int dwTime)
{
  unsigned int party_ap; // edi
  const char *ON_n; // ebx
  const char *ON_n_1; // edx
  _BYTE *?__UNX_base_img_addr@@3PAXA; // edi
  char _Buffer[128]; // [esp+14h] [ebp-9Ch] BYREF
  std::string *v10; // [esp+94h] [ebp-1Ch]
  unsigned int dwTime_1; // [esp+98h] [ebp-18h]
  const char *v12; // [esp+9Ch] [ebp-14h]
  int v13; // [esp+A0h] [ebp-10h]
  int v14; // [esp+ACh] [ebp-4h]

  v10 = a1;
  a1->_Mypair._Myval2._Mysize = 0;
  a1->_Mypair._Myval2._Myres = 15;
  dwTime_1 = dwTime;
  a1->_Mypair._Myval2._Bx._Buf[0] = 0;
  std::string::assign(a1, Ptr, 0);
  v14 = 0;
  v13 = 1;
  if ( game_type != GAME_FFX )
    return a1;
  party_ap = dwTime - 2500;
  ON_n = "ON\n";
  if ( last_changed.party_ap > party_ap )
  {
    std::string::append(a1, "Full Party AP:    ", 0x12u);
    ON_n_1 = "ON\n";
    if ( !config.cheat.ffx.entire_party_earns_ap )
      ON_n_1 = "OFF\n";
    v12 = ON_n_1 + 1;
    std::string::append(a1, ON_n_1, strlen(ON_n_1));
  }
  if ( last_changed.sensor > party_ap )
  {
    std::string::append(a1, "Permanent Sensor: ", 0x12u);
    if ( !config.cheat.ffx.permanent_sensor )
      ON_n = "OFF\n";
    std::string::append(a1, ON_n, strlen(ON_n));
  }
  if ( last_changed.speed > dwTime_1 - 5000 && !config.cheat.ffx.disable_timing_hacks )
  {
    memset(_Buffer, 0, sizeof(_Buffer));
    sprintf(_Buffer, "Game Speed:       %4.1fx\n", __UNX_speed_mod);
    std::string::append(a1, _Buffer, strlen(_Buffer));
  }
  ?__UNX_base_img_addr@@3PAXA = __UNX_base_img_addr;
  if ( ffx.debug_flags->control.camera || *((_BYTE *)__UNX_base_img_addr + 15711075) || __UNX_skip_cutscenes )
  {
    std::string::append(a1, "SPECIAL MODE:     ", 0x12u);
    if ( ffx.debug_flags->control.camera )
      std::string::append(a1, "(Free Look) ", 0xCu);
    if ( ?__UNX_base_img_addr@@3PAXA[15711075] )
      std::string::append(a1, "(Timestop) ", 0xBu);
    if ( __UNX_skip_cutscenes )
      std::string::append(a1, "(Cutscene Skip) ", 0x10u);
    std::string::append(a1, "\n", 1u);
  }
  return a1;
}


// ===== xref:Toggle_VSYNC :: ??0UNX_Keybindings@@QAE@XZ @ 0x10009690 (ref 0x100096c2) =====
UNX_Keybindings *__thiscall UNX_Keybindings::UNX_Keybindings(UNX_Keybindings *this)
{
  SK_Keybind *__Val_0_[4]; // [esp+4h] [ebp-10h] BYREF

  keybinds.VSYNC.bind_name = "Toggle VSYNC";
  keybinds.VSYNC.human_readable._Mypair._Myval2._Mysize = 0;
  keybinds.VSYNC.human_readable._Mypair._Myval2._Myres = 7;
  keybinds.VSYNC.human_readable._Mypair._Myval2._Bx._Buf[0] = 0;
  std::wstring::assign(&keybinds.VSYNC.human_readable, L"Ctrl+Shift+V", 0xCu);
  keybinds.VSYNC.modifiers.ctrl = 1;
  keybinds.VSYNC.modifiers.shift = 1;
  keybinds.VSYNC.modifiers.alt = 0;
  keybinds.VSYNC.vKey = 86;
  keybinds.VSYNC.masked_code = 0;
  __Val_0_[3] = (SK_Keybind *)9;
  keybinds.KickStart.bind_name = "Kickstart (fix stuck loading)";
  keybinds.KickStart.human_readable._Mypair._Myval2._Mysize = 0;
  keybinds.KickStart.human_readable._Mypair._Myval2._Myres = 7;
  keybinds.KickStart.human_readable._Mypair._Myval2._Bx._Buf[0] = 0;
  std::wstring::assign(&keybinds.KickStart.human_readable, L"Ctrl+Alt+Shift+K", 0x10u);
  keybinds.KickStart.modifiers.ctrl = 1;
  keybinds.KickStart.modifiers.shift = 1;
  keybinds.KickStart.modifiers.alt = 1;
  keybinds.KickStart.vKey = 75;
  keybinds.KickStart.masked_code = 0;
  keybinds.SpeedStep.bind_name = "Speed Boost";
  keybinds.SpeedStep.human_readable._Mypair._Myval2._Mysize = 0;
  keybinds.SpeedStep.human_readable._Mypair._Myval2._Myres = 7;
  keybinds.SpeedStep.human_readable._Mypair._Myval2._Bx._Buf[0] = 0;
  std::wstring::assign(&keybinds.SpeedStep.human_readable, L"Ctrl+Shift+H", 0xCu);
  keybinds.SpeedStep.modifiers.ctrl = 1;
  keybinds.SpeedStep.modifiers.shift = 1;
  keybinds.SpeedStep.modifiers.alt = 0;
  keybinds.SpeedStep.vKey = 72;
  keybinds.SpeedStep.masked_code = 0;
  keybinds.TimeStop.bind_name = "Toggle Time Stop";
  keybinds.TimeStop.human_readable._Mypair._Myval2._Mysize = 0;
  keybinds.TimeStop.human_readable._Mypair._Myval2._Myres = 7;
  keybinds.TimeStop.human_readable._Mypair._Myval2._Bx._Buf[0] = 0;
  std::wstring::assign(&keybinds.TimeStop.human_readable, L"Ctrl+Shift+P", 0xCu);
  keybinds.TimeStop.modifiers.ctrl = 1;
  keybinds.TimeStop.modifiers.shift = 1;
  keybinds.TimeStop.modifiers.alt = 0;
  keybinds.TimeStop.vKey = 80;
  keybinds.TimeStop.masked_code = 0;
  keybinds.FreeLook.bind_name = "Toggle Freelook";
  keybinds.FreeLook.human_readable._Mypair._Myval2._Mysize = 0;
  keybinds.FreeLook.human_readable._Mypair._Myval2._Myres = 7;
  keybinds.FreeLook.human_readable._Mypair._Myval2._Bx._Buf[0] = 0;
  std::wstring::assign(&keybinds.FreeLook.human_readable, L"Ctrl+Shift+F", 0xCu);
  keybinds.FreeLook.modifiers.ctrl = 1;
  keybinds.FreeLook.modifiers.shift = 1;
  keybinds.FreeLook.modifiers.alt = 0;
  keybinds.FreeLook.masked_code = 0;
  keybinds.FreeLook.vKey = 70;
  keybinds.Sensor.bind_name = "Toggle Permanent Sensor";
  keybinds.Sensor.human_readable._Mypair._Myval2._Mysize = 0;
  keybinds.Sensor.human_readable._Mypair._Myval2._Myres = 7;
  keybinds.Sensor.human_readable._Mypair._Myval2._Bx._Buf[0] = 0;
  std::wstring::assign(&keybinds.Sensor.human_readable, L"Ctrl+Shift+S", 0xCu);
  keybinds.Sensor.modifiers.ctrl = 1;
  keybinds.Sensor.modifiers.shift = 1;
  keybinds.Sensor.modifiers.alt = 0;
  keybinds.Sensor.vKey = 83;
  keybinds.Sensor.masked_code = 0;
  keybinds.FullAP.bind_name = "Toggle Full Party AP";
  keybinds.FullAP.human_readable._Mypair._Myval2._Mysize = 0;
  keybinds.FullAP.human_readable._Mypair._Myval2._Myres = 7;
  keybinds.FullAP.human_readable._Mypair._Myval2._Bx._Buf[0] = 0;
  std::wstring::assign(&keybinds.FullAP.human_readable, L"Ctrl+Shift+A", 0xCu);
  keybinds.FullAP.modifiers.ctrl = 1;
  keybinds.FullAP.modifiers.shift = 1;
  keybinds.FullAP.modifiers.alt = 0;
  keybinds.FullAP.vKey = 65;
  keybinds.FullAP.masked_code = 0;
  keybinds.SoftReset.bind_name = "Soft Reset (FFX)";
  keybinds.SoftReset.human_readable._Mypair._Myval2._Mysize = 0;
  keybinds.SoftReset.human_readable._Mypair._Myval2._Myres = 7;
  keybinds.SoftReset.human_readable._Mypair._Myval2._Bx._Buf[0] = 0;
  std::wstring::assign(&keybinds.SoftReset.human_readable, L"Ctrl+Shift+Delete", 0x11u);
  keybinds.SoftReset.modifiers.ctrl = 1;
  keybinds.SoftReset.modifiers.shift = 1;
  keybinds.SoftReset.modifiers.alt = 0;
  keybinds.SoftReset.vKey = 46;
  keybinds.SoftReset.masked_code = 0;
  keybinds.vec._Mypair._Myval2._Myfirst = 0;
  keybinds.vec._Mypair._Myval2._Mylast = 0;
  keybinds.vec._Mypair._Myval2._Myend = 0;
  keybinds.ffx_vec._Mypair._Myval2._Myfirst = 0;
  keybinds.ffx_vec._Mypair._Myval2._Mylast = 0;
  keybinds.ffx_vec._Mypair._Myval2._Myend = 0;
  __Val_0_[0] = (SK_Keybind *)&keybinds;
  std::vector<SK_Keybind *>::emplace_back<SK_Keybind *>(&keybinds.vec, __Val_0_);
  __Val_0_[0] = &keybinds.KickStart;
  std::vector<SK_Keybind *>::emplace_back<SK_Keybind *>(&keybinds.vec, __Val_0_);
  __Val_0_[0] = (SK_Keybind *)&keybinds;
  std::vector<SK_Keybind *>::emplace_back<SK_Keybind *>(&keybinds.ffx_vec, __Val_0_);
  __Val_0_[0] = &keybinds.KickStart;
  std::vector<SK_Keybind *>::emplace_back<SK_Keybind *>(&keybinds.ffx_vec, __Val_0_);
  __Val_0_[0] = &keybinds.SpeedStep;
  std::vector<SK_Keybind *>::emplace_back<SK_Keybind *>(&keybinds.ffx_vec, __Val_0_);
  __Val_0_[0] = &keybinds.TimeStop;
  std::vector<SK_Keybind *>::emplace_back<SK_Keybind *>(&keybinds.ffx_vec, __Val_0_);
  __Val_0_[0] = &keybinds.FreeLook;
  std::vector<SK_Keybind *>::emplace_back<SK_Keybind *>(&keybinds.ffx_vec, __Val_0_);
  __Val_0_[0] = &keybinds.Sensor;
  std::vector<SK_Keybind *>::emplace_back<SK_Keybind *>(&keybinds.ffx_vec, __Val_0_);
  __Val_0_[0] = &keybinds.FullAP;
  std::vector<SK_Keybind *>::emplace_back<SK_Keybind *>(&keybinds.ffx_vec, __Val_0_);
  __Val_0_[0] = &keybinds.SoftReset;
  std::vector<SK_Keybind *>::emplace_back<SK_Keybind *>(&keybinds.ffx_vec, __Val_0_);
  return &keybinds;
}


// ===== xref:Toggle_VSYNC :: ?UNX_ControlPanelWidget@@YGXXZ @ 0x1001ee70 (ref 0x1001f26d) =====
// positive sp value has been detected, the output may be wrong!
void UNX_ControlPanelWidget()
{
  const char *Final_Fantasy_X_HD_Remaster; // eax
  bool (__cdecl *__imp_?CollapsingHeader@ImGui@@YA_NPBDH@Z)(ImGui *__hidden, const char *, _DWORD); // esi
  int v2; // esi
  int v3; // edi
  int pTex_1; // eax
  bool v5; // al
  void (*__imp_?Text@ImGui@@YAXPBDZZ)(ImGui *__hidden, const char *, ...); // esi
  UNX_ControlPanelWidget::__l56::<lambda_1aa19b9566548e7b598ab4fba2209336> *v7; // ecx
  UNX_ControlPanelWidget::__l56::<lambda_1aa19b9566548e7b598ab4fba2209336> *v8; // ecx
  UNX_ControlPanelWidget::__l56::<lambda_1aa19b9566548e7b598ab4fba2209336> *v9; // ecx
  UNX_ControlPanelWidget::__l56::<lambda_1aa19b9566548e7b598ab4fba2209336> *v10; // ecx
  UNX_ControlPanelWidget::__l56::<lambda_1aa19b9566548e7b598ab4fba2209336> *v11; // ecx
  UNX_ControlPanelWidget::__l56::<lambda_1aa19b9566548e7b598ab4fba2209336> *v12; // ecx
  UNX_ControlPanelWidget::__l56::<lambda_1aa19b9566548e7b598ab4fba2209336> *v13; // ecx
  UNX_ControlPanelWidget::__l56::<lambda_1aa19b9566548e7b598ab4fba2209336> *v14; // ecx
  unx_gamepad_s *Ptr; // eax
  unx_gamepad_s *p_?gamepad@@3Uunx_gamepad_s@@A; // eax
  PWSTR v17; // eax
  void (__cdecl *__imp_?TreePop@ImGui@@YAXXZ)(ImGui *__hidden); // edi
  std::wstring *_Ptr; // eax
  HMODULE ModuleHandleW; // eax
  HMODULE hModule; // eax
  HANDLE hFindFile_1; // edi
  unx_config_s::textures_s *p_textures; // eax
  ID3D11Device *Device; // eax
  std::string *_Ptr_1; // eax
  int max_width_1; // edi
  void *block_1; // ecx
  void *v28; // eax
  int max_width; // eax
  std::vector<ButtonRef_s> *v30; // ecx
  ButtonRef_s *Myfirst; // esi
  ButtonRef_s *i; // edi
  std::wstring *value; // eax
  bool close_config_1; // al
  float y; // eax
  unsigned int *p_CpuAccessFlags; // eax
  int v37; // eax
  bool IsItemHovered; // al
  float y_1; // ecx
  std::_Wrap_alloc<std::allocator<wchar_t> > *v40; // ecx
  int v41; // eax
  float y_2; // esi
  struct IUnknown *v43; // eax
  float *p_hFindFile; // eax
  float speed_step_1; // xmm2_4
  HANDLE *p_hFindFile_1; // ecx
  char v47; // cl
  bool v48; // al
  bool v49; // al
  bool v50; // al
  bool (__cdecl *__imp_?CollapsingHeader@ImGui@@YA_NPBDH@Z_1)(ImGui *__hidden, const char *, _DWORD); // esi
  std::string *v52; // [esp+38h] [ebp-7A0h] BYREF
  _BYTE v53[36]; // [esp+3Ch] [ebp-79Ch] BYREF
  wchar_t String1[520]; // [esp+64h] [ebp-774h] BYREF
  _WIN32_FIND_DATAW FindFileData; // [esp+474h] [ebp-364h] BYREF
  ButtonRef_s __Val_0__; // [esp+6C4h] [ebp-114h] BYREF
  _BYTE v57[44]; // [esp+6F8h] [ebp-E0h] BYREF
  void *block[4]; // [esp+724h] [ebp-B4h] BYREF
  __int64 v59; // [esp+734h] [ebp-A4h]
  D3DX11_IMAGE_LOAD_INFO v60; // [esp+73Ch] [ebp-9Ch] BYREF
  std::wstring v61; // [esp+770h] [ebp-68h] BYREF
  struct ImVec2 v62; // [esp+788h] [ebp-50h] BYREF
  std::wstring in; // [esp+790h] [ebp-48h] BYREF
  float v64; // [esp+7A8h] [ebp-30h] BYREF
  float speed_step; // [esp+7ACh] [ebp-2Ch] BYREF
  HANDLE hFindFile; // [esp+7B0h] [ebp-28h] BYREF
  unsigned int hFindFile_2; // [esp+7B4h] [ebp-24h] BYREF
  bool v68; // [esp+7BBh] [ebp-1Dh] BYREF
  ID3D11Resource *pTex; // [esp+7BCh] [ebp-1Ch] BYREF
  struct ImVec2 v70; // [esp+7C0h] [ebp-18h] BYREF
  char v71; // [esp+7CAh] [ebp-Eh]
  bool close_config; // [esp+7CBh] [ebp-Dh] BYREF
  int n4; // [esp+7D4h] [ebp-4h]

  if ( first )
  {
    SKX_ImGui_RegisterResetCallback(UNX_ImGui_ResetCallback);
    first = 0;
  }
  speed_step = *((float *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index);
  if ( pOnce > *(_DWORD *)(LODWORD(speed_step) + 4) )
  {
    _Init_thread_header(&pOnce);
    if ( pOnce == -1 )
    {
      Final_Fantasy_X_HD_Remaster = "Final Fantasy X HD Remaster";
      if ( (game_type & 1) == 0 )
        Final_Fantasy_X_HD_Remaster = "Final Fantasy X-2 HD Remaster";
      szLabel = Final_Fantasy_X_HD_Remaster;
      _Init_thread_footer(&pOnce);
    }
  }
  __imp_?CollapsingHeader@ImGui@@YA_NPBDH@Z = ImGui::CollapsingHeader;
  if ( ImGui::CollapsingHeader((ImGui *)szLabel, (const char *)0x20, *(_DWORD *)&v53[32]) )
  {
    *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&in._Mypair._Myval2._Bx + 8) = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
    ImGui::PushStyleColor((ImGui *)0x19, &in._Mypair._Myval2._Bx._Alias[8], *(const struct ImVec4 **)&v53[32]);
    *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&in._Mypair._Myval2._Bx + 8) = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
    ImGui::PushStyleColor((ImGui *)0x1A, &in._Mypair._Myval2._Bx._Alias[8], *(const struct ImVec4 **)&v53[24]);
    *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&in._Mypair._Myval2._Bx + 8) = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
    ImGui::PushStyleColor((ImGui *)0x1B, &in._Mypair._Myval2._Bx._Alias[8], *(const struct ImVec4 **)&v53[16]);
    ImGui::TreePush((ImGui *)::Ptr, *(const char **)&v53[8]);
    if ( !ImGui::CollapsingHeader((ImGui *)"Language", (const char *)0x20, *(_DWORD *)&v53[4]) )
    {
LABEL_51:
      v5 = __imp_?CollapsingHeader@ImGui@@YA_NPBDH@Z((ImGui *)"Key Bindings", 0, *(_DWORD *)&v53[32]);
      __imp_?Text@ImGui@@YAXPBDZZ = ImGui::Text;
      if ( v5 )
      {
        ImGui::TreePush((ImGui *)::Ptr, *(const char **)&v53[32]);
        ImGui::BeginGroup(*(ImGui **)&v53[28]);
        ImGui::Text((ImGui *)"Toggle VSYNC", *(const char **)&v53[28]);
        ImGui::Text((ImGui *)"Kickstart (Fix Stuck Loading)", *(const char **)&v53[24]);
        if ( (game_type & 1) != 0 )
        {
          ImGui::Text((ImGui *)"Speed Boost", *(const char **)&v53[32]);
          ImGui::Text((ImGui *)"Toggle Time Stop", *(const char **)&v53[28]);
          ImGui::Text((ImGui *)"Toggle Freelook", *(const char **)&v53[24]);
          ImGui::Text((ImGui *)"Toggle Permanent Sensor", *(const char **)&v53[20]);
          ImGui::Text((ImGui *)"Toggle Full Party AP", *(const char **)&v53[16]);
          ImGui::Text((ImGui *)"Soft Reset", *(const char **)&v53[12]);
        }
        ImGui::EndGroup(*(ImGui **)&v53[32]);
        ImGui::SameLine(0, -1.0, *(float *)&v53[32]);
        ImGui::BeginGroup(*(ImGui **)&v53[32]);
        lambda_1aa19b9566548e7b598ab4fba2209336_::operator()(v7, &keybinds.VSYNC, unx_VSYNC);
        lambda_1aa19b9566548e7b598ab4fba2209336_::operator()(v8, &keybinds.KickStart, unx_kickstart);
        if ( (game_type & 1) != 0 )
        {
          lambda_1aa19b9566548e7b598ab4fba2209336_::operator()(v9, &keybinds.SpeedStep, unx_speedstep);
          lambda_1aa19b9566548e7b598ab4fba2209336_::operator()(v10, &keybinds.TimeStop, unx_timestop);
          lambda_1aa19b9566548e7b598ab4fba2209336_::operator()(v11, &keybinds.FreeLook, unx_freelook);
          lambda_1aa19b9566548e7b598ab4fba2209336_::operator()(v12, &keybinds.Sensor, unx_sensor);
          lambda_1aa19b9566548e7b598ab4fba2209336_::operator()(v13, &keybinds.FullAP, unx_fullap);
          lambda_1aa19b9566548e7b598ab4fba2209336_::operator()(v14, &keybinds.SoftReset, unx_soft_reset);
        }
        ImGui::EndGroup(*(ImGui **)&v53[32]);
        ImGui::TreePop(*(ImGui **)&v53[32]);
      }
      if ( ImGui::CollapsingHeader((ImGui *)"Gamepad Config", 0, *(_DWORD *)&v53[32]) )
      {
        ImGui::TreePush((ImGui *)::Ptr, *(const char **)&v53[32]);
        *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&in._Mypair._Myval2._Bx + 8) = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
        ImGui::PushStyleColor((ImGui *)0x19, &in._Mypair._Myval2._Bx._Alias[8], *(const struct ImVec4 **)&v53[28]);
        *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&in._Mypair._Myval2._Bx + 8) = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
        ImGui::PushStyleColor((ImGui *)0x1A, &in._Mypair._Myval2._Bx._Alias[8], *(const struct ImVec4 **)&v53[20]);
        *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&in._Mypair._Myval2._Bx + 8) = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
        ImGui::PushStyleColor((ImGui *)0x1B, &in._Mypair._Myval2._Bx._Alias[8], *(const struct ImVec4 **)&v53[12]);
        close_config = ImGui::CollapsingHeader((ImGui *)&result, 0, *(_DWORD *)&v53[4]);
        if ( ImGui::IsItemHovered(*(ImGui **)&v53[32]) )
          ImGui::SetTooltip((ImGui *)&result._Mypair._Myval2._Myres, *(const char **)&v53[32]);
        if ( close_config )
        {
          Ptr = &gamepad;
          *(_DWORD *)&v53[28] = L"PlayStation";
          if ( gamepad.tex_set._Mypair._Myval2._Myres >= 8 )
            Ptr = (unx_gamepad_s *)gamepad.tex_set._Mypair._Myval2._Bx._Ptr;
          if ( StrStrIW(Ptr->tex_set._Mypair._Myval2._Bx._Buf, *(PCWSTR *)&v53[28]) )
            goto LABEL_67;
          p_?gamepad@@3Uunx_gamepad_s@@A = &gamepad;
          *(_DWORD *)&v53[28] = L"PS";
          if ( gamepad.tex_set._Mypair._Myval2._Myres >= 8 )
            p_?gamepad@@3Uunx_gamepad_s@@A = (unx_gamepad_s *)gamepad.tex_set._Mypair._Myval2._Bx._Ptr;
          v17 = StrStrIW(p_?gamepad@@3Uunx_gamepad_s@@A->tex_set._Mypair._Myval2._Bx._Buf, *(PCWSTR *)&v53[28]);
          close_config = 0;
          if ( v17 )
LABEL_67:
            close_config = 1;
          LODWORD(v70.y) = &close_config;
          ImGui::TreePush((ImGui *)::Ptr, *(const char **)&v53[32]);
          ImGui::BeginGroup(*(ImGui **)&v53[28]);
          ImGui::Text((ImGui *)"F1", *(const char **)&v53[28]);
          ImGui::Text((ImGui *)"F2", *(const char **)&v53[24]);
          ImGui::Text((ImGui *)"F3", *(const char **)&v53[20]);
          ImGui::Text((ImGui *)"F4", *(const char **)&v53[16]);
          ImGui::Text((ImGui *)"F5", *(const char **)&v53[12]);
          ImGui::Text((ImGui *)"Screenshot", *(const char **)&v53[8]);
          ImGui::Text((ImGui *)"Fullscreen", *(const char **)&v53[4]);
          ImGui::Text((ImGui *)"Escape", *(const char **)v53);
          ImGui::Text((ImGui *)"Kickstart", v52->_Mypair._Myval2._Bx._Buf);
          if ( (game_type & 1) != 0 )
          {
            ImGui::Text((ImGui *)"Speed Boost", *(const char **)&v53[32]);
            ImGui::Text((ImGui *)"Soft Reset", *(const char **)&v53[28]);
          }
          ImGui::EndGroup(*(ImGui **)&v53[32]);
          ImGui::SameLine(0, -1.0, *(float *)&v53[32]);
          ImGui::BeginGroup(*(ImGui **)&v53[32]);
          lambda_c7d689ac2cf5a62ffff009ee2b71b6ad_::operator()(
            (UNX_ControlPanelWidget::__l70::<lambda_c7d689ac2cf5a62ffff009ee2b71b6ad> *)&v70.y,
            &gamepad.f1);
          lambda_c7d689ac2cf5a62ffff009ee2b71b6ad_::operator()(
            (UNX_ControlPanelWidget::__l70::<lambda_c7d689ac2cf5a62ffff009ee2b71b6ad> *)&v70.y,
            &gamepad.f2);
          lambda_c7d689ac2cf5a62ffff009ee2b71b6ad_::operator()(
            (UNX_ControlPanelWidget::__l70::<lambda_c7d689ac2cf5a62ffff009ee2b71b6ad> *)&v70.y,
            &gamepad.f3);
          lambda_c7d689ac2cf5a62ffff009ee2b71b6ad_::operator()(
            (UNX_ControlPanelWidget::__l70::<lambda_c7d689ac2cf5a62ffff009ee2b71b6ad> *)&v70.y,
            &gamepad.f4);
          lambda_c7d689ac2cf5a62ffff009ee2b71b6ad_::operator()(
            (UNX_ControlPanelWidget::__l70::<lambda_c7d689ac2cf5a62ffff009ee2b71b6ad> *)&v70.y,
            &gamepad.f5);
          lambda_c7d689ac2cf5a62ffff009ee2b71b6ad_::operator()(
            (UNX_ControlPanelWidget::__l70::<lambda_c7d689ac2cf5a62ffff009ee2b71b6ad> *)&v70.y,
            &gamepad.screenshot);
          lambda_c7d689ac2cf5a62ffff009ee2b71b6ad_::operator()(
            (UNX_ControlPanelWidget::__l70::<lambda_c7d689ac2cf5a62ffff009ee2b71b6ad> *)&v70.y,
            &gamepad.fullscreen);
          lambda_c7d689ac2cf5a62ffff009ee2b71b6ad_::operator()(
            (UNX_ControlPanelWidget::__l70::<lambda_c7d689ac2cf5a62ffff009ee2b71b6ad> *)&v70.y,
            &gamepad.esc);
          lambda_c7d689ac2cf5a62ffff009ee2b71b6ad_::operator()(
            (UNX_ControlPanelWidget::__l70::<lambda_c7d689ac2cf5a62ffff009ee2b71b6ad> *)&v70.y,
            &gamepad.kickstart);
          if ( (game_type & 1) != 0 )
          {
            lambda_c7d689ac2cf5a62ffff009ee2b71b6ad_::operator()(
              (UNX_ControlPanelWidget::__l70::<lambda_c7d689ac2cf5a62ffff009ee2b71b6ad> *)&v70.y,
              &gamepad.speedboost);
            lambda_c7d689ac2cf5a62ffff009ee2b71b6ad_::operator()(
              (UNX_ControlPanelWidget::__l70::<lambda_c7d689ac2cf5a62ffff009ee2b71b6ad> *)&v70.y,
              &gamepad.softreset);
            if ( ImGui::IsItemHovered(*(ImGui **)&v53[32]) || ImGui::IsItemFocused(*(ImGui **)&v53[32]) )
              ImGui::SetTooltip(
                (ImGui *)"It is STRONGLY recommended that you do not change this gamepad combo!",
                *(const char **)&v53[32]);
          }
          ImGui::EndGroup(*(ImGui **)&v53[32]);
          __imp_?TreePop@ImGui@@YAXXZ = ImGui::TreePop;
          ImGui::TreePop(*(ImGui **)&v53[32]);
        }
        else
        {
          __imp_?TreePop@ImGui@@YAXXZ = ImGui::TreePop;
        }
        if ( ImGui::CollapsingHeader((ImGui *)"Gamepad Button Icons", 0, *(_DWORD *)&v53[32]) )
        {
          ImGui::TreePush((ImGui *)::Ptr, *(const char **)&v53[32]);
          if ( gamepads._Mypair._Myval2._Myfirst == gamepads._Mypair._Myval2._Mylast )
          {
            memset(&FindFileData, 0, sizeof(FindFileData));
            v61._Mypair._Myval2._Mysize = 0;
            v61._Mypair._Myval2._Myres = 7;
            v61._Mypair._Myval2._Bx._Buf[0] = 0;
            std::wstring::assign(&v61, &config.textures.resource_root, 0, 0xFFFFFFFF);
            n4 = 0;
            std::wstring::append(&v61, L"\\gamepads\\*", 0xBu);
            _Ptr = &v61;
            if ( v61._Mypair._Myval2._Myres >= 8 )
              _Ptr = (std::wstring *)v61._Mypair._Myval2._Bx._Ptr;
            hFindFile = FindFirstFileW(_Ptr->_Mypair._Myval2._Bx._Buf, &FindFileData);
            if ( !D3DX11CreateTextureFromFileW )
            {
              *(_DWORD *)&v53[28] = "D3DX11CreateTextureFromFileW";
              ModuleHandleW = GetModuleHandleW(L"d3dx11_43.dll");
              D3DX11CreateTextureFromFileW = (HRESULT (__stdcall *)(ID3D11Device *, const wchar_t *, D3DX11_IMAGE_LOAD_INFO *, IUnknown *, ID3D11Resource **, HRESULT *))GetProcAddress(ModuleHandleW, *(LPCSTR *)&v53[28]);
            }
            if ( !D3DX11GetImageInfoFromFileW )
            {
              *(_DWORD *)&v53[28] = "D3DX11GetImageInfoFromFileW";
              hModule = GetModuleHandleW(L"d3dx11_43.dll");
              D3DX11GetImageInfoFromFileW = (HRESULT (__stdcall *)(const wchar_t *, ID3DX11ThreadPump *, D3DX11_IMAGE_INFO *, HRESULT *))GetProcAddress(hModule, *(LPCSTR *)&v53[28]);
            }
            hFindFile_1 = hFindFile;
            if ( hFindFile != (HANDLE)-1 )
            {
              do
              {
                memset(String1, 0, sizeof(String1));
                p_textures = &config.textures;
                if ( config.textures.resource_root._Mypair._Myval2._Myres >= 8 )
                  p_textures = (unx_config_s::textures_s *)config.textures.resource_root._Mypair._Myval2._Bx._Ptr;
                lstrcatW(String1, p_textures->resource_root._Mypair._Myval2._Bx._Buf);
                lstrcatW(String1, L"\\gamepads\\");
                lstrcatW(String1, FindFileData.cFileName);
                lstrcatW(String1, L"\\ButtonMap.dds");
                if ( GetFileAttributesW(String1) != -1 )
                {
                  pTex = 0;
                  memset(&v57[8], 0, 36);
                  memset(&v60, 0, sizeof(v60));
                  if ( D3DX11GetImageInfoFromFileW )
                  {
                    if ( D3DX11GetImageInfoFromFileW(String1, 0, (D3DX11_IMAGE_INFO *)&v57[8], 0) >= 0 )
                    {
                      v60.Depth = *(_DWORD *)&v57[16];
                      v60.Format = *(_DWORD *)&v57[32];
                      v60.Height = *(_DWORD *)&v57[12];
                      v60.MipLevels = *(_DWORD *)&v57[24];
                      v60.MiscFlags = *(_DWORD *)&v57[28];
                      v60.pSrcInfo = (D3DX11_IMAGE_INFO *)&v57[8];
                      v60.BindFlags = 8;
                      v60.CpuAccessFlags = 0;
                      v60.Filter = -1;
                      v60.FirstMipLevel = 0;
                      v60.MipFilter = -1;
                      v60.Usage = D3D11_USAGE_IMMUTABLE;
                      v60.Width = *(_DWORD *)&v57[8];
                      if ( D3DX11CreateTextureFromFileW )
                      {
                        *(_DWORD *)&v53[28] = 0;
                        *(_DWORD *)&v53[24] = &pTex;
                        *(_DWORD *)&v53[20] = 0;
                        *(_DWORD *)&v53[16] = &v60;
                        *(_DWORD *)&v53[12] = String1;
                        Device = (ID3D11Device *)SK_Render_GetDevice();
                        if ( D3DX11CreateTextureFromFileW(
                               Device,
                               *(const wchar_t **)&v53[12],
                               *(D3DX11_IMAGE_LOAD_INFO **)&v53[16],
                               *(IUnknown **)&v53[20],
                               *(ID3D11Resource ***)&v53[24],
                               *(HRESULT **)&v53[28]) >= 0 )
                        {
                          *(_DWORD *)&v53[28] = -1082130432;
                          *(_DWORD *)&v53[24] = 0;
                          *(_DWORD *)&v53[20] = 0;
                          std::wstring::wstring((std::wstring *)&v52, FindFileData.cFileName);
                          _Ptr_1 = UNX_WideCharToUTF8(v52, *(std::wstring *)v53);
                          LOBYTE(n4) = 1;
                          if ( _Ptr_1->_Mypair._Myval2._Myres >= 0x10 )
                            _Ptr_1 = (std::string *)_Ptr_1->_Mypair._Myval2._Bx._Ptr;
                          max_width_1 = (int)*(float *)*(_QWORD *)&ImGui::CalcTextSize(
                                                                     (ImGui *)&in,
                                                                     _Ptr_1->_Mypair._Myval2._Bx._Buf,
                                                                     *(const char **)&v53[20],
                                                                     v53[24],
                                                                     *(float *)&v53[28]);
                          LOBYTE(n4) = 0;
                          if ( HIDWORD(v59) >= 0x10 )
                          {
                            block_1 = block[0];
                            if ( (unsigned int)(HIDWORD(v59) + 1) >= 0x1000 )
                            {
                              if ( ((int)block[0] & 0x1F) != 0
                                || (v28 = (void *)*((_DWORD *)block[0] - 1), v28 >= block[0])
                                || (unsigned int)((char *)block[0] - (char *)v28) < 4
                                || (unsigned int)((char *)block[0] - (char *)v28) > 0x23 )
                              {
                                __invalid_parameter_noinfo_noreturn();
                              }
                              block_1 = (void *)*((_DWORD *)block[0] - 1);
                            }
                            operator delete(block_1);
                          }
                          max_width = max_width;
                          if ( max_width_1 > max_width )
                            max_width = max_width_1;
                          max_width = max_width;
                          __Val_0__.pTex = (ID3D11Texture2D *)pTex;
                          std::wstring::wstring(&__Val_0__.name, FindFileData.cFileName);
                          LOBYTE(n4) = 2;
                          std::wstring::wstring((std::wstring *)&v53[8], FindFileData.cFileName);
                          UNX_WideCharToUTF8(*(std::string **)&v53[8], *(std::wstring *)&v53[12]);
                          LOBYTE(n4) = 3;
                          std::vector<ButtonRef_s>::emplace_back<ButtonRef_s>(v30, &__Val_0__);
                          LOBYTE(n4) = 0;
                          ButtonRef_s::~ButtonRef_s(&__Val_0__);
                          SKX_ImGui_RegisterResource(pTex);
                          hFindFile_1 = hFindFile;
                        }
                      }
                    }
                  }
                }
              }
              while ( FindNextFileW(hFindFile_1, &FindFileData) );
              FindClose(hFindFile_1);
            }
            n4 = -1;
            std::wstring::~wstring(&v61);
          }
          v70.y = 0.0;
          ImGui::Columns((ImGui *)2, 0, (const char *)1, v53[32]);
          Myfirst = gamepads._Mypair._Myval2._Myfirst;
          for ( i = gamepads._Mypair._Myval2._Mylast; Myfirst != i; ++Myfirst )
          {
            v60.Width = (unsigned int)Myfirst->pTex;
            LOWORD(v60.Height) = 0;
            v60.Usage = D3D11_USAGE_DEFAULT;
            v60.BindFlags = 7;
            std::wstring::assign((std::wstring *)&v60.Height, &Myfirst->name, 0, 0xFFFFFFFF);
            n4 = 4;
            v60.MipFilter = 0;
            v60.pSrcInfo = (D3DX11_IMAGE_INFO *)15;
            LOBYTE(v60.CpuAccessFlags) = 0;
            std::string::assign((std::string *)&v60.CpuAccessFlags, &Myfirst->name_utf8, 0, 0xFFFFFFFF);
            n4 = 5;
            if ( pOnce_ > *(_DWORD *)(LODWORD(speed_step) + 4) )
            {
              _Init_thread_header(&pOnce_);
              if ( pOnce_ == -1 )
              {
                LOBYTE(n4) = 6;
                texture_set->get_value(texture_set, &original);
                atexit(UNX_ControlPanelWidget_::_110_::_dynamic_atexit_destructor_for__original__);
                LOBYTE(n4) = 5;
                _Init_thread_footer(&pOnce_);
              }
            }
            value = texture_set->get_value(texture_set, block);
            close_config_1 = std::wstring::_Equal(value, (const std::wstring *)&v60.Height);
            close_config = close_config_1;
            if ( HIDWORD(v59) >= 8 )
            {
              std::_Wrap_alloc<std::allocator<wchar_t>>::deallocate(
                (std::_Wrap_alloc<std::allocator<wchar_t> > *)HIDWORD(v59),
                (wchar_t *)block[0],
                HIDWORD(v59) + 1);
              close_config_1 = close_config;
            }
            if ( close_config_1 )
            {
              y = v70.y;
              if ( !LODWORD(v70.y) )
                y = *(float *)&v60.Width;
              v70.y = y;
            }
            *(_DWORD *)&v53[28] = &in;
            *(_DWORD *)&v53[24] = 0;
            *(_QWORD *)in._Mypair._Myval2._Bx._Buf = 0;
            p_CpuAccessFlags = &v60.CpuAccessFlags;
            if ( v60.pSrcInfo >= (D3DX11_IMAGE_INFO *)0x10 )
              p_CpuAccessFlags = (unsigned int *)v60.CpuAccessFlags;
            if ( ImGui::Selectable(
                   (ImGui *)p_CpuAccessFlags,
                   (const char *)&close_config,
                   *(bool **)&v53[24],
                   *(_DWORD *)&v53[28],
                   *(const struct ImVec2 **)&v53[32])
              && close_config )
            {
              std::wstring::assign(&gamepad.tex_set, (const std::wstring *)&v60.Height, 0, 0xFFFFFFFF);
              *(_DWORD *)&v53[24] = 0;
              *(_DWORD *)&v53[28] = 7;
              *(_WORD *)&v53[8] = 0;
              std::wstring::assign((std::wstring *)&v53[8], (const std::wstring *)&v60.Height, 0, 0xFFFFFFFF);
              ((void (__thiscall *)(unx::ParameterStringW *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))texture_set->store)(
                texture_set,
                *(_DWORD *)&v53[8],
                *(_DWORD *)&v53[12],
                *(_DWORD *)&v53[16],
                *(_DWORD *)&v53[20],
                *(_DWORD *)&v53[24],
                *(_DWORD *)&v53[28]);
              *(_DWORD *)&v53[28] = pad_cfg;
              hFindFile_2 = (unsigned int)pad_cfg->__vftable;
              v37 = (*(int (__thiscall **)(iSK_INI *, iSK_INI *))(hFindFile_2 + 44))(pad_cfg, pad_cfg);
              (*(void (__stdcall **)(iSK_INI *, int))(hFindFile_2 + 20))(pad_cfg, v37);
              changed = !std::wstring::_Equal(&original, (const std::wstring *)&v60.Height);
              UNX_SetupSpecialButtons();
            }
            IsItemHovered = ImGui::IsItemHovered(*(ImGui **)&v53[32]);
            y_1 = v70.y;
            if ( IsItemHovered )
              y_1 = *(float *)&v60.Width;
            v70.y = y_1;
            n4 = -1;
            std::string::_Tidy_deallocate((std::string *)&v60.CpuAccessFlags);
            if ( v60.BindFlags >= 8 )
              std::_Wrap_alloc<std::allocator<wchar_t>>::deallocate(v40, (wchar_t *)v60.Height, v60.BindFlags + 1);
          }
          if ( changed )
          {
            ImGui::ColorConvertHSVtoRGB(
              (ImGui *)0x3E000000,
              1.0,
              1.0,
              COERCE_FLOAT(&speed_step),
              (float *)&hFindFile_2,
              (float *)&in._Mypair._Myval2._Bx._Alias[4],
              *(float **)&v53[32]);
            *(_QWORD *)&in._Mypair._Myval2._Bx._Alias[8] = __PAIR64__(hFindFile_2, LODWORD(speed_step));
            in._Mypair._Myval2._Mysize = *(_DWORD *)&in._Mypair._Myval2._Bx._Alias[4];
            in._Mypair._Myval2._Myres = 1065353216;
            ImGui::PushStyleColor(0, &in._Mypair._Myval2._Bx._Alias[8], *(const struct ImVec4 **)&v53[8]);
            ImGui::BulletText((ImGui *)"Game Restart Required", *(const char **)v53);
            ImGui::PopStyleColor((ImGui *)1, v52);
          }
          ImGui::NextColumn(*(ImGui **)&v53[32]);
          v41 = *(_QWORD *)&ImGui::GetItemRectSize((ImGui *)&v64);
          y_2 = v70.y;
          hFindFile_2 = *(_DWORD *)(v41 + 4);
          hFindFile = (HANDLE)hFindFile_2;
          if ( LODWORD(v70.y) )
          {
            memset(v57, 0, sizeof(v57));
            (*(void (__stdcall **)(_DWORD, _BYTE *))(*(_DWORD *)LODWORD(v70.y) + 40))(LODWORD(v70.y), v57);
            pTex = 0;
            v59 = 0;
            block[1] = (void *)4;
            block[0] = *(void **)&v57[16];
            block[3] = (void *)1;
            block[2] = 0;
            v43 = SK_Render_GetDevice();
            if ( v43 )
            {
              if ( ((int (__stdcall *)(struct IUnknown *, float, void **, ID3D11Resource **))v43->__vftable[2].AddRef)(
                     v43,
                     COERCE_FLOAT(LODWORD(y_2)),
                     block,
                     &pTex) >= 0 )
              {
                if ( pTex )
                {
                  *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&in._Mypair._Myval2._Bx + 8) = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
                  v62.x = 1.0;
                  *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&v61._Mypair._Myval2._Bx + 8) = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
                  v62.y = 0.0;
                  v70.x = 0.0;
                  v70.y = 1.0;
                  p_hFindFile = &speed_step;
                  speed_step_1 = (float)*(unsigned int *)&v57[4];
                  speed_step = speed_step_1;
                  *(float *)&in._Mypair._Myval2._Bx._Alias[4] = speed_step_1;
                  if ( speed_step_1 <= *(float *)&hFindFile_2 )
                    p_hFindFile = (float *)&hFindFile;
                  p_hFindFile_1 = (HANDLE *)&in._Mypair._Myval2._Bx._Alias[4];
                  if ( speed_step_1 <= *(float *)&hFindFile_2 )
                    p_hFindFile_1 = &hFindFile;
                  speed_step = *p_hFindFile;
                  *(_DWORD *)&v53[28] = &in._Mypair._Myval2._Bx._Alias[8];
                  *(_DWORD *)&v53[24] = &v61._Mypair._Myval2._Bx._Alias[8];
                  *(_DWORD *)&v53[20] = &v62;
                  *(_DWORD *)&v53[16] = &v70;
                  *(_DWORD *)&v53[12] = &v64;
                  *(_DWORD *)&v53[8] = pTex;
                  v64 = (float)((float)*(unsigned int *)v57 / speed_step_1) * *(float *)p_hFindFile_1;
                  ImGui::Image(
                    (ImGui *)pTex,
                    &v64,
                    &v70,
                    &v62,
                    (const struct ImVec2 *)&v61._Mypair._Myval2._Bx._Alias[8],
                    (const struct ImVec4 *)&in._Mypair._Myval2._Bx._Alias[8],
                    *(const struct ImVec4 **)&v53[32]);
                  SKX_ImGui_RegisterDiscardableResource(pTex);
                }
              }
            }
          }
          ImGui::NextColumn(*(ImGui **)&v53[32]);
          ImGui::Columns((ImGui *)1, 0, (const char *)1, v53[32]);
          __imp_?TreePop@ImGui@@YAXXZ = ImGui::TreePop;
          ImGui::TreePop(*(ImGui **)&v53[32]);
          __imp_?Text@ImGui@@YAXPBDZZ = ImGui::Text;
        }
        ImGui::PopStyleColor((ImGui *)3, *(_DWORD *)&v53[32]);
        __imp_?TreePop@ImGui@@YAXXZ(*(ImGui **)&v53[32]);
      }
      else
      {
        __imp_?TreePop@ImGui@@YAXXZ = ImGui::TreePop;
      }
      if ( (game_type & 1) != 0
        && ImGui::CollapsingHeader((ImGui *)"Game Boosters", (const char *)0x20, *(_DWORD *)&v53[32]) )
      {
        close_config = 0;
        ImGui::TreePush((ImGui *)::Ptr, *(const char **)&v53[32]);
        *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&v61._Mypair._Myval2._Bx + 8) = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
        ImGui::PushStyleColor((ImGui *)0x19, &v61._Mypair._Myval2._Bx._Alias[8], *(const struct ImVec4 **)&v53[28]);
        *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&v61._Mypair._Myval2._Bx + 8) = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
        ImGui::PushStyleColor((ImGui *)0x1A, &v61._Mypair._Myval2._Bx._Alias[8], *(const struct ImVec4 **)&v53[20]);
        *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&v61._Mypair._Myval2._Bx + 8) = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
        ImGui::PushStyleColor((ImGui *)0x1B, &v61._Mypair._Myval2._Bx._Alias[8], *(const struct ImVec4 **)&v53[12]);
        if ( ImGui::CollapsingHeader((ImGui *)"Speed Boost", 0, *(_DWORD *)&v53[4]) )
        {
          ImGui::TreePush((ImGui *)::Ptr, *(const char **)&v53[32]);
          v68 = !config.cheat.ffx.disable_timing_hacks;
          v71 = ImGui::Checkbox((ImGui *)"Enable", (const char *)&v68, *(bool **)&v53[28]);
          if ( ImGui::IsItemHovered(*(ImGui **)&v53[32]) )
          {
            ImGui::BeginTooltip(*(ImGui **)&v53[32]);
            __imp_?Text@ImGui@@YAXPBDZZ(
              (ImGui *)"May cause compatibility issues with third-party software",
              *(const char **)&v53[32]);
            ImGui::Separator(*(ImGui **)&v53[28]);
            ImGui::BulletText(
              (ImGui *)"Disable if logs\\crash\\*\\crash.log contains a line about UNX_FFX_GameTick",
              *(const char **)&v53[28]);
            ImGui::EndTooltip(*(ImGui **)&v53[32]);
          }
          v47 = v71;
          if ( v71 )
            config.cheat.ffx.disable_timing_hacks = !v68;
          if ( v68 )
          {
            v48 = ImGui::InputFloat(
                    (ImGui *)"Step Multiplier",
                    (const char *)&config.cheat.ffx.speed_step,
                    0,
                    0.0,
                    COERCE_FLOAT(1),
                    0,
                    *(_DWORD *)&v53[32]);
            v71 |= v48;
            v49 = ImGui::InputFloat(
                    (ImGui *)"Speed Limit",
                    (const char *)&config.cheat.ffx.max_speed,
                    0,
                    0.0,
                    COERCE_FLOAT(1),
                    0,
                    *(_DWORD *)&v53[32]);
            v71 |= v49;
            v50 = ImGui::InputFloat(
                    (ImGui *)"Dialog Skip At",
                    (const char *)&config.cheat.ffx.skip_dialog,
                    0,
                    0.0,
                    COERCE_FLOAT(1),
                    0,
                    *(_DWORD *)&v53[32]);
            v47 = v50 | v71;
          }
          if ( v47 )
          {
            close_config = 1;
            speed_step = config.cheat.ffx.speed_step;
            config.cheat.ffx.speed_step = 1.0;
            UNX_SpeedStep();
            config.cheat.ffx.speed_step = speed_step;
          }
          ImGui::TreePop(*(ImGui **)&v53[32]);
        }
        __imp_?CollapsingHeader@ImGui@@YA_NPBDH@Z_1 = ImGui::CollapsingHeader;
        if ( ImGui::CollapsingHeader((ImGui *)"Sensor / Party AP", 0, *(_DWORD *)&v53[32]) )
        {
          ImGui::TreePush((ImGui *)::Ptr, *(const char **)&v53[32]);
          if ( ImGui::Checkbox(
                 (ImGui *)"Entire Party Earns AP",
                 (const char *)&config.cheat.ffx.entire_party_earns_ap,
                 *(bool **)&v53[28]) )
          {
            close_config = 1;
            last_changed.party_ap = timeGetTime();
            config.cheat.ffx.entire_party_earns_ap = !config.cheat.ffx.entire_party_earns_ap;
            __imp_?CollapsingHeader@ImGui@@YA_NPBDH@Z_1 = ImGui::CollapsingHeader;
            last_changed.party_ap = timeGetTime();
            config.cheat.ffx.entire_party_earns_ap = !config.cheat.ffx.entire_party_earns_ap;
          }
          if ( ImGui::Checkbox(
                 (ImGui *)"Grant Permanent Sensor",
                 (const char *)&config.cheat.ffx.permanent_sensor,
                 *(bool **)&v53[32]) )
          {
            close_config = 1;
            UNX_ToggleSensor();
            UNX_ToggleSensor();
          }
          ImGui::TreePop(*(ImGui **)&v53[32]);
        }
        if ( __imp_?CollapsingHeader@ImGui@@YA_NPBDH@Z_1((ImGui *)"Misc.", 0, *(_DWORD *)&v53[32]) )
        {
          close_config = 1;
          ImGui::TreePush((ImGui *)::Ptr, *(const char **)&v53[32]);
          ImGui::Checkbox(
            (ImGui *)"Seymour As Playable Character",
            (const char *)&config.cheat.ffx.playable_seymour,
            *(bool **)&v53[28]);
          __imp_?TreePop@ImGui@@YAXXZ = ImGui::TreePop;
          ImGui::TreePop(*(ImGui **)&v53[32]);
        }
        else
        {
          __imp_?TreePop@ImGui@@YAXXZ = ImGui::TreePop;
        }
        ImGui::PopStyleColor((ImGui *)3, *(_DWORD *)&v53[32]);
        __imp_?TreePop@ImGui@@YAXXZ(*(ImGui **)&v53[32]);
        if ( close_config )
        {
          close_config = 0;
          *(_DWORD *)&v53[24] = 0;
          *(_DWORD *)&v53[28] = 7;
          *(_WORD *)&v53[8] = 0;
          std::wstring::assign((std::wstring *)&v53[8], L"UnX", 3u);
          UNX_SaveConfig(*(std::wstring *)&v53[8], close_config);
        }
      }
      ImGui::PopStyleColor((ImGui *)3, *(_DWORD *)&v53[32]);
      __imp_?TreePop@ImGui@@YAXXZ(*(ImGui **)&v53[32]);
      return;
    }
    ImGui::TreePush((ImGui *)::Ptr, *(const char **)&v53[32]);
    if ( std::wstring::_Equal(&config.language.voice, L"us") )
      v2 = 1;
    else
      v2 = std::wstring::_Equal(&config.language.voice, L"jp") ? 2 : 0;
    LODWORD(v70.y) = v2;
    if ( std::wstring::_Equal(&config.language.sfx, L"us") )
      v3 = 1;
    else
      v3 = std::wstring::_Equal(&config.language.sfx, L"jp") ? 2 : 0;
    LODWORD(v62.y) = v3;
    if ( std::wstring::_Equal(&config.language.video, L"us") )
      pTex_1 = 1;
    else
      pTex_1 = std::wstring::_Equal(&config.language.video, L"jp") ? 2 : 0;
    pTex = (ID3D11Resource *)pTex_1;
    hFindFile = (HANDLE)pTex_1;
    *(float *)&v53[28] = ImGui::GetWindowWidth(*(ImGui **)&v53[32]) * 0.69999999;
    ImGui::PushItemWidth(*(ImGui **)&v53[28], *(float *)&v53[32]);
    close_config = 0;
    if ( ImGui::Combo(
           (ImGui *)"Dialogue",
           (const char *)&v70.y,
           (int *)"Game Default",
           (const char *)0xFFFFFFFF,
           *(_DWORD *)&v53[28]) )
    {
      if ( LODWORD(v70.y) == 1 )
      {
        std::wstring::assign(&config.language.voice, L"us", 2u);
      }
      else
      {
        if ( LODWORD(v70.y) == 2 )
          *(_DWORD *)&v53[28] = L"jp";
        else
          *(_DWORD *)&v53[28] = L"default";
        std::wstring::operator=(&config.language.voice, *(const wchar_t *const *)&v53[28]);
      }
      if ( LODWORD(v70.y) != v2 )
      {
        close_config = 1;
        unx::LanguageManager::ApplyPatch(Voice);
      }
    }
    if ( ImGui::Combo(
           (ImGui *)"Sound Effects",
           (const char *)&v62.y,
           (int *)"Game Default",
           (const char *)0xFFFFFFFF,
           *(_DWORD *)&v53[32]) )
    {
      if ( LODWORD(v62.y) == 1 )
      {
        std::wstring::assign(&config.language.sfx, L"us", 2u);
      }
      else
      {
        if ( LODWORD(v62.y) == 2 )
          *(_DWORD *)&v53[28] = L"jp";
        else
          *(_DWORD *)&v53[28] = L"default";
        std::wstring::operator=(&config.language.sfx, *(const wchar_t *const *)&v53[28]);
      }
      if ( LODWORD(v62.y) != v3 )
      {
        close_config = 1;
        unx::LanguageManager::ApplyPatch(SoundEffect);
      }
    }
    if ( ImGui::Combo(
           (ImGui *)"Full Motion Video",
           (const char *)&pTex,
           (int *)"Game Default",
           (const char *)0xFFFFFFFF,
           *(_DWORD *)&v53[32]) )
    {
      if ( pTex == (ID3D11Resource *)1 )
      {
        std::wstring::assign(&config.language.video, L"us", 2u);
      }
      else
      {
        if ( pTex == (ID3D11Resource *)2 )
          *(_DWORD *)&v53[28] = L"jp";
        else
          *(_DWORD *)&v53[28] = L"default";
        std::wstring::operator=(&config.language.video, *(const wchar_t *const *)&v53[28]);
      }
      if ( pTex != hFindFile )
      {
        close_config = 1;
        unx::LanguageManager::ApplyPatch(Video);
      }
    }
    ImGui::PopItemWidth(*(ImGui **)&v53[32]);
    if ( close_config )
    {
      close_config = 0;
      *(_DWORD *)&v53[24] = 0;
      *(_DWORD *)&v53[28] = 7;
      *(_WORD *)&v53[8] = 0;
      std::wstring::assign((std::wstring *)&v53[8], L"UnX", 3u);
      UNX_SaveConfig(*(std::wstring *)&v53[8], close_config);
      changed_0 = 1;
    }
    else if ( !changed_0 )
    {
LABEL_50:
      ImGui::TreePop(*(ImGui **)&v53[32]);
      __imp_?CollapsingHeader@ImGui@@YA_NPBDH@Z = ImGui::CollapsingHeader;
      goto LABEL_51;
    }
    ImGui::ColorConvertHSVtoRGB(
      (ImGui *)0x3ECCCCCD,
      1.0,
      0.94,
      COERCE_FLOAT(&hFindFile),
      (float *)&in._Mypair._Myval2._Bx._Alias[4],
      (float *)&hFindFile_2,
      *(float **)&v53[32]);
    *(_QWORD *)&in._Mypair._Myval2._Bx._Alias[8] = __PAIR64__(
                                                     *(unsigned int *)&in._Mypair._Myval2._Bx._Alias[4],
                                                     (unsigned int)hFindFile);
    in._Mypair._Myval2._Mysize = hFindFile_2;
    in._Mypair._Myval2._Myres = 1065353216;
    ImGui::PushStyleColor(0, &in._Mypair._Myval2._Bx._Alias[8], *(const struct ImVec4 **)&v53[8]);
    ImGui::BulletText((ImGui *)"Game Restart Required", *(const char **)v53);
    ImGui::PopStyleColor((ImGui *)1, v52);
    goto LABEL_50;
  }
}


// ===== xref:Soft_Reset :: ??0unx_gamepad_s@@QAE@XZ @ 0x10009e10 (ref 0x10009ef4) =====
unx_gamepad_s *__thiscall unx_gamepad_s::unx_gamepad_s(unx_gamepad_s *this)
{
  unx_gamepad_s *p_?gamepad@@3Uunx_gamepad_s@@A; // eax

  gamepad.tex_set._Mypair._Myval2._Mysize = 0;
  gamepad.tex_set._Mypair._Myval2._Myres = 7;
  gamepad.tex_set._Mypair._Myval2._Bx._Buf[0] = 0;
  std::wstring::assign(&gamepad.tex_set, L"PlayStation_Glossy", 0x12u);
  gamepad.legacy = 0;
  UNX_GamepadCombo::UNX_GamepadCombo(&gamepad.f1, "F1");
  UNX_GamepadCombo::UNX_GamepadCombo(&gamepad.f2, "F2");
  UNX_GamepadCombo::UNX_GamepadCombo(&gamepad.f3, "F3");
  UNX_GamepadCombo::UNX_GamepadCombo(&gamepad.f4, "F4");
  UNX_GamepadCombo::UNX_GamepadCombo(&gamepad.f5, "F5");
  UNX_GamepadCombo::UNX_GamepadCombo(&gamepad.screenshot, "Steam Screenshot");
  UNX_GamepadCombo::UNX_GamepadCombo(&gamepad.fullscreen, "Fullscreen Toggle");
  UNX_GamepadCombo::UNX_GamepadCombo(&gamepad.esc, "Escape");
  UNX_GamepadCombo::UNX_GamepadCombo(&gamepad.speedboost, "Speedboost");
  UNX_GamepadCombo::UNX_GamepadCombo(&gamepad.kickstart, "Kickstart");
  UNX_GamepadCombo::UNX_GamepadCombo(&gamepad.softreset, "Soft Reset");
  unx_gamepad_s::names_s::names_s(&gamepad.names);
  p_?gamepad@@3Uunx_gamepad_s@@A = &gamepad;
  *(_OWORD *)&gamepad.remap.buttons.X = _xmm;
  *(_OWORD *)&gamepad.remap.buttons.LB = _xmm;
  *(_OWORD *)&gamepad.remap.buttons.BACK = _xmm;
  return p_?gamepad@@3Uunx_gamepad_s@@A;
}


// ===== xref:SK_Input_GetDI8Keyboard :: ?Init@InputManager@unx@@YAXXZ @ 0x10024da0 (ref 0x10026bfc) =====
// positive sp value has been detected, the output may be wrong!
void __usercall unx::InputManager::Init(int a1@<edi>)
{
  std::wstring *p_injector; // eax
  HMODULE ModuleHandleW; // eax
  const wchar_t *ConfigPath; // edx
  int v4; // ecx
  const wchar_t **v5; // eax
  const wchar_t *v6; // esi
  iSK_INI *(__stdcall *SK_CreateINI)(const wchar_t *const); // eax
  std::_Wrap_alloc<std::allocator<wchar_t> > *v8; // ecx
  const wchar_t *__formal; // ecx
  std::_Wrap_alloc<std::allocator<wchar_t> > *v10; // ecx
  unsigned int Mysize; // esi
  std::_Wrap_alloc<std::allocator<wchar_t> > *Myres; // ecx
  std::wstring *value; // esi
  std::wstring *p_gamepad; // eax
  unx::ParameterFactory *factory_1; // eax
  int config_parameter_15; // ecx
  unx::ParameterFactory *factory; // eax
  unsigned int v18; // esi
  unx::iParameter *config_parameter_16; // ecx
  unx::iParameter *config_parameter_17; // esi
  unx::iParameter *config_parameter_18; // esi
  wchar_t *Ptr; // ecx
  wchar_t *_Ptr_1; // eax
  wchar_t *_Ptr_2; // ecx
  wchar_t *_Ptr_3; // eax
  iSK_INI *ini; // edx
  wchar_t **p_ini_section; // ecx
  unx::iParameter *section; // eax
  bool v29; // cf
  wchar_t **p_ini_key; // ecx
  wchar_t **p_ini_key_1; // ecx
  const std::wstring *_Right; // eax
  unx::iParameter *config_parameter_19; // esi
  unx::iParameter *config_parameter_20; // esi
  wchar_t *_Ptr_4; // ecx
  wchar_t *_Ptr_5; // eax
  wchar_t *_Ptr_6; // ecx
  wchar_t *_Ptr_7; // eax
  int ini_1; // eax
  int ini_2; // ecx
  const wchar_t *__formal_1; // ecx
  unsigned int A; // eax
  iSK_INI *ini_36; // ecx
  unx::iParameter_vtbl *v44; // eax
  iSK_INI *ini_3; // edx
  unx::iParameter *v46; // esi
  int ini_4; // eax
  int ini_5; // ecx
  const wchar_t *__formal_2; // ecx
  unsigned int B; // eax
  iSK_INI *ini_37; // ecx
  unx::iParameter_vtbl *v52; // eax
  iSK_INI *ini_6; // edx
  unx::iParameter *v54; // esi
  int ini_7; // eax
  int ini_8; // ecx
  const wchar_t *__formal_3; // ecx
  unsigned int X; // eax
  iSK_INI *ini_38; // ecx
  unx::iParameter_vtbl *v60; // eax
  iSK_INI *ini_9; // edx
  unx::iParameter *v62; // esi
  int ini_10; // eax
  int ini_11; // ecx
  const wchar_t *__formal_4; // ecx
  unsigned int Y; // eax
  iSK_INI *ini_39; // ecx
  unx::iParameter_vtbl *v68; // eax
  iSK_INI *ini_12; // edx
  unx::iParameter *v70; // esi
  int ini_13; // eax
  int ini_14; // ecx
  const wchar_t *__formal_5; // ecx
  unsigned int START; // eax
  iSK_INI *ini_40; // ecx
  unx::iParameter_vtbl *v76; // eax
  iSK_INI *ini_15; // edx
  unx::iParameter *v78; // esi
  int ini_16; // eax
  int ini_17; // ecx
  const wchar_t *__formal_6; // ecx
  unsigned int BACK; // eax
  iSK_INI *ini_41; // ecx
  unx::iParameter_vtbl *v84; // eax
  iSK_INI *ini_18; // edx
  unx::iParameter *v86; // esi
  int ini_19; // eax
  int ini_20; // ecx
  const wchar_t *__formal_7; // ecx
  unsigned int LB; // eax
  iSK_INI *ini_42; // ecx
  unx::iParameter_vtbl *v92; // eax
  iSK_INI *ini_21; // edx
  unx::iParameter *v94; // esi
  int ini_22; // eax
  int ini_23; // ecx
  const wchar_t *__formal_8; // ecx
  unsigned int RB; // eax
  iSK_INI *ini_43; // ecx
  unx::iParameter_vtbl *v100; // eax
  iSK_INI *ini_24; // edx
  unx::iParameter *v102; // esi
  int ini_25; // eax
  int ini_26; // ecx
  const wchar_t *__formal_9; // ecx
  unsigned int LT; // eax
  iSK_INI *ini_44; // ecx
  unx::iParameter_vtbl *v108; // eax
  iSK_INI *ini_27; // edx
  unx::iParameter *v110; // esi
  int ini_28; // eax
  int ini_29; // ecx
  const wchar_t *__formal_10; // ecx
  unsigned int RT; // eax
  iSK_INI *ini_45; // ecx
  unx::iParameter_vtbl *v116; // eax
  iSK_INI *ini_30; // edx
  unx::iParameter *v118; // esi
  int ini_31; // eax
  int ini_32; // ecx
  const wchar_t *__formal_11; // ecx
  unsigned int LS; // eax
  iSK_INI *ini_46; // ecx
  unx::iParameter_vtbl *v124; // eax
  iSK_INI *ini_33; // edx
  unx::iParameter *v126; // esi
  int ini_34; // eax
  int ini_35; // ecx
  const wchar_t *__formal_12; // ecx
  unsigned int RS; // eax
  iSK_INI *j; // ecx
  unx::iParameter_vtbl *v132; // eax
  iSK_INI *j_1; // edx
  const wchar_t *__formal_13; // ecx
  const wchar_t *__formal_14; // ecx
  const wchar_t *__formal_15; // ecx
  const wchar_t *__formal_16; // ecx
  const wchar_t *__formal_17; // ecx
  const wchar_t *__formal_18; // ecx
  const wchar_t *__formal_19; // ecx
  const wchar_t *__formal_20; // ecx
  const wchar_t *__formal_21; // ecx
  const wchar_t *__formal_22; // ecx
  unx::ParameterStringW *config_parameter_7; // eax
  unx::ParameterStringW *config_parameter; // edi
  unx::iParameter *config_parameter_21; // esi
  const std::wstring *_Right_1; // eax
  const std::wstring *_Right_2; // eax
  unx::iParameter *i_1; // edi
  const std::wstring *_Right_3; // eax
  unx::ParameterFactory *factory_2; // edi
  const std::wstring *_Right_4; // eax
  unx::iParameter *config_parameter_9; // edi
  const std::wstring *_Right_5; // eax
  unx::iParameter *config_parameter_10; // edi
  const std::wstring *_Right_6; // eax
  unx::iParameter *config_parameter_11; // edi
  const std::wstring *_Right_7; // eax
  unx::iParameter *config_parameter_12; // edi
  const std::wstring *_Right_8; // eax
  unx::iParameter *config_parameter_13; // edi
  const std::wstring *_Right_9; // eax
  unx::iParameter *config_parameter_14; // edi
  const std::wstring *_Right_10; // eax
  const std::wstring *_Right_11; // eax
  const wchar_t *_Ptr_8; // edx
  int v167; // ecx
  _DWORD *v168; // eax
  _DWORD *v169; // edx
  std::_Wrap_alloc<std::allocator<wchar_t> > *v170; // ecx
  std::wstring *p_injector_1; // eax
  HMODULE hModule; // eax
  std::wstring *p_injector_2; // eax
  HMODULE hModule_1; // eax
  SK_DI8_Mouse *(__stdcall *?SK_Input_GetDI8Mouse@@3P6GPAUSK_DI8_Mouse@@XZA)(); // eax
  std::wstring *p_injector_3; // ecx
  int *map; // edx
  unsigned int k_1; // eax
  int v179; // ecx
  unsigned int k; // esi
  int v181; // eax
  std::wstring *p_injector_4; // eax
  HMODULE hModule_2; // eax
  void *pDetour; // ecx
  HWND__ *GameWindow; // eax
  _BYTE v186[52]; // [esp-34h] [ebp-704h] BYREF
  void **pwszModule; // [esp+0h] [ebp-6D0h]
  wchar_t lpString1_1[260]; // [esp+4h] [ebp-6CCh] BYREF
  wchar_t lpString1[260]; // [esp+20Ch] [ebp-4C4h] BYREF
  wchar_t String1[260]; // [esp+414h] [ebp-2BCh] BYREF
  LPCWSTR lpString2[16]; // [esp+61Ch] [ebp-B4h]
  unx::iParameter *config_parameter_5; // [esp+65Ch] [ebp-74h]
  unx::iParameter *config_parameter_4; // [esp+660h] [ebp-70h]
  unx::iParameter *config_parameter_3; // [esp+664h] [ebp-6Ch]
  unx::iParameter *config_parameter_2; // [esp+668h] [ebp-68h]
  std::wstring _Left; // [esp+66Ch] [ebp-64h] BYREF
  std::wstring _Ptr; // [esp+684h] [ebp-4Ch] BYREF
  unx::ParameterFactory v198; // [esp+69Ch] [ebp-34h] BYREF
  _BYTE *v199; // [esp+6A8h] [ebp-28h]
  unx::iParameter *config_parameter_6; // [esp+6ACh] [ebp-24h]
  unx::iParameter *config_parameter_1; // [esp+6B0h] [ebp-20h] BYREF
  unx::InputManager::Init::__l2::<lambda_2b651fb238a7ad45244b7d572ab31c2e> v202; // [esp+6B4h] [ebp-1Ch] BYREF
  unx::iParameter *config_parameter_8; // [esp+6B8h] [ebp-18h]
  unx::InputManager::Hooker *?pInputHook@Hooker@InputManager@unx@@0PAV123@A; // [esp+6BCh] [ebp-14h]
  unx::iParameter *i; // [esp+6C0h] [ebp-10h]
  int v206; // [esp+6CCh] [ebp-4h]

  p_injector = &config.system.injector;
  if ( config.system.injector._Mypair._Myval2._Myres >= 8 )
    p_injector = (std::wstring *)config.system.injector._Mypair._Myval2._Bx._Ptr;
  *(_DWORD *)&v186[48] = a1;
  ModuleHandleW = GetModuleHandleW(p_injector->_Mypair._Myval2._Bx._Buf);
  SK_GetGameWindow = (HWND__ *(__stdcall *)())GetProcAddress(ModuleHandleW, "SK_GetGameWindow");
  memset(&v198, 0, sizeof(v198));
  v206 = 0;
  _Left._Mypair._Myval2._Mysize = 0;
  _Left._Mypair._Myval2._Myres = 7;
  _Left._Mypair._Myval2._Bx._Buf[0] = 0;
  ConfigPath = SK_GetConfigPath();
  std::wstring::assign(&_Left, ConfigPath, wcslen(ConfigPath));
  LOBYTE(v206) = 1;
  v5 = (const wchar_t **)((int (__cdecl *)(int))std::operator+<wchar_t>)(v4);
  v6 = (const wchar_t *)v5;
  LOBYTE(v206) = 2;
  if ( (unsigned int)v5[5] >= 8 )
    v6 = *v5;
  SK_CreateINI = ::SK_CreateINI;
  if ( !::SK_CreateINI )
  {
    SK_CreateINI = (iSK_INI *(__stdcall *)(const wchar_t *const))GetProcAddress(hInjectorDLL, "SK_CreateINI");
    ::SK_CreateINI = SK_CreateINI;
  }
  pad_cfg = SK_CreateINI(v6);
  if ( _Ptr._Mypair._Myval2._Myres >= 8 )
    std::_Wrap_alloc<std::allocator<wchar_t>>::deallocate(
      v8,
      _Ptr._Mypair._Myval2._Bx._Ptr,
      _Ptr._Mypair._Myval2._Myres + 1);
  _Ptr._Mypair._Myval2._Mysize = 0;
  _Ptr._Mypair._Myval2._Bx._Buf[0] = 0;
  LOBYTE(v206) = 0;
  _Ptr._Mypair._Myval2._Myres = 7;
  if ( _Left._Mypair._Myval2._Myres >= 8 )
    std::_Wrap_alloc<std::allocator<wchar_t>>::deallocate(
      v8,
      _Left._Mypair._Myval2._Bx._Ptr,
      _Left._Mypair._Myval2._Myres + 1);
  v202.factory = &v198;
  unx_speedstep = lambda_2b651fb238a7ad45244b7d572ab31c2e_::operator()(
                    &v202,
                    &keybinds.SpeedStep,
                    (wchar_t *)L"CycleSpeedBoost");
  unx_kickstart = lambda_2b651fb238a7ad45244b7d572ab31c2e_::operator()(
                    &v202,
                    &keybinds.KickStart,
                    (wchar_t *)L"KickStart");
  unx_timestop = lambda_2b651fb238a7ad45244b7d572ab31c2e_::operator()(
                   &v202,
                   &keybinds.TimeStop,
                   (wchar_t *)L"ToggleTimeStop");
  unx_freelook = lambda_2b651fb238a7ad45244b7d572ab31c2e_::operator()(
                   &v202,
                   &keybinds.FreeLook,
                   (wchar_t *)L"ToggleFreeLook");
  unx_sensor = lambda_2b651fb238a7ad45244b7d572ab31c2e_::operator()(
                 &v202,
                 &keybinds.Sensor,
                 (wchar_t *)L"TogglePermanentSensor");
  unx_fullap = lambda_2b651fb238a7ad45244b7d572ab31c2e_::operator()(
                 &v202,
                 &keybinds.FullAP,
                 (wchar_t *)L"ToggleFullPartyAP");
  unx_VSYNC = lambda_2b651fb238a7ad45244b7d572ab31c2e_::operator()(&v202, &keybinds.VSYNC, (wchar_t *)L"ToggleVSYNC");
  unx_soft_reset = lambda_2b651fb238a7ad45244b7d572ab31c2e_::operator()(
                     &v202,
                     &keybinds.SoftReset,
                     (wchar_t *)L"SoftReset");
  texture_set = (unx::ParameterStringW *)unx::ParameterFactory::create_parameter<std::wstring>(&v198, __formal);
  config_parameter_8 = (unx::iParameter *)&v186[24];
  *(_DWORD *)&v186[40] = 0;
  *(_DWORD *)&v186[44] = 7;
  *(_WORD *)&v186[24] = 0;
  std::wstring::assign((std::wstring *)&v186[24], L"TextureSet", 0xAu);
  LOBYTE(v206) = 3;
  *(_DWORD *)&v186[16] = 0;
  *(_DWORD *)&v186[20] = 7;
  *(_WORD *)v186 = 0;
  std::wstring::assign((std::wstring *)v186, L"Gamepad.Type", 0xCu);
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(texture_set, pad_cfg, *(std::wstring *)v186, *(std::wstring *)&v186[24]);
  if ( !((unsigned __int8 (__thiscall *)(unx::ParameterStringW *, unx_gamepad_s *, _DWORD))texture_set->load)(
          texture_set,
          &gamepad,
          *(_DWORD *)&v186[48]) )
  {
    std::wstring::assign(&gamepad.tex_set, L"PlayStation_Glossy", 0x12u);
    *(_DWORD *)&v186[44] = 0;
    *(_DWORD *)&v186[48] = 7;
    *(_WORD *)&v186[28] = 0;
    std::wstring::assign((std::wstring *)&v186[28], &gamepad.tex_set, 0, 0xFFFFFFFF);
    ((void (__thiscall *)(unx::ParameterStringW *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))texture_set->store)(
      texture_set,
      *(_DWORD *)&v186[28],
      *(_DWORD *)&v186[32],
      *(_DWORD *)&v186[36],
      *(_DWORD *)&v186[40],
      *(_DWORD *)&v186[44],
      *(_DWORD *)&v186[48]);
  }
  Mysize = texture_set->get_value(texture_set, &_Left)->_Mypair._Myval2._Mysize;
  if ( _Left._Mypair._Myval2._Myres >= 8 )
    std::_Wrap_alloc<std::allocator<wchar_t>>::deallocate(
      v10,
      _Left._Mypair._Myval2._Bx._Ptr,
      _Left._Mypair._Myval2._Myres + 1);
  _Left._Mypair._Myval2._Mysize = 0;
  _Left._Mypair._Myval2._Myres = 7;
  _Left._Mypair._Myval2._Bx._Buf[0] = 0;
  if ( Mysize )
  {
    value = texture_set->get_value(texture_set, &_Ptr);
    if ( value != &config.textures.gamepad )
    {
      Myres = (std::_Wrap_alloc<std::allocator<wchar_t> > *)config.textures.gamepad._Mypair._Myval2._Myres;
      if ( config.textures.gamepad._Mypair._Myval2._Myres >= 8 )
        std::_Wrap_alloc<std::allocator<wchar_t>>::deallocate(
          (std::_Wrap_alloc<std::allocator<wchar_t> > *)(config.textures.gamepad._Mypair._Myval2._Myres + 1),
          config.textures.gamepad._Mypair._Myval2._Bx._Ptr,
          config.textures.gamepad._Mypair._Myval2._Myres + 1);
      config.textures.gamepad._Mypair._Myval2._Mysize = 0;
      config.textures.gamepad._Mypair._Myval2._Myres = 7;
      config.textures.gamepad._Mypair._Myval2._Bx._Buf[0] = 0;
      config.textures.gamepad = *value;
      value->_Mypair._Myval2._Mysize = 0;
      value->_Mypair._Myval2._Myres = 7;
      value->_Mypair._Myval2._Bx._Buf[0] = 0;
    }
    if ( _Ptr._Mypair._Myval2._Myres >= 8 )
      std::_Wrap_alloc<std::allocator<wchar_t>>::deallocate(
        Myres,
        _Ptr._Mypair._Myval2._Bx._Ptr,
        _Ptr._Mypair._Myval2._Myres + 1);
    memset(String1, 0, sizeof(String1));
    lstrcatW(String1, L"gamepads\\");
    p_gamepad = &config.textures.gamepad;
    if ( config.textures.gamepad._Mypair._Myval2._Myres >= 8 )
      p_gamepad = (std::wstring *)config.textures.gamepad._Mypair._Myval2._Bx._Ptr;
    lstrcatW(String1, p_gamepad->_Mypair._Myval2._Bx._Buf);
    lstrcatW(String1, L"\\");
    dll_log->Log(dll_log, L"[Button Map] Button Pack: %s", String1);
    memset(lpString1, 0, sizeof(lpString1));
    lstrcatW(lpString1, String1);
    lstrcatW(lpString1, L"ButtonMap.dds");
    dll_log->Log(dll_log, L"[Button Map] Button Map:  %s", lpString1);
    SK_D3D11_AddTexHash(lpString1, config.textures.pad.icons.high, 0);
    SK_D3D11_AddTexHash(lpString1, config.textures.pad.icons.low, 0);
    LOBYTE(factory_1) = 0;
    lpString2[0] = L"A";
    lpString2[1] = L"B";
    LOBYTE(config_parameter_15) = 1;
    lpString2[2] = L"X";
    lpString2[3] = L"Y";
    lpString2[4] = L"LB";
    lpString2[5] = L"RB";
    lpString2[6] = L"LT";
    lpString2[7] = L"RT";
    lpString2[8] = L"LS";
    lpString2[9] = L"RS";
    lpString2[10] = L"UP";
    lpString2[11] = L"RIGHT";
    lpString2[12] = L"DOWN";
    lpString2[13] = L"LEFT";
    lpString2[14] = L"START";
    lpString2[15] = L"SELECT";
    v202.factory = 0;
    do
    {
      config_parameter_15 = (unsigned __int8)config_parameter_15;
      if ( ((unsigned __int8)factory_1 & 1) == 0 )
        config_parameter_15 = 1;
      config_parameter_1 = (unx::iParameter *)config_parameter_15;
      memset(lpString1_1, 0, sizeof(lpString1_1));
      lstrcatW(lpString1_1, String1);
      i = (unx::iParameter *)lpString2[(unsigned int)v202.factory >> 1];
      lstrcatW(lpString1_1, (LPCWSTR)i);
      lstrcatW(lpString1_1, L".dds");
      factory = v202.factory;
      v18 = *(&config.textures.pad.buttons.A.high + (int)v202.factory);
      if ( v18 )
      {
        if ( (_BYTE)config_parameter_1 )
        {
          if ( (int)v202.factory > 0 )
            dll_log->LogEx(dll_log, 0, L"\n");
          dll_log->LogEx(dll_log, 1, L"[Button Map] Button %10s: '%#38s' ( %08x :: ", i, lpString1_1, v18);
          LOBYTE(config_parameter_16) = 0;
          config_parameter_1 = config_parameter_16;
        }
        else
        {
          dll_log->LogEx(dll_log, 0, L"%08x )", v18);
        }
        SK_D3D11_AddTexHash(lpString1_1, v18, 0);
        factory = v202.factory;
      }
      LOBYTE(config_parameter_15) = (_BYTE)config_parameter_1;
      factory_1 = (unx::ParameterFactory *)((char *)&factory->params._Mypair._Myval2._Myfirst + 1);
      v202.factory = factory_1;
    }
    while ( (unsigned int)factory_1 < 0x20 );
    dll_log->LogEx(dll_log, 0, L"\n");
  }
  std::string::assign(&gamepad.f1.combo_name, "F1", 2u);
  std::string::assign(&gamepad.f2.combo_name, "F2", 2u);
  std::string::assign(&gamepad.f3.combo_name, "F3", 2u);
  std::string::assign(&gamepad.f4.combo_name, "F4", 2u);
  std::string::assign(&gamepad.f5.combo_name, "F5", 2u);
  std::string::assign(&gamepad.screenshot.combo_name, "Steam Screenshot", 0x10u);
  std::string::assign(&gamepad.fullscreen.combo_name, "Fullscreen Toggle", 0x11u);
  std::string::assign(&gamepad.esc.combo_name, "PC Game Menu", 0xCu);
  std::string::assign(&gamepad.speedboost.combo_name, "Speed Hack", 0xAu);
  std::string::assign(&gamepad.kickstart.combo_name, "Kickstart", 9u);
  std::string::assign(&gamepad.softreset.combo_name, "Soft Game Reset", 0xFu);
  config_parameter_17 = (unx::iParameter *)operator new(0x40u);
  config_parameter_8 = config_parameter_17;
  memset(config_parameter_17, 0, 0x40u);
  config_parameter_17->ini_section._Mypair._Myval2._Mysize = 0;
  config_parameter_17->ini_section._Mypair._Myval2._Myres = 7;
  config_parameter_17->ini_section._Mypair._Myval2._Bx._Buf[0] = 0;
  config_parameter_17->ini_key._Mypair._Myval2._Mysize = 0;
  config_parameter_17->ini_key._Mypair._Myval2._Myres = 7;
  config_parameter_17->ini_key._Mypair._Myval2._Bx._Buf[0] = 0;
  config_parameter_17->ini = 0;
  *(_DWORD *)&v186[48] = &config_parameter_1;
  config_parameter_17->__vftable = (unx::iParameter_vtbl *)unx::iParameter_vtbl1_;
  config_parameter_1 = config_parameter_17;
  std::vector<unx::iParameter *>::emplace_back<unx::iParameter * const &>(
    &v198.params,
    *(unx::iParameter *const **)&v186[48]);
  _Left._Mypair._Myval2._Mysize = 0;
  _Left._Mypair._Myval2._Myres = 7;
  _Left._Mypair._Myval2._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"UsesXInput", 0xAu);
  LOBYTE(v206) = 4;
  _Ptr._Mypair._Myval2._Mysize = 0;
  _Ptr._Mypair._Myval2._Myres = 7;
  _Ptr._Mypair._Myval2._Bx._Buf[0] = 0;
  std::wstring::assign(&_Ptr, L"Gamepad.Type", 0xCu);
  LOBYTE(v206) = 6;
  config_parameter_18 = config_parameter_1;
  config_parameter_1->ini = pad_cfg;
  if ( &config_parameter_18->ini_section != &_Ptr )
    std::wstring::assign(&config_parameter_18->ini_section, &_Ptr, 0, 0xFFFFFFFF);
  if ( &config_parameter_18->ini_key != &_Left )
    std::wstring::assign(&config_parameter_18->ini_key, &_Left, 0, 0xFFFFFFFF);
  LOBYTE(v206) = 5;
  if ( _Ptr._Mypair._Myval2._Myres >= 8 )
  {
    Ptr = _Ptr._Mypair._Myval2._Bx._Ptr;
    if ( _Ptr._Mypair._Myval2._Myres + 1 > 0x7FFFFFFF )
      __invalid_parameter_noinfo_noreturn();
    if ( 2 * (_Ptr._Mypair._Myval2._Myres + 1) >= 0x1000 )
    {
      if ( (_Ptr._Mypair._Myval2._Bx._Alias[0] & 0x1F) != 0 )
        __invalid_parameter_noinfo_noreturn();
      _Ptr_1 = (wchar_t *)*((_DWORD *)_Ptr._Mypair._Myval2._Bx._Ptr - 1);
      if ( _Ptr_1 >= _Ptr._Mypair._Myval2._Bx._Ptr )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)((char *)_Ptr._Mypair._Myval2._Bx._Ptr - (char *)_Ptr_1) < 4 )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)((char *)_Ptr._Mypair._Myval2._Bx._Ptr - (char *)_Ptr_1) > 0x23 )
        __invalid_parameter_noinfo_noreturn();
      Ptr = (wchar_t *)*((_DWORD *)_Ptr._Mypair._Myval2._Bx._Ptr - 1);
    }
    operator delete(Ptr);
  }
  _Ptr._Mypair._Myval2._Mysize = 0;
  _Ptr._Mypair._Myval2._Bx._Buf[0] = 0;
  LOBYTE(v206) = 0;
  _Ptr._Mypair._Myval2._Myres = 7;
  if ( _Left._Mypair._Myval2._Myres >= 8 )
  {
    _Ptr_2 = _Left._Mypair._Myval2._Bx._Ptr;
    if ( _Left._Mypair._Myval2._Myres + 1 > 0x7FFFFFFF )
      __invalid_parameter_noinfo_noreturn();
    if ( 2 * (_Left._Mypair._Myval2._Myres + 1) >= 0x1000 )
    {
      if ( (_Left._Mypair._Myval2._Bx._Alias[0] & 0x1F) != 0 )
        __invalid_parameter_noinfo_noreturn();
      _Ptr_3 = (wchar_t *)*((_DWORD *)_Left._Mypair._Myval2._Bx._Ptr - 1);
      if ( _Ptr_3 >= _Left._Mypair._Myval2._Bx._Ptr )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)((char *)_Left._Mypair._Myval2._Bx._Ptr - (char *)_Ptr_3) < 4 )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)((char *)_Left._Mypair._Myval2._Bx._Ptr - (char *)_Ptr_3) > 0x23 )
        __invalid_parameter_noinfo_noreturn();
      _Ptr_2 = (wchar_t *)*((_DWORD *)_Left._Mypair._Myval2._Bx._Ptr - 1);
    }
    operator delete(_Ptr_2);
  }
  ini = config_parameter_18->ini;
  if ( !ini )
    goto LABEL_79;
  p_ini_section = (wchar_t **)&config_parameter_18->ini_section;
  if ( config_parameter_18->ini_section._Mypair._Myval2._Myres >= 8 )
    p_ini_section = (wchar_t **)*p_ini_section;
  section = (unx::iParameter *)ini->get_section(ini, (const wchar_t *)p_ini_section);
  v29 = config_parameter_18->ini_key._Mypair._Myval2._Myres < 8;
  p_ini_key = (wchar_t **)&config_parameter_18->ini_key;
  i = section;
  if ( !v29 )
    p_ini_key = (wchar_t **)*p_ini_key;
  if ( ((unsigned __int8 (__stdcall *)(unx::iParameter *, wchar_t **))section->__vftable[2].set_value_str)(
         section,
         p_ini_key) )
  {
    p_ini_key_1 = (wchar_t **)&config_parameter_18->ini_key;
    if ( config_parameter_18->ini_key._Mypair._Myval2._Myres >= 8 )
      p_ini_key_1 = (wchar_t **)*p_ini_key_1;
    _Right = (const std::wstring *)((int (__stdcall *)(unx::iParameter *, wchar_t **))i->__vftable[1].set_value_str)(
                                     i,
                                     p_ini_key_1);
    *(_DWORD *)&v186[44] = 0;
    *(_DWORD *)&v186[48] = 7;
    *(_WORD *)&v186[28] = 0;
    std::wstring::assign((std::wstring *)&v186[28], _Right, 0, 0xFFFFFFFF);
    ((void (__thiscall *)(unx::iParameter *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))config_parameter_18->set_value_str)(
      config_parameter_18,
      *(_DWORD *)&v186[28],
      *(_DWORD *)&v186[32],
      *(_DWORD *)&v186[36],
      *(_DWORD *)&v186[40],
      *(_DWORD *)&v186[44],
      *(_DWORD *)&v186[48]);
    if ( (void (__cdecl *const *)())config_parameter_18->__vftable == unx::iParameter_vtbl1_ )
      gamepad.legacy = LOBYTE(config_parameter_18[1].ini) == 0;
    else
      gamepad.legacy = ((unsigned __int8 (__thiscall *)(unx::iParameter *))config_parameter_18->__vftable[1].get_value_str)(config_parameter_18) == 0;
  }
  else
  {
LABEL_79:
    if ( (void (__cdecl *const *)())config_parameter_18->__vftable == unx::iParameter_vtbl1_ )
    {
      LOBYTE(config_parameter_18[1].ini) = 1;
      unx::iParameter::store(config_parameter_18);
    }
    else
    {
      config_parameter_18->__vftable[2].get_value_str(config_parameter_18, (std::wstring *)1);
    }
  }
  config_parameter_19 = (unx::iParameter *)operator new(0x40u);
  config_parameter_8 = config_parameter_19;
  memset(config_parameter_19, 0, 0x40u);
  config_parameter_19->ini_section._Mypair._Myval2._Mysize = 0;
  config_parameter_19->ini_section._Mypair._Myval2._Myres = 7;
  config_parameter_19->ini_section._Mypair._Myval2._Bx._Buf[0] = 0;
  config_parameter_19->ini_key._Mypair._Myval2._Mysize = 0;
  config_parameter_19->ini_key._Mypair._Myval2._Myres = 7;
  config_parameter_19->ini_key._Mypair._Myval2._Bx._Buf[0] = 0;
  config_parameter_19->ini = 0;
  *(_DWORD *)&v186[48] = &config_parameter_1;
  config_parameter_19->__vftable = (unx::iParameter_vtbl *)unx::iParameter_vtbl2_;
  config_parameter_1 = config_parameter_19;
  std::vector<unx::iParameter *>::emplace_back<unx::iParameter * const &>(
    &v198.params,
    *(unx::iParameter *const **)&v186[48]);
  _Left._Mypair._Myval2._Mysize = 0;
  _Left._Mypair._Myval2._Myres = 7;
  _Left._Mypair._Myval2._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"XInput_A", 8u);
  LOBYTE(v206) = 7;
  _Ptr._Mypair._Myval2._Mysize = 0;
  _Ptr._Mypair._Myval2._Myres = 7;
  _Ptr._Mypair._Myval2._Bx._Buf[0] = 0;
  std::wstring::assign(&_Ptr, L"Gamepad.Remap", 0xDu);
  LOBYTE(v206) = 9;
  config_parameter_20 = config_parameter_1;
  config_parameter_1->ini = pad_cfg;
  if ( &config_parameter_20->ini_section != &_Ptr )
    std::wstring::assign(&config_parameter_20->ini_section, &_Ptr, 0, 0xFFFFFFFF);
  if ( &config_parameter_20->ini_key != &_Left )
    std::wstring::assign(&config_parameter_20->ini_key, &_Left, 0, 0xFFFFFFFF);
  LOBYTE(v206) = 8;
  if ( _Ptr._Mypair._Myval2._Myres >= 8 )
  {
    _Ptr_4 = _Ptr._Mypair._Myval2._Bx._Ptr;
    if ( _Ptr._Mypair._Myval2._Myres + 1 > 0x7FFFFFFF )
      __invalid_parameter_noinfo_noreturn();
    if ( 2 * (_Ptr._Mypair._Myval2._Myres + 1) >= 0x1000 )
    {
      if ( (_Ptr._Mypair._Myval2._Bx._Alias[0] & 0x1F) != 0 )
        __invalid_parameter_noinfo_noreturn();
      _Ptr_5 = (wchar_t *)*((_DWORD *)_Ptr._Mypair._Myval2._Bx._Ptr - 1);
      if ( _Ptr_5 >= _Ptr._Mypair._Myval2._Bx._Ptr )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)((char *)_Ptr._Mypair._Myval2._Bx._Ptr - (char *)_Ptr_5) < 4 )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)((char *)_Ptr._Mypair._Myval2._Bx._Ptr - (char *)_Ptr_5) > 0x23 )
        __invalid_parameter_noinfo_noreturn();
      _Ptr_4 = (wchar_t *)*((_DWORD *)_Ptr._Mypair._Myval2._Bx._Ptr - 1);
    }
    operator delete(_Ptr_4);
  }
  _Ptr._Mypair._Myval2._Mysize = 0;
  _Ptr._Mypair._Myval2._Bx._Buf[0] = 0;
  LOBYTE(v206) = 0;
  _Ptr._Mypair._Myval2._Myres = 7;
  if ( _Left._Mypair._Myval2._Myres >= 8 )
  {
    _Ptr_6 = _Left._Mypair._Myval2._Bx._Ptr;
    if ( _Left._Mypair._Myval2._Myres + 1 > 0x7FFFFFFF )
      __invalid_parameter_noinfo_noreturn();
    if ( 2 * (_Left._Mypair._Myval2._Myres + 1) >= 0x1000 )
    {
      if ( (_Left._Mypair._Myval2._Bx._Alias[0] & 0x1F) != 0 )
        __invalid_parameter_noinfo_noreturn();
      _Ptr_7 = (wchar_t *)*((_DWORD *)_Left._Mypair._Myval2._Bx._Ptr - 1);
      if ( _Ptr_7 >= _Left._Mypair._Myval2._Bx._Ptr )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)((char *)_Left._Mypair._Myval2._Bx._Ptr - (char *)_Ptr_7) < 4 )
        __invalid_parameter_noinfo_noreturn();
      if ( (unsigned int)((char *)_Left._Mypair._Myval2._Bx._Ptr - (char *)_Ptr_7) > 0x23 )
        __invalid_parameter_noinfo_noreturn();
      _Ptr_6 = (wchar_t *)*((_DWORD *)_Left._Mypair._Myval2._Bx._Ptr - 1);
    }
    operator delete(_Ptr_6);
  }
  if ( unx::iParameter::load(config_parameter_20) )
  {
    if ( (void (__cdecl *const *)())config_parameter_20->__vftable == unx::iParameter_vtbl2_ )
      ini_1 = (int)config_parameter_20[1].ini;
    else
      ini_1 = ((int (__thiscall *)(unx::iParameter *))config_parameter_20->__vftable[1].get_value_str)(config_parameter_20);
    ini_2 = 16 - ini_1;
    if ( ini_1 > 0 )
      ini_2 = ini_1;
    __formal_1 = (const wchar_t *)(ini_2 - 1);
    gamepad.remap.buttons.A = 1 << (char)__formal_1;
  }
  else
  {
    A = gamepad.remap.buttons.A;
    ini_36 = 0;
    for ( i = (unx::iParameter *)gamepad.remap.buttons.A; A; A >>= 1 )
      ini_36 = (iSK_INI *)((char *)ini_36 + 1);
    v44 = config_parameter_20->__vftable;
    ini_3 = (iSK_INI *)(16 - (_DWORD)ini_36);
    if ( (unsigned int)i < 0x10000 )
      ini_3 = ini_36;
    i = (unx::iParameter *)v44[2].get_value_str;
    if ( v44 == (unx::iParameter_vtbl *)unx::iParameter_vtbl2_ )
    {
      config_parameter_20[1].ini = ini_3;
      unx::iParameter::store(config_parameter_20);
    }
    else
    {
      ((void (__thiscall *)(unx::iParameter *, iSK_INI *))i)(config_parameter_20, ini_3);
    }
  }
  v46 = unx::ParameterFactory::create_parameter<int>(&v198, __formal_1);
  config_parameter_8 = (unx::iParameter *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], L"XInput_B", 8u);
  LOBYTE(v206) = 10;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.Remap", 0xDu);
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(v46, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( unx::iParameter::load(v46) )
  {
    if ( (void (__cdecl *const *)())v46->__vftable == unx::iParameter_vtbl2_ )
      ini_4 = (int)v46[1].ini;
    else
      ini_4 = ((int (__thiscall *)(unx::iParameter *))v46->__vftable[1].get_value_str)(v46);
    ini_5 = 16 - ini_4;
    if ( ini_4 > 0 )
      ini_5 = ini_4;
    __formal_2 = (const wchar_t *)(ini_5 - 1);
    gamepad.remap.buttons.B = 1 << (char)__formal_2;
  }
  else
  {
    B = gamepad.remap.buttons.B;
    ini_37 = 0;
    for ( i = (unx::iParameter *)gamepad.remap.buttons.B; B; B >>= 1 )
      ini_37 = (iSK_INI *)((char *)ini_37 + 1);
    v52 = v46->__vftable;
    ini_6 = (iSK_INI *)(16 - (_DWORD)ini_37);
    if ( (unsigned int)i < 0x10000 )
      ini_6 = ini_37;
    i = (unx::iParameter *)v52[2].get_value_str;
    if ( v52 == (unx::iParameter_vtbl *)unx::iParameter_vtbl2_ )
    {
      v46[1].ini = ini_6;
      unx::iParameter::store(v46);
    }
    else
    {
      ((void (__thiscall *)(unx::iParameter *, iSK_INI *))i)(v46, ini_6);
    }
  }
  v54 = unx::ParameterFactory::create_parameter<int>(&v198, __formal_2);
  config_parameter_8 = (unx::iParameter *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], L"XInput_X", 8u);
  LOBYTE(v206) = 11;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.Remap", 0xDu);
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(v54, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( unx::iParameter::load(v54) )
  {
    if ( (void (__cdecl *const *)())v54->__vftable == unx::iParameter_vtbl2_ )
      ini_7 = (int)v54[1].ini;
    else
      ini_7 = ((int (__thiscall *)(unx::iParameter *))v54->__vftable[1].get_value_str)(v54);
    ini_8 = 16 - ini_7;
    if ( ini_7 > 0 )
      ini_8 = ini_7;
    __formal_3 = (const wchar_t *)(ini_8 - 1);
    gamepad.remap.buttons.X = 1 << (char)__formal_3;
  }
  else
  {
    X = gamepad.remap.buttons.X;
    ini_38 = 0;
    for ( i = (unx::iParameter *)gamepad.remap.buttons.X; X; X >>= 1 )
      ini_38 = (iSK_INI *)((char *)ini_38 + 1);
    v60 = v54->__vftable;
    ini_9 = (iSK_INI *)(16 - (_DWORD)ini_38);
    if ( (unsigned int)i < 0x10000 )
      ini_9 = ini_38;
    i = (unx::iParameter *)v60[2].get_value_str;
    if ( v60 == (unx::iParameter_vtbl *)unx::iParameter_vtbl2_ )
    {
      v54[1].ini = ini_9;
      unx::iParameter::store(v54);
    }
    else
    {
      ((void (__thiscall *)(unx::iParameter *, iSK_INI *))i)(v54, ini_9);
    }
  }
  v62 = unx::ParameterFactory::create_parameter<int>(&v198, __formal_3);
  config_parameter_8 = (unx::iParameter *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], L"XInput_Y", 8u);
  LOBYTE(v206) = 12;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.Remap", 0xDu);
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(v62, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( unx::iParameter::load(v62) )
  {
    if ( (void (__cdecl *const *)())v62->__vftable == unx::iParameter_vtbl2_ )
      ini_10 = (int)v62[1].ini;
    else
      ini_10 = ((int (__thiscall *)(unx::iParameter *))v62->__vftable[1].get_value_str)(v62);
    ini_11 = 16 - ini_10;
    if ( ini_10 > 0 )
      ini_11 = ini_10;
    __formal_4 = (const wchar_t *)(ini_11 - 1);
    gamepad.remap.buttons.Y = 1 << (char)__formal_4;
  }
  else
  {
    Y = gamepad.remap.buttons.Y;
    ini_39 = 0;
    for ( i = (unx::iParameter *)gamepad.remap.buttons.Y; Y; Y >>= 1 )
      ini_39 = (iSK_INI *)((char *)ini_39 + 1);
    v68 = v62->__vftable;
    ini_12 = (iSK_INI *)(16 - (_DWORD)ini_39);
    if ( (unsigned int)i < 0x10000 )
      ini_12 = ini_39;
    i = (unx::iParameter *)v68[2].get_value_str;
    if ( v68 == (unx::iParameter_vtbl *)unx::iParameter_vtbl2_ )
    {
      v62[1].ini = ini_12;
      unx::iParameter::store(v62);
    }
    else
    {
      ((void (__thiscall *)(unx::iParameter *, iSK_INI *))i)(v62, ini_12);
    }
  }
  v70 = unx::ParameterFactory::create_parameter<int>(&v198, __formal_4);
  config_parameter_8 = (unx::iParameter *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], L"XInput_Start", 0xCu);
  LOBYTE(v206) = 13;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.Remap", 0xDu);
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(v70, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( unx::iParameter::load(v70) )
  {
    if ( (void (__cdecl *const *)())v70->__vftable == unx::iParameter_vtbl2_ )
      ini_13 = (int)v70[1].ini;
    else
      ini_13 = ((int (__thiscall *)(unx::iParameter *))v70->__vftable[1].get_value_str)(v70);
    ini_14 = 16 - ini_13;
    if ( ini_13 > 0 )
      ini_14 = ini_13;
    __formal_5 = (const wchar_t *)(ini_14 - 1);
    gamepad.remap.buttons.START = 1 << (char)__formal_5;
  }
  else
  {
    START = gamepad.remap.buttons.START;
    ini_40 = 0;
    for ( i = (unx::iParameter *)gamepad.remap.buttons.START; START; START >>= 1 )
      ini_40 = (iSK_INI *)((char *)ini_40 + 1);
    v76 = v70->__vftable;
    ini_15 = (iSK_INI *)(16 - (_DWORD)ini_40);
    if ( (unsigned int)i < 0x10000 )
      ini_15 = ini_40;
    i = (unx::iParameter *)v76[2].get_value_str;
    if ( v76 == (unx::iParameter_vtbl *)unx::iParameter_vtbl2_ )
    {
      v70[1].ini = ini_15;
      unx::iParameter::store(v70);
    }
    else
    {
      ((void (__thiscall *)(unx::iParameter *, iSK_INI *))i)(v70, ini_15);
    }
  }
  v78 = unx::ParameterFactory::create_parameter<int>(&v198, __formal_5);
  config_parameter_8 = (unx::iParameter *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], L"XInput_Back", 0xBu);
  LOBYTE(v206) = 14;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.Remap", 0xDu);
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(v78, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( unx::iParameter::load(v78) )
  {
    if ( (void (__cdecl *const *)())v78->__vftable == unx::iParameter_vtbl2_ )
      ini_16 = (int)v78[1].ini;
    else
      ini_16 = ((int (__thiscall *)(unx::iParameter *))v78->__vftable[1].get_value_str)(v78);
    ini_17 = 16 - ini_16;
    if ( ini_16 > 0 )
      ini_17 = ini_16;
    __formal_6 = (const wchar_t *)(ini_17 - 1);
    gamepad.remap.buttons.BACK = 1 << (char)__formal_6;
  }
  else
  {
    BACK = gamepad.remap.buttons.BACK;
    ini_41 = 0;
    for ( i = (unx::iParameter *)gamepad.remap.buttons.BACK; BACK; BACK >>= 1 )
      ini_41 = (iSK_INI *)((char *)ini_41 + 1);
    v84 = v78->__vftable;
    ini_18 = (iSK_INI *)(16 - (_DWORD)ini_41);
    if ( (unsigned int)i < 0x10000 )
      ini_18 = ini_41;
    i = (unx::iParameter *)v84[2].get_value_str;
    if ( v84 == (unx::iParameter_vtbl *)unx::iParameter_vtbl2_ )
    {
      v78[1].ini = ini_18;
      unx::iParameter::store(v78);
    }
    else
    {
      ((void (__thiscall *)(unx::iParameter *, iSK_INI *))i)(v78, ini_18);
    }
  }
  v86 = unx::ParameterFactory::create_parameter<int>(&v198, __formal_6);
  config_parameter_8 = (unx::iParameter *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], L"XInput_LB", 9u);
  LOBYTE(v206) = 15;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.Remap", 0xDu);
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(v86, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( unx::iParameter::load(v86) )
  {
    if ( (void (__cdecl *const *)())v86->__vftable == unx::iParameter_vtbl2_ )
      ini_19 = (int)v86[1].ini;
    else
      ini_19 = ((int (__thiscall *)(unx::iParameter *))v86->__vftable[1].get_value_str)(v86);
    ini_20 = 16 - ini_19;
    if ( ini_19 > 0 )
      ini_20 = ini_19;
    __formal_7 = (const wchar_t *)(ini_20 - 1);
    gamepad.remap.buttons.LB = 1 << (char)__formal_7;
  }
  else
  {
    LB = gamepad.remap.buttons.LB;
    ini_42 = 0;
    for ( i = (unx::iParameter *)gamepad.remap.buttons.LB; LB; LB >>= 1 )
      ini_42 = (iSK_INI *)((char *)ini_42 + 1);
    v92 = v86->__vftable;
    ini_21 = (iSK_INI *)(16 - (_DWORD)ini_42);
    if ( (unsigned int)i < 0x10000 )
      ini_21 = ini_42;
    i = (unx::iParameter *)v92[2].get_value_str;
    if ( v92 == (unx::iParameter_vtbl *)unx::iParameter_vtbl2_ )
    {
      v86[1].ini = ini_21;
      unx::iParameter::store(v86);
    }
    else
    {
      ((void (__thiscall *)(unx::iParameter *, iSK_INI *))i)(v86, ini_21);
    }
  }
  v94 = unx::ParameterFactory::create_parameter<int>(&v198, __formal_7);
  config_parameter_8 = (unx::iParameter *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], L"XInput_RB", 9u);
  LOBYTE(v206) = 16;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.Remap", 0xDu);
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(v94, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( unx::iParameter::load(v94) )
  {
    if ( (void (__cdecl *const *)())v94->__vftable == unx::iParameter_vtbl2_ )
      ini_22 = (int)v94[1].ini;
    else
      ini_22 = ((int (__thiscall *)(unx::iParameter *))v94->__vftable[1].get_value_str)(v94);
    ini_23 = 16 - ini_22;
    if ( ini_22 > 0 )
      ini_23 = ini_22;
    __formal_8 = (const wchar_t *)(ini_23 - 1);
    gamepad.remap.buttons.RB = 1 << (char)__formal_8;
  }
  else
  {
    RB = gamepad.remap.buttons.RB;
    ini_43 = 0;
    for ( i = (unx::iParameter *)gamepad.remap.buttons.RB; RB; RB >>= 1 )
      ini_43 = (iSK_INI *)((char *)ini_43 + 1);
    v100 = v94->__vftable;
    ini_24 = (iSK_INI *)(16 - (_DWORD)ini_43);
    if ( (unsigned int)i < 0x10000 )
      ini_24 = ini_43;
    i = (unx::iParameter *)v100[2].get_value_str;
    if ( v100 == (unx::iParameter_vtbl *)unx::iParameter_vtbl2_ )
    {
      v94[1].ini = ini_24;
      unx::iParameter::store(v94);
    }
    else
    {
      ((void (__thiscall *)(unx::iParameter *, iSK_INI *))i)(v94, ini_24);
    }
  }
  v102 = unx::ParameterFactory::create_parameter<int>(&v198, __formal_8);
  config_parameter_8 = (unx::iParameter *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], L"XInput_LT", 9u);
  LOBYTE(v206) = 17;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.Remap", 0xDu);
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(v102, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( unx::iParameter::load(v102) )
  {
    if ( (void (__cdecl *const *)())v102->__vftable == unx::iParameter_vtbl2_ )
      ini_25 = (int)v102[1].ini;
    else
      ini_25 = ((int (__thiscall *)(unx::iParameter *))v102->__vftable[1].get_value_str)(v102);
    ini_26 = 16 - ini_25;
    if ( ini_25 > 0 )
      ini_26 = ini_25;
    __formal_9 = (const wchar_t *)(ini_26 - 1);
    gamepad.remap.buttons.LT = 1 << (char)__formal_9;
  }
  else
  {
    LT = gamepad.remap.buttons.LT;
    ini_44 = 0;
    for ( i = (unx::iParameter *)gamepad.remap.buttons.LT; LT; LT >>= 1 )
      ini_44 = (iSK_INI *)((char *)ini_44 + 1);
    v108 = v102->__vftable;
    ini_27 = (iSK_INI *)(16 - (_DWORD)ini_44);
    if ( (unsigned int)i < 0x10000 )
      ini_27 = ini_44;
    i = (unx::iParameter *)v108[2].get_value_str;
    if ( v108 == (unx::iParameter_vtbl *)unx::iParameter_vtbl2_ )
    {
      v102[1].ini = ini_27;
      unx::iParameter::store(v102);
    }
    else
    {
      ((void (__thiscall *)(unx::iParameter *, iSK_INI *))i)(v102, ini_27);
    }
  }
  v110 = unx::ParameterFactory::create_parameter<int>(&v198, __formal_9);
  config_parameter_8 = (unx::iParameter *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], L"XInput_RT", 9u);
  LOBYTE(v206) = 18;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.Remap", 0xDu);
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(v110, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( unx::iParameter::load(v110) )
  {
    if ( (void (__cdecl *const *)())v110->__vftable == unx::iParameter_vtbl2_ )
      ini_28 = (int)v110[1].ini;
    else
      ini_28 = ((int (__thiscall *)(unx::iParameter *))v110->__vftable[1].get_value_str)(v110);
    ini_29 = 16 - ini_28;
    if ( ini_28 > 0 )
      ini_29 = ini_28;
    __formal_10 = (const wchar_t *)(ini_29 - 1);
    gamepad.remap.buttons.RT = 1 << (char)__formal_10;
  }
  else
  {
    RT = gamepad.remap.buttons.RT;
    ini_45 = 0;
    for ( i = (unx::iParameter *)gamepad.remap.buttons.RT; RT; RT >>= 1 )
      ini_45 = (iSK_INI *)((char *)ini_45 + 1);
    v116 = v110->__vftable;
    ini_30 = (iSK_INI *)(16 - (_DWORD)ini_45);
    if ( (unsigned int)i < 0x10000 )
      ini_30 = ini_45;
    i = (unx::iParameter *)v116[2].get_value_str;
    if ( v116 == (unx::iParameter_vtbl *)unx::iParameter_vtbl2_ )
    {
      v110[1].ini = ini_30;
      unx::iParameter::store(v110);
    }
    else
    {
      ((void (__thiscall *)(unx::iParameter *, iSK_INI *))i)(v110, ini_30);
    }
  }
  v118 = unx::ParameterFactory::create_parameter<int>(&v198, __formal_10);
  config_parameter_8 = (unx::iParameter *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], L"XInput_LS", 9u);
  LOBYTE(v206) = 19;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.Remap", 0xDu);
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(v118, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( unx::iParameter::load(v118) )
  {
    if ( (void (__cdecl *const *)())v118->__vftable == unx::iParameter_vtbl2_ )
      ini_31 = (int)v118[1].ini;
    else
      ini_31 = ((int (__thiscall *)(unx::iParameter *))v118->__vftable[1].get_value_str)(v118);
    ini_32 = 16 - ini_31;
    if ( ini_31 > 0 )
      ini_32 = ini_31;
    __formal_11 = (const wchar_t *)(ini_32 - 1);
    gamepad.remap.buttons.LS = 1 << (char)__formal_11;
  }
  else
  {
    LS = gamepad.remap.buttons.LS;
    ini_46 = 0;
    for ( i = (unx::iParameter *)gamepad.remap.buttons.LS; LS; LS >>= 1 )
      ini_46 = (iSK_INI *)((char *)ini_46 + 1);
    v124 = v118->__vftable;
    ini_33 = (iSK_INI *)(16 - (_DWORD)ini_46);
    if ( (unsigned int)i < 0x10000 )
      ini_33 = ini_46;
    i = (unx::iParameter *)v124[2].get_value_str;
    if ( v124 == (unx::iParameter_vtbl *)unx::iParameter_vtbl2_ )
    {
      v118[1].ini = ini_33;
      unx::iParameter::store(v118);
    }
    else
    {
      ((void (__thiscall *)(unx::iParameter *, iSK_INI *))i)(v118, ini_33);
    }
  }
  v126 = unx::ParameterFactory::create_parameter<int>(&v198, __formal_11);
  config_parameter_8 = (unx::iParameter *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], L"XInput_RS", 9u);
  LOBYTE(v206) = 20;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.Remap", 0xDu);
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(v126, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( unx::iParameter::load(v126) )
  {
    if ( (void (__cdecl *const *)())v126->__vftable == unx::iParameter_vtbl2_ )
      ini_34 = (int)v126[1].ini;
    else
      ini_34 = ((int (__thiscall *)(unx::iParameter *))v126->__vftable[1].get_value_str)(v126);
    ini_35 = 16 - ini_34;
    if ( ini_34 > 0 )
      ini_35 = ini_34;
    __formal_12 = (const wchar_t *)(ini_35 - 1);
    gamepad.remap.buttons.RS = 1 << (char)__formal_12;
  }
  else
  {
    RS = gamepad.remap.buttons.RS;
    for ( j = 0; RS; RS >>= 1 )
      j = (iSK_INI *)((char *)j + 1);
    v132 = v126->__vftable;
    j_1 = (iSK_INI *)(16 - (_DWORD)j);
    if ( gamepad.remap.buttons.RS < 0x10000u )
      j_1 = j;
    if ( v132 == (unx::iParameter_vtbl *)unx::iParameter_vtbl2_ )
    {
      v126[1].ini = j_1;
      unx::iParameter::store(v126);
    }
    else
    {
      v132[2].get_value_str(v126, (std::wstring *)j_1);
    }
  }
  gamepad.speedboost.config_parameter = (unx::ParameterStringW *)unx::ParameterFactory::create_parameter<std::wstring>(
                                                                   &v198,
                                                                   __formal_12);
  gamepad.kickstart.config_parameter = (unx::ParameterStringW *)unx::ParameterFactory::create_parameter<std::wstring>(
                                                                  &v198,
                                                                  __formal_13);
  gamepad.f1.config_parameter = (unx::ParameterStringW *)unx::ParameterFactory::create_parameter<std::wstring>(
                                                           &v198,
                                                           __formal_14);
  gamepad.f2.config_parameter = (unx::ParameterStringW *)unx::ParameterFactory::create_parameter<std::wstring>(
                                                           &v198,
                                                           __formal_15);
  gamepad.f3.config_parameter = (unx::ParameterStringW *)unx::ParameterFactory::create_parameter<std::wstring>(
                                                           &v198,
                                                           __formal_16);
  gamepad.f4.config_parameter = (unx::ParameterStringW *)unx::ParameterFactory::create_parameter<std::wstring>(
                                                           &v198,
                                                           __formal_17);
  gamepad.f5.config_parameter = (unx::ParameterStringW *)unx::ParameterFactory::create_parameter<std::wstring>(
                                                           &v198,
                                                           __formal_18);
  gamepad.esc.config_parameter = (unx::ParameterStringW *)unx::ParameterFactory::create_parameter<std::wstring>(
                                                            &v198,
                                                            __formal_19);
  gamepad.fullscreen.config_parameter = (unx::ParameterStringW *)unx::ParameterFactory::create_parameter<std::wstring>(
                                                                   &v198,
                                                                   __formal_20);
  gamepad.screenshot.config_parameter = (unx::ParameterStringW *)unx::ParameterFactory::create_parameter<std::wstring>(
                                                                   &v198,
                                                                   __formal_21);
  config_parameter_7 = (unx::ParameterStringW *)unx::ParameterFactory::create_parameter<std::wstring>(
                                                  &v198,
                                                  __formal_22);
  config_parameter = gamepad.kickstart.config_parameter;
  config_parameter_21 = config_parameter_7;
  config_parameter_1 = gamepad.speedboost.config_parameter;
  i = gamepad.f1.config_parameter;
  v202.factory = (unx::ParameterFactory *)gamepad.f2.config_parameter;
  config_parameter_2 = gamepad.f3.config_parameter;
  config_parameter_3 = gamepad.f4.config_parameter;
  config_parameter_4 = gamepad.f5.config_parameter;
  config_parameter_5 = gamepad.esc.config_parameter;
  config_parameter_6 = gamepad.fullscreen.config_parameter;
  v199 = &v186[28];
  gamepad.softreset.config_parameter = config_parameter_7;
  config_parameter_8 = gamepad.screenshot.config_parameter;
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], L"SpeedBoost", 0xAu);
  LOBYTE(v206) = 21;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.PC", 0xAu);
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(config_parameter_1, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( !config_parameter_1->__vftable[3].get_value_str(config_parameter_1, &gamepad.speedboost.unparsed) )
  {
    _Right_1 = std::wstring::assign(&gamepad.speedboost.unparsed, L"Select+L2+Cross", 0xFu);
    *(_DWORD *)&v186[44] = 0;
    *(_DWORD *)&v186[48] = 7;
    *(_WORD *)&v186[28] = 0;
    std::wstring::assign((std::wstring *)&v186[28], _Right_1, 0, 0xFFFFFFFF);
    ((void (__thiscall *)(unx::iParameter *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))config_parameter_1->__vftable[2].get_value_str)(
      config_parameter_1,
      *(_DWORD *)&v186[28],
      *(_DWORD *)&v186[32],
      *(_DWORD *)&v186[36],
      *(_DWORD *)&v186[40],
      *(_DWORD *)&v186[44],
      *(_DWORD *)&v186[48]);
  }
  ?pInputHook@Hooker@InputManager@unx@@0PAV123@A = (unx::InputManager::Hooker *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], L"KickStart", 9u);
  LOBYTE(v206) = 22;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.PC", 0xAu);
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(config_parameter, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( !config_parameter->load(config_parameter, &gamepad.kickstart.unparsed) )
  {
    _Right_2 = std::wstring::assign(&gamepad.kickstart.unparsed, L"L1+L2+Up", 8u);
    *(_DWORD *)&v186[44] = 0;
    *(_DWORD *)&v186[48] = 7;
    *(_WORD *)&v186[28] = 0;
    std::wstring::assign((std::wstring *)&v186[28], _Right_2, 0, 0xFFFFFFFF);
    ((void (__thiscall *)(unx::ParameterStringW *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))config_parameter->store)(
      config_parameter,
      *(_DWORD *)&v186[28],
      *(_DWORD *)&v186[32],
      *(_DWORD *)&v186[36],
      *(_DWORD *)&v186[40],
      *(_DWORD *)&v186[44],
      *(_DWORD *)&v186[48]);
  }
  ?pInputHook@Hooker@InputManager@unx@@0PAV123@A = (unx::InputManager::Hooker *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], aF1, 2u);
  LOBYTE(v206) = 23;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.PC", 0xAu);
  i_1 = i;
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(i, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( !i_1->__vftable[3].get_value_str(i_1, &gamepad.f1.unparsed) )
  {
    _Right_3 = std::wstring::assign(&gamepad.f1.unparsed, L"Select+Cross", 0xCu);
    *(_DWORD *)&v186[44] = 0;
    *(_DWORD *)&v186[48] = 7;
    *(_WORD *)&v186[28] = 0;
    std::wstring::assign((std::wstring *)&v186[28], _Right_3, 0, 0xFFFFFFFF);
    ((void (__thiscall *)(unx::iParameter *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))i_1->__vftable[2].get_value_str)(
      i_1,
      *(_DWORD *)&v186[28],
      *(_DWORD *)&v186[32],
      *(_DWORD *)&v186[36],
      *(_DWORD *)&v186[40],
      *(_DWORD *)&v186[44],
      *(_DWORD *)&v186[48]);
  }
  ?pInputHook@Hooker@InputManager@unx@@0PAV123@A = (unx::InputManager::Hooker *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], aF2_2, 2u);
  LOBYTE(v206) = 24;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.PC", 0xAu);
  factory_2 = v202.factory;
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(
    (unx::iParameter *)v202.factory,
    pad_cfg,
    *(std::wstring *)&v186[4],
    *(std::wstring *)&v186[28]);
  if ( !(*((unsigned __int8 (__thiscall **)(unx::ParameterFactory *, std::wstring *))factory_2->params._Mypair._Myval2._Myfirst
         + 6))(
          factory_2,
          &gamepad.f2.unparsed) )
  {
    _Right_4 = std::wstring::assign(&gamepad.f1.unparsed, L"Select+Circle", 0xDu);
    *(_DWORD *)&v186[44] = 0;
    *(_DWORD *)&v186[48] = 7;
    *(_WORD *)&v186[28] = 0;
    std::wstring::assign((std::wstring *)&v186[28], _Right_4, 0, 0xFFFFFFFF);
    (*((void (__thiscall **)(unx::ParameterFactory *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))factory_2->params._Mypair._Myval2._Myfirst
     + 4))(
      factory_2,
      *(_DWORD *)&v186[28],
      *(_DWORD *)&v186[32],
      *(_DWORD *)&v186[36],
      *(_DWORD *)&v186[40],
      *(_DWORD *)&v186[44],
      *(_DWORD *)&v186[48]);
  }
  ?pInputHook@Hooker@InputManager@unx@@0PAV123@A = (unx::InputManager::Hooker *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], aF3_0, 2u);
  LOBYTE(v206) = 25;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.PC", 0xAu);
  config_parameter_9 = config_parameter_2;
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(config_parameter_2, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( !config_parameter_9->__vftable[3].get_value_str(config_parameter_9, &gamepad.f3.unparsed) )
  {
    _Right_5 = std::wstring::assign(&gamepad.f3.unparsed, L"Select+Square", 0xDu);
    *(_DWORD *)&v186[44] = 0;
    *(_DWORD *)&v186[48] = 7;
    *(_WORD *)&v186[28] = 0;
    std::wstring::assign((std::wstring *)&v186[28], _Right_5, 0, 0xFFFFFFFF);
    ((void (__thiscall *)(unx::iParameter *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))config_parameter_9->__vftable[2].get_value_str)(
      config_parameter_9,
      *(_DWORD *)&v186[28],
      *(_DWORD *)&v186[32],
      *(_DWORD *)&v186[36],
      *(_DWORD *)&v186[40],
      *(_DWORD *)&v186[44],
      *(_DWORD *)&v186[48]);
  }
  ?pInputHook@Hooker@InputManager@unx@@0PAV123@A = (unx::InputManager::Hooker *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], aF4_0, 2u);
  LOBYTE(v206) = 26;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.PC", 0xAu);
  config_parameter_10 = config_parameter_3;
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(config_parameter_3, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( !config_parameter_10->__vftable[3].get_value_str(config_parameter_10, &gamepad.f4.unparsed) )
  {
    _Right_6 = std::wstring::assign(&gamepad.f4.unparsed, L"Select+L1", 9u);
    *(_DWORD *)&v186[44] = 0;
    *(_DWORD *)&v186[48] = 7;
    *(_WORD *)&v186[28] = 0;
    std::wstring::assign((std::wstring *)&v186[28], _Right_6, 0, 0xFFFFFFFF);
    ((void (__thiscall *)(unx::iParameter *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))config_parameter_10->__vftable[2].get_value_str)(
      config_parameter_10,
      *(_DWORD *)&v186[28],
      *(_DWORD *)&v186[32],
      *(_DWORD *)&v186[36],
      *(_DWORD *)&v186[40],
      *(_DWORD *)&v186[44],
      *(_DWORD *)&v186[48]);
  }
  ?pInputHook@Hooker@InputManager@unx@@0PAV123@A = (unx::InputManager::Hooker *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], aF5_0, 2u);
  LOBYTE(v206) = 27;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.PC", 0xAu);
  config_parameter_11 = config_parameter_4;
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(config_parameter_4, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( !config_parameter_11->__vftable[3].get_value_str(config_parameter_11, &gamepad.f5.unparsed) )
  {
    _Right_7 = std::wstring::assign(&gamepad.f5.unparsed, L"Select+R1", 9u);
    *(_DWORD *)&v186[44] = 0;
    *(_DWORD *)&v186[48] = 7;
    *(_WORD *)&v186[28] = 0;
    std::wstring::assign((std::wstring *)&v186[28], _Right_7, 0, 0xFFFFFFFF);
    ((void (__thiscall *)(unx::iParameter *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))config_parameter_11->__vftable[2].get_value_str)(
      config_parameter_11,
      *(_DWORD *)&v186[28],
      *(_DWORD *)&v186[32],
      *(_DWORD *)&v186[36],
      *(_DWORD *)&v186[40],
      *(_DWORD *)&v186[44],
      *(_DWORD *)&v186[48]);
  }
  ?pInputHook@Hooker@InputManager@unx@@0PAV123@A = (unx::InputManager::Hooker *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], L"ESC", 3u);
  LOBYTE(v206) = 28;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.PC", 0xAu);
  config_parameter_12 = config_parameter_5;
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(config_parameter_5, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( !config_parameter_12->__vftable[3].get_value_str(config_parameter_12, &gamepad.esc.unparsed) )
  {
    _Right_8 = std::wstring::assign(&gamepad.esc.unparsed, L"L2+R2+Select", 0xCu);
    *(_DWORD *)&v186[44] = 0;
    *(_DWORD *)&v186[48] = 7;
    *(_WORD *)&v186[28] = 0;
    std::wstring::assign((std::wstring *)&v186[28], _Right_8, 0, 0xFFFFFFFF);
    ((void (__thiscall *)(unx::iParameter *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))config_parameter_12->__vftable[2].get_value_str)(
      config_parameter_12,
      *(_DWORD *)&v186[28],
      *(_DWORD *)&v186[32],
      *(_DWORD *)&v186[36],
      *(_DWORD *)&v186[40],
      *(_DWORD *)&v186[44],
      *(_DWORD *)&v186[48]);
  }
  ?pInputHook@Hooker@InputManager@unx@@0PAV123@A = (unx::InputManager::Hooker *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], L"Fullscreen", 0xAu);
  LOBYTE(v206) = 29;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.PC", 0xAu);
  config_parameter_13 = config_parameter_6;
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(config_parameter_6, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( !config_parameter_13->__vftable[3].get_value_str(config_parameter_13, &gamepad.fullscreen.unparsed) )
  {
    _Right_9 = std::wstring::assign(&gamepad.fullscreen.unparsed, L"L2+L3", 5u);
    *(_DWORD *)&v186[44] = 0;
    *(_DWORD *)&v186[48] = 7;
    *(_WORD *)&v186[28] = 0;
    std::wstring::assign((std::wstring *)&v186[28], _Right_9, 0, 0xFFFFFFFF);
    ((void (__thiscall *)(unx::iParameter *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))config_parameter_13->__vftable[2].get_value_str)(
      config_parameter_13,
      *(_DWORD *)&v186[28],
      *(_DWORD *)&v186[32],
      *(_DWORD *)&v186[36],
      *(_DWORD *)&v186[40],
      *(_DWORD *)&v186[44],
      *(_DWORD *)&v186[48]);
  }
  ?pInputHook@Hooker@InputManager@unx@@0PAV123@A = (unx::InputManager::Hooker *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], L"Screenshot", 0xAu);
  LOBYTE(v206) = 30;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.Steam", 0xDu);
  config_parameter_14 = config_parameter_8;
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(config_parameter_8, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( !config_parameter_14->__vftable[3].get_value_str(config_parameter_14, &gamepad.screenshot.unparsed) )
  {
    _Right_10 = std::wstring::assign(&gamepad.screenshot.unparsed, L"Select+R3", 9u);
    *(_DWORD *)&v186[44] = 0;
    *(_DWORD *)&v186[48] = 7;
    *(_WORD *)&v186[28] = 0;
    std::wstring::assign((std::wstring *)&v186[28], _Right_10, 0, 0xFFFFFFFF);
    ((void (__thiscall *)(unx::iParameter *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))config_parameter_14->__vftable[2].get_value_str)(
      config_parameter_14,
      *(_DWORD *)&v186[28],
      *(_DWORD *)&v186[32],
      *(_DWORD *)&v186[36],
      *(_DWORD *)&v186[40],
      *(_DWORD *)&v186[44],
      *(_DWORD *)&v186[48]);
  }
  ?pInputHook@Hooker@InputManager@unx@@0PAV123@A = (unx::InputManager::Hooker *)&v186[28];
  *(_DWORD *)&v186[44] = 0;
  *(_DWORD *)&v186[48] = 7;
  *(_WORD *)&v186[28] = 0;
  std::wstring::assign((std::wstring *)&v186[28], L"SoftReset", 9u);
  LOBYTE(v206) = 31;
  *(_DWORD *)&v186[20] = 0;
  *(_DWORD *)&v186[24] = 7;
  *(_WORD *)&v186[4] = 0;
  std::wstring::assign((std::wstring *)&v186[4], L"Gamepad.PC", 0xAu);
  LOBYTE(v206) = 0;
  unx::iParameter::register_to_ini(config_parameter_21, pad_cfg, *(std::wstring *)&v186[4], *(std::wstring *)&v186[28]);
  if ( !config_parameter_21->__vftable[3].get_value_str(config_parameter_21, &gamepad.softreset.unparsed) )
  {
    _Right_11 = std::wstring::assign(&gamepad.softreset.unparsed, L"L1+L2+R1+R2+Select+Start", 0x18u);
    *(_DWORD *)&v186[44] = 0;
    *(_DWORD *)&v186[48] = 7;
    *(_WORD *)&v186[28] = 0;
    std::wstring::assign((std::wstring *)&v186[28], _Right_11, 0, 0xFFFFFFFF);
    ((void (__thiscall *)(unx::iParameter *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))config_parameter_21->__vftable[2].get_value_str)(
      config_parameter_21,
      *(_DWORD *)&v186[28],
      *(_DWORD *)&v186[32],
      *(_DWORD *)&v186[36],
      *(_DWORD *)&v186[40],
      *(_DWORD *)&v186[44],
      *(_DWORD *)&v186[48]);
  }
  _Ptr_8 = SK_GetConfigPath();
  _Left._Mypair._Myval2._Mysize = 0;
  _Left._Mypair._Myval2._Myres = 7;
  _Left._Mypair._Myval2._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, _Ptr_8, wcslen(_Ptr_8));
  LOBYTE(v206) = 32;
  v168 = (_DWORD *)((int (__cdecl *)(int))std::operator+<wchar_t>)(v167);
  v169 = v168;
  LOBYTE(v206) = 33;
  if ( v168[5] >= 8u )
    v169 = (_DWORD *)*v168;
  *(_DWORD *)&v186[48] = v169;
  ((void (__stdcall *)(iSK_INI *))pad_cfg->write)(pad_cfg);
  if ( _Ptr._Mypair._Myval2._Myres >= 8 )
    std::_Wrap_alloc<std::allocator<wchar_t>>::deallocate(
      v170,
      _Ptr._Mypair._Myval2._Bx._Ptr,
      _Ptr._Mypair._Myval2._Myres + 1);
  _Ptr._Mypair._Myval2._Mysize = 0;
  _Ptr._Mypair._Myval2._Bx._Buf[0] = 0;
  LOBYTE(v206) = 0;
  _Ptr._Mypair._Myval2._Myres = 7;
  if ( _Left._Mypair._Myval2._Myres >= 8 )
    std::_Wrap_alloc<std::allocator<wchar_t>>::deallocate(
      v170,
      _Left._Mypair._Myval2._Bx._Ptr,
      _Left._Mypair._Myval2._Myres + 1);
  if ( config.input.remap_dinput8 )
  {
    p_injector_1 = &config.system.injector;
    *(_DWORD *)&v186[44] = "SK_Input_GetDI8Keyboard";
    if ( config.system.injector._Mypair._Myval2._Myres >= 8 )
      p_injector_1 = (std::wstring *)config.system.injector._Mypair._Myval2._Bx._Ptr;
    hModule = GetModuleHandleW(p_injector_1->_Mypair._Myval2._Bx._Buf);
    SK_Input_GetDI8Keyboard = (SK_DI8_Keyboard *(__stdcall *)())GetProcAddress(hModule, *(LPCSTR *)&v186[44]);
    p_injector_2 = &config.system.injector;
    if ( config.system.injector._Mypair._Myval2._Myres >= 8 )
      p_injector_2 = (std::wstring *)config.system.injector._Mypair._Myval2._Bx._Ptr;
    *(_DWORD *)&v186[44] = "SK_Input_GetDI8Mouse";
    hModule_1 = GetModuleHandleW(p_injector_2->_Mypair._Myval2._Bx._Buf);
    ?SK_Input_GetDI8Mouse@@3P6GPAUSK_DI8_Mouse@@XZA = (SK_DI8_Mouse *(__stdcall *)())GetProcAddress(
                                                                                       hModule_1,
                                                                                       *(LPCSTR *)&v186[44]);
    p_injector_3 = &config.system.injector;
    SK_Input_GetDI8Mouse = ?SK_Input_GetDI8Mouse@@3P6GPAUSK_DI8_Mouse@@XZA;
    if ( config.system.injector._Mypair._Myval2._Myres >= 8 )
      p_injector_3 = (std::wstring *)config.system.injector._Mypair._Myval2._Bx._Ptr;
    UNX_CreateDLLHook2(
      (const wchar_t *)IDirectInputDevice8_GetDeviceState_Detour,
      (void **)&IDirectInputDevice8_GetDeviceState_Original,
      p_injector_3,
      *(void ***)&v186[48],
      pwszModule);
  }
  map = gamepad.remap.map;
  do
  {
    k_1 = *(map - 12);
    v179 = 0;
    for ( k = k_1; k_1; k_1 >>= 1 )
      ++v179;
    v181 = 16 - v179;
    if ( k < 0x10000 )
      v181 = v179;
    *map++ = v181 - 1;
  }
  while ( (int)map < (int)&humanKeyNameToVirtKeyCode );
  p_injector_4 = &config.system.injector;
  *(_DWORD *)&v186[44] = "SK_XInput_PollController";
  if ( config.system.injector._Mypair._Myval2._Myres >= 8 )
    p_injector_4 = (std::wstring *)config.system.injector._Mypair._Myval2._Bx._Ptr;
  hModule_2 = GetModuleHandleW(p_injector_4->_Mypair._Myval2._Bx._Buf);
  SK_XInput_PollController = (bool (__stdcall *)(int, _XINPUT_STATE *))GetProcAddress(hModule_2, *(LPCSTR *)&v186[44]);
  UNX_CreateDLLHook2(
    (const wchar_t *)SK_UNX_PluginKeyPress,
    (void **)&SK_PluginKeyPress_Original,
    pDetour,
    *(void ***)&v186[48],
    pwszModule);
  UNX_ApplyQueuedHooks();
  if ( !unx::InputManager::Hooker::pInputHook )
  {
    ?pInputHook@Hooker@InputManager@unx@@0PAV123@A = (unx::InputManager::Hooker *)operator new(4u);
    unx::InputManager::Hooker::pInputHook = ?pInputHook@Hooker@InputManager@unx@@0PAV123@A;
  }
  GameWindow = SK_GetGameWindow();
  UNX_InstallWindowHook(GameWindow);
  if ( v198.params._Mypair._Myval2._Myfirst )
    std::_Wrap_alloc<std::allocator<unx::iParameter *>>::deallocate(
      (std::_Wrap_alloc<std::allocator<unx::iParameter *> > *)v198.params._Mypair._Myval2._Myfirst,
      v198.params._Mypair._Myval2._Myfirst,
      v198.params._Mypair._Myval2._Myend - v198.params._Mypair._Myval2._Myfirst);
}


// ===== xref:Voice :: ?UNX_PatchLanguageFFX_Will@@YA_NW4asset_type_t@@@Z @ 0x100270a0 (ref 0x100270da) =====
// positive sp value has been detected, the output may be wrong!
char __fastcall UNX_PatchLanguageFFX_Will(asset_type_t type)
{
  char type_1; // bl
  std::queue<unsigned long> threads; // [esp-14h] [ebp-3Ch] BYREF
  std::queue<unsigned long> *v4; // [esp+0h] [ebp-28h]
  std::deque<unsigned long> _Right; // [esp+4h] [ebp-24h] BYREF
  std::queue<unsigned long> *p_threads; // [esp+18h] [ebp-10h]
  int v7; // [esp+24h] [ebp-4h]

  type_1 = type;
  UNX_SuspendAllOtherThreads(v4);
  v7 = 0;
  if ( (type_1 & 1) != 0 )
  {
    UNX_PatchLanguageRef(Voice, 0, "Voice/JP/ffx_jp_voice_btl.fev", "Voice/US/ffx_us_voice_btl.fev");
    UNX_PatchLanguageRef(Voice, 1, "Voice/JP/VoiceFevMapper.txt", "Voice/US/VoiceFevMapper.txt");
    UNX_PatchLanguageRef(
      Voice,
      2,
      "Voice/JP/ffx_jp_voice_btl_iop_bank00.fsb",
      "Voice/US/ffx_us_voice_btl_iop_bank00.fsb");
    UNX_PatchLanguageRef(Voice, 3, "Voice/JP/", "Voice/US/");
    UNX_PatchLanguageRef(Voice, 4, "ffx_jp_voice01", "ffx_us_voice01");
    UNX_PatchLanguageRef(Voice, 5, "ffx_jp_voice270", "ffx_us_voice270");
  }
  if ( (type_1 & 2) != 0 )
  {
    UNX_PatchLanguageRef(SoundEffect, 0, "SFX/JP/%04d.fev", "SFX/US/%04d.fev");
    UNX_PatchLanguageRef(SoundEffect, 1, "SFX/JP/9999.fev", "SFX/US/9999.fev");
  }
  if ( (type_1 & 4) != 0 )
  {
    UNX_PatchLanguageRef(Video, 0, "JP/FFX_VideoList.txt", "US/FFX_VideoList.txt");
    if ( std::wstring::_Equal(&config.language.video, L"us") )
      UNX_PatchLanguageRef(Video, 1, "Asia/FFX_VideoList.txt", "US/FFX_VideoList.txt");
    UNX_PatchLanguageRef(
      Video,
      1,
      "/MetaMenu/GameData/PS3Data/Video/JP/SideStory.webm",
      "/MetaMenu/GameData/PS3Data/Video/US/SideStory.webm");
    if ( std::wstring::_Equal(&config.language.video, L"jp") )
      UNX_PatchLanguageRef(
        Video,
        2,
        "/MetaMenu/GameData/PS3Data/Video/JP/timestamp_JP.txt",
        "/MetaMenu/GameData/PS3Data/Video/US/timestamp_%s.txt");
  }
  p_threads = &threads;
  std::deque<unsigned long>::deque<unsigned long>(&threads.c, &_Right);
  UNX_ResumeThreads(threads);
  std::deque<unsigned long>::_Tidy(&_Right);
  operator delete(_Right._Mypair._Myval2._Myproxy);
  return 1;
}


// ===== xref:Voice :: ?UNX_PatchLanguageFFX@@YA_NW4asset_type_t@@@Z @ 0x10027450 (ref 0x1002748a) =====
// positive sp value has been detected, the output may be wrong!
char __fastcall UNX_PatchLanguageFFX(asset_type_t type)
{
  char type_1; // bl
  std::queue<unsigned long> threads; // [esp-14h] [ebp-3Ch] BYREF
  std::queue<unsigned long> *v4; // [esp+0h] [ebp-28h]
  std::deque<unsigned long> _Right; // [esp+4h] [ebp-24h] BYREF
  std::queue<unsigned long> *p_threads; // [esp+18h] [ebp-10h]
  int v7; // [esp+24h] [ebp-4h]

  type_1 = type;
  UNX_SuspendAllOtherThreads(v4);
  v7 = 0;
  if ( (type_1 & 1) != 0 )
  {
    UNX_PatchLanguageRef(Voice, 0, "Voice/JP/ffx_jp_voice_btl.fev", "Voice/US/ffx_us_voice_btl.fev");
    UNX_PatchLanguageRef(Voice, 1, "Voice/JP/VoiceFevMapper.txt", "Voice/US/VoiceFevMapper.txt");
    UNX_PatchLanguageRef(
      Voice,
      2,
      "Voice/JP/ffx_jp_voice_btl_iop_bank00.fsb",
      "Voice/US/ffx_us_voice_btl_iop_bank00.fsb");
    UNX_PatchLanguageRef(Voice, 3, "Voice/JP/", "Voice/US/");
    UNX_PatchLanguageRef(Voice, 4, "ffx_jp_voice01", "ffx_us_voice01");
    UNX_PatchLanguageRef(Voice, 5, "ffx_jp_voice270", "ffx_us_voice270");
  }
  if ( (type_1 & 2) != 0 )
  {
    UNX_PatchLanguageRef(SoundEffect, 0, "SFX/JP/%04d.fev", "SFX/US/%04d.fev");
    UNX_PatchLanguageRef(SoundEffect, 1, "SFX/JP/9999.fev", "SFX/US/9999.fev");
  }
  if ( (type_1 & 4) != 0 )
  {
    UNX_PatchLanguageRef(Video, 0, "JP/FFX_VideoList.txt", "US/FFX_VideoList.txt");
    if ( std::wstring::_Equal(&config.language.video, L"us") )
      UNX_PatchLanguageRef(Video, 1, "Asia/FFX_VideoList.txt", "US/FFX_VideoList.txt");
    if ( std::wstring::_Equal(&config.language.video, L"jp") )
      UNX_PatchLanguageRef(
        Video,
        2,
        "/MetaMenu/GameData/PS3Data/Video/JP/timestamp_JP.txt",
        "/MetaMenu/GameData/PS3Data/Video/US/timestamp_%s.txt");
  }
  p_threads = &threads;
  std::deque<unsigned long>::deque<unsigned long>(&threads.c, &_Right);
  UNX_ResumeThreads(threads);
  std::deque<unsigned long>::_Tidy(&_Right);
  operator delete(_Right._Mypair._Myval2._Myproxy);
  return 1;
}


// ===== xref:mem_b_D2A8E2_2 :: ?SK_BeginBufferSwap_Detour@@YGXXZ @ 0x10028850 (ref 0x100288c7) =====
wchar_t *SK_BeginBufferSwap_Detour()
{
  SK_ICommandProcessor *CommandProcessor; // eax
  DWORD Time; // eax
  unsigned int Time_1; // edi
  std::string *_Right; // eax
  char *Ptr; // ecx
  char *_Ptr; // eax
  std::string *_Ptr_1; // eax
  char *_Ptr_2; // ecx
  char *_Ptr_3; // eax
  wchar_t *result; // eax
  FARPROC SK_UpdateSoftware; // edi
  FARPROC SK_FetchVersionInfo; // eax
  std::wstring *p_?injector_name@@3V?$basic_string@_WU?$char_traits@_W@std@@V?$; // ecx
  int (__stdcall *SK_FetchVersionInfo_1)(const wchar_t *); // esi
  char v14; // [esp+0h] [ebp-90h] BYREF
  std::string v15; // [esp+8h] [ebp-88h] BYREF
  std::string v16; // [esp+20h] [ebp-70h] BYREF
  std::string v17; // [esp+38h] [ebp-58h] BYREF
  std::string block; // [esp+54h] [ebp-3Ch] BYREF
  std::string v19; // [esp+6Ch] [ebp-24h] BYREF
  int v20; // [esp+8Ch] [ebp-4h]

  UNX_PollInput();
  if ( !unx::window.render_thread )
    unx::window.render_thread = GetCurrentThreadId();
  if ( SK_BeginBufferSwap_Original )
    SK_BeginBufferSwap_Original();
  else
    dll_log->Log(dll_log, L" !!! Unexpected Lack of SK_BufferSwap_Override in dxgi.dll !!! ");
  if ( _InterlockedCompareExchange((volatile signed __int32 *)&queue_death, 0, 1) )
  {
    CommandProcessor = SK_GetCommandProcessor();
    CommandProcessor->ProcessCommandLine(CommandProcessor, (SK_ICommandResult *)&v14, "mem b D2A8E2 2 ");
    std::string::_Tidy_deallocate(&v17);
    std::string::_Tidy_deallocate(&v16);
    std::string::_Tidy_deallocate(&v15);
    UNX_KillMeNow();
  }
  if ( SKX_DrawExternalOSD )
  {
    if ( pOnce__0 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 4) )
    {
      _Init_thread_header(&pOnce__0);
      if ( pOnce__0 == -1 )
      {
        first_frame_time = timeGetTime();
        _Init_thread_footer(&pOnce__0);
      }
    }
    Time = timeGetTime();
    v19._Mypair._Myval2._Mysize = 0;
    Time_1 = Time;
    v19._Mypair._Myval2._Myres = 15;
    v19._Mypair._Myval2._Bx._Buf[0] = 0;
    std::string::assign(&v19, ::Ptr, 0);
    v20 = 0;
    if ( draw_osd_toggle )
    {
      if ( Time_1 - first_frame_time >= 0x1388 )
        draw_osd_toggle = 0;
      else
        std::string::append(
          &v19,
          "  Press Ctrl + Shift + O         to toggle In-Game OSD\n"
          "  Press Ctrl + Shift + Backspace to access In-Game Config Menu\n"
          "    ( Press Start + Select on Gamepads )\n"
          "      [Titlebar will colorcycle in gamepad mode]\n"
          "\n",
          0xD1u);
    }
    _Right = UNX_SummarizeCheats(&block, Time_1);
    LOBYTE(v20) = 1;
    std::string::append(&v19, _Right, 0, 0xFFFFFFFF);
    LOBYTE(v20) = 0;
    if ( block._Mypair._Myval2._Myres >= 0x10 )
    {
      Ptr = block._Mypair._Myval2._Bx._Ptr;
      if ( block._Mypair._Myval2._Myres + 1 >= 0x1000 )
      {
        if ( (block._Mypair._Myval2._Bx._Buf[0] & 0x1F) != 0 )
          __invalid_parameter_noinfo_noreturn();
        _Ptr = (char *)*((_DWORD *)block._Mypair._Myval2._Bx._Ptr - 1);
        if ( _Ptr >= block._Mypair._Myval2._Bx._Ptr )
          __invalid_parameter_noinfo_noreturn();
        if ( (unsigned int)(block._Mypair._Myval2._Bx._Ptr - _Ptr) < 4 )
          __invalid_parameter_noinfo_noreturn();
        if ( (unsigned int)(block._Mypair._Myval2._Bx._Ptr - _Ptr) > 0x23 )
          __invalid_parameter_noinfo_noreturn();
        Ptr = (char *)*((_DWORD *)block._Mypair._Myval2._Bx._Ptr - 1);
      }
      operator delete(Ptr);
    }
    _Ptr_1 = &v19;
    block._Mypair._Myval2._Mysize = 0;
    if ( v19._Mypair._Myval2._Myres >= 0x10 )
      _Ptr_1 = (std::string *)v19._Mypair._Myval2._Bx._Ptr;
    block._Mypair._Myval2._Myres = 15;
    block._Mypair._Myval2._Bx._Buf[0] = 0;
    SKX_DrawExternalOSD("UnX Status", _Ptr_1->_Mypair._Myval2._Bx._Buf);
    v20 = -1;
    if ( v19._Mypair._Myval2._Myres >= 0x10 )
    {
      _Ptr_2 = v19._Mypair._Myval2._Bx._Ptr;
      if ( v19._Mypair._Myval2._Myres + 1 >= 0x1000 )
      {
        if ( (v19._Mypair._Myval2._Bx._Buf[0] & 0x1F) != 0 )
          __invalid_parameter_noinfo_noreturn();
        _Ptr_3 = (char *)*((_DWORD *)v19._Mypair._Myval2._Bx._Ptr - 1);
        if ( _Ptr_3 >= v19._Mypair._Myval2._Bx._Ptr )
          __invalid_parameter_noinfo_noreturn();
        if ( (unsigned int)(v19._Mypair._Myval2._Bx._Ptr - _Ptr_3) < 4 )
          __invalid_parameter_noinfo_noreturn();
        if ( (unsigned int)(v19._Mypair._Myval2._Bx._Ptr - _Ptr_3) > 0x23 )
          __invalid_parameter_noinfo_noreturn();
        _Ptr_2 = (char *)*((_DWORD *)v19._Mypair._Myval2._Bx._Ptr - 1);
      }
      operator delete(_Ptr_2);
    }
    v19._Mypair._Myval2._Mysize = 0;
    v19._Mypair._Myval2._Myres = 15;
    v19._Mypair._Myval2._Bx._Buf[0] = 0;
  }
  result = (wchar_t *)_InterlockedCompareExchange((volatile signed __int32 *)&init_2, 1, 0);
  if ( !result )
  {
    SK_UpdateSoftware = GetProcAddress(hInjectorDLL, "SK_UpdateSoftware");
    SK_FetchVersionInfo = GetProcAddress(hInjectorDLL, "SK_FetchVersionInfo");
    p_?injector_name@@3V?$basic_string@_WU?$char_traits@_W@std@@V?$ = &injector_name;
    if ( injector_name._Mypair._Myval2._Myres >= 8 )
      p_?injector_name@@3V?$basic_string@_WU?$char_traits@_W@std@@V?$ = (std::wstring *)injector_name._Mypair._Myval2._Bx._Ptr;
    SK_FetchVersionInfo_1 = (int (__stdcall *)(const wchar_t *))SK_FetchVersionInfo;
    result = _wcsstr(
               p_?injector_name@@3V?$basic_string@_WU?$char_traits@_W@std@@V?$->_Mypair._Myval2._Bx._Buf,
               L"SpecialK");
    if ( !result )
    {
      if ( SK_FetchVersionInfo_1 )
      {
        if ( SK_UpdateSoftware )
        {
          result = (wchar_t *)SK_FetchVersionInfo_1(L"UnX");
          if ( (_BYTE)result )
            return (wchar_t *)((int (__stdcall *)(const wchar_t *))SK_UpdateSoftware)(L"UnX");
        }
      }
    }
  }
  return result;
}


// ===== ffx_memory_s_ctor :: ??0unx_ffx_memory_s@@QAE@XZ @ 0x100016c0 (ref 0x100016c0) =====
unx_ffx_memory_s *__thiscall unx_ffx_memory_s::unx_ffx_memory_s(unx_ffx_memory_s *this)
{
  ffx.ap = 0;
  *(_OWORD *)&ffx.debug_flags = 0;
  return &ffx;
}


// ===== ffx2_memory_s_ctor :: ??0unx_ffx2_memory_s@@QAE@XZ @ 0x10001690 (ref 0x10001690) =====
unx_ffx2_memory_s *__thiscall unx_ffx2_memory_s::unx_ffx2_memory_s(unx_ffx2_memory_s *this)
{
  unx_ffx2_memory_s *p_?ffx2@@3Uunx_ffx2_memory_s@@A; // eax

  ffx2.debug_flags = 0;
  p_?ffx2@@3Uunx_ffx2_memory_s@@A = &ffx2;
  ffx2.party = 0;
  return p_?ffx2@@3Uunx_ffx2_memory_s@@A;
}


// ===== CheatTimer_FFX :: ?CheatTimer_FFX@unx@@YAXXZ @ 0x1001df40 (ref 0x1001df40) =====
void __thiscall unx::CheatTimer_FFX(void *flOldProtect_1)
{
  unx_ffx_memory_s::battle_s *battle; // esi
  int v2; // ecx
  int n7; // edx
  unsigned __int8 in_party; // al
  int v5; // ecx
  int i; // edx
  unsigned __int8 in_party_1; // al
  unsigned int flOldProtect; // [esp+0h] [ebp-4h] BYREF

  flOldProtect = (unsigned int)flOldProtect_1;
  if ( game_type == GAME_FFX )
  {
    if ( config.cheat.ffx.permanent_sensor )
      ffx.debug_flags->permanent_sensor = config.cheat.ffx.permanent_sensor;
    ffx.party[7].in_party = config.cheat.ffx.playable_seymour + 16;
    if ( config.cheat.ffx.entire_party_earns_ap && UNX_IsInBattle() )
    {
      VirtualProtect(ffx.battle, 8u, 4u, &flOldProtect);
      battle = ffx.battle;
      v2 = 0;
      n7 = 0;
      while ( 1 )
      {
        in_party = ffx.party[n7].in_party;
        if ( !in_party || in_party == 16 )
          break;
        if ( battle[v2].participation != 1 )
        {
          battle[v2].participation = 2;
LABEL_12:
          battle = ffx.battle;
        }
        ++n7;
        ++v2;
        if ( n7 >= 7 )
        {
          VirtualProtect(battle, 8u, flOldProtect, &flOldProtect);
          VirtualProtect(ffx.ap, 8u, 4u, &flOldProtect);
          v5 = 0;
          for ( i = 0; i < 7; ++i )
          {
            in_party_1 = ffx.party[i].in_party;
            ffx.ap[v5++].earn = in_party_1 && in_party_1 != 16;
          }
          VirtualProtect(ffx.ap, 8u, flOldProtect, &flOldProtect);
          return;
        }
      }
      battle[v2].participation = 0;
      goto LABEL_12;
    }
  }
}


// ===== CheatManager_Init :: ?Init@CheatManager@unx@@YAXXZ @ 0x1001e610 (ref 0x1001e610) =====
(decompile failed)

// ===== UNX_ToggleSensor :: ?UNX_ToggleSensor@@YAXXZ @ 0x1001e520 (ref 0x1001e520) =====
void __thiscall UNX_ToggleSensor(void *this)
{
  bool permanent_sensor; // cl
  DWORD Time; // eax
  bool permanent_sensor_1; // [esp+1h] [ebp-1h]

  if ( game_type == GAME_FFX )
  {
    permanent_sensor = !config.cheat.ffx.permanent_sensor;
    permanent_sensor_1 = !config.cheat.ffx.permanent_sensor;
    if ( config.cheat.ffx.permanent_sensor != !config.cheat.ffx.permanent_sensor )
    {
      Time = timeGetTime();
      permanent_sensor = permanent_sensor_1;
      last_changed.sensor = Time;
    }
    config.cheat.ffx.permanent_sensor = permanent_sensor;
    ffx.debug_flags->permanent_sensor = permanent_sensor;
  }
}


// ===== UNX_FFX_AudioSkip :: ?UNX_FFX_AudioSkip@@YAX_N@Z @ 0x1001e880 (ref 0x1001e880) =====
// positive sp value has been detected, the output may be wrong!
void __fastcall UNX_FFX_AudioSkip(bool bSkip)
{
  _BYTE *pFMODSyncAddr; // ecx
  std::queue<unsigned long> threads; // [esp-14h] [ebp-40h] BYREF
  std::queue<unsigned long> *v4; // [esp+0h] [ebp-2Ch]
  std::deque<unsigned long> _Right; // [esp+4h] [ebp-28h] BYREF
  unsigned int flOldProtect; // [esp+18h] [ebp-14h] BYREF
  std::queue<unsigned long> *p_threads; // [esp+1Ch] [ebp-10h]
  int v8; // [esp+28h] [ebp-4h]

  if ( pOnce__1 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 4) )
  {
    _Init_thread_header(&pOnce__1);
    if ( pOnce__1 == -1 )
    {
      pFMODSyncAddr = (char *)__UNX_base_img_addr + 3190464;
      _Init_thread_footer(&pOnce__1);
    }
  }
  if ( !init )
  {
    init = 1;
    *(_WORD *)orig_inst = *(_WORD *)pFMODSyncAddr;
    byte_1003308A = *((_BYTE *)pFMODSyncAddr + 2);
  }
  UNX_SuspendAllOtherThreads(v4);
  v8 = 0;
  VirtualProtect(pFMODSyncAddr, 3u, 4u, &flOldProtect);
  pFMODSyncAddr = pFMODSyncAddr;
  if ( bSkip )
  {
    LOWORD(p_threads) = 2242;
    *(_WORD *)pFMODSyncAddr = 2242;
    pFMODSyncAddr[2] = 0;
  }
  else
  {
    *(_WORD *)pFMODSyncAddr = *(_WORD *)orig_inst;
    pFMODSyncAddr[2] = byte_1003308A;
  }
  __UNX_skip_cutscenes = bSkip;
  VirtualProtect(pFMODSyncAddr, 3u, flOldProtect, &flOldProtect);
  p_threads = &threads;
  std::deque<unsigned long>::deque<unsigned long>(&threads.c, &_Right);
  UNX_ResumeThreads(threads);
  std::deque<unsigned long>::_Tidy(&_Right);
  operator delete(_Right._Mypair._Myval2._Myproxy);
}


// ===== UNX_PatchLanguageFFX2 :: ?UNX_PatchLanguageFFX2@@YA_NW4asset_type_t@@@Z @ 0x10027270 (ref 0x10027270) =====
// positive sp value has been detected, the output may be wrong!
char __fastcall UNX_PatchLanguageFFX2(asset_type_t type)
{
  char type_1; // bl
  std::queue<unsigned long> threads; // [esp-14h] [ebp-3Ch] BYREF
  std::queue<unsigned long> *v4; // [esp+0h] [ebp-28h]
  std::deque<unsigned long> _Right; // [esp+4h] [ebp-24h] BYREF
  std::queue<unsigned long> *p_threads; // [esp+18h] [ebp-10h]
  int v7; // [esp+24h] [ebp-4h]

  type_1 = type;
  UNX_SuspendAllOtherThreads(v4);
  v7 = 0;
  if ( (type_1 & 1) != 0 )
  {
    UNX_PatchLanguageRef(Voice, 0, "Voice/JP/ffx2_jp_voice_btl.fev", "Voice/US/ffx2_us_voice_btl.fev");
    UNX_PatchLanguageRef(Voice, 1, "Voice/JP/VoiceFevMapper.txt", "Voice/US/VoiceFevMapper.txt");
    UNX_PatchLanguageRef(
      Voice,
      2,
      "Voice/JP/ffx2_jp_voice_btl_iop_bank00.fsb",
      "Voice/US/ffx2_us_voice_btl_iop_bank00.fsb");
    UNX_PatchLanguageRef(Voice, 3, "Voice/JP/", "Voice/US/");
    UNX_PatchLanguageRef(Voice, 4, "ffx2_jp_voice00_2", "ffx2_us_voice00_2");
    UNX_PatchLanguageRef(Voice, 5, "ffx2_jp_voice02_2", "ffx2_us_voice02_2");
    UNX_PatchLanguageRef(Voice, 6, "ffx2_jp_voice03_2", "ffx2_us_voice03_2");
    UNX_PatchLanguageRef(Voice, 7, "ffx2_jp_voice04_2", "ffx2_us_voice04_2");
    UNX_PatchLanguageRef(Voice, 8, "ffx2_jp_voice06_1", "ffx2_us_voice06_1");
  }
  if ( (type_1 & 2) != 0 )
    UNX_PatchLanguageRef(SoundEffect, 0, "SFX/JP/%04d.fev", "SFX/US/%04d.fev");
  if ( (type_1 & 4) != 0 )
  {
    UNX_PatchLanguageRef(Video, 0, "JP/FFX_VideoList.txt", "US/FFX_VideoList.txt");
    if ( std::wstring::_Equal(&config.language.video, L"us") )
      UNX_PatchLanguageRef(Video, 1, "Asia/FFX_VideoList.txt", "US/FFX_VideoList.txt");
    if ( std::wstring::_Equal(&config.language.video, L"jp") )
      UNX_PatchLanguageRef(
        Video,
        2,
        "/MetaMenu/GameData/PSVitaData/Video/JP/timestamp_JP.txt",
        "/MetaMenu/GameData/PSVitaData/Video/US/timestamp_%s.txt");
  }
  p_threads = &threads;
  std::deque<unsigned long>::deque<unsigned long>(&threads.c, &_Right);
  UNX_ResumeThreads(threads);
  std::deque<unsigned long>::_Tidy(&_Right);
  operator delete(_Right._Mypair._Myval2._Myproxy);
  return 1;
}


// ===== UNX_FFX2_UnitTest :: ?UNX_FFX2_UnitTest@@YAXXZ @ 0x1001dee0 (ref 0x1001dee0) =====
int UNX_FFX2_UnitTest()
{
  int i; // esi
  int result; // eax

  if ( game_type == GAME_FFX2 )
  {
    for ( i = 0; i < 3; ++i )
      result = ((int (*)(iSK_Logger *, const wchar_t *, ...))dll_log->Log)(
                 dll_log,
                 L"[UnitTest] %lu / %lu HP :: %lu / %lu MP",
                 ffx2.party[i].vitals.current.HP,
                 ffx2.party[i].vitals.max.HP,
                 ffx2.party[i].vitals.current.MP,
                 ffx2.party[i].vitals.max.MP);
  }
  return result;
}

