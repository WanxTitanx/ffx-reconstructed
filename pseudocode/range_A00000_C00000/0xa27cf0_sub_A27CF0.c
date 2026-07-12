// Function: sub_A27CF0
// Address: 0xa27cf0
// Size: 0xb2
// Prototype: 

int __thiscall sub_A27CF0(int this, int a2, int n30_1, int a4)
{
  int n30; // eax
  int result; // eax
  _BYTE v7[4]; // [esp+8h] [ebp-18h] BYREF
  int v8; // [esp+Ch] [ebp-14h]
  int this_1; // [esp+10h] [ebp-10h]
  int v10; // [esp+14h] [ebp-Ch]
  const char *PVideoPlaybackWin32::_ReadingThread; // [esp+18h] [ebp-8h]
  int v12; // [esp+1Ch] [ebp-4h]

  *(_DWORD *)(this + 664) = a4;
  n30 = n30_1;
  *(_DWORD *)(this + 208) = 0;
  *(_DWORD *)(this + 212) = 0;
  *(_DWORD *)(this + 228) = 0;
  *(_DWORD *)(this + 232) = 0;
  *(_BYTE *)(this + 340) = 0;
  if ( !n30_1 )
    n30 = 30;
  *(_DWORD *)(this + 344) = n30;
  PhyreEvent_Create((HANDLE *)(this + 684), 1u);
  *(_BYTE *)(this + 688) = 1;
  sub_42FD80(sub_A27880);
  v12 = 1;
  v10 = 0;
  v8 = 0;
  PVideoPlaybackWin32::_ReadingThread = "PVideoPlaybackWin32::_ReadingThread";
  this_1 = this;
  result = PhyreThread_Create((HANDLE *)(this + 192), (int)v7);
  *(_BYTE *)(this + 196) = 1;
  return result;
}

