// Function: sub_A288F0
// Address: 0xa288f0
// Size: 0x129
// Prototype: int __stdcall(char ArgList, float, float, float, float, int)

float *__thiscall sub_A288F0(float *this, int ArgList, float a3, float a4, float a5, float a6, int a7)
{
  _DWORD *v8; // eax
  void **v9; // eax
  size_t nNumberOfBytesToRead; // esi
  void *lpBuffer; // edi
  int v13; // [esp+0h] [ebp-1Ch]
  int v14; // [esp+0h] [ebp-1Ch]
  int v15; // [esp+0h] [ebp-1Ch]
  void **v16; // [esp+28h] [ebp+Ch]

  *(this + 29) = a3; /*0xa2891d*/
  *(_DWORD *)this = &IggyMenu::`vftable'; /*0xa28925*/
  *(this + 30) = a4; /*0xa2892b*/
  *(this + 26) = 0.0; /*0xa2892e*/
  *((_BYTE *)this + 112) = 1; /*0xa28938*/
  *(this + 31) = a5; /*0xa2893c*/
  *((_BYTE *)this + 148) = 1; /*0xa2893f*/
  *((_DWORD *)this + 38) = a7; /*0xa28949*/
  *(this + 32) = a6; /*0xa2894f*/
  v8 = (_DWORD *)FFX_Memory_Alloc_w(8u, v13); /*0xa28955*/
  if ( v8 ) /*0xa28969*/
    v9 = (void **)FFX_FileIO_DeviceStructInit(v8, ArgList, 1, 0, 0, 1); /*0xa28978*/
  else
    v9 = 0; /*0xa2897f*/
  v16 = v9; /*0xa28983*/
  nNumberOfBytesToRead = sub_607F80(v9); /*0xa28992*/
  lpBuffer = (void ... [1584 chars total]