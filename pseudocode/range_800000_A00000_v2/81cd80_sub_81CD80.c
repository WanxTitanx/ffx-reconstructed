// Function: sub_81CD80
// Address: 0x81cd80
_WORD *__cdecl sub_81CD80(unsigned __int8 *a1, _WORD *a2)
{
  _WORD *result; // eax
  char v4; // bl
  int v5; // ecx
  int v6; // ecx
  char v7; // bl
  int v8; // edi
  int v9; // edx
  int v10; // edi
  char v11; // cl
  int v12; // edx
  bool v13; // zf
  char v14; // bl
  int v15; // ecx
  int v16; // ecx
  char v17; // bl
  int v18; // edi
  int v19; // edx
  int v20; // edi
  char v21; // cl
  int v22; // edx
  unsigned int v23; // [esp+Ch] [ebp-10h]
  _WORD *v24; // [esp+10h] [ebp-Ch]
  char v25; // [esp+10h] [ebp-Ch]
  char v26; // [esp+14h] [ebp-8h]
  _WORD *v27; // [esp+14h] [ebp-8h]
  int v28; // [esp+18h] [ebp-4h]
  int v29; // [esp+18h] [ebp-4h]
  _BYTE *v30; // [esp+24h] [ebp+8h]
  _BYTE *v31; // [esp+24h] [ebp+8h]
  int n8; // [esp+28h] [ebp+Ch]
  int n8_1; // [esp+28h] [ebp+Ch]

  result = a2;
  v23 = (unsigned int)(a2 + 12800);
  do
  {
    v24 = result + 256;
    do
    {
      v4 = *a1;
      v5 = *a1++;
      v6 = v5 >> 4;
      v7 = v4 & 0xF;
      v30 = a1;
      v28 = v6;
      n8 = 8;
      v26 = v7;
      do
      {
        v8 = unk_12F4F54 * dword_C49474[2 * v6] + dword_12F4F50 * dword_C49470[2 * v6];
        v9 = (__int16)(*a1 << 12) >> v7;
        unk_12F4F54 = dword_12F4F50;
        dword_12F4F50 = v9 + (v8 >> 6);
        *result = dword_12F4F50;
        v10 = unk_12F4F54 * dword_C49474[2 * v28] + dword_12F4F50 * dword_C49470[2 * v28];
        v11 = v7;
        v7 = v26;
        v12 = (__int16)((*v30 & 0xF0) << 8) >> v11;
        v6 = v28;
        unk_12F4F54 = dword_12F4F50;
        dword_12F4F50 = v12 + (v10 >> 6);
        result[1] = dword_12F4F50;
        a1 = v30 + 1;
        result += 2;
        v13 = n8-- == 1;
        ++v30;
      }
      while ( !v13 );
    }
    while ( result < v24 );
    v27 = result + 256;
    do
    {
      v14 = *a1;
      v15 = *a1++;
      v16 = v15 >> 4;
      v17 = v14 & 0xF;
      v31 = a1;
      v29 = v16;
      n8_1 = 8;
      v25 = v17;
      do
      {
        v18 = unk_12F4F5C * dword_C49474[2 * v16] + dword_12F4F58 * dword_C49470[2 * v16];
        v19 = (__int16)(*a1 << 12) >> v17;
        unk_12F4F5C = dword_12F4F58;
        dword_12F4F58 = v19 + (v18 >> 6);
        *result = dword_12F4F58;
        v20 = unk_12F4F5C * dword_C49474[2 * v29] + dword_12F4F58 * dword_C49470[2 * v29];
        v21 = v17;
        v17 = v25;
        v22 = (__int16)((*v31 & 0xF0) << 8) >> v21;
        v16 = v29;
        unk_12F4F5C = dword_12F4F58;
        dword_12F4F58 = v22 + (v20 >> 6);
        result[1] = dword_12F4F58;
        a1 = v31 + 1;
        result += 2;
        v13 = n8_1-- == 1;
        ++v31;
      }
      while ( !v13 );
    }
    while ( result < v27 );
  }
  while ( (unsigned int)result < v23 );
  return result;
}
