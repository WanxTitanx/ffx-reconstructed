// Function: FFX_Magic_RunPhase2Wrapper_structural
// Address: 0x800950
// Size: 0x47

int FFX_Magic_RunPhase2Wrapper_structural()
{
  int result; // eax

  sub_7E4D90(0);
  sub_7BFFF0(&unk_113FCB0);
  sub_7BB9D0(&unk_113FCF0);
  FFX_Magic_RunRuntimeRootPhase_structural(1u, 0);
  FFX_Magic_RunAuxRuntimeRootPass_structural(1u);
  result = unk_2332E88;
  unk_2332E88 = 0;
  return result;
}
