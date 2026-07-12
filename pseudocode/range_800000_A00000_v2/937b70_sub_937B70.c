// Function: sub_937B70
// Address: 0x937b70
int __usercall sub_937B70@<eax>(int a1@<ebx>, int a2@<edi>)
{
  int v2; // esi
  int ActiveGuideMapRoot; // eax
  int ActiveGuideMapRoot_1; // esi
  int v5; // eax
  int v6; // edi
  double v7; // st7
  __int16 *v8; // ebx
  int v9; // esi
  double v10; // st6
  double v11; // st6
  int ActiveGuideMapRoot_3; // esi
  float v13; // ebx
  int v14; // eax
  int v15; // eax
  int v16; // ebx
  int v17; // eax
  float v18; // ecx
  __int16 *v19; // esi
  int v20; // eax
  int v21; // eax
  float v22; // ecx
  int v23; // eax
  int v24; // edi
  int v25; // esi
  int v26; // ebx
  int v27; // edx
  double v28; // st7
  double v29; // st6
  int v30; // ecx
  int v31; // eax
  double v32; // st6
  double v33; // st6
  int v34; // ecx
  double v35; // st6
  double v36; // st6
  double v37; // st6
  int v38; // eax
  int v40; // [esp-8h] [ebp-74h]
  int v43; // [esp+Ch] [ebp-60h]
  int v44; // [esp+Ch] [ebp-60h]
  int v45; // [esp+Ch] [ebp-60h]
  int v46; // [esp+Ch] [ebp-60h]
  int v47; // [esp+10h] [ebp-5Ch] BYREF
  int v48; // [esp+14h] [ebp-58h]
  int v49[4]; // [esp+20h] [ebp-4Ch] BYREF
  float v50; // [esp+30h] [ebp-3Ch]
  int ActiveGuideMapRoot_2; // [esp+34h] [ebp-38h]
  int v52; // [esp+38h] [ebp-34h]
  int v53; // [esp+3Ch] [ebp-30h] BYREF
  float v54; // [esp+40h] [ebp-2Ch]
  float v55; // [esp+44h] [ebp-28h]
  float v56; // [esp+4Ch] [ebp-20h]
  double v57; // [esp+50h] [ebp-1Ch]
  int v58[4]; // [esp+58h] [ebp-14h] BYREF

  if ( unk_193BF80 && *(_DWORD *)unk_193BF80 )
    v2 = *(_DWORD *)(*(_DWORD *)unk_193BF80 + 8);
  else
    v2 = 0;
  v56 = *(float *)(v2 + 244);
  sub_937610((int)&v47, v2 + 120, v56, v43, v47, v48);
  sub_937610((int)&v53, v2 + 104, v56, v44, v47, v48);
  sub_9376B0((int)v58, (int)&v47, (float *)&v53);
  sub_921360(v58);
  *((float *)&v57 + 1) = v56 * 5.0;
  sub_937610((int)v49, (int)v58, *((float *)&v57 + 1), v45, v47, v48);
  sub_937540((int)v49, (int)v49, (float *)&v53);
  ActiveGuideMapRoot = FFX_FieldMap_GetActiveGuideMapRoot();
  ActiveGuideMapRoot_1 = ActiveGuideMapRoot;
  ActiveGuideMapRoot_2 = ActiveGuideMapRoot;
  if ( ActiveGuideMapRoot )
  {
    v52 = *(__int16 *)(ActiveGuideMapRoot + 10);
    if ( v52 > 0 )
    {
      v5 = unknown_libname_741(*(_DWORD *)(ActiveGuideMapRoot + 24));
      v6 = 0;
      v50 = 1.0 / *(float *)(ActiveGuideMapRoot_1 + 12) * v56;
      v56 = 3.4028235e38;
      v7 = v50;
      v8 = (__int16 *)(v5 + 4);
      v9 = 0;
      do
      {
        HIDWORD(v57) = *(v8 - 2);
        v57 = (double)SHIDWORD(v57);
        v10 = v57 * v7;
        HIDWORD(v57) = *(v8 - 1);
        *(float *)&v53 = v10;
        v57 = (double)SHIDWORD(v57);
        v11 = v57 * v7;
        HIDWORD(v57) = *v8;
        v54 = v11;
        v57 = (double)SHIDWORD(v57);
        v55 = v7 * v57;
        sub_9376B0((int)v58, (int)&v53, (float *)v49);
        *((float *)&v57 + 1) = sub_921250(v58);
        if ( *((float *)&v57 + 1) < (double)v56 )
        {
          v56 = *((float *)&v57 + 1);
          v6 = v9;
        }
        v7 = v50;
        ++v9;
        v8 += 4;
      }
      while ( v9 < v52 );
      ActiveGuideMapRoot_3 = ActiveGuideMapRoot_2;
      v52 = 0;
      if ( *(__int16 *)(ActiveGuideMapRoot_2 + 6) > 0 )
      {
        v13 = 0.0;
        v56 = 0.0;
        while ( 1 )
        {
          v14 = unknown_libname_741(*(_DWORD *)(ActiveGuideMapRoot_3 + 28));
          v15 = unknown_libname_741(*(_DWORD *)(v14 + LODWORD(v13) + 12));
          v40 = *(_DWORD *)(ActiveGuideMapRoot_3 + 28);
          HIDWORD(v57) = v15;
          v16 = 0;
          v17 = unknown_libname_741(v40);
          v18 = v56;
          if ( *(__int16 *)(v17 + LODWORD(v56) + 8) > 0 )
            break;
LABEL_20:
          v21 = *(__int16 *)(ActiveGuideMapRoot_3 + 6);
          LODWORD(v22) = LODWORD(v18) + 16;
          ++v52;
          v56 = v22;
          if ( v52 >= v21 )
            goto LABEL_23;
          v13 = v22;
        }
        v19 = (__int16 *)(HIDWORD(v57) + 4);
        while ( v6 != *(v19 - 2) && v6 != *(v19 - 1) && v6 != *v19 )
        {
          ++v16;
          v19 += 8;
          v20 = unknown_libname_741(*(_DWORD *)(ActiveGuideMapRoot_2 + 28));
          v18 = v56;
          if ( v16 >= *(__int16 *)(v20 + LODWORD(v56) + 8) )
          {
            ActiveGuideMapRoot_3 = ActiveGuideMapRoot_2;
            goto LABEL_20;
          }
        }
        v23 = unknown_libname_741(*(_DWORD *)(ActiveGuideMapRoot_2 + 24));
        v24 = HIDWORD(v57);
        v25 = v23;
        v26 = 2 * v16;
        v27 = *(__int16 *)(HIDWORD(v57) + 8 * v26);
        HIDWORD(v57) = *(__int16 *)(v23 + 8 * v27);
        v57 = (double)SHIDWORD(v57);
        v28 = v57;
        HIDWORD(v57) = *(__int16 *)(v23 + 8 * v27 + 2);
        *(float *)&v53 = v28 * v50;
        v57 = (double)SHIDWORD(v57);
        v29 = v57 * v50;
        HIDWORD(v57) = *(__int16 *)(v23 + 8 * v27 + 4);
        v54 = v29;
        v57 = (double)SHIDWORD(v57);
        v30 = *(__int16 *)(v24 + 8 * v26 + 2);
        v31 = *(__int16 *)(v23 + 8 * v30);
        v55 = v57 * v50;
        v57 = (double)v31;
        v32 = v57 * v50;
        HIDWORD(v57) = *(__int16 *)(v25 + 8 * v30 + 2);
        *(float *)&v53 = v32 + *(float *)&v53;
        v57 = (double)SHIDWORD(v57);
        v33 = v57 * v50;
        HIDWORD(v57) = *(__int16 *)(v25 + 8 * v30 + 4);
        v54 = v33 + v54;
        v57 = (double)SHIDWORD(v57);
        v34 = *(__int16 *)(v24 + 8 * v26 + 4);
        v35 = v57 * v50 + v55;
        HIDWORD(v57) = *(__int16 *)(v25 + 8 * v34);
        v55 = v35;
        v57 = (double)SHIDWORD(v57);
        v36 = v57 * v50;
        HIDWORD(v57) = *(__int16 *)(v25 + 8 * v34 + 2);
        *(float *)&v53 = v36 + *(float *)&v53;
        v57 = (double)SHIDWORD(v57);
        v37 = v57 * v50;
        HIDWORD(v57) = *(__int16 *)(v25 + 8 * v34 + 4);
        v54 = v37 + v54;
        v57 = (double)SHIDWORD(v57);
        v55 = v50 * v57 + v55;
        sub_937610((int)v49, (int)&v53, 0.33333334, a2, a1, v46);
      }
    }
  }
LABEL_23:
  v38 = sub_82D8E0();
  return FFX_Chr_SetWorldPosition(v38, *(float *)v49, *(float *)&v49[1], *(float *)&v49[2]);
}
