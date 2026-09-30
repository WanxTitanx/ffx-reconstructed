// FFX: PS3Data resolves DDS texture path by descriptor — resolves DDS texture path using descriptor info
// FFX Ps3Data: Resolve DDS texture path by descriptor
int __thiscall FFX_Ps3Data_ResolveDdsTexturePathByDescriptor(
        int this,
        unsigned __int16 n2,
        __int16 n19,
        __int16 a4,
        __int16 a5,
        __int16 n128,
        __int16 n32,
        _BYTE *RWTT)
{
  _BYTE *RWTT_1; // ebx
  int n2_3; // esi
  unsigned __int16 n2_1; // di
  __int16 n19_1; // cx
  unsigned int v12; // ecx
  char *v13; // ecx
  char v14; // al
  int n7050; // eax
  __int16 n32_1; // dx
  __int16 n19_2; // ax
  __int16 n32_2; // dx
  int n6349; // eax
  __int16 n19_3; // ax
  __int16 n19_4; // ax
  __int16 n32_3; // dx
  __int16 n19_5; // ax
  __int16 n32_4; // cx
  unsigned int CurrentMagicId; // eax
  __int16 n19_6; // dx
  int this_1; // eax
  unsigned int v29; // ecx
  _BYTE *v30; // eax
  int v31; // ecx
  unsigned int v32; // edi
  int CurrentMagicColor; // eax
  int v34; // eax
  int v35; // eax
  unsigned int n168; // eax
  unsigned int n170; // ecx
  int v38; // eax
  __int16 n14464; // ax
  _BYTE *RWTT_2; // edx
  char *v41; // ecx
  char v42; // al
  unsigned int v43; // [esp+28h] [ebp-24h]
  unsigned __int16 n2_2; // [esp+2Ch] [ebp-20h]
  char Buffer[16]; // [esp+38h] [ebp-14h] BYREF

  RWTT_1 = RWTT; /*0x660661*/
  n2_3 = 0; /*0x660667*/
  if ( *(_DWORD *)(this + 64244) != 7166 /*0x660698*/
    || !ms_effect_from_magicfile
    || FFX_Magic_GetCurrentMagicId() != 539
    || FFX_Magic_GetTextureDescriptorFlag() != 1 )
  {
    n2_1 = n2; /*0x6606af*/
    goto LABEL_8; /*0x6606af*/
  }
  n2_1 = n2; /*0x66069a*/
  n2_2 = n2; /*0x6606a2*/
  if ( n2 == 13824 ) /*0x6606a8*/
  {
    n2_1 = 13825; /*0x6606aa*/
LABEL_8:
    n2_2 = n2_1; /*0x6606b2*/
  }
  n19_1 = n19; /*0x6606b5*/
  if ( *(_WORD *)(this + 100) == n2_1 /*0x6606ee*/
    && *(_WORD *)(this + 102) == n19
    && *(_WORD *)(this + 104) == a4
    && *(_WORD *)(this + 106) == a5
    && *(_WORD *)(this + 108) == n128
    && *(_WORD *)(this + 110) == n32 )
  {
    v12 = *(unsigned __int16 *)(this + 112); /*0x6606f0*/
    if ( v12 < *(_DWORD *)(this + 52) ) /*0x6606f7*/
    {
      v13 = *(char **)(*(_DWORD *)(this + 84) + 4 * v12); /*0x6606fc*/
      do /*0x66070c*/
      {
        v14 = *v13; /*0x660700*/
        *RWTT_1++ = *v13++; /*0x660702*/
      }
      while ( v14 ); /*0x66070c*/
      return 1; /*0x660723*/
    }
    n19_1 = n19; /*0x660726*/
  }
  n7050 = *(_DWORD *)(this + 64244); /*0x66072a*/
  if ( n7050 == 7050 && n2_1 == 16128 && n19_1 == 19 ) /*0x660745*/
  {
    FFX_FileSystem_BuildDataPath( /*0x660752*/
      "/FFX_Data/GameData/PS3Data/chr/mon/m220/fp/tex/GCM/16128_0_0_8_256_128.dds.phyre",
      RWTT,
      256);
    return 1; /*0x66076f*/
  }
  if ( n7050 == 9238 && n2_1 == 15040 && n19_1 == 19 ) /*0x66078a*/
  {
    FFX_FileSystem_BuildDataPath( /*0x660797*/
      "/FFX_Data/GameData/PS3Data/map/bsyt/bsyt01/fp/tex/GCM/15040_19_0_0_256_64.dds.phyre",
      RWTT,
      256);
    return 1; /*0x6607b4*/
  }
  if ( n7050 == 7016 && n2_1 == 14272 && n19_1 == 19 ) /*0x6607d7*/
  {
    n32_1 = n32; /*0x6607dd*/
    if ( n128 == 128 && n32 == 32 ) /*0x6607e7*/
    {
      FFX_FileSystem_BuildDataPath( /*0x6607f4*/
        "/FFX_Data/GameData/PS3Data/map/hiku/hiku08/fp/tex/GCM/14272_19_0_0_128_32.dds.phyre",
        RWTT,
        256);
      return 1; /*0x660811*/
    }
  }
  else
  {
    n32_1 = n32; /*0x660814*/
  }
  if ( n7050 == 503 && n2_1 == 15040 && n19_1 == 19 ) /*0x660829*/
  {
    RWTT_1 = RWTT; /*0x660834*/
    if ( n128 == 128 && n32_1 == 128 ) /*0x66083d*/
    {
      FFX_FileSystem_BuildDataPath( /*0x66084a*/
        "/FFX_Data/GameData/PS3Data/map/sins/sins02/fp/tex/GCM/15040_19_0_0_128_128.dds.phyre",
        RWTT,
        256);
      return 1; /*0x660867*/
    }
  }
  if ( n7050 == 7016 && n2_1 == 14272 && n19_1 == 19 && n128 == 128 && n32_1 == 64 ) /*0x660890*/
  {
    FFX_FileSystem_BuildDataPath( /*0x66089d*/
      "/FFX_Data/GameData/PS3Data/map/hiku/hiku08/fp/tex/GCM/14272_19_0_0_128_64.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x6608ba*/
  }
  if ( FFX_Magic_GetCurrentMagicId() == 487 && n2_1 == 14720 && n19 == 19 ) /*0x6608db*/
  {
    FFX_FileSystem_BuildDataPath( /*0x6608e8*/
      "/FFX_Data/GameData/PS3Data/magic/magic_0487/tex/GCM/14720_19_0_0_128_128.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x660905*/
  }
  if ( FFX_Magic_GetCurrentMagicId() == 487 && n2_1 == 15040 && n19 == 19 ) /*0x660923*/
  {
    FFX_FileSystem_BuildDataPath( /*0x660930*/
      "/FFX_Data/GameData/PS3Data/magic/magic_0487/tex/GCM/15040_19_0_0_128_256.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x66094d*/
  }
  if ( FFX_Magic_GetCurrentMagicId() == 710 ) /*0x66095a*/
  {
    n19_2 = n19; /*0x660964*/
    if ( n2_1 == 14592 && n19 == 19 ) /*0x66096e*/
    {
      FFX_FileSystem_BuildDataPath( /*0x66097b*/
        "/FFX_Data/GameData/PS3Data/magic/magic_0710/tex/GCM/14592_19_0_0_128_128.dds.phyre",
        RWTT_1,
        256);
      return 1; /*0x660998*/
    }
  }
  else
  {
    n19_2 = n19; /*0x66099b*/
  }
  if ( *(_DWORD *)(this + 64244) == 6333 && n2_1 == 15040 && n19_2 == 19 ) /*0x6609bc*/
  {
    FFX_FileSystem_BuildDataPath( /*0x6609c9*/
      "/FFX_Data/GameData/PS3Data/map/bsil/bsil00/fp/tex/GCM/15040_19_0_0_128_256.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x6609e6*/
  }
  if ( FFX_Magic_GetCurrentMagicId() == 641 && n2_1 == 13824 && n19 == 19 ) /*0x660a0c*/
  {
    n32_2 = n32; /*0x660a12*/
    if ( n128 == 512 && n32 == 256 ) /*0x660a20*/
    {
      FFX_FileSystem_BuildDataPath( /*0x660a29*/
        "/FFX_Data/GameData/PS3Data/magic/magic_0641/tex/GCM/13824_19_0_0_512_256.dds.phyre",
        RWTT_1,
        256);
      return 1; /*0x660a46*/
    }
  }
  else
  {
    n32_2 = n32; /*0x660a49*/
  }
  n6349 = *(_DWORD *)(this + 64244); /*0x660a50*/
  if ( n6349 == 6349 ) /*0x660a5b*/
  {
    if ( n2_1 == 13120 && n19 == 19 ) /*0x660a72*/
    {
      RWTT_1 = RWTT; /*0x660a7d*/
      if ( n128 == 128 && n32_2 == 64 ) /*0x660a86*/
      {
        FFX_FileSystem_BuildDataPath( /*0x660a93*/
          "/FFX_Data/GameData/PS3Data/map/dome/dome06/fp/tex/GCM/13120_19_0_0_128_64.dds.phyre",
          RWTT,
          256);
        return 1; /*0x660ab0*/
      }
    }
    if ( n2_1 == 13152 && n19 == 19 ) /*0x660acb*/
    {
      RWTT_1 = RWTT; /*0x660ad6*/
      if ( n128 == 128 && n32_2 == 64 ) /*0x660adf*/
      {
        FFX_FileSystem_BuildDataPath( /*0x660aec*/
          "/FFX_Data/GameData/PS3Data/map/dome/dome06/fp/tex/GCM/13152_19_0_0_128_64.dds.phyre",
          RWTT,
          256);
        return 1; /*0x660b09*/
      }
    }
  }
  if ( n6349 == 4563 && g_saveOpCount_5 == 8 && n2_1 == 14080 && n19 == 19 && n128 == 128 && n32_2 == 128 ) /*0x660b3d*/
  {
    FFX_FileSystem_BuildDataPath( /*0x660b4a*/
      "/FFX_Data/GameData/PS3Data/map/bika/bika00/fp/tex/GCM/13920_19_0_0_128_128.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x660b67*/
  }
  if ( FFX_Magic_GetCurrentMagicId() == 343 && n2_1 == 13312 && n19 == 19 && n128 == 256 && n32 == 512 ) /*0x660b9b*/
  {
    FFX_FileSystem_BuildDataPath( /*0x660ba8*/
      "/FFX_Data/GameData/PS3Data/magic/magic_0343/tex/GCM/13312_19_0_0_256_512.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x660bc5*/
  }
  if ( FFX_Magic_GetCurrentMagicId() == 372 && n2_1 == 15040 && n19 == 19 ) /*0x660be3*/
  {
    FFX_FileSystem_BuildDataPath( /*0x660bf0*/
      "/FFX_Data/GameData/PS3Data/magic/magic_0372/tex/GCM/15040_19_0_0_128_128.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x660c0d*/
  }
  if ( FFX_Magic_GetCurrentMagicId() == 641 ) /*0x660c1e*/
  {
    n19_3 = n19; /*0x660c28*/
    if ( n2_1 == 14368 && n19 == 19 && n128 == 512 && n32 == 256 ) /*0x660c47*/
    {
      FFX_FileSystem_BuildDataPath( /*0x660c50*/
        "/FFX_Data/GameData/PS3Data/magic/magic_0641/tex/GCM/14368_19_0_0_512_256.dds.phyre",
        RWTT_1,
        256);
      return 1; /*0x660c6d*/
    }
  }
  else
  {
    n19_3 = n19; /*0x660c70*/
  }
  if ( *(_DWORD *)(this + 64244) == 9648 && n2_1 == 15040 && n19_3 == 19 && n128 == 128 && n32 == 128 ) /*0x660ca1*/
  {
    FFX_FileSystem_BuildDataPath( /*0x660cae*/
      "/FFX_Data/GameData/PS3Data/map/dome/dome07/fp/tex/GCM/15040_19_0_0_128_128.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x660ccb*/
  }
  if ( FFX_Magic_GetModuleHandle() != -1 && FFX_Magic_GetCurrentMagicId() == 561 && n2_1 == 14336 && n19 == 19 ) /*0x660cf3*/
  {
    FFX_FileSystem_BuildDataPath( /*0x660d00*/
      "/FFX_Data/GameData/PS3Data/magic/magic_0561/tex/GCM/14336_19_0_0_128_64.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x660d1d*/
  }
  if ( FFX_Magic_GetModuleHandle() != -1 /*0x660d57*/
    && FFX_Magic_GetCurrentMagicId() == 561
    && n2_1 == 14336
    && n19 == 19
    && n128 == 128
    && n32 == 64 )
  {
    FFX_FileSystem_BuildDataPath( /*0x660d64*/
      "/FFX_Data/GameData/PS3Data/magic/magic_0561/tex/GCM/14368_19_0_0_128_64.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x660d81*/
  }
  if ( FFX_Magic_GetCurrentMagicId() == 505 ) /*0x660d8e*/
  {
    n19_4 = n19; /*0x660d98*/
    if ( n2_1 == 14336 && n19 == 19 ) /*0x660da2*/
    {
      FFX_FileSystem_BuildDataPath( /*0x660daf*/
        "/FFX_Data/GameData/PS3Data/magic/magic_0505/tex/GCM/14336_19_0_0_128_256.dds.phyre",
        RWTT_1,
        256);
      return 1; /*0x660dcc*/
    }
  }
  else
  {
    n19_4 = n19; /*0x660dcf*/
  }
  if ( ms_effect_from_magicfile && *(_DWORD *)(this + 64244) == 1587 && n2_1 == 15040 && n19_4 == 19 ) /*0x660df8*/
  {
    n32_3 = n32; /*0x660e03*/
    if ( n128 == 128 && n32 == 128 ) /*0x660e0d*/
    {
      FFX_FileSystem_BuildDataPath( /*0x660e1a*/
        "/FFX_Data/GameData/PS3Data/magic/magic_0496/tex/GCM/15040_19_0_0_128_128.dds.phyre",
        RWTT_1,
        256);
      return 1; /*0x660e37*/
    }
  }
  else
  {
    n32_3 = n32; /*0x660e3a*/
  }
  if ( *(_DWORD *)(this + 64244) == 4700 && n2_1 == 13888 && n19_4 == 19 && n128 == 128 && n32_3 == 4 ) /*0x660e6c*/
  {
    FFX_FileSystem_BuildDataPath( /*0x660e79*/
      "/FFX_Data/GameData/PS3Data/map/luca/luca01/fp/tex/GCM/13888_19_0_0_128_64.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x660e96*/
  }
  if ( FFX_Magic_GetCurrentMagicId() == 165 && n2_1 == 13312 && n19 == 19 && n128 == 128 && n32 == 4 ) /*0x660ec6*/
  {
    FFX_FileSystem_BuildDataPath( /*0x660ed3*/
      "/FFX_Data/GameData/PS3Data/magic/magic_0165/tex/GCM/13312_19_0_0_128_64.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x660ef0*/
  }
  if ( FFX_Magic_GetCurrentMagicId() != 165 ) /*0x660f01*/
  {
    n19_5 = n19; /*0x660f56*/
LABEL_156:
    n32_4 = n32; /*0x660f5a*/
    goto LABEL_157; /*0x660f5a*/
  }
  n19_5 = n19; /*0x660f0b*/
  if ( n2_1 != 13344 || n19 != 19 ) /*0x660f15*/
    goto LABEL_156; /*0x660f15*/
  n32_4 = n32; /*0x660f1f*/
  if ( n128 == 128 && n32 == 4 ) /*0x660f29*/
  {
    FFX_FileSystem_BuildDataPath( /*0x660f36*/
      "/FFX_Data/GameData/PS3Data/magic/magic_0165/tex/GCM/13344_19_0_0_128_64.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x660f53*/
  }
LABEL_157:
  if ( ptr_new_for_once_0 ) /*0x660f6b*/
  {
    if ( n2_1 == 14688 ) /*0x660f7c*/
    {
      if ( n19_5 == 19 && n128 == 128 && n32_4 == 128 ) /*0x660f99*/
      {
        FFX_FileSystem_BuildDataPath( /*0x660faa*/
          "/FFX_Data/GameData/PS3Data/menu/abmap/dat00/tex/GCM/14688_19.dds.phyre",
          RWTT_1,
          256);
        return 1; /*0x660fc7*/
      }
    }
    else if ( n2_1 == 14752 ) /*0x660fce*/
    {
      if ( n19_5 == 19 && n128 == 128 && n32_4 == 4 ) /*0x660fe8*/
      {
        FFX_FileSystem_BuildDataPath( /*0x660ff5*/
          "/FFX_Data/GameData/PS3Data/menu/abmap/dat00/tex/GCM/14752_19.dds.phyre",
          RWTT_1,
          256);
        return 1; /*0x661012*/
      }
    }
    else if ( n2_1 == 14784 && n19_5 == 19 && n128 == 128 && n32_4 == 4 ) /*0x661036*/
    {
      FFX_FileSystem_BuildDataPath( /*0x661043*/
        "/FFX_Data/GameData/PS3Data/menu/abmap/dat00/tex/GCM/14784_19.dds.phyre",
        RWTT_1,
        256);
      return 1; /*0x661060*/
    }
  }
  if ( FFX_Magic_GetModuleHandle() != -1 /*0x66109e*/
    && FFX_Magic_GetCurrentMagicId() == 497
    && n2_1 == 15040
    && n19 == 19
    && n128 == 128
    && n32 == 256 )
  {
    FFX_FileSystem_BuildDataPath( /*0x6610a7*/
      "/FFX_Data/GameData/PS3Data/magic/magic_0497/tex/GCM/15040_19_0_0_128_256.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x6610c4*/
  }
  if ( FFX_Magic_GetModuleHandle() != -1 /*0x6610fe*/
    && FFX_Magic_GetCurrentMagicId() == 505
    && n2_1 == 14720
    && n19 == 19
    && n128 == 128
    && n32 == 64 )
  {
    FFX_FileSystem_BuildDataPath( /*0x66110b*/
      "/FFX_Data/GameData/PS3Data/magic/magic_0505/tex/GCM/14720_19_0_0_128_64.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x661128*/
  }
  if ( FFX_Magic_GetModuleHandle() != -1 && FFX_Magic_GetCurrentMagicId() == 432 && n2_1 == 15040 && n19 == 19 ) /*0x661150*/
  {
    FFX_FileSystem_BuildDataPath( /*0x66115d*/
      "/FFX_Data/GameData/PS3Data/magic/magic_0432/tex/GCM/15040_19_0_0_128_64.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x66117a*/
  }
  if ( FFX_Magic_GetModuleHandle() != -1 /*0x6611b4*/
    && FFX_Magic_GetCurrentMagicId() == 438
    && n2_1 == 15040
    && n19 == 19
    && n128 == 128
    && n32 == 4 )
  {
    FFX_FileSystem_BuildDataPath( /*0x6611c1*/
      "/FFX_Data/GameData/PS3Data/magic/magic_0438/tex/GCM/15040_19_0_0_128_64.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x6611de*/
  }
  if ( FFX_Magic_GetModuleHandle() != -1 /*0x661218*/
    && FFX_Magic_GetCurrentMagicId() == 437
    && n2_1 == 15040
    && n19 == 19
    && n128 == 128
    && n32 == 4 )
  {
    FFX_FileSystem_BuildDataPath( /*0x661225*/
      "/FFX_Data/GameData/PS3Data/magic/magic_0437/tex/GCM/15040_19_0_0_128_64.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x661242*/
  }
  if ( FFX_Magic_GetModuleHandle() != -1 /*0x66127c*/
    && FFX_Magic_GetCurrentMagicId() == 369
    && n2_1 == 13440
    && n19 == 19
    && n128 == 128
    && n32 == 4 )
  {
    FFX_FileSystem_BuildDataPath( /*0x661289*/
      "/FFX_Data/GameData/PS3Data/magic/magic_0369/tex/GCM/13440_19_0_0_128_64.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x6612a6*/
  }
  if ( FFX_Magic_GetModuleHandle() != -1 /*0x6612e4*/
    && FFX_Magic_GetCurrentMagicId() == 369
    && n2_1 == 13440
    && n19 == 19
    && n128 == 512
    && n32 == 256 )
  {
    FFX_FileSystem_BuildDataPath( /*0x6612ed*/
      "/FFX_Data/GameData/PS3Data/magic/magic_0369/tex/GCM/13440_19_0_0_512_256.dds.phyre",
      RWTT_1,
      256);
    return 1; /*0x66130a*/
  }
  if ( FFX_Magic_GetModuleHandle() == -1 ) /*0x661315*/
  {
    n19_6 = n19; /*0x661362*/
  }
  else
  {
    CurrentMagicId = FFX_Magic_GetCurrentMagicId(); /*0x661317*/
    n19_6 = n19; /*0x66131c*/
    if ( CurrentMagicId == 188 && n2_1 == 15040 && n19 == 19 ) /*0x661335*/
    {
      FFX_FileSystem_BuildDataPath( /*0x661342*/
        "/FFX_Data/GameData/PS3Data/magic/magic_0188/tex/GCM/15040_19_0_0_128_64.dds.phyre",
        RWTT_1,
        256);
      return 1; /*0x66135f*/
    }
  }
  this_1 = this; /*0x661366*/
  if ( *(_BYTE *)(this + 64512) ) /*0x661369*/
  {
    if ( *(_DWORD *)(this + 64612) == n2_1 ) /*0x66137e*/
    {
      strcpy(RWTT_1, "RWTT"); /*0x661385*/
      return 2; /*0x6613a4*/
    }
    this_1 = this; /*0x6613a7*/
  }
  v29 = 0; /*0x6613a9*/
  v43 = 0; /*0x6613ab*/
  if ( !*(_DWORD *)(this_1 + 52) ) /*0x6613b1*/
    return 0; /*0x661dcc*/
  while ( 1 ) /*0x6613d3*/
  {
    v30 = *(_BYTE **)(*(_DWORD *)(this_1 + 60) + 4 * v29); /*0x6613d3*/
    if ( !v30 || !*v30 ) /*0x6613de*/
      goto LABEL_524; /*0x6613e1*/
    if ( !ms_effect_from_magicfile ) /*0x6613f1*/
    {
      if ( *(_DWORD *)(*(_DWORD *)(this + 72) + 20 * v29) == 2 ) /*0x6613fd*/
        goto LABEL_524; /*0x6613fd*/
      v29 = v43; /*0x661403*/
    }
    if ( MEMORY[0xCCB9D0] && !*(_DWORD *)(*(_DWORD *)(this + 72) + 20 * v29) ) /*0x661415*/
      goto LABEL_524; /*0x661415*/
    if ( ms_effect_from_magicfile && *(_DWORD *)(*(_DWORD *)(this + 72) + 20 * v43) == 1 ) /*0x661435*/
      goto LABEL_524; /*0x661435*/
    v31 = *(_DWORD *)(this + 72); /*0x661444*/
    if ( n2_1 != *(_DWORD *)(v31 + 20 * v43 + 4) || n19_6 != *(_WORD *)(v31 + 20 * v43 + 8) ) /*0x661459*/
      goto LABEL_524; /*0x661459*/
    v32 = FFX_Magic_GetCurrentMagicId(); /*0x661464*/
    CurrentMagicColor = FFX_Magic_GetCurrentMagicColor(); /*0x661466*/
    if ( v32 != -1 && CurrentMagicColor != -1 ) /*0x661473*/
    {
      sprintf(Buffer, "%d", v32); /*0x66147f*/
      if ( !strstr(*(const char **)(*(_DWORD *)(this + 84) + 4 * v43), Buffer) ) /*0x6614a0*/
      {
        n2_1 = n2_2; /*0x6616b0*/
        n19_6 = n19; /*0x6616b3*/
        goto LABEL_524; /*0x6616b7*/
      }
    }
    if ( FFX_Magic_GetModuleHandle() == -1 ) /*0x6614ae*/
    {
      n2_1 = n2_2; /*0x6614e5*/
    }
    else
    {
      n2_1 = n2_2; /*0x6614b5*/
      if ( FFX_Magic_GetCurrentMagicId() == 673 ) /*0x6614bd*/
      {
        if ( switchTexture ) /*0x6614c6*/
        {
          if ( !n2_3 && n2_2 == 14528 ) /*0x6614d4*/
          {
            n19_6 = n19; /*0x6614d6*/
            if ( n19 == 19 ) /*0x6614de*/
              goto LABEL_523; /*0x6614de*/
          }
        }
      }
    }
    if ( FFX_Magic_GetModuleHandle() == -1 /*0x661530*/
      || FFX_Magic_GetCurrentMagicId() != 662
      || n2_1 != 12544
      || (n19_6 = n19, n19 != 19)
      || (v34 = *(_DWORD *)(this + 72), n128 == *(_WORD *)(v34 + 20 * v43 + 14))
      && n32 == *(_WORD *)(v34 + 20 * v43 + 16) )
    {
      if ( !FFX_JobSchedule_GetThreadDataDeref() /*0x66155d*/
        && FFX_Magic_GetModuleHandle() != -1
        && FFX_Magic_GetCurrentMagicId() == 662
        && n2_1 == 11776 )
      {
        FFX_FileSystem_BuildDataPath( /*0x661ddd*/
          "/FFX_Data/GameData/PS3Data/magic/magic_0662/tex/GCM/11776_19_0_0_512_512_JP.dds.phyre",
          RWTT,
          256);
        return 2; /*0x661dec*/
      }
      if ( FFX_Magic_GetModuleHandle() == -1 ) /*0x66156b*/
        break; /*0x66156b*/
      if ( FFX_Magic_GetCurrentMagicId() != 253 ) /*0x661577*/
        break; /*0x661577*/
      if ( n2_1 != 13312 ) /*0x661581*/
        break; /*0x661581*/
      n19_6 = n19; /*0x661583*/
      if ( n19 != 19 ) /*0x66158b*/
        break; /*0x66158b*/
      if ( n128 != 512 ) /*0x661596*/
        break; /*0x661596*/
      if ( n32 != 256 ) /*0x6615a1*/
        break; /*0x6615a1*/
      v35 = *(_DWORD *)(this + 72); /*0x6615ab*/
      if ( *(_WORD *)(v35 + 20 * v43 + 14) == 512 && *(_WORD *)(v35 + 20 * v43 + 16) == 256 ) /*0x6615c3*/
        break; /*0x6615c3*/
    }
LABEL_524:
    ++v43; /*0x661da8*/
    this_1 = this; /*0x661dab*/
    v29 = v43; /*0x661dae*/
    if ( v43 >= *(_DWORD *)(this + 52) ) /*0x661db4*/
      return 0; /*0x661db4*/
  }
  if ( FFX_Magic_GetModuleHandle() == -1 ) /*0x6615d1*/
    goto LABEL_300; /*0x6615d1*/
  n168 = FFX_Magic_GetCurrentMagicId(); /*0x6615d7*/
  n170 = n168; /*0x6615e2*/
  if ( (n168 == 168 || n168 == 587) /*0x661633*/
    && (switchTexture > 0 && !n2_3 && (n2_1 == 13824 || n2_1 == 13952)
     || switchTexture > 1 && !n2_3 && (n2_1 == 14080 || n2_1 == 13568)) )
  {
    goto LABEL_522; /*0x661633*/
  }
  if ( n168 == 170 || n168 == 607 ) /*0x661647*/
  {
    if ( n2_1 == 13312 && n19 == 19 ) /*0x661658*/
    {
      v38 = *(_DWORD *)(this + 72); /*0x661661*/
      n2_1 = n2_2; /*0x661669*/
      if ( n128 != *(_WORD *)(v38 + 20 * v43 + 14) ) /*0x66166c*/
        goto LABEL_360; /*0x66166c*/
      n2_1 = n2_2; /*0x66167b*/
      if ( n32 != *(_WORD *)(v38 + 20 * v43 + 16) ) /*0x66167e*/
        goto LABEL_360; /*0x66167e*/
    }
    if ( !n2_3 && n2_1 == 15040 ) /*0x661690*/
      goto LABEL_522; /*0x661690*/
    if ( n170 == 170 ) /*0x66169c*/
    {
      if ( !switchTexture || n2_3 ) /*0x6616a4*/
        goto LABEL_300; /*0x6616a4*/
      n14464 = 14464; /*0x6616a6*/
      goto LABEL_521; /*0x6616ab*/
    }
  }
  if ( n170 == 154 ) /*0x6616c2*/
  {
    if ( !switchTexture ) /*0x6616ca*/
    {
      if ( n2_3 ) /*0x6616ce*/
        goto LABEL_300; /*0x6616ce*/
      if ( n2_1 != 14144 ) /*0x6616d8*/
        goto LABEL_300; /*0x6616d8*/
      n19_6 = n19; /*0x6616da*/
      if ( n19 != 19 ) /*0x6616e2*/
        goto LABEL_300; /*0x6616e2*/
      goto LABEL_523; /*0x6616e2*/
    }
    if ( n2_3 ) /*0x66172f*/
      goto LABEL_300; /*0x66172f*/
    if ( n2_1 != 13440 && n2_1 != 14400 && n2_1 != 14464 ) /*0x661755*/
    {
      n14464 = 15104; /*0x66175b*/
      goto LABEL_521; /*0x661760*/
    }
LABEL_522:
    n19_6 = n19; /*0x661d9f*/
LABEL_523:
    n2_3 = 1; /*0x661da3*/
    goto LABEL_524; /*0x661da3*/
  }
  if ( (n170 == 162 || n170 == 586) && !n2_3 && n2_1 == 15040 /*0x6618cf*/
    || (n170 == 304 || n170 == 568)
    && (switchTexture >= 1 && !n2_3 && n2_1 == 13312
     || switchTexture >= 2 && !n2_3 && n2_1 == 14752
     || switchTexture >= 3 && !n2_3 && n2_1 == 14496)
    || (n170 == 148 || n170 == 569 || n170 == 208)
    && ((switchTexture & 1) != 0 && !n2_3 && n2_1 == 13696
     || (switchTexture & 2) != 0 && !n2_3 && n2_1 == 13504
     || (switchTexture & 4) != 0 && !n2_3 && n2_1 == 13568
     || (switchTexture & 8) != 0 && !n2_3 && n2_1 == 13632)
    || (n170 == 430 || n170 == 588) && switchTexture && !n2_3 && n2_1 == 14144
    || (n170 == 511 || n170 == 589) && switchTexture == 1 && !n2_3 && (n2_1 == 13632 || n2_1 == 13888 || n2_1 == 14400)
    || (n170 == 70 || n170 == 570) && !switchTexture && !n2_3 && n2_1 == 13312 )
  {
    goto LABEL_522; /*0x6618cf*/
  }
  switch ( n170 ) /*0x6618e1*/
  {
    case 0x133u: /*0x6618e1*/
      if ( switchTexture >= 1 && n2_3 <= 0 && n2_1 == 14848 ) /*0x6618f8*/
      {
        ++n2_3; /*0x6618fa*/
LABEL_360:
        n19_6 = n19; /*0x6618fb*/
        goto LABEL_524; /*0x6618ff*/
      }
      if ( switchTexture >= 2 && n2_3 <= 0 && n2_1 == 14336 ) /*0x661915*/
      {
        n19_6 = n19; /*0x661917*/
        ++n2_3; /*0x66191b*/
        goto LABEL_524; /*0x66191c*/
      }
      if ( switchTexture >= 4 && n2_3 <= 1 && n2_1 == 14336 ) /*0x66192e*/
      {
        n19_6 = n19; /*0x661930*/
        ++n2_3; /*0x661934*/
        goto LABEL_524; /*0x661935*/
      }
      if ( switchTexture >= 2 && n2_3 <= 0 && n2_1 == 13824 ) /*0x66194b*/
      {
        n19_6 = n19; /*0x66194d*/
        ++n2_3; /*0x661951*/
        goto LABEL_524; /*0x661952*/
      }
      if ( switchTexture >= 3 && n2_3 <= 1 && n2_1 == 13824 ) /*0x661964*/
      {
        n19_6 = n19; /*0x661966*/
        ++n2_3; /*0x66196a*/
        goto LABEL_524; /*0x66196b*/
      }
      goto LABEL_377; /*0x661964*/
    case 0x233u: /*0x6618e1*/
      if ( switchTexture >= 1 && n2_3 <= 0 && n2_1 == 14848 ) /*0x6619c6*/
      {
        n19_6 = n19; /*0x6619c8*/
        ++n2_3; /*0x6619cc*/
        goto LABEL_524; /*0x6619cd*/
      }
      if ( switchTexture == 2 ) /*0x6619d5*/
      {
        if ( n2_3 > 0 ) /*0x6619d9*/
          goto LABEL_300; /*0x6619d9*/
        if ( n2_1 == 14336 ) /*0x6619e7*/
        {
          n19_6 = n19; /*0x6619e9*/
          ++n2_3; /*0x6619ed*/
          goto LABEL_524; /*0x6619ee*/
        }
LABEL_395:
        if ( n2_3 <= 0 && n2_1 == 13824 ) /*0x661a09*/
        {
          n19_6 = n19; /*0x661a0f*/
          ++n2_3; /*0x661a13*/
          goto LABEL_524; /*0x661a14*/
        }
      }
      else if ( switchTexture >= 2 ) /*0x6619f3*/
      {
        goto LABEL_395; /*0x6619f3*/
      }
LABEL_377:
      if ( switchTexture >= 1 && n2_3 <= 0 && n2_1 == 13312 ) /*0x66197c*/
      {
        n19_6 = n19; /*0x66197e*/
        ++n2_3; /*0x661982*/
      }
      else
      {
        if ( switchTexture < 4 || n2_3 > 1 || n2_1 != 13312 ) /*0x66199d*/
          goto LABEL_300; /*0x66199d*/
        n19_6 = n19; /*0x6619a3*/
        ++n2_3; /*0x6619a7*/
      }
      goto LABEL_524; /*0x661983*/
    case 0x203u: /*0x6618e1*/
    case 0x29Bu: /*0x6618e1*/
      if ( (switchTexture & 1) != 0 && !n2_3 && n2_1 == 13952 /*0x661a6c*/
        || (switchTexture & 2) != 0 && !n2_3 && n2_1 == 14720
        || (switchTexture & 4) != 0 && !n2_3 && n2_1 == 14048 )
      {
        goto LABEL_522; /*0x661a6c*/
      }
      if ( (switchTexture & 8) != 0 && n2_3 < 2 && n2_1 == 14048 ) /*0x661a7f*/
      {
        n19_6 = n19; /*0x661a81*/
        ++n2_3; /*0x661a85*/
        goto LABEL_524; /*0x661a86*/
      }
      if ( (switchTexture & 0x10) != 0 && !n2_3 && n2_1 == 14016 ) /*0x661a9c*/
        goto LABEL_522; /*0x661a9c*/
      if ( (switchTexture & 0x20) != 0 && n2_3 < 2 && n2_1 == 14720 ) /*0x661ab2*/
      {
        n19_6 = n19; /*0x661ab4*/
        ++n2_3; /*0x661ab8*/
        goto LABEL_524; /*0x661ab9*/
      }
      if ( (switchTexture & 0x20) != 0 && !n2_3 && n2_1 == 14976 ) /*0x661ace*/
        goto LABEL_522; /*0x661ace*/
      if ( (switchTexture & 0x40) != 0 && n2_3 < 2 && n2_1 == 14976 ) /*0x661ae4*/
      {
        n19_6 = n19; /*0x661ae6*/
        ++n2_3; /*0x661aea*/
        goto LABEL_524; /*0x661aeb*/
      }
      if ( (switchTexture & 0x40) != 0 && !n2_3 && n2_1 == 13312 ) /*0x661afb*/
        goto LABEL_522; /*0x661afb*/
      break;
  }
  if ( n170 == 611 || n170 == 668 ) /*0x661b0f*/
  {
    if ( (switchTexture & 1) != 0 && !n2_3 && n2_1 == 13952 ) /*0x661b24*/
      goto LABEL_522; /*0x661b24*/
    if ( (switchTexture & 1) != 0 ) /*0x661b2c*/
    {
      if ( !n2_3 && n2_1 == 14720 ) /*0x661b36*/
        goto LABEL_522; /*0x661b36*/
      if ( (switchTexture & 1) != 0 ) /*0x661b3e*/
      {
        if ( n2_3 < 2 && n2_1 == 14048 ) /*0x661b49*/
        {
          n19_6 = n19; /*0x661b4b*/
          ++n2_3; /*0x661b4f*/
          goto LABEL_524; /*0x661b50*/
        }
        if ( (switchTexture & 1) != 0 && !n2_3 && n2_1 == 14016 ) /*0x661b65*/
          goto LABEL_522; /*0x661b65*/
      }
    }
    if ( (switchTexture & 2) != 0 && n2_3 < 2 && n2_1 == 14720 ) /*0x661b7b*/
    {
      n19_6 = n19; /*0x661b7d*/
      ++n2_3; /*0x661b81*/
      goto LABEL_524; /*0x661b82*/
    }
    if ( (switchTexture & 2) != 0 && !n2_3 && n2_1 == 14976 ) /*0x661b97*/
      goto LABEL_522; /*0x661b97*/
    if ( (switchTexture & 4) != 0 && n2_3 < 2 && n2_1 == 14976 ) /*0x661bad*/
    {
      n19_6 = n19; /*0x661baf*/
      ++n2_3; /*0x661bb3*/
      goto LABEL_524; /*0x661bb4*/
    }
    if ( (switchTexture & 4) != 0 && !n2_3 && n2_1 == 13312 ) /*0x661bc4*/
      goto LABEL_522; /*0x661bc4*/
  }
  switch ( n170 ) /*0x661bdc*/
  {
    case 0x18Du: /*0x661bdc*/
    case 0x15Fu: /*0x661bdc*/
      goto LABEL_519; /*0x661bdc*/
    case 0x207u: /*0x661bdc*/
      if ( (switchTexture & 1) != 0 && !n2_3 && n2_1 == 13312 /*0x661cbd*/
        || (switchTexture & 1) != 0
        && (!n2_3 && n2_1 == 13568
         || (switchTexture & 1) != 0
         && (!n2_3 && n2_1 == 13600
          || (switchTexture & 1) != 0
          && (!n2_3 && n2_1 == 13728
           || (switchTexture & 1) != 0 && (!n2_3 && n2_1 == 13856 || (switchTexture & 1) != 0 && !n2_3 && n2_1 == 13888))))
        || (switchTexture & 2) != 0 && !n2_3 && n2_1 == 14016
        || (switchTexture & 2) != 0
        && (!n2_3 && n2_1 == 14080
         || (switchTexture & 2) != 0 && (!n2_3 && n2_1 == 14496 || (switchTexture & 2) != 0 && !n2_3 && n2_1 == 14528)) )
      {
        goto LABEL_522; /*0x661cbd*/
      }
      if ( (switchTexture & 4) == 0 || n2_3 >= 2 || n2_1 != 13312 ) /*0x661cd0*/
      {
        if ( (switchTexture & 4) == 0 || n2_3 ) /*0x661ce6*/
          goto LABEL_300; /*0x661ce6*/
        n14464 = 14336; /*0x661cec*/
        goto LABEL_521; /*0x661cf1*/
      }
      n19_6 = n19; /*0x661cd2*/
      ++n2_3; /*0x661cd6*/
      goto LABEL_524; /*0x661cd7*/
    case 0x280u: /*0x661bdc*/
      if ( !switchTexture || n2_3 ) /*0x661d08*/
        goto LABEL_300; /*0x661d08*/
      if ( n2_1 != 13376 && n2_1 != 14720 ) /*0x661d24*/
      {
        n14464 = 14048; /*0x661d26*/
        goto LABEL_521; /*0x661d2b*/
      }
      goto LABEL_522; /*0x661d24*/
  }
  if ( n170 != 577 ) /*0x661d33*/
  {
    if ( n170 != 582 ) /*0x661d83*/
      goto LABEL_300; /*0x661d83*/
LABEL_519:
    if ( n2_3 ) /*0x661d8b*/
      goto LABEL_300; /*0x661d8b*/
    n14464 = 15040; /*0x661d91*/
LABEL_521:
    if ( n2_1 != n14464 ) /*0x661d99*/
      goto LABEL_300; /*0x661d99*/
    goto LABEL_522; /*0x661d99*/
  }
  if ( (switchTexture & 1) != 0 && !n2_3 && n2_1 == 14080 /*0x661d64*/
    || (switchTexture & 1) != 0 && !n2_3 && n2_1 == 14656
    || (switchTexture & 2) != 0 && !n2_3 && n2_1 == 13312 )
  {
    goto LABEL_522; /*0x661d64*/
  }
  if ( (switchTexture & 2) != 0 && !n2_3 ) /*0x661d70*/
  {
    n14464 = 13504; /*0x661d76*/
    goto LABEL_521; /*0x661d7b*/
  }
LABEL_300:
  RWTT_2 = RWTT; /*0x6616e8*/
  v41 = *(char **)(*(_DWORD *)(this + 84) + 4 * v43); /*0x6616f4*/
  do /*0x661703*/
  {
    v42 = *v41; /*0x6616f7*/
    *RWTT_2++ = *v41++; /*0x6616f9*/
  }
  while ( v42 ); /*0x661703*/
  *(_WORD *)(this + 100) = n2_1; /*0x661709*/
  *(_WORD *)(this + 112) = v43; /*0x66170e*/
  *(_WORD *)(this + 102) = n19; /*0x661712*/
  return 2; /*0x66070e*/
}