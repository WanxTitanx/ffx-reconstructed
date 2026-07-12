// Function: sub_89A820
// Address: 0x89a820
void __cdecl sub_89A820(int n20)
{
  int KernelString; // eax
  _BYTE *v2; // edx
  char v3; // cl
  char *v4; // eax
  char *v5; // edx
  char v6; // cl
  int v7; // eax
  char *v8; // edx
  char v9; // cl
  float *DurationFloatPtr; // edx
  int v11; // eax
  char n44; // al
  int v13; // ecx
  char v14; // al
  unsigned int count; // edx
  char *dst; // edi
  char v17; // al
  int v18; // ecx
  char v19; // al
  char v20; // [esp+4h] [ebp-3Ch]
  float *DurationFloatPtr_1; // [esp+8h] [ebp-38h]
  _BYTE v22[16]; // [esp+Ch] [ebp-34h] BYREF
  char src[16]; // [esp+1Ch] [ebp-24h] BYREF
  char src_; // [esp+2Ch] [ebp-14h] BYREF
  char v25; // [esp+2Dh] [ebp-13h]

  if ( n20 != 255 )
  {
    KernelString = FFX_Table_GetKernelString(1, 4167, 0);
    v2 = &v22[-KernelString];
    do
    {
      v3 = *(_BYTE *)KernelString;
      v2[KernelString] = *(_BYTE *)KernelString;
      ++KernelString;
    }
    while ( v3 );
    v4 = (char *)FFX_Table_GetKernelString(1, 4168, 0);
    v5 = (char *)(&src_ - v4);
    do
    {
      v6 = *v4;
      v4[(_DWORD)v5] = *v4;
      ++v4;
    }
    while ( v6 );
    v7 = FFX_Table_GetKernelString(1, 4169, 0);
    v8 = &src[-v7];
    do
    {
      v9 = *(_BYTE *)v7;
      v8[v7] = *(_BYTE *)v7;
      ++v7;
    }
    while ( v9 );
    memset(&n44, 0, 0x80u);
    DurationFloatPtr = FFX_StatusEffect_GetDurationFloatPtr(n20);
    DurationFloatPtr_1 = DurationFloatPtr;
    if ( n20 < 20 )
      goto LABEL_28;
    v11 = sub_79AE40(n20);
    switch ( v11 )
    {
      case 20:
        v20 = sub_79AE20(n20);
        if ( FFX_Game_GetRegion() || FFX_Kernel_GetStubZero() )
        {
          if ( FFX_Game_GetRegion() == 10 || FFX_Game_GetRegion() == 9 )
            n44 = v20 + 90;
          else
            n44 = v20 + 80;
          unk_133F4F9 = 0;
          n44 = n44;
        }
        else
        {
          n44 = 44;
          unk_133F4F9 = v20 + 48;
          unk_133F4FA = 0;
        }
        break;
      case 21:
        v13 = 0;
        do
        {
          v14 = v22[v13];
          *((_BYTE *)&n44 + v13++) = v14;
        }
        while ( v14 );
        break;
      case 22:
        v17 = sub_79AE20(n20);
        v25 += v17;
        v18 = 0;
        do
        {
          v19 = v22[v18];
          *((_BYTE *)&n44 + v18++) = v19;
        }
        while ( v19 );
        strcat((char *)&n44, &src_);
        count = &src[strlen(src) + 1] - src;
        dst = (char *)&n44 + strlen((const char *)&n44);
LABEL_26:
        qmemcpy(dst, src, count);
        goto LABEL_27;
      default:
LABEL_27:
        DurationFloatPtr = DurationFloatPtr_1;
LABEL_28:
        strcat((char *)&n44, (const char *)DurationFloatPtr);
        sub_8B9600(0, &n44, &unk_133F4F4, &unk_133F4F0, 0, 0);
        return;
    }
    count = strlen(src) + 1;
    dst = (char *)&n44 + strlen((const char *)&n44);
    goto LABEL_26;
  }
}
