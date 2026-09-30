// FFX: Magic PPP builds drawable from opcode process cmd — PPP bytecode: build drawable from opcode
// FFX Magic: PPP build drawable from opcode process command
void __fastcall FFX_Magic_PPP_BuildDrawableFromOpcode_ProcessCmd(
        FFX_AtelPppOpcodeCategory category,
        void *pppContext,
        int cmd)
{
  int v3; // eax
  int v4; // edi
  unsigned int v5; // edx
  unsigned int v6; // esi
  unsigned __int8 *v7; // ebx
  unsigned int v8; // edi
  FFX_CharacterId charId; // ecx
  void *hudContext; // edx
  FFXMagicHost *host_1; // ecx
  __int16 *v12; // edi
  int n3240; // edx
  int v14; // esi
  int dst_1; // esi
  int v16; // eax
  int i_1; // edi
  float *v18; // ecx
  float *hudContext_1; // edx
  int n3; // ecx
  void *hudContext_2; // edx
  FFX_CharacterId charId_2; // ecx
  void *hudContext_3; // edx
  FFX_CharacterId charId_3; // ecx
  float *v25; // ecx
  int v26; // ecx
  const void *src; // esi
  float *charId_1; // [esp-10h] [ebp-8Ch]
  int v29; // [esp+8h] [ebp-74h]
  int dst; // [esp+Ch] [ebp-70h]
  float v31; // [esp+10h] [ebp-6Ch]
  float v32; // [esp+14h] [ebp-68h]
  float v33; // [esp+18h] [ebp-64h]
  float v34; // [esp+1Ch] [ebp-60h]
  __int16 *v35; // [esp+20h] [ebp-5Ch]
  float v36; // [esp+24h] [ebp-58h]
  FFXMagicHost *host; // [esp+28h] [ebp-54h]
  float v38; // [esp+2Ch] [ebp-50h]
  float v39; // [esp+30h] [ebp-4Ch]
  int i; // [esp+34h] [ebp-48h]
  float v41; // [esp+38h] [ebp-44h]
  int v42; // [esp+3Ch] [ebp-40h]
  float v43; // [esp+40h] [ebp-3Ch]
  int v44; // [esp+44h] [ebp-38h]
  float v45; // [esp+48h] [ebp-34h]
  int n3240_1; // [esp+4Ch] [ebp-30h]
  unsigned int v47; // [esp+50h] [ebp-2Ch]
  int v48; // [esp+50h] [ebp-2Ch]
  int v49; // [esp+58h] [ebp-24h]
  int v50; // [esp+5Ch] [ebp-20h]
  float v51; // [esp+64h] [ebp-18h]
  float v52; // [esp+64h] [ebp-18h]
  float v53; // [esp+64h] [ebp-18h]
  float v54; // [esp+64h] [ebp-18h]
  float v55; // [esp+64h] [ebp-18h]
  float v56; // [esp+64h] [ebp-18h]
  float v57; // [esp+64h] [ebp-18h]
  float v58; // [esp+64h] [ebp-18h]
  float v59; // [esp+64h] [ebp-18h]
  int v60; // [esp+64h] [ebp-18h]
  unsigned int n11_4; // [esp+88h] [ebp+Ch]
  int v62; // [esp+8Ch] [ebp+10h]
  int v63; // [esp+90h] [ebp+14h]

  v31 = 0.0; /*0x71d62c*/
  v32 = 0.0; /*0x71d632*/
  v33 = 0.0; /*0x71d638*/
  v34 = 0.0; /*0x71d63b*/
  v43 = 3.4028235e38; /*0x71d644*/
  v41 = 3.4028235e38; /*0x71d647*/
  v39 = 3.4028235e38; /*0x71d64a*/
  v45 = -3.4028235e38; /*0x71d653*/
  v36 = -3.4028235e38; /*0x71d656*/
  v38 = -3.4028235e38; /*0x71d659*/
  dst = FFX_TextureSlot_FindOrCacheByKeyExProxy(__SPAIR64__(n11_4, cmd)); /*0x71d664*/
  if ( dst ) /*0x71d669*/
  {
    v3 = Std_IdentityFunc(*(_DWORD *)(v62 + 28)); /*0x71d67f*/
    v4 = v3 + *(_DWORD *)(v3 + 4); /*0x71d697*/
    host = (FFXMagicHost *)*(__int16 *)(v3 + 16); /*0x71d699*/
    v5 = *(_DWORD *)(v4 + 12); /*0x71d69f*/
    v6 = *(_DWORD *)(v4 + 8); /*0x71d6a9*/
    v29 = v3 + *(_DWORD *)(v3 + 8); /*0x71d6ac*/
    v35 = (__int16 *)v4; /*0x71d6be*/
    v7 = (unsigned __int8 *)(v4 + 16); /*0x71d6c1*/
    v8 = 1 << ((__PAIR64__(v5, v6) >> 26) & 0xF); /*0x71d6d2*/
    charId = (__PAIR64__(v5, v6) >> 30) & 0xF; /*0x71d6d4*/
    hudContext = (void *)(v5 >> 30); /*0x71d6e0*/
    flt_C3A48C = 0.0078125 / flt_C3A4C8; /*0x71d6e3*/
    v47 = 1 << charId; /*0x71d6e9*/
    if ( v63 ) /*0x71d6ee*/
    {
      FFX_BtlUI_HudParty_GetTarget(charId, hudContext); /*0x71d756*/
      v31 = (float)(((*(_DWORD *)(v63 + 16) % (v8 << 16)) >> 4) / v8); /*0x71d786*/
      v32 = (float)(((*(_DWORD *)(v63 + 20) % (v47 << 16)) >> 4) / v47); /*0x71d7af*/
      v33 = v31; /*0x71d7b5*/
      v34 = v32; /*0x71d7bb*/
    }
    host_1 = host; /*0x71d7be*/
    if ( (int)host <= 0 ) /*0x71d7c3*/
    {
LABEL_29:
      if ( v63 ) /*0x71dbc2*/
      {
        *(_DWORD *)(dst + 176) = *(_DWORD *)v63; /*0x71dbce*/
        qmemcpy((void *)dst, *(const void **)(v63 + 32), 0x40u); /*0x71dbe4*/
        FFX_Menu2D_ProjectNodeCoords_structural(dst, (int)src_6, dst); /*0x71dbe6*/
        *(float *)(dst + 12) = 0.0; /*0x71dbf3*/
        *(float *)(dst + 28) = 0.0; /*0x71dbf6*/
        *(float *)(dst + 44) = 0.0; /*0x71dbf9*/
        *(float *)(dst + 60) = 1.0; /*0x71dbfe*/
        src = *(const void **)(v63 + 68); /*0x71dc01*/
        if ( src ) /*0x71dc06*/
        {
          qmemcpy((void *)(dst + 64), src, 0x40u); /*0x71dc19*/
          FFX_Menu2D_ProjectNodeCoords_structural(dst + 64, (int)src_6, dst + 64); /*0x71dc1b*/
          *(_DWORD *)(dst + 128) = 1; /*0x71dc23*/
        }
        else
        {
          *(_DWORD *)(dst + 128) = 0; /*0x71dc42*/
        }
        *(float *)(dst + 152) = v43; /*0x71dc4f*/
        *(float *)(dst + 156) = v41; /*0x71dc58*/
        *(float *)(dst + 160) = v39; /*0x71dc61*/
        *(float *)(dst + 164) = v45; /*0x71dc6a*/
        *(float *)(dst + 168) = v36; /*0x71dc73*/
        *(float *)(dst + 172) = v38; /*0x71dc7c*/
      }
      FFX_TextureSlot_FindOrCacheAndRelease(__SPAIR64__(n11_4, cmd), 1); /*0x71dc8a*/
    }
    else
    {
      v12 = v35; /*0x71d7c9*/
      n3240 = 0; /*0x71d7cc*/
      v14 = 0; /*0x71d7ce*/
      while ( 1 ) /*0x71d7d0*/
      {
        n3240 += 108; /*0x71d7d0*/
        v49 = ++v14; /*0x71d7d4*/
        n3240_1 = n3240; /*0x71d7d7*/
        if ( n3240 >= 3240 ) /*0x71d7e0*/
          break; /*0x71d7e0*/
        if ( *((_BYTE *)v12 + 1) == 3 ) /*0x71d7ea*/
        {
          dst_1 = dst; /*0x71d7fc*/
          FFX_MagicHost_AllocPppParticleSlot(host_1); /*0x71d801*/
          if ( !v16 ) /*0x71d80b*/
            return; /*0x71d80b*/
          n3240 = n3240_1; /*0x71d811*/
          v48 = 0; /*0x71d816*/
          if ( v12[1] > 0 ) /*0x71d821*/
          {
            i_1 = 0; /*0x71d827*/
            v50 = 0; /*0x71d829*/
            v44 = 0; /*0x71d82c*/
            v42 = 0; /*0x71d82f*/
            for ( i = 0; ; i_1 = i ) /*0x71d832*/
            {
              v18 = (float *)(i_1 + *(_DWORD *)(n3240 + *(_DWORD *)(dst_1 + 148) - 96)); /*0x71d851*/
              hudContext_1 = v18 + 2; /*0x71d859*/
              v51 = (float)*(__int16 *)(v29 + 6 * *((unsigned __int16 *)v7 + 6)); /*0x71d866*/
              *v18 = v51; /*0x71d86c*/
              v52 = (float)*(__int16 *)(v29 + 6 * *((unsigned __int16 *)v7 + 6) + 2); /*0x71d880*/
              v18[1] = v52; /*0x71d886*/
              v53 = (float)*(__int16 *)(v29 + 6 * *((unsigned __int16 *)v7 + 6) + 4); /*0x71d89b*/
              v18[2] = v53; /*0x71d8a1*/
              v54 = (float)*(__int16 *)(v29 + 6 * *((unsigned __int16 *)v7 + 7)); /*0x71d8b4*/
              v18[3] = v54; /*0x71d8ba*/
              v55 = (float)*(__int16 *)(v29 + 6 * *((unsigned __int16 *)v7 + 7) + 2); /*0x71d8cf*/
              v18[4] = v55; /*0x71d8d5*/
              v56 = (float)*(__int16 *)(v29 + 6 * *((unsigned __int16 *)v7 + 7) + 4); /*0x71d8ea*/
              v18[5] = v56; /*0x71d8f0*/
              v57 = (float)*(__int16 *)(v29 + 6 * *((unsigned __int16 *)v7 + 8)); /*0x71d904*/
              v18[6] = v57; /*0x71d90a*/
              v58 = (float)*(__int16 *)(v29 + 6 * *((unsigned __int16 *)v7 + 8) + 2); /*0x71d91f*/
              v18[7] = v58; /*0x71d925*/
              v59 = (float)*(__int16 *)(v29 + 6 * *((unsigned __int16 *)v7 + 8) + 4); /*0x71d93a*/
              v18[8] = v59; /*0x71d940*/
              n3 = 3; /*0x71d943*/
              do /*0x71d9c6*/
              {
                if ( *(hudContext_1 - 2) < (double)v43 ) /*0x71d955*/
                  v43 = *(hudContext_1 - 2); /*0x71d95a*/
                if ( *(hudContext_1 - 1) < (double)v41 ) /*0x71d96a*/
                  v41 = *(hudContext_1 - 1); /*0x71d96f*/
                if ( *hudContext_1 < (double)v39 ) /*0x71d97e*/
                  v39 = *hudContext_1; /*0x71d982*/
                if ( *(hudContext_1 - 2) > (double)v45 ) /*0x71d992*/
                  v45 = *(hudContext_1 - 2); /*0x71d997*/
                if ( *(hudContext_1 - 1) > (double)v36 ) /*0x71d9a7*/
                  v36 = *(hudContext_1 - 1); /*0x71d9ac*/
                if ( *hudContext_1 > (double)v38 ) /*0x71d9bb*/
                  v38 = *hudContext_1; /*0x71d9bf*/
                hudContext_1 += 3; /*0x71d9c2*/
                --n3; /*0x71d9c5*/
              }
              while ( n3 ); /*0x71d9c6*/
              charId_1 = (float *)(v42 + *(_DWORD *)(n3240_1 + *(_DWORD *)(dst_1 + 148) - 88)); /*0x71d9de*/
              *charId_1 = (float)*v7; /*0x71d9e8*/
              charId_1[1] = (float)v7[1]; /*0x71d9f4*/
              charId_1[2] = (float)v7[2]; /*0x71da01*/
              charId_1[3] = 128.0; /*0x71da0a*/
              charId_1[4] = (float)v7[4]; /*0x71da17*/
              charId_1[5] = (float)v7[5]; /*0x71da23*/
              charId_1[6] = (float)v7[6]; /*0x71da30*/
              charId_1[7] = (float)v7[7]; /*0x71da3d*/
              charId_1[3] = 128.0; /*0x71da40*/
              charId_1[8] = (float)v7[8]; /*0x71da4d*/
              charId_1[9] = (float)v7[9]; /*0x71da59*/
              charId_1[10] = (float)v7[10]; /*0x71da66*/
              charId_1[11] = (float)v7[11]; /*0x71da78*/
              charId_1[3] = 128.0; /*0x71da7b*/
              FFX_BtlUI_HudParty_GetTarget((FFX_CharacterId)charId_1, hudContext_1); /*0x71da7e*/
              FFX_BtlUI_HudParty_GetTarget(charId_2, hudContext_2); /*0x71da89*/
              FFX_BtlUI_HudParty_GetTarget(charId_3, hudContext_3); /*0x71da94*/
              dst_1 = dst; /*0x71da99*/
              n3240 = n3240_1; /*0x71da9c*/
              v25 = (float *)(v44 + *(_DWORD *)(n3240_1 + *(_DWORD *)(dst + 148) - 84)); /*0x71dab0*/
              i += 36; /*0x71dacd*/
              v42 += 48; /*0x71dad3*/
              v44 += 24; /*0x71dad7*/
              *v25 = ((double)*((unsigned __int16 *)v7 + 10) + v31) * 0.000244140625; /*0x71dadb*/
              v60 = *((unsigned __int16 *)v7 + 11); /*0x71dae1*/
              v7 += 40; /*0x71dae4*/
              v25[1] = 1.0 - ((double)v60 + v32) * 0.000244140625; /*0x71dafd*/
              v25[2] = ((double)*((unsigned __int16 *)v7 - 8) + v33) * 0.000244140625; /*0x71db15*/
              v25[3] = 1.0 - ((double)*((unsigned __int16 *)v7 - 7) + v34) * 0.000244140625; /*0x71db2f*/
              v25[4] = ((double)*((unsigned __int16 *)v7 - 6) + v31) * 0.000244140625; /*0x71db47*/
              v25[5] = 1.0 - 0.000244140625 * ((double)*((unsigned __int16 *)v7 - 5) + v32); /*0x71db61*/
              v26 = *(_DWORD *)(n3240_1 + *(_DWORD *)(dst + 148) - 80); /*0x71db6a*/
              *(_WORD *)(v26 + 2 * v50 + 2) = v50 + 1; /*0x71db71*/
              *(_WORD *)(v26 + 2 * v50) = v50; /*0x71db79*/
              *(_WORD *)(v26 + 2 * v50 + 4) = v50 + 2; /*0x71db7d*/
              v50 += 3; /*0x71db88*/
              v12 = v35; /*0x71db8b*/
              if ( ++v48 >= v35[1] ) /*0x71db98*/
                break; /*0x71db98*/
            }
          }
          host_1 = host; /*0x71db9e*/
          v14 = v49; /*0x71dba1*/
        }
        host_1 = (FFXMagicHost *)((char *)host_1 - v12[1]); /*0x71dba8*/
        v12 = (__int16 *)v7; /*0x71dbaa*/
        v7 += 16; /*0x71dbac*/
        host = host_1; /*0x71dbaf*/
        v35 = v12; /*0x71dbb2*/
        if ( (int)host_1 <= 0 ) /*0x71dbb7*/
          goto LABEL_29; /*0x71dbb7*/
      }
    }
  }
}