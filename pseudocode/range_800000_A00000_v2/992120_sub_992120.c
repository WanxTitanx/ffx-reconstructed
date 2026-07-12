// Function: sub_992120
// Address: 0x992120
int __userpurge sub_992120@<eax>(int a1@<ecx>, int a2@<ebp>, int *a3, char a4, float *a5, float *a6)
{
  int v6; // esi
  int v7; // edx
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList_2; // eax
  int v9; // edi
  int v10; // edx
  int v11; // ecx
  int dst_6; // eax
  int v13; // edi
  _DWORD *v14; // edx
  _DWORD *v15; // ecx
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList_3; // eax
  int v17; // ecx
  _DWORD *v18; // eax
  _DWORD *v19; // ecx
  int v20; // eax
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList_4; // eax
  int v22; // edx
  int v23; // edi
  char *dst; // eax
  int v25; // ecx
  int v26; // edx
  int dst_5; // eax
  int v28; // eax
  void *dst_1; // edi
  int v30; // eax
  int v31; // ecx
  int v32; // edi
  char *dst_2; // eax
  int v34; // ecx
  int v35; // edx
  int v36; // edi
  int v37; // eax
  void *dst_3; // edi
  _WORD *v39; // ecx
  int v40; // edx
  int v41; // eax
  int v42; // eax
  int result; // eax
  _BYTE src[64]; // [esp+18h] [ebp-ACh] BYREF
  _DWORD v45[4]; // [esp+58h] [ebp-6Ch] BYREF
  _DWORD v46[5]; // [esp+68h] [ebp-5Ch] BYREF
  _DWORD v47[3]; // [esp+7Ch] [ebp-48h] BYREF
  _DWORD v48[2]; // [esp+88h] [ebp-3Ch] BYREF
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList_1; // [esp+90h] [ebp-34h]
  int v50; // [esp+94h] [ebp-30h]
  int v51; // [esp+98h] [ebp-2Ch]
  int v52; // [esp+9Ch] [ebp-28h]
  int v53; // [esp+A0h] [ebp-24h]
  int dst_4; // [esp+A4h] [ebp-20h]
  int *v55; // [esp+A8h] [ebp-1Ch]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+ACh] [ebp-18h]
  void *v57; // [esp+B0h] [ebp-14h]
  int v58; // [esp+B4h] [ebp-10h]
  _DWORD v59[2]; // [esp+B8h] [ebp-Ch] BYREF
  int v60; // [esp+C0h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+C4h] [ebp+0h]

  v59[0] = a2;
  v59[1] = retaddr;
  v58 = -1;
  v57 = &loc_AD8FC0;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v55 = &v60;
  v6 = a1;
  v51 = a1;
  *(_BYTE *)(a1 + 72) = a4;
  if ( a4 )
  {
    sub_990330(a1, a5, a6, 1.0);
    v47[0] = &`btOptimizedBvh::build'::`3'::QuantizedNodeTriangleCallback::`vftable';
    v47[1] = v6 + 116;
    v47[2] = v6;
    v7 = *a3;
    v58 = 0;
    (*(void (__thiscall **)(int *, _DWORD *, int, int))(v7 + 4))(a3, v47, v6 + 16, v6 + 32);
    ExceptionList_2 = *(struct _EXCEPTION_REGISTRATION_RECORD **)(v6 + 120);
    v9 = *(_DWORD *)(v6 + 140);
    v10 = 2 * (_DWORD)ExceptionList_2;
    ExceptionList_1 = ExceptionList_2;
    v52 = v9;
    if ( 2 * (int)ExceptionList_2 >= v9 )
    {
      if ( 2 * (int)ExceptionList_2 > v9 && *(_DWORD *)(v6 + 144) < v10 )
      {
        if ( v10 )
        {
          v11 = sub_9D4CE0(32 * (_DWORD)ExceptionList_2, 16);
          v53 = v11;
        }
        else
        {
          v11 = 0;
          v53 = 0;
        }
        dst_6 = *(_DWORD *)(v6 + 140);
        dst_4 = dst_6;
        if ( dst_6 > 0 )
        {
          v13 = 0;
          v14 = (_DWORD *)v11;
          do
          {
            if ( v14 )
            {
              v15 = (_DWORD *)(v13 + *(_DWORD *)(v6 + 148));
              *v14 = *v15;
              v14[1] = v15[1];
              v14[2] = v15[2];
              v14[3] = v15[3];
              dst_6 = dst_4;
            }
            v13 += 16;
            v14 += 4;
            dst_4 = --dst_6;
          }
          while ( dst_6 );
          v9 = v52;
        }
        if ( *(_DWORD *)(v6 + 148) )
        {
          if ( *(_BYTE *)(v6 + 152) )
            sub_9D4D50(*(_DWORD *)(v6 + 148));
          *(_DWORD *)(v6 + 148) = 0;
        }
        *(_DWORD *)(v6 + 148) = v53;
        ExceptionList_3 = ExceptionList_1;
        *(_BYTE *)(v6 + 152) = 1;
        v10 = 2 * (_DWORD)ExceptionList_3;
        *(_DWORD *)(v6 + 144) = 2 * (_DWORD)ExceptionList_3;
      }
      if ( v9 < v10 )
      {
        v17 = 16 * v9;
        do
        {
          v18 = (_DWORD *)(v17 + *(_DWORD *)(v6 + 148));
          if ( v18 )
          {
            *v18 = 0;
            v18[1] = 0;
            v18[2] = 0;
            v18[3] = 0;
          }
          ++v9;
          v17 += 16;
        }
        while ( v9 < v10 );
      }
    }
    *(_DWORD *)(v6 + 140) = v10;
    v19 = v47;
  }
  else
  {
    v48[0] = &`btOptimizedBvh::build'::`2'::NodeTriangleCallback::`vftable';
    v48[1] = a1 + 76;
    v20 = *a3;
    v58 = 1;
    v46[0] = -581039253;
    v46[1] = -581039253;
    v46[2] = -581039253;
    v46[3] = 0;
    v45[0] = 1566444395;
    v45[1] = 1566444395;
    v45[2] = 1566444395;
    v45[3] = 0;
    (*(void (__thiscall **)(int *, _DWORD *, _DWORD *, _DWORD *))(v20 + 4))(a3, v48, v46, v45);
    ExceptionList_4 = *(struct _EXCEPTION_REGISTRATION_RECORD **)(v6 + 80);
    v22 = *(_DWORD *)(v6 + 100);
    v23 = 2 * (_DWORD)ExceptionList_4;
    ExceptionList_1 = ExceptionList_4;
    v52 = 2 * (_DWORD)ExceptionList_4;
    v50 = v22;
    if ( 2 * (int)ExceptionList_4 >= v22 )
    {
      if ( 2 * (int)ExceptionList_4 > v22 && *(_DWORD *)(v6 + 104) < v23 )
      {
        if ( v23 )
          dst = (char *)sub_9D4CE0((_DWORD)ExceptionList_4 << 7, 16);
        else
          dst = 0;
        v25 = *(_DWORD *)(v6 + 100);
        dst_4 = (int)dst;
        v53 = v25;
        if ( v25 > 0 )
        {
          v26 = 0;
          do
          {
            if ( dst )
            {
              qmemcpy(dst, (const void *)(v26 + *(_DWORD *)(v6 + 108)), 0x40u);
              v6 = v51;
              v25 = v53;
            }
            v26 += 64;
            dst += 64;
            v53 = --v25;
          }
          while ( v25 );
          v23 = v52;
        }
        if ( *(_DWORD *)(v6 + 108) )
        {
          if ( *(_BYTE *)(v6 + 112) )
            sub_9D4D50(*(_DWORD *)(v6 + 108));
          *(_DWORD *)(v6 + 108) = 0;
        }
        dst_5 = dst_4;
        v22 = v50;
        *(_BYTE *)(v6 + 112) = 1;
        *(_DWORD *)(v6 + 108) = dst_5;
        *(_DWORD *)(v6 + 104) = v23;
      }
      if ( v22 < v23 )
      {
        v28 = v22 << 6;
        do
        {
          dst_1 = (void *)(v28 + *(_DWORD *)(v6 + 108));
          if ( dst_1 )
          {
            qmemcpy(dst_1, src, 0x40u);
            v6 = v51;
          }
          v23 = v52;
          ++v22;
          v28 += 64;
        }
        while ( v22 < v52 );
      }
    }
    *(_DWORD *)(v6 + 100) = v23;
    v19 = v48;
  }
  v58 = -1;
  sub_98ACA0(v19);
  ExceptionList = ExceptionList_1;
  v55 = 0;
  *(_DWORD *)(v6 + 68) = 0;
  sub_98C800(v6, (int)v59, (int)v55, (int)ExceptionList);
  if ( *(_BYTE *)(v6 + 72) && !*(_DWORD *)(v6 + 164) )
  {
    v30 = *(_DWORD *)(v6 + 164);
    v31 = *(_DWORD *)(v6 + 168);
    v50 = v30;
    if ( v30 == v31 )
    {
      v32 = 2 * v30;
      if ( !v30 )
        v32 = 1;
      v53 = v32;
      if ( v31 < v32 )
      {
        if ( v32 )
          dst_2 = (char *)sub_9D4CE0(32 * v32, 16);
        else
          dst_2 = 0;
        v34 = *(_DWORD *)(v6 + 164);
        dst_4 = (int)dst_2;
        v52 = v34;
        if ( v34 > 0 )
        {
          v35 = 0;
          do
          {
            if ( dst_2 )
            {
              qmemcpy(dst_2, (const void *)(v35 + *(_DWORD *)(v6 + 172)), 0x20u);
              v6 = v51;
              v34 = v52;
            }
            v35 += 32;
            dst_2 += 32;
            v52 = --v34;
          }
          while ( v34 );
          v32 = v53;
        }
        if ( *(_DWORD *)(v6 + 172) )
        {
          if ( *(_BYTE *)(v6 + 176) )
            sub_9D4D50(*(_DWORD *)(v6 + 172));
          *(_DWORD *)(v6 + 172) = 0;
        }
        *(_DWORD *)(v6 + 172) = dst_4;
        v30 = v50;
        *(_BYTE *)(v6 + 176) = 1;
        *(_DWORD *)(v6 + 168) = v32;
      }
    }
    v36 = *(_DWORD *)(v6 + 172);
    ++*(_DWORD *)(v6 + 164);
    v37 = 32 * v30;
    dst_3 = (void *)(v37 + v36);
    if ( dst_3 )
    {
      qmemcpy(dst_3, &src[32], 0x20u);
      v6 = v51;
    }
    v39 = *(_WORD **)(v6 + 148);
    v40 = v37 + *(_DWORD *)(v6 + 172);
    *(_WORD *)v40 = *v39;
    *(_WORD *)(v40 + 2) = v39[1];
    *(_WORD *)(v40 + 4) = v39[2];
    *(_WORD *)(v40 + 6) = v39[3];
    *(_WORD *)(v40 + 8) = v39[4];
    *(_WORD *)(v40 + 10) = v39[5];
    *(_DWORD *)(v40 + 12) = 0;
    v41 = *(_DWORD *)(*(_DWORD *)(v6 + 148) + 12);
    if ( v41 < 0 )
      v42 = -v41;
    else
      v42 = 1;
    *(_DWORD *)(v40 + 16) = v42;
  }
  *(_DWORD *)(v6 + 180) = *(_DWORD *)(v6 + 164);
  if ( *(_DWORD *)(v6 + 128) )
  {
    if ( *(_BYTE *)(v6 + 132) )
      sub_9D4D50(*(_DWORD *)(v6 + 128));
    *(_DWORD *)(v6 + 128) = 0;
  }
  *(_BYTE *)(v6 + 132) = 1;
  *(_DWORD *)(v6 + 128) = 0;
  *(_DWORD *)(v6 + 120) = 0;
  *(_DWORD *)(v6 + 124) = 0;
  result = *(_DWORD *)(v6 + 88);
  if ( result )
  {
    if ( *(_BYTE *)(v6 + 92) )
      result = sub_9D4D50(*(_DWORD *)(v6 + 88));
    *(_DWORD *)(v6 + 88) = 0;
  }
  *(_BYTE *)(v6 + 92) = 1;
  *(_DWORD *)(v6 + 88) = 0;
  *(_DWORD *)(v6 + 80) = 0;
  *(_DWORD *)(v6 + 84) = 0;
  return result;
}
