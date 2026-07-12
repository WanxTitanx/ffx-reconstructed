// Function: FFX_Magic_RunPhase0Wrapper_structural
// Address: 0x800530
int FFX_Magic_RunPhase0Wrapper_structural()
{
  int v0; // esi
  int v1; // eax

  v0 = dword_12A4080[0];
  v1 = *(_DWORD *)(dword_12A4080[0] + 88);
  if ( v1 )
  {
    *(_DWORD *)(dword_12A4080[0] + 84) = v1;
    unk_2332E88 = 0;
  }
  else
  {
    *(_DWORD *)(dword_12A4080[0] + 84) = unk_2332E8C;
    unk_2332E88 = unk_2332E90 + 983040;
  }
  FFX_Magic_RunRuntimeRootPhase_structural(0, 0);
  if ( !*(_DWORD *)(v0 + 88) )
    unk_2332E8C = *(_DWORD *)(v0 + 84);
  unk_2332E88 = 0;
  return 0;
}
