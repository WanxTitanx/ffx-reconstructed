============================== 0x684E70 ==============================
// Jarvis goal 2026-06-25: core Menu2D capture context resolver; called by FFX_Menu2D_ResolveCaptureCtx.
// FFX Menu2D: Resolve capture context core
void *__cdecl FFX_Menu2D_ResolveCaptureCtxCore(int Str, const char *n4, int a3)
{
  int *v3; // ecx
  int *v4; // esi
  void *result; // eax
  void *v6; // eax
  void *IsVisible; // eax

  v4 = v3; /*0x684e77*/
  switch ( (unsigned int)n4 ) /*0x684e82*/
  {
    case 0u: /*0x684e82*/
      result = (void *)v3[34]; /*0x684e89*/
      break; /*0x684e91*/
    case 1u: /*0x684e82*/
      result = (void *)v3[35]; /*0x684e94*/
      break; /*0x684e9c*/
    case 2u: /*0x684e82*/
      result = (void *)v3[36]; /*0x684e9f*/
      break; /*0x684ea7*/
    case 3u: /*0x684e82*/
      result = (void *)v3[37]; /*0x684eaa*/
      break; /*0x684eb2*/
    case 4u: /*0x684e82*/
      if ( v3[1] <= 0 ) /*0x684eb9*/
        result = (void *)v3[38]; /*0x684ec6*/
      else
        result = (void *)v3[44]; /*0x684ebb*/
      break; /*0x684ec3*/
    case 5u: /*0x684e82*/
      if ( v3[1] <= 0 ) /*0x684ed5*/
        result = (void *)v3[40]; /*0x684ee2*/
      else
        result = (void *)v3[46]; /*0x684ed7*/
      break; /*0x684edf*/
    case 6u: /*0x684e82*/
    case 0xBu: /*0x684e82*/
      if ( v3[1] <= 0 ) /*0x684ef5*/
      {
        if ( Str /*0x684f50*/
          && (IsVisible = (void *)FFX_BtlUI_HudBar_IsVisible(), FFX_BtlUI_HudIcon_GetSize(IsVisible))
          && strstr((const char *)Str, "pad_icon") )
        {
          result = (void *)v4[43]; /*0x684f5d*/
        }
        else
        {
          result = (void *)v4[41]; /*0x684f69*/
        }
      }
      else if ( Str /*0x684f11*/
             && (v6 = (void *)FFX_BtlUI_HudBar_IsVisible(), FFX_BtlUI_HudIcon_GetSize(v6))
             && strstr((const char *)Str, "pad_icon") )
      {
        result = (void *)v4[49]; /*0x684f1e*/
      }
      else
      {
        result = (void *)v4[47]; /*0x684f2a*/
      }
      break; /*0x684f27*/
    case 7u: /*0x684e82*/
      result = (void *)v3[50]; /*0x684f75*/
      break; /*0x684f7d*/
    case 8u: /*0x684e82*/
      result = (void *)v3[51]; /*0x684f80*/
      break; /*0x684f88*/
    case 9u: /*0x684e82*/
      if ( v3[2] <= 0 ) /*0x684f8f*/
        result = (void *)v3[52]; /*0x684f9c*/
      else
        result = (void *)v3[54]; /*0x684f91*/
      break; /*0x684f99*/
    case 0xAu: /*0x684e82*/
      result = (void *)v3[56]; /*0x684fa7*/
      break; /*0x684faf*/
    case 0xCu: /*0x684e82*/
      if ( v3[2] <= 0 ) /*0x684fb6*/
        result = (void *)v3[53]; /*0x684fc3*/
      else
        result = (void *)v3[55]; /*0x684fb8*/
      break; /*0x684fc0*/
    case 0xDu: /*0x684e82*/
      if ( v3[1] <= 0 ) /*0x684fd2*/
        result = (void *)v3[39]; /*0x684fdf*/
      else
        result = (void *)v3[45]; /*0x684fd4*/
      break; /*0x684fdc*/
    case 0xEu: /*0x684e82*/
      if ( v3[1] <= 0 ) /*0x684fee*/
        result = (void *)v3[42]; /*0x684ffb*/
      else
        result = (void *)v3[48]; /*0x684ff0*/
      break; /*0x684ff8*/
    default:
      result = 0; /*0x685006*/
      break; /*0x685006*/
  }
  return result; /*0x684e8f*/
}
============================== 0x67BC00 ==============================
// ResolveTextureNameForUI — resolves a texture name for UI use
int __thiscall ResolveTextureNameForUI(int this, char *Str, int n10)
{
  int this_1; // esi
  int v4; // eax
  int v5; // edi
  char *Str_1; // ebx
  unsigned int n6_1; // edi
  unsigned int v9; // ecx
  unsigned int v10; // eax
  int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  int v14; // edi
  int v15; // edi
  unsigned int v16; // ecx
  unsigned int v17; // eax
  int v18; // edi
  int v19; // eax
  int v20; // eax
  unsigned int v21; // ecx
  int v22; // ecx
  int v23; // edi
  unsigned int n0xC_1; // edx
  int v25; // edi
  unsigned int v26; // edx
  unsigned int v27; // eax
  int v28; // ecx
  int v29; // edx
  unsigned int n6; // edi
  int v31; // eax
  int v32; // edi
  int v33; // edi
  int v34; // edi
  int v35; // eax
  unsigned int v36; // ecx
  int v37; // ecx
  int v38; // edi
  unsigned int n0xC; // edx
  int v40; // edi

  this_1 = this; /*0x67bc05*/
  v4 = *(_DWORD *)(this + 23420); /*0x67bc08*/
  v5 = 0; /*0x67bc0e*/
  if ( !v4 )
  {
    if ( n10 == 1 || n10 == 10 || n10 == 2 ) /*0x67bf76*/
    {
      if ( *(_DWORD *)(this + 22596) ) /*0x67c1a7*/
      {
        FFX_Scene_UpdateVertexBuffer((_DWORD *)this, 0); /*0x67c1b1*/
        *(_DWORD *)(this_1 + 22596) = 0; /*0x67c1b6*/
      }
      *(_DWORD *)(this_1 + 23432) = "Unitialized TextureName"; /*0x67c1c0*/
      return ResolveTexture_PopEntry((unsigned int *)this_1, 0); /*0x67c1ca*/
    }
    Str_1 = Str; /*0x67bf83*/
    if ( *(_DWORD *)(this + 23436) == 1 ) /*0x67bf86*/
    {
      n6 = *(_DWORD *)(this + 22596); /*0x67bf8c*/
      if ( !n6 ) /*0x67bf94*/
      {
        n6_1 = ResolveTexture_PopEntry_0(this, 0); /*0x67bf9c*/
LABEL_44:
        FFX_PS3_SetUITextureSlot((int *)this_1, 0, (int)Str_1); /*0x67bf9e*/
        ++*(_DWORD *)(this_1 + 22596); /*0x67bfa8*/
        *(_DWORD *)(this_1 + 23432) = Str_1; /*0x67bfb1*/
        return n6_1; /*0x67bfba*/
      }
      if ( n6 < 6 ) /*0x67bfc0*/
      {
        v31 = FFX_Texture_FindInTextureTable((unsigned int *)this, Str); /*0x67bfc3*/
        if ( v31 == -1 ) /*0x67bfcd*/
        {
          v32 = ResolveTexture_PopEntry_0(this_1, 0); /*0x67bfe1*/
          FFX_PS3_SetUITextureSlot((int *)this_1, *(_DWORD *)(this_1 + 22596), (int)Str); /*0x67bfe3*/
          ++*(_DWORD *)(this_1 + 22596); /*0x67bfe8*/
          *(_DWORD *)(this_1 + 23432) = Str; /*0x67bff1*/
          return v32; /*0x67bffa*/
        }
        if ( FontShadowSonNums[v31] < 12 ) /*0x67c005*/
        {
          v33 = *(_DWORD *)(*(_DWORD *)(this_1 + 5612) + 4 * (v31 + *(_DWORD *)(this_1 + 11260) - n6)); /*0x67c017*/
          ++FontShadowSonNums[v31]; /*0x67c01a*/
          *(_DWORD *)(this_1 + 23432) = Str; /*0x67c024*/
          return v33; /*0x67c02d*/
        }
        this = this_1; /*0x67c030*/
      }
      FFX_Scene_UpdateVertexBuffer((_DWORD *)this, 0); /*0x67c034*/
      v34 = ResolveTexture_PopEntry_0(this_1, 0); /*0x67c047*/
      FFX_PS3_SetUITextureSlot((int *)this_1, 0, (int)Str); /*0x67c049*/
      *(_DWORD *)(this_1 + 23432) = Str; /*0x67c051*/
      *(_DWORD *)(this_1 + 22596) = 1; /*0x67c057*/
      return v34; /*0x67c064*/
    }
    if ( *(_DWORD *)(this + 22596) )
    {
      FFX_Scene_UpdateVertexBuffer((_DWORD *)this, 0); /*0x67c071*/
      *(_DWORD *)(this_1 + 22596) = 0; /*0x67c076*/
    }
    else
    {
      v35 = strcmp(*(const char **)(this + 23432), Str); /*0x67c0b4*/
      if ( v35 )
        v35 = v35 < 0 ? -1 : 1;
      if ( !v35 ) /*0x67c0d7*/
      {
        if ( *(_BYTE *)(this_1 + 23412) == 1 ) /*0x67c0e0*/
        {
          v36 = *(_DWORD *)(this_1 + 11260); /*0x67c0ec*/
          if ( v36 < (*(_DWORD *)(this_1 + 5608) & 0x7FFFFFFFu) ) /*0x67c0f9*/
          {
            FFX_Shader_CopyAndClearSourceState( /*0x67c110*/
              *(_DWORD *)(this_1 + 4 * *(_DWORD *)(this_1 + 11344) - 4),
              *(_DWORD *)(*(_DWORD *)(this_1 + 5612) + 4 * v36));
            *(_DWORD *)(this_1 + 4 * *(_DWORD *)(this_1 + 11344) - 4) = *(_DWORD *)(*(_DWORD *)(this_1 + 5612) /*0x67c12a*/
                                                                                  + 4 * *(_DWORD *)(this_1 + 11260));
            v37 = *(_DWORD *)(this_1 + 11260); /*0x67c12e*/
            v38 = *(_DWORD *)(*(_DWORD *)(this_1 + 5612) + 4 * v37); /*0x67c13a*/
            --*(_DWORD *)(this_1 + 11256); /*0x67c13d*/
            *(_DWORD *)(this_1 + 23416) += 2; /*0x67c143*/
            *(_DWORD *)(this_1 + 11260) = v37 + 1; /*0x67c14d*/
            *(_DWORD *)(this_1 + 23432) = Str; /*0x67c156*/
            *(_BYTE *)(this_1 + 23412) = 0; /*0x67c15c*/
            return v38; /*0x67c166*/
          }
LABEL_56:
          *(_DWORD *)(this_1 + 23432) = Str_1; /*0x67c098*/
          return v5; /*0x67c0a4*/
        }
        n0xC = *(_DWORD *)(this_1 + 23416); /*0x67c169*/
        if ( n0xC < 0xC ) /*0x67c172*/
        {
          v40 = *(_DWORD *)(*(_DWORD *)(this_1 + 5612) + 4 * *(_DWORD *)(this_1 + 11260) - 4); /*0x67c184*/
          *(_DWORD *)(this_1 + 23416) = n0xC + 1; /*0x67c18b*/
          *(_DWORD *)(this_1 + 23432) = Str; /*0x67c194*/
          *(_BYTE *)(this_1 + 23412) = 0; /*0x67c19a*/
          return v40; /*0x67c1a4*/
        }
      }
    }
    v19 = ResolveTexture_PopEntry((unsigned int *)this_1, 0); /*0x67c080*/
LABEL_55:
    v5 = v19; /*0x67c085*/
    *(_BYTE *)(this_1 + 23412) = 1; /*0x67c087*/
    *(_DWORD *)(this_1 + 23416) = 1; /*0x67c08e*/
    goto LABEL_56; /*0x67c08e*/
  }
  if ( v4 != 1 ) /*0x67bc19*/
    return 0; /*0x67bc21*/
  if ( n10 == 1 || n10 == 10 || n10 == 2 ) /*0x67bc3c*/
  {
    if ( *(_DWORD *)(this + 22596) ) /*0x67bee1*/
    {
      FFX_Scene_UpdateVertexBuffer((_DWORD *)this, 1); /*0x67beeb*/
      *(_DWORD *)(this_1 + 22596) = 0; /*0x67bef0*/
    }
    v26 = *(_DWORD *)(this_1 + 22584); /*0x67befc*/
    v27 = *(_DWORD *)(this_1 + 16952) & 0x7FFFFFFF; /*0x67bf02*/
    *(_DWORD *)(this_1 + 23432) = "Unitialized TextureName"; /*0x67bf07*/
    if ( v26 >= v27 ) /*0x67bf13*/
      return n10; /*0x67bf57*/
    *(_DWORD *)(this_1 + 4 * *(_DWORD *)(this_1 + 22592) + 11352) = *(_DWORD *)(*(_DWORD *)(this_1 + 16956) + 4 * v26); /*0x67bf24*/
    v28 = *(_DWORD *)(this_1 + 22584); /*0x67bf2b*/
    v29 = *(_DWORD *)(*(_DWORD *)(this_1 + 16956) + 4 * v28); /*0x67bf38*/
    ++*(_DWORD *)(this_1 + 22592); /*0x67bf3b*/
    *(_DWORD *)(this_1 + 22584) = v28 + 1; /*0x67bf44*/
    return v29; /*0x67bf4f*/
  }
  Str_1 = Str; /*0x67bc49*/
  if ( *(_DWORD *)(this + 23436) != 1 )
  {
    if ( *(_DWORD *)(this + 22596) )
    {
      FFX_Scene_UpdateVertexBuffer((_DWORD *)this, 1); /*0x67bdc5*/
      *(_DWORD *)(this_1 + 22596) = 0; /*0x67bdca*/
    }
    else
    {
      v20 = strcmp(*(const char **)(this + 23432), Str); /*0x67bde4*/
      if ( v20 )
        v20 = v20 < 0 ? -1 : 1;
      if ( !v20 ) /*0x67be07*/
      {
        if ( *(_BYTE *)(this_1 + 23412) == 1 ) /*0x67be10*/
        {
          v21 = *(_DWORD *)(this_1 + 22588); /*0x67be1c*/
          if ( v21 < (*(_DWORD *)(this_1 + 16960) & 0x7FFFFFFFu) ) /*0x67be29*/
          {
            FFX_Shader_CopyAndClearSourceState( /*0x67be47*/
              *(_DWORD *)(this_1 + 4 * *(_DWORD *)(this_1 + 22592) + 11348),
              *(_DWORD *)(*(_DWORD *)(this_1 + 16964) + 4 * v21));
            *(_DWORD *)(this_1 + 4 * *(_DWORD *)(this_1 + 22592) + 11348) = *(_DWORD *)(*(_DWORD *)(this_1 + 16964) /*0x67be61*/
                                                                                      + 4 * *(_DWORD *)(this_1 + 22588));
            v22 = *(_DWORD *)(this_1 + 22588); /*0x67be68*/
            v23 = *(_DWORD *)(*(_DWORD *)(this_1 + 16964) + 4 * v22); /*0x67be74*/
            --*(_DWORD *)(this_1 + 22584); /*0x67be77*/
            *(_DWORD *)(this_1 + 23416) += 2; /*0x67be7d*/
            *(_DWORD *)(this_1 + 22588) = v22 + 1; /*0x67be87*/
            *(_DWORD *)(this_1 + 23432) = Str; /*0x67be90*/
            *(_BYTE *)(this_1 + 23412) = 0; /*0x67be96*/
            return v23; /*0x67bea0*/
          }
          goto LABEL_56; /*0x67be29*/
        }
        n0xC_1 = *(_DWORD *)(this_1 + 23416); /*0x67bea3*/
        if ( n0xC_1 < 0xC ) /*0x67beac*/
        {
          v25 = *(_DWORD *)(*(_DWORD *)(this_1 + 16964) + 4 * *(_DWORD *)(this_1 + 22588) - 4); /*0x67bebe*/
          *(_DWORD *)(this_1 + 23416) = n0xC_1 + 1; /*0x67bec5*/
          *(_DWORD *)(this_1 + 23432) = Str; /*0x67bece*/
          *(_BYTE *)(this_1 + 23412) = 0; /*0x67bed4*/
          return v25; /*0x67bede*/
        }
      }
    }
    v19 = ResolveTexture_PopEntry((unsigned int *)this_1, 1); /*0x67bdd2*/
    goto LABEL_55; /*0x67bdd2*/
  }
  n6_1 = *(_DWORD *)(this + 22596); /*0x67bc52*/
  if ( !n6_1 ) /*0x67bc5a*/
  {
    v9 = *(_DWORD *)(this + 22588); /*0x67bc62*/
    v10 = *(_DWORD *)(this_1 + 16960) & 0x7FFFFFFF; /*0x67bc68*/
    *(_BYTE *)(this_1 + 23412) = 0; /*0x67bc6d*/
    if ( v9 < v10 ) /*0x67bc76*/
    {
      n6_1 = *(_DWORD *)(*(_DWORD *)(this_1 + 16964) + 4 * v9); /*0x67bc82*/
      *(_DWORD *)(this_1 + 4 * *(_DWORD *)(this_1 + 22592) + 11352) = n6_1; /*0x67bc8b*/
      ++*(_DWORD *)(this_1 + 22588); /*0x67bc92*/
      ++*(_DWORD *)(this_1 + 22592); /*0x67bc98*/
    }
    goto LABEL_44; /*0x67bc9e*/
  }
  if ( n6_1 < 6 ) /*0x67bca6*/
  {
    v11 = FFX_Texture_FindInTextureTable((unsigned int *)this, Str); /*0x67bcad*/
    if ( v11 == -1 ) /*0x67bcb7*/
    {
      v12 = *(_DWORD *)(this_1 + 22588); /*0x67bcbf*/
      v13 = *(_DWORD *)(this_1 + 16960) & 0x7FFFFFFF; /*0x67bcc5*/
      v14 = 0; /*0x67bcca*/
      *(_BYTE *)(this_1 + 23412) = 0; /*0x67bccc*/
      if ( v12 < v13 ) /*0x67bcd5*/
      {
        v14 = *(_DWORD *)(*(_DWORD *)(this_1 + 16964) + 4 * v12); /*0x67bcdd*/
        *(_DWORD *)(this_1 + 4 * *(_DWORD *)(this_1 + 22592) + 11352) = v14; /*0x67bce6*/
        ++*(_DWORD *)(this_1 + 22588); /*0x67bced*/
        ++*(_DWORD *)(this_1 + 22592); /*0x67bcf3*/
      }
      FFX_PS3_SetUITextureSlot((int *)this_1, *(_DWORD *)(this_1 + 22596), (int)Str); /*0x67bd02*/
      ++*(_DWORD *)(this_1 + 22596); /*0x67bd07*/
      *(_DWORD *)(this_1 + 23432) = Str; /*0x67bd10*/
      return v14; /*0x67bd19*/
    }
    if ( FontShadowSonNums[v11] < 12 ) /*0x67bd24*/
    {
      v15 = *(_DWORD *)(*(_DWORD *)(this_1 + 16964) + 4 * (v11 + *(_DWORD *)(this_1 + 22588) - n6_1)); /*0x67bd36*/
      ++FontShadowSonNums[v11]; /*0x67bd39*/
      *(_DWORD *)(this_1 + 23432) = Str; /*0x67bd43*/
      return v15; /*0x67bd4c*/
    }
    this = this_1; /*0x67bd4f*/
  }
  FFX_Scene_UpdateVertexBuffer((_DWORD *)this, 1); /*0x67bd53*/
  v16 = *(_DWORD *)(this_1 + 22588); /*0x67bd5e*/
  v17 = *(_DWORD *)(this_1 + 16960) & 0x7FFFFFFF; /*0x67bd64*/
  v18 = 0; /*0x67bd69*/
  *(_BYTE *)(this_1 + 23412) = 0; /*0x67bd6b*/
  if ( v16 < v17 ) /*0x67bd74*/
  {
    v18 = *(_DWORD *)(*(_DWORD *)(this_1 + 16964) + 4 * v16); /*0x67bd7c*/
    *(_DWORD *)(this_1 + 4 * *(_DWORD *)(this_1 + 22592) + 11352) = v18; /*0x67bd85*/
    ++*(_DWORD *)(this_1 + 22588); /*0x67bd8c*/
    ++*(_DWORD *)(this_1 + 22592); /*0x67bd92*/
  }
  FFX_PS3_SetUITextureSlot((int *)this_1, 0, (int)Str); /*0x67bd9d*/
  *(_DWORD *)(this_1 + 23432) = Str; /*0x67bda5*/
  *(_DWORD *)(this_1 + 22596) = 1; /*0x67bdab*/
  return v18; /*0x67bc1b*/
}
