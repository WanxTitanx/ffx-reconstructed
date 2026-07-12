// Function: sub_8E4790
// Address: 0x8e4790
int __cdecl sub_8E4790(int a1, int a2, int *a3, int n2, __int16 n357, char a6)
{
  int v6; // eax
  int n2_1; // edx
  int v8; // ebx
  int v9; // ecx
  int *v10; // eax
  _DWORD *v11; // ebx
  int v12; // esi
  int v13; // esi
  int v14; // edi
  int v15; // eax
  bool v16; // zf
  int n497; // ecx
  int n497_1; // eax
  int n0x80; // eax
  int v21; // [esp+4h] [ebp-4h]
  int v22; // [esp+10h] [ebp+8h]
  int v23; // [esp+14h] [ebp+Ch]
  int v24; // [esp+18h] [ebp+10h]
  int n357a; // [esp+20h] [ebp+18h]

  v6 = sub_8AA150();
  n2_1 = n2;
  v8 = v6;
  *(_DWORD *)(v6 + 28) = a1;
  *(_WORD *)(v6 + 78) = n357;
  v9 = 0;
  v21 = v6;
  *(_DWORD *)(v6 + 8) = nullsub_157;
  *(_DWORD *)(v6 + 12) = sub_8E3880;
  *(_DWORD *)(v6 + 16) = sub_8E3CF0;
  *(_DWORD *)(v6 + 20) = sub_8E4A60;
  *(_WORD *)(v6 + 48) = n2;
  *(_DWORD *)(v6 + 70) = 4096;
  *(_BYTE *)(v6 + 66) = 1;
  *(_DWORD *)(v6 + 54) = 259;
  *(_BYTE *)(v6 + 62) = 2;
  *(_BYTE *)(v6 + 68) = a6;
  v22 = 0;
  if ( n2 > 0 )
  {
    v10 = a3;
    v11 = (_DWORD *)(v8 + 92);
    v12 = a2 - (_DWORD)a3;
    v23 = a2 - (_DWORD)a3;
    n357a = n2;
    do
    {
      v13 = *(int *)((char *)v10 + v12);
      v14 = *v10;
      v24 = (int)(v10 + 1);
      v15 = sub_8C2C90(v13);
      v9 = v15 + v22;
      v16 = n357a-- == 1;
      *(v11 - 1) = v13;
      v12 = v23;
      v11[1] = v15;
      v10 = (int *)v24;
      *v11 = v14;
      v22 = v9;
      v11 += 3;
    }
    while ( !v16 );
    v8 = v21;
    n2_1 = n2;
  }
  n497 = 32 * n2_1 - 32 + v9;
  *(_DWORD *)(v8 + 144) = 0;
  n497_1 = *(__int16 *)(v8 + 78);
  *(_WORD *)(v8 + 58) = n497;
  if ( n497_1 < n497 && n497 < 497 )
    *(_WORD *)(v8 + 78) = 496;
  if ( n2_1 <= 1
    || (n0x80 = (*(__int16 *)(v8 + 78) - n497 - 96) / (n2_1 - 1),
        *(_WORD *)(v8 + 60) = n0x80,
        (unsigned __int16)n0x80 < 0x20u) )
  {
    *(_WORD *)(v8 + 60) = 32;
    sub_8AAAB0(v8);
    return v8;
  }
  else
  {
    if ( (unsigned __int16)n0x80 <= 0x80u )
      *(_WORD *)(v8 + 60) = n0x80;
    else
      *(_WORD *)(v8 + 60) = 128;
    sub_8AAAB0(v8);
    return v8;
  }
}
