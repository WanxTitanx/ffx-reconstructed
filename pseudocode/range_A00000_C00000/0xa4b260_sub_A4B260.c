// Function: sub_A4B260
// Address: 0xa4b260
// Size: 0x242
// Prototype: int(void)

void sub_A4B260()
{
  int v0; // esi
  float v1; // [esp+0h] [ebp-Ch]
  float v2; // [esp+0h] [ebp-Ch]
  float v3; // [esp+0h] [ebp-Ch]
  float v4; // [esp+0h] [ebp-Ch]
  float v5; // [esp+0h] [ebp-Ch]
  float v6; // [esp+0h] [ebp-Ch]
  float v7; // [esp+0h] [ebp-Ch]
  float v8; // [esp+0h] [ebp-Ch]
  float v9; // [esp+0h] [ebp-Ch]
  float v10; // [esp+0h] [ebp-Ch]
  float v11; // [esp+0h] [ebp-Ch]
  float v12; // [esp+0h] [ebp-Ch]
  float v13; // [esp+0h] [ebp-Ch]
  float v14; // [esp+0h] [ebp-Ch]
  float v15; // [esp+0h] [ebp-Ch]
  float v16; // [esp+0h] [ebp-Ch]
  int v17; // [esp+4h] [ebp-8h] BYREF
  int v18; // [esp+8h] [ebp-4h] BYREF

  if ( !unk_12FB790 )
  {
    v0 = *(_DWORD *)(sub_639180("NoTexture", 0) + 148);
    qmemcpy(*(void **)(v0 + 32), "NoTexture", 9);
    *(_DWORD *)v0 = 0;
    **(float **)(v0 + 20) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 20) + 4) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 20) + 8) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 20) + 12) = 1.0;
    *(float *)(*(_DWORD *)(v0 + 20) + 16) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 20) + 20) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 20) + 24) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 20) + 28) = 1.0;
    *(float *)(*(_DWORD *)(v0 + 20) + 32) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 20) + 36) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 20) + 40) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 20) + 44) = 1.0;
    *(float *)(*(_DWORD *)(v0 + 20) + 48) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 20) + 52) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 20) + 56) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 20) + 60) = 1.0;
    sub_640F60(&v18, &v17);
    v1 = (float)v18;
    v2 = -v1 / 0.1000000014901161;
    **(float **)(v0 + 12) = v2;
    v3 = (float)v17;
    v4 = -v3 / 0.1000000014901161;
    *(float *)(*(_DWORD *)(v0 + 12) + 4) = v4;
    *(float *)(*(_DWORD *)(v0 + 12) + 8) = 1.0;
    v5 = (float)v18;
    v6 = -v5 / 0.1000000014901161;
    *(float *)(*(_DWORD *)(v0 + 12) + 12) = v6;
    v7 = (float)v17;
    v8 = v7 / 0.1000000014901161;
    *(float *)(*(_DWORD *)(v0 + 12) + 16) = v8;
    *(float *)(*(_DWORD *)(v0 + 12) + 20) = 1.0;
    v9 = (float)v18;
    v10 = v9 / 0.1000000014901161;
    *(float *)(*(_DWORD *)(v0 + 12) + 24) = v10;
    v11 = (float)v17;
    v12 = v11 / 0.1000000014901161;
    *(float *)(*(_DWORD *)(v0 + 12) + 28) = v12;
    *(float *)(*(_DWORD *)(v0 + 12) + 32) = 1.0;
    v13 = (float)v18;
    v14 = v13 / 0.1000000014901161;
    *(float *)(*(_DWORD *)(v0 + 12) + 36) = v14;
    v15 = (float)v17;
    v16 = -v15 / 0.1000000014901161;
    *(float *)(*(_DWORD *)(v0 + 12) + 40) = v16;
    *(float *)(*(_DWORD *)(v0 + 12) + 44) = 1.0;
    **(float **)(v0 + 16) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 16) + 4) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 16) + 8) = 1.0;
    *(float *)(*(_DWORD *)(v0 + 16) + 12) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 16) + 16) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 16) + 20) = 1.0;
    *(float *)(*(_DWORD *)(v0 + 16) + 24) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 16) + 28) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 16) + 32) = 1.0;
    *(float *)(*(_DWORD *)(v0 + 16) + 36) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 16) + 40) = 0.0;
    *(float *)(*(_DWORD *)(v0 + 16) + 44) = 1.0;
    **(_WORD **)(v0 + 28) = 0;
    *(_WORD *)(*(_DWORD *)(v0 + 28) + 2) = 1;
    *(_WORD *)(*(_DWORD *)(v0 + 28) + 4) = 3;
    *(_WORD *)(*(_DWORD *)(v0 + 28) + 6) = 3;
    *(_WORD *)(*(_DWORD *)(v0 + 28) + 8) = 1;
    *(_WORD *)(*(_DWORD *)(v0 + 28) + 10) = 2;
    *(_DWORD *)(v0 + 4) += 4;
    *(_DWORD *)(v0 + 8) += 6;
  }
}

