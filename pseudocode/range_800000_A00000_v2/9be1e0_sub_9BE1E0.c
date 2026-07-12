// Function: sub_9BE1E0
// Address: 0x9be1e0
int __usercall sub_9BE1E0@<eax>(int a1@<ecx>, char a2@<efl>)
{
  float v2; // xmm1_4
  bool v3; // cf
  bool v4; // zf
  char v5; // sf
  char v6; // of
  char v7; // pf
  int result; // eax
  double v9; // st7
  double v10; // st7
  float v11; // [esp-10h] [ebp-1Ch]
  float v12; // [esp-10h] [ebp-1Ch]
  float v13; // [esp-Ch] [ebp-18h]
  float v14; // [esp-Ch] [ebp-18h]
  float v15; // [esp-8h] [ebp-14h]
  float v16; // [esp-8h] [ebp-14h]

  v2 = *(float *)(a1 + 352);
  v3 = v2 < 0.0;
  v7 = 0;
  v4 = v2 == 0.0;
  v5 = 0;
  v6 = 0;
  BYTE1(result) = a2;
  if ( v2 != 0.0 )
  {
    v11 = *(float *)(a1 + 320) + *(float *)(a1 + 576);
    v13 = *(float *)(a1 + 324) + *(float *)(a1 + 580);
    v9 = *(float *)(a1 + 328) + *(float *)(a1 + 584);
    *(float *)(a1 + 320) = v11;
    *(float *)(a1 + 324) = v13;
    v15 = v9;
    *(float *)(a1 + 328) = v15;
    *(_DWORD *)(a1 + 332) = 0;
    v12 = *(float *)(a1 + 336) + *(float *)(a1 + 592);
    v14 = *(float *)(a1 + 340) + *(float *)(a1 + 596);
    v10 = *(float *)(a1 + 344) + *(float *)(a1 + 600);
    *(float *)(a1 + 336) = v12;
    *(float *)(a1 + 340) = v14;
    v16 = v10;
    *(float *)(a1 + 344) = v16;
    *(_DWORD *)(a1 + 348) = 0;
    return 0;
  }
  return result;
}
