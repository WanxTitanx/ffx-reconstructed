// Function: sub_8E20F0
// Address: 0x8e20f0
int __thiscall sub_8E20F0(void *this)
{
  int result; // eax
  int v2; // esi
  int n4096_2; // ecx
  double v4; // st7
  double v5; // st6
  float v6; // [esp+0h] [ebp-2Ch]
  int v7; // [esp+4h] [ebp-28h]
  float v8; // [esp+8h] [ebp-24h]
  float v9; // [esp+Ch] [ebp-20h]
  int v10; // [esp+18h] [ebp-14h]
  int v11; // [esp+18h] [ebp-14h]
  int v12; // [esp+1Ch] [ebp-10h]
  int v13; // [esp+1Ch] [ebp-10h]
  float n4096; // [esp+28h] [ebp-4h]
  float v15; // [esp+28h] [ebp-4h]
  float n4096_1; // [esp+28h] [ebp-4h]
  float v17; // [esp+28h] [ebp-4h]

  result = sub_8AA410(this);
  if ( (result & 0x80800) == 0 )
  {
    n4096 = (float)n4096_0;
    v15 = n4096 * 805.0 * 0.000244140625;
    v9 = FFX_Menu2D_ScaleY_1080to416(v15);
    v8 = FFX_Menu2D_ScaleX_1920to512(2.0);
    n4096_1 = (float)n4096_0;
    v17 = n4096_1 * 194.0 * 0.000244140625;
    *(float *)&v7 = FFX_Menu2D_ScaleY_1080to416(v17);
    v6 = FFX_Menu2D_ScaleX_1920to512(1280.0);
    FFX_Menu2D_DrawTexQuadTinted(
      0xFFFFFFFF,
      v6,
      v7,
      v8,
      v9,
      COERCE_INT(1879.0),
      COERCE_INT(542.0),
      COERCE_INT(1881.0),
      COERCE_INT(662.0),
      0x80808080,
      0x80808080);
    sub_88EBD0();
    sub_8BEF00();
    if ( n4096_0 )
    {
      v2 = 0;
      v4 = -20.0;
      v5 = 0.0;
      if ( ((int (*)(void))sub_8E2280)() > 0 )
      {
        do
        {
          if ( v2 != unk_1871508 )
          {
            *(float *)&v12 = v4;
            *(float *)&v10 = v5;
            sub_8E22A0(v2, *(float *)&v10, v10, v12, n4096_2);
            v4 = -20.0;
            n4096_2 = n4096_0;
            v5 = 0.0;
          }
          ++v2;
        }
        while ( v2 < sub_8E2280(n4096_2) );
      }
      *(float *)&v13 = v4;
      *(float *)&v11 = v5;
      sub_8E22A0(unk_1871508, *(float *)&v11, v11, v13, n4096_2);
    }
    sub_8BE9F0();
    return sub_88EBD0();
  }
  return result;
}
