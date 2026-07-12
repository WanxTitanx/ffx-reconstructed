// Function: sub_A490C0
// Address: 0xa490c0
// Size: 0x1a5
// Prototype: 

int sub_A490C0()
{
  int v0; // ecx
  int v1; // eax
  int result; // eax
  __int16 v3; // ax
  float v4; // [esp+4h] [ebp-4h]
  float v5; // [esp+4h] [ebp-4h]

  v0 = dword_2305834[0];
  if ( *(__int16 *)(unk_1A86108 + 9984) < 0 && (*(_WORD *)(dword_2305834[0] + 71278) & 0x100) != 0 )
  {
    ++*(_BYTE *)(dword_2305834[0] + 71116);
    v1 = dword_2305834[0];
    if ( *(_BYTE *)(dword_2305834[0] + 71116) > 2u )
    {
      *(_BYTE *)(dword_2305834[0] + 71116) = 0;
      v1 = dword_2305834[0];
    }
    *(_WORD *)(v1 + 71120) = 30;
    *(float *)(dword_2305834[0] + 71132) = *(float *)(dword_2305834[0] + 70480);
    *(float *)(dword_2305834[0] + 71136) = sub_A56820(v0);
    v0 = dword_2305834[0];
  }
  result = *(unsigned __int16 *)(v0 + 71120);
  if ( (__int16)result > 0 )
  {
    v3 = result - 1;
    *(_WORD *)(v0 + 71120) = v3;
    if ( v3 )
    {
      v5 = flt_C44BE0[((((30 - *(__int16 *)(dword_2305834[0] + 71120)) << 14) / 30) >> 4) & 0xFFF]
         * (*(float *)(dword_2305834[0] + 71136) - *(float *)(dword_2305834[0] + 71132))
         + *(float *)(dword_2305834[0] + 71132);
      *(float *)(dword_2305834[0] + 70488) = v5;
      *(float *)(dword_2305834[0] + 70484) = v5;
      *(float *)(dword_2305834[0] + 70480) = v5;
      if ( v5 <= 0.375 && *(int *)(dword_2305834[0] + 71344) >= 0 )
        *(_DWORD *)(dword_2305834[0] + 71344) = -2;
      if ( v5 >= 0.375 && *(int *)(dword_2305834[0] + 71344) <= 0 )
        *(_DWORD *)(dword_2305834[0] + 71344) = 2;
      result = dword_2305834[0];
      if ( !*(_DWORD *)(dword_2305834[0] + 71340) )
        *(_DWORD *)(dword_2305834[0] + 71340) = 1;
    }
    else
    {
      v4 = *(float *)(dword_2305834[0] + 71136);
      *(float *)(dword_2305834[0] + 70488) = v4;
      *(float *)(dword_2305834[0] + 70484) = v4;
      *(float *)(dword_2305834[0] + 70480) = v4;
      result = dword_2305834[0];
      *(_BYTE *)(dword_2305834[0] + 71111) = 1;
    }
  }
  return result;
}

