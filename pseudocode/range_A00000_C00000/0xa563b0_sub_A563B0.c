// Function: sub_A563B0
// Address: 0xa563b0
// Size: 0x2d5
// Prototype: int __cdecl(int, int, int, int, float)

int __cdecl sub_A563B0(float *a1, float *a2, float *a3, float *a4, float a5)
{
  double v5; // st5
  double v6; // st5
  int v7; // eax
  double v8; // st7
  int result; // eax
  float v10; // [esp+8h] [ebp-34h]
  float v11; // [esp+Ch] [ebp-30h]
  float v12; // [esp+10h] [ebp-2Ch]
  float v13; // [esp+14h] [ebp-28h]
  float v14; // [esp+20h] [ebp-1Ch]
  float v15; // [esp+24h] [ebp-18h]
  float v16; // [esp+30h] [ebp-Ch]
  float v17; // [esp+34h] [ebp-8h]
  float v18; // [esp+34h] [ebp-8h]
  float v19; // [esp+34h] [ebp-8h]
  float v20; // [esp+34h] [ebp-8h]
  float v21; // [esp+34h] [ebp-8h]
  float v22; // [esp+34h] [ebp-8h]
  float v23; // [esp+38h] [ebp-4h]
  float v24; // [esp+38h] [ebp-4h]
  float v25; // [esp+38h] [ebp-4h]
  float v26; // [esp+38h] [ebp-4h]

  v12 = *a2 - *a4;
  v13 = a2[1] - a4[1];
  v17 = atan2(v13, v12);
  v11 = v17;
  v14 = *a3 - *a4;
  v15 = a3[1] - a4[1];
  v18 = atan2(v15, v14);
  v10 = v18;
  unk_C8F830 = v12 * v12;
  unk_C8F834 = v13 * v13;
  unk_C8F838 = (float)0.0 * 0.0;
  unk_C8F824 = unk_C8F834 + unk_C8F830;
  flt_C8F828 = unk_C8F838 + unk_C8F824;
  v19 = fabs(flt_C8F828);
  v20 = sqrt(v19);
  v21 = v20 + flt_C0A004;
  unk_C8F83C = 1.0;
  unk_C8F810 = flt_C0A004 + v14;
  unk_C8F814 = v15 + *(float *)&dword_C0A008;
  unk_C8F818 = *(float *)&dword_C0A00C + 0.0;
  unk_C8F830 = v14 * v14;
  unk_C8F834 = v15 * v15;
  unk_C8F838 = 0.0 * (float)0.0;
  unk_C8F824 = unk_C8F834 + unk_C8F830;
  flt_C8F828 = unk_C8F838 + unk_C8F824;
  v23 = fabs(flt_C8F828);
  v24 = sqrt(v23);
  unk_C8F830 = v24 + flt_C0A004;
  unk_C8F788 = flt_C0A010 / unk_C8F830;
  unk_C8F820 = unk_C8F810 * unk_C8F788;
  unk_C8F824 = unk_C8F814 * unk_C8F788;
  flt_C8F828 = unk_C8F788 * unk_C8F818;
  v25 = v10 - v11;
  v5 = v25;
  if ( v11 > (double)v10 )
  {
    if ( v5 < -3.141592741012573 )
    {
      v6 = v5 + 6.283185482025146;
      goto LABEL_6;
    }
  }
  else if ( v5 > 3.141592741012573 )
  {
    v6 = v5 - 6.283185482025146;
LABEL_6:
    v26 = v6;
    v5 = v26;
  }
  v22 = v21 + (unk_C8F830 - v21) * a5;
  v16 = v11 + v5 * a5;
  v7 = (int)(v16 * 32768.0 / 3.141592741012573);
  v8 = flt_C44BE0[(((unsigned __int16)v7 + 0x4000) >> 4) & 0xFFF];
  result = (unsigned __int16)v7 >> 4;
  *a1 = v8 * v22 + *a4;
  a1[1] = v22 * flt_C44BE0[result] + a4[1];
  a1[2] = a4[2];
  a1[3] = 1.0;
  return result;
}

