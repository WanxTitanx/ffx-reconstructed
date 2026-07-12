// Function: sub_897410
// Address: 0x897410
void sub_897410()
{
  int v0; // eax
  int KernelString_Table0; // esi
  float v2; // [esp+18h] [ebp-8h]
  int v3; // [esp+1Ch] [ebp-4h] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  if ( unk_133C8FF )
  {
    sub_8B0FD0();
    v0 = sub_8AC270();
    sub_8B0AC0((int)&savedregs, v0, 16128, 19, 0, 0, 256, 256);
    sub_9047C0(&unk_1F00000, 0x100000, 983040);
    nullsub_162();
    sub_8A1DE0();
    sub_8AE2A0(2, 4, 1);
    if ( sub_8AE4E0(2, "bwakk") == 3 )
    {
      KernelString_Table0 = FFX_Btl_GetKernelString_Table0(12307, 0);
      sub_905290(KernelString_Table0, (int)&v3, 0, 0.77999997);
      v2 = (512.0 - *(float *)&v3) * 0.5;
      sub_9016B0(0, KernelString_Table0, v2, 71.0, 0, 0.77999997, 1.0);
    }
    nullsub_159();
    sub_8F5BC0();
  }
}
