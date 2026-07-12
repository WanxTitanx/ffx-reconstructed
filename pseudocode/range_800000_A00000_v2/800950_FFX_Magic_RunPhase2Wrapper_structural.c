// Function: FFX_Magic_RunPhase2Wrapper_structural
// Address: 0x800950
int FFX_Magic_RunPhase2Wrapper_structural()
{
  int v0; // esi

  v0 = unk_12A4080;
  if ( !*(_DWORD *)(unk_12A4080 + 88) )
  {
    *(_DWORD *)(unk_12A4080 + 84) = unk_2332E8C;
    unk_2332E88 = unk_2332E90 + 983040;
  }
  FFX_Magic_RunRuntimeRootPhase_structural(0, 2u);
  if ( !*(_DWORD *)(v0 + 88) )
    unk_2332E8C = *(_DWORD *)(v0 + 84);
  unk_2332E88 = 0;
  return 0;
}
