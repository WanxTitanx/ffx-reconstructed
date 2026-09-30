// Jarvis-HEAVY H01: PPP opcode byte classifier. 0x41->0x100, 0x42->0x10, 0x46->0x20, 0x48->0x2, 0x88->0x200, 0x44/default->0 with VIRTUOS warning for unexpected alpha function.
// FFX MagicHost: Classify PPP opcode byte
int __fastcall FFX_MagicHost_ClassifyPppOpcodeByte(FFX_AtelPppOpcodeCategory category, int opcodeByte)
{
  int n256; // eax
  int v3; // [esp+Ch] [ebp+8h]

  // [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass.
  switch ( v3 )
  {
    case 65:
      n256 = 256; /*0x712d3e*/
      break; /*0x712d42*/
    case 66:
      n256 = 16; /*0x712d48*/
      break; /*0x712d4c*/
    case 68:
      goto LABEL_8;
    case 70:
      n256 = 32; /*0x712d52*/
      break; /*0x712d56*/
    case 72:
      n256 = 2; /*0x712d34*/
      break; /*0x712d38*/
    case 136:
      n256 = 512; /*0x712d5c*/
      break; /*0x712d60*/
    default:
      nullsub_34("[VIRTUOS WARNING - VFX] other alpha function: %2x\n", v3);
LABEL_8:
      n256 = 0; /*0x712d6f*/
      break; /*0x712d6f*/
  }
  return n256; /*0x712d36*/
}