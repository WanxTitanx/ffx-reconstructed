// Function: sub_8926B0
// Address: 0x8926b0
unsigned int sub_8926B0()
{
  unsigned int result; // eax
  int v1; // edi
  int v2; // esi
  double v3; // st7
  int KernelString_Table0; // esi
  float v5; // [esp+4h] [ebp-20h]
  float v6; // [esp+1Ch] [ebp-8h]
  int v7; // [esp+20h] [ebp-4h] BYREF

  result = *(__int16 *)&byte_133D6B2[2] - 3;
  if ( result <= 1 )
  {
    v1 = unk_133D6BC[0];
    if ( unk_133D6BC[0] < unk_133D6C0 )
    {
      v2 = 30 * unk_133D6BC[0];
      do
      {
        sub_8B1300(-1, *(unsigned __int16 *)(unk_133D6C4 + 2 * v1));
        sub_643070(1.5, 1.5);
        v3 = FFX_Menu2D_ScaleY_1080to416(514.0) - 3.0;
        sub_9029B0(*(unsigned __int16 *)(unk_133D6C4 + 2 * v1), v2 + (__int16)unk_133D6B6 - 46, (int)v3);
        sub_642E10();
        sub_8B12E0();
        ++v1;
        v2 += 30;
      }
      while ( v1 < unk_133D6C0 );
    }
    KernelString_Table0 = FFX_Btl_GetKernelString_Table0(12305, 0);
    sub_905290(KernelString_Table0, (int)&v7, 0, 0.77999997);
    v5 = FFX_Menu2D_ScaleY_1080to416(186.0);
    v6 = (512.0 - *(float *)&v7) * 0.5;
    return sub_9016B0(0, KernelString_Table0, v6, v5, 0, 0.77999997, 1.0);
  }
  return result;
}
