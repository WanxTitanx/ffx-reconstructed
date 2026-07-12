// Function: sub_A26CE0
// Address: 0xa26ce0
// Size: 0x158
// Prototype: 

void __thiscall sub_A26CE0(_DWORD *this)
{
  struct _RTL_CRITICAL_SECTION *lpCriticalSection; // eax
  _DWORD *v3; // eax
  int v4; // ebx
  void (__stdcall *__imp__IggyMakeEventMouseButton@8)(_BYTE *, int); // esi
  unsigned int v6; // esi
  int v7; // ecx
  unsigned int v8; // esi
  void (__thiscall ***v9)(_DWORD); // ecx
  struct _RTL_CRITICAL_SECTION *lpCriticalSection_1; // eax
  _BYTE v11[12]; // [esp+Ch] [ebp-28h] BYREF
  _BYTE v12[24]; // [esp+18h] [ebp-1Ch] BYREF

  lpCriticalSection = (struct _RTL_CRITICAL_SECTION *)sub_A3D7C0();
  EnterCriticalSection(lpCriticalSection);
  v3 = (_DWORD *)sub_A25A30();
  v4 = sub_A25A40(v3);
  if ( v4 )
  {
    __imp__IggyMakeEventMouseButton@8 = (void (__stdcall *)(_BYTE *, int))IggyMakeEventMouseButton;
    do
    {
      IggyMakeEventNone(v12);
      switch ( *(_DWORD *)v4 )
      {
        case 0:
          __imp__IggyMakeEventMouseButton@8(v12, 1);
          break;
        case 1:
          __imp__IggyMakeEventMouseButton@8(v12, 2);
          break;
        case 2:
          __imp__IggyMakeEventMouseButton@8(v12, 5);
          break;
        case 3:
          __imp__IggyMakeEventMouseButton@8(v12, 6);
          break;
        case 4:
          __imp__IggyMakeEventMouseButton@8(v12, 3);
          break;
        case 5:
          __imp__IggyMakeEventMouseButton@8(v12, 4);
          break;
        case 6:
          IggyMakeEventMouseMove(v12, (int)*(float *)(v4 + 4), (int)*(float *)(v4 + 8));
          break;
        case 7:
          IggyMakeEventMouseWheel(v12, (unsigned __int16)(int)(*(float *)(v4 + 12) * 120.0));
          break;
        default:
          break;
      }
      v6 = 0;
      if ( (*(this + 2) & 0x7FFFFFFF) != 0 )
      {
        do
        {
          v7 = *(_DWORD *)(*(this + 3) + 4 * v6);
          if ( v7 )
            (*(void (__thiscall **)(int, _BYTE *, _BYTE *))(*(_DWORD *)v7 + 4))(v7, v12, v11);
          ++v6;
        }
        while ( v6 < (*(this + 2) & 0x7FFFFFFFu) );
      }
      v4 = *(_DWORD *)(v4 + 16);
      __imp__IggyMakeEventMouseButton@8 = (void (__stdcall *)(_BYTE *, int))IggyMakeEventMouseButton;
    }
    while ( v4 );
  }
  v8 = 0;
  if ( (*(this + 2) & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v9 = *(void (__thiscall ****)(_DWORD))(*(this + 3) + 4 * v8);
      if ( v9 )
        (**v9)(v9);
      ++v8;
    }
    while ( v8 < (*(this + 2) & 0x7FFFFFFFu) );
  }
  lpCriticalSection_1 = (struct _RTL_CRITICAL_SECTION *)sub_A3D7C0();
  LeaveCriticalSection(lpCriticalSection_1);
}

