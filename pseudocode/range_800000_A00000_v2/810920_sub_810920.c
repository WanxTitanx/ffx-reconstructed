// Function: sub_810920
// Address: 0x810920
__int16 *__cdecl sub_810920(int a1, int a2, int a3, int a4)
{
  unsigned __int16 v4; // di
  _DWORD *v5; // eax
  __int16 *v6; // edx
  float *v7; // esi
  int v9; // [esp+1Ch] [ebp-4h]
  int v10; // [esp+28h] [ebp+8h]
  float v11; // [esp+28h] [ebp+8h]
  int v12; // [esp+28h] [ebp+8h]
  float v13; // [esp+28h] [ebp+8h]
  float v14; // [esp+28h] [ebp+8h]
  int v15; // [esp+30h] [ebp+10h]

  v4 = *(_WORD *)(a1 + 538);
  v5 = (_DWORD *)((char *)&unk_C49398 + 16 * (((int)v4 >> 7) & 0xE));
  v6 = (__int16 *)(a3 + 2);
  v15 = v5[1];
  v9 = v5[2];
  v7 = (float *)(a4 + word_C49300[((int)v4 >> 7) & 0xE]);
  if ( (v4 & 0x1000) != 0 )
  {
    v10 = *v5 * *v6++;
    v11 = (float)v10;
    *v7 = v11 * 0.000244140625;
  }
  if ( (v4 & 0x2000) != 0 )
  {
    v12 = v15 * *v6++;
    v13 = (float)v12;
    v7[1] = v13 * 0.000244140625;
  }
  if ( (v4 & 0x4000) == 0 )
    return v6;
  v14 = (float)(v9 * *v6);
  v7[2] = 0.000244140625 * v14;
  return v6 + 1;
}
