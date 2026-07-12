// Function: sub_880730
// Address: 0x880730
int __cdecl sub_880730(int a1, int a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // esi
  int v5; // edi
  int n7; // eax
  const char *___; // eax
  int v8; // eax
  int v9; // esi
  int n7_1; // edi
  int v11; // eax
  int v12; // eax
  int v13; // esi
  int v14; // ecx
  int v15; // esi
  int v16; // eax
  unsigned __int8 n7_2; // al
  int v18; // esi
  int v19; // esi
  int v20; // esi
  int j; // ebx
  int v22; // esi
  const char *future_error_what; // eax
  const char *v24; // eax
  const char *v25; // eax
  const char *v26; // eax
  int v27; // esi
  int v28; // edi
  int Base_1; // eax
  bool v30; // zf
  int v31; // esi
  int v32; // ebx
  int Base_2; // eax
  int v34; // esi
  int v35; // edi
  int Base_3; // eax
  int n32_1; // edi
  int v38; // esi
  int v39; // ebx
  int Base_4; // eax
  int v41; // esi
  int v42; // ebx
  int v43; // eax
  int v44; // esi
  int v45; // esi
  unsigned __int16 v46; // ax
  int v47; // esi
  void (*__imp_sprintf)(char *const, const char *const, ...); // esi
  int v49; // eax
  int v50; // edi
  int v51; // eax
  int v52; // eax
  int v53; // ebx
  int v54; // eax
  int v55; // eax
  int v56; // eax
  int v57; // eax
  int v58; // eax
  int v59; // eax
  int v60; // ebx
  int v61; // ebx
  int v62; // ebx
  int v63; // ebx
  int v64; // eax
  int v65; // eax
  int v66; // eax
  int v67; // ebx
  int v68; // ebx
  int v69; // ebx
  int v70; // ebx
  int v71; // ebx
  int v72; // ebx
  int v73; // ebx
  int v75; // [esp+8h] [ebp-464h]
  int v76; // [esp+14h] [ebp-458h] BYREF
  int (__cdecl **CoreWorkPtr)(int); // [esp+18h] [ebp-454h]
  int v78; // [esp+1Ch] [ebp-450h] BYREF
  int v79; // [esp+20h] [ebp-44Ch]
  int v80; // [esp+24h] [ebp-448h]
  int n20; // [esp+28h] [ebp-444h]
  int v82; // [esp+2Ch] [ebp-440h]
  int n32; // [esp+30h] [ebp-43Ch]
  int i; // [esp+34h] [ebp-438h]
  int Base; // [esp+38h] [ebp-434h]
  int v86; // [esp+3Ch] [ebp-430h] BYREF
  _BYTE v87[4]; // [esp+40h] [ebp-42Ch] BYREF
  _BYTE v88[4]; // [esp+44h] [ebp-428h] BYREF
  char Buffer_1[1024]; // [esp+48h] [ebp-424h] BYREF
  char Buffer[32]; // [esp+448h] [ebp-24h] BYREF

  Base = j_FFX_SceneState_GetBase();
  CoreWorkPtr = (int (__cdecl **)(int))FFX_Btl_GetCoreWorkPtr();
  v82 = a2 + 2;
  sub_88FA60(a1 + 112, a2 + 2);
  sub_88F430(unk_1328A34, 0, "IMapX:");
  sprintf(Buffer, "%d", *(unsigned __int16 *)(Base + 180));
  sub_88F430(unk_1328A34, 0, Buffer);
  sub_88FA60(a1 + 112, a2 + 15);
  sub_88F430(unk_1328A34, 0, "IMapY:");
  sprintf(Buffer, "%d", *(unsigned __int16 *)(Base + 182));
  sub_88F430(unk_1328A34, 0, Buffer);
  sub_88FA60(a1 + 112, a2 + 28);
  sub_88F430(unk_1328A34, 0, "V.Vol:");
  v2 = sub_873B30();
  sprintf(Buffer, "%d", v2);
  sub_88F430(unk_1328A34, 0, Buffer);
  sub_88FA60(a1 + 112, a2 + 41);
  sub_88F430(unk_1328A34, 0, "V.Pan:");
  v3 = sub_873B20();
  sprintf(Buffer, "%d", v3);
  sub_88F430(unk_1328A34, 0, Buffer);
  v4 = a2 + 2;
  v5 = a1 + 4;
  n32 = a1 + 4;
  v80 = sub_86AF30(0);
  sub_7853B0(&v86, v87, v88);
  for ( i = 0; i < 12; i += 4 )
  {
    sub_88FA60(v5, v4);
    sub_88F0B0(unk_1328A34, 0, *(char **)((char *)off_C5343C + i));// "1st:"
    n7 = *(_DWORD *)&v87[i - 4];
    if ( n7 <= 7 )
      ___ = (const char *)*(&off_C53728 + n7);
    else
      ___ = "---";
    sub_88F450(unk_1328A34, 0, ___);
    v4 += 13;
  }
  sub_88FA60(v5, v4);
  sub_88F430(unk_1328A34, 0, "GIL:");
  sub_88FA60(a1 + 64, v4);
  v8 = sub_784F40();
  sprintf(Buffer, "%d", v8);
  sub_88F430(unk_1328A34, 0, Buffer);
  v9 = v4 + 13;
  *(float *)&n20 = COERCE_FLOAT(sub_86BCD0());
  n7_1 = 0;
  i = 1;
  Base += 44;
  do
  {
    sub_88FA60(n32, v9);
    if ( (n20 & i) != 0 )
      sub_88F450(unk_1328A34, 0, "x");
    sub_88FA60(n32 + 10, v9);
    sub_88F450(unk_1328A34, 0, *(&off_C53728 + n7_1));
    sub_88FA60(n32 + 60, v9);
    if ( LOBYTE_w_0(n7_1) == 1 )
      sub_88F0B0(unk_1328A34, 0, "join");
    else
      sub_88F0B0(unk_1328A34, 0, "out");
    sub_88FA60(n32 + 100, v9);
    if ( FFX_Party_IsMemberActive(n7_1) == 1 )
      sub_88F0B0(unk_1328A34, 0, "join");
    else
      sub_88F0B0(unk_1328A34, 0, "out");
    sub_88FA60(n32 + 180, v9);
    sprintf(Buffer, "%d", *(_DWORD *)Base);
    sub_88F530(unk_1328A34, 0, Buffer);
    Base += 4;
    ++n7_1;
    v9 += 13;
    i = __ROL4__(i, 1);
  }
  while ( n7_1 <= 7 );
  sub_88FA60(n32, v9);
  sub_88F450(unk_1328A34, 0, "IMOVIE:");
  sub_88FA60(n32 + 60, v9);
  switch ( sub_873AB0() )
  {
    case 0:
      sub_88F450(unk_1328A34, 0, "None");
      break;
    case 1:
      sub_88F450(unk_1328A34, 0, "Wait/");
      goto LABEL_18;
    case 2:
      sub_88F450(unk_1328A34, 0, "Ready/");
      goto LABEL_18;
    case 3:
      sub_88F450(unk_1328A34, 0, "Ready2/");
      goto LABEL_18;
    case 4:
      sub_88F450(unk_1328A34, 0, "Pause/");
      goto LABEL_18;
    case 5:
      sub_88F450(unk_1328A34, 0, "Exec/");
LABEL_18:
      v11 = sub_873AC0();
      sprintf(Buffer, "%d", v11);
      sub_88F430(unk_1328A34, 0, Buffer);
      sub_88F450(unk_1328A34, 0, word_B8F87C);
      v12 = sub_873AD0();
      sprintf(Buffer, "%x", v12);
      sub_88F430(unk_1328A34, 0, Buffer);
      break;
    case 6:
      sub_88F450(unk_1328A34, 0, "Remove");
      break;
    default:
      break;
  }
  v13 = v9 + 13;
  sub_88FA60(n32, v13);
  sub_88F450(unk_1328A34, 0, &unk_B5D1A0);
  sub_88FA60(n32 + 60, v13);
  if ( (*(_BYTE *)(v80 + 2) & 0x40) != 0 )
    sub_88F430(unk_1328A34, 0, "On");
  else
    sub_88F430(unk_1328A34, 0, "Off");
  sub_88FA60(n32 + 108, v13);
  sub_88F450(unk_1328A34, 0, &unk_B5D1AC);
  if ( sub_86A770(v14) )
    sub_88F430(unk_1328A34, 0, "On");
  else
    sub_88F430(unk_1328A34, 0, "Off");
  v15 = v13 + 13;
  sub_88FA60(n32, v15);
  sub_88F450(unk_1328A34, 0, &unk_B5D1BC);
  sub_88FA60(n32 + 60, v15);
  v16 = sub_86C150();
  Base = v16 % 32;
  n20 = v16 / 32;
  i = j_FFX_SceneState_GetBase();
  if ( n20 < 20 )
  {
    if ( ((1 << Base) & *(_DWORD *)(i + 4 * n20 + 76)) != 0 )
    {
      n7_2 = *(_BYTE *)(v80 + 487);
      if ( n7_2 >= 8u )
      {
        sub_88F450(unk_1328A34, 0, &unk_B5D1D0);
      }
      else if ( n7_2 <= 7u )
      {
        sub_88F450(unk_1328A34, 0, *(&off_C53728 + n7_2));
      }
      else
      {
        sub_88F450(unk_1328A34, 0, "---");
      }
    }
    else
    {
      sub_88F450(unk_1328A34, 0, &unk_B5D1C8);
    }
  }
  v18 = v15 + 13;
  sub_88FA60(n32, v18);
  sub_88F450(unk_1328A34, 0, "SndType");
  sub_88FA60(n32 + 60, v18);
  if ( sub_8863A0() == 1 )
    sub_88F450(unk_1328A34, 0, "ADPCM");
  else
    sub_88F450(unk_1328A34, 0, "PCM");
  v19 = v18 + 13;
  sub_88FA60(n32, v19);
  sub_88F450(unk_1328A34, 0, &unk_B5D1EC);
  sub_88FA60(n32 + 60, v19);
  if ( FFX_SceneState_GetBase_w() )
    sub_88F450(unk_1328A34, 0, &unk_B5CA64);
  else
    sub_88F450(unk_1328A34, 0, &unk_B5D1F8);
  v20 = v19 + 13;
  sub_88FA60(n32, v20);
  sub_88F450(unk_1328A34, 0, "EffFlag");
  sub_88FA60(n32 + 60, v20);
  for ( j = 0; j < 32; ++j )
  {
    if ( sub_86AFC0(j) )
      sub_88F450(unk_1328A34, 0, "O");
    else
      sub_88F450(unk_1328A34, 0, "X");
  }
  v22 = v20 + 13;
  sub_88FA60(n32, v22);
  sub_88F450(unk_1328A34, 0, "EffPm[0]");
  sub_88FA60(n32 + 60, v22);
  future_error_what = std::_Get_future_error_what(0);
  sprintf(Buffer, "%d", future_error_what);
  sub_88F0B0(unk_1328A34, 0, Buffer);
  v79 = n32 + 200;
  sub_88FA60(n32 + 200, v22);
  sub_88F450(unk_1328A34, 0, "EffPm[1]");
  sub_88FA60(n32 + 260, v22);
  v24 = std::_Get_future_error_what(1);
  sprintf(Buffer, "%d", v24);
  sub_88F0B0(unk_1328A34, 0, Buffer);
  v22 += 13;
  sub_88FA60(n32, v22);
  sub_88F450(unk_1328A34, 0, "EffPm[2]");
  sub_88FA60(n32 + 60, v22);
  v25 = std::_Get_future_error_what(2);
  sprintf(Buffer, "%d", v25);
  sub_88F0B0(unk_1328A34, 0, Buffer);
  sub_88FA60(n32 + 200, v22);
  sub_88F450(unk_1328A34, 0, "EffPm[3]");
  sub_88FA60(n32 + 260, v22);
  v26 = std::_Get_future_error_what(3);
  sprintf(Buffer, "%d", v26);
  sub_88F0B0(unk_1328A34, 0, Buffer);
  v27 = v22 + 13;
  sub_88FA60(n32, v27);
  sub_88F450(unk_1328A34, 0, "FootMsk");
  sub_88FA60(n32 + 60, v27);
  v28 = sub_886130();
  Base_1 = 1;
  Base = 1;
  i = 32;
  do
  {
    if ( (Base_1 & v28) != 0 )
      sub_88F450(unk_1328A34, 0, "O");
    else
      sub_88F450(unk_1328A34, 0, "X");
    Base_1 = __ROL4__(Base, 1);
    v30 = i-- == 1;
    Base = Base_1;
  }
  while ( !v30 );
  v31 = v27 + 13;
  sub_88FA60(n32, v31);
  sub_88F450(unk_1328A34, 0, "Foot3d");
  sub_88FA60(n32 + 60, v31);
  v32 = sub_886090();
  Base_2 = 1;
  Base = 1;
  i = 32;
  do
  {
    if ( (Base_2 & v32) != 0 )
      sub_88F450(unk_1328A34, 0, "O");
    else
      sub_88F450(unk_1328A34, 0, "X");
    Base_2 = __ROL4__(Base, 1);
    v30 = i-- == 1;
    Base = Base_2;
  }
  while ( !v30 );
  v34 = v31 + 13;
  sub_88FA60(n32, v34);
  sub_88F450(unk_1328A34, 0, "KinuMsk");
  sub_88FA60(n32 + 60, v34);
  v35 = sub_886310();
  Base_3 = 1;
  Base = 1;
  i = 32;
  do
  {
    if ( (Base_3 & v35) != 0 )
      sub_88F450(unk_1328A34, 0, "O");
    else
      sub_88F450(unk_1328A34, 0, "X");
    Base_3 = __ROL4__(Base, 1);
    v30 = i-- == 1;
    Base = Base_3;
  }
  while ( !v30 );
  n32_1 = n32;
  v38 = v34 + 13;
  sub_88FA60(n32, v38);
  sub_88F450(unk_1328A34, 0, "EvSndMsk");
  sub_88FA60(n32 + 60, v38);
  v39 = sub_886080();
  Base_4 = 1;
  Base = 1;
  n32 = 32;
  do
  {
    if ( (Base_4 & v39) != 0 )
      sub_88F450(unk_1328A34, 0, "O");
    else
      sub_88F450(unk_1328A34, 0, "X");
    Base_4 = __ROL4__(Base, 1);
    v30 = n32-- == 1;
    Base = Base_4;
  }
  while ( !v30 );
  v41 = v38 + 13;
  sub_88FA60(n32_1, v41);
  sub_88F450(unk_1328A34, 0, "FootSep");
  sub_88FA60(n32_1 + 60, v41);
  v42 = v82;
  if ( sub_887A30() )
    sub_88F450(unk_1328A34, 0, "Kick!!!");
  sub_88FA60(n32_1 + 200, v41);
  sub_88F450(unk_1328A34, 0, "FootId");
  sub_88FA60(n32_1 + 260, v41);
  v43 = sub_887A40();
  sprintf(Buffer, "%d", v43);
  sub_88F0B0(unk_1328A34, 0, Buffer);
  v44 = v41 + 13;
  sub_875D90(&v78, &v76);
  sub_88FA60(n32_1, v44);
  sub_88F450(unk_1328A34, 0, "ActHigh");
  sub_88FA60(n32_1 + 60, v44);
  if ( sub_888B10(0, 0) )
  {
    sprintf(Buffer, "%d", v78);
    sub_88F0B0(unk_1328A34, 0, Buffer);
  }
  else
  {
    sub_88F430(unk_1328A34, 0, "Off");
  }
  sub_88FA60(n32_1 + 200, v44);
  sub_88F450(unk_1328A34, 0, "ActLow");
  sub_88FA60(n32_1 + 260, v44);
  if ( sub_888B10(0, 0) )
  {
    sprintf(Buffer, "%d", v76);
    sub_88F0B0(unk_1328A34, 0, Buffer);
  }
  else
  {
    sub_88F430(unk_1328A34, 0, "Off");
  }
  v45 = v44 + 13;
  sub_88FA60(n32_1, v45);
  sub_88F450(unk_1328A34, 0, "HalfTurn");
  sub_88FA60(n32_1 + 60, v45);
  *(float *)&n20 = sub_873A70();
  sprintf(Buffer, "%f", *(float *)&n20);
  sub_88F430(unk_1328A34, 0, Buffer);
  sub_88FA60(n32_1 + 200, v45);
  sub_88F450(unk_1328A34, 0, "Sphere M.");
  sub_88FA60(n32_1 + 260, v45);
  v46 = sub_86C440();
  sprintf(Buffer, "%d", v46);
  sub_88F430(unk_1328A34, 0, Buffer);
  v47 = v45 + 13;
  sub_88FA60(n32_1, v47);
  sub_88F450(unk_1328A34, 0, "SndSort");
  sub_88FA60(n32_1 + 60, v47);
  if ( sub_8863B0() )
    sub_88F430(unk_1328A34, 0, "Off");
  else
    sub_88F430(unk_1328A34, 0, "On");
  sub_88FA60(n32_1, v47 + 13);
  sub_88F450(unk_1328A34, 0, "ForceBMap");
  if ( sub_86B650() >= 0 )
  {
    v49 = sub_86B650();
    __imp_sprintf = (void (*)(char *const, const char *const, ...))sprintf;
    sprintf(Buffer_1, &Format_, v49);
    sub_88F450(unk_1328A34, 0, Buffer_1);
  }
  else
  {
    sub_88F450(unk_1328A34, 0, &unk_B5D2B0);
    __imp_sprintf = (void (*)(char *const, const char *const, ...))sprintf;
  }
  v50 = v79;
  sub_88FA60(v79, v42);
  sub_88F450(unk_1328A34, 0, "NowEv.");
  sub_88FA60(v50 + 60, v42);
  v51 = sub_86C150();
  __imp_sprintf(Buffer, "%d", v51);
  sub_88F0B0(unk_1328A34, 0, Buffer);
  sub_88F450(unk_1328A34, 0, word_B8F87C);
  v52 = sub_86C160();
  __imp_sprintf(Buffer, "%d", v52);
  sub_88F0B0(unk_1328A34, 0, Buffer);
  v53 = v42 + 13;
  sub_88FA60(v50, v53);
  sub_88F450(unk_1328A34, 0, "LastEv.");
  sub_88FA60(v50 + 60, v53);
  v54 = sub_86BC00();
  __imp_sprintf(Buffer, "%d", v54);
  sub_88F0B0(unk_1328A34, 0, Buffer);
  sub_88F450(unk_1328A34, 0, word_B8F87C);
  v55 = sub_86BC10();
  __imp_sprintf(Buffer, "%d", v55);
  sub_88F0B0(unk_1328A34, 0, Buffer);
  v53 += 13;
  sub_88FA60(v50, v53);
  sub_88F450(unk_1328A34, 0, "NowMap");
  sub_88FA60(v50 + 60, v53);
  v56 = FFX_BtlTick_BattleEndCleanupLate();
  __imp_sprintf(Buffer, "%d", v56);
  sub_88F0B0(unk_1328A34, 0, Buffer);
  sub_88F450(unk_1328A34, 0, word_B8F87C);
  v57 = sub_86C170();
  __imp_sprintf(Buffer, "%d", v57);
  sub_88F0B0(unk_1328A34, 0, Buffer);
  v53 += 13;
  sub_88FA60(v50, v53);
  sub_88F450(unk_1328A34, 0, "LastMap");
  sub_88FA60(v50 + 60, v53);
  v58 = sub_86BC30();
  __imp_sprintf(Buffer, "%d", v58);
  sub_88F0B0(unk_1328A34, 0, Buffer);
  sub_88F450(unk_1328A34, 0, word_B8F87C);
  v59 = sub_86BC20();
  __imp_sprintf(Buffer, "%d", v59);
  sub_88F0B0(unk_1328A34, 0, Buffer);
  v60 = v53 + 13;
  if ( *(_DWORD *)(v80 + 72) )
  {
    sub_88FA60(v50, v60);
    sub_88F450(unk_1328A34, 0, "AutoMus.");
    sub_88FA60(v50 + 60, v60);
    Base = sub_86ABA0(*(_DWORD *)(v80 + 72));
    if ( Base >= 0 )
      sub_88F450(unk_1328A34, 0, "Off");
    else
      sub_88F450(unk_1328A34, 0, "On");
    v79 = HIWORD(Base) & 0x7FFF;
    Base = (unsigned __int16)Base;
    sub_88F450(unk_1328A34, 0, word_B8F87C);
    if ( (unsigned int)Base >= 0x100 )
    {
      sub_88F450(unk_1328A34, 0, "Stop");
    }
    else
    {
      __imp_sprintf(Buffer, "%d", Base);
      sub_88F0B0(unk_1328A34, 0, Buffer);
    }
    sub_88F450(unk_1328A34, 0, word_B8F87C);
    __imp_sprintf(Buffer, "%d", v79);
    sub_88F0B0(unk_1328A34, 0, Buffer);
  }
  v61 = v60 + 13;
  sub_88FA60(v50, v61);
  sub_88F450(unk_1328A34, 0, "NewGame");
  sub_88FA60(v50 + 60, v61);
  if ( sub_88D540() )
    sub_88F450(unk_1328A34, 0, "TRUE");
  else
    sub_88F450(unk_1328A34, 0, "FALSE");
  v62 = v61 + 13;
  sub_88FA60(v50, v62);
  sub_88F450(unk_1328A34, 0, "PushMem");
  sub_88FA60(v50 + 60, v62);
  if ( sub_86D960() )
    sub_88F450(unk_1328A34, 0, "exist");
  else
    sub_88F450(unk_1328A34, 0, "empty");
  v63 = v62 + 13;
  sub_88FA60(v50, v63);
  sub_88F450(unk_1328A34, 0, "Sc.Flag");
  sub_88FA60(v50 + 60, v63);
  v64 = sub_86C400();
  __imp_sprintf(Buffer, "%d", v64);
  sub_88F430(unk_1328A34, 0, Buffer);
  v63 += 13;
  sub_88FA60(v50, v63);
  sub_88F450(unk_1328A34, 0, "PlayMusic");
  sub_88FA60(v50 + 60, v63);
  v65 = FFX_BtlMenu_PostBattle_FadeTransitionSetup();
  __imp_sprintf(Buffer, "%d", v65);
  sub_88F0B0(unk_1328A34, 0, Buffer);
  v63 += 13;
  sub_88FA60(v50, v63);
  sub_88F450(unk_1328A34, 0, "ATELPlay");
  sub_88FA60(v50 + 60, v63);
  v66 = sub_873AA0();
  __imp_sprintf(Buffer, "%d", v66);
  sub_88F0B0(unk_1328A34, 0, Buffer);
  v67 = v63 + 13;
  sub_88FA60(v50, v67);
  sub_88F450(unk_1328A34, 0, "SndRead");
  sub_88FA60(v50 + 60, v67);
  if ( j_FFX_BtlMenu_PostBattle_WaitResourceDecompress(v75) )
    sub_88F450(unk_1328A34, 0, "Read");
  else
    sub_88F450(unk_1328A34, 0, "Free");
  v68 = v67 + 13;
  sub_88FA60(v50, v68);
  sub_88F450(unk_1328A34, 0, "SndVoice");
  sub_88FA60(v50 + 60, v68);
  if ( sub_887A80() )
    sub_88F450(unk_1328A34, 0, "Read");
  else
    sub_88F450(unk_1328A34, 0, "Free");
  v69 = v68 + 13;
  sub_88FA60(v50, v69);
  sub_88F450(unk_1328A34, 0, "ShoutV.");
  sub_88FA60(v50 + 60, v69);
  if ( sub_887A60() )
    sub_88F450(unk_1328A34, 0, "Read");
  else
    sub_88F450(unk_1328A34, 0, "Free");
  v70 = v69 + 13;
  sub_88FA60(v50, v70);
  sub_88F450(unk_1328A34, 0, "VagV.");
  sub_88FA60(v50 + 60, v70);
  if ( sub_887A70() )
    sub_88F450(unk_1328A34, 0, "Read");
  else
    sub_88F450(unk_1328A34, 0, "Free");
  v71 = v70 + 13;
  sub_88FA60(v50, v71);
  sub_88F450(unk_1328A34, 0, "V.Stndby");
  sub_88FA60(v50 + 60, v71);
  if ( sub_887A90() )
    sub_88F450(unk_1328A34, 0, "Read");
  else
    sub_88F450(unk_1328A34, 0, "Free");
  v72 = v71 + 13;
  sub_88FA60(v50, v72);
  sub_88F450(unk_1328A34, 0, "FileRead");
  sub_88FA60(v50 + 60, v72);
  if ( CoreWorkPtr[2](1) )
    sub_88F450(unk_1328A34, 0, "Read");
  else
    sub_88F450(unk_1328A34, 0, "Free");
  v73 = v72 + 13;
  sub_88FA60(v50, v73);
  sub_88F450(unk_1328A34, 0, "bindp3");
  sub_88FA60(v50 + 60, v73);
  if ( sub_86AD70() )
    return sub_88F450(unk_1328A34, 0, "Wait");
  else
    return sub_88F450(unk_1328A34, 0, "Free");
}
