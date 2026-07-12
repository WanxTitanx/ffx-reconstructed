// Function: sub_9B5EC0
// Address: 0x9b5ec0
int __userpurge sub_9B5EC0@<eax>(int a1@<ecx>, int a2@<edi>, int a3@<esi>, int a4)
{
  int v5; // ecx
  _DWORD *v6; // ecx
  float v7; // eax
  int v8; // eax
  double v9; // st7
  double v10; // st7
  float v13; // [esp+1Ch] [ebp-2Ch]
  float v14; // [esp+20h] [ebp-28h]
  float v15; // [esp+24h] [ebp-24h]
  float v16; // [esp+28h] [ebp-20h]
  float v17; // [esp+38h] [ebp-10h]

  *(_DWORD *)(a1 + 244) = 2;
  *(_DWORD *)(a1 + 320) = 0;
  *(_DWORD *)(a1 + 324) = 0;
  *(_DWORD *)(a1 + 328) = 0;
  *(_DWORD *)(a1 + 332) = 0;
  *(_DWORD *)(a1 + 336) = 0;
  *(_DWORD *)(a1 + 340) = 0;
  *(_DWORD *)(a1 + 344) = 0;
  *(_DWORD *)(a1 + 348) = 0;
  *(_DWORD *)(a1 + 608) = 1065353216;
  *(_DWORD *)(a1 + 612) = 1065353216;
  *(_DWORD *)(a1 + 616) = 1065353216;
  *(_DWORD *)(a1 + 620) = 0;
  *(_DWORD *)(a1 + 368) = 1065353216;
  *(_DWORD *)(a1 + 372) = 1065353216;
  *(_DWORD *)(a1 + 376) = 1065353216;
  *(_DWORD *)(a1 + 380) = 0;
  *(_DWORD *)(a1 + 384) = 0;
  *(_DWORD *)(a1 + 388) = 0;
  *(_DWORD *)(a1 + 392) = 0;
  *(_DWORD *)(a1 + 396) = 0;
  *(_DWORD *)(a1 + 400) = 0;
  *(_DWORD *)(a1 + 404) = 0;
  *(_DWORD *)(a1 + 408) = 0;
  *(_DWORD *)(a1 + 412) = 0;
  *(_DWORD *)(a1 + 432) = 0;
  *(_DWORD *)(a1 + 436) = 0;
  *(_DWORD *)(a1 + 440) = 0;
  *(_DWORD *)(a1 + 444) = 0;
  *(_DWORD *)(a1 + 448) = 0;
  *(_DWORD *)(a1 + 452) = 0;
  *(_DWORD *)(a1 + 456) = 0;
  *(_DWORD *)(a1 + 460) = 0;
  *(_DWORD *)(a1 + 464) = 0;
  *(_DWORD *)(a1 + 468) = 1056964608;
  *(float *)(a1 + 492) = *(float *)(a4 + 128);
  *(float *)(a1 + 496) = *(float *)(a4 + 132);
  *(_DWORD *)(a1 + 500) = *(_DWORD *)(a4 + 4);
  v5 = *(_DWORD *)(a1 + 500);
  *(_DWORD *)(a1 + 672) = 0;
  *(_DWORD *)(a1 + 676) = 0;
  *(_BYTE *)(a1 + 472) = *(_BYTE *)(a4 + 136);
  *(float *)(a1 + 476) = *(float *)(a4 + 140);
  *(float *)(a1 + 480) = *(float *)(a4 + 144);
  *(float *)(a1 + 484) = *(float *)(a4 + 148);
  *(float *)(a1 + 488) = *(float *)(a4 + 152);
  if ( v5 )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 4))(v5, a1 + 16);
    v6 = (_DWORD *)(a1 + 16);
  }
  else
  {
    *(_DWORD *)(a1 + 16) = *(_DWORD *)(a4 + 16);
    v6 = (_DWORD *)(a1 + 16);
    *(_DWORD *)(a1 + 20) = *(_DWORD *)(a4 + 20);
    *(_DWORD *)(a1 + 24) = *(_DWORD *)(a4 + 24);
    *(_DWORD *)(a1 + 28) = *(_DWORD *)(a4 + 28);
    *(_DWORD *)(a1 + 32) = *(_DWORD *)(a4 + 32);
    *(_DWORD *)(a1 + 36) = *(_DWORD *)(a4 + 36);
    *(_DWORD *)(a1 + 40) = *(_DWORD *)(a4 + 40);
    *(_DWORD *)(a1 + 44) = *(_DWORD *)(a4 + 44);
    *(_DWORD *)(a1 + 48) = *(_DWORD *)(a4 + 48);
    *(_DWORD *)(a1 + 52) = *(_DWORD *)(a4 + 52);
    *(_DWORD *)(a1 + 56) = *(_DWORD *)(a4 + 56);
    *(_DWORD *)(a1 + 60) = *(_DWORD *)(a4 + 60);
    *(_DWORD *)(a1 + 64) = *(_DWORD *)(a4 + 64);
    *(_DWORD *)(a1 + 68) = *(_DWORD *)(a4 + 68);
    *(_DWORD *)(a1 + 72) = *(_DWORD *)(a4 + 72);
    *(_DWORD *)(a1 + 76) = *(_DWORD *)(a4 + 76);
  }
  *(_DWORD *)(a1 + 80) = *v6;
  *(_DWORD *)(a1 + 84) = v6[1];
  *(_DWORD *)(a1 + 88) = v6[2];
  *(_DWORD *)(a1 + 92) = v6[3];
  *(_DWORD *)(a1 + 96) = v6[4];
  *(_DWORD *)(a1 + 100) = v6[5];
  *(_DWORD *)(a1 + 104) = v6[6];
  *(_DWORD *)(a1 + 108) = v6[7];
  *(_DWORD *)(a1 + 112) = v6[8];
  *(_DWORD *)(a1 + 116) = v6[9];
  *(_DWORD *)(a1 + 120) = v6[10];
  *(_DWORD *)(a1 + 124) = v6[11];
  *(_DWORD *)(a1 + 128) = v6[12];
  *(_DWORD *)(a1 + 132) = v6[13];
  *(_DWORD *)(a1 + 136) = v6[14];
  *(_DWORD *)(a1 + 140) = v6[15];
  *(_DWORD *)(a1 + 144) = 0;
  *(_DWORD *)(a1 + 148) = 0;
  *(_DWORD *)(a1 + 152) = 0;
  *(_DWORD *)(a1 + 156) = 0;
  *(_DWORD *)(a1 + 160) = 0;
  *(_DWORD *)(a1 + 164) = 0;
  *(_DWORD *)(a1 + 168) = 0;
  *(_DWORD *)(a1 + 172) = 0;
  v7 = *(float *)a1;
  *(float *)(a1 + 236) = *(float *)(a4 + 120);
  *(float *)(a1 + 240) = *(float *)(a4 + 124);
  (*(void (__thiscall **)(int, _DWORD, int, int))(LODWORD(v7) + 8))(a1, *(_DWORD *)(a4 + 80), a2, a3);
  v8 = unk_193F65C;
  *(_DWORD *)(a1 + 528) = unk_193F65C;
  v9 = *(float *)a4;
  unk_193F65C = v8 + 1;
  v16 = v9;
  sub_9B5D30(a1, v16, (float *)(a4 + 96));
  sub_9B5BF0((float *)a1, *(float *)(a4 + 112), *(float *)(a4 + 116));
  sub_9B6390(a1);
  *(_DWORD *)(a1 + 524) = 0;
  *(_DWORD *)(a1 + 576) = 0;
  *(_DWORD *)(a1 + 580) = 0;
  *(_DWORD *)(a1 + 584) = 0;
  *(_DWORD *)(a1 + 588) = 0;
  *(_DWORD *)(a1 + 592) = 0;
  *(_DWORD *)(a1 + 596) = 0;
  *(_DWORD *)(a1 + 600) = 0;
  *(_DWORD *)(a1 + 604) = 0;
  v17 = *(float *)(a1 + 352);
  v13 = *(float *)(a1 + 368) * v17;
  v14 = v17 * *(float *)(a1 + 372);
  v10 = v17 * *(float *)(a1 + 376);
  *(float *)(a1 + 624) = v13;
  *(float *)(a1 + 628) = v14;
  v15 = v10;
  *(float *)(a1 + 632) = v15;
  *(_DWORD *)(a1 + 636) = 0;
  *(_DWORD *)(a1 + 640) = 0;
  *(_DWORD *)(a1 + 644) = 0;
  *(_DWORD *)(a1 + 648) = 0;
  *(_DWORD *)(a1 + 652) = 0;
  *(_DWORD *)(a1 + 656) = 0;
  *(_DWORD *)(a1 + 660) = 0;
  *(_DWORD *)(a1 + 664) = 0;
  *(_DWORD *)(a1 + 668) = 0;
  return 0;
}
