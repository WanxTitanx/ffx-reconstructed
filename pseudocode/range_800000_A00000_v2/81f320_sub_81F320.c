// Function: sub_81F320
// Address: 0x81f320
int __cdecl sub_81F320(unsigned __int8 *a1, int a2, unsigned __int8 *a3, int a4)
{
  int v4; // ebx
  char *v5; // edi
  int v6; // eax
  int v7; // ecx
  __int16 *v8; // esi
  __int16 *v9; // edi
  __int16 *v10; // edx
  unsigned int v11; // ecx
  int v12; // esi
  unsigned __int8 **v13; // ecx
  int v14; // eax
  unsigned __int8 *v15; // eax
  int v16; // eax
  int n0x10000; // esi
  int result; // eax
  _DWORD *v20; // eax
  int v21; // [esp+Ch] [ebp-Ch]
  int v22; // [esp+10h] [ebp-8h]
  int v23; // [esp+14h] [ebp-4h]
  int v24; // [esp+24h] [ebp+Ch]

  v23 = 0;
  v4 = n2_9 == 0 ? a2 : 0;
  v22 = unk_12F4E84;
  v21 = unk_12F4E80 + 0x8000;
  if ( unk_12F4E9C || n3_15 != 3 )
  {
    v7 = (dword_12F4E94 & 1) == 0;
    v22 = v7 * (unk_12F4E88 / 2) + unk_12F4E84;
    v5 = (char *)a1;
    v24 = 1;
    v23 = v7;
  }
  else
  {
    v5 = (char *)a1;
    v6 = 0;
    v24 = 0;
    unk_12F4E98 = 0;
    unk_12F4F5C = 0;
    dword_12F4F58 = 0;
    unk_12F4F54 = 0;
    dword_12F4F50 = 0;
    dword_12F4E94 = 0;
    unk_12F4E30 = 0;
    if ( a1 )
    {
      v6 = 1;
      unk_12F4E30 = 1;
    }
    if ( !n2_9 && v4 )
    {
      v6 |= 2u;
      unk_12F4E30 = v6;
    }
    if ( a3 )
      unk_12F4E30 = v6 | 1;
    unk_12F4E50 = 0;
    LOBYTE(v7) = 0;
  }
  n3_15 &= ~(1 << v7);
  nullsub_33(0);
  if ( a3 )
  {
    sub_81CD80(a3, word_12F4F80);
    v5 = (char *)word_12F4F80;
    a1 = (unsigned __int8 *)word_12F4F80;
    if ( !v24 )
      *(_DWORD *)a3 = word_12F4F80;
  }
  else if ( !v5 )
  {
    goto LABEL_21;
  }
  if ( n2_9 == 2 )
  {
    v8 = (__int16 *)v5;
    v9 = (__int16 *)&v5[unk_12F4E88 / 2];
    do
    {
      v10 = v8;
      do
      {
        v11 = (unsigned int)(v10[256] + *v10) >> 1;
        v10[256] = v11;
        *v10++ = v11;
      }
      while ( v10 < v8 + 256 );
      v8 += 512;
    }
    while ( v8 < v9 );
  }
LABEL_21:
  v12 = 0;
  v13 = (unsigned __int8 **)&dword_12F4DC0;
  if ( v4 )
  {
    unk_12F4DC4 = v21;
    v12 = 1;
    dword_12F4DC0 = v4;
    if ( unk_12F4E88 % 12288 )
      n2048 = a4 % 6 != 0 ? 7168 : 8960;
    else
      n2048 = 1792 * (unk_12F4E88 / 12288);
    unk_12F4DCC = 0;
    v13 = (unsigned __int8 **)&unk_12F4DD0;
  }
  if ( a1 )
  {
    v13[1] = (unsigned __int8 *)v22;
    ++v12;
    v14 = unk_12F4E88 / 2;
    *v13 = a1;
    v13[2] = (unsigned __int8 *)v14;
  }
  else
  {
    if ( !a3 )
      goto LABEL_31;
    v15 = (unsigned __int8 *)unk_12F4E80;
    ++v12;
    *v13 = a3;
    v13[1] = v15;
    v13[2] = (unsigned __int8 *)20480;
  }
  v13[3] = 0;
LABEL_31:
  if ( v12 )
  {
    do
      v16 = sub_A44790(&dword_12F4DC0, v12);
    while ( !v16 );
    unk_12F4E90 = v16;
  }
  nullsub_33(0);
  n0x10000 = 1;
  do
  {
    if ( n0x10000 )
    {
      n0x10000 = 0;
    }
    else
    {
      n0x10000 = 0x10000;
      while ( n0x10000-- )
        ;
    }
    result = sub_A44770(unk_12F4E90);
  }
  while ( result >= 0 );
  if ( v4 )
  {
    v20 = off_C49458;
    *(_DWORD *)off_C49458 = v24;
    v20[1] = a4;
    result = sub_81CCE0(17);
  }
  if ( a1 )
  {
    if ( (unk_12F4108 & 2) != 0 )
      nullsub_34();
    unk_12F4EA4 = v23;
    unk_12F4EA8 = a4;
    unk_12F4EAC = dword_12F4E94;
    result = *(_DWORD *)a1;
    unk_12F4EB0 = *(_DWORD *)a1;
  }
  ++unk_12F4E98;
  return result;
}
