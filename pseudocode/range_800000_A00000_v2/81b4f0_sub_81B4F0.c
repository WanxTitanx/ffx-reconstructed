// Function: sub_81B4F0
// Address: 0x81b4f0
void __cdecl sub_81B4F0(int a1, int a2, int a3)
{
  int v4; // edx
  char *v5; // edi
  int v6; // eax
  int v7; // ecx
  float v8; // ecx
  float v9; // [esp+4h] [ebp-10h]
  float v10; // [esp+8h] [ebp-Ch]
  float v11; // [esp+Ch] [ebp-8h]
  int v12; // [esp+10h] [ebp-4h]
  int v13; // [esp+1Ch] [ebp+8h]
  float v14; // [esp+1Ch] [ebp+8h]

  v9 = 0.0;
  v4 = 0;
  v10 = 0.0;
  v11 = 0.0;
  v12 = 0;
  if ( *(_BYTE *)(a1 + 8) )
  {
    v5 = (char *)(a1 + 16);
    v13 = -16 - a1;
    do
    {
      if ( !a3 || (v6 = sub_787CD0(*v5), v4 = v12, v6) )
      {
        v7 = (unsigned __int8)*v5;
        *(_DWORD *)a2 = word_C8F508[0];
        *(float *)(a2 + 4) = word_C8F50C;
        *(float *)(a2 + 8) = word_C8F510;
        *(float *)(a2 + 12) = word_C8F514[0];
        v8 = flt_12A80C0[v7];
        if ( v8 != 0.0 )
        {
          sub_82AD10(LODWORD(v8), a2, a2 + 4, a2 + 8);
          v4 = v12;
        }
        v12 = ++v4;
        v11 = *(float *)a2 + v11;
        v10 = *(float *)(a2 + 4) + v10;
        v9 = *(float *)(a2 + 8) + v9;
      }
      ++v5;
    }
    while ( (int)&v5[v13] < *(unsigned __int8 *)(a1 + 8) );
  }
  v14 = (float)v12;
  *(float *)a2 = v11 / v14;
  *(float *)(a2 + 4) = v10 / v14;
  *(float *)(a2 + 8) = v9 / v14;
}
