// Function: sub_A57620
// Address: 0xa57620
// Size: 0xea
// Prototype: int __stdcall(_DWORD, _DWORD)

int sub_A57620()
{
  void (__cdecl **CoreWorkPtr)(int); // esi

  if ( (*(_DWORD *)sub_785350() & 0xC000) == 0x8000 ) /*0xa57637*/
  {
    *(_DWORD *)(dword_2305834[0] + 71332) = 2; /*0xa57639*/
    CoreWorkPtr = (void (__cdecl **)(int))FFX_Btl_GetCoreWorkPtr(); /*0xa57648*/
    CoreWorkPtr[4](37); /*0xa5764f*/
    ((void (__cdecl *)(int, void *, _DWORD, _DWORD))*CoreWorkPtr)(20, &unk_11A1240, 0, 0); /*0xa5765c*/
  }
  else
  {
    *(_DWORD *)(dword_2305834[0] + 71332) = 0; /*0xa5765e*/
    CoreWorkPtr = (void (__cdecl **)(int))FFX_Btl_GetCoreWorkPtr(); /*0xa5766d*/
    CoreWorkPtr[4](37); /*0xa57674*/
    ((void (__cdecl *)(int, void *, _DWORD, _DWORD))*CoreWorkPtr)(8, &unk_11A1240, 0, 0); /*0xa57683*/
  }
  CoreWorkPtr[2](0); /*0xa5768a*/
  unk_1A860E8 = &unk_11A1240; /*0xa5768f*/
  sub_7E3D40((int)&unk_11A1240); /*0xa5769e*/
  sub_7E4740(unk_1A860E8, 0, 35, 256); /*0xa576b2*/
  sub_7E4B40(256); /*0xa576bc*/
  sub_7E4740(unk_1A860E8, 36, 1000, 256); /*0xa576d3*/
  sub_7E4B40(256); /*... [1174 chars total]