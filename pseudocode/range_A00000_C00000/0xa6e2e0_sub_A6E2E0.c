// Function: sub_A6E2E0
// Address: 0xa6e2e0
// Size: 0x252
// Prototype: 

int __cdecl sub_A6E2E0(int *a1)
{
  int *v1; // edi
  int v2; // eax
  int v3; // eax
  int n3; // ebx
  __int64 v5; // rdi
  int v6; // eax
  BOOL v7; // ebx
  int v8; // eax
  int v9; // ecx
  int n3_2; // ebx
  int v11; // ecx
  int v12; // esi
  int v13; // eax
  int v14; // ecx
  _DWORD v16[3]; // [esp+Ch] [ebp-18h]
  _DWORD *v17; // [esp+18h] [ebp-Ch]
  int v18; // [esp+1Ch] [ebp-8h]
  int n3_1; // [esp+20h] [ebp-4h]
  int v20; // [esp+2Ch] [ebp+8h]

  v1 = (int *)sub_7E6910(4352);
  v1[1024] = 1879048194;
  v1[1025] = 0;
  v1[1026] = 0;
  v1[1027] = 0;
  v1[1028] = 32769;
  v1[1029] = 0x10000000;
  v1[1030] = -286331154;
  v1[1031] = 0;
  v1[1032] = 72;
  v1[1033] = 0;
  v1[1034] = 66;
  v1[1035] = 0;
  sub_62FA30(0, 0);
  nullsub_39(unk_23328E0, (unsigned int)(v1 + 1024) | 0x80000000);
  *v1 = 1879048192;
  v1[1] = 0;
  v2 = *v1;
  v1[4] = 0x8000;
  v1[5] = 539246592;
  v1[6] = 65;
  v1[7] = 0;
  MEMORY[0xC8F528] = v2;
  unk_C8F52C = v1[1];
  unk_C8F530 = v1[2];
  unk_C8F534 = v1[3];
  v1[512] = *v1;
  v1[513] = v1[1];
  v1[514] = v1[2];
  v1[515] = v1[3];
  MEMORY[0xC8F528] = v1[4];
  unk_C8F52C = v1[5];
  unk_C8F530 = v1[6];
  unk_C8F534 = v1[7];
  v1[516] = v1[4];
  v1[517] = v1[5];
  v1[518] = v1[6];
  v1[519] = v1[7];
  v3 = *a1;
  n3 = 0;
  v17 = a1 + 4;
  v18 = v3;
  n3_1 = 0;
  while ( 1 )
  {
    v5 = n3 + 1000 + 0x1B500000000LL;
    v6 = sub_645580(v5);
    v7 = v6 == 0;
    if ( !v6 )
      sub_714C40(v5, HIDWORD(v5), 3000, 2);
    v8 = sub_645580(v5);
    v9 = v8;
    v20 = v8;
    if ( !v8 )
      break;
    if ( v7 )
    {
      *(_DWORD *)(v8 + 184) = 1;
      sub_645930(v5);
      v9 = v20;
    }
    if ( !sub_63FF60(v9, 0, *(_DWORD *)(*(_DWORD *)(v9 + 148) + 4), *(_DWORD *)(*(_DWORD *)(v9 + 148) + 8)) )
      break;
    n3_2 = n3_1;
    v16[n3_1] = *(_DWORD *)(v20 + 148);
    sub_6EDAE0(v20);
    sub_6458C0(v5, HIDWORD(v5), 1);
    sub_6457B0(v5, HIDWORD(v5));
    n3 = n3_2 + 1;
    n3_1 = n3;
    if ( n3 >= 3 )
    {
      if ( sub_63FF20(v11) )
      {
        v12 = v18;
        v13 = FFX_MagicHost_AllocPppDrawRecord(v18);
        v14 = v16[0];
        *(_BYTE *)v13 = 4;
        *(_DWORD *)(v13 + 16) = v14;
        *(_DWORD *)(v13 + 20) = v16[1];
        *(_DWORD *)(v13 + 24) = v16[2];
        *(_DWORD *)(v13 + 28) = v17;
        *(_DWORD *)(v13 + 32) = v12;
      }
      return sub_7E6970(4352);
    }
  }
  return sub_7E6970(4352);
}

