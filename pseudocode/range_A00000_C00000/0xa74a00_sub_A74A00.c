// Function: sub_A74A00
// Address: 0xa74a00
// Size: 0x251
// Prototype: 

int __cdecl sub_A74A00(int a1, int a2)
{
  int v2; // ebx
  _DWORD *v3; // ecx
  int v4; // edx
  int v5; // edi
  float *v6; // eax
  int v8; // edx
  bool v9; // zf
  int *v10; // ecx
  float *v11; // esi
  double v12; // st7
  float *v13; // [esp+1Ch] [ebp-1Ch]
  unsigned int n12288; // [esp+20h] [ebp-18h]
  unsigned __int16 v15; // [esp+24h] [ebp-14h]
  unsigned __int16 v16; // [esp+28h] [ebp-10h]
  _DWORD *v17; // [esp+2Ch] [ebp-Ch]
  int v18; // [esp+30h] [ebp-8h]
  int v19; // [esp+34h] [ebp-4h]
  float v20; // [esp+40h] [ebp+8h]
  int v21; // [esp+44h] [ebp+Ch]

  v2 = 0;
  v3 = *(_DWORD **)(a1 + 948);
  v4 = *(_DWORD *)(a1 + 544);
  v19 = v4;
  v17 = v3;
  if ( v3 )
    v2 = *v3;
  v5 = a2;
  v18 = a2 + 2;
  v21 = *(unsigned __int16 *)(a2 + 2);
  v16 = *(_WORD *)(v5 + 4);
  v15 = *(_WORD *)(v5 + 6);
  v13 = (float *)(v4 + (unsigned __int16)v21);
  n12288 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( n12288 > 0x2000 )
  {
    if ( n12288 == 12288 )
    {
      if ( v2 )
      {
        v11 = (float *)v3[8];
        if ( 0.0 == *(float *)(v2 + 96) )
        {
          nullsub_34();
          v12 = *v11 * 0.324999988079071;
        }
        else
        {
          nullsub_34();
          v12 = *(float *)(v2 + 96) * *v11;
        }
        v20 = v12;
        *v13 = v20 * 2097152.0;
      }
      v5 += 4;
    }
    return v5;
  }
  if ( n12288 != 0x2000 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
    {
      if ( n12288 == 4096 )
      {
        if ( v2 )
        {
          sub_7EA640((void *)(a1 + 64), v2 + 96);
          sub_7E9880(a1 + 64, a1 + 64, v2 + 80, v2 + 64);
          v6 = (float *)v17[2];
          *(float *)a1 = *v6;
          *(float *)(a1 + 4) = v6[1];
          *(float *)(a1 + 8) = v6[2];
          sub_7E78B0(v19 + 144, a1 + 64, a1);
          sub_7EA760(v19 + 64, v19 + 144, 16.0);
        }
        return v18;
      }
      return v5;
    }
    v8 = sub_800F80(a1 + 768, v4, v21);
    v9 = *(_BYTE *)(v8 + 187) == 3;
    unk_22FB4D0 = v8;
    if ( v9 )
      (*(void (__cdecl **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)(a1 + 848) + 100))(
        a1 + 768,
        *(_DWORD *)(v8 + 188),
        v16,
        v15);
    return v5 + 8;
  }
  if ( !v2 )
    return v5 + 8;
  sub_7EA5E0((void *)(a1 + 64));
  sub_7E9880(a1 + 64, a1 + 64, v2 + 80, v2 + 64);
  v10 = (int *)v17[5];
  if ( (_WORD)v21 )
    *v13 = (float)((*v10 >> 4) & 0xFFF);
  if ( v16 )
    *(float *)(v16 + v19) = (float)((v10[1] >> 4) & 0xFFF);
  if ( v15 )
    *(float *)(v15 + v19) = (float)((v10[2] >> 4) & 0xFFF);
  return v5 + 8;
}

