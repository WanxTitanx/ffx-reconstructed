// Function: FFX_MagicCoreOp_02_RelJump
// Address: 0x8169f0
// [Jarvis naming goal 2026-06-17] Magic core opcode 0x02 handler: relative jump, returns ip + signed i16 at ip+2.
int __cdecl FFX_MagicCoreOp_02_RelJump(int a1, int a2)
{
  return a2 + *(__int16 *)(a2 + 2);
}
