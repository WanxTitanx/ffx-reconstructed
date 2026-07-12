// Function: sub_A5B030
// Address: 0xa5b030
// Size: 0xc3
// Prototype: int(void)

int sub_A5B030()
{
  int v0; // esi
  int v1; // eax
  _DWORD *v2; // ecx
  _DWORD *v3; // edx
  _DWORD *v4; // ecx

  v0 = dword_2305834[0];
  v1 = *(unsigned __int8 *)(dword_2305834[0] + 71100);
  *(float *)(dword_2305834[0] + 71072) = 256.0;
  v2 = (_DWORD *)dword_2305834[0];
  *(_DWORD *)(dword_2305834[0] + 70944) = *(_DWORD *)(v0 + 80 * v1 + 69768);
  v2[17737] = *(_DWORD *)(v0 + 80 * v1 + 69772);
  v2[17738] = *(_DWORD *)(v0 + 80 * v1 + 69776);
  v2[17739] = *(_DWORD *)(v0 + 80 * v1 + 69780);
  *(float *)(dword_2305834[0] + 70952) = *(float *)(v0 + 80 * v1 + 69776) - 32.0;
  v3 = (_DWORD *)dword_2305834[0];
  v4 = (_DWORD *)((char *)&unk_C86010 + 16 * *(unsigned __int8 *)(dword_2305834[0] + 71100));
  *(_DWORD *)(dword_2305834[0] + 71008) = *v4;
  v3[17753] = v4[1];
  v3[17754] = v4[2];
  v3[17755] = v4[3];
  *(float *)(dword_2305834[0] + 70956) = *(float *)(dword_2305834[0] + 71072) + *(float *)(dword_2305834[0] + 71072);
  return sub_A47440();
}

