// FFX Phyre: Render state setup
int __cdecl FFX_Phyre_RenderStateSetup()
{
  int ebx___slot_record_do_efeito_atual_(from_this_0x220); // ebx
  int FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe; // esi
  __int16 v2; // ax
  double v3; // st7
  int n4096; // eax
  Address *Address_1; // eax
  int n255_1; // eax
  char Alpha_do_efeito,_clamp_0_0xFF; // al
  int n255_2; // eax
  char v9; // al
  int UV_scale_calculation:_4_canais_(RGBA)._Le_bytes_de_UV_tile_do_s; // ecx
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st4
  double v15; // rt0
  double v16; // rt1
  double v17; // st4
  double v18; // st7
  double v19; // st3
  int v20; // eax
  Address *Address; // eax
  int n255; // eax
  char v24; // cl
  int *SlotSubResource; // eax
  int *v26; // ecx
  int v27; // eax
  int v28; // esi
  int v29; // eax
  unsigned int CurrentMagicId; // edi
  unsigned int n581; // eax
  unsigned int i; // ecx
  float v33; // [esp+4h] [ebp-3CCh]
  float Size; // [esp+14h] [ebp-3BCh]
  float ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_blef; // [esp+18h] [ebp-3B8h]
  int ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_bleh; // [esp+18h] [ebp-3B8h]
  float ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_blei; // [esp+18h] [ebp-3B8h]
  float Prepara_scale_factors_de_UV___dynamic_light_params__Type0_; // [esp+1Ch] [ebp-3B4h]
  char *inited; // [esp+2Ch] [ebp-3A4h]
  int v40; // [esp+2Ch] [ebp-3A4h]
  _DWORD *FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe_1; // [esp+34h] [ebp-39Ch]
  unsigned __int16 v42; // [esp+34h] [ebp-39Ch]
  _DWORD *v43; // [esp+34h] [ebp-39Ch]
  int *v44; // [esp+38h] [ebp-398h]
  int *v45; // [esp+38h] [ebp-398h]
  int v46; // [esp+38h] [ebp-398h]
  _DWORD *v47; // [esp+3Ch] [ebp-394h]
  int v48; // [esp+3Ch] [ebp-394h]
  int v49; // [esp+3Ch] [ebp-394h]
  int v50; // [esp+3Ch] [ebp-394h]
  int v51; // [esp+40h] [ebp-390h]
  int v52; // [esp+40h] [ebp-390h]
  unsigned __int16 Size_2; // [esp+40h] [ebp-390h]
  float v54; // [esp+44h] [ebp-38Ch]
  float v55; // [esp+44h] [ebp-38Ch]
  int v56; // [esp+48h] [ebp-388h]
  int ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_blea; // [esp+50h] [ebp-380h]
  int ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_bleb; // [esp+50h] [ebp-380h]
  int ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_blec; // [esp+50h] [ebp-380h]
  float ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_bled; // [esp+50h] [ebp-380h]
  float ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_blee; // [esp+50h] [ebp-380h]
  int ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_bleg; // [esp+50h] [ebp-380h]
  float *____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_ble; // [esp+50h] [ebp-380h]
  float v64; // [esp+58h] [ebp-378h]
  float v65; // [esp+58h] [ebp-378h]
  float v66; // [esp+58h] [ebp-378h]
  float v67; // [esp+58h] [ebp-378h]
  unsigned __int16 v68; // [esp+58h] [ebp-378h]
  float v69; // [esp+58h] [ebp-378h]
  float v70; // [esp+58h] [ebp-378h]
  float ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_ble_1; // [esp+58h] [ebp-378h]
  float Size_1; // [esp+58h] [ebp-378h]
  float v73; // [esp+58h] [ebp-378h]
  unsigned __int64 hudContext_; // [esp+5Ch] [ebp-374h] BYREF
  unsigned __int8 v75; // [esp+66h] [ebp-36Ah]
  unsigned __int8 v76; // [esp+67h] [ebp-369h]
  float v77[16]; // [esp+7Ch] [ebp-354h] BYREF
  float v78[16]; // [esp+BCh] [ebp-314h] BYREF
  int v79[16]; // [esp+FCh] [ebp-2D4h] BYREF
  float dst[16]; // [esp+13Ch] [ebp-294h] BYREF
  float src; // [esp+17Ch] [ebp-254h] BYREF
  float v82; // [esp+180h] [ebp-250h]
  float v83; // [esp+184h] [ebp-24Ch]
  float v84; // [esp+18Ch] [ebp-244h]
  float v85; // [esp+190h] [ebp-240h]
  float Side_op:_copia_matriz_UV_scale_e_multiplica_por_0.5_(dbl_B0DBB0; // [esp+194h] [ebp-23Ch]
  float v87; // [esp+19Ch] [ebp-234h]
  float v88; // [esp+1A0h] [ebp-230h]
  float v89; // [esp+1A4h] [ebp-22Ch]
  float v91[4]; // [esp+1BCh] [ebp-214h] BYREF
  int v92[64]; // [esp+1CCh] [ebp-204h] BYREF
  int v93[64]; // [esp+2CCh] [ebp-104h] BYREF
  int savedregs; // [esp+3D0h] [ebp+0h] BYREF
  int v95; // [esp+3D8h] [ebp+8h]
  __int16 *v96; // [esp+3DCh] [ebp+Ch]

  ebx___slot_record_do_efeito_atual_(from_this_0x220) = *(_DWORD *)(v95 + 544);// ebx = slot record do efeito atual (from this+0x220) /*0xa6f4f2*/
  v51 = owu_chr_hd[*(unsigned __int8 *)(ebx___slot_record_do_efeito_atual_(from_this_0x220) + 24)]; /*0xa6f509*/
  v47 = *(_DWORD **)(v95 + 4 * *(unsigned __int8 *)(ebx___slot_record_do_efeito_atual_(from_this_0x220) + 30) + 864); /*0xa6f51a*/
  FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe = FFX_Magic_TraverseRecordChain( /*0xa6f52c*/
                                                                      (_DWORD *)(v95 + 768),
                                                                      ebx___slot_record_do_efeito_atual_(from_this_0x220),
                                                                      v96[1]);// FFX_Magic_TraverseRecordChain: percorre chain de records do efeito
  v2 = *(_WORD *)(v95 + 538); /*0xa6f52e*/
  FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe_1 = (_DWORD *)FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe; /*0xa6f538*/
  if ( (v2 & 0x800) != 0 ) // Flag 0x800: override de alpha? Se sim, usa alpha do record; se nao, default 1.0 /*0xa6f543*/
    v3 = *(float *)(FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe + 60); /*0xa6f545*/
  else
    v3 = 256.0; /*0xa6f54a*/
  n4096 = v2 & 0xF000; /*0xa6f550*/
  v54 = v3; /*0xa6f555*/
  if ( n4096 == 4096 ) // Check flag 0x1000: path de efeito secundario (side-op)
  {
    ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_ble = (float *)(v95 + 128);// === PATH SIDE-OP (0x1000) === Efeitos secundarios com alpha blending interpolation /*0xa6fb33*/
    inited = FFX_Ps3Data_InitSlotDrawParams( /*0xa6fb69*/
               v95 + 256,
               v95,
               v95 + 768,
               ebx___slot_record_do_efeito_atual_(from_this_0x220),
               v96[3]);
    FFX_MagicSideOp_ComputeSlotColorScales( /*0xa6fb7f*/
      v95 + 256,
      v95,
      (_DWORD *)(v95 + 768),
      ebx___slot_record_do_efeito_atual_(from_this_0x220),
      (int)(v96 + 3)); // FFX_MagicSideOp_ComputeSlotColorScales: calcula escalas de cor para slot side-op
    Address = (float *)FFX_Magic_ResolveRecordTargetAddress( /*0xa6fb86*/
                         (_DWORD *)v95,
                         (unsigned __int16 *)ebx___slot_record_do_efeito_atual_(from_this_0x220));
    FFX_Magic_CopyRuntimeTransformMatricesToGlobals_structural(v77, (float *)(v95 + 704), Address); /*0xa6fb9a*/
    *(_DWORD *)(v95 + 272) = (int)*(float *)(FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe + 144) << 16; /*0xa6fbb6*/
    *(_DWORD *)(v95 + 276) = (int)*(float *)(FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe + 148) << 16; /*0xa6fbca*/
    *(_DWORD *)(v95 + 280) = *(_DWORD *)(FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe + 200); /*0xa6fbd6*/
    n255 = (int)*(float *)(FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe + 76); /*0xa6fbdf*/
    if ( n255 < 255 )
      v24 = n255 < 0 ? 0 : n255;
    else
      v24 = -1; /*0xa6fbeb*/
    *(_BYTE *)(v95 + 283) = v24; /*0xa6fc02*/
    FFX_Magic_TransformDrawDispatchForScene( /*0xa6fc2b*/
      COERCE_FLOAT(&savedregs),
      v79,
      *(unsigned __int8 *)(ebx___slot_record_do_efeito_atual_(from_this_0x220) + 24),
      v54,
      ebx___slot_record_do_efeito_atual_(from_this_0x220) + 48,
      ebx___slot_record_do_efeito_atual_(from_this_0x220) + 144,
      *(char *)(v95 + 542));
    FFX_Magic_TransformDrawDispatchForScene( /*0xa6fc5c*/
      COERCE_FLOAT(&savedregs),
      (void *)(v95 + 128),
      *(unsigned __int8 *)(ebx___slot_record_do_efeito_atual_(from_this_0x220) + 24),
      v54,
      FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe + 48,
      ebx___slot_record_do_efeito_atual_(from_this_0x220) + 144,
      *(char *)(v95 + 542));
    if ( FFX_Magic_GetCurrentMagicId() == 581 ) /*0xa6fc6e*/
    {
      FFX_Mem_Copy64Bytes_structural(&src, v79); /*0xa6fc82*/
      src = src * 1000.0; /*0xa6fca7*/
      v82 = v82 * 1000.0; /*0xa6fcb5*/
      v83 = v83 * 1000.0; /*0xa6fcc3*/
      v84 = v84 * 1000.0; /*0xa6fcd1*/
      v85 = v85 * 1000.0; /*0xa6fcdf*/
      Side_op:_copia_matriz_UV_scale_e_multiplica_por_0.5_(dbl_B0DBB0 = Side_op:_copia_matriz_UV_scale_e_multiplica_por_0.5_(dbl_B0DBB0 /*0xa6fced*/
                                                                      * 1000.0;// Side-op: copia matriz UV scale e multiplica por 0.5 (dbl_B0DBB0)
      v87 = v87 * 1000.0; /*0xa6fcfb*/
      v88 = v88 * 1000.0; /*0xa6fd09*/
      v89 = 1000.0 * v89; /*0xa6fd15*/
      SlotSubResource = (int *)FFX_Magic_GetSlotSubResource(v51); /*0xa6fd1b*/
      FFX_ResourcePool_AllocSlotWithCopy(SlotSubResource, &src);// AllocSlotWithCopy: aloca slot com copia da textura /*0xa6fd24*/
    }
    FFX_Magic_ThunkToServiceDraw(v47, v96[2], (int)&hudContext_); /*0xa6fd44*/
    v26 = (int *)(inited + 16); /*0xa6fd4f*/
    v27 = *((unsigned __int16 *)inited + 2); /*0xa6fd52*/
    v49 = v27; /*0xa6fd5f*/
    v45 = (int *)(inited + 16); /*0xa6fd65*/
    *(_DWORD *)(v95 + 300) = v78; /*0xa6fd6b*/
    if ( v27 ) /*0xa6fd73*/
    {
      do /*0xa6fe6f*/
      {
        qmemcpy(dst, (const void *)Std_IdentityFunc(v26[1]), sizeof(dst)); /*0xa6fd95*/
        dst[12] = dst[12] * 1000.0; /*0xa6fda7*/
        dst[13] = dst[13] * 1000.0; /*0xa6fdb5*/
        dst[14] = 1000.0 * dst[14]; /*0xa6fdd5*/
        FFX_Magic_CopyRuntimeTransformMatricesToGlobals_structural(v78, (float *)v79, dst); /*0xa6fddc*/
        FFX_Magic_CopyRuntimeTransformMatricesToGlobals_structural((float *)(v95 + 192), v77, v78); /*0xa6fdf5*/
        FFX_Magic_CopyRuntimeTransformMatricesToGlobals_structural( /*0xa6fe0e*/
          v78,
          ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_ble,
          dst);
        v28 = v49; /*0xa6fe19*/
        if ( v49 == *((unsigned __int16 *)inited + 2) ) /*0xa6fe28*/
        {
          v29 = Std_IdentityFunc(*v45); /*0xa6fe46*/
          FFX_Phyre_AlphaBlendInterpolate( /*0xa6fe4f*/
            v29,
            v95 + 256,
            ebx___slot_record_do_efeito_atual_(from_this_0x220),
            (int)FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe_1,
            (unsigned __int8 *)&hudContext_); // FFX_Phyre_AlphaBlendInterpolate: interpola alpha entre sub-slots
        }
        v26 = v45 + 4; /*0xa6fe5e*/
        v45 += 4; /*0xa6fe61*/
        --v49; /*0xa6fe67*/
      }
      while ( v28 - 1 > 0 ); /*0xa6fe6f*/
    }
    v43 = (_DWORD *)FFX_Magic_GetSlotSubResource(v51); /*0xa6fe8d*/
    Size_2 = 16 * v76; /*0xa6feb4*/
    v68 = 16 * v75; /*0xa6fedb*/
    if ( !FFX_Texture_ResolveDdsByDescriptor(hudContext_ & 0x3FFF, (hudContext_ >> 20) & 0x3F, 0, 0, v68, Size_2, v93) ) /*0xa6feee*/
      return (int)(v96 + 8); // Resolve textura DDS para o side-op /*0xa6feee*/
    CurrentMagicId = FFX_Magic_GetCurrentMagicId(); /*0xa6fef9*/
    v40 = v68; /*0xa6ff15*/
    v69 = (float)(((*(_DWORD *)(v95 + 272) % (v68 << 16)) >> 4) / v68); /*0xa6ff3e*/
    *(float *)&v46 = v69 * 0.000244140625; /*0xa6ff5f*/
    v70 = (float)(((*(_DWORD *)(v95 + 276) % (Size_2 << 16)) >> 4) / Size_2); /*0xa6ff85*/
    *(float *)&v50 = 0.000244140625 * v70; /*0xa6ff9b*/
    v55 = (double)*(unsigned __int8 *)(v95 + 283) * 0.0078125; /*0xa6ffb9*/
    n581 = FFX_Magic_GetCurrentMagicId(); /*0xa6ffbf*/
    for ( i = 0; i < 7; ++i ) /*0xa6ffc6*/
    {
      if ( n581 == dword_C88C6C[i] ) /*0xa6ffce*/
        goto LABEL_48; /*0xa6ffce*/
    }
    if ( n581 - 622 <= 7 || n581 - 630 <= 7 || n581 == 581 ) /*0xa6fff4*/
LABEL_48:
      v55 = (double)*(char *)(v95 + 284) / 48.0; /*0xa6fff6*/
    if ( CurrentMagicId == 581 ) /*0xa70024*/
      v55 = v55 * 3.0; /*0xa70032*/
    ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_ble_1 = *(float *)(ebx___slot_record_do_efeito_atual_(from_this_0x220) /*0xa70047*/
                                                                                 + 60)
                                                                      * 16.0
                                                                      * 0.000244140625;
    *(float *)&v56 = 1.0; /*0xa7004f*/
    switch ( CurrentMagicId ) /*0xa7007b*/
    { // Magic ID checks para override de alpha scale (0x276/0x27A/0x270/0x0A1/0x26F/0x272 = Overdrives)
      case 0x276u: /*0xa7007b*/
      case 0x27Au: /*0xa7007b*/
      case 0x270u: /*0xa7007b*/
      case 0xA1u: /*0xa7007b*/
      case 0x26Fu: /*0xa7007b*/
        *(float *)&v56 = 1000.0; /*0xa700af*/
        break;
      case 0x272u: /*0xa7007b*/
        *(float *)&v56 = 500.0; /*0xa7008b*/
LABEL_64:
        ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_blei = ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_ble_1; /*0xa700d7*/
        Size_1 = (float)Size_2; /*0xa700fa*/
        Size = Size_1; /*0xa70106*/
        v73 = (float)v40; /*0xa70110*/
        FFX_DynamicLight_Type1_Wrapper( /*0xa7014c*/
          v43,
          (int)v93,
          *(float *)&v46,
          *(float *)&v50,
          v55,
          ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_ble,
          v73,
          Size,
          ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_blei,
          *(float *)&v56); // FFX_DynamicLight_Type1_Wrapper — dynamic lighting tipo 1 com UV offset e alpha
        return (int)(v96 + 8); /*0xa70161*/
      case 0x144u: /*0xa7007b*/
        *(float *)&v56 = 700.0; /*0xa700a1*/
        goto LABEL_64; /*0xa700a7*/
      case 0x2C6u: /*0xa7007b*/
        ++magic_710_count; /*0xa700c3*/
        if ( magic_710_count < 635 ) /*0xa700cd*/
          v55 = 0.0; /*0xa700d1*/
        break;
    }
    goto LABEL_64; /*0xa700d1*/
  }
  if ( n4096 != 0x2000 ) // Check flag 0x2000: path de draw padrao /*0xa6f56b*/
    return (int)v96; /*0xa6fb10*/
  v44 = (int *)FFX_Ps3Data_InitSlotDrawParams( /*0xa6f5a5*/
                 v95 + 256,
                 v95,
                 v95 + 768,
                 ebx___slot_record_do_efeito_atual_(from_this_0x220),
                 v96[3]);
  Address_1 = (float *)FFX_Magic_ResolveRecordTargetAddress( /*0xa6f5ab*/
                         (_DWORD *)v95,
                         (unsigned __int16 *)ebx___slot_record_do_efeito_atual_(from_this_0x220));// Resolve endereco alvo do record (slot sub-resource)
  FFX_Magic_CopyRuntimeTransformMatricesToGlobals_structural(v77, (float *)(v95 + 704), Address_1);// Copia matrizes de transformacao do runtime para globals /*0xa6f5bf*/
  *(_DWORD *)(v95 + 272) = (int)*(float *)(FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe + 144) << 16;// Converte posicao X (esi+0x90) para fixed-point 16.16 /*0xa6f5d5*/
  *(_DWORD *)(v95 + 276) = (int)*(float *)(FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe + 148) << 16;// Converte posicao Y (esi+0x94) para fixed-point 16.16 /*0xa6f5e9*/
  *(_DWORD *)(v95 + 280) = *(_DWORD *)(FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe + 200); /*0xa6f5f5*/
  *(_DWORD *)(v95 + 284) = *(_DWORD *)(ebx___slot_record_do_efeito_atual_(from_this_0x220) + 200); /*0xa6f601*/
  n255_1 = (int)*(float *)(FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe + 76); /*0xa6f60a*/
  if ( n255_1 < 255 )
    Alpha_do_efeito,_clamp_0_0xFF = n255_1 < 0 ? 0 : n255_1;
  else
    Alpha_do_efeito,_clamp_0_0xFF = -1; /*0xa6f619*/
  *(_BYTE *)(v95 + 283) = Alpha_do_efeito,_clamp_0_0xFF;// Alpha do efeito, clamp 0-0xFF /*0xa6f62a*/
  if ( FFX_Magic_GetCurrentMagicId() == 438 || FFX_Magic_GetCurrentMagicId() == 437 )// Magic ID check: 0x1B6 e 0x1B5 sao efeitos especiais que sobrescrevem posicao X/Y
  {
    *(_DWORD *)(v95 + 272) = (int)*(float *)(FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe + 48) << 16; /*0xa6f653*/
    *(_DWORD *)(v95 + 276) = (int)*(float *)(FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe + 52) << 16; /*0xa6f664*/
    n255_2 = (int)*(float *)(ebx___slot_record_do_efeito_atual_(from_this_0x220) + 76); /*0xa6f66d*/
    if ( n255_2 < 255 )
      v9 = n255_2 < 0 ? 0 : n255_2;
    else
      v9 = -1; /*0xa6f67c*/
    *(_BYTE *)(v95 + 283) = v9; /*0xa6f68d*/
  }
  FFX_Magic_TransformDrawDispatchForScene( /*0xa6f6bc*/
    COERCE_FLOAT(&savedregs),
    v79,
    *(unsigned __int8 *)(ebx___slot_record_do_efeito_atual_(from_this_0x220) + 24),
    v54,
    ebx___slot_record_do_efeito_atual_(from_this_0x220) + 48,
    ebx___slot_record_do_efeito_atual_(from_this_0x220) + 144,
    *(char *)(v95 + 542)); // FFX_Magic_TransformDrawDispatchForScene: transforma dispatch com offset do bone
  FFX_Magic_TransformDrawDispatchForScene( /*0xa6f6ed*/
    COERCE_FLOAT(&savedregs),
    (void *)(v95 + 128),
    *(unsigned __int8 *)(ebx___slot_record_do_efeito_atual_(from_this_0x220) + 24),
    v54,
    FFX_Magic_TraverseRecordChain:_percorre_chain_de_records_do_efe + 48,
    ebx___slot_record_do_efeito_atual_(from_this_0x220) + 144,
    *(char *)(v95 + 542));
  FFX_Magic_ThunkToServiceDraw(v47, v96[2], (int)&hudContext_);// FFX_Magic_ThunkToServiceDraw: submete draw indiretamente /*0xa6f70a*/
  if ( FFX_Magic_GetCurrentMagicId() == 438 || FFX_Magic_GetCurrentMagicId() == 437 )// Magic ID check para Overdrive triggers (0x1B6/0x1B5) = atalho SetupTransforms /*0xa6f72c*/
  {
    if ( !gParticleDoNotRender ) /*0xa6fab4*/
      FFX_Phyre_RenderState_SetupTransforms(); /*0xa6faee*/
  }
  else
  {
    v48 = FFX_Magic_GetSlotSubResource(*v44); /*0xa6f745*/
    v42 = 1 << ((hudContext_ >> 26) & 0xF); /*0xa6f773*/
    LOWORD(v52) = 1 << ((hudContext_ >> 30) & 0xF); /*0xa6f799*/
    if ( FFX_Texture_ResolveDdsByDescriptor(hudContext_ & 0x3FFF, (hudContext_ >> 20) & 0x3F, 0, 0, v42, v52, v92) )// FFX_Texture_ResolveDdsByDescriptor: resolve textura DDS do slot /*0xa6f7bb*/
    {
      UV_scale_calculation:_4_canais_(RGBA)._Le_bytes_de_UV_tile_do_s = 0;// UV scale calculation: 4 canais (RGBA). Le bytes de UV tile do slot draw params /*0xa6f7d1*/
      ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_blea = *(unsigned __int8 *)(v95 + 285); /*0xa6f80f*/
      v91[0] = (double)*(unsigned __int8 *)(v95 + 284) + (double)*(unsigned __int8 *)(v95 + 280); /*0xa6f815*/
      v11 = (double)____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_blea /*0xa6f843*/
          + (double)*(unsigned __int8 *)(v95 + 281);
      ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_bleb = *(unsigned __int8 *)(v95 + 286); /*0xa6f84d*/
      v91[1] = v11; /*0xa6f853*/
      v12 = (double)____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_bleb /*0xa6f881*/
          + (double)*(unsigned __int8 *)(v95 + 282);
      ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_blec = *(unsigned __int8 *)(v95 + 287); /*0xa6f88b*/
      v91[2] = v12; /*0xa6f891*/
      v91[3] = (double)____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_blec /*0xa6f8c5*/
             + (double)*(unsigned __int8 *)(v95 + 283);
      v13 = 0.0; /*0xa6f8cb*/
      v14 = 0.0078125; /*0xa6f8d9*/
      while ( 1 ) /*0xa6f8e3*/
      {
        v16 = v14; /*0xa6f8e3*/
        v17 = v13; /*0xa6f8e3*/
        v18 = v16; /*0xa6f8e3*/
        if ( v17 > v91[UV_scale_calculation:_4_canais_(RGBA)._Le_bytes_de_UV_tile_do_s] ) /*0xa6f8f1*/
          v91[UV_scale_calculation:_4_canais_(RGBA)._Le_bytes_de_UV_tile_do_s] = v17; /*0xa6f8f3*/
        if ( v91[UV_scale_calculation:_4_canais_(RGBA)._Le_bytes_de_UV_tile_do_s] > 255.0 ) /*0xa6f908*/
          v91[UV_scale_calculation:_4_canais_(RGBA)._Le_bytes_de_UV_tile_do_s] = 255.0; /*0xa6f90c*/
        v19 = v91[UV_scale_calculation:_4_canais_(RGBA)._Le_bytes_de_UV_tile_do_s++]; /*0xa6f915*/
        v91[UV_scale_calculation:_4_canais_(RGBA)._Le_bytes_de_UV_tile_do_s - 1] = v19 * v18; /*0xa6f91f*/
        if ( UV_scale_calculation:_4_canais_(RGBA)._Le_bytes_de_UV_tile_do_s >= 4 ) /*0xa6f929*/
          break; /*0xa6f929*/
        v15 = v17; /*0xa6f8e1*/
        v14 = v18; /*0xa6f8e1*/
        v13 = v15; /*0xa6f8e1*/
      }
      v52 = (unsigned __int16)v52; /*0xa6f957*/
      ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_bled = *(float *)(ebx___slot_record_do_efeito_atual_(from_this_0x220) /*0xa6f96d*/
                                                                                  + 60)
                                                                       * 16.0
                                                                       * 0.000244140625;// Prepara scale factors de UV + dynamic light params (Type0)
      Prepara_scale_factors_de_UV___dynamic_light_params__Type0_ = ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_bled; /*0xa6f979*/
      ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_blee = (float)(unsigned __int16)v52; /*0xa6f983*/
      ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_blef = ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_blee; /*0xa6f98f*/
      *(float *)&____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_bleg = (float)v42; /*0xa6f999*/
      v64 = (float)(((*(_DWORD *)(v95 + 276) % (v52 << 16)) >> 4) / v52); /*0xa6f9e2*/
      v65 = v64 * 0.000244140625; /*0xa6f9f6*/
      v33 = v65; /*0xa6fa02*/
      v66 = (float)(((*(_DWORD *)(v95 + 272) % (v42 << 16)) >> 4) / v42); /*0xa6fa20*/
      v67 = 0.000244140625 * v66; /*0xa6fa2c*/
      FFX_DynamicLight_Type0_Wrapper( /*0xa6fa42*/
        v48,
        (int)v92,
        v67,
        v33,
        v91,
        1.0,
        (void *)(v95 + 128),
        ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_bleg,
        ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_blef,
        Prepara_scale_factors_de_UV___dynamic_light_params__Type0_);// FFX_DynamicLight_Type0_Wrapper: aplica dynamic lighting tipo 0
      if ( FFX_Magic_GetCurrentMagicId() == 344 && ++unk_22FB3F4 >= 125 )// Contador de frames para fade alpha (magic ID 0x158 = Transparencia) /*0xa6fa68*/
      {
        ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_bleh = *v44; /*0xa6fa80*/
        v20 = FFX_Magic_GetSlotSubResource(*v44); /*0xa6fa82*/
        FFX_Phyre_SetMaterialColourFadeAlpha_WhiteRGB( /*0xa6fa8b*/
          v20,
          ____PATH_SIDE_OP__0x1000______Efeitos_secundarios_com_alpha_bleh,
          0.000099999997); // Threshold de fade: 0x7D frames, depois aplica fade branco via SetMaterialColourFadeAlpha_WhiteRGB
        return (int)(v96 + 4); /*0xa6faac*/
      }
    }
  }
  return (int)(v96 + 4); /*0xa6fa9c*/
}
/* Orphan comments:
Contador de frames para magic ID 0x2C6 (efeito com fade-in progressivo)
*/