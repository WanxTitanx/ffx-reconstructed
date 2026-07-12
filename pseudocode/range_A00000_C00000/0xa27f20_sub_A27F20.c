// Function: sub_A27F20
// Address: 0xa27f20
// Size: 0x3c6
// Prototype: int __stdcall(char ArgList, int)

int __thiscall sub_A27F20(int this, char ArgList, char a3)
{
  DWORD TickCount; // eax
  int v6; // eax
  unsigned int v7; // esi
  int v8; // ebx
  int n2; // eax
  double v10; // st7
  int v11; // ecx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  double v16; // st7
  unsigned __int64 v17; // kr00_8
  unsigned int v18; // ecx
  unsigned int v19; // edx
  unsigned int v20; // eax
  unsigned int v21; // edx
  bool v22; // zf
  int (__cdecl *v23)(int, int); // [esp-18h] [ebp-44h]
  int (__cdecl *v24)(int, int); // [esp-14h] [ebp-40h]
  int (__cdecl *v25)(int); // [esp-10h] [ebp-3Ch]
  int v26; // [esp-10h] [ebp-3Ch]
  int (__cdecl *v27)(int); // [esp-Ch] [ebp-38h]
  int (__cdecl *v28)(int); // [esp-8h] [ebp-34h]
  _BYTE v29[4]; // [esp+4h] [ebp-28h] BYREF
  int v30; // [esp+8h] [ebp-24h]
  int this_1; // [esp+Ch] [ebp-20h]
  int v32; // [esp+10h] [ebp-1Ch]
  const char *PVideoPlaybackWin32::_VideoDecodingThread; // [esp+14h] [ebp-18h]
  int v34; // [esp+18h] [ebp-14h]
  double v35; // [esp+1Ch] [ebp-10h]
  double v36; // [esp+24h] [ebp-8h]
  int ArgLista; // [esp+34h] [ebp+8h]
  unsigned int v38; // [esp+38h] [ebp+Ch]

  if ( *(_BYTE *)(this + 196) )
    sub_A28350();
  else
    sub_A27CF0(this, 0, 30, 0);
  *(_BYTE *)(this + 680) = 1;
  *(_DWORD *)(this + 256) = 0;
  *(_DWORD *)(this + 668) = 0;
  *(_DWORD *)(this + 672) = 0;
  TickCount = GetTickCount();
  v25 = off_C6B280[0];
  ::TickCount = TickCount;
  v24 = off_C6B27C;
  v23 = off_C6B278[0];
  *(_BYTE *)(this + 240) = a3;
  if ( sub_40A5D0(off_C6B274, v23, v24, v25, memcpy_w, memset_w, sub_A26FC0) )
    return -1;
  v6 = sub_40A430();
  if ( sub_4094C0(this + 304, v6, 0, 0, 9) )
    return -2;
  sub_41E5B0(off_C6B284[0], off_C6B288[0]);
  if ( sub_A3E1F0(ArgList) )
    return -3;
  sub_41FD50(this + 280, 0, 0, this + 272);
  sub_421450(*(_DWORD *)(this + 272));
  ArgLista = sub_4251B0(*(_DWORD *)(this + 272));
  *(_DWORD *)(this + 656) = 0;
  *(_DWORD *)(this + 660) = 0;
  v7 = 0;
  v38 = sub_4294C0(ArgLista);
  if ( v38 )
  {
    do
    {
      v8 = sub_429DE0(v7);
      n2 = sub_427B10(v8);
      if ( n2 == 1 )
      {
        *(_DWORD *)(this + 656) = v8;
      }
      else if ( n2 == 2 )
      {
        *(_DWORD *)(this + 660) = v8;
      }
      ++v7;
    }
    while ( v7 < v38 );
  }
  v10 = sub_428DD0(*(_DWORD *)(this + 656));
  v35 = v10;
  if ( 0.0 == v10 )
  {
    v10 = 29.97002997002997;
    v35 = 29.97002997002997;
  }
  v11 = *(_DWORD *)(this + 656);
  *(double *)(this + 264) = 1000.0 / v10;
  v12 = sub_428DB0(v11);
  v13 = *(_DWORD *)(this + 656);
  *(_DWORD *)(this + 332) = v12;
  v14 = sub_428DC0(v13);
  v15 = *(_DWORD *)(this + 272);
  *(_DWORD *)(this + 336) = v14;
  v36 = (double)sub_425200(v15);
  v16 = v36 * 0.001 * 0.001;
  v17 = 0;
  if ( v16 >= 9.223372036854776e18 )
  {
    v16 = v16 - 9.223372036854776e18;
    if ( v16 < 9.223372036854776e18 )
      v17 = 0x8000000000000000uLL;
  }
  v18 = *(_DWORD *)(this + 332);
  *(_QWORD *)(this + 248) = v17 + (unsigned __int64)v16;
  v19 = *(_DWORD *)(this + 336);
  *(_DWORD *)(this + 704) = v18 >> 1;
  v20 = v19;
  v21 = v18 * v19;
  *(_DWORD *)(this + 712) = v21;
  v22 = *(_DWORD *)(this + 664) == 0;
  *(_DWORD *)(this + 708) = v20 >> 1;
  *(_DWORD *)(this + 716) = v21 >> 2;
  if ( v22 )
    *(_DWORD *)(this + 660) = 0;
  v36 = (double)*(unsigned __int64 *)(this + 248);
  v22 = *(_DWORD *)(this + 660) == 0;
  *(_QWORD *)&v35 = (__int64)(v36 / v35);
  *(_DWORD *)(this + 700) = LODWORD(v35);
  if ( !v22 && !sub_A273B0((int *)this) )
    *(_DWORD *)(this + 660) = 0;
  v28 = off_C6B2A0;
  v27 = off_C6B29C[0];
  v26 = *(_DWORD *)(this + 712) + (*(_DWORD *)(this + 712) >> 1);
  *(_DWORD *)(this + 720) = v26;
  sub_A3DDF0(0x400000, v26, v27, v28);
  sub_A3DDF0(
    *(_DWORD *)(this + 344) * (*(_DWORD *)(this + 720) + 4),
    *(_DWORD *)(this + 720),
    off_C6B29C[0],
    off_C6B2A0);
  *(_DWORD *)(this + 236) = 0;
  sub_42FD80(sub_A27B90);
  v34 = 1;
  v32 = 0;
  v30 = 0;
  PVideoPlaybackWin32::_VideoDecodingThread = "PVideoPlaybackWin32::_VideoDecodingThread";
  this_1 = this;
  PhyreThread_Create((HANDLE *)(this + 200), (int)v29);
  *(_BYTE *)(this + 204) = 1;
  *(_BYTE *)(this + 340) = 1;
  PhyreEvent_Create((HANDLE *)(this + 692), 1u);
  *(_BYTE *)(this + 696) = 1;
  *(_DWORD *)(this + 228) = 1;
  PhyreEvent_Set((HANDLE *)(this + 684));
  return 0;
}

