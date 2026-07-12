// Function: sub_A48740
// Address: 0xa48740
// Size: 0x1cf
// Prototype: 

int __cdecl sub_A48740(int a1, int a2)
{
  int v3; // edi
  _DWORD *v4; // esi
  int v5; // ecx
  int result; // eax
  int v7; // ecx
  float v8; // [esp+4h] [ebp-34h]
  float v9; // [esp+8h] [ebp-30h]
  float v10; // [esp+Ch] [ebp-2Ch]
  float v11; // [esp+10h] [ebp-28h]
  float v12; // [esp+14h] [ebp-24h]
  float v13; // [esp+18h] [ebp-20h]
  float v14; // [esp+1Ch] [ebp-1Ch]
  float v15; // [esp+20h] [ebp-18h]
  int v16; // [esp+44h] [ebp+Ch]
  float v17; // [esp+44h] [ebp+Ch]
  float v18; // [esp+44h] [ebp+Ch]

  v3 = 5 * a2;
  v16 = dword_2305834[0];
  v4 = (_DWORD *)sub_785350();
  FFX_MagicHost_LinkResourceBufferRange(dword_1A86034, dword_16C1830, 512000);
  v5 = v16;
  v15 = 0.5;
  v14 = 0.5;
  v13 = 0.5;
  v12 = 0.0;
  v11 = 0.0;
  v10 = 0.0;
  v9 = 0.0;
  v17 = (float)*(__int16 *)(v16 + 8 * v3 + 2058);
  v8 = v17;
  v18 = (float)*(__int16 *)(v5 + 8 * v3 + 2056);
  if ( (*v4 & 0xC000) == 0x8000 )
    sub_A5BAD0((int)&unk_1A86060, 5, v18, v8, v9, v10, v11, v12, v13, v14, v15);
  else
    sub_A5BAD0((int)&unk_1A86060, 3, v18, v8, v9, v10, v11, v12, v13, v14, v15);
  *(float *)(dword_2305834[0] + 71208) = (double)(*(__int16 *)(dword_2305834[0]
                                                             + 48
                                                             * *(unsigned __int16 *)(dword_2305834[0] + 8 * v3 + 2062)
                                                             + 63540) >> 1)
                                       + 3.0;
  *(float *)(dword_2305834[0] + 71212) = (double)(*(__int16 *)(dword_2305834[0] + 48 * a1 + 63540) >> 1) + 3.0;
  *(_BYTE *)(dword_2305834[0] + 71248) = 0;
  *(_WORD *)(dword_2305834[0] + 71244) = a1;
  *(_WORD *)(dword_2305834[0] + 71246) = a2;
  result = sub_A5A640(a1, a2);
  v7 = dword_2305834[0];
  if ( !*(_DWORD *)(dword_2305834[0] + 71092) )
  {
    *(_DWORD *)(dword_2305834[0] + 71092) = *(_DWORD *)(dword_2305834[0] + 71084);
    result = dword_2305834[0];
    *(_DWORD *)(dword_2305834[0] + 71084) = sub_A51700;
    v7 = dword_2305834[0];
  }
  if ( !*(_DWORD *)(v7 + 71088) )
  {
    *(_DWORD *)(v7 + 71088) = *(_DWORD *)(v7 + 71080);
    result = dword_2305834[0];
    *(_DWORD *)(dword_2305834[0] + 71080) = sub_A47D50;
  }
  return result;
}

