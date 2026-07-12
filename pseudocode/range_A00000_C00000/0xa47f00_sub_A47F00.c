// Function: sub_A47F00
// Address: 0xa47f00
// Size: 0x321
// Prototype: 

char sub_A47F00()
{
  int v0; // edx
  int v1; // eax
  int v2; // ecx
  float *v3; // ecx
  int v4; // ecx
  float v6; // [esp+28h] [ebp-28h]
  int v7[4]; // [esp+2Ch] [ebp-24h] BYREF
  int v8; // [esp+3Ch] [ebp-14h] BYREF
  float v9; // [esp+40h] [ebp-10h]
  float v10; // [esp+44h] [ebp-Ch]
  float v11; // [esp+48h] [ebp-8h]

  v0 = dword_2305834[0];
  if ( *(_BYTE *)(dword_2305834[0] + 71244) )
  {
    if ( *(_BYTE *)(dword_2305834[0] + 71244) == 1 )
    {
      v2 = 5 * *(unsigned __int16 *)(dword_2305834[0] + 71220);
      *(float *)&v8 = (float)*(__int16 *)(dword_2305834[0] + 40 * *(unsigned __int16 *)(dword_2305834[0] + 71220) + 2056);
      v9 = (float)*(__int16 *)(dword_2305834[0] + 8 * v2 + 2058);
      v10 = 0.0;
      v11 = 1.0;
      v6 = *(float *)(dword_2305834[0] + 71200) + 0.0833333358168602;
      *(float *)(dword_2305834[0] + 71200) = v6;
      if ( v6 < 1.0 )
      {
        sub_62FF20((int)v7, (int)&v8, dword_2305834[0] + 71228, v6);
        *(float *)(dword_2305834[0] + 70408) = *(float *)v7;
        LOBYTE(v1) = dword_2305834[0];
        *(float *)(dword_2305834[0] + 70412) = *(float *)&v7[1];
      }
      else
      {
        *(_BYTE *)(v0 + 71244) = 2;
        *(_BYTE *)(dword_2305834[0] + 71245) = 0;
        FFX_BtlEffect_Enable(-2147483536);
        v3 = (float *)dword_2305834[0];
        *(float *)(dword_2305834[0] + 70408) = *(float *)&v8;
        v3[17603] = v9;
        v3[17604] = v10;
        v3[17605] = v11;
        FFX_MagicHost_LinkResourceBufferRange(dword_1A86034, dword_16C1830, 512000);
        sub_A5BAD0((int)&unk_1A86060, 1, *(float *)&v8, v9, 0.0, 0.0, 0.0, 0.0, 0.5, 0.5, 0.5);
        *(_WORD *)(dword_2305834[0] + 80 * *(unsigned __int8 *)(dword_2305834[0] + 71224) + 69836) = *(_WORD *)(dword_2305834[0] + 71220);
        sub_A5A990(*(unsigned __int8 *)(dword_2305834[0] + 71224));
        sub_A58080(*(unsigned __int8 *)(dword_2305834[0] + 71224));
        *(_BYTE *)(dword_2305834[0] + 71111) = 1;
        LOBYTE(v1) = sub_A5B030();
      }
    }
    else
    {
      LOBYTE(v1) = *(_BYTE *)(dword_2305834[0] + 71244) - 2;
      if ( *(_BYTE *)(dword_2305834[0] + 71244) == 2 )
      {
        *(_BYTE *)(dword_2305834[0] + 71110) = (char)(++*(_BYTE *)(dword_2305834[0] + 71245) << 7) / 40;
        v1 = dword_2305834[0];
        if ( *(_BYTE *)(dword_2305834[0] + 71110) >= 0x80u )
        {
          *(_BYTE *)(dword_2305834[0] + 71110) = 0x80;
          v1 = dword_2305834[0];
        }
        if ( !unk_1A8607E )
        {
          *(_BYTE *)(v1 + 71110) = 0x80;
          *(_DWORD *)(dword_2305834[0] + 71080) = *(_DWORD *)(dword_2305834[0] + 71088);
          *(_DWORD *)(dword_2305834[0] + 71088) = 0;
          *(_DWORD *)(dword_2305834[0] + 71084) = *(_DWORD *)(dword_2305834[0] + 71092);
          LOBYTE(v1) = dword_2305834[0];
          *(_DWORD *)(dword_2305834[0] + 71092) = 0;
        }
      }
    }
  }
  else
  {
    LOBYTE(v1) = 0x80 - (char)(++*(_BYTE *)(dword_2305834[0] + 71245) << 7) / 40;
    *(_BYTE *)(dword_2305834[0] + 71110) = v1;
    v4 = dword_2305834[0];
    if ( *(_BYTE *)(dword_2305834[0] + 71110) >= 0x80u )
    {
      *(_BYTE *)(dword_2305834[0] + 71110) = 0x80;
      v4 = dword_2305834[0];
    }
    if ( !unk_1A8607E )
    {
      *(float *)(v4 + 80 * *(unsigned __int8 *)(v4 + 71224) + 69828) = 0.0;
      *(_BYTE *)(dword_2305834[0] + 71244) = 1;
      LOBYTE(v1) = dword_2305834[0];
      *(_BYTE *)(dword_2305834[0] + 71110) = 0;
    }
  }
  return v1;
}

