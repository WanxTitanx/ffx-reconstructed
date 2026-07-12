// Function: sub_A5C370
// Address: 0xa5c370
// Size: 0x2e3
// Prototype: int __cdecl(int, int, int, int, int, int, int, int, int, int, float, float, int, int, int, int, int)

int __cdecl sub_A5C370(
        __int64 a1,
        int a2,
        int a3,
        const void *src,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        float a10,
        float a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16)
{
  int v16; // edi
  int dst; // ebx
  int v19; // esi
  int v20; // esi
  int v21; // eax
  int v22; // [esp+4Ch] [ebp-8h]
  int v23; // [esp+50h] [ebp-4h]
  int v24; // [esp+84h] [ebp+30h]
  int v25; // [esp+90h] [ebp+3Ch]
  int v26; // [esp+94h] [ebp+40h]
  int v27; // [esp+98h] [ebp+44h]

  v23 = a15 + 64;
  v25 = (a13 << 7) / 128;
  v26 = (a14 << 7) / 128;
  unk_C8F8E0 = 0;
  unk_C8F8E4 = 0;
  unk_C8F8E8 = 0;
  unk_C8F8EC = 0;
  unk_C8F920 = 1.0;
  unk_C8F924 = 1.0;
  unk_C8F928 = 1.0;
  unk_C8F92C = 0.0;
  flt_C8F850 = 0.5;
  flt_C8F854 = 0.5;
  flt_C8F858 = 0.0;
  unk_C8F85C = 0.0;
  unk_C8F8C0 = a10;
  unk_C8F8C4 = a11;
  unk_C8F8C8 = 0.0;
  unk_C8F8CC = 0.0;
  unk_C8F78C[0] = 255.0;
  sub_A5BEC0(a5);
  v16 = a2 + *(_DWORD *)(a2 + 4);
  sub_A5BE30(src);
  sub_83B6D0();
  sub_83B6D0();
  dst = sub_645580(a1);
  if ( !dst )
    return 0;
  v22 = *(__int16 *)(a2 + 16);
  v27 = 0;
  v19 = FFX_MagicHost_AllocPppDrawRecord(v22);
  *(_DWORD *)(v19 + 20) = a2;
  *(_DWORD *)(v19 + 32) = v23;
  *(_DWORD *)(v19 + 36) = 64;
  *(_DWORD *)(v19 + 48) = 128;
  *(_DWORD *)(v19 + 40) = 128;
  *(_DWORD *)(v19 + 44) = v25;
  *(_DWORD *)(v19 + 52) = 128;
  *(_DWORD *)(v19 + 56) = 128;
  *(_DWORD *)(v19 + 60) = v26;
  *(_BYTE *)v19 = 2;
  *(_DWORD *)(v19 + 16) = dst;
  *(_DWORD *)(v19 + 24) = a3;
  sub_6ED4A0(v19 + 64, src);
  sub_6ED4A0(v19 + 128, a5);
  *(float *)(v19 + 192) = 0.0;
  *(float *)(v19 + 208) = (float)a12;
  *(float *)(v19 + 196) = 0.0;
  *(float *)(v19 + 212) = a10;
  *(float *)(v19 + 200) = 0.0;
  *(float *)(v19 + 216) = a11;
  *(float *)(v19 + 204) = 0.0;
  *(_DWORD *)(v19 + 220) = a16;
  v20 = v22;
  if ( v22 > 0 )
  {
    v24 = 0;
    do
    {
      if ( *(_BYTE *)(v16 + 1) == 3 )
      {
        if ( !sub_63FF60(dst, v27, 3 * *(__int16 *)(v16 + 2), 3 * *(__int16 *)(v16 + 2)) )
          return 0;
        *(_DWORD *)(*(_DWORD *)(dst + 148) + v24 + 36) = 2 - ((*(_DWORD *)a2 & 4) != 0);
      }
      v21 = *(__int16 *)(v16 + 2);
      ++v27;
      v24 += 108;
      v16 = a2;
      v20 -= v21;
    }
    while ( v20 > 0 );
  }
  *(_DWORD *)(dst + 176) = 0;
  qmemcpy((void *)dst, src, 0x40u);
  sub_6ED700(dst, &src__0, dst);
  *(float *)(dst + 12) = 0.0;
  *(float *)(dst + 28) = 0.0;
  *(float *)(dst + 44) = 0.0;
  *(float *)(dst + 60) = 1.0;
  *(_DWORD *)(dst + 128) = 0;
  *(float *)(dst + 152) = -100000.0;
  *(float *)(dst + 156) = -100000.0;
  *(float *)(dst + 160) = -100000.0;
  *(float *)(dst + 164) = 100000.0;
  *(float *)(dst + 168) = 100000.0;
  *(float *)(dst + 172) = 100000.0;
  sub_6458C0(a1, HIDWORD(a1), 1);
  return 1;
}

