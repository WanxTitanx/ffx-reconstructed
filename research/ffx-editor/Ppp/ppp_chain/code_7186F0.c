// FFX: MagicHost allocs VFX particle slots — allocates VFX particle slots
// FFX MagicHost: Alloc VFX particle slots
// VFX particle slot allocator. Allocates particle slots for PPP bytecode-driven particle effects. Uses FFX_VFXShaderProperty bitmask flags to select shader variant. Manages particle pool, texture bindings, and render state.
int __cdecl FFX_MagicHost_AllocVfxParticleSlots(__int64 a1, int a2, int a3)
{
  int v3; // edi
  int DataPtr; // esi
  int n40000_3; // eax
  int v7; // ecx
  int host_11; // ebx
  int n2; // eax
  int n40000; // eax
  int v11; // eax
  int v12; // eax
  int n14208_1; // edx
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int n14208_2; // edx
  int v18; // eax
  double v19; // st7
  double v20; // st7
  void *hudContext; // edx
  double v22; // st7
  int *charId; // ecx
  _BYTE *v24; // eax
  int v25; // ecx
  int v26; // eax
  int v27; // ecx
  int i; // esi
  int v29; // esi
  double v30; // st7
  int host_22; // ebx
  int n40000_1; // ecx
  int v33; // edi
  int host_23; // ebx
  int j; // esi
  int host_1; // ecx
  int host_24; // esi
  int v38; // eax
  int v39; // edx
  const void *src; // esi
  bool v41; // zf
  int host_25; // ecx
  int host_17; // eax
  int v44; // edx
  int v45; // edi
  int n3240; // esi
  int n4; // ecx
  int v48; // eax
  int v49; // ecx
  int v50; // eax
  int host_18; // ecx
  bool v52; // cf
  int v53; // eax
  int host_19; // eax
  int v55; // eax
  int v56; // eax
  int v57; // ecx
  int v58; // eax
  int v59; // eax
  int host_3; // eax
  int v61; // eax
  int n4_1; // ecx
  int v63; // eax
  int v64; // ecx
  int v65; // eax
  int host_20; // ecx
  int v67; // eax
  int host_21; // eax
  int v69; // eax
  int host_5; // eax
  FFXMagicHost *host_4; // ecx
  int v72; // eax
  int v73; // ecx
  int v74; // eax
  int host_6; // ecx
  int v76; // eax
  int host_7; // eax
  int v78; // eax
  int v79; // eax
  int v80; // eax
  int host_9; // eax
  FFXMagicHost *host_8; // ecx
  int v83; // eax
  int v84; // ecx
  int host_12; // ecx
  int v86; // eax
  int host_13; // eax
  int v88; // eax
  int v89; // [esp+0h] [ebp-10Ch]
  int v90; // [esp+10h] [ebp-FCh]
  int host_14; // [esp+18h] [ebp-F4h]
  int v92; // [esp+1Ch] [ebp-F0h]
  FFXMagicHost *host[4]; // [esp+20h] [ebp-ECh]
  int v94; // [esp+30h] [ebp-DCh]
  int v95; // [esp+34h] [ebp-D8h]
  int v96; // [esp+38h] [ebp-D4h]
  int v97; // [esp+3Ch] [ebp-D0h]
  int v98; // [esp+40h] [ebp-CCh]
  double v99; // [esp+44h] [ebp-C8h]
  int v100; // [esp+4Ch] [ebp-C0h]
  int n2_1; // [esp+50h] [ebp-BCh]
  int n40000_2; // [esp+54h] [ebp-B8h]
  int host_16; // [esp+58h] [ebp-B4h]
  int n14208; // [esp+5Ch] [ebp-B0h]
  double host_15; // [esp+60h] [ebp-ACh]
  int DataPtr_1; // [esp+68h] [ebp-A4h]
  int host_10; // [esp+6Ch] [ebp-A0h]
  int v108; // [esp+70h] [ebp-9Ch]
  int host_2; // [esp+74h] [ebp-98h]
  float v110[16]; // [esp+78h] [ebp-94h] BYREF
  int dst[16]; // [esp+B8h] [ebp-54h] BYREF
  float v112; // [esp+F8h] [ebp-14h]
  float v113; // [esp+FCh] [ebp-10h]
  float v114; // [esp+100h] [ebp-Ch]
  float v115; // [esp+104h] [ebp-8h]

  v112 = 1.0; /*0x718709*/
  v113 = 1.0; /*0x71870f*/
  v114 = 1.0; /*0x718713*/
  v115 = 1.0; /*0x718719*/
  v3 = a3; /*0x71871d*/
  v89 = *(_DWORD *)(a2 + 28); /*0x718720*/
  host_16 = HIDWORD(a1); /*0x718729*/
  v100 = a1; /*0x718729*/
  v98 = a3; /*0x718735*/
  v92 = 0; /*0x71873b*/
  host_2 = 0; /*0x718745*/
  n40000_2 = Std_IdentityFunc(v89); /*0x71875e*/
  if ( *(_DWORD *)&byte_11333C4[1868748] ) /*0x718764*/
    return 1; /*0x71979f*/
  v94 = FFX_TextureSlot_FindOrCacheByKeyProxy(a1); /*0x718772*/
  DataPtr = FFX_TextureSlot_GetDataPtr(v94); /*0x71877d*/
  DataPtr_1 = DataPtr; /*0x718782*/
  if ( !DataPtr ) /*0x71878a*/
    return 0; /*0x71878a*/
  n40000_3 = n40000_2; /*0x71879f*/
  *(_BYTE *)(DataPtr + 193) = 1; /*0x7187a5*/
  v7 = *(__int16 *)(n40000_3 + 16); /*0x7187af*/
  host_11 = n40000_3 + *(_DWORD *)(n40000_3 + 4); /*0x7187b3*/
  n2 = *(char *)(DataPtr + 192); /*0x7187b5*/
  v108 = v7; /*0x7187bc*/
  host_14 = host_11; /*0x7187c2*/
  n2_1 = n2; /*0x7187c8*/
  if ( n2 == 1 ) /*0x7187d1*/
  {
    n40000 = 0; /*0x7187d7*/
    host_10 = 0; /*0x7187d9*/
    n14208 = 0; /*0x7187df*/
    do /*0x71885e*/
    {
      v11 = FFX_TextureSlot_FindOrCacheByKeyProxy(__PAIR64__(host_16, v100) + n40000); /*0x7187ff*/
      *(int *)((char *)&v94 + n14208) = v11; /*0x71880b*/
      v12 = FFX_TextureSlot_GetDataPtr(v11); /*0x718812*/
      n14208_1 = n14208; /*0x718817*/
      *(FFXMagicHost **)((char *)host + n14208) = (FFXMagicHost *)v12; /*0x718820*/
      if ( !v12 ) /*0x718829*/
        return 0; /*0x718829*/
      *(_BYTE *)(v12 + 193) = 1; /*0x71882f*/
      *(_BYTE *)(v12 + 182) = *(_BYTE *)(a3 + 68); /*0x718839*/
      n40000 = host_10 + 10000; /*0x718845*/
      host_10 = n40000; /*0x71884d*/
      n14208 = n14208_1 + 4; /*0x718853*/
    }
    while ( n40000 < 40000 ); /*0x71885e*/
  }
  else if ( n2 == 2 ) /*0x718868*/
  {
    n14208 = 0; /*0x718870*/
    if ( *(_WORD *)(DataPtr + 196) ) /*0x71887a*/
    {
      v14 = 0; /*0x718887*/
      host_10 = 0; /*0x718889*/
      do /*0x718903*/
      {
        v15 = FFX_TextureSlot_FindOrCacheByKeyProxy(__PAIR64__(host_16, v100) + v14); /*0x7188a1*/
        *(&v94 + n14208) = v15; /*0x7188ad*/
        v16 = FFX_TextureSlot_GetDataPtr(v15); /*0x7188b4*/
        n14208_2 = n14208; /*0x7188b9*/
        host[n14208] = (FFXMagicHost *)v16; /*0x7188c2*/
        if ( !v16 ) /*0x7188cb*/
          return 0; /*0x7188cb*/
        *(_BYTE *)(v16 + 193) = 1; /*0x7188d1*/
        *(_BYTE *)(v16 + 182) = *(_BYTE *)(a3 + 68); /*0x7188db*/
        v18 = *(unsigned __int16 *)(DataPtr + 196); /*0x7188e7*/
        v14 = host_10 + 10000; /*0x7188ef*/
        n14208 = n14208_2 + 1; /*0x7188f5*/
        host_10 += 10000; /*0x7188fb*/
      }
      while ( n14208_2 + 1 < v18 ); /*0x718903*/
    }
  }
  else
  {
    *(_BYTE *)(DataPtr + 182) = *(_BYTE *)(a3 + 68); /*0x71890a*/
  }
  host_10 = host_11 + 16; /*0x718913*/
  n14208 = *(_DWORD *)(host_11 + 8) & 0x3FFF; /*0x718921*/
  if ( FFX_Magic_GetCurrentMagicId() == 374 && (n14208 == 14208 || n14208 == 14336 || n14208 == 14464) ) /*0x71894c*/
  {
    *(_WORD *)(a3 + 25) = 12336; /*0x71894e*/
    *(_BYTE *)(a3 + 24) = 48; /*0x718954*/
  }
  v19 = 512.0; /*0x71895d*/
  if ( FFX_Magic_GetCurrentMagicId() != 102 ) /*0x718966*/
  {
    if ( FFX_Magic_GetCurrentMagicId() != 103 ) /*0x718972*/
    {
LABEL_25:
      v19 = 256.0; /*0x718988*/
      goto LABEL_26; /*0x718988*/
    }
    v19 = 512.0; /*0x718974*/
  }
  if ( n14208 != 13312 ) /*0x718984*/
    goto LABEL_25; /*0x718984*/
LABEL_26:
  flt_C3A4C8 = v19; /*0x71898e*/
  if ( FFX_Magic_GetCurrentMagicId() == 515 && !n14208 && *(_BYTE *)(a3 + 8) == 72 && MEMORY[0x230FD20] == 11 ) /*0x7189b6*/
  {
    if ( n31 == 31 ) /*0x7189bf*/
      v20 = 512.0; /*0x7189c1*/
    else
      v20 = 256.0; /*0x7189c9*/
    flt_C3A4C8 = v20; /*0x7189cf*/
  }
  if ( FFX_Magic_GetCurrentMagicId() == 667 && !n14208 && *(_BYTE *)(a3 + 8) == 72 && MEMORY[0x230FD20] == 11 ) /*0x7189f7*/
  {
    if ( n31 == 31 ) /*0x718a00*/
      v22 = 512.0; /*0x718a02*/
    else
      v22 = 256.0; /*0x718a0a*/
    flt_C3A4C8 = v22; /*0x718a10*/
  }
  flt_C3A48C = 0.0078125 / flt_C3A4C8; /*0x718a22*/
  if ( a3 ) /*0x718a2a*/
  {
    host_2 = *(unsigned __int8 *)(a3 + 24); /*0x718a34*/
    charId = &dword_B43674; /*0x718a3a*/
    host_15 = (double)host_2; /*0x718a45*/
    host_2 = *(unsigned __int8 *)(a3 + 25); /*0x718a58*/
    v112 = host_15 * v112; /*0x718a5e*/
    host_15 = (double)host_2; /*0x718a67*/
    host_2 = *(unsigned __int8 *)(a3 + 26); /*0x718a7a*/
    v113 = host_15 * v113; /*0x718a80*/
    host_15 = (double)host_2; /*0x718a89*/
    host_2 = *(unsigned __int8 *)(a3 + 27); /*0x718a9c*/
    v114 = host_15 * v114; /*0x718aa2*/
    host_15 = (double)host_2; /*0x718aab*/
    v115 = host_15 * v115; /*0x718aba*/
    v24 = *(_BYTE **)(*(_DWORD *)(DataPtr + 148) + 32); /*0x718ac3*/
    do /*0x718ae0*/
    {
      LOBYTE(hudContext) = *v24; /*0x718ac6*/
      if ( *v24 != *(_BYTE *)charId ) /*0x718aca*/
        break; /*0x718aca*/
      if ( !(_BYTE)hudContext ) /*0x718ace*/
        break; /*0x718ace*/
      LOBYTE(hudContext) = v24[1]; /*0x718ad0*/
      if ( (_BYTE)hudContext != *((_BYTE *)charId + 1) ) /*0x718ad6*/
        break; /*0x718ad6*/
      v24 += 2; /*0x718ad8*/
      charId = (int *)((char *)charId + 2); /*0x718adb*/
    }
    while ( (_BYTE)hudContext ); /*0x718ae0*/
    FFX_BtlUI_HudParty_GetTarget((FFX_CharacterId)charId, hudContext); /*0x718b0b*/
    v92 = *(_DWORD *)(a3 + 16); /*0x718b13*/
    host_2 = *(_DWORD *)(a3 + 20); /*0x718b1f*/
  }
  v25 = *(_DWORD *)(a3 + 56); /*0x718b25*/
  v26 = *(_DWORD *)(a3 + 60); /*0x718b28*/
  v90 = v25; /*0x718b31*/
  HIDWORD(host_15) = v26; /*0x718b37*/
  if ( !v25 ) /*0x718b3f*/
    v25 = n40000_2 + *(_DWORD *)(n40000_2 + 8); /*0x718b44*/
  if ( !v26 ) /*0x718b48*/
    v26 = n40000_2 + *(_DWORD *)(n40000_2 + 12); /*0x718b4d*/
  *(_DWORD *)(a3 + 56) = v25; /*0x718b4f*/
  *(_DWORD *)(a3 + 60) = v26; /*0x718b52*/
  v27 = FFX_Render_Return0(); /*0x718b62*/
  if ( v27 && *(_DWORD *)(v27 + 8) != n40000_2 ) /*0x718b74*/
  {
    FFX_MagicHost_FreeResourceByIndex(*(_WORD *)(DataPtr + 194)); /*0x718b7e*/
    *(_WORD *)(DataPtr + 194) = FFX_Render_Return65535(); /*0x718b91*/
  }
  if ( (*(_BYTE *)a3 & 0x40) != 0 && FFX_Magic_GetCurrentMagicId() == 519 ) /*0x718bab*/
  {
    qmemcpy(dst, *(const void **)(a3 + 40), sizeof(dst)); /*0x718bbc*/
    v3 = v98; /*0x718bbe*/
    FFX_BtlUI_HudParty_ApplyStatus(v110, *(float **)(v98 + 44)); /*0x718bce*/
    for ( i = 0; i < 16; v110[i + 15] = *(float *)(*(_DWORD *)(v3 + 40) + i * 4 - 4) ) /*0x718bd6*/
    {
      *(float *)&dst[i + 3] = 1.0; /*0x718bdf*/
      FFX_MagicHost_CopySmallTransformVec4_structural(&dst[i], (int)v110, (int)&dst[i]); /*0x718beb*/
      i += 4; /*0x718bf3*/
    }
    v29 = v100; /*0x718c0d*/
    if ( n2_1 ) /*0x718c13*/
    {
      v30 = 255.0; /*0x718c19*/
      host_22 = host_16; /*0x718c1f*/
      n40000_1 = 0; /*0x718c25*/
      n40000_2 = 0; /*0x718c27*/
      do /*0x718c8f*/
      {
        HIDWORD(v99) = *(unsigned __int8 *)(v3 + 77); /*0x718c31*/
        v99 = (double)SHIDWORD(v99); /*0x718c41*/
        *((float *)&v99 + 1) = v99 / v30; /*0x718c4d*/
        FFX_Material_SetLightMatricesByTextureKey( /*0x718c69*/
          __PAIR64__(host_22, v29) + n40000_1,
          dst,
          *(void **)(v3 + 36),
          *((float *)&v99 + 1));
        v30 = 255.0; /*0x718c74*/
        n40000_1 = n40000_2 + 10000; /*0x718c7a*/
        n40000_2 = n40000_1; /*0x718c83*/
      }
      while ( n40000_1 < 40000 ); /*0x718c8f*/
      host_11 = host_14; /*0x718c91*/
    }
    else
    {
      HIDWORD(v99) = *(unsigned __int8 *)(v3 + 77); /*0x718c9f*/
      v99 = (double)SHIDWORD(v99); /*0x718caf*/
      *((float *)&v99 + 1) = v99 / 255.0; /*0x718cc1*/
      FFX_Material_SetLightMatricesByTextureKey( /*0x718cdb*/
        __SPAIR64__(host_16, v100),
        dst,
        *(void **)(v3 + 36),
        *((float *)&v99 + 1));
    }
  }
  else
  {
    v29 = v100; /*0x718ce5*/
  }
  if ( g_saveOpCount_5 != -1 && *(_DWORD *)&byte_11333C4[1869876] == 392 ) /*0x718cfe*/
  {
    if ( n2_1 ) /*0x718d07*/
    {
      v33 = v100; /*0x718d09*/
      host_23 = host_16; /*0x718d0f*/
      for ( j = 0; j < 40000; j += 10000 ) /*0x718d15*/
        FFX_TextureSlot_FindOrCacheAndShiftYIQ(__PAIR64__(host_23, v33) + j); /*0x718d20*/
      host_11 = host_14; /*0x718d36*/
      v3 = v98; /*0x718d3c*/
    }
    else
    {
      FFX_TextureSlot_FindOrCacheAndShiftYIQ(__SPAIR64__(host_16, v29)); /*0x718d4b*/
    }
  }
  if ( Phyre_Global_CD4B68_CheckNonNull() ) /*0x718d53*/
  {
    host_24 = FFX_MagicHost_AllocPppDrawRecord(v108); /*0x718d6b*/
    host_16 = host_24; /*0x718d6d*/
    *(_BYTE *)host_24 = 0; /*0x718d73*/
    *(_DWORD *)(host_24 + 264) = *(_DWORD *)&byte_112BDE2[30074]; /*0x718d7c*/
    *(_DWORD *)(host_24 + 16) = *(_DWORD *)v3; /*0x718d84*/
    *(_DWORD *)(host_24 + 20) = *(_DWORD *)(v3 + 56); /*0x718d8a*/
    *(_BYTE *)(host_24 + 1) = *(_DWORD *)(v3 + 68) != 0; /*0x718d94*/
    v38 = Std_IdentityFunc(*(_DWORD *)(a2 + 28)); /*0x718da0*/
    v39 = v98; /*0x718da5*/
    *(_DWORD *)(host_24 + 24) = v38; /*0x718dab*/
    *(_WORD *)(host_24 + 28) = n14208; /*0x718db4*/
    qmemcpy((void *)(host_24 + 32), *(const void **)(v39 + 32), 0x40u); /*0x718dc3*/
    src = *(const void **)(v39 + 68); /*0x718dc5*/
    if ( src ) /*0x718dcd*/
      qmemcpy((void *)(host_16 + 96), src, 0x40u); /*0x718ddd*/
    v41 = n2_1 == 0; /*0x718ddf*/
    host_25 = host_16; /*0x718de6*/
    *(_DWORD *)(host_16 + 160) = v92; /*0x718df2*/
    *(_DWORD *)(host_25 + 164) = host_2; /*0x718dfe*/
    *(_BYTE *)(host_25 + 30) = *(_BYTE *)(v39 + 8); /*0x718e07*/
    *(float *)(host_25 + 176) = v112; /*0x718e0d*/
    *(float *)(host_25 + 180) = v113; /*0x718e16*/
    *(float *)(host_25 + 184) = v114; /*0x718e1f*/
    *(float *)(host_25 + 188) = v115; /*0x718e28*/
    qmemcpy((void *)(host_25 + 468), src_6, 0x40u); /*0x718e3e*/
    host_1 = host_16; /*0x718e40*/
    if ( v41 ) /*0x718e46*/
    {
      *(_DWORD *)(host_16 + 192) = DataPtr_1; /*0x718e4e*/
      *(_DWORD *)(host_1 + 240) = v94; /*0x718e5a*/
    }
    else
    {
      *(_DWORD *)(host_16 + 240) = v94; /*0x718e6b*/
      *(_DWORD *)(host_1 + 244) = v95; /*0x718e77*/
      *(_DWORD *)(host_1 + 248) = v96; /*0x718e83*/
      *(_DWORD *)(host_1 + 252) = v97; /*0x718e8f*/
      *(FFXMagicHost **)(host_1 + 192) = host[0]; /*0x718e9b*/
      *(FFXMagicHost **)(host_1 + 196) = host[1]; /*0x718ea7*/
      *(FFXMagicHost **)(host_1 + 200) = host[2]; /*0x718eb3*/
      *(FFXMagicHost **)(host_1 + 204) = host[3]; /*0x718ebf*/
      *(_DWORD *)(host_1 + 208) = v94; /*0x718ecb*/
      *(_DWORD *)(host_1 + 212) = v95; /*0x718ed7*/
      *(_DWORD *)(host_1 + 216) = v96; /*0x718ee3*/
      *(_DWORD *)(host_1 + 220) = v97; /*0x718eef*/
      *(_DWORD *)(host_1 + 224) = v94; /*0x718efb*/
      *(_DWORD *)(host_1 + 228) = v95; /*0x718f07*/
      *(_DWORD *)(host_1 + 232) = v96; /*0x718f13*/
      *(_DWORD *)(host_1 + 236) = v97; /*0x718f1f*/
    }
    if ( (*(_BYTE *)v39 & 0x40) != 0 ) /*0x718f28*/
    {
      *(_DWORD *)(host_1 + 256) = *(_DWORD *)(v39 + 60); /*0x718f2d*/
      host_17 = host_16; /*0x718f36*/
      qmemcpy((void *)(host_1 + 400), *(const void **)(v39 + 36), 0x40u); /*0x718f47*/
      qmemcpy((void *)(host_17 + 272), *(const void **)(v39 + 44), 0x40u); /*0x718f57*/
      qmemcpy((void *)(host_17 + 336), *(const void **)(v39 + 40), 0x40u); /*0x718f67*/
      host_1 = host_16; /*0x718f69*/
      *(_BYTE *)(host_16 + 464) = *(_BYTE *)(v39 + 77); /*0x718f72*/
    }
    *(_DWORD *)(host_1 + 260) = 0; /*0x718f78*/
  }
  else
  {
    v39 = v98; /*0x718f84*/
  }
  *(_DWORD *)(v39 + 56) = v90; /*0x718f90*/
  *(_DWORD *)(v39 + 60) = HIDWORD(host_15); /*0x718f99*/
  v44 = v108; /*0x718f9c*/
  if ( v108 <= 0 ) /*0x718fa4*/
    return 1; /*0x718fa4*/
  v45 = -1; /*0x718faa*/
  n3240 = 0; /*0x718fad*/
  while ( 2 ) /*0x718fb0*/
  {
    n3240 += 108; /*0x718fb0*/
    ++v45; /*0x718fb3*/
    if ( n3240 >= 3240 ) /*0x718fba*/
      return 0; /*0x718fba*/
    switch ( *(_BYTE *)(host_11 + 1) ) /*0x718fcd*/
    {
      case 0: /*0x718fcd*/
        if ( n2_1 == 1 ) /*0x718fdd*/
        {
          n4 = 0; /*0x718fdf*/
          host_2 = 0; /*0x718fe1*/
          do /*0x71904a*/
          {
            HIDWORD(host_15) = host[n4]; /*0x719002*/
            FFX_MagicHost_AllocPppParticleSlot((FFXMagicHost *)HIDWORD(host_15)); /*0x719008*/
            if ( !v48 ) /*0x719012*/
              return 0; /*0x719012*/
            v49 = HIDWORD(host_15); /*0x719018*/
            *(_DWORD *)(*(_DWORD *)(HIDWORD(host_15) + 148) + n3240 - 104) = 0; /*0x719024*/
            v50 = *(_DWORD *)(v49 + 148); /*0x71902c*/
            n4 = host_2 + 1; /*0x719038*/
            *(_DWORD *)(v50 + n3240 - 100) = 0; /*0x719039*/
            host_2 = n4; /*0x719041*/
          }
          while ( n4 < 4 ); /*0x71904a*/
        }
        else if ( n2_1 == 2 ) /*0x719054*/
        {
          host_18 = 0; /*0x719062*/
          v52 = *(_WORD *)(DataPtr_1 + 196) != 0; /*0x719064*/
          v44 = v108; /*0x71906b*/
          host_2 = 0; /*0x719071*/
          if ( !v52 ) /*0x719077*/
          {
LABEL_99:
            host_1 = host_10 + 20 * *(__int16 *)(host_11 + 2); /*0x719114*/
            goto LABEL_158; /*0x719124*/
          }
          do /*0x7190ea*/
          {
            HIDWORD(host_15) = host[host_18]; /*0x719087*/
            FFX_MagicHost_AllocPppParticleSlot((FFXMagicHost *)HIDWORD(host_15)); /*0x71909d*/
            if ( !v53 ) /*0x7190a7*/
              return 0; /*0x7190a7*/
            memset( /*0x7190c6*/
              *(void **)(*(_DWORD *)(HIDWORD(host_15) + 148) + n3240 - 80),
              0,
              2 * *(_DWORD *)(*(_DWORD *)(HIDWORD(host_15) + 148) + n3240 - 100));
            host_19 = *(unsigned __int16 *)(DataPtr_1 + 196); /*0x7190d7*/
            host_18 = host_2 + 1; /*0x7190de*/
            host_2 = host_18; /*0x7190e2*/
          }
          while ( host_18 < host_19 ); /*0x7190ea*/
        }
        else
        {
          FFX_MagicHost_AllocPppParticleSlot((FFXMagicHost *)host_1); /*0x7190fe*/
          if ( !v55 ) /*0x719108*/
            return 0; /*0x719108*/
        }
        v44 = v108; /*0x71910e*/
        goto LABEL_99; /*0x71910e*/
      case 1: /*0x718fcd*/
        if ( n2_1 == 1 ) /*0x7192a5*/
        {
          n4_1 = 0; /*0x7192a7*/
          host_2 = 0; /*0x7192a9*/
          while ( 1 ) /*0x7192c2*/
          {
            HIDWORD(host_15) = host[n4_1]; /*0x7192c2*/
            FFX_MagicHost_AllocPppParticleSlot((FFXMagicHost *)HIDWORD(host_15)); /*0x7192c8*/
            if ( !v63 ) /*0x7192d2*/
              return 0; /*0x7192d2*/
            v64 = HIDWORD(host_15); /*0x7192d8*/
            *(_DWORD *)(n3240 + *(_DWORD *)(HIDWORD(host_15) + 148) - 104) = 0; /*0x7192e4*/
            v65 = *(_DWORD *)(v64 + 148); /*0x7192ec*/
            n4_1 = host_2 + 1; /*0x7192f8*/
            *(_DWORD *)(n3240 + v65 - 100) = 0; /*0x7192f9*/
            host_2 = n4_1; /*0x719301*/
            if ( n4_1 >= 4 ) /*0x71930a*/
              goto LABEL_124; /*0x71930a*/
          }
        }
        if ( n2_1 == 2 ) /*0x719314*/
        {
          host_20 = 0; /*0x719322*/
          v52 = *(_WORD *)(DataPtr_1 + 196) != 0; /*0x719324*/
          v44 = v108; /*0x71932b*/
          host_2 = 0; /*0x719331*/
          if ( v52 ) /*0x719337*/
          {
            while ( 1 ) /*0x719347*/
            {
              HIDWORD(host_15) = host[host_20]; /*0x719347*/
              FFX_MagicHost_AllocPppParticleSlot((FFXMagicHost *)HIDWORD(host_15)); /*0x71935d*/
              if ( !v67 ) /*0x719367*/
                return 0; /*0x719367*/
              memset( /*0x719386*/
                *(void **)(*(_DWORD *)(HIDWORD(host_15) + 148) + n3240 - 80),
                0,
                2 * *(_DWORD *)(*(_DWORD *)(HIDWORD(host_15) + 148) + n3240 - 100));
              host_21 = *(unsigned __int16 *)(DataPtr_1 + 196); /*0x719397*/
              host_20 = host_2 + 1; /*0x71939e*/
              host_2 = host_20; /*0x7193a2*/
              if ( host_20 >= host_21 ) /*0x7193aa*/
                goto LABEL_124; /*0x7193aa*/
            }
          }
        }
        else
        {
          FFX_MagicHost_AllocPppParticleSlot((FFXMagicHost *)host_1); /*0x7193be*/
          if ( !v69 ) /*0x7193c8*/
            return 0; /*0x7193c8*/
LABEL_124:
          v44 = v108; /*0x7193ce*/
        }
        host_1 = host_10 + 28 * *(__int16 *)(host_11 + 2); /*0x7193e7*/
        goto LABEL_158; /*0x7193ea*/
      case 2: /*0x718fcd*/
        if ( n2_1 == 1 ) /*0x719132*/
        {
          host_1 = 0; /*0x719138*/
          host_2 = 0; /*0x71913a*/
          do /*0x71919a*/
          {
            HIDWORD(host_15) = host[host_1]; /*0x719152*/
            FFX_MagicHost_AllocPppParticleSlot((FFXMagicHost *)HIDWORD(host_15)); /*0x719158*/
            if ( !v56 ) /*0x719162*/
              return 0; /*0x719162*/
            v57 = HIDWORD(host_15); /*0x719168*/
            *(_DWORD *)(*(_DWORD *)(HIDWORD(host_15) + 148) + n3240 - 104) = 0; /*0x719174*/
            v58 = *(_DWORD *)(v57 + 148); /*0x71917c*/
            host_1 = host_2 + 1; /*0x719188*/
            *(_DWORD *)(v58 + n3240 - 100) = 0; /*0x719189*/
            host_2 = host_1; /*0x719191*/
          }
          while ( host_1 < 4 ); /*0x71919a*/
          v44 = v108; /*0x7191a0*/
          host_10 += 32 * *(__int16 *)(host_11 + 2); /*0x7191a9*/
        }
        else
        {
          if ( n2_1 != 2 ) /*0x7191b7*/
          {
            FFX_MagicHost_AllocPppParticleSlot((FFXMagicHost *)host_1); /*0x719274*/
            if ( !v61 ) /*0x71927e*/
              return 0; /*0x71927e*/
            v44 = v108; /*0x719284*/
LABEL_112:
            host_10 += 32 * *(__int16 *)(host_11 + 2); /*0x71928a*/
            goto LABEL_159; /*0x719297*/
          }
          host_1 = 0; /*0x7191c5*/
          v52 = *(_WORD *)(DataPtr_1 + 196) != 0; /*0x7191c7*/
          v44 = v108; /*0x7191ce*/
          host_2 = 0; /*0x7191d4*/
          if ( !v52 ) /*0x7191da*/
            goto LABEL_112; /*0x7191da*/
          do /*0x71924a*/
          {
            HIDWORD(host_15) = host[host_1]; /*0x7191e7*/
            FFX_MagicHost_AllocPppParticleSlot((FFXMagicHost *)HIDWORD(host_15)); /*0x7191fd*/
            if ( !v59 ) /*0x719207*/
              return 0; /*0x719207*/
            memset( /*0x719226*/
              *(void **)(*(_DWORD *)(HIDWORD(host_15) + 148) + n3240 - 80),
              0,
              2 * *(_DWORD *)(*(_DWORD *)(HIDWORD(host_15) + 148) + n3240 - 100));
            host_3 = *(unsigned __int16 *)(DataPtr_1 + 196); /*0x719237*/
            host_1 = host_2 + 1; /*0x71923e*/
            host_2 = host_1; /*0x719242*/
          }
          while ( host_1 < host_3 ); /*0x71924a*/
          v44 = v108; /*0x719250*/
          host_10 += 32 * *(__int16 *)(host_11 + 2); /*0x719259*/
        }
        goto LABEL_159; /*0x7191af*/
      case 3: /*0x718fcd*/
        goto LABEL_154;
      case 4: /*0x718fcd*/
        if ( n2_1 == 1 ) /*0x719405*/
        {
          host_5 = 0; /*0x71940b*/
          host_2 = 0; /*0x71940d*/
          do /*0x719483*/
          {
            host_4 = (FFXMagicHost *)*(__int16 *)(host_11 + 2); /*0x719420*/
            HIDWORD(host_15) = host[host_5]; /*0x71943b*/
            FFX_MagicHost_AllocPppParticleSlot(host_4); /*0x719441*/
            if ( !v72 ) /*0x71944b*/
              return 0; /*0x71944b*/
            v73 = HIDWORD(host_15); /*0x719451*/
            *(_DWORD *)(*(_DWORD *)(HIDWORD(host_15) + 148) + n3240 - 104) = 0; /*0x71945d*/
            *(_DWORD *)(*(_DWORD *)(v73 + 148) + n3240 - 100) = 0; /*0x71946b*/
            host_5 = host_2 + 1; /*0x719479*/
            host_2 = host_5; /*0x71947a*/
          }
          while ( host_5 < 4 ); /*0x719483*/
          v44 = v108; /*0x719489*/
          v74 = 3 * *(__int16 *)(host_11 + 2); /*0x71948f*/
        }
        else
        {
          if ( n2_1 != 2 ) /*0x71949a*/
          {
            FFX_MagicHost_AllocPppParticleSlot((FFXMagicHost *)*(__int16 *)(host_11 + 2)); /*0x71955a*/
            if ( !v78 ) /*0x719564*/
              return 0; /*0x719564*/
            v44 = v108; /*0x71956a*/
LABEL_138:
            v74 = 3 * *(__int16 *)(host_11 + 2); /*0x719570*/
            goto LABEL_157; /*0x719577*/
          }
          host_6 = 0; /*0x7194a8*/
          v52 = *(_WORD *)(DataPtr_1 + 196) != 0; /*0x7194aa*/
          v44 = v108; /*0x7194b1*/
          host_2 = 0; /*0x7194b7*/
          if ( !v52 ) /*0x7194bd*/
            goto LABEL_138; /*0x7194bd*/
          do /*0x71952d*/
          {
            HIDWORD(host_15) = host[host_6]; /*0x7194ca*/
            FFX_MagicHost_AllocPppParticleSlot((FFXMagicHost *)HIDWORD(host_15)); /*0x7194e0*/
            if ( !v76 ) /*0x7194ea*/
              return 0; /*0x7194ea*/
            memset( /*0x719509*/
              *(void **)(*(_DWORD *)(HIDWORD(host_15) + 148) + n3240 - 80),
              0,
              2 * *(_DWORD *)(*(_DWORD *)(HIDWORD(host_15) + 148) + n3240 - 100));
            host_7 = *(unsigned __int16 *)(DataPtr_1 + 196); /*0x71951a*/
            host_6 = host_2 + 1; /*0x719521*/
            host_2 = host_6; /*0x719525*/
          }
          while ( host_6 < host_7 ); /*0x71952d*/
          v44 = v108; /*0x719533*/
          v74 = 3 * *(__int16 *)(host_11 + 2); /*0x719539*/
        }
        goto LABEL_157; /*0x719492*/
      case 5: /*0x718fcd*/
        FFX_MagicHost_AllocPppParticleSlot((FFXMagicHost *)*(__int16 *)(host_11 + 2)); /*0x719595*/
        if ( !v79 ) /*0x71959f*/
          return 0; /*0x71959f*/
        v44 = v108; /*0x7195a9*/
        host_10 += 32 * *(__int16 *)(host_11 + 2); /*0x7195b2*/
        goto LABEL_159; /*0x7195b8*/
      case 6: /*0x718fcd*/
        if ( n2_1 == 1 ) /*0x71960a*/
        {
          host_9 = 0; /*0x719610*/
          host_2 = 0; /*0x719612*/
          while ( 1 ) /*0x719620*/
          {
            host_8 = (FFXMagicHost *)*(__int16 *)(host_11 + 2); /*0x719620*/
            HIDWORD(host_15) = host[host_9]; /*0x71963b*/
            FFX_MagicHost_AllocPppParticleSlot(host_8); /*0x719641*/
            if ( !v83 ) /*0x71964b*/
              return 0; /*0x71964b*/
            v84 = HIDWORD(host_15); /*0x719651*/
            *(_DWORD *)(*(_DWORD *)(HIDWORD(host_15) + 148) + n3240 - 104) = 0; /*0x71965d*/
            *(_DWORD *)(*(_DWORD *)(v84 + 148) + n3240 - 100) = 0; /*0x71966b*/
            host_9 = host_2 + 1; /*0x719679*/
            host_2 = host_9; /*0x71967a*/
            if ( host_9 >= 4 ) /*0x719683*/
              goto LABEL_155; /*0x719683*/
          }
        }
        if ( n2_1 != 2 ) /*0x71968d*/
        {
          host_1 = *(__int16 *)(host_11 + 2); /*0x71972e*/
LABEL_154:
          FFX_MagicHost_AllocPppParticleSlot((FFXMagicHost *)host_1); /*0x71973f*/
          if ( !v88 ) /*0x719751*/
            return 0; /*0x719751*/
LABEL_155:
          v44 = v108; /*0x719757*/
          goto LABEL_156; /*0x719757*/
        }
        host_12 = 0; /*0x71969b*/
        v52 = *(_WORD *)(DataPtr_1 + 196) != 0; /*0x71969d*/
        v44 = v108; /*0x7196a4*/
        host_2 = 0; /*0x7196aa*/
        if ( !v52 ) /*0x7196b0*/
        {
LABEL_156:
          v74 = 5 * *(__int16 *)(host_11 + 2); /*0x71975d*/
LABEL_157:
          host_1 = host_10 + 8 * v74; /*0x719764*/
LABEL_158:
          host_10 = host_1; /*0x71976d*/
LABEL_159:
          v44 -= *(__int16 *)(host_11 + 2); /*0x719773*/
          host_11 = host_10; /*0x71977f*/
          v108 = v44; /*0x719784*/
          host_10 += 16; /*0x71978a*/
          if ( v44 <= 0 ) /*0x719792*/
            return 1; /*0x719792*/
          continue; /*0x719792*/
        }
        while ( 1 ) /*0x7196c7*/
        {
          HIDWORD(host_15) = host[host_12]; /*0x7196c7*/
          FFX_MagicHost_AllocPppParticleSlot((FFXMagicHost *)HIDWORD(host_15)); /*0x7196dd*/
          if ( !v86 ) /*0x7196e7*/
            return 0; /*0x7196e7*/
          memset( /*0x719706*/
            *(void **)(n3240 + *(_DWORD *)(HIDWORD(host_15) + 148) - 80),
            0,
            2 * *(_DWORD *)(n3240 + *(_DWORD *)(HIDWORD(host_15) + 148) - 100));
          host_13 = *(unsigned __int16 *)(DataPtr_1 + 196); /*0x719717*/
          host_12 = host_2 + 1; /*0x71971e*/
          host_2 = host_12; /*0x719722*/
          if ( host_12 >= host_13 ) /*0x71972a*/
            goto LABEL_155; /*0x71972a*/
        }
      case 7: /*0x718fcd*/
        FFX_MagicHost_AllocPppParticleSlot((FFXMagicHost *)*(__int16 *)(host_11 + 2)); /*0x7195d6*/
        if ( !v80 ) /*0x7195e0*/
          return 0; /*0x7195e0*/
        v44 = v108; /*0x7195ea*/
        host_10 += 48 * *(__int16 *)(host_11 + 2); /*0x7195f6*/
        goto LABEL_159; /*0x7195fc*/
      default:
        goto LABEL_159;
    }
  }
}