// Function: sub_8A0C70
// Address: 0x8a0c70
char *sub_8A0C70()
{
  char *refreshed; // eax
  int v1; // edx
  char *v2; // ecx
  unsigned __int16 *v3; // esi
  _DWORD *v4; // ecx
  char *result; // eax
  int v6; // [esp+4h] [ebp-4h] BYREF

  unk_1340406[0] = 0;
  unk_134040C = 0;
  unk_1340410 = 0;
  unk_1340404 = 0;
  word_1340408[0] = 0;
  unk_1340430 = 0;
  memset(&unk_13404B8, 0, 0x300u);
  memset(&dword_1340434[1], 0, 0x80u);
  refreshed = (char *)FFX_Btl_RefreshAllActorsCommandStates(&v6);
  v1 = 0;
  v2 = (char *)&unk_13404B9;
  v3 = (unsigned __int16 *)(refreshed + 2);
  do
  {
    *(v2 - 1) = 1;
    *v2 = *((_BYTE *)v3 - 2);
    *(_DWORD *)(v2 + 3) = *v3;
    *(_DWORD *)(v2 + 7) = *v3;
    *(_WORD *)(v2 + 15) = 0;
    v2[11] = v1;
    v2[12] = v1;
    v2[13] = 0;
    *(_WORD *)(v2 + 17) = 22 * v1;
    *(_DWORD *)(v2 + 19) = 0;
    v2 += 24;
    ++v1;
    v3 += 2;
  }
  while ( (int)v2 < (int)unk_1340639 );
  v4 = &dword_1340434[1];
  result = (char *)&unk_13404B8;
  do
  {
    *v4 = result;
    result += 24;
    ++v4;
  }
  while ( (int)result < (int)&unk_1340638 );
  return result;
}
