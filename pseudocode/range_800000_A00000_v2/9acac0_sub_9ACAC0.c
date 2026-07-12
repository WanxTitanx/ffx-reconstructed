// Function: sub_9ACAC0
// Address: 0x9acac0
int __cdecl sub_9ACAC0(int a1, float *Src_5, float *Src_1)
{
  float *Src_3; // eax
  float *Src_2; // edx
  int n4; // esi
  int i; // ecx
  int n4_1; // ebx
  float *Src_6; // edi
  float *v9; // eax
  double v10; // st7
  float *v11; // edx
  float *v12; // eax
  double v13; // st6
  double v14; // st4
  float *v15; // eax
  float *v17; // [esp+14h] [ebp-64h]
  float *Src_4; // [esp+18h] [ebp-60h]
  float *v19; // [esp+1Ch] [ebp-5Ch]
  int v20; // [esp+20h] [ebp-58h]
  int v21; // [esp+28h] [ebp-50h]
  float *Src; // [esp+30h] [ebp-48h]
  char v23; // [esp+34h] [ebp-44h] BYREF

  Src_3 = Src_1;
  Src_2 = Src_5;
  Src_4 = Src_5;
  n4 = 4;
  Src = Src_1;
  for ( i = 0; i <= 4; i += 4 )
  {
    v20 = -1;
    do
    {
      n4_1 = 0;
      Src_6 = Src_3;
      if ( n4 > 0 )
      {
        v9 = &Src_2[i / 4u];
        v21 = (int)&Src[i / 0xFFFFFFFC + 1];
        v17 = &Src_2[i / 4u];
        v10 = (float)v20;
        v11 = &Src_4[i / 0xFFFFFFFC + 1];
        do
        {
          if ( *(float *)(a1 + i) > *v9 * v10 )
          {
            v21 += 8;
            *Src_6 = v11[i / 4u - 1];
            ++n4_1;
            Src_6 += 2;
            *(Src_6 - 1) = v11[i / 4u];
            if ( (n4_1 & 8) != 0 )
              goto LABEL_12;
          }
          v12 = n4 <= 1 ? Src_4 : &v11[i / 4u + 1];
          v19 = v12;
          v13 = *v17;
          v14 = v12[i / 4u];
          if ( *(float *)(a1 + i) > v13 * v10 != *(float *)(a1 + i) > v14 * v10 )
          {
            ++n4_1;
            v15 = (float *)v21;
            v21 += 8;
            Src_6 += 2;
            *v15 = (*(float *)(a1 + i) * v10 - v13) * ((v19[i / 0xFFFFFFFC + 1] - *v11) / (v14 - v13)) + *v11;
            Src_6[i / 4u - 2] = v10 * *(float *)(a1 + i);
            if ( (n4_1 & 8) != 0 )
            {
LABEL_12:
              Src_2 = Src;
              goto LABEL_13;
            }
          }
          v9 = v17 + 2;
          --n4;
          v11 += 2;
          v17 += 2;
        }
        while ( n4 > 0 );
        Src_3 = Src;
      }
      Src_2 = Src_3;
      Src_3 = (float *)&v23;
      if ( Src != Src_1 )
        Src_3 = Src_1;
      Src_4 = Src_2;
      Src = Src_3;
      n4 = n4_1;
      v20 += 2;
    }
    while ( v20 <= 1 );
  }
LABEL_13:
  if ( Src_2 != Src_1 )
    memcpy(Src_1, Src_2, 8 * n4_1);
  return n4_1;
}
