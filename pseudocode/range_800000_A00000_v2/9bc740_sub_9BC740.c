// Function: sub_9BC740
// Address: 0x9bc740
_DWORD *__thiscall sub_9BC740(_DWORD *this, float a2)
{
  _DWORD *this_1; // eax
  int v3; // edi
  double v4; // st7
  int v5; // esi
  int n2; // eax
  int n2_1; // ecx
  float v9; // [esp-4h] [ebp-10h]
  float v10; // [esp-4h] [ebp-10h]

  this_1 = this;
  v3 = 0;
  if ( (int)*(this + 52) > 0 )
  {
    v4 = a2;
    do
    {
      v5 = *(_DWORD *)(this_1[54] + 4 * v3);
      if ( v5 )
      {
        n2 = *(_DWORD *)(v5 + 228);
        if ( n2 != 2 && n2 != 4 )
        {
          v9 = *(float *)(v5 + 320) * *(float *)(v5 + 320)
             + *(float *)(v5 + 324) * *(float *)(v5 + 324)
             + *(float *)(v5 + 328) * *(float *)(v5 + 328);
          if ( *(float *)(v5 + 492) * *(float *)(v5 + 492) <= v9
            || (v10 = *(float *)(v5 + 336) * *(float *)(v5 + 336)
                    + *(float *)(v5 + 340) * *(float *)(v5 + 340)
                    + *(float *)(v5 + 344) * *(float *)(v5 + 344),
                *(float *)(v5 + 496) * *(float *)(v5 + 496) <= v10) )
          {
            *(_DWORD *)(v5 + 232) = 0;
            sub_97A440(0);
          }
          else
          {
            *(float *)(v5 + 232) = v4 + *(float *)(v5 + 232);
          }
        }
        n2_1 = *(_DWORD *)(v5 + 228);
        if ( n2_1 != 4 )
        {
          if ( unk_193F658
            || *(float *)&dword_C64954 == 0.0
            || n2_1 != 2 && n2_1 != 3 && *(float *)(v5 + 232) <= (double)*(float *)&dword_C64954 )
          {
            sub_97A440(1);
          }
          else if ( (*(_BYTE *)(v5 + 216) & 3) != 0 )
          {
            sub_97A440(2);
          }
          else
          {
            if ( n2_1 == 1 )
              sub_97A440(3);
            if ( *(_DWORD *)(v5 + 228) == 2 )
            {
              *(_DWORD *)(v5 + 336) = 0;
              *(_DWORD *)(v5 + 340) = 0;
              *(_DWORD *)(v5 + 344) = 0;
              *(_DWORD *)(v5 + 348) = 0;
              *(_DWORD *)(v5 + 320) = 0;
              *(_DWORD *)(v5 + 324) = 0;
              *(_DWORD *)(v5 + 328) = 0;
              *(_DWORD *)(v5 + 332) = 0;
            }
          }
        }
      }
      this_1 = this;
      v4 = a2;
      ++v3;
    }
    while ( v3 < *(this + 52) );
  }
  return this_1;
}
