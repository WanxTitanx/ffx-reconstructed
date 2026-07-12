// Function: sub_9B51F0
// Address: 0x9b51f0
__int16 __userpurge sub_9B51F0@<ax>(int a1@<ecx>, int a2@<ebp>, char a3@<efl>, float a4)
{
  float v4; // xmm1_4
  bool v5; // cf
  bool v6; // zf
  char v7; // sf
  char v8; // of
  char v9; // pf
  unsigned int v10; // eax
  double v11; // st7
  double v12; // st7
  float v14; // [esp+18h] [ebp-6Ch]
  float v15; // [esp+18h] [ebp-6Ch]
  float v16; // [esp+1Ch] [ebp-68h]
  float v17; // [esp+1Ch] [ebp-68h]
  float v18; // [esp+20h] [ebp-64h]
  float v19; // [esp+20h] [ebp-64h]
  _BYTE v20[80]; // [esp+28h] [ebp-5Ch] BYREF
  _DWORD v21[3]; // [esp+78h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+84h] [ebp+0h]

  v21[0] = a2;
  v21[1] = retaddr;
  v10 = (unsigned int)v21 ^ __security_cookie;
  v4 = *(float *)(a1 + 352);
  v5 = v4 < 0.0;
  v9 = 0;
  v6 = v4 == 0.0;
  v7 = 0;
  v8 = 0;
  BYTE1(v10) = a3;
  if ( v4 != 0.0 )
  {
    v14 = *(float *)(a1 + 320) + *(float *)(a1 + 576);
    v16 = *(float *)(a1 + 324) + *(float *)(a1 + 580);
    v11 = *(float *)(a1 + 328) + *(float *)(a1 + 584);
    *(float *)(a1 + 320) = v14;
    *(float *)(a1 + 324) = v16;
    v18 = v11;
    *(float *)(a1 + 328) = v18;
    *(_DWORD *)(a1 + 332) = 0;
    v15 = *(float *)(a1 + 336) + *(float *)(a1 + 592);
    v17 = *(float *)(a1 + 340) + *(float *)(a1 + 596);
    v12 = *(float *)(a1 + 344) + *(float *)(a1 + 600);
    *(float *)(a1 + 336) = v15;
    *(float *)(a1 + 340) = v17;
    v19 = v12;
    *(float *)(a1 + 344) = v19;
    *(_DWORD *)(a1 + 348) = 0;
    sub_9A7AC0((int)v21, (float *)(a1 + 16), (float *)(a1 + 640), (float *)(a1 + 656), a4, (int)v20);
    LOWORD(v10) = sub_6043A0(v20);
  }
  return v10;
}
