// Function: sub_814680
// Address: 0x814680
int __cdecl sub_814680(int a1, int a2)
{
  int v2; // edx
  int v3; // esi
  int v4; // ebx
  float v5; // edi
  char v7; // al
  int v8; // eax
  int n256; // ebx
  int v10; // eax
  bool v11; // zf

  v2 = *(_DWORD *)(a1 + 544);
  v3 = a2;
  v4 = *(unsigned __int8 *)(v2 + 24);
  v5 = flt_12A80C0[v4];
  switch ( *(_WORD *)(a2 + 2) )
  {
    case 1:
      if ( ++*(_BYTE *)(a1 + 826) >= 0xFAu )
        *(_BYTE *)(a1 + 826) = -6;
      return a2 + 4;
    case 2:
      v7 = *(_BYTE *)(a1 + 826);
      if ( v7 )
        *(_BYTE *)(a1 + 826) = v7 - 1;
      return a2 + 4;
    case 3:
      if ( *(_BYTE *)(a1 + 826) >= 0xAu )
        return *(__int16 *)(a2 + 4) + a2;
      return a2 + 6;
    case 4:
      *(_DWORD *)a1 = word_C8F508[0];
      *(float *)(a1 + 4) = word_C8F50C;
      *(float *)(a1 + 8) = word_C8F510;
      *(float *)(a1 + 12) = word_C8F514[0];
      *(float *)(a1 + 4) = *(float *)(v2 + 52);
      nullsub_101(*(unsigned __int8 *)(v2 + 24), v2 + 144, a1);
      return a2 + 4;
    case 5:
      sub_7FBE10(LODWORD(v5), *(_WORD *)(a2 + 4));
      return a2 + 6;
    case 6:
      sub_7FB9D0(LODWORD(flt_12A80C0[v4]));
      return a2 + 4;
    case 7:
      sub_7FB960(LODWORD(flt_12A80C0[v4]));
      return a2 + 4;
    case 8:
      sub_7FBAB0(LODWORD(flt_12A80C0[v4]));
      return a2 + 4;
    case 9:
      sub_7FB1B0(LODWORD(flt_12A80C0[v4]));
      return a2 + 4;
    case 0xA:
      sub_7FC0B0(LODWORD(flt_12A80C0[v4]));
      return a2 + 4;
    case 0xB:
      sub_7FC050(LODWORD(flt_12A80C0[v4]));
      return a2 + 4;
    case 0xC:
      *(_BYTE *)(v2 + 179) = 127;
      return a2 + 4;
    case 0xD:
      v8 = sub_800F50(*(unsigned __int8 *)(v2 + 24));
      if ( !dword_119FE80[v8] || byte_119FEDC[v8] <= 32 )
        return a2 + 6;
      return *(__int16 *)(a2 + 4) + a2;
    case 0xE:
      n256 = 256;
      goto LABEL_28;
    case 0xF:
      n256 = 512;
      goto LABEL_28;
    case 0x10:
      n256 = 0x2000;
      goto LABEL_28;
    case 0x11:
      n256 = 4096;
      goto LABEL_28;
    case 0x12:
      n256 = 2048;
LABEL_28:
      if ( sub_82AC50(LODWORD(v5)) )
        return *(__int16 *)(a2 + 4) + a2;
      v10 = sub_7FE890(LODWORD(v5), 0, 0);
      if ( v10 < 0 )
        return *(__int16 *)(a2 + 4) + a2;
      if ( ((unk_11A0060 | *((unsigned __int16 *)&unk_12A228C + 16 * v10)) & (n256 | 0x4020)) == 0 )
        return a2 + 6;
      return *(__int16 *)(a2 + 4) + a2;
    case 0x13:
      v11 = (unk_11A004E & 1) == 0;
      goto LABEL_34;
    case 0x14:
      v11 = (unk_11A004E & 2) == 0;
LABEL_34:
      if ( !v11 )
        return *(__int16 *)(a2 + 4) + a2;
      return a2 + 6;
    default:
      return v3;
  }
}
