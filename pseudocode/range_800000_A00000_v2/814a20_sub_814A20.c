// Function: sub_814A20
// Address: 0x814a20
_WORD *__cdecl sub_814A20(int a1, _WORD *a2)
{
  _WORD *v2; // edi
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // esi
  int v8; // eax

  v2 = a2;
  switch ( a2[1] )
  {
    case 0:
      sub_829F70((__int16)a2[2]);
      return a2 + 3;
    case 1:
      if ( sub_82A0C0((__int16)a2[2]) != 1 )
        return a2 + 3;
      goto LABEL_4;
    case 2:
      sub_836AC0((__int16)a2[2], (__int16)a2[3]);
      return a2 + 4;
    case 3:
      if ( sub_836AD0((__int16)a2[2], (__int16)a2[3]) == 1 )
      {
LABEL_4:
        *(_BYTE *)(a1 + 528) = 1;
        return a2;
      }
      else
      {
        sub_8368F0((__int16)a2[2], (__int16)a2[3]);
        return a2 + 4;
      }
    case 4:
      v4 = (__int16)a2[2];
      FFX_Chr_AllocateActiveInstance(v4);
      v5 = *((_DWORD *)&unk_12A2280 + 8 * sub_7FE9C0(v4));
      if ( v5 )
      {
        v6 = sub_826BF0(v5);
        sub_63C550(v6, 0);
      }
      return a2 + 3;
    case 5:
      v7 = (__int16)a2[2];
      v8 = *((_DWORD *)&unk_12A2280 + 8 * sub_7FE9C0(v7));
      if ( v8 )
      {
        sub_826770(v8);
        sub_824F90(v7, 1);
        sub_8368B0(v7, (__int16)a2[3]);
      }
      return a2 + 4;
    default:
      return v2;
  }
}
