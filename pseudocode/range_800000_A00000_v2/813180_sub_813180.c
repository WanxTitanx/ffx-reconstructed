// Function: sub_813180
// Address: 0x813180
int __cdecl sub_813180(_DWORD *a1, _DWORD *a2)
{
  int v2; // esi
  int v3; // eax
  __int16 v4; // cx
  float v5; // ebx
  int v6; // edx
  char v7; // al
  int v8; // ebx
  __int16 v9; // di
  int v10; // ecx
  int v11; // edx
  __int16 v12; // cx
  float v13; // ebx
  int v14; // edx
  float v15; // edi
  int v16; // ecx
  int v17; // edx
  int result; // eax
  int v19; // [esp+14h] [ebp-34h]
  int v20; // [esp+18h] [ebp-30h]
  int v21; // [esp+20h] [ebp-28h]
  int v22; // [esp+20h] [ebp-28h]
  char v23; // [esp+27h] [ebp-21h]
  char v24; // [esp+2Bh] [ebp-1Dh]
  char v25; // [esp+37h] [ebp-11h]
  __int16 v26; // [esp+3Ah] [ebp-Eh]

  v2 = a1[136];
  v19 = sub_800F80(a2, v2, *(_WORD *)(v2 + 168));
  v20 = a2[21];
  v3 = sub_801E20(a1, (unsigned __int16 *)v2);
  sub_7E82C0(a1, a1 + 176, v3);
  *(_DWORD *)(v20 + 16) = 32769;
  *(_DWORD *)(v20 + 24) = 267294;
  *(_BYTE *)(v20 + 32) = *(_BYTE *)(v2 + 194);
  *(_BYTE *)(v20 + 52) = *(_BYTE *)(v2 + 195);
  *(_DWORD *)(v20 + 40) = 66;
  v4 = word_C8F508[0];
  v5 = word_C8F50C;
  v6 = *(_DWORD *)(v2 + 200);
  v21 = *(_DWORD *)(v2 + 204);
  v23 = HIBYTE(word_C8F50A);
  *(_BYTE *)(v2 + 205) = word_C8F50A;
  *(_BYTE *)(v2 + 207) = v23;
  *(_BYTE *)(v2 + 209) = LOBYTE(v5);
  *(_BYTE *)(v2 + 211) = BYTE1(v5);
  v24 = HIBYTE(v5);
  v7 = BYTE2(v5);
  v8 = v2;
  *(_BYTE *)(v2 + 201) = v4;
  *(_BYTE *)(v2 + 213) = v7;
  *(_BYTE *)(v2 + 215) = v24;
  *(_BYTE *)(v2 + 203) = HIBYTE(v4);
  *(_BYTE *)(v2 + 204) = BYTE2(v6);
  *(_BYTE *)(v2 + 206) = HIBYTE(v6);
  *(_BYTE *)(v2 + 208) = v21;
  *(_BYTE *)(v2 + 210) = BYTE1(v21);
  *(_BYTE *)(v2 + 212) = BYTE2(v21);
  *(_BYTE *)(v2 + 200) = v6;
  *(_BYTE *)(v2 + 202) = BYTE1(v6);
  *(_BYTE *)(v2 + 214) = HIBYTE(v21);
  LOWORD(v2) = word_C8F508[0];
  v9 = LOWORD(word_C8F50C);
  v26 = unk_C8F50E;
  v10 = *(_DWORD *)(v8 + 200);
  v11 = *(_DWORD *)(v8 + 204);
  *(_WORD *)(v8 + 206) = word_C8F50A;
  *(_WORD *)(v8 + 214) = v26;
  *(_WORD *)(v8 + 202) = v2;
  *(_WORD *)(v8 + 210) = v9;
  *(_WORD *)(v8 + 204) = HIWORD(v10);
  *(_WORD *)(v8 + 200) = v10;
  *(_WORD *)(v8 + 208) = v11;
  *(_WORD *)(v8 + 212) = HIWORD(v11);
  *(_DWORD *)(v20 + 48) = *(_DWORD *)(v8 + 200);
  *(_DWORD *)(v20 + 52) = *(_DWORD *)(v8 + 204);
  *(_DWORD *)(v20 + 56) = *(_DWORD *)(v8 + 208);
  *(_DWORD *)(v20 + 60) = *(_DWORD *)(v8 + 212);
  sub_7E9A60(v20 + 64, a1, v8 + 144);
  v12 = word_C8F508[0];
  v13 = word_C8F50C;
  v14 = *(_DWORD *)(v19 + 200);
  v22 = *(_DWORD *)(v19 + 204);
  v25 = HIBYTE(word_C8F50A);
  *(_BYTE *)(v19 + 205) = word_C8F50A;
  *(_BYTE *)(v19 + 207) = v25;
  *(_BYTE *)(v19 + 209) = LOBYTE(v13);
  *(_BYTE *)(v19 + 211) = BYTE1(v13);
  *(_BYTE *)(v19 + 201) = v12;
  *(_BYTE *)(v19 + 213) = BYTE2(v13);
  *(_BYTE *)(v19 + 215) = HIBYTE(v13);
  *(_BYTE *)(v19 + 203) = HIBYTE(v12);
  *(_BYTE *)(v19 + 204) = BYTE2(v14);
  *(_BYTE *)(v19 + 206) = HIBYTE(v14);
  *(_BYTE *)(v19 + 208) = v22;
  *(_BYTE *)(v19 + 210) = BYTE1(v22);
  *(_BYTE *)(v19 + 212) = BYTE2(v22);
  *(_BYTE *)(v19 + 200) = v14;
  *(_BYTE *)(v19 + 202) = BYTE1(v14);
  *(_BYTE *)(v19 + 214) = HIBYTE(v22);
  LOWORD(v2) = word_C8F508[0];
  v15 = word_C8F50C;
  v16 = *(_DWORD *)(v19 + 200);
  v17 = *(_DWORD *)(v19 + 204);
  *(_WORD *)(v19 + 206) = word_C8F50A;
  *(_WORD *)(v19 + 202) = v2;
  *(_WORD *)(v19 + 210) = LOWORD(v15);
  *(_WORD *)(v19 + 214) = HIWORD(v15);
  *(_WORD *)(v19 + 204) = HIWORD(v16);
  *(_WORD *)(v19 + 200) = v16;
  *(_WORD *)(v19 + 208) = v17;
  *(_WORD *)(v19 + 212) = HIWORD(v17);
  *(_DWORD *)(v20 + 80) = *(_DWORD *)(v19 + 200);
  *(_DWORD *)(v20 + 84) = *(_DWORD *)(v19 + 204);
  *(_DWORD *)(v20 + 88) = *(_DWORD *)(v19 + 208);
  *(_DWORD *)(v20 + 92) = *(_DWORD *)(v19 + 212);
  sub_7E9A60(v20 + 96, a1, v19 + 144);
  result = nullsub_97(a2[21], (v20 + 112 - a2[21]) / 16, 0, 0);
  a2[21] = v20 + 112;
  return result;
}
