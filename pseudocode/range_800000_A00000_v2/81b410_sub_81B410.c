// Function: sub_81B410
// Address: 0x81b410
char *__cdecl sub_81B410(int a1)
{
  char *result; // eax
  int i_1; // edx
  int v4; // ecx
  float v5; // eax
  double v6; // st7
  int i; // [esp+4h] [ebp-1Ch]
  char *v8; // [esp+8h] [ebp-18h]
  int i_2; // [esp+Ch] [ebp-14h] BYREF
  float v10; // [esp+10h] [ebp-10h]
  float v11; // [esp+14h] [ebp-Ch]
  float v12; // [esp+18h] [ebp-8h]
  int v13; // [esp+1Ch] [ebp-4h]
  float v14; // [esp+28h] [ebp+8h]

  result = sub_7B6BD0(16, &i_2);
  i_1 = i_2;
  v10 = 0.0;
  v11 = 0.0;
  v12 = 0.0;
  v8 = result;
  v13 = 0;
  for ( i = 0; i < i_1; v10 = *(float *)(a1 + 8) + v10 )
  {
    v4 = *result;
    *(_DWORD *)a1 = word_C8F508[0];
    *(float *)(a1 + 4) = word_C8F50C;
    *(float *)(a1 + 8) = word_C8F510;
    *(float *)(a1 + 12) = word_C8F514[0];
    v5 = flt_12A80C0[v4];
    if ( v5 != 0.0 )
    {
      sub_82AD10(LODWORD(v5), a1, a1 + 4, a1 + 8);
      i_1 = i_2;
    }
    v6 = *(float *)a1 + v12;
    ++v13;
    v12 = v6;
    result = ++v8;
    ++i;
    v11 = v11 + *(float *)(a1 + 4);
  }
  v14 = (float)v13;
  *(float *)a1 = v12 / v14;
  *(float *)(a1 + 4) = v11 / v14;
  *(float *)(a1 + 8) = v10 / v14;
  return result;
}
