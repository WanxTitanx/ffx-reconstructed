// Function: sub_998D10
// Address: 0x998d10
int __userpurge sub_998D10@<eax>(int a1@<ecx>, int a2@<ebp>, _DWORD *a3, int a4, int a5)
{
  int v6; // xmm0_4
  _DWORD v8[19]; // [esp-18h] [ebp-38Ch] BYREF
  int v9; // [esp+34h] [ebp-340h] BYREF
  int v10; // [esp+44h] [ebp-330h]
  _DWORD v11[88]; // [esp+48h] [ebp-32Ch] BYREF
  __int16 v12; // [esp+1A8h] [ebp-1CCh]
  _DWORD v13[28]; // [esp+1D8h] [ebp-19Ch] BYREF
  void **p_??_7CastResult@btConvexCast@@6B@; // [esp+248h] [ebp-12Ch] BYREF
  float v15; // [esp+2F8h] [ebp-7Ch]
  int v16; // [esp+2FCh] [ebp-78h]
  int v17; // [esp+300h] [ebp-74h]
  float v18[23]; // [esp+308h] [ebp-6Ch] BYREF
  int v19; // [esp+364h] [ebp-10h]
  int v20; // [esp+368h] [ebp-Ch]
  void *v21; // [esp+36Ch] [ebp-8h]
  int v22; // [esp+370h] [ebp-4h] BYREF
  void *retaddr; // [esp+374h] [ebp+0h]

  v20 = a2;
  v21 = retaddr;
  v19 = -1;
  LODWORD(v18[22]) = &loc_AD92AC;
  v18[21] = *(float *)&NtCurrentTeb()->NtTib.ExceptionList;
  LODWORD(v18[20]) = &v22;
  sub_6035C0(v18);
  p_??_7CastResult@btConvexCast@@6B@ = &btConvexCast::CastResult::`vftable';
  v16 = 0;
  v17 = 0;
  v15 = *(float *)(a1 + 212);
  v6 = *(_DWORD *)(a1 + 208);
  v19 = 0;
  v10 = v6;
  sub_96A2F0(v8);
  v8[0] = &btSphereShape::`vftable';
  v8[1] = 8;
  v8[8] = v10;
  v8[12] = v10;
  LOBYTE(v19) = 1;
  sub_9976E0(v13, a3, a3 + 4, a3 + 8);
  v12 &= 0xFFF0u;
  LOBYTE(v19) = 2;
  v11[80] = 953267991;
  sub_9A6090(v8, v13, v11);
  LOBYTE(v19) = 3;
  if ( (unsigned __int8)sub_9A60F0(
                          (float *)(a1 + 16),
                          (float *)(a1 + 80),
                          v18,
                          v18,
                          &p_??_7CastResult@btConvexCast@@6B@)
    && *(float *)(a1 + 212) > (double)v15 )
  {
    *(float *)(a1 + 212) = v15;
  }
  LOBYTE(v19) = 2;
  sub_9A6040(&v9);
  LOBYTE(v19) = 1;
  v13[0] = &btConvexInternalShape::`vftable';
  sub_968890(v13);
  LOBYTE(v19) = 0;
  v8[0] = &btConvexInternalShape::`vftable';
  return sub_968890(v8);
}
