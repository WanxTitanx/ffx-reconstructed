// Function: sub_8F3DB0
// Address: 0x8f3db0
void __cdecl sub_8F3DB0(int a1, int a2, int n512, int n416, unsigned int a5, unsigned int a6)
{
  int v6[38]; // [esp+4h] [ebp-9Ch] BYREF

  if ( sub_641210() != 1 )
  {
    v6[4] = (unsigned __int8)a5;
    *(float *)v6 = (float)a1;
    v6[5] = BYTE1(a5);
    *(float *)&v6[1] = (float)a2;
    v6[6] = BYTE2(a5);
    v6[7] = HIBYTE(a5);
    *(float *)&v6[8] = (float)(n512 + a1);
    v6[12] = (unsigned __int8)a6;
    *(float *)&v6[9] = (float)(n416 + a2);
    v6[13] = BYTE1(a6);
    v6[14] = BYTE2(a6);
    v6[36] = 0;
    v6[37] = 0;
    v6[34] = 0;
    v6[15] = HIBYTE(a6);
    sub_63F090((int)v6, 0, 1, 0, 0.0);
  }
}
