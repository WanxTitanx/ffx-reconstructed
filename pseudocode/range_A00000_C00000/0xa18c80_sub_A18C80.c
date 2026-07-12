// Function: sub_A18C80
// Address: 0xa18c80
// Size: 0x2a0
// Prototype: 

int __userpurge sub_A18C80@<eax>(_DWORD *a1@<ecx>, int a2@<ebx>, int a3@<edi>, int a4, int a5)
{
  int result; // eax
  int v7; // eax
  int v8; // ecx
  _DWORD *v9; // edx
  _DWORD *p_Size; // ecx
  int *v11; // edi
  unsigned int v12; // eax
  int v13; // ecx
  _DWORD *v14; // ebx
  unsigned int v15; // eax
  _DWORD *v16; // eax
  int v17; // edi
  int v18; // ecx
  _DWORD *v19; // edx
  unsigned int n4; // ecx
  size_t Size; // ebx
  unsigned int n4_1; // ecx
  _DWORD *v23; // edx
  size_t Size_1; // esi
  int v26; // [esp-8h] [ebp-2Ch]
  int v28; // [esp-4h] [ebp-28h]
  _DWORD v29[4]; // [esp+4h] [ebp-20h] BYREF
  _DWORD Src[4]; // [esp+14h] [ebp-10h] BYREF
  int v31; // [esp+30h] [ebp+Ch]

  if ( !a1[823] )
    return 21;
  v7 = sub_4E6BA0(a4, 0, 0);
  v8 = a1[2];
  a1[842] = v7;
  if ( v8 )
  {
    v9 = *(_DWORD **)(v7 + 4);
    p_Size = *(_DWORD **)(v8 + 4);
    if ( ((p_Size[2] ^ v9[2]) & 0x7FFFFFFF) == 0 )
      memcpy(v9, p_Size, *p_Size);
  }
  a1[843] = sub_56CD50("ColorBuffer");
  a1[844] = sub_56CD50("DepthBuffer");
  a1[845] = sub_56CD50("VelocityBuffer");
  a1[847] = sub_56CD50("GaussianBlurWeights");
  a1[848] = sub_56CD50("GaussianBlurOffsets");
  a1[846] = sub_56CD50("VelocityScale");
  a1[849] = sub_56CD50("ViewToPreviousViewProjection");
  a1[850] = sub_56CD50("ObjectViewToPreviousViewProjection");
  v11 = (int *)sub_4410E0(1, (int)&unk_C998E8, 0);
  if ( *v11 != 1 )
  {
    v12 = *v11 & 0x7FFFFFFF;
    if ( v12 <= 1 )
      v13 = v12 ? (int)(v11 + 1) : 0;
    else
      v13 = v11[1];
    v14 = v11 + 1;
    if ( v11 != (int *)-4 )
    {
      *v14 = 0;
      if ( (_DWORD *)v13 != v14 && *v11 >= 0 )
        Phyre_Memory_AlignedFree(v13);
      *v11 = 1;
    }
  }
  v15 = *v11 & 0x7FFFFFFF;
  if ( v15 )
  {
    if ( v15 <= 1 )
      v16 = v11 + 1;
    else
      v16 = (_DWORD *)v11[1];
    *v16 = a1[842];
  }
  *(_DWORD *)(a1[823] + 16) = v11;
  result = sub_58D110(a3, a2);
  if ( !result )
  {
    result = sub_58D110(v26, v28);
    if ( !result )
    {
      v31 = sub_56CD50("PointClampSampler");
      v17 = sub_56CD50("LinearClampSampler");
      if ( v31 )
      {
        v18 = a1[842];
        Src[0] = 71;
        v19 = *(_DWORD **)(v18 + 4);
        Src[2] = a1 + 824;
        n4 = *(unsigned __int16 *)(v31 + 8);
        Size = *(_WORD *)(v31 + 10) & 0x1FFF;
        Src[1] = 0;
        Src[3] = 0;
        if ( Size + n4 > *v19 || n4 < 4 )
          return 3;
        memcpy((char *)v19 + n4, Src, Size);
      }
      if ( !v17 )
        return 0;
      n4_1 = *(unsigned __int16 *)(v17 + 8);
      v23 = *(_DWORD **)(a1[842] + 4);
      v29[2] = a1 + 833;
      Size_1 = *(_WORD *)(v17 + 10) & 0x1FFF;
      v29[0] = 71;
      v29[1] = 0;
      v29[3] = 0;
      if ( n4_1 + Size_1 <= *v23 && n4_1 >= 4 )
      {
        memcpy((char *)v23 + n4_1, v29, Size_1);
        return 0;
      }
      return 3;
    }
  }
  return result;
}

