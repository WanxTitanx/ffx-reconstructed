// Function: sub_986120
// Address: 0x986120
// bad sp value at call has been detected, the output may be wrong!
int __userpurge sub_986120@<eax>(_DWORD *a1@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>, int a5)
{
  bool v6; // zf
  int v7; // ecx
  int result; // eax
  int *v9; // ecx
  int v10; // eax
  float v12; // [esp-40h] [ebp-4Ch]
  float v13; // [esp-3Ch] [ebp-48h]
  float v14; // [esp-38h] [ebp-44h]
  float v15; // [esp-30h] [ebp-3Ch] BYREF
  float v16; // [esp-2Ch] [ebp-38h]
  float v17; // [esp-28h] [ebp-34h]
  float v18; // [esp-20h] [ebp-2Ch] BYREF
  float v19; // [esp-1Ch] [ebp-28h]
  float v20; // [esp-18h] [ebp-24h]
  float v21; // [esp-4h] [ebp-10h]
  int v22; // [esp+0h] [ebp-Ch]
  void *v23; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v22 = a2;
  v23 = retaddr;
  (*(void (__thiscall **)(_DWORD, int, float *, float *, int, int))(**(_DWORD **)(a5 + 204) + 4))(
    *(_DWORD *)(a5 + 204),
    a5 + 16,
    &v15,
    &v18,
    a3,
    a4);
  v6 = (*(_BYTE *)(a5 + 216) & 1) == 0;
  v7 = a1[20];
  v15 = v15 - flt_C64838;
  v16 = v16 - flt_C64838;
  v17 = v17 - flt_C64838;
  v18 = flt_C64838 + v18;
  v19 = flt_C64838 + v19;
  v20 = flt_C64838 + v20;
  if ( !v6 )
    return (*(int (__thiscall **)(int, _DWORD, float *, float *, _DWORD))(*(_DWORD *)v7 + 12))(
             v7,
             *(_DWORD *)(a5 + 200),
             &v15,
             &v18,
             a1[6]);
  v12 = v18 - v15;
  v13 = v19 - v16;
  v14 = v20 - v17;
  v21 = v12 * v12 + v13 * v13 + v14 * v14;
  if ( v21 < 9.99999995904e11 )
    return (*(int (__thiscall **)(int, _DWORD, float *, float *, _DWORD))(*(_DWORD *)v7 + 12))(
             v7,
             *(_DWORD *)(a5 + 200),
             &v15,
             &v18,
             a1[6]);
  result = sub_97A440(5);
  if ( byte_C63946 )
  {
    v9 = (int *)a1[21];
    if ( v9 )
    {
      v10 = *v9;
      byte_C63946 = 0;
      (*(void (__thiscall **)(int *, const char *))(v10 + 32))(v9, "Overflow in AABB, object removed from simulation");
      (*(void (__thiscall **)(_DWORD, const char *))(*(_DWORD *)a1[21] + 32))(
        a1[21],
        "If you can reproduce this, please email bugs@continuousphysics.com\n");
      (*(void (__thiscall **)(_DWORD, const char *))(*(_DWORD *)a1[21] + 32))(
        a1[21],
        "Please include above information, your Platform, version of OS.\n");
      return (*(int (__thiscall **)(_DWORD, const char *))(*(_DWORD *)a1[21] + 32))(a1[21], "Thanks.\n");
    }
  }
  return result;
}
