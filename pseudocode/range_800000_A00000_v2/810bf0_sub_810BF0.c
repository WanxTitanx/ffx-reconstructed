// Function: sub_810BF0
// Address: 0x810bf0
__int16 *__cdecl sub_810BF0(int a1, int a2, int a3, int a4)
{
  unsigned __int16 v4; // si
  int v5; // eax
  float *v6; // ecx
  _DWORD *v7; // eax
  __int16 *v8; // edx
  int v9; // ebx
  int v11; // [esp+24h] [ebp+8h]
  float v12; // [esp+24h] [ebp+8h]
  int v13; // [esp+24h] [ebp+8h]
  float v14; // [esp+24h] [ebp+8h]
  float v15; // [esp+24h] [ebp+8h]
  int v16; // [esp+2Ch] [ebp+10h]

  v4 = *(_WORD *)(a1 + 538);
  v5 = ((int)v4 >> 7) & 0xE;
  v6 = (float *)(a4 + word_C49300[v5]);
  v7 = (_DWORD *)((char *)&unk_C49398 + 16 * v5);
  v8 = (__int16 *)(a3 + 2);
  v16 = v7[2];
  v9 = v7[1];
  if ( (v4 & 0x1000) != 0 )
  {
    v11 = *v7 * *v8++;
    v12 = (float)v11;
    *v6 = v12 * 0.000244140625 + *v6;
  }
  if ( (v4 & 0x2000) != 0 )
  {
    v13 = v9 * *v8++;
    v14 = (float)v13;
    v6[1] = v14 * 0.000244140625 + v6[1];
  }
  if ( (v4 & 0x4000) == 0 )
    return v8;
  v15 = (float)(v16 * *v8);
  v6[2] = 0.000244140625 * v15 + v6[2];
  return v8 + 1;
}
