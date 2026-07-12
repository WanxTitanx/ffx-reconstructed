// Function: sub_A215D0
// Address: 0xa215d0
// Size: 0x409
// Prototype: 

int __thiscall sub_A215D0(int *this, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int n3; // eax
  int v9; // edi
  _DWORD *v10; // ebx
  int n66; // eax
  unsigned int n4; // ecx
  size_t Size; // edx
  int v14; // edi
  _DWORD *v15; // ebx
  int n66_1; // eax
  unsigned int n4_1; // ecx
  size_t Size_1; // edx
  int v19; // edi
  int n66_2; // eax
  int v21; // ecx
  _DWORD *v22; // edi
  unsigned int n4_2; // ebx
  size_t Size_2; // ecx
  int v25; // ecx
  _DWORD *v26; // edi
  unsigned int n4_3; // ebx
  size_t Size_3; // ecx
  int v29; // ebx
  _BYTE v30[16]; // [esp+10h] [ebp-4Ch] BYREF
  _DWORD v31[4]; // [esp+20h] [ebp-3Ch] BYREF
  _DWORD v32[4]; // [esp+30h] [ebp-2Ch] BYREF
  _DWORD Src[4]; // [esp+40h] [ebp-1Ch] BYREF
  int v34; // [esp+58h] [ebp-4h]

  if ( !*(this + 823) )
    return 21;
  v9 = *(this + 843);
  if ( v9 )
  {
    v10 = *(_DWORD **)(*(this + 842) + 4);
    n66 = *(unsigned __int8 *)(v9 + 2);
    Src[0] = 66;
    Src[1] = 0;
    Src[3] = a5;
    Src[2] = this + 833;
    if ( n66 != 66 && n66 != 217 && n66 != 218 && n66 != 219 && n66 != 220 && n66 != 18 )
      return 5;
    if ( this != (int *)-3332 )
    {
      if ( a5 )
      {
        n3 = sub_59E6B0(a5);
        if ( n3 )
          return n3;
      }
    }
    n4 = *(unsigned __int16 *)(v9 + 8);
    Size = *(_WORD *)(v9 + 10) & 0x1FFF;
    if ( n4 + Size <= *v10 )
    {
      if ( n4 >= 4 )
      {
        memcpy((char *)v10 + n4, Src, Size);
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
    if ( n3 )
      return n3;
  }
  v14 = *(this + 844);
  if ( v14 )
  {
    v15 = *(_DWORD **)(*(this + 842) + 4);
    n66_1 = *(unsigned __int8 *)(v14 + 2);
    v32[0] = 66;
    v32[1] = 0;
    v32[3] = a6;
    v32[2] = this + 824;
    if ( n66_1 != 66 && n66_1 != 217 && n66_1 != 218 && n66_1 != 219 && n66_1 != 220 && n66_1 != 18 )
      return 5;
    if ( this != (int *)-3296 )
    {
      if ( a6 )
      {
        n3 = sub_59E6B0(a6);
        if ( n3 )
          return n3;
      }
    }
    n4_1 = *(unsigned __int16 *)(v14 + 8);
    Size_1 = *(_WORD *)(v14 + 10) & 0x1FFF;
    if ( n4_1 + Size_1 <= *v15 )
    {
      if ( n4_1 >= 4 )
      {
        memcpy((char *)v15 + n4_1, v32, Size_1);
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
    if ( n3 )
      return n3;
  }
  v19 = *(this + 845);
  if ( v19 )
  {
    n66_2 = *(unsigned __int8 *)(v19 + 2);
    v31[0] = 66;
    v31[1] = 0;
    v31[3] = a7;
    v31[2] = this + 833;
    if ( n66_2 == 66 || n66_2 == 217 || n66_2 == 218 || n66_2 == 219 || n66_2 == 220 || n66_2 == 18 )
    {
      if ( this != (int *)-3332 )
      {
        if ( a7 )
        {
          n3 = sub_59E6B0(a7);
          if ( n3 )
            return n3;
        }
      }
      n3 = sub_4D5910(v19, v31);
      if ( n3 )
        return n3;
      goto LABEL_47;
    }
    return 5;
  }
LABEL_47:
  v21 = *(this + 846);
  if ( v21 )
  {
    v22 = *(_DWORD **)(*(this + 842) + 4);
    if ( this == (int *)-3284 )
      return 1;
    n4_2 = *(unsigned __int16 *)(v21 + 8);
    Size_2 = *(_WORD *)(v21 + 10) & 0x1FFF;
    if ( Size_2 + n4_2 > *v22 || n4_2 < 4 )
      return 3;
    memcpy((char *)v22 + n4_2, this + 821, Size_2);
  }
  v25 = *(this + 849);
  if ( v25 )
  {
    v26 = *(_DWORD **)(*(this + 842) + 4);
    if ( this == (int *)-148 )
      return 1;
    n4_3 = *(unsigned __int16 *)(v25 + 8);
    Size_3 = *(_WORD *)(v25 + 10) & 0x1FFF;
    if ( Size_3 + n4_3 > *v26 || n4_3 < 4 )
      return 3;
    memcpy((char *)v26 + n4_3, this + 37, Size_3);
  }
  *(_DWORD *)(a2 + 72) = &unk_1944944;
  if ( a3 )
  {
    sub_5B3760(a3, 0);
    v34 = 0;
    v29 = sub_5BB2D0(v30, 0);
    v34 = -1;
    nullsub_24(v30);
    if ( v29 )
      return v29;
  }
  else
  {
    n3 = sub_5BB2D0(0, 0);
    if ( n3 )
      return n3;
  }
  n3 = sub_5BB750(0);
  if ( !n3 )
  {
    n3 = sub_5B5FD0(0);
    if ( !n3 )
    {
      n3 = sub_5B9C30(*(this + 823), *(_DWORD *)(*(this + 823) + 16), 0, *(_DWORD *)(a2 + 316));
      if ( !n3 )
      {
        n3 = sub_5B6AF0(1);
        if ( !n3 )
          return sub_5BB2D0(0, 0);
      }
    }
  }
  return n3;
}

