// Function: sub_816180
// Address: 0x816180
int __cdecl sub_816180(int a1, int a2)
{
  int v2; // esi
  char *v3; // eax
  char v4; // cl
  int result; // eax
  unsigned __int8 v6; // cl
  int v7; // eax
  int v8; // esi
  int v9; // eax
  unsigned __int8 n0x20; // al
  int v11; // edi
  int v12; // eax
  int v13; // eax

  v2 = *(_DWORD *)(a1 + 544);
  v3 = (char *)&unk_12A40C0 + 32 * *(unsigned __int16 *)(v2 + 20);
  switch ( *(unsigned __int16 *)(a1 + 538) >> 12 )
  {
    case 0:
      v4 = v3[16];
      if ( v4 == -1 )
        v4 = v3[24];
      *(_BYTE *)(v2 + 24) = v4;
      result = a2 + 2;
      break;
    case 1:
      if ( *(_BYTE *)(a1 + 542) )
        *(_BYTE *)(v2 + 24) = *(_BYTE *)(a2 + 2);
      result = a2 + 4;
      break;
    case 2:
      if ( !*(_BYTE *)(a1 + 542) )
      {
        v8 = *(unsigned __int16 *)(a2 + 2);
        LODWORD(flt_12A80C0[v8]) = sub_86AE70(v8);
      }
      result = a2 + 4;
      break;
    case 3:
      if ( unk_2322790 )
      {
        v6 = *(_BYTE *)(a2 + 2);
        if ( !LODWORD(flt_12A80C0[v6]) )
        {
          v7 = sub_7FCED0(0);
          v6 = *((_BYTE *)&unk_12A2280 + 32 * sub_7FE890(v7, 0, 0) + 14);
        }
        *(_BYTE *)(v2 + 24) = v6;
      }
      result = a2 + 4;
      break;
    case 5:
      v9 = sub_7FE9C0(*(__int16 *)(a2 + 2));
      if ( v9 >= 0 )
        *(_BYTE *)(v2 + 24) = *((_BYTE *)&unk_12A228E + 32 * v9);
      result = a2 + 4;
      break;
    case 6:
      n0x20 = sub_788ED0(*(_BYTE *)(v2 + 24));
      v11 = a2;
      *(_BYTE *)(v2 + 24) = n0x20;
      if ( n0x20 >= 0x20u )
        goto LABEL_26;
      result = a2 + 4;
      break;
    case 8:
      *(_BYTE *)(v2 + 24) = v3[24];
      result = a2 + 2;
      break;
    case 9:
      v12 = sub_795B50(*(unsigned __int8 *)(v2 + 24), 0);
      goto LABEL_24;
    case 0xA:
      v12 = sub_795B50(*(unsigned __int8 *)(v2 + 24), 1);
LABEL_24:
      if ( v12 )
      {
        v13 = sub_7FE890(v12, 0, 0);
        if ( v13 >= 0 )
          *(_BYTE *)(v2 + 24) = *((_BYTE *)&unk_12A228E + 32 * v13);
        result = a2 + 4;
      }
      else
      {
        v11 = a2;
LABEL_26:
        result = *(__int16 *)(v11 + 2) + v11;
      }
      break;
    default:
      result = a2;
      break;
  }
  return result;
}
