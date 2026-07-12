// Function: sub_8FDC00
// Address: 0x8fdc00
_DWORD *__cdecl sub_8FDC00(float *src, float *a2)
{
  _DWORD *v2; // eax
  int n8; // edi
  int n11964; // esi
  int n11964_1; // [esp-48h] [ebp-54h]
  int srca; // [esp+14h] [ebp+8h]

  v2 = dword_187168C;
  *dword_187168C = 32769;
  v2[1] = -1867825152;
  v2[2] = 875687662;
  v2[3] = 4;
  n8 = *((_BYTE *)src + 27) & 0xF;
  dword_187168C = v2 + 4;
  if ( n8 >= 8 )
  {
    n11964 = 11964;
    n8 -= 8;
  }
  else
  {
    n11964 = 11960;
  }
  srca = n11964;
  sub_8FABE0(1, 7, 0, 0, 0, 0, 0, 0);
  sub_8FAA20(0, 1, 0, 1, 128);
  n11964_1 = n11964;
  sub_8FAC10(*(__int16 *)a2, 2, 19, 7, 10, 1, 0, n11964_1, 0, 0, 0, 1);
  sub_8FAC10(*(__int16 *)a2, 2, *((__int16 *)a2 + 1), 7, 10, 1, 0, srca, 0, 0, *((__int16 *)a2 + 2) + 2 * n8, 0);
  sub_8FAB80(*(unsigned __int8 *)src, *((unsigned __int8 *)src + 1), *((unsigned __int8 *)src + 2), 96);
  sub_8FACA0((int)a2[2], (int)a2[3]);
  sub_8FAD50((int)src[1], (int)(src[2] + a2[6]), 1);
  sub_8FACA0((int)a2[4], (int)a2[5]);
  sub_8FACF0((int)(a2[7] + src[1]), (int)(src[2] + a2[6] + a2[8]));
  return sub_8F3A30();
}
