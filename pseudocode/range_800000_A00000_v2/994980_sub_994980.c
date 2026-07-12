// Function: sub_994980
// Address: 0x994980
double __userpurge sub_994980@<st0>(int a1@<ebp>, int a2, int a3, int a4, int a5)
{
  double v5; // st7
  double v6; // st7
  double v7; // st7
  int v9; // esi
  int v10; // esi
  float v11; // xmm0_4
  double v12; // st7
  int v13; // esi
  float v14; // xmm0_4
  double v15; // st7
  _DWORD v16[16]; // [esp-1Ch] [ebp-58Ch] BYREF
  _DWORD v17[16]; // [esp+24h] [ebp-54Ch] BYREF
  int v18; // [esp+64h] [ebp-50Ch] BYREF
  float v19; // [esp+74h] [ebp-4FCh] BYREF
  int v20; // [esp+90h] [ebp-4E0h]
  float v21; // [esp+94h] [ebp-4DCh]
  float v22; // [esp+98h] [ebp-4D8h]
  float v23; // [esp+9Ch] [ebp-4D4h]
  float v24; // [esp+A0h] [ebp-4D0h]
  _DWORD v25[88]; // [esp+A4h] [ebp-4CCh] BYREF
  __int16 v26; // [esp+204h] [ebp-36Ch]
  _DWORD v27[88]; // [esp+234h] [ebp-33Ch] BYREF
  __int16 v28; // [esp+394h] [ebp-1DCh]
  void **p_??_7CastResult@btConvexCast@@6B@; // [esp+3C4h] [ebp-1ACh] BYREF
  float v30; // [esp+474h] [ebp-FCh]
  int v31; // [esp+478h] [ebp-F8h]
  int v32; // [esp+47Ch] [ebp-F4h]
  void **p_??_7CastResult@btConvexCast@@6B@_1; // [esp+484h] [ebp-ECh] BYREF
  float v34; // [esp+534h] [ebp-3Ch]
  int v35; // [esp+538h] [ebp-38h]
  int v36; // [esp+53Ch] [ebp-34h]
  int *v37; // [esp+554h] [ebp-1Ch]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+558h] [ebp-18h]
  void *v39; // [esp+55Ch] [ebp-14h]
  int n4; // [esp+560h] [ebp-10h]
  int v41; // [esp+564h] [ebp-Ch]
  void *v42; // [esp+568h] [ebp-8h]
  int v43; // [esp+56Ch] [ebp-4h] BYREF
  void *retaddr; // [esp+570h] [ebp+0h]

  v41 = a1;
  v42 = retaddr;
  n4 = -1;
  v39 = &loc_AD90B2;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v37 = &v43;
  v5 = *(float *)(a2 + 136);
  v20 = a2;
  v6 = v5 - *(float *)(a2 + 72);
  v21 = 1.0;
  v23 = v6;
  v22 = *(float *)(a2 + 132) - *(float *)(a2 + 68);
  v19 = *(float *)(a2 + 128) - *(float *)(a2 + 64);
  v24 = v22 * v22 + v19 * v19 + v23 * v23;
  v22 = *(float *)(a3 + 136) - *(float *)(a3 + 72);
  v23 = *(float *)(a3 + 132) - *(float *)(a3 + 68);
  v19 = *(float *)(a3 + 128) - *(float *)(a3 + 64);
  v23 = v19 * v19 + v23 * v23 + v22 * v22;
  v7 = v24;
  v24 = *(float *)(a2 + 260) * *(float *)(a2 + 260);
  if ( v24 > v7 )
  {
    v24 = *(float *)(a3 + 260) * *(float *)(a3 + 260);
    if ( v24 > (double)v23 )
      return 1.0;
  }
  if ( unk_193F248 )
    return 1.0;
  v9 = *(_DWORD *)(a2 + 204);
  v24 = *(float *)(a3 + 256);
  sub_96A2F0(v16);
  v16[0] = &btSphereShape::`vftable';
  v16[1] = 8;
  *(float *)&v16[8] = v24;
  *(float *)&v16[12] = v24;
  n4 = 1;
  p_??_7CastResult@btConvexCast@@6B@ = &btConvexCast::CastResult::`vftable';
  v30 = 9.9999998e17;
  v31 = 0;
  v32 = 0;
  v26 &= 0xFFF0u;
  v25[80] = 953267991;
  sub_9A9590(v9, v16, v25);
  v10 = v20;
  LODWORD(v22) = v20 + 16;
  LOBYTE(n4) = 2;
  LODWORD(v23) = v20 + 80;
  if ( (unsigned __int8)sub_9A95F0(v20 + 16, v20 + 80, a3 + 16, a3 + 80, &p_??_7CastResult@btConvexCast@@6B@) )
  {
    v11 = v30;
    v24 = *(float *)(v10 + 252);
    v12 = v30;
    if ( v24 > (double)v30 )
      *(float *)(v10 + 252) = v30;
    v24 = *(float *)(a3 + 252);
    if ( v24 > v12 )
      *(float *)(a3 + 252) = v11;
    if ( v12 < 1.0 )
      v21 = v11;
  }
  LOBYTE(n4) = 1;
  sub_9A6040(&v18);
  p_??_7CastResult@btConvexCast@@6B@ = &btConvexCast::CastResult::`vftable';
  n4 = -1;
  v16[0] = &btConvexInternalShape::`vftable';
  sub_968890(v16);
  v13 = *(_DWORD *)(a3 + 204);
  v24 = *(float *)(v20 + 256);
  sub_96A2F0(v17);
  v17[0] = &btSphereShape::`vftable';
  v17[1] = 8;
  *(float *)&v17[8] = v24;
  *(float *)&v17[12] = v24;
  n4 = 4;
  p_??_7CastResult@btConvexCast@@6B@_1 = &btConvexCast::CastResult::`vftable';
  v34 = 9.9999998e17;
  v35 = 0;
  v36 = 0;
  v28 &= 0xFFF0u;
  v27[80] = 953267991;
  sub_9A9590(v17, v13, v27);
  LOBYTE(n4) = 5;
  if ( (unsigned __int8)sub_9A95F0(LODWORD(v22), LODWORD(v23), a3 + 16, a3 + 80, &p_??_7CastResult@btConvexCast@@6B@_1) )
  {
    v14 = v34;
    v24 = *(float *)(v20 + 252);
    v15 = v34;
    if ( v24 > (double)v34 )
      *(float *)(v20 + 252) = v34;
    v24 = *(float *)(a3 + 252);
    if ( v24 > v15 )
      *(float *)(a3 + 252) = v14;
    if ( v21 > v15 )
      v21 = v14;
  }
  LOBYTE(n4) = 4;
  sub_9A6040(&v19);
  p_??_7CastResult@btConvexCast@@6B@_1 = &btConvexCast::CastResult::`vftable';
  n4 = -1;
  v17[0] = &btConvexInternalShape::`vftable';
  sub_968890(v17);
  return v21;
}
