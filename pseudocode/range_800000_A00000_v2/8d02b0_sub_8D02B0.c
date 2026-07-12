// Function: sub_8D02B0
// Address: 0x8d02b0
void sub_8D02B0()
{
  int v0; // esi
  int v1; // edi
  double v2; // st7
  double v3; // st7
  int v4; // eax
  double v5; // st7
  _WORD *v6; // esi
  int n4; // edi
  int n255; // eax
  double v9; // st7
  float v10; // [esp+8h] [ebp-20h]
  float v11; // [esp+8h] [ebp-20h]
  float v12; // [esp+Ch] [ebp-1Ch]
  float v13; // [esp+Ch] [ebp-1Ch]
  _BYTE v14[4]; // [esp+1Ch] [ebp-Ch] BYREF
  float v15; // [esp+20h] [ebp-8h]
  float v16; // [esp+24h] [ebp-4h]

  if ( n255_4 != 255 )
  {
    v0 = sub_7ABBF0(n255_4, v14);
    v15 = FFX_Menu2D_ScaleX_1920to512(970.0);
    v16 = FFX_Menu2D_ScaleY_1080to416(599.0);
    sub_798EC0(v0);
    v1 = 0;
    if ( *(_BYTE *)(v0 + 11) )
    {
      v2 = 60.0;
      do
      {
        v12 = v2;
        v13 = FFX_Menu2D_ScaleY_1080to416(v12);
        v10 = FFX_Menu2D_ScaleX_1920to512(740.0);
        sub_8F5F70(v15, v16, v10, v13, 14);
        ++v1;
        v3 = FFX_Menu2D_ScaleY_1080to416(79.0);
        v4 = *(unsigned __int8 *)(v0 + 11);
        v16 = v3 + v16;
        v2 = 60.0;
      }
      while ( v1 < v4 );
    }
    v15 = FFX_Menu2D_ScaleX_1920to512(970.0);
    v16 = FFX_Menu2D_ScaleY_1080to416(599.0);
    v5 = v15;
    v6 = (_WORD *)(v0 + 14);
    n4 = 4;
    do
    {
      n255 = (unsigned __int16)*v6;
      if ( *v6 )
      {
        if ( n255 != 255 )
        {
          v11 = v5;
          sub_8F4F10(n255, v11, v16, 0.0);
        }
      }
      ++v6;
      v9 = FFX_Menu2D_ScaleY_1080to416(79.0);
      v16 = v9 + v16;
      v5 = v15;
      --n4;
    }
    while ( n4 );
  }
}
