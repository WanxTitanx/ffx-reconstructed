// Function: sub_804BB0
// Address: 0x804bb0
_WORD *__cdecl sub_804BB0(int a1, _WORD *a2)
{
  int v3; // esi
  _WORD *v4; // edi
  int v5; // edi
  int n4; // ecx
  __int16 v7; // ax
  unsigned __int16 n4_2; // dx
  int v9; // eax
  int v10; // edi
  double v11; // st7
  int v12; // esi
  double v13; // st7
  int n4_7; // ecx
  int n4435; // eax
  unsigned __int16 n4_4; // cx
  __int16 v17; // ax
  double v18; // st7
  int v19; // eax
  int v20; // edi
  int v22; // eax
  __int16 v23; // si
  float v24; // [esp+0h] [ebp-24h]
  float v25; // [esp+0h] [ebp-24h]
  float v26; // [esp+10h] [ebp-14h]
  int v27; // [esp+10h] [ebp-14h]
  __int16 *v28; // [esp+10h] [ebp-14h]
  float v29; // [esp+10h] [ebp-14h]
  __int16 *v30; // [esp+14h] [ebp-10h]
  int v31; // [esp+14h] [ebp-10h]
  __int16 v32; // [esp+18h] [ebp-Ch]
  float *v33; // [esp+1Ch] [ebp-8h]
  unsigned __int16 v34; // [esp+20h] [ebp-4h]
  int n4_5; // [esp+20h] [ebp-4h]
  int v36; // [esp+2Ch] [ebp+8h]
  int n4_6; // [esp+2Ch] [ebp+8h]
  float v38; // [esp+2Ch] [ebp+8h]
  float v39; // [esp+2Ch] [ebp+8h]
  float v40; // [esp+2Ch] [ebp+8h]
  int v41; // [esp+2Ch] [ebp+8h]
  unsigned __int16 n4_1; // [esp+30h] [ebp+Ch]
  float v43; // [esp+30h] [ebp+Ch]
  unsigned __int16 n4_3; // [esp+30h] [ebp+Ch]
  __int16 v45; // [esp+30h] [ebp+Ch]

  v3 = *(_DWORD *)(a1 + 544);
  v4 = a2;
  v32 = *(_WORD *)(a1 + 538) & 1;
  v30 = a2 + 1;
  v34 = a2[1];
  v33 = (float *)v3;
  v36 = LODWORD(flt_12A80C0[*(unsigned __int8 *)(v3 + 24)]);
  v26 = sub_82ABE0(v36);
  switch ( *(unsigned __int16 *)(a1 + 538) >> 12 )
  {
    case 0:
      if ( v32 )
      {
        sub_8053F0(a1, v36, v34);
        sub_7EA760(v3 + 64, a1, 16.0);
      }
      else
      {
        sub_833C00(v36, v34, a1);
        sub_7EA760(v3 + 64, a1 + 48, 0.016000001);
      }
      v4 = a2 + 2;
      goto LABEL_52;
    case 1:
      LOWORD(v9) = v34;
      goto LABEL_20;
    case 2:
      if ( !v32 )
        goto LABEL_9;
      sub_835570(v36, v34, a1);
      goto LABEL_8;
    case 3:
      v5 = v36;
      n4 = sub_830470(v36) - 1;
      n4_6 = n4;
      if ( n4 < 4 )
      {
        n4_2 = n4;
      }
      else
      {
        v7 = sub_7E5C60(n4 - 4);
        n4 = n4_6;
        n4_2 = v7 + 4;
      }
      n4_1 = n4_2;
      if ( n4_2 > n4 )
        n4_1 = n4;
      if ( v32 )
      {
        sub_805320(a1, v5);
        sub_805350(a1 + 64, v5, n4_1);
        sub_7E78B0(a1, a1, a1 + 112);
        sub_7EA760(v3 + 64, a1, 16.0);
      }
      v4 = v30;
      goto LABEL_52;
    case 4:
      v9 = (int)*(float *)(v3 + 4 * v34 + 48);
      v34 = v9;
LABEL_20:
      if ( v32 )
      {
        sub_805320(a1, v36);
        v10 = a1 + 64;
        sub_805350(a1 + 64, v36, v34);
        sub_7E82C0(a1, a1, a1 + 64);
        v38 = 10.0 / v26;
        sub_7EA760(a1 + 128, v3 + 48, LODWORD(v38));
        sub_7E78B0(a1 + 64, a1, a1 + 128);
        v11 = 16.0;
      }
      else
      {
        v10 = a1 + 64;
        sub_805350(a1 + 64, v36, (unsigned __int16)v9);
        v39 = 10.0 / v26;
        sub_7EA760(a1 + 128, v3 + 48, LODWORD(v39));
        sub_7E78B0(a1 + 64, a1, a1 + 128);
        v11 = 0.016000001;
      }
      v24 = v11;
      sub_7EA760(v3 + 64, v10, LODWORD(v24));
      v4 = a2 + 2;
      goto LABEL_52;
    case 5:
      *(float *)(a1 + 192) = (float)(__int16)a2[2];
      *(float *)(a1 + 196) = (float)(__int16)a2[3];
      *(float *)(a1 + 200) = (float)(__int16)a2[4];
      v43 = 10.0 / v26;
      sub_7EA760(a1 + 192, a1 + 192, LODWORD(v43));
      if ( v32 )
      {
        sub_805320(a1, v36);
        v12 = a1 + 64;
        sub_805350(a1 + 64, v36, v34);
        sub_7E82C0(a1, a1, a1 + 64);
        sub_7E78B0(a1 + 64, a1, a1 + 192);
        v13 = 16.0;
      }
      else
      {
        v12 = a1 + 64;
        sub_805350(a1 + 64, v36, v34);
        sub_7E78B0(a1 + 64, a1, a1 + 192);
        v13 = 0.016000001;
      }
      v25 = v13;
      sub_7EA760(v33 + 16, v12, LODWORD(v25));
      v4 += 5;
      goto LABEL_52;
    case 6:
      n4_5 = sub_830470(v36) - 1;
      n4_7 = n4_5;
      if ( n4_5 > (__int16)a2[2] )
        n4_7 = (__int16)a2[2];
      v27 = *v30;
      v31 = n4_7 - v27;
      n4_3 = v27 + sub_7E5C60(n4_7 - v27);
      if ( FFX_Btl_GetCurrentBattleFormationId() == 302 )
      {
        n4435 = sub_826C00(v36);
        n4_4 = n4_3;
        if ( n4435 == 4435 && (n4_3 >= 4u && n4_3 <= 0x14u || (unsigned __int16)(n4_3 - 26) <= 0x2Eu) )
          n4_4 = sub_7E5C60(v27 - 75 + v31) + 75;
      }
      else
      {
        n4_4 = n4_3;
      }
      if ( n4_4 > n4_5 )
        n4_4 = n4_5;
      if ( v32 )
      {
        sub_833D90(v36, n4_4, 0, a1);
        sub_7EA760(v3 + 64, a1, 16.0);
      }
      v4 += 3;
      goto LABEL_52;
    case 7:
      v28 = (_WORD *)((char *)a2 + *v30);
      v45 = *v28;
      v17 = sub_7E5C60(*v28);
      if ( v17 >= v45 )
        v17 = v45 - 1;
      if ( !v32 )
        goto LABEL_9;
      sub_833D90(v36, (unsigned __int16)v28[v17 + 1], 0, a1);
LABEL_8:
      sub_7EA760(v3 + 64, a1, 16.0);
LABEL_9:
      v4 += 2;
LABEL_52:
      sub_7EA760(v33 + 36, v33 + 16, 0.0625);
      return v4;
    case 8:
      v18 = *(float *)(v3 + 72);
      *(_BYTE *)(v3 + 178) |= 4u;
      v19 = ((int)v18 & 0xFFF) + 1024;
      *(float *)a1 = flt_C43BE0[v19] * *(float *)(v3 + 64) * 0.0625 / 0.001000000047497451;
      *(float *)(a1 + 8) = flt_C44BE0[v19 & 0xFFF] * *(float *)(v3 + 64) * 0.0625 / 0.001000000047497451;
      *(float *)(a1 + 4) = 0.0625 * *(float *)(v3 + 68) / 0.001000000047497451;
      LOWORD(v19) = 4 * a2[2];
      v20 = a1 + 192;
      *(float *)(v20 + 4 * (unsigned __int8)byte_C48E10[(__int16)v19]) = *(float *)a1;
      *(float *)(v20 + 4 * (unsigned __int8)byte_C48E11[(__int16)v19]) = *(float *)(a1 + 4);
      *(float *)(v20 + 4 * (unsigned __int8)byte_C48E12[(__int16)v19]) = *(float *)(a1 + 8);
      sub_805320(a1, v36);
      sub_805350(a1 + 64, v36, *v30);
      sub_7E82C0(a1, a1, a1 + 64);
      v40 = 10.0 / v26;
      sub_7EA760(a1 + 192, a1 + 192, LODWORD(v40));
      sub_7E78B0(v3 + 144, a1, a1 + 192);
      return a2 + 3;
    case 9:
      v22 = sub_795B50(*(unsigned __int8 *)(v3 + 24), 0);
      v41 = v22;
      if ( v22 )
      {
        v29 = *(float *)(*v30 + v3) * 0.00390625;
        sub_805320(a1, v22);
        v23 = a2[3];
        sub_805350(a1 + 64, v41, (__int16)a2[2]);
        sub_805350(a1 + 128, v41, v23);
        sub_7E82C0(a1 + 192, a1, a1 + 112);
        sub_7E82C0(a1 + 208, a1, a1 + 176);
        v4 = a2;
        v33[16] = ((*(float *)(a1 + 208) - *(float *)(a1 + 192)) * v29 + *(float *)(a1 + 192)) * 16.0;
        v33[17] = ((*(float *)(a1 + 212) - *(float *)(a1 + 196)) * v29 + *(float *)(a1 + 196)) * 16.0;
        v33[18] = ((*(float *)(a1 + 216) - *(float *)(a1 + 200)) * v29 + *(float *)(a1 + 200)) * 16.0;
        v33[19] = 16.0 * (v29 * (*(float *)(a1 + 220) - *(float *)(a1 + 204)) + *(float *)(a1 + 204));
      }
      v4 += 4;
      goto LABEL_52;
    case 0xA:
      sub_8053F0(a1, v36, (unsigned __int16)(int)*(float *)(*v30 + v3));
      goto LABEL_8;
    default:
      FFX_Btl_UpdateActorActionState(*(_BYTE *)(v3 + 24), a1);
      sub_7EA760(v3 + 64, a1, 16.0);
      *(float *)(v3 + 68) = *(float *)(v3 + 68) - 256.0;
      goto LABEL_52;
  }
}
