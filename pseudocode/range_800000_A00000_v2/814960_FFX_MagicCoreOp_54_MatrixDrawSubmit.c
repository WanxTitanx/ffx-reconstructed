// Function: FFX_MagicCoreOp_54_MatrixDrawSubmit
// Address: 0x814960
// [Jarvis naming goal 2026-06-17 pass2] Magic core opcode 0x54: builds matrix from record transforms and submits draw via sub_A69300.
int __cdecl FFX_MagicCoreOp_54_MatrixDrawSubmit(int a1, int a2)
{
  int v3; // esi
  int v4; // eax
  float v6; // [esp+18h] [ebp+8h]

  v3 = *(_DWORD *)(a1 + 544);
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0x1000 )
    {
      v6 = *(float *)(v3 + 60) * 0.0009765625;
      sub_7EA610((void *)(a1 + 128), v6);
      sub_7E9760(a1 + 128, a1 + 128, v3 + 48, v3 + 144);
      v4 = sub_801E20((_DWORD *)a1, (unsigned __int16 *)v3);
      sub_7E82C0(a1 + 128, v4, a1 + 128);
      sub_7E82C0(a1 + 192, a1 + 704, a1 + 128);
      sub_A69300(109051904, a1 + 192, &unk_1F00000);
      return a2 + 2;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    sub_908420(109051904, 0);
    return a2 + 2;
  }
}
