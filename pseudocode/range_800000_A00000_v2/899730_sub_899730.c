// Function: sub_899730
// Address: 0x899730
void __cdecl sub_899730(unsigned int n255)
{
  unsigned int n255_1; // esi
  _BYTE *n255_2; // ecx
  float *v3; // eax
  int v4; // edx
  char v5; // al

  n255_1 = n255;
  if ( n255 < 0x12 || n255 == 12543 )
  {
    memset(&unk_133F4F8, 0, 0x80u);
    if ( n255 > 7 )
      n255_2 = (_BYTE *)n255;
    else
      n255_2 = (_BYTE *)sub_78F810(n255, 0);
    if ( n255_1 - 8 <= 9 )
      n255_2 = (_BYTE *)sub_78F810(n255_1, 0);
    if ( n255_1 == 12543 )
    {
      v3 = FFX_Btl_LookupCommandDataById(12543, &n255);
      n255_2 = (_BYTE *)(n255 + *((unsigned __int16 *)v3 + 4));
    }
    v4 = &unk_133F4F8 - (_UNKNOWN *)n255_2;
    do
    {
      v5 = *n255_2;
      n255_2[v4] = *n255_2;
      ++n255_2;
    }
    while ( v5 );
    sub_8B9600(0, &unk_133F4F8, &unk_133F4F4, &unk_133F4F0, 0, 0);
  }
}
