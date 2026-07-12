// Function: sub_A182F0
// Address: 0xa182f0
// Size: 0x2aa
// Prototype: 

int __userpurge sub_A182F0@<eax>(_DWORD *a1@<ecx>, int a2@<ebx>, int a3@<edi>, int a4, int a5)
{
  int result; // eax
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  _DWORD *v10; // edx
  _DWORD *p_Size; // ecx
  int *v12; // ebx
  unsigned int v13; // eax
  int v14; // ecx
  _DWORD *v15; // edi
  int v16; // edi
  int v18; // [esp-8h] [ebp-Ch]
  int v19; // [esp-8h] [ebp-Ch]
  int v21; // [esp-4h] [ebp-8h]
  int v22; // [esp-4h] [ebp-8h]
  int v23; // [esp+10h] [ebp+Ch]

  if ( !a1[4023] || !a1[4024] || !a1[4025] )
    return 21;
  v7 = a1[4022];
  if ( v7 )
    sub_441310(v7);
  v8 = sub_4E6BA0(a4, 0, 0);
  v9 = a1[2];
  a1[4022] = v8;
  if ( v9 )
  {
    v10 = *(_DWORD **)(v8 + 4);
    p_Size = *(_DWORD **)(v9 + 4);
    if ( ((p_Size[2] ^ v10[2]) & 0x7FFFFFFF) == 0 )
      memcpy(v10, p_Size, *p_Size);
  }
  v12 = (int *)sub_4410E0(1, (int)&unk_C998E8, 0);
  if ( *v12 != 1 )
  {
    v13 = *v12 & 0x7FFFFFFF;
    if ( v13 <= 1 )
      v14 = v13 ? (int)(v12 + 1) : 0;
    else
      v14 = v12[1];
    v15 = v12 + 1;
    if ( v12 != (int *)-4 )
    {
      *v15 = 0;
      if ( (_DWORD *)v14 != v15 && *v12 >= 0 )
        Phyre_Memory_AlignedFree(v14);
      *v12 = 1;
    }
  }
  sub_48C610(0, a1[4022]);
  *(_DWORD *)(a1[4023] + 16) = v12;
  *(_DWORD *)(a1[4024] + 16) = v12;
  *(_DWORD *)(a1[4025] + 16) = v12;
  a1[4053] = sub_56CD50("NormalDepthBuffer");
  a1[4054] = sub_56CD50("DepthBuffer");
  a1[4055] = sub_56CD50("DeferredWorldTransform");
  a1[4056] = sub_56CD50("ShadowTexture");
  a1[4057] = sub_56CD50("DeferredShadowMatrix");
  a1[4065] = sub_56CD50("InvProjXY");
  a1[4063] = sub_56CD50("DeferredShadowAlpha");
  a1[4064] = sub_56CD50("DeferredShadowMask");
  a1[4058] = sub_56CD50("DeferredShadowMatrixSplit0");
  a1[4059] = sub_56CD50("DeferredShadowMatrixSplit1");
  a1[4060] = sub_56CD50("DeferredShadowMatrixSplit2");
  a1[4061] = sub_56CD50("DeferredShadowMatrixSplit3");
  a1[4062] = sub_56CD50("DeferredSplitDistances");
  a1[4066] = sub_56CD50("FogCoefficients");
  a1[4067] = sub_56CD50("FogColor");
  result = sub_58D110(a3, a2);
  if ( !result )
  {
    result = sub_58D110(v18, v21);
    if ( !result )
    {
      result = sub_58D110(v19, v22);
      if ( !result )
      {
        v23 = sub_56CD50("PointClampSampler");
        v16 = sub_56CD50("ShadowMapSampler");
        if ( !v23 || (result = sub_56E770(v23, a1 + 4026)) == 0 )
        {
          if ( !v16 )
            return 0;
          result = sub_56E770(v16, a1 + 4035);
          if ( !result )
            return 0;
        }
      }
    }
  }
  return result;
}

