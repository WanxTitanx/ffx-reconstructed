// Function: FFX_MagicCoreOp_FF_MatrixComposeToRecord
// Address: 0x801c20
__int16 *__cdecl FFX_MagicCoreOp_FF_MatrixComposeToRecord(__int16 *a1, __int16 *a2)
{
  int v2; // edi
  __int16 v4; // dx
  double v5; // st7
  __int16 *v6; // ebx
  int v8; // [esp+0h] [ebp-18h]
  int v9; // [esp+24h] [ebp+Ch]

  v2 = *((_DWORD *)a1 + 136);
  if ( (a1[269] & 0x400) != 0 )
  {
    v4 = a2[3];
    v5 = (double)a2[1];
    v9 = a2[2];
    *(float *)a1 = v5;
    *(float *)a1 = *(float *)a1 * 0.00390625;
    *((float *)a1 + 1) = (double)v9 * 0.00390625;
    *((float *)a1 + 2) = 0.00390625 * (double)v4;
    sub_7EA640(a1, (int)a1);
    v6 = a2 + 4;
  }
  else
  {
    sub_7EA610(a1, 1.0);
    v6 = a2 + 1;
  }
  v8 = (a1[269] >> 12) & 7;
  *(_BYTE *)(v2 + 25) = v8;
  sub_7E97C0(a1, a1, v2 + 48, v2 + 144, v8);
  if ( (a1[269] & 0x800) != 0 )
  {
    if ( (a1[269] & 0x200) != 0 )
    {
      sub_7E8A10(v2 + 192, a1 + 320, a1);
      n1065353216 = *((_DWORD *)a1 + 12);
      unk_C8F52C = *((_DWORD *)a1 + 13);
      unk_C8F530 = *((_DWORD *)a1 + 14);
      unk_C8F534 = *((_DWORD *)a1 + 15);
      *(_DWORD *)(v2 + 240) = n1065353216;
      *(_DWORD *)(v2 + 244) = unk_C8F52C;
      *(_DWORD *)(v2 + 248) = unk_C8F530;
      *(_DWORD *)(v2 + 252) = unk_C8F534;
    }
    else
    {
      sub_7E7F20(v2 + 192, a1);
    }
    return v6;
  }
  else
  {
    if ( (a1[269] & 0x200) != 0 )
    {
      sub_7E78B0(a1 + 24, a1 + 320, a1 + 24);
      sub_7E7F20(v2 + 192, a1);
    }
    else
    {
      sub_7E82C0(v2 + 192, a1 + 320, a1);
    }
    return v6;
  }
}
