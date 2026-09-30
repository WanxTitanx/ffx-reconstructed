// DrawUITextElement — draws a UI text element
void __cdecl DrawUITextElement(FFXMenu2DContext *ctx, char *text, float x, float y, int slot)
{
  int v5; // edi
  FFXMenu2DContext *ctx_1; // esi
  _DWORD *v7; // ebx
  unsigned int v8; // eax
  double v9; // st7
  double v10; // st6
  int n3; // edx
  int v12; // ecx
  double v13; // st1
  double v14; // rtt
  double v15; // st1
  double v16; // st7
  double v17; // st1
  double v18; // rt0
  double v19; // st1
  int v20; // eax
  double v21; // st1
  int v22; // edi
  double v23; // st6
  int v24; // ecx
  unsigned int v25; // edi
  int v26; // eax
  int v27; // ecx
  float v28; // [esp+4h] [ebp-28h]
  float v29; // [esp+4h] [ebp-28h]
  float v30; // [esp+4h] [ebp-28h]
  float v31; // [esp+4h] [ebp-28h]
  float v32; // [esp+4h] [ebp-28h]
  float v33; // [esp+4h] [ebp-28h]
  float v34; // [esp+4h] [ebp-28h]
  float v35; // [esp+4h] [ebp-28h]
  float v36; // [esp+4h] [ebp-28h]
  float v37; // [esp+4h] [ebp-28h]
  float v38; // [esp+8h] [ebp-24h]
  float v39; // [esp+8h] [ebp-24h]
  float v40; // [esp+8h] [ebp-24h]
  float v41; // [esp+8h] [ebp-24h]
  float v42; // [esp+Ch] [ebp-20h]
  float v43; // [esp+Ch] [ebp-20h]
  float v44; // [esp+Ch] [ebp-20h]
  float v45; // [esp+Ch] [ebp-20h]
  float v46; // [esp+Ch] [ebp-20h]
  float v47; // [esp+Ch] [ebp-20h]
  float v48; // [esp+10h] [ebp-1Ch]
  float m_pGeomSlot4; // [esp+10h] [ebp-1Ch]
  float v50; // [esp+10h] [ebp-1Ch]
  float m_pTexDesc4; // [esp+10h] [ebp-1Ch]
  float v52; // [esp+10h] [ebp-1Ch]
  float m_pGeomSlot5; // [esp+10h] [ebp-1Ch]
  float v54; // [esp+10h] [ebp-1Ch]
  float m_pTexDesc5; // [esp+10h] [ebp-1Ch]
  float v56; // [esp+10h] [ebp-1Ch]
  float m_pGeomSlot0; // [esp+10h] [ebp-1Ch]
  float v58; // [esp+10h] [ebp-1Ch]
  float m_pTexDesc0; // [esp+10h] [ebp-1Ch]
  float v60; // [esp+10h] [ebp-1Ch]
  float m_pGeomSlot1; // [esp+10h] [ebp-1Ch]
  float v62; // [esp+10h] [ebp-1Ch]
  float m_pTexDesc1; // [esp+10h] [ebp-1Ch]
  float v64; // [esp+10h] [ebp-1Ch]
  float v65; // [esp+10h] [ebp-1Ch]
  float v66; // [esp+14h] [ebp-18h]
  float v67; // [esp+18h] [ebp-14h]
  float v68; // [esp+1Ch] [ebp-10h]
  float v69; // [esp+20h] [ebp-Ch]
  FFXMenu2DTextureSlot *texSlot2; // [esp+24h] [ebp-8h]
  FFXMenu2DTextureSlot *texSlot2_1; // [esp+24h] [ebp-8h]
  FFXMenu2DTextureSlot *texSlot3; // [esp+28h] [ebp-4h]
  FFXMenu2DTextureSlot *texSlot3_1; // [esp+28h] [ebp-4h]

  v69 = 1.0; /*0x64081f*/
  v68 = 1.0; /*0x640822*/
  v67 = 1.0; /*0x640825*/
  v66 = 1.0; /*0x640828*/
  v48 = 1.0; /*0x64082b*/
  v42 = 1.0; /*0x64082e*/
  v38 = 1.0; /*0x640831*/
  v28 = 1.0; /*0x640834*/
  if ( gParticleDoNotRender ) /*0x640837*/
    return; /*0x640837*/
  if ( ptr_new_for_once_0 && ptr_new_for_once_0[1] < 2 ) /*0x64085d*/
  {
    ctx_1 = ctx; /*0x640863*/
    texSlot3 = ctx->texSlot3; /*0x640879*/
    v69 = (double)(unsigned __int8)HIBYTE(*(_QWORD *)&ctx->texSlot2) / 255.0; /*0x640898*/
    v68 = (double)BYTE2(texSlot3) / 255.0; /*0x6408ad*/
    v67 = (double)BYTE1(texSlot3) / 255.0; /*0x6408c2*/
    texSlot2 = ctx->texSlot2; /*0x6408d6*/
    v66 = (double)(unsigned __int8)texSlot3 * 2.0 / 255.0; /*0x6408e2*/
    v48 = (double)HIBYTE(texSlot2) / 255.0; /*0x6408f7*/
    v42 = (double)BYTE2(texSlot2) / 255.0; /*0x64090c*/
    v38 = (double)BYTE1(texSlot2) / 255.0; /*0x640921*/
    v28 = 2.0 * (double)(unsigned __int8)texSlot2 / 255.0; /*0x640935*/
    if ( slot >= 4 ) /*0x64093b*/
      v7 = (_DWORD *)(*((_DWORD *)FFX_Menu2D_ResolveCaptureCtxCore((int)text, (const char *)0xD, v5) + 37) /*0x640965*/
                    + 108 * (slot - 4));
    else
      v7 = (_DWORD *)(*((_DWORD *)FFX_Menu2D_ResolveCaptureCtxCore((int)text, (const char *)0xE, v5) + 37) + 108 * slot); /*0x64094a*/
  }
  else
  {
    ctx_1 = ctx; /*0x640970*/
    TransformUICoordinatesToScreen((int)ctx, 2); /*0x64097a*/
    if ( text ) /*0x64098f*/
    {
      v8 = ResolveTextureNameForUI((int)MEMORY[0xCCC81C], text, 0); /*0x640996*/
      if ( !v8 ) /*0x64099f*/
        return; /*0x64099f*/
      *(_DWORD *)(v8 + 188) = 1; /*0x6409a5*/
      texSlot3_1 = ctx->texSlot3; /*0x6409c2*/
      v9 = 255.0; /*0x6409e4*/
      v69 = (double)(unsigned __int8)HIBYTE(*(_QWORD *)&ctx->texSlot2) / 255.0; /*0x6409e6*/
      v68 = (double)BYTE2(texSlot3_1) / 255.0; /*0x6409fb*/
      v67 = (double)BYTE1(texSlot3_1) / 255.0; /*0x640a10*/
      texSlot2_1 = ctx->texSlot2; /*0x640a28*/
      v10 = 2.0; /*0x640a31*/
      v66 = (double)(unsigned __int8)texSlot3_1 * 2.0 / 255.0; /*0x640a38*/
      v48 = (double)HIBYTE(texSlot2_1) / 255.0; /*0x640a4d*/
      v42 = (double)BYTE2(texSlot2_1) / 255.0; /*0x640a62*/
      v38 = (double)BYTE1(texSlot2_1) / 255.0; /*0x640a77*/
      v7 = *(_DWORD **)(v8 + 148); /*0x640a83*/
      v7[8] = text; /*0x640a8b*/
      *v7 = 1; /*0x640a8e*/
      v28 = (double)(unsigned __int8)texSlot2_1 * 2.0 / 255.0; /*0x640a96*/
      goto LABEL_12; /*0x640a99*/
    }
    v7 = *(_DWORD **)(ResolveTextureNameForUI((int)MEMORY[0xCCC81C], "NoTexture", 0) + 148); /*0x640aa5*/
    v7[8] = "NoTexture"; /*0x640aab*/
    *v7 = 0; /*0x640ab2*/
  }
  v9 = 255.0; /*0x640ab8*/
  v10 = 2.0; /*0x640abe*/
LABEL_12:
  if ( v7 ) /*0x640ac6*/
  {
    n3 = 0; /*0x640adb*/
    v12 = 16 * v7[1]; /*0x640ae0*/
    v13 = v48; /*0x640ae7*/
    while ( 1 ) /*0x640af0*/
    {
      if ( !n3 || n3 == 3 ) /*0x640af5*/
      {
        m_pGeomSlot0 = (float)(int)ctx_1->m_pGeomSlot0; /*0x640b58*/
        v58 = m_pGeomSlot0 / v9; /*0x640b63*/
        *(float *)(v12 + v7[5]) = v58; /*0x640b69*/
        m_pTexDesc0 = (float)(int)ctx_1->m_pTexDesc0; /*0x640b6f*/
        v60 = m_pTexDesc0 / v9; /*0x640b7a*/
        *(float *)(v7[5] + v12 + 4) = v60; /*0x640b80*/
        m_pGeomSlot1 = (float)(int)ctx_1->m_pGeomSlot1; /*0x640b87*/
        v62 = m_pGeomSlot1 / v9; /*0x640b92*/
        *(float *)(v12 + v7[5] + 8) = v62; /*0x640b98*/
        m_pTexDesc1 = (float)(int)ctx_1->m_pTexDesc1; /*0x640b9f*/
        v18 = v13; /*0x640ba9*/
        v19 = m_pTexDesc1 * v10 / v9; /*0x640ba9*/
        v16 = v18; /*0x640ba9*/
        v64 = v19; /*0x640bab*/
        v17 = v64; /*0x640bae*/
      }
      else
      {
        m_pGeomSlot4 = (float)(int)ctx_1->m_pGeomSlot4; /*0x640afa*/
        v50 = m_pGeomSlot4 / v9; /*0x640b05*/
        *(float *)(v12 + v7[5]) = v50; /*0x640b0b*/
        m_pTexDesc4 = (float)(int)ctx_1->m_pTexDesc4; /*0x640b11*/
        v52 = m_pTexDesc4 / v9; /*0x640b1c*/
        *(float *)(v7[5] + v12 + 4) = v52; /*0x640b22*/
        m_pGeomSlot5 = (float)(int)ctx_1->m_pGeomSlot5; /*0x640b29*/
        v54 = m_pGeomSlot5 / v9; /*0x640b34*/
        *(float *)(v12 + v7[5] + 8) = v54; /*0x640b3a*/
        m_pTexDesc5 = (float)(int)ctx_1->m_pTexDesc5; /*0x640b41*/
        v14 = v13; /*0x640b4b*/
        v15 = m_pTexDesc5 * v10 / v9; /*0x640b4b*/
        v16 = v14; /*0x640b4b*/
        v56 = v15; /*0x640b4d*/
        v17 = v56; /*0x640b50*/
      }
      *(float *)(v12 + v7[5] + 12) = v17; /*0x640bb4*/
      if ( n3 == 2 || n3 == 3 ) /*0x640bc0*/
      {
        *(float *)(v7[5] + v12) = *(float *)(v7[5] + v12) * v69; /*0x640bfd*/
        *(float *)(v7[5] + v12 + 4) = *(float *)(v7[5] + v12 + 4) * v68; /*0x640c09*/
        *(float *)(v7[5] + v12 + 8) = v67 * *(float *)(v7[5] + v12 + 8); /*0x640c16*/
        v20 = v7[5]; /*0x640c1a*/
        v21 = *(float *)(v20 + v12 + 12) * v66; /*0x640c21*/
      }
      else
      {
        *(float *)(v7[5] + v12) = *(float *)(v7[5] + v12) * v16; /*0x640bca*/
        *(float *)(v7[5] + v12 + 4) = *(float *)(v7[5] + v12 + 4) * v42; /*0x640bd7*/
        *(float *)(v7[5] + v12 + 8) = v38 * *(float *)(v7[5] + v12 + 8); /*0x640be5*/
        v20 = v7[5]; /*0x640be9*/
        v21 = *(float *)(v20 + v12 + 12) * v28; /*0x640bf0*/
      }
      *(float *)(v20 + v12 + 12) = v21; /*0x640c23*/
      ++n3; /*0x640c27*/
      v12 += 16; /*0x640c2e*/
      if ( n3 >= 4 ) /*0x640c34*/
        break; /*0x640c34*/
      v13 = v16; /*0x640aec*/
      v9 = 255.0; /*0x640aec*/
    }
    v22 = 3 * v7[1]; /*0x640c43*/
    v29 = *(float *)&ctx_1->vfptr * 3.75 + x; /*0x640c59*/
    v30 = (float)(int)(v29 + 0.5); /*0x640c74*/
    v39 = *(float *)&ctx_1->m_pGeomSlot2 - *(float *)&ctx_1->vfptr; /*0x640c7c*/
    v23 = v30; /*0x640c91*/
    v31 = v39 * 2.596153736114502 + v30; /*0x640c93*/
    v40 = (float)(int)(v31 + 0.5); /*0x640ca6*/
    v32 = v23 - 960.0; /*0x640cb3*/
    v43 = *(float *)&ctx_1->highResFlag * 2.596153736114502 + y; /*0x640cc4*/
    v44 = (float)(int)(v43 + 0.5); /*0x640cd7*/
    v65 = v44 - 540.0; /*0x640ce7*/
    v41 = v40 - 960.0; /*0x640cf1*/
    v45 = 2.596153736114502 * *(float *)&ctx_1->m_pTexDesc2 + y; /*0x640cfb*/
    v46 = (float)(int)(v45 + 0.5); /*0x640d10*/
    v47 = v46 - 540.0; /*0x640d19*/
    *(float *)(v7[3] + 4 * v22) = v32; /*0x640d1f*/
    *(float *)(v7[3] + 4 * v22 + 4) = v47; /*0x640d28*/
    *(float *)(v7[3] + 4 * v22 + 8) = 1.0; /*0x640d31*/
    *(float *)(v7[3] + 4 * v22 + 12) = v41; /*0x640d3b*/
    *(float *)(v7[3] + 4 * v22 + 16) = v47; /*0x640d44*/
    *(float *)(v7
