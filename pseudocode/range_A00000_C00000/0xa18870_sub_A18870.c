// Function: sub_A18870
// Address: 0xa18870
// Size: 0x20f
// Prototype: 

int __userpurge sub_A18870@<eax>(_DWORD *a1@<ecx>, int a2@<edi>, int a3@<esi>, int a4, int a5)
{
  int result; // eax
  int v7; // eax
  int v8; // ecx
  _DWORD *v9; // edx
  _DWORD *p_Size; // ecx
  int *v11; // esi
  unsigned int v12; // eax
  int v13; // ecx
  _DWORD *v14; // edi
  unsigned int v15; // eax
  _DWORD *v16; // eax
  int v17; // eax
  int v18; // ecx
  _DWORD *v19; // edx
  unsigned int n4; // ecx
  size_t Size; // esi
  int v22; // eax
  int v23; // ecx
  _DWORD *v24; // edx
  unsigned int n4_1; // ecx
  size_t Size_1; // esi
  int v28; // [esp-8h] [ebp-2Ch]
  int v30; // [esp-4h] [ebp-28h]
  _DWORD v31[4]; // [esp+4h] [ebp-20h] BYREF
  _DWORD Src[4]; // [esp+14h] [ebp-10h] BYREF

  if ( !a1[24] )
    return 21;
  v7 = sub_4E6BA0(a4, 0, 0);
  v8 = a1[2];
  a1[25] = v7;
  if ( v8 )
  {
    v9 = *(_DWORD **)(v7 + 4);
    p_Size = *(_DWORD **)(v8 + 4);
    if ( ((p_Size[2] ^ v9[2]) & 0x7FFFFFFF) == 0 )
      memcpy(v9, p_Size, *p_Size);
  }
  a1[26] = sub_56CD50("ColorBuffer");
  a1[27] = sub_56CD50("InvColorBufferSize");
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
    *v16 = a1[25];
  }
  *(_DWORD *)(a1[24] + 16) = v11;
  result = sub_58D110(a2, a3);
  if ( !result )
  {
    result = sub_58D110(v28, v30);
    if ( !result )
    {
      v17 = sub_56CD50("LinearClampSampler");
      if ( v17 )
      {
        v18 = a1[25];
        Src[2] = a1 + 14;
        v19 = *(_DWORD **)(v18 + 4);
        n4 = *(unsigned __int16 *)(v17 + 8);
        Size = *(_WORD *)(v17 + 10) & 0x1FFF;
        Src[0] = 71;
        Src[1] = 0;
        Src[3] = 0;
        if ( Size + n4 > *v19 || n4 < 4 )
          return 3;
        memcpy((char *)v19 + n4, Src, Size);
      }
      v22 = sub_56CD50("PointClampSampler");
      if ( !v22 )
        return 0;
      v23 = a1[25];
      v31[0] = 71;
      v24 = *(_DWORD **)(v23 + 4);
      v31[2] = a1 + 5;
      n4_1 = *(unsigned __int16 *)(v22 + 8);
      Size_1 = *(_WORD *)(v22 + 10) & 0x1FFF;
      v31[1] = 0;
      v31[3] = 0;
      if ( n4_1 + Size_1 <= *v24 && n4_1 >= 4 )
      {
        memcpy((char *)v24 + n4_1, v31, Size_1);
        return 0;
      }
      return 3;
    }
  }
  return result;
}

