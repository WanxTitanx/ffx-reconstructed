// Function: sub_81B0B0
// Address: 0x81b0b0
int __cdecl sub_81B0B0(int a1, int a2)
{
  int v2; // ecx
  unsigned int n24576; // eax

  v2 = *(_DWORD *)(a1 + 544);
  n24576 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( n24576 > 0x4000 )
  {
    if ( n24576 == 20480 )
    {
      *(_DWORD *)(v2 + 96) = 0;
      *(float *)(v2 + 104) = 0.0;
      *(_DWORD *)(v2 + 100) = 0;
      *(float *)(v2 + 136) = 0.0;
      *(_DWORD *)(v2 + 128) = 0;
      *(_DWORD *)(v2 + 132) = 0;
    }
    else if ( n24576 == 24576 )
    {
      *(float *)(v2 + 88) = 0.0;
      *(_DWORD *)(v2 + 80) = 0;
      *(float *)(v2 + 120) = 0.0;
      *(_DWORD *)(v2 + 84) = 0;
      *(_DWORD *)(v2 + 112) = 0;
      *(_DWORD *)(v2 + 116) = 0;
      return a2 + 2;
    }
  }
  else
  {
    if ( n24576 == 0x4000 )
    {
      *(_DWORD *)(v2 + 80) = word_C8F508[0];
      *(float *)(v2 + 84) = word_C8F50C;
      *(float *)(v2 + 88) = word_C8F510;
      *(float *)(v2 + 92) = word_C8F514[0];
      *(_DWORD *)(v2 + 96) = word_C8F508[0];
      *(float *)(v2 + 100) = word_C8F50C;
      *(float *)(v2 + 104) = word_C8F510;
      *(float *)(v2 + 108) = word_C8F514[0];
      *(_DWORD *)(v2 + 112) = word_C8F508[0];
      *(float *)(v2 + 116) = word_C8F50C;
      *(float *)(v2 + 120) = word_C8F510;
      *(float *)(v2 + 124) = word_C8F514[0];
      *(_DWORD *)(v2 + 128) = word_C8F508[0];
      *(float *)(v2 + 132) = word_C8F50C;
      *(float *)(v2 + 136) = word_C8F510;
      *(float *)(v2 + 140) = word_C8F514[0];
      return a2 + 2;
    }
    if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0 )
    {
      *(_DWORD *)(v2 + 48) = word_C8F508[0];
      *(float *)(v2 + 52) = word_C8F50C;
      *(float *)(v2 + 56) = word_C8F510;
      *(float *)(v2 + 60) = word_C8F514[0];
      *(_DWORD *)(v2 + 64) = word_C8F508[0];
      *(float *)(v2 + 68) = word_C8F50C;
      *(float *)(v2 + 72) = word_C8F510;
      *(float *)(v2 + 76) = word_C8F514[0];
      goto LABEL_9;
    }
    if ( n24576 == 4096 )
    {
      *(_DWORD *)(v2 + 64) = 0;
      *(float *)(v2 + 72) = 0.0;
      *(_DWORD *)(v2 + 68) = 0;
      goto LABEL_9;
    }
    if ( n24576 == 0x2000 )
    {
      *(_DWORD *)(v2 + 48) = 0;
      *(float *)(v2 + 56) = 0.0;
      *(_DWORD *)(v2 + 52) = 0;
LABEL_9:
      g_FFX_MagicPostProcTable[*(unsigned __int8 *)(v2 + 186)](a1, a2);
      return a2 + 2;
    }
  }
  return a2 + 2;
}
