// Function: sub_897B40
// Address: 0x897b40
int sub_897B40()
{
  double v0; // st7
  float v2; // [esp+8h] [ebp-4h]
  float v3; // [esp+8h] [ebp-4h]

  unk_133C8FD = 0;
  n255_2 = 255;
  word_133F64C = (int)FFX_Menu2D_ScaleX_1920to512(700.0);
  word_133F650[0] = (int)FFX_Menu2D_ScaleY_1080to416(101.0);
  unk_133F654 = (int)FFX_Menu2D_ScaleX_1920to512(700.0);
  LOWORD(flt_133F658) = (int)FFX_Menu2D_ScaleY_1080to416(109.0);
  word_133F65C = (int)FFX_Menu2D_ScaleX_1920to512(1400.0);
  unk_133F660 = (int)FFX_Menu2D_ScaleY_1080to416(160.0);
  unk_133F648 = 0;
  n2_15 = 0;
  unk_133F5DA = unk_133F654;
  unk_133F5DC = LOWORD(flt_133F658);
  unk_133F5DE = word_133F65C - word_133F64C;
  v2 = (float)word_133F64C;
  v0 = v2;
  unk_133F5E4 = v2;
  v3 = (float)word_133F650[0];
  unk_133F5EC[0] = 0;
  unk_133F5F0 = 0;
  unk_133F5E8 = v3;
  n3_2 = 0;
  unk_133F600 = v0;
  unk_133F5F6 = unk_133F654;
  unk_133F5F8 = LOWORD(flt_133F658);
  unk_133F604 = v3;
  unk_133F5FA = word_133F65C - word_133F64C;
  unk_133F608[0] = 0;
  unk_133F60C = 0;
  n3_16 = 0;
  unk_133F612 = unk_133F654;
  unk_133F614 = LOWORD(flt_133F658);
  unk_133F630 = LOWORD(flt_133F658);
  unk_133F61C = unk_133F600;
  unk_133F624[0] = 0;
  unk_133F620 = v3;
  unk_133F628 = 0;
  src__5 = 0;
  unk_133F638 = unk_133F600;
  unk_133F616 = word_133F65C - word_133F64C;
  unk_133F62E = unk_133F654;
  unk_133F63C = v3;
  unk_133F632 = word_133F65C - word_133F64C;
  unk_133F640[0] = 0;
  unk_133F644 = 0;
  return 0;
}
