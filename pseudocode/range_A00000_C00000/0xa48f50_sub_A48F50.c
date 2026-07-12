// Function: sub_A48F50
// Address: 0xa48f50
// Size: 0x163
// Prototype: 

int sub_A48F50()
{
  int v0; // ecx
  __int16 v1; // ax
  double v2; // st7
  int result; // eax
  __int16 v4; // ax
  float v5; // [esp+4h] [ebp-4h]
  float v6; // [esp+4h] [ebp-4h]

  v0 = dword_2305834[0];
  if ( *(__int16 *)(unk_1A86108 + 9984) < 0 )
  {
    v1 = *(_WORD *)(dword_2305834[0] + 71278);
    if ( (v1 & 2) != 0 )
    {
      ++*(_BYTE *)(dword_2305834[0] + 71115);
      if ( *(_BYTE *)(v0 + 71115) > 2u )
        *(_BYTE *)(dword_2305834[0] + 71115) = 0;
    }
    else
    {
      if ( (v1 & 1) == 0 )
        goto LABEL_15;
      --*(_BYTE *)(dword_2305834[0] + 71115);
      if ( *(_BYTE *)(v0 + 71115) > 2u )
        *(_BYTE *)(dword_2305834[0] + 71115) = 2;
    }
    *(_WORD *)(dword_2305834[0] + 71118) = 30;
    *(float *)(dword_2305834[0] + 71124) = (float)*(int *)(dword_2305834[0] + 70464);
    if ( *(_BYTE *)(dword_2305834[0] + 71115) )
    {
      if ( *(_BYTE *)(dword_2305834[0] + 71115) == 1 )
      {
        v2 = -3640.0;
        goto LABEL_14;
      }
      if ( *(_BYTE *)(dword_2305834[0] + 71115) == 2 )
      {
        v2 = -7281.0;
LABEL_14:
        v5 = v2;
        *(float *)(dword_2305834[0] + 71128) = v5;
        v0 = dword_2305834[0];
        goto LABEL_15;
      }
    }
    v2 = 0.0;
    goto LABEL_14;
  }
LABEL_15:
  result = *(unsigned __int16 *)(v0 + 71118);
  if ( (__int16)result > 0 )
  {
    v4 = result - 1;
    *(_WORD *)(v0 + 71118) = v4;
    if ( v4 )
    {
      v6 = flt_C44BE0[((((30 - *(__int16 *)(dword_2305834[0] + 71118)) << 14) / 30) >> 4) & 0xFFF]
         * (*(float *)(dword_2305834[0] + 71128) - *(float *)(dword_2305834[0] + 71124))
         + *(float *)(dword_2305834[0] + 71124);
      result = (int)v6;
      *(_DWORD *)(dword_2305834[0] + 70464) = result;
    }
    else
    {
      *(_DWORD *)(dword_2305834[0] + 70464) = (int)*(float *)(dword_2305834[0] + 71128);
      result = dword_2305834[0];
      *(_BYTE *)(dword_2305834[0] + 71111) = 1;
    }
  }
  return result;
}

