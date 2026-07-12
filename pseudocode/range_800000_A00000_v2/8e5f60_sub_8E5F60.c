// Function: sub_8E5F60
// Address: 0x8e5f60
void sub_8E5F60()
{
  int v0[38]; // [esp+0h] [ebp-9Ch] BYREF

  *(float *)v0 = 0.0;
  *(float *)&v0[1] = 0.0;
  v0[36] = 0;
  v0[37] = 0;
  v0[4] = 128;
  v0[5] = 128;
  *(float *)&v0[2] = 0.001953125 * 0.0;
  v0[6] = 128;
  v0[7] = 128;
  v0[12] = 128;
  v0[13] = 128;
  v0[14] = 128;
  v0[15] = 128;
  *(float *)&v0[3] = 0.0 / 416.0;
  *(float *)&v0[8] = 512.0;
  *(float *)&v0[9] = 416.0;
  *(float *)&v0[10] = 1.0;
  *(float *)&v0[11] = 1.0;
  sub_63F090(
    (int)v0,
    aFramebuffer_0, // "FrameBuffer"
    1,
    0,
    0.0);
}
