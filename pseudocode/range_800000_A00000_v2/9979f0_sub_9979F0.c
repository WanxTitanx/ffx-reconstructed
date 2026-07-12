// Function: sub_9979F0
// Address: 0x9979f0
void __thiscall sub_9979F0(float *this, int a2, int a3, int a4)
{
  int v4; // edi
  float *v6; // esi
  int n2; // ecx
  float *v8; // ecx
  int v9; // eax
  float v10; // [esp-20h] [ebp-2Ch]
  float v11; // [esp-1Ch] [ebp-28h]
  float v12; // [esp-18h] [ebp-24h]
  float v13; // [esp-Ch] [ebp-18h]
  float v14; // [esp-8h] [ebp-14h]
  float *this_1; // [esp-4h] [ebp-10h]

  v4 = a4;
  this_1 = this;
  if ( a4 > 0 )
  {
    v6 = (float *)(a2 + 8);
    do
    {
      v14 = *(v6 - 1);
      v13 = *(v6 - 2);
      v10 = *(this + 18) * *v6 + *(this + 17) * v14 + v13 * *(this + 16);
      v11 = v13 * *(this + 20) + v14 * *(this + 21) + *v6 * *(this + 22);
      v12 = *v6 * *(this + 26) + v14 * *(this + 25) + v13 * *(this + 24);
      if ( v11 <= (double)v10 )
      {
        if ( v12 <= (double)v10 )
          n2 = 0;
        else
          n2 = 2;
      }
      else if ( v12 <= (double)v11 )
      {
        n2 = 1;
      }
      else
      {
        n2 = 2;
      }
      v8 = &this_1[4 * n2 + 16];
      v6 += 4;
      a3 += 16;
      *(float *)(a3 - 16) = *v8;
      *(float *)(a3 - 12) = v8[1];
      *(float *)(a3 - 8) = v8[2];
      v9 = *((_DWORD *)v8 + 3);
      this = this_1;
      *(_DWORD *)(a3 - 4) = v9;
      --v4;
    }
    while ( v4 );
  }
}
