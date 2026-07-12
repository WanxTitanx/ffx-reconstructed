// Function: sub_A3D9F0
// Address: 0xa3d9f0
// Size: 0x132
// Prototype: 

void __thiscall sub_A3D9F0(_DWORD *this, int *a2)
{
  void (__stdcall *__imp_EnterCriticalSection)(LPCRITICAL_SECTION); // ebx
  int v4; // eax
  int v5; // edx
  int v6; // ecx
  int *v7; // edi
  int v8; // eax
  int v9; // [esp+8h] [ebp-1Ch] BYREF
  int v10; // [esp+Ch] [ebp-18h] BYREF
  _BYTE v11[12]; // [esp+10h] [ebp-14h] BYREF
  float v12; // [esp+1Ch] [ebp-8h]

  if ( *this && unk_1A858C4 )
  {
    __imp_EnterCriticalSection = EnterCriticalSection;
    EnterCriticalSection(&lpCriticalSection_);
    if ( IggyPlayerReadyToTick(*this) )
    {
      do
        IggyPlayerTickRS(*this);
      while ( IggyPlayerReadyToTick(*this) );
      __imp_EnterCriticalSection = EnterCriticalSection;
    }
    LeaveCriticalSection(&lpCriticalSection_);
    v4 = *a2;
    v5 = *(_DWORD *)(*a2 + 696);
    v10 = v5;
    v6 = *(_DWORD *)(v4 + 728);
    v9 = v6;
    v7 = *(int **)(v4 + 112);
    if ( v7 )
    {
      if ( !v5 || !v6 )
      {
        (*(void (__stdcall **)(int *, int, int *, int *))(*v7 + 356))(v7, 1, &v10, &v9);
        v5 = v10;
        v6 = v9;
      }
      if ( v5 && v6 )
      {
        IggyPlayerSetDisplaySize(*this, *(this + 3), *(this + 4));
        if ( *((_BYTE *)this + 40) )
        {
          IggyPlayerGetBackgroundColor(*this, v11);
          v8 = *v7;
          v12 = 1.0;
          (*(void (__stdcall **)(int *, int, _BYTE *))(v8 + 200))(v7, v10, v11);
        }
        sub_A38300(v10, v9, 0, *(this + 5), *(this + 6));
        __imp_EnterCriticalSection(&lpCriticalSection_);
        IggyPlayerDraw(*this);
        LeaveCriticalSection(&lpCriticalSection_);
      }
    }
  }
}

