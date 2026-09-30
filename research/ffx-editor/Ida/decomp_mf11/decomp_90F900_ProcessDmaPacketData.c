// FFX GS: Process DMA packet data
// GS (Graphics Synthesizer) DMA packet processor. Processes PS2 GS DMA packets for texture upload, vertex buffer expansion, palette upload. PS2 emulation layer for backward compatibility with PS2-era rendering code.
int __cdecl FFX_GS_ProcessDmaPacketData(_DWORD *yiBGRender, _DWORD *lpBuffer)
{
  _DWORD *yiBGRender_1; // esi
  _DWORD *lpBuffer_1; // ecx
  _DWORD *v4; // edi
  _DWORD *v5; // edx
  int v6; // edx
  int v7; // edx
  int v8; // eax
  _DWORD *v9; // edi
  unsigned int v10; // ecx
  int v11; // edi
  _DWORD *v12; // ecx
  void *hudContext; // edx
  FFX_CharacterId charId; // ecx
  void *hudContext_1; // edx
  FFX_CharacterId charId_1; // ecx
  void *hudContext_2; // edx
  FFX_CharacterId charId_2; // ecx
  int v19; // ecx
  int v20; // eax
  int v21; // edx
  int v22; // ecx
  int v23; // edx
  _DWORD *v24; // eax
  int v25; // ecx
  int v28; // [esp+14h] [ebp-8Ch]
  int v29; // [esp+1Ch] [ebp-84h]
  int v30; // [esp+20h] [ebp-80h]
  _DWORD *v31; // [esp+24h] [ebp-7Ch]
  int v32; // [esp+24h] [ebp-7Ch]
  int v33; // [esp+28h] [ebp-78h]
  int v34; // [esp+28h] [ebp-78h]
  _DWORD *v35; // [esp+2Ch] [ebp-74h]

  yiBGRender_1 = yiBGRender; /*0x90f92a*/
  FFX_GS_WaitVif1DmaSyncAndDumpTimeout_structural(); /*0x90f934*/
  FFX_GenericStub_Return0(); /*0x90f93d*/
  lpBuffer_1 = lpBuffer; /*0x90f942*/
  v4 = lpBuffer + 16; /*0x90f94e*/
  if ( *lpBuffer == 2179941 && lpBuffer[1] == 272 ) /*0x90f95e*/
  {
    v30 = 0; /*0x90f968*/
    if ( lpBuffer[3] ) /*0x90f964*/
    {
      while ( 2 ) /*0x90f975*/
      {
        v5 = v4; /*0x90f975*/
        v4 += 16; /*0x90f977*/
        v35 = v5; /*0x90f97c*/
        switch ( *v5 ) /*0x90f988*/
        {
          case 0: /*0x90f988*/
            v28 = yiBGRender_1[106978]; /*0x90f9a9*/
            v30 = (int)&yiBGRender_1[45 * v28 + 106979]; /*0x90f9ac*/
            yiBGRender_1[106978] = v28 + 1; /*0x90f9af*/
            FFX_GS_InitSpriteStruct(v30); /*0x90f9b5*/
            FFX_GS_ReadDmaPacketHeader(v30, (int)v4); /*0x90f9be*/
            FFX_FieldEngine_TransformPosition(yiBGRender_1[106978] - 1, (float *)(v30 + 96)); /*0x90f9d2*/
            FFX_Field_VertexBuffer_ApplySkinning_impl_w( /*0x90f9ee*/
              yiBGRender_1[106978] - 1,
              (float *)(v30 + 80),
              *(_WORD *)(v30 + 134));
            v4 = (_DWORD *)((char *)v4 + v35[1]); /*0x90f9f9*/
            *(_DWORD *)(v30 + 172) = 0; /*0x90f9ff*/
            v29 = 0; /*0x90fa0b*/
            goto LABEL_41; /*0x90fa0e*/
          case 1: /*0x90f988*/
            v6 = 23 * yiBGRender_1[112739]++; /*0x90fa1b*/
            v7 = (int)&yiBGRender_1[v6 + 112740]; /*0x90fa2f*/
            *(_DWORD *)(v7 + 48) = 0; /*0x90fa32*/
            *(_WORD *)(v7 + 54) = 0; /*0x90fa35*/
            *(_DWORD *)(v7 + 72) = 0; /*0x90fa39*/
            *(_DWORD *)(v7 + 68) = 0; /*0x90fa3c*/
            *(_DWORD *)(v7 + 84) = 0; /*0x90fa3f*/
            *(_DWORD *)(v7 + 88) = 0; /*0x90fa42*/
            *(_DWORD *)(v7 + 76) = 0; /*0x90fa45*/
            *(_DWORD *)(v7 + 80) = 0; /*0x90fa48*/
            ++*(_DWORD *)(v30 + 172); /*0x90fa4f*/
            v33 = v7; /*0x90fa55*/
            FFX_GS_ReadSpriteCoords(v7, (int)v4); /*0x90fa58*/
            v8 = v29; /*0x90fa60*/
            v9 = v4 + 16; /*0x90fa63*/
            *(_DWORD *)(v33 + 68) = v9; /*0x90fa69*/
            v29 = v33; /*0x90fa6c*/
            if ( v8 ) /*0x90fa71*/
            {
              *(_DWORD *)(v8 + 76) = v33; /*0x90fa85*/
              *(_DWORD *)(v33 + 80) = v8; /*0x90fa88*/
            }
            else
            {
              *(_DWORD *)(v30 + 168) = v33; /*0x90fa76*/
              *(_DWORD *)(v33 + 80) = 0; /*0x90fa7c*/
            }
            *(_WORD *)(v33 + 52) = v28; /*0x90fa8e*/
            *(_DWORD *)(v33 + 84) = 0; /*0x90fa95*/
            v10 = (unsigned int)(v35[1] - 64) >> 4; /*0x90faa2*/
            v4 = &v9[4 * v10]; /*0x90faaa*/
            if ( *(_DWORD *)(v33 + 72) == v10 ) /*0x90faaf*/
              goto LABEL_41; /*0x90faaf*/
            return 0; /*0x90faaf*/
          case 2: /*0x90f988*/
            v11 = (int)(v4 + 15); /*0x90fac0*/
            v12 = &yiBGRender_1[9 * yiBGRender_1[159846] + 159847]; /*0x90facc*/
            *v12 = *(_DWORD *)(v11 - 60); /*0x90fad2*/
            v12[1] = *(_DWORD *)(v11 - 56); /*0x90fad7*/
            v12[2] = *(_DWORD *)(v11 - 52); /*0x90fadd*/
            v12[3] = *(_DWORD *)(v11 - 48); /*0x90fae3*/
            v12[4] = *(_DWORD *)(v11 - 44); /*0x90fae9*/
            v12[5] = *(_DWORD *)(v11 - 40); /*0x90faef*/
            v31 = v12; /*0x90faf5*/
            v12[8] = *(_DWORD *)(v11 - 4); /*0x90faf8*/
            FFX_GS_WaitVif1DmaSyncAndDumpTimeout_structural(); /*0x90fafb*/
            FFX_GenericStub_Return0(); /*0x90fb04*/
            FFX_DmaTextureStub_Return0_B(); /*0x90fb50*/
            if ( v31[1] < 0x3C00u ) /*0x90fb62*/
            {
              FFX_GenericStub_Return0(); /*0x90fb75*/
              FlushCache(); /*0x90fb7c*/
              FFX_DmaTextureStub_Return0(); /*0x90fb86*/
            }
            else
            {
              FFX_GS_ProcessTextureDmaPacket((int)yiBGRender_1, v31, v11); /*0x90fb67*/
            }
            v4 = (_DWORD *)(v35[1] - 60 + v11); /*0x90fb97*/
            ++yiBGRender_1[159846]; /*0x90fb99*/
            goto LABEL_41; /*0x90fb9f*/
          case 3: /*0x90f988*/
            switch ( v5[9] ) /*0x90fbaa*/
            {
              case 2: /*0x90fbaa*/
                yiBGRender_1[106440] = 2; /*0x90fbca*/
                break;
              case 3: /*0x90fbaa*/
                yiBGRender_1[106440] = 3; /*0x90fbbe*/
                break;
              case 4: /*0x90fbaa*/
                yiBGRender_1[106440] = 4; /*0x90fbb2*/
                break;
              default:
                goto LABEL_22; /*0x90fbb0*/
            }
            FFX_GS_UploadPaletteToGsMem(yiBGRender_1, v4, 72); /*0x90fbd8*/
            v5 = v35; /*0x90fbdd*/
            lpBuffer_1 = lpBuffer; /*0x90fbe0*/
LABEL_22:
            v4 = (_DWORD *)((char *)v4 + v5[1]); /*0x90fbe6*/
            goto LABEL_42; /*0x90fbe9*/
          case 4: /*0x90f988*/
            FFX_GS_ReadSceneLightingState((int)yiBGRender_1, (int)v4); /*0x90fbf0*/
            FFX_BtlUI_HudParty_GetElement(charId, hudContext); /*0x90fbfc*/
            FFX_BtlUI_HudParty_GetAnimState(charId_1, hudContext_1); /*0x90fc24*/
            FFX_BtlUI_HudParty_SetAnimState(charId_2, hudContext_2, (int)(yiBGRender_1 + 106526)); /*0x90fc4c*/
            yiBGRender_1 = yiBGRender; /*0x90fc51*/
            goto LABEL_40; /*0x90fc57*/
          case 5: /*0x90f988*/
            if ( v5[8] ) /*0x90fc5c*/
            {
              yiBGRender_1[v5[9] + 161073] = v4; /*0x90fc65*/
              yiBGRender_1[v5[9] + 161201] = v5[10]; /*0x90fc72*/
              ++yiBGRender_1[161072]; /*0x90fc79*/
              v4 = (_DWORD *)((char *)v4 + v5[1]); /*0x90fc7f*/
              goto LABEL_41; /*0x90fc82*/
            }
            yiBGRender_1[yiBGRender_1[161072] + 161073] = v4; /*0x90fc8d*/
            v19 = v5[1] >> 7; /*0x90fc97*/
            goto LABEL_27; /*0x90fc97*/
          case 6: /*0x90f988*/
            if ( yiBGRender_1[161393] <= *v4 ) /*0x90fcfd*/
              yiBGRender_1[161393] = *v4 + 1; /*0x90fd00*/
            v20 = 456 * *v4; /*0x90fd08*/
            v21 = yiBGRender_1[v20 + 161401]; /*0x90fd0e*/
            v22 = 7 * v21; /*0x90fd20*/
            v32 = 7 * v21; /*0x90fd23*/
            yiBGRender_1[v20 + 161402 + v22] = 0; /*0x90fd26*/
            v34 = v21; /*0x90fd3b*/
            v23 = 7 * v21; /*0x90fd3e*/
            yiBGRender_1[456 * *v4 + 161403 + v22] = 0; /*0x90fd41*/
            yiBGRender_1[456 * *v4 + 161405 + v23] = v4[6]; /*0x90fd59*/
            yiBGRender_1[456 * *v4 + 161404 + v23] = v4 + 16; /*0x90fd6d*/
            v24 = &yiBGRender_1[456 * *v4]; /*0x90fd7c*/
            if ( v4[9] ) /*0x90fd7e*/
            {
              LOWORD(v24[v23 + 161408]) = 4 * *((_WORD *)v4 + 18); /*0x90fd90*/
              yiBGRender_1[456 * *v4 + 161406 + 7 * v34] = &v4[4 * v4[6] + 16]; /*0x90fdbe*/
              LOWORD(yiBGRender_1[456 * *v4 + 161407 + v32]) = *((_WORD *)v4 + 14); /*0x90fdd2*/
              HIWORD(yiBGRender_1[456 * *v4 + 161407 + v32]) = *((_WORD *)v4 + 16); /*0x90fde8*/
              HIWORD(yiBGRender_1[456 * *v4 + 161408 + v32]) = *((_WORD *)v4 + 20); /*0x90fdfe*/
            }
            else
            {
              LOWORD(v24[v32 + 161408]) = 0; /*0x90fe0d*/
              yiBGRender_1[456 * *v4 + 161406 + 7 * v34] = 0; /*0x90fe30*/
              LOWORD(yiBGRender_1[456 * *v4 + 161407 + v32]) = 0; /*0x90fe40*/
              HIWORD(yiBGRender_1[456 * *v4 + 161407 + v32]) = 0; /*0x90fe52*/
              HIWORD(yiBGRender_1[456 * *v4 + 161408 + v32]) = 0; /*0x90fe64*/
            }
            v5 = v35; /*0x90fe6e*/
            ++yiBGRender_1[456 * *v4 + 161401]; /*0x90fe77*/
            v25 = v4[1]; /*0x90fe7e*/
            if ( !v25 ) /*0x90fe83*/
              goto LABEL_28; /*0x90fe83*/
            yiBGRender_1[456 * *v4 + 161396] = v25; /*0x90fe91*/
            yiBGRender_1[456 * *v4 + 161397] = v4[2]; /*0x90fea3*/
            yiBGRender_1[456 * *v4 + 161398] = v4[3]; /*0x90feb5*/
            yiBGRender_1[456 * *v4 + 161399] = v4[4]; /*0x90fec7*/
            yiBGRender_1[456 * *v4 + 161400] = v4[5]; /*0x90fed9*/
            v4 = (_DWORD *)((char *)v4 + v35[1]); /*0x90fee0*/
            goto LABEL_41; /*0x90fee3*/
          case 7: /*0x90f988*/
            FFX_GS_CopyMatrixData((int)yiBGRender_1, (int)v4); /*0x90fee7*/
LABEL_40:
            v4 = (_DWORD *)((char *)v4 + v35[1]); /*0x90feef*/
            goto LABEL_41; /*0x90fef2*/
          case 8: /*0x90f988*/
            if ( v5[8] ) /*0x90fcb5*/
            {
              yiBGRender_1[v5[9] + 161137] = v4; /*0x90fcbe*/
              yiBGRender_1[v5[9] + 161201] = v5[10]; /*0x90fccb*/
              ++yiBGRender_1[161072]; /*0x90fcd2*/
              v4 = (_DWORD *)((char *)v4 + v5[1]); /*0x90fcd8*/
            }
            else
            {
              yiBGRender_1[yiBGRender_1[161072] + 161137] = v4; /*0x90fce6*/
              v19 = v5[1] >> 5; /*0x90fcf0*/
LABEL_27:
              yiBGRender_1[yiBGRender_1[161072]++ + 161201] = v19; /*0x90fc9a*/
LABEL_28:
              v4 = (_DWORD *)((char *)v4 + v5[1]); /*0x90fcad*/
            }
LABEL_41:
            lpBuffer_1 = lpBuffer; /*0x90fef5*/
LABEL_42:
            if ( lpBuffer_1[3]-- == 1 ) /*0x90fef8*/
              return 0; /*0x90fefb*/
            continue; /*0x90fefb*/
          default:
            goto LABEL_42;
        }
      }
    }
  }
  return 0; /*0x90ff12*/
}