// Function: sub_9B5780
// Address: 0x9b5780
const char *__thiscall sub_9B5780(int this, int a2, int a3)
{
  int v4; // eax
  int v5; // ecx
  int n3; // edx
  double v7; // st7

  sub_97A0F0(a2, a3);
  v4 = a2 + 252;
  v5 = this + 276;
  n3 = 3;
  do
  {
    v7 = *(float *)(v5 - 4);
    v5 += 16;
    *(float *)(v4 - 4) = v7;
    v4 += 16;
    *(float *)(v4 - 16) = *(float *)(v5 - 16);
    *(float *)(v4 - 12) = *(float *)(v5 - 12);
    *(float *)(v4 - 8) = *(float *)(v5 - 8);
    --n3;
  }
  while ( n3 );
  *(float *)(a2 + 296) = *(float *)(this + 320);
  *(float *)(a2 + 300) = *(float *)(this + 324);
  *(float *)(a2 + 304) = *(float *)(this + 328);
  *(float *)(a2 + 308) = *(float *)(this + 332);
  *(float *)(a2 + 312) = *(float *)(this + 336);
  *(float *)(a2 + 316) = *(float *)(this + 340);
  *(float *)(a2 + 320) = *(float *)(this + 344);
  *(float *)(a2 + 324) = *(float *)(this + 348);
  *(float *)(a2 + 440) = *(float *)(this + 352);
  *(float *)(a2 + 328) = *(float *)(this + 608);
  *(float *)(a2 + 332) = *(float *)(this + 612);
  *(float *)(a2 + 336) = *(float *)(this + 616);
  *(float *)(a2 + 340) = *(float *)(this + 620);
  *(float *)(a2 + 344) = *(float *)(this + 368);
  *(float *)(a2 + 348) = *(float *)(this + 372);
  *(float *)(a2 + 352) = *(float *)(this + 376);
  *(float *)(a2 + 356) = *(float *)(this + 380);
  *(float *)(a2 + 360) = *(float *)(this + 384);
  *(float *)(a2 + 364) = *(float *)(this + 388);
  *(float *)(a2 + 368) = *(float *)(this + 392);
  *(float *)(a2 + 372) = *(float *)(this + 396);
  *(float *)(a2 + 376) = *(float *)(this + 400);
  *(float *)(a2 + 380) = *(float *)(this + 404);
  *(float *)(a2 + 384) = *(float *)(this + 408);
  *(float *)(a2 + 388) = *(float *)(this + 412);
  *(float *)(a2 + 392) = *(float *)(this + 416);
  *(float *)(a2 + 396) = *(float *)(this + 420);
  *(float *)(a2 + 400) = *(float *)(this + 424);
  *(float *)(a2 + 404) = *(float *)(this + 428);
  *(float *)(a2 + 408) = *(float *)(this + 432);
  *(float *)(a2 + 412) = *(float *)(this + 436);
  *(float *)(a2 + 416) = *(float *)(this + 440);
  *(float *)(a2 + 420) = *(float *)(this + 444);
  *(float *)(a2 + 424) = *(float *)(this + 448);
  *(float *)(a2 + 428) = *(float *)(this + 452);
  *(float *)(a2 + 432) = *(float *)(this + 456);
  *(float *)(a2 + 436) = *(float *)(this + 460);
  *(float *)(a2 + 444) = *(float *)(this + 464);
  *(float *)(a2 + 448) = *(float *)(this + 468);
  *(_DWORD *)(a2 + 476) = *(unsigned __int8 *)(this + 472);
  *(float *)(a2 + 452) = *(float *)(this + 476);
  *(float *)(a2 + 456) = *(float *)(this + 480);
  *(float *)(a2 + 460) = *(float *)(this + 484);
  *(float *)(a2 + 464) = *(float *)(this + 488);
  *(float *)(a2 + 468) = *(float *)(this + 492);
  *(float *)(a2 + 472) = *(float *)(this + 496);
  return "btRigidBodyFloatData";
}
