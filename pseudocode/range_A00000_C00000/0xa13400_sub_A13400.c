// Function: sub_A13400
// Address: 0xa13400
// Size: 0x2a1
// Prototype: 

int __thiscall sub_A13400(int this, int a2, int a3)
{
  int v4; // ecx
  bool v5; // zf
  int v6; // eax
  _DWORD *v7; // edx
  int n3; // eax
  unsigned int n4; // esi
  size_t Size; // ecx
  int v11; // ecx
  int v12; // eax
  _DWORD *v13; // edx
  unsigned int n4_1; // esi
  size_t Size_1; // ecx
  int v16; // ecx
  int v17; // edx
  _DWORD *v18; // edi
  int n73; // eax
  unsigned int n4_2; // edx
  size_t Size_2; // ecx
  int v22; // eax
  int v23; // ecx
  int v24; // ecx
  unsigned int v25; // ecx
  int v26; // ecx
  _DWORD v27[5]; // [esp+Ch] [ebp-54h] BYREF
  _DWORD v28[5]; // [esp+20h] [ebp-40h] BYREF
  _DWORD v29[5]; // [esp+34h] [ebp-2Ch] BYREF
  _DWORD Src[5]; // [esp+48h] [ebp-18h] BYREF
  unsigned int v31; // [esp+5Ch] [ebp-4h]

  v4 = *(_DWORD *)(this + 16420);
  if ( !v4 )
    goto LABEL_10;
  v5 = *(_BYTE *)(v4 + 2) == 72;
  Src[3] = *(_DWORD *)(this + 16436);
  v6 = *(_DWORD *)(this + 16088);
  Src[0] = 72;
  v7 = *(_DWORD **)(v6 + 4);
  Src[2] = 0;
  Src[4] = 0;
  Src[1] = 0;
  if ( !v5 )
    return 5;
  n4 = *(unsigned __int16 *)(v4 + 8);
  Size = *(_WORD *)(v4 + 10) & 0x1FFF;
  if ( n4 + Size <= *v7 )
  {
    if ( n4 >= 4 )
    {
      memcpy((char *)v7 + n4, Src, Size);
      n3 = 0;
    }
    else
    {
      n3 = 3;
    }
  }
  else
  {
    n3 = 3;
  }
  if ( !n3 )
  {
LABEL_10:
    v11 = *(_DWORD *)(this + 16444);
    if ( !v11 )
      goto LABEL_18;
    v5 = *(_BYTE *)(v11 + 2) == 72;
    v29[3] = *(_DWORD *)(this + 16440);
    v12 = *(_DWORD *)(this + 16088);
    v29[0] = 72;
    v13 = *(_DWORD **)(v12 + 4);
    v29[2] = 0;
    v29[4] = 0;
    v29[1] = 0;
    if ( !v5 )
      return 5;
    n4_1 = *(unsigned __int16 *)(v11 + 8);
    Size_1 = *(_WORD *)(v11 + 10) & 0x1FFF;
    if ( n4_1 + Size_1 <= *v13 )
    {
      if ( n4_1 >= 4 )
      {
        memcpy((char *)v13 + n4_1, v29, Size_1);
        n3 = 0;
      }
      else
      {
        n3 = 3;
      }
    }
    else
    {
      n3 = 3;
    }
    if ( !n3 )
    {
LABEL_18:
      v16 = *(_DWORD *)(this + 16404);
      if ( !v16 )
        goto LABEL_43;
      v17 = *(_DWORD *)(this + 16336);
      v18 = *(_DWORD **)(*(_DWORD *)(this + 16088) + 4);
      n73 = *(unsigned __int8 *)(v16 + 2);
      v28[0] = 73;
      v28[2] = 0;
      v28[4] = 0;
      v28[3] = v17;
      v28[1] = 0;
      if ( n73 != 73 && n73 != 20 && n73 != 21 || v17 && (*(_BYTE *)(v17 + 8) & 8) == 0 )
        return 5;
      n4_2 = *(unsigned __int16 *)(v16 + 8);
      Size_2 = *(_WORD *)(v16 + 10) & 0x1FFF;
      if ( n4_2 + Size_2 <= *v18 )
      {
        if ( n4_2 >= 4 )
        {
          memcpy((char *)v18 + n4_2, v28, Size_2);
          n3 = 0;
        }
        else
        {
          n3 = 3;
        }
      }
      else
      {
        n3 = 3;
      }
      if ( !n3 )
      {
LABEL_43:
        v22 = *(_DWORD *)(this + 16324);
        v23 = *(_BYTE *)(v22 + 4) ? 0 : *(_DWORD *)v22;
        v5 = *(_BYTE *)(v22 + 4) == 0;
        v31 = *(_DWORD *)(v23 + 28);
        v24 = v5 ? *(_DWORD *)v22 : 0;
        v25 = *(_DWORD *)(v24 + 32);
        *(_DWORD *)(a2 + 72) = &unk_1944C3C;
        n3 = sub_5B67C0(
               **(_DWORD **)(this + 16088),
               *(void **)(*(_DWORD *)(this + 16088) + 4),
               (v31 >> 3) + ((v31 & 7) != 0),
               (v25 >> 3) + ((v25 & 7) != 0),
               1);
        if ( !n3 )
        {
          v26 = *(_DWORD *)(this + 16400);
          if ( !v26 )
            return 0;
          v5 = *(_BYTE *)(v26 + 2) == 72;
          v27[2] = 0;
          v27[4] = 0;
          v27[3] = *(_DWORD *)(this + 16336);
          v27[0] = 72;
          v27[1] = 0;
          if ( !v5 )
            return 5;
          n3 = sub_4D5910(v26, v27);
          if ( !n3 )
            return 0;
        }
      }
    }
  }
  return n3;
}

