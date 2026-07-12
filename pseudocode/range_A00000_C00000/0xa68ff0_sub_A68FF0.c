// Function: sub_A68FF0
// Address: 0xa68ff0
// Size: 0xc7

int sub_A68FF0()
{
  int i; // ecx
  double v1; // st4
  int v3; // [esp+0h] [ebp-20h]
  float v4; // [esp+4h] [ebp-1Ch]
  _BYTE v5[2]; // [esp+8h] [ebp-18h]
  unsigned __int16 v6; // [esp+Ah] [ebp-16h]
  float v7[4]; // [esp+Ch] [ebp-14h] BYREF

  sub_836170(3, v7); /*0xa69006*/
  for ( i = 0; i < 4; ++i ) /*0xa6901c*/
  {
    v4 = v7[i] * 256.0; /*0xa69024*/
    v1 = v4; /*0xa69027*/
    if ( v4 <= 255.0 ) /*0xa69031*/
    {
      if ( v1 >= 0.0 ) /*0xa69043*/
      {
        v3 = (int)v1; /*0xa69065*/
        v5[i] = (int)v1; /*0xa6906b*/
      }
      else
      {
        if ( (unsigned int)i >= 4 ) /*0xa6904a*/
          __report_rangecheckfailure(v3); /*0xa690b2*/
        v5[i] = 0; /*0xa6904c*/
      }
    }
    else
    {
      v5[i] = -1; /*0xa69035*/
    }
  }
  return v5[0] | ((v5[1] | (v6 << 8)) << 8); /*0xa6909e*/
}