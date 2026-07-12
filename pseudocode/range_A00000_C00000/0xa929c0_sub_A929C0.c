// Function: sub_A929C0
// Address: 0xa929c0
// Size: 0x9e
// Prototype: int __thiscall(_DWORD)

int __thiscall sub_A929C0(int *this)
{
  int X_1; // ebx
  double X; // xmm0_8
  double v3; // st7
  int v4; // eax
  int v5; // esi
  int i; // edi
  int X_3; // ecx
  int X_4; // edx
  int v9; // ebx
  int v11; // [esp+44h] [ebp-4h]
  int X_2; // [esp+48h] [ebp+0h]
  _UNKNOWN *retaddr; // [esp+4Ch] [ebp+4h]

  X_1 = *(this + 1);
  X = (float)X_1;
  libm_sse2_pow_precise();
  retaddr = (_UNKNOWN *)LODWORD(X);
  v3 = floor(X);
  v4 = v11;
  v5 = (int)v3;
  for ( i = (int)v3 + 1; ; ++i )
  {
    while ( 1 )
    {
      X_3 = 1;
      X_4 = 1;
      if ( v4 > 0 )
      {
        v9 = v4;
        do
        {
          X_3 *= v5;
          X_4 *= i;
          --v9;
        }
        while ( v9 );
        X_1 = X_2;
        v4 = v11;
      }
      if ( X_3 <= X_1 )
        break;
      --v5;
      --i;
    }
    if ( X_4 > X_1 )
      break;
    ++v5;
  }
  return v5;
}

