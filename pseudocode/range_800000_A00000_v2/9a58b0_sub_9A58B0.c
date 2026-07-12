// Function: sub_9A58B0
// Address: 0x9a58b0
int __userpurge sub_9A58B0@<eax>(int a1@<ecx>, int a2@<ebp>, _DWORD *a3, int a4, int a5)
{
  int v6; // xmm0_4
  void (__thiscall *v7)(int, float *, int *, _DWORD, int, int); // eax
  int v9; // [esp-4h] [ebp-320h]
  _DWORD v10[5]; // [esp+14h] [ebp-308h] BYREF
  void **p_??_7btGjkEpaPenetrationDepthSolver@@6B@; // [esp+28h] [ebp-2F4h] BYREF
  float v12; // [esp+2Ch] [ebp-2F0h]
  _DWORD v13[88]; // [esp+30h] [ebp-2ECh] BYREF
  __int16 v14; // [esp+190h] [ebp-18Ch]
  _DWORD v15[28]; // [esp+1C0h] [ebp-15Ch] BYREF
  void **p_??_7CastResult@btConvexCast@@6B@; // [esp+230h] [ebp-ECh] BYREF
  float v17; // [esp+2C0h] [ebp-5Ch] BYREF
  float v18; // [esp+2C4h] [ebp-58h]
  float v19; // [esp+2C8h] [ebp-54h]
  int v20; // [esp+2D0h] [ebp-4Ch] BYREF
  float v21; // [esp+2E0h] [ebp-3Ch]
  int v22; // [esp+2E4h] [ebp-38h]
  int v23; // [esp+2E8h] [ebp-34h]
  int *v24; // [esp+300h] [ebp-1Ch]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+304h] [ebp-18h]
  void *v26; // [esp+308h] [ebp-14h]
  int v27; // [esp+30Ch] [ebp-10h]
  _DWORD v28[2]; // [esp+310h] [ebp-Ch] BYREF
  int v29; // [esp+318h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+31Ch] [ebp+0h]

  v28[0] = a2;
  v28[1] = retaddr;
  v27 = -1;
  v26 = &loc_AD9A8C;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v24 = &v29;
  sub_9976E0(v15, a3, a3 + 4, a3 + 8);
  v6 = *(_DWORD *)(a1 + 212);
  v27 = 0;
  v15[12] = v6;
  v13[80] = 953267991;
  v14 &= 0xFFF0u;
  p_??_7btGjkEpaPenetrationDepthSolver@@6B@ = &btGjkEpaPenetrationDepthSolver::`vftable';
  v9 = *(_DWORD *)(a1 + 4);
  LOBYTE(v27) = 1;
  sub_9A6E40(v10, v9, (int)v15, (int)v13, (int)&p_??_7btGjkEpaPenetrationDepthSolver@@6B@);
  p_??_7CastResult@btConvexCast@@6B@ = &btConvexCast::CastResult::`vftable';
  v22 = 0;
  v23 = 0;
  LOBYTE(v27) = 3;
  v21 = 1.0;
  if ( sub_9A6F60(
         COERCE_FLOAT(v10),
         (int)v28,
         (int *)(a1 + 16),
         a1 + 80,
         (int *)(a1 + 144),
         a1 + 144,
         (int)&p_??_7CastResult@btConvexCast@@6B@) )
  {
    v12 = v17 * v17 + v18 * v18 + v19 * v19;
    if ( v12 > 0.00009999999747378752 && *(float *)(a1 + 208) > (double)v21 )
    {
      v12 = sqrt(v12);
      v7 = *(void (__thiscall **)(int, float *, int *, _DWORD, int, int))(*(_DWORD *)a1 + 8);
      v12 = 1.0 / v12;
      v17 = v12 * v17;
      v18 = v12 * v18;
      v19 = v12 * v19;
      v7(a1, &v17, &v20, LODWORD(v21), a4, a5);
    }
  }
  p_??_7CastResult@btConvexCast@@6B@ = &btConvexCast::CastResult::`vftable';
  LOBYTE(v27) = 1;
  sub_9A6040(v10);
  p_??_7btGjkEpaPenetrationDepthSolver@@6B@ = &btConvexPenetrationDepthSolver::`vftable';
  v27 = -1;
  v15[0] = &btConvexInternalShape::`vftable';
  return sub_968890(v15);
}
