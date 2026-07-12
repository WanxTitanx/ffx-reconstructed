// Function: sub_A6B710
// Address: 0xa6b710
// Size: 0x36b
// Prototype: 

int __cdecl sub_A6B710(int a1, int a2)
{
  int v2; // edi
  int v3; // ecx
  int *v4; // ecx
  int v5; // ebx
  int v6; // edx
  _BYTE *v7; // esi
  int v8; // kr00_4
  _DWORD *v9; // eax
  _DWORD *v10; // ecx
  _DWORD *v11; // ebx
  _WORD *v12; // edx
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int *v18; // [esp+10h] [ebp-58h]
  _WORD *v19; // [esp+14h] [ebp-54h]
  _DWORD *v20; // [esp+18h] [ebp-50h]
  _DWORD *v21; // [esp+1Ch] [ebp-4Ch]
  int *v22; // [esp+20h] [ebp-48h]
  _BYTE v23[64]; // [esp+24h] [ebp-44h] BYREF

  v2 = dword_119FDF0[byte_2332EA1[0]];
  v3 = byte_2332EA1[0] + 1;
  dword_119FDF0[v3] = v2 + 6144;
  byte_2332EA1[0] = v3;
  v4 = (int *)sub_A69940(a1, a2, v2);
  v18 = v4;
  *(float *)(v2 + 880) = (float)*((char *)v4 + 28);
  *(float *)(v2 + 884) = (float)*((char *)v4 + 29);
  *(float *)(v2 + 888) = (float)*((char *)v4 + 30);
  *(float *)(v2 + 892) = (float)*((char *)v4 + 31);
  *(_DWORD *)(v2 + 912) = v4[1] + 16 * *(__int16 *)(a1 + 18);
  *(_DWORD *)(v2 + 916) = v4[1];
  v5 = *v4;
  if ( (*v4 & 0x40) != 0 )
  {
    if ( ((v5 | *(_DWORD *)a1) & 0x400) != 0 )
    {
      if ( (*(_DWORD *)a1 & 8) == 0 )
        nullsub_201(a1, v4, v2);
    }
    else
    {
      nullsub_202(a1, v4, v2);
    }
  }
  else if ( *(_WORD *)(a1 + 20) )
  {
    if ( (v5 & 0x20) != 0 )
      sub_A6CF70(a1, v4, v2);
    else
      sub_A6CD80(v23, v4[10], v4[11]);
  }
  v6 = a1 + *(_DWORD *)(a1 + 4);
  v7 = (_BYTE *)(v6 + 1);
  v8 = *(char *)(v6 + 1);
  v22 = (int *)(v6 + 16);
  v9 = (_DWORD *)(v6 + 24);
  v10 = (_DWORD *)(v6 + 8);
  v11 = (_DWORD *)(v6 + 12);
  v12 = (_WORD *)(v6 + 2);
  v21 = v9;
  v20 = v10;
  v19 = v12;
  while ( 2 )
  {
    switch ( v8 )
    {
      case 0:
      case 1:
        v21 += 4;
        v22 += 4;
        v12 += 8;
        v10 += 4;
        *(_DWORD *)(v2 + 496) = 32769;
        *(_DWORD *)(v2 + 504) = 4276545;
        v11 += 4;
        v19 = v12;
        v20 = v10;
        if ( *v7 != 1 )
          goto LABEL_19;
        v7 += 16;
        goto LABEL_28;
      case 2:
      case 3:
        v21 += 4;
        v22 += 4;
        *(_DWORD *)(v2 + 496) = 32769;
        *(_DWORD *)(v2 + 504) = 306258962;
        v12 += 8;
        *(_DWORD *)(v2 + 288) = *v10 + *((unsigned __int16 *)v18 + 6);
        v10 += 4;
        v13 = *v11 + 32 * *((unsigned __int16 *)v18 + 7);
        v11 += 4;
        *(_DWORD *)(v2 + 292) = v13;
        v19 = v12;
        v20 = v10;
        if ( *v7 != 3 )
          goto LABEL_19;
        v7 += 16;
        goto LABEL_28;
      case 4:
      case 5:
        v21 += 4;
        v22 += 4;
        v12 += 8;
        v10 += 4;
        *(_DWORD *)(v2 + 496) = 32769;
        *(_DWORD *)(v2 + 504) = 1094795585;
        v11 += 4;
        v19 = v12;
        v20 = v10;
        if ( *v7 != 5 )
          goto LABEL_19;
        v7 += 16;
        goto LABEL_28;
      case 6:
      case 7:
        v21 += 4;
        *(_DWORD *)(v2 + 496) = 32769;
        *(_DWORD *)(v2 + 504) = 306258962;
        v12 += 8;
        *(_DWORD *)(v2 + 288) = *v10 + *((unsigned __int16 *)v18 + 6);
        v10 += 4;
        v14 = *v11 + 32 * *((unsigned __int16 *)v18 + 7);
        v11 += 4;
        v22 += 4;
        *(_DWORD *)(v2 + 292) = v14;
        v19 = v12;
        v20 = v10;
LABEL_19:
        v7 += 16;
        goto LABEL_28;
      case 32:
        v21 += 8;
        v22 += 8;
        v10 += 8;
        v11 += 8;
        v20 = v10;
        if ( *v12 )
        {
          *(_DWORD *)(v2 + 496) = 32769;
          *(_DWORD *)(v2 + 504) = 4276545;
        }
        goto LABEL_27;
      case 34:
        if ( *v12 )
        {
          *(_DWORD *)(v2 + 496) = 32769;
          *(_DWORD *)(v2 + 504) = 306258962;
          *(_DWORD *)(v2 + 288) = *v10 + *((unsigned __int16 *)v18 + 6);
          v15 = *v11 + 32 * *((unsigned __int16 *)v18 + 7);
          *(_DWORD *)(v2 + 256) = 1879048198;
          *(_DWORD *)(v2 + 292) = v15;
          *(_DWORD *)(v2 + 272) = 32769;
          *(_DWORD *)(v2 + 336) = *v21;
          v16 = *v22;
          if ( !*v22 )
            v16 = *(_DWORD *)(v2 + 288);
          *(_DWORD *)(v2 + 352) = v16;
          *(_DWORD *)(v2 + 360) = 6;
          nullsub_94();
          v12 = v19;
          v10 = v20;
        }
        v21 += 8;
        v10 += 8;
        v11 += 8;
        v22 += 8;
        v20 = v10;
LABEL_27:
        v12 += 16;
        v7 += 32;
        v19 = v12;
LABEL_28:
        if ( (unsigned int)(char)*v7 > 0x22 )
          goto LABEL_29;
        continue;
      default:
LABEL_29:
        while ( (word_23056E8 & 0x100) != 0 )
          ;
        --byte_2332EA1[0];
        return *(_DWORD *)(v2 + 820);
    }
  }
}

