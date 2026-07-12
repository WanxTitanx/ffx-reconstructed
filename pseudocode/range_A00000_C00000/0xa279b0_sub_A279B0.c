// Function: sub_A279B0
// Address: 0xa279b0
// Size: 0x1d8
// Prototype: 

void __thiscall sub_A279B0(int this)
{
  _DWORD *this_1; // ebx
  _DWORD *v2; // eax
  int v3; // edi
  int v4; // esi
  size_t Size; // eax
  void *Size_2; // ecx
  char *v7; // edi
  char *v8; // ebx
  int v9; // edi
  int v10; // edx
  char *v11; // ebx
  int Size_5; // ecx
  size_t Size_3; // eax
  _DWORD *this_3; // esi
  char *v15; // esi
  int v16; // edi
  size_t Size_6; // eax
  void *Size_8; // ecx
  char *v19; // esi
  char *v20; // ebx
  _DWORD *v21; // [esp+4h] [ebp-20h]
  int Size_10; // [esp+8h] [ebp-1Ch]
  size_t Size_7; // [esp+8h] [ebp-1Ch]
  void *Size_9; // [esp+Ch] [ebp-18h]
  void *Size_11; // [esp+Ch] [ebp-18h]
  size_t Size_1; // [esp+10h] [ebp-14h]
  size_t Size_4; // [esp+10h] [ebp-14h]
  int v28; // [esp+14h] [ebp-10h] BYREF
  void *v29; // [esp+18h] [ebp-Ch]
  int v30; // [esp+1Ch] [ebp-8h]
  _DWORD *this_2; // [esp+20h] [ebp-4h]

  this_1 = (_DWORD *)this;
  this_2 = (_DWORD *)this;
  if ( *(_DWORD *)(this + 236) == 1 )
  {
    *(_BYTE *)(this + 340) = 0;
  }
  else
  {
    do
    {
      v2 = (_DWORD *)sub_A3DD90(this_1);
      if ( !v2 )
        break;
      sub_409680(this_1 + 76, v2 + 1, *v2, 0, 0);
      sub_A3DDC0(this_1);
      v28 = 0;
      v3 = sub_4096E0(this_1 + 76, &v28);
      v30 = v3;
      if ( v3 )
      {
        v21 = this_1 + 16;
        v29 = (void *)sub_A3DEC0(this_1[180]);
        if ( !v29 )
          break;
        v4 = this_1[84];
        Size = this_1[83];
        Size_2 = *(void **)(v3 + 52);
        v7 = *(char **)(v3 + 36);
        v8 = (char *)v29 + 4;
        Size_1 = Size;
        Size_9 = Size_2;
        if ( v4 && Size )
        {
          if ( Size_2 == (void *)Size )
          {
            memcpy((char *)v29 + 4, v7, v4 * (_DWORD)Size_2);
          }
          else
          {
            do
            {
              memcpy(v8, v7, Size);
              Size = Size_1;
              v7 = &v7[(_DWORD)Size_9];
              v8 += Size_1;
              --v4;
            }
            while ( v4 );
          }
        }
        v9 = this_2[177];
        v10 = v30;
        v11 = *(char **)(v30 + 40);
        Size_5 = *(_DWORD *)(v30 + 56);
        v29 = (char *)v29 + this_2[178] + 4;
        Size_3 = this_2[176];
        this_3 = this_2;
        Size_4 = Size_3;
        Size_10 = Size_5;
        if ( v9 && Size_3 )
        {
          if ( Size_5 == Size_3 )
          {
            memcpy(v29, v11, v9 * Size_5);
          }
          else
          {
            v15 = (char *)v29;
            do
            {
              memcpy(v15, v11, Size_3);
              Size_3 = Size_4;
              v11 += Size_10;
              v15 += Size_4;
              --v9;
            }
            while ( v9 );
            this_3 = this_2;
          }
          v10 = v30;
        }
        v16 = this_3[177];
        Size_6 = this_3[176];
        Size_8 = *(void **)(v10 + 60);
        v19 = (char *)v29 + this_3[179];
        v20 = *(char **)(v10 + 44);
        Size_7 = Size_6;
        Size_11 = Size_8;
        if ( v16 && Size_6 )
        {
          if ( Size_8 == (void *)Size_6 )
          {
            memcpy(v19, v20, v16 * (_DWORD)Size_8);
          }
          else
          {
            do
            {
              memcpy(v19, v20, Size_6);
              Size_6 = Size_7;
              v20 = &v20[(_DWORD)Size_11];
              v19 += Size_7;
              --v16;
            }
            while ( v16 );
          }
        }
        sub_A3DF00(v21);
        this_1 = this_2;
      }
    }
    while ( this_1[59] != 1 );
    *((_BYTE *)this_1 + 340) = 0;
  }
}

