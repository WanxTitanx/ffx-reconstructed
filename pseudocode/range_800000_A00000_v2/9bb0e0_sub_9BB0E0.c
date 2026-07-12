// Function: sub_9BB0E0
// Address: 0x9bb0e0
int __userpurge sub_9BB0E0@<eax>(int a1@<ecx>, int a2@<ebp>, float a3)
{
  int result; // eax
  int v4; // edi
  double v5; // st7
  int v6; // esi
  int n2; // eax
  int v8; // eax
  float v9; // xmm0_4
  int v10; // ecx
  float v11; // [esp+0h] [ebp-158h]
  int v12; // [esp+4h] [ebp-154h]
  void **p_??_7ConvexResultCallback@btCollisionWorld@@6B@; // [esp+1Ch] [ebp-13Ch] BYREF
  float v14; // [esp+20h] [ebp-138h]
  __int16 v15; // [esp+24h] [ebp-134h]
  __int16 v16; // [esp+26h] [ebp-132h]
  _DWORD v17[16]; // [esp+8Ch] [ebp-CCh] BYREF
  float v18; // [esp+CCh] [ebp-8Ch]
  int v19; // [esp+E0h] [ebp-78h]
  float v20; // [esp+E4h] [ebp-74h]
  float v21; // [esp+E8h] [ebp-70h]
  _BYTE v22[48]; // [esp+ECh] [ebp-6Ch] BYREF
  float v23[11]; // [esp+11Ch] [ebp-3Ch] BYREF
  int v24; // [esp+148h] [ebp-10h]
  int v25; // [esp+14Ch] [ebp-Ch]
  void *v26; // [esp+150h] [ebp-8h]
  int v27; // [esp+154h] [ebp-4h] BYREF
  void *retaddr; // [esp+158h] [ebp+0h]

  v25 = a2;
  v26 = retaddr;
  v24 = -1;
  LODWORD(v23[10]) = &loc_AD9DA6;
  v23[9] = *(float *)&NtCurrentTeb()->NtTib.ExceptionList;
  LODWORD(v23[8]) = &v27;
  result = a1;
  v19 = a1;
  v4 = 0;
  if ( *(int *)(a1 + 208) > 0 )
  {
    v5 = a3;
    do
    {
      v6 = *(_DWORD *)(*(_DWORD *)(result + 216) + 4 * v4);
      n2 = *(_DWORD *)(v6 + 228);
      *(_DWORD *)(v6 + 252) = 1065353216;
      if ( n2 != 2 && n2 != 5 && (*(_BYTE *)(v6 + 216) & 3) == 0 )
      {
        v11 = v5;
        sub_9B5340((float *)v6, v11, (int)v22);
        v21 = v23[2] - *(float *)(v6 + 72);
        v20 = v23[1] - *(float *)(v6 + 68);
        v18 = v23[0] - *(float *)(v6 + 64);
        v20 = v18 * v18 + v20 * v20 + v21 * v21;
        v21 = *(float *)(v6 + 260) * *(float *)(v6 + 260);
        if ( v21 != 0.0 && v20 > (double)v21 && *(int *)(*(_DWORD *)(v6 + 204) + 4) < 20 )
        {
          ++unk_193F660;
          v12 = *(_DWORD *)(v19 + 24);
          v8 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v19 + 80) + 36))(*(_DWORD *)(v19 + 80));
          sub_9B6890(&p_??_7ConvexResultCallback@btCollisionWorld@@6B@, v6, (_DWORD *)(v6 + 64), v23, v8, v12);
          v9 = *(float *)(v6 + 256);
          v24 = 0;
          v21 = v9;
          sub_96A2F0(v17);
          v17[0] = &btSphereShape::`vftable';
          v17[1] = 8;
          *(float *)&v17[8] = v21;
          *(float *)&v17[12] = v21;
          v10 = *(_DWORD *)(v6 + 200);
          v15 = *(_WORD *)(v10 + 4);
          v16 = *(_WORD *)(v10 + 6);
          LOBYTE(v24) = 1;
          sub_97DD40(v17, v6 + 16, v22, &p_??_7ConvexResultCallback@btCollisionWorld@@6B@, 0.0);
          if ( v14 < 1.0 )
          {
            v21 = v14 * a3;
            *(float *)(v6 + 252) = v14;
            sub_9B5340((float *)v6, v21, (int)v22);
            *(_DWORD *)(v6 + 252) = 0;
          }
          LOBYTE(v24) = 0;
          v17[0] = &btConvexInternalShape::`vftable';
          sub_968890(v17);
          v24 = -1;
          p_??_7ConvexResultCallback@btCollisionWorld@@6B@ = &btCollisionWorld::ConvexResultCallback::`vftable';
        }
        sub_9B5370((int)v22);
        v5 = a3;
      }
      result = v19;
      ++v4;
    }
    while ( v4 < *(_DWORD *)(v19 + 208) );
  }
  return result;
}
