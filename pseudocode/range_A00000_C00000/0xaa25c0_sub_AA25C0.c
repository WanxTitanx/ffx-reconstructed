// Function: sub_AA25C0
// Address: 0xaa25c0
// Size: 0xbc
// Prototype: _DWORD __cdecl(int, int n255, int n255, float *)

float *__fastcall sub_AA25C0(int a1, int a2, int a3, int n255, int a5, float *a6)
{
  int v6; // esi
  int v7; // edi
  int v8; // eax
  int v10; // ecx
  float *result; // eax
  int v12; // ecx
  int v13; // edx
  float v14; // xmm0_4
  int v15; // [esp+Ch] [ebp-Ch]
  int v16; // [esp+Ch] [ebp-Ch]
  int v18; // [esp+14h] [ebp-4h]
  int v19; // [esp+28h] [ebp+10h]
  int v20; // [esp+28h] [ebp+10h]

  v6 = a5 - n255;
  v7 = a3 - a2;
  v19 = abs32(a5 - n255);
  v8 = v6 / (a3 - a2);
  v15 = v8;
  v10 = v8 - 1;
  if ( v6 >= 0 )
    v10 = v8 + 1;
  v20 = v19 - abs32(v7 * v8);
  result = (float *)a2;
  v18 = v10;
  v12 = 0;
  if ( a1 > a3 )
    a1 = a3;
  if ( a2 < a1 )
    a6[a2] = dword_B8F068[n255] * a6[a2];
  v13 = a2 + 1;
  if ( a2 + 1 < a1 )
  {
    v16 = 4 * v15;
    result = &dword_B8F068[n255];
    do
    {
      v12 += v20;
      if ( v12 < v7 )
      {
        result = (float *)((char *)result + v16);
      }
      else
      {
        v12 -= v7;
        result += v18;
      }
      v14 = a6[v13++] * *result;
      a6[v13 - 1] = v14;
    }
    while ( v13 < a1 );
  }
  return result;
}

