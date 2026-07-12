// Function: FFX_Magic_RunPhase1Wrapper_structural
// Address: 0x800590
int FFX_Magic_RunPhase1Wrapper_structural()
{
  sub_7E4630();
  sub_7E4D90(-1);
  FFX_Magic_ProcessPendingQueue_structural();
  if ( !*(_DWORD *)(dword_12A4080[0] + 88) )
  {
    *(_DWORD *)(dword_12A4080[0] + 84) = unk_2332E8C;
    unk_2332E88 = unk_2332E90 + 983040;
  }
  sub_7BFFF0(&unk_113FCB0);
  sub_7BB9D0(&n1065353216_0);
  FFX_Magic_RunRuntimeRootPhase_structural(0, 1u);
  FFX_Magic_RunAuxRuntimeRootPass_structural(0);
  if ( !*(_DWORD *)(dword_12A4080[0] + 88) )
    unk_2332E8C = *(_DWORD *)(dword_12A4080[0] + 84);
  unk_2332E88 = 0;
  return 0;
}
