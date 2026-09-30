// Jarvis 2026-06-23 docsweep: corrected from SetupSceneNode. Decompile walks material PParameterBuffer, finds "TextureSampler", and binds texture handles via FFX_Phyre_BindTextureHandleToShaderParam; not a PNode setup hook.
// FFX FieldMap: Bind material texture sampler
void __fastcall FFX_FieldMap_BindMaterialTextureSampler(FFX_System_Host *host, int materialIndex)
{
  _DWORD *v2; // edx
  int v3; // ecx
  int v4; // esi
  int host__1; // edi
  _DWORD *host__2; // ebx
  _DWORD *v7; // ecx
  int ShaderParamDefinitionByName; // eax
  int ShaderParamDefinitionByName_1; // ecx
  unsigned int n4; // edx
  _DWORD *v11; // eax
  int *v12; // ecx
  int v13; // eax
  FFX_System_Host *host_2; // edx
  char *v15; // eax
  bool v16; // zf
  int host_; // [esp+4h] [ebp-2Ch] BYREF
  _DWORD *host__3; // [esp+8h] [ebp-28h]
  int v19; // [esp+Ch] [ebp-24h]
  int v20; // [esp+10h] [ebp-20h]
  int v21; // [esp+14h] [ebp-1Ch]
  _DWORD *v22; // [esp+18h] [ebp-18h]
  int v23; // [esp+1Ch] [ebp-14h]
  PhyrePClassDescriptor *p_PClassDescriptor_PMaterial; // [esp+20h] [ebp-10h]
  int v25; // [esp+24h] [ebp-Ch]
  int ShaderParamDefinitionByName_2; // [esp+28h] [ebp-8h]
  FFX_System_Host *host_1; // [esp+2Ch] [ebp-4h]
  _DWORD *v28; // [esp+38h] [ebp+8h]
  char v29; // [esp+3Ch] [ebp+Ch]

  host_1 = host; // [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass. /*0x6f6d49*/
  v2 = (_DWORD *)(*v28 + 28); /*0x6f6d4e*/
  v3 = v2 != (_DWORD *)*v2 ? *v2 : 0;
  host_ = 0; /*0x6f6d5c*/
  v23 = v3; /*0x6f6d63*/
  host__3 = 0; /*0x6f6d69*/
  v19 = 0; /*0x6f6d70*/
  v20 = 0; /*0x6f6d77*/
  v21 = 0; /*0x6f6d7e*/
  v22 = v2; /*0x6f6d85*/
  p_PClassDescriptor_PMaterial = &PClassDescriptor_PMaterial; /*0x6f6d88*/
  FFX_FieldMap_WalkMaterialPParameterBufferMembers_structural((FFX_System_Host *)&host_); /*0x6f6d8f*/
  v4 = v20; /*0x6f6d94*/
  if ( v20 ) /*0x6f6d99*/
  {
    while ( 1 ) /*0x6f6da1*/
    {
      host__1 = host_; /*0x6f6da1*/
      host__2 = host__3; /*0x6f6da4*/
LABEL_3:
      v7 = *(_DWORD **)(host__1 + v21); /*0x6f6dba*/
      v25 = host__1 + v21; /*0x6f6dbc*/
      ShaderParamDefinitionByName = FFX_Phyre_FindShaderParamDefinitionByName(v7, "TextureSampler"); /*0x6f6dbf*/
      ShaderParamDefinitionByName_1 = ShaderParamDefinitionByName; /*0x6f6dc4*/
      ShaderParamDefinitionByName_2 = ShaderParamDefinitionByName; /*0x6f6dc6*/
      if ( ShaderParamDefinitionByName ) /*0x6f6dcb*/
        break; /*0x6f6dcb*/
LABEL_19:
      if ( v4 ) /*0x6f6e5b*/
      {
        while ( 1 ) /*0x6f6e60*/
        {
          host__1 += v19; /*0x6f6e60*/
          --v4; /*0x6f6e62*/
          host_ = host__1; /*0x6f6e63*/
          v20 = v4; /*0x6f6e66*/
          if ( host__2 != (_DWORD *)host__1 ) /*0x6f6e6b*/
            break; /*0x6f6e6b*/
          host__2 = (_DWORD *)*host__2; /*0x6f6e6d*/
          host__3 = host__2; /*0x6f6e6f*/
          if ( !v4 ) /*0x6f6e74*/
            goto LABEL_24; /*0x6f6e74*/
        }
        if ( v4 ) /*0x6f6e7a*/
          goto LABEL_3; /*0x6f6e7a*/
LABEL_24:
        FFX_StringMap_IterateGetLen_H(&host_); /*0x6f6e83*/
        v4 = v20; /*0x6f6e88*/
        if ( v20 ) /*0x6f6e8d*/
          continue; /*0x6f6e8d*/
      }
      return; /*0x6f6e8d*/
    }
    n4 = *(unsigned __int16 *)(ShaderParamDefinitionByName + 8); /*0x6f6dd1*/
    v11 = *(_DWORD **)(v25 + 4); /*0x6f6de2*/
    if ( n4 + (*(_WORD *)(ShaderParamDefinitionByName_1 + 10) & 0x1FFF) <= *v11 ) /*0x6f6dec*/
    {
      if ( n4 >= 4 ) /*0x6f6df5*/
        v12 = (_DWORD *)((char *)v11 + n4); /*0x6f6dfe*/
      else
        v12 = 0; /*0x6f6df7*/
    }
    else
    {
      v12 = 0; /*0x6f6dee*/
    }
    v13 = v12[2]; /*0x6f6e00*/
    host_2 = host_1; /*0x6f6e03*/
    if ( v13 ) /*0x6f6e08*/
    {
      if ( *(_BYTE *)(v13 + 2) == 2 ) /*0x6f6e0e*/
      {
        if ( *(_BYTE *)(v13 + 3) == 2 ) /*0x6f6e14*/
          v15 = &host_1->padD4[1028]; /*0x6f6e16*/
        else
          v15 = &host_1->padD4[1100]; /*0x6f6e1e*/
LABEL_16:
        v12[2] = (int)v15; /*0x6f6e38*/
        if ( v29 ) /*0x6f6e3f*/
          v12[2] = (int)&host_2->padD4[1028]; /*0x6f6e47*/
        FFX_Phyre_BindTextureHandleToShaderParam(*(_DWORD **)(v25 + 4), ShaderParamDefinitionByName_2, v12); /*0x6f6e54*/
        goto LABEL_19; /*0x6f6e54*/
      }
      v16 = *(_BYTE *)(v13 + 3) == 2; /*0x6f6e26*/
      v15 = &host_1->padD4[1064]; /*0x6f6e2a*/
      if ( v16 ) /*0x6f6e30*/
        goto LABEL_16; /*0x6f6e30*/
    }
    v15 = &host_1->padD4[992]; /*0x6f6e32*/
    goto LABEL_16; /*0x6f6e32*/
  }
}