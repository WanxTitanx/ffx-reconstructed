// Function: sub_A48A80
// Address: 0xa48a80
// Size: 0x19c
// Prototype: 

int __cdecl sub_A48A80(int a1, __int16 a2)
{
  char v2; // bl
  int v3; // edi
  int v4; // esi
  int result; // eax
  int v6; // ecx
  float v7; // [esp+4h] [ebp-2Ch]
  float v8; // [esp+38h] [ebp+8h]
  float v9; // [esp+38h] [ebp+8h]
  float v10; // [esp+38h] [ebp+8h]
  float v11; // [esp+38h] [ebp+8h]

  v2 = a1;
  v3 = dword_2305834[0];
  v4 = 5 * *(unsigned __int16 *)(dword_2305834[0] + 80 * a1 + 69836);
  FFX_BtlEffect_Enable(-2147483536);
  *(_BYTE *)(dword_2305834[0] + 71244) = 0;
  *(_BYTE *)(dword_2305834[0] + 71245) = 0;
  v8 = (float)*(__int16 *)(v3 + 8 * v4 + 2056);
  *(float *)(dword_2305834[0] + 70408) = v8;
  *(float *)(dword_2305834[0] + 71228) = v8;
  v9 = (float)*(__int16 *)(v3 + 8 * v4 + 2058);
  *(float *)(dword_2305834[0] + 70412) = v9;
  *(float *)(dword_2305834[0] + 71232) = v9;
  *(float *)(dword_2305834[0] + 71200) = 0.0;
  *(_WORD *)(dword_2305834[0] + 71220) = a2;
  *(_BYTE *)(dword_2305834[0] + 71224) = v2;
  FFX_MagicHost_LinkResourceBufferRange(dword_1A86034, dword_16C1830, 512000);
  v10 = (float)*(__int16 *)(v3 + 8 * v4 + 2058);
  v7 = v10;
  v11 = (float)*(__int16 *)(v3 + 8 * v4 + 2056);
  result = sub_A5BAD0((int)&unk_1A86060, 2, v11, v7, 0.0, 0.0, 0.0, 0.0, 0.5, 0.5, 0.5);
  v6 = dword_2305834[0];
  if ( !*(_DWORD *)(dword_2305834[0] + 71092) )
  {
    *(_DWORD *)(dword_2305834[0] + 71092) = *(_DWORD *)(dword_2305834[0] + 71084);
    result = dword_2305834[0];
    *(_DWORD *)(dword_2305834[0] + 71084) = sub_A4C430;
    v6 = dword_2305834[0];
  }
  if ( !*(_DWORD *)(v6 + 71088) )
  {
    *(_DWORD *)(v6 + 71088) = *(_DWORD *)(v6 + 71080);
    result = dword_2305834[0];
    *(_DWORD *)(dword_2305834[0] + 71080) = sub_A47F00;
  }
  return result;
}

